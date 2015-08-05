#ifndef __FUNCTIONAL_H
#define __FUNCTIONAL_H

typedef struct {
    uint32_t len;
    uint8_t destroy;
    int32_t elems[];
} array_t;


int32_t reduce_u8(int32_t (*fn)(int32_t, int32_t), uint32_t size, void *elms_);
int32_t reduce_int(int32_t (*fn)(int32_t, int32_t), uint32_t size, void *elms_);
int32_t reduce_array(int32_t (*fn)(int32_t, int32_t), array_t *data);
double reduce2float(double (*fn)(double, double), uint32_t len, double *data);
array_t *grep(int *in, int len, int (*sel)(int));
void map_u8(char* array, int len, int(*callback)(int));
int* mapN(void* array, int len, char*(*callback)(void *in));


double *map2float(void *a_, void *b_, uint32_t size, double(*callback)(double, double));
double *iterate(void *buf, double(*fn)(double), uint32_t a, uint32_t size);
#endif

