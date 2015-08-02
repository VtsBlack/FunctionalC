#include "allheaders.h"


typedef struct {
  char name[6];
  char email[20];
} customer_t;

customer_t Customers[2] = {
    [0].name = "Ota",
    [0].email = "O@ta",
    [1].name = "Put",
    [1].email = "P@ta",
};

char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);   // Allocate memory
    if (d != NULL) strcpy (d,s);         // Copy string if okay
    return d;                            // Return new memory
}

char *getCustomerName(void **in)
{
  char *return_val;
  return_val =  strdup(((customer_t*)*in)->name);
  *in = *in + sizeof(customer_t);
  printf("Cus:%s\r\n", return_val);

  return return_val;
}



int main(void)
{
    int *strings;
    strings = mapN(Customers, 2, getCustomerName);

    printf("Result 1 %s\r\n", (char*)strings[0]);
    printf("Result 2 %s\r\n", (char*)strings[1]);

}
