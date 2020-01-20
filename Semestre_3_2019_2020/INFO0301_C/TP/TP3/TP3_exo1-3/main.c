#include <stdio.h>
#include <float.h>

int main()
{
    printf("float radix : %d\n",FLT_RADIX);
    printf("float mant dig : %d\n",FLT_MANT_DIG);
    printf("float dig : %d\n",FLT_DIG);
    printf("float min exp : %d\n",FLT_MIN_EXP);
    printf("float min 10 exp : %d\n",FLT_MIN_10_EXP);
    printf("float max exp : %d\n", FLT_MAX_EXP);
    printf("float max 10 exp : %d\n", FLT_MAX_10_EXP);
    printf("float min : %d\n", FLT_MIN);
    printf("float max : %d\n", FLT_MAX);
    printf("float epsilon : %d\n", FLT_EPSILON);
    printf("float rounds : %d\n", FLT_ROUNDS);
    return 0;
}
