#include "allheaders.h"
#include "ADT.h"

typedef struct my_state_s {
    uint8_t state;
}my_state_t;

abstracted_state create_something(void)
{
    abstracted_state x = malloc(sizeof(my_state_t));
    return x;
}
void do_something(abstracted_state x)
{
    x->state = 1;
}

void showATD(abstracted_state x)
{
    printf("state:%d\n", x->state);
}

