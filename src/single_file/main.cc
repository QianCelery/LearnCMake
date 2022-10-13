/**
 * @file main.cc
 * @author your name (you@domain.com)
 * @brief 练习使用cmake构建单个源文件的项目
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
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


int main(int argc,  char **argv)
{
    if (argc < 3) {
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);

    return 0;
}