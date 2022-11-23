//
//  main.c
//  栈-括号匹配
//
//  Created by 林祥 on 2022/2/16.
//

#include <stdio.h>

#define MaxSize 20
#define ElemType char

typedef struct {
    char data[MaxSize]; // 数组存放元素
    int top;            // 栈顶指针
}SqStack;

// 初始化栈
void InitStack(SqStack &S) {
    S.top = -1;
}

// 判断栈是否为空
bool StackEmpty(SqStack &S) {
    if( S.top == -1) {
        return true;
    }
    return false;
}

// 进栈
bool Push(SqStack &S, char x) {
    // 是否栈满
    if (S.top == MaxSize - 1) {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

// 出栈
bool Pop(SqStack &S, char &x) {
    // 若为栈空
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

int countStr(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

bool bracketCheck(char str[]) {
    SqStack S;  // 声明栈
    InitStack(S);   // 初始化栈
    
    int len = countStr(str);
    for (int i = 0; i < len ; i++) {
        char elem = str[i];
        if (elem == '(' || elem == '{' || elem == '[') {
            Push(S, elem);
        } else {
            if (StackEmpty(S)) {  // 扫描到右括号，若当前栈为空
                return false;   // 匹配失败
            }
            char topElem;
            Pop(S, topElem);    // 栈顶出栈
            
            if (topElem == '(' && elem == ')') {
                continue;
            }
            if (topElem == '[' && elem == ']') {
                continue;
            }
            if (topElem == '{' && elem == '{') {
                continue;
            }
        }
    }
    // 最后判断栈是否为空
    return StackEmpty(S);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    bool A = bracketCheck("[][");
    if (A) {
        printf("成功");
    } else {
        printf("失败");
    }
    
    return 0;
}
