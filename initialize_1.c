#include "allheaders.h"

enum { Iron = 26, Aluminium = 13, Beryllium = 4};

const char *element_names[] =
{
    [Iron]      = "Iron",
    [Aluminium] = "Aluminium",
    [Beryllium] = "Beryllium",
};

int main(void)
{
    printf("Size: %d\n", sizeof(element_names));
    printf("%s\r\n", element_names[Iron]);
}
