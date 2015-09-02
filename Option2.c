#include "allheaders.h"
#include "Option2.h"


typedef union {

    char *string;
    OptionStatus_t status;
} Optionstring_t;

OptionStatus_t MatchOptionString(void *x_)
{
    OptionStatus_t status = OptNone;
    Optionstring_t x = {.string=x_};
    if (x.status != OptNone) {status = OptSome;}
    return status;
}

Optionstring_t SomeString(char p[])
{
    Optionstring_t ret = {.string=""};
    if (!p) {
        printf("Cannot set null string default to empty string");
    }
    else {
        ret = (Optionstring_t){.string = p};
    }
    return ret;
}

Optionstring_t NoneString(void)
{
    Optionstring_t ret = {.string=NULL};
    return ret;
}

void testOption2(void)
{
    char buffer[200] = {"t"};
    Optionstring_t msg = {.string = buffer};
    char *msg2;
    char len;
    Optionstring_t *msg3 = malloc(20);
    //msg = SomeString("Aga");

    //len = strlen(msg);
    // /msg = NoneString();
    switch (MatchOptionString(&msg)) {
        case OptSome: {
            printf("before\n");
            strcpy(msg.string, "oho");
            strcat(msg.string, "labas");
            printf("Some %s\n", msg.string);
        } break;
        case OptNone: {
            printf("None\n");
        } break;
    }
    switch (MatchOptionString(&buffer)) {
        case OptSome: {

            printf("Some %s\n", buffer);
        } break;
        case OptNone: {
            printf("None\n");
        } break;
    }
}

int main(int argc, char const *argv[])
{
    testOption2();
    return 0;
}