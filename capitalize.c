#include "allheaders.h"


int main(void)
{
    char s1[] = "This is string";

    map_u8(s1, sizeof(s1), toupper);

    printf("Result:%s\n", s1);
}
