// Example program
#include "allheaders.h"


int sum(int a, int b)
{
    return a+b;
}

int biger_than_5(int x)
{
    if (x > 5) {
        return true;
    }
    else {
        return false;
    }
}

#define CRITICAL(x) printf("A\r\n"); x; printf("B\r\n")


int main()
{
    int total =0;
    int input[] = {2,4,8,1,12};

    total = reduce_array(sum, grep(input, 5, biger_than_5));
    
    printf("Result: %d\r\n", total);
    
  
}
