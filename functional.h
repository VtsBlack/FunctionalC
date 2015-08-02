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
array_t *grep(int *in, int len, int (*sel)(int));
void map_u8(char* array, int len, int(*callback)(int));
int* mapN(void* array, int len, char*(*callback)(void *in));

#endif

