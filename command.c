#include "allheaders.h"

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
} customCmd_t;

/**
 * @brief: Command Table
 */
const customCmd_t custom_cmd[] = {
    {eCmd1, "testcmd:"}
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
    for (i=0; i<num_of_commands; i++) {
        if (strncmp(commands[i].cmd, toFind, strlen(commands[i].cmd))==0) {
            *next = toFind + strlen(commands[i].cmd);
            return commands[i].id;
        }
    }
    return eCmdLast;
}

int main(void)
{
    void *next;
    switch (findCustomCmd("testcmd:", &next, custom_cmd, NUM_OF_CUSTOM_COMMANDS)) {
        case eCmd1: {
            printf("Custom Cmd1 Found\r\n");
        } break;
        default: {
            printf("Cmd not found\r\n");
        }
    }
}
