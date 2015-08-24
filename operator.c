
int32_t sum_int(const int32_t a, const int32_t b)
{
    return a + b;
}

int32_t sub_int(const int32_t a, const int32_t b)
{
    return a - b;
}


int32_t mul_int(const int32_t a, const int32_t b)
{
    return a * b;
}

int32_t div_int(const int32_t a, const int32_t b)
{
    if (b==0) {b = 1;}
    return a / b;
}

int32_t inc_int(const int32_t a)
{
    return a + 1;
}

int32_t dec_int(const int32_t a)
{
    return a + 1;
}

int32_t get_int(const uint32_t i, const int32_t a[])
{
    return a[i];
}

char get_u8(const uint32_t i, const char a[])
{
    return a[i];
}