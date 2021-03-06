#include "allheaders.h"

void command1(char *cmd, uint8_t test);
void command2(char *cmd, uint8_t test);

/**
 * @brief: commands id list
 */
typedef enum {
    eCmd1,
    eCmd2,
    eCmdLast,
} customCmdId_e;

/**
 * @brief: single command definition attach to command individual id;
 */
typedef struct {
    customCmdId_e id;
    const char *cmd;
    void (*f_command)(char *cmd, uint8_t test);
} customCmd_t;

/**
 * @brief: Command Table
 */
const customCmd_t custom_cmd[] = {
    {eCmd1, "testcmd:", command1},
    {eCmd2, "TESTCMD=", command2},
};

#define NUM_OF_CUSTOM_COMMANDS (sizeof(custom_cmd)/sizeof(customCmd_t))

/**
 * [findCustomCmd Functions that looks for commands in command table]
 * @param  toFind          [string to look for]
 * @param  next            [pointer will point after command if command found]
 * @param  commands        [pinter to commands table]
 * @param  num_of_commands [Number of commands available in table]
 * @return                 [id of command type of customCmdId_e: eCmdLast - if not found]
 */
customCmdId_e findCustomCmd(const char *toFind,
                            void **next,
                            const customCmd_t *commands,
                            const uint32_t num_of_commands)
{
    uint32_t i = 0;

    Stop_If(!toFind, return eCmdLast, "Can't search sting of NULL");
    Stop_If(!toFind[0], return eCmdLast, "Can't empty string");

    for (i=0; i<num_of_commands; i++) {
        if (strncmp(commands[i].cmd, toFind, strlen(commands[i].cmd))==0) {
            *next = (void*)toFind + strlen(commands[i].cmd);
            return commands[i].id;
        }
    }
    return eCmdLast;
}

/**
 * [next_arg Select Next argument must be preceeded with ',']
 * @param  next [pointer of current position in parsed string]
 * @return      [true if argument matches else otherwise]
 */
bool next_arg(void **next)
{
    bool return_val = false;
    char *ptr = strchr(*next, ',');
    if (ptr) {
        ptr++;
        *next = ptr;
        return_val = true;
    }
    return return_val;
}

void command1(char *cmd, uint8_t test)
{
    void *next = cmd;
    printf("Custom Cmd1 Found\r\n");
    printf("argument 1 is %d\r\n", atoi(next));
    next_arg(&next);
    printf("argument 2 is %d\r\n", atoi(next));
}

void command2(char *cmd, uint8_t test)
{
    void *next = cmd;
    switch(atoi(cmd)) {
        case 1: {
            next_arg(&next);
            printf("Last Argument %d\r\n", atoi(next));
        } break;
        default: {
            printf("Undefined %s\n", (char*)next);
        }
    }
}

void parser(char *RXBUF)
{
    void *next;
    customCmdId_e cmd_idx = findCustomCmd(RXBUF, &next, custom_cmd, NUM_OF_CUSTOM_COMMANDS);
    if (cmd_idx != eCmdLast) {
        custom_cmd[cmd_idx].f_command(next, 0);
    }
    else {
        printf("Cmd not found\r\n");
    }
}

int main(void)
{
    parser("testcmd:4,5");
    parser("TESTCMD=1,5");
}
