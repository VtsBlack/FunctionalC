#ifndef __DEBUG_H
#define __DEBUG_H

#define log_assert(...) printf("ASSERT [F:%s L:%d] - "__VA_ARGS__"\r\n", __FILE__, __LINE__);

#define Stop_If(exp, error_action,  ...) if (exp) {log_assert(__VA_ARGS__); error_action;}
#endif
