#include "allheaders.h"





/*
  @Example:
    int nums[] = {1, 2, 3, 4, 5};
    printf("%d\n", reduce_u8(add, 5, nums));
    printf("%d\n", reduce_u8(sub, 5, nums));
    printf("%d\n", reduce_u8(mul, 5, nums));
 */
int32_t reduce_u8(int32_t (*fn)(int32_t, int32_t), uint32_t size, void *elms_)
{
    uint32_t i;
    char *elms = elms_;
    int32_t val = *elms;

    printf("R size:%d\r\n", size);
    for (i = 1; i < size; ++i) {
        val = fn(val, elms[i]);
    }
    return val;
}

int32_t reduce_int(int32_t (*fn)(int32_t, int32_t), uint32_t size, void *elms_)
{
    uint32_t i;
    int32_t *elms = elms_;
    int32_t val = *elms;

    for (i = 1; i < size; ++i) {
        val = fn(val, elms[i]);
    }
    return val;
}

int32_t reduce_array(int32_t (*fn)(int32_t, int32_t), array_t *data)
{
    uint32_t i;
    int32_t val = data->elems[0];

    for (i = 1; i < data->len; ++i) {
        val = fn(val, data->elems[i]);
    }
    if (data->destroy) {
        free(data);
    }

    return val;
}

double reduce2float(double (*fn)(double, double), uint32_t len, double *data)
{
    uint32_t i;
    double val = data[0];

    for (i = 1; i < len; ++i) {
        val = fn(val, data[i]);
    }
    free(data);

    return val;
}



int* mapN(void* array, int len, char*(*callback)(void *in))
{
  void *msg = array;
  char *d;
  int i = 0;
  int *place = malloc(len);
  for (i = 0; i < len; i++){
    d = callback(&msg);
    place[i] = d;
    // free(d);
  }
  return place;
} 


void map(int* array, int len, void(*callback)(int,int))
{
  int i;
  for(i = 0; i < len; i++)
  {
     callback(i, array[i]);
  }
} 

void map_u8(char* array, int len, int(*callback)(int))
{
  int i;
  for(i = 0; i < len; i++)
  {
     array[i] = callback(array[i]);
  }
}

double *map2float(void *a_, void *b_, uint32_t size, double(*callback)(double, double))
{
  int i;
  double *a = a_;
  double *b = b_;

  double *c = malloc(size*sizeof(double));

  for(i = 0; i < size; i++)
  {
      if ((b==NULL) && (b==NULL)) {
        c[i] = callback(0,0);
      }
      else {
        c[i] = callback(a[i], b[i]);
      }
      

  }

  return c;
}

double *iterate(void *buf, double(*fn)(double), uint32_t a, uint32_t size)
{
  int i;
  double *c = (double*)buf;
  if (buf == NULL) {
    malloc(size*sizeof(double));
  }
  for(i = 0; i < size; i++) {
    if (a) {
      c[i] = fn(a);
    }
    else {
      c[i] = fn(i);
    }
  }
  return c;
}



/* using a predicate function sel() to select elements */
array_t *grep(int *in, int len, int (*sel)(int))
{
    int i, j;
    array_t *out;

    out = calloc(sizeof(array_t) + sizeof(int) * len,1);
 
    for (i = j = 0; i < len; i++)
        if (sel(in[i]))
            out->elems[j++] = in[i];
 
    if (j < len)
        out = realloc(out, sizeof(array_t) + sizeof(int) * j);
 
    out->len = j;
    out->destroy = true;

    return out;
}
 