/**
 * @file main.cc
 * @author your name (you@domain.com)
 * @brief 练习使用cmake构建多个源文件，多个目录的项目
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#ifdef USE_MYMATH
    #include "math/math_functions.h"
#else
    #include <math.h>
#endif


int main(int argc,  char **argv)
{
    if (argc < 3) {
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    

#ifdef USE_MYMATH
    printf("Now we use our own Math libary. \n");
    double result = power(base, exponent);
#else
    printf("Now we use standard libary. \n ");
    double result = pow(base, exponent);
#endif

    printf("%g ^ %d is %g\n", base, exponent, result);

    return 0;
}