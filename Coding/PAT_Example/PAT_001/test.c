//
//  test.c
//  PAT_Example
//
//  Created by 启业云03 on 2022/1/24.
//

#include "test.h"

int add(int num1, int num2) {
    return num1 + num2;
}

void test_add() {
    // 手动输入
    int x, y;
    printf("请输入第一个数：");
    scanf("%d", &x);
    printf("请输入第二个数：");
    scanf("%d", &y);
    // add
    int num = add(x, y);
    printf("两数之和：%d + %d = %d \n", x, y, num);
}
