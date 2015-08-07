#ifndef __ATD_H
#define __ATD_H

typedef struct my_state_s *abstracted_state;

abstracted_state create_something(void);
void do_something(abstracted_state x);
void showATD(abstracted_state x);
#endif
