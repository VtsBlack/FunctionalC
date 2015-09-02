#include "allheaders.h"



/* Create a lambda function.  Note: unlike lambdas in functional
   languages, this lambda does not capture the containing
   environment.  Thus, if you access the enclosing environment, you
   must ensure that the lifetime of this lambda is bound by the
   lifetime of the enclosing environment (i.e., until the enclosing
   function returns).  This means that if you access local
   variables, bad things will happen.  If you don't access local
   variables, you're fine.  */
#define lambda(l_ret_type, l_arguments, l_body)         \
  ({                                                    \
    l_ret_type l_anonymous_functions_name l_arguments   \
      l_body                                            \
    &l_anonymous_functions_name;                        \
  })




int main(void)
{
  char values[4] = {4, 0, 1, 2};
    map_u8(values,
                4,
                lambda(int, (int b),
                {
                  return b*b;
                }));

    
  printf("Result: %d %d %d %d\r\n", 
    values[0],
    values[1],
    values[2],
    values[3]
    );
map_u8(values, sizeof(values),
  lambda(int, (int x),
                {
                  return x==0?5:x;
                }));


  printf("Result: %d %d %d %d\r\n", 
    values[0],
    values[1],
    values[2],
    values[3]
    );
}

