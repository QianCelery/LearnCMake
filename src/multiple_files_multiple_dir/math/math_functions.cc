#include <stdlib.h>

/**
 * @brief 计算数的幂
 * 
 * @param base : 底数
 * @param exponent 指数
 * @return double 
 */
double power(double base, int exponent)
{
    double result = base;
    if (exponent == 0) {
        return 1;
    }

    for (int i = 1; i < exponent; ++i) {
        result *= base;
    }
    
    return result;
}