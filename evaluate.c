#include "allheaders.h"



static inline double mul_double(double a, double b)
{
    return a*b;
}

static inline double sum_double(double a, double b)
{
    return a+b;
}

static inline double inc(double x)
{
    return x;
}

static inline double set_to(double x)
{
    return x;
}

double evaluate(double a[], uint32_t a_size, double x)
{
    double *xi;
    double *axi;
    // # [x^0, x^1, x^2, ..., x^n-1]
    xi = map2float(iterate(NULL, inc,0,a_size),
                     iterate(NULL set_to,x, a_size),
                     a_size, pow);
    // # [a[0]*x^0, a[1]*x^1, ..., a[n-1]*x^n-1]
    axi = map2float(xi, a, a_size, mul_double);
    free(xi);
    // # sum of axi
    return reduce2float(sum_double, a_size, axi);
}


int main(void)
{
    double y = evaluate((double[]){0.34, 0.62}, 2, 4);

    printf("Result: %f\r\n", y);
}
