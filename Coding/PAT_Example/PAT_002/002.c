//
//  002.c
//  PAT_Example
//
//  Created by 启业云03 on 2022/1/24.
//

/*
 读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

 输入格式：
 每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100次方

 输出格式：
 在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

 输入样例：
 1234567890987654321123456789
 输出样例：
 yi san wu
 */

#include "002.h"
#include "math.h"

void test_ShowNumber(void) {
    printf("int size: %lu byte\n",sizeof(int));
    printf("short size: %lu byte\n",sizeof(short int));
    printf("long size: %lu byte\n",sizeof(long int));
    printf("long long size: %lu byte\n",sizeof(long long int));
    /*
     int size: 4 byte
     short size: 2 byte
     long size: 8 byte
     long long size: 8 byte
     
     int占32位，取值范围为-2147483648～2147483647（-2^{31} \sim 2^{31}-1）
     无符号64位，其最大为2的64次幂，远小于10的100次幂，这样当输入夫人数字n很大时，就不符合题目要求。
    */
    
    char x[100];
    scanf("%s", x);
    printf("输入值为：%s \n", x);
    
    // 计算和
    int sum = 0;
    for (int i = 0; x[i] != '\0'; i++) {
        int realNum = x[i] - '0';       // 字符串中数字是ASCII码，减去'0'才能得到真正的数字
        sum += realNum;
        printf("%d \n", sum);
    }
    
    char y[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    
    
    
}
