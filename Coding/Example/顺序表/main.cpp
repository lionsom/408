//
//  main.c
//  顺序表
//
//  Created by 启业云03 on 2022/2/8.
//

#include <stdio.h>
#include <stdlib.h>

// 宏定义
#define MAXSIZE 10      //定义最大长度
#define ElemType int    //定义顺序表存储的类型，可自行设置

//========================== 初始化 InitList 静态数组 ==========================

// 顺序存储结构的线性表的类型
typedef struct {
    ElemType data[MAXSIZE]; //用『静态数组』存放数据元素
    int length;             //顺序表的当前长度
}SqList;                    //顺序表的类型定义（静态分配方式） Sq:Sequence 顺序、序列

// 顺序表初始化一：静态数组
SqList InitList() {
    SqList L;
    L.length = 0;
    return L;
}

// 顺序表初始化二：静态数组
// C语言中是不存在引用传参，仅仅是取地址符。所以GCC编译不过。
// 解决方案:
//      1.用指针传参代替引用传参（代码如下InitList_2_1）；
//      2.将代码保存成.cpp文件(c++中支持引用)。
void InitList_2(SqList &L) {
    for (int i = 0; i < MAXSIZE; i++) {
        L.data[i] = 0;
    }
    L.length = 0;
}

// 指针传参：静态数组
void InitList_2_1(SqList *L) {
    for (int i = 0; i < MAXSIZE; i++) {
        L->data[i] = 0;    //赋默认值，否则会有脏数据
    }
    L->length = 0;
}

//========================== 初始化 InitList 动态数组 ==========================

typedef struct{
    ElemType *data;     //动态分配数组的指针
    int maxSize;        //顺序表最大容量
    int length;         //顺序表当前长度
}SeqList;               //顺序表的类型定义（动态分配方式）

// 顺序表初始化三：动态分配数组
void InitList_3(SeqList *L) {
    L->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    L->length = 0;
    L->maxSize = MAXSIZE;
}

void IncreaseSize(SeqList &L, int len) {
    ElemType *p = L.data;
    L.data = (ElemType *)malloc((L.maxSize + len) * sizeof(ElemType));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];           //将数据复制到新区域
    }
    L.maxSize = L.maxSize + len;    //顺序表最大长度增加len
    free(p);                        //是否原内存空间
}


//========================== 插入 ==========================

/*
 * 在顺序表 L LL 的第 i ii (1<=i<=L.length+1)个位置上插入新元素 e
 * 判断 i 的位置是否合法
 * 第 i 个元素及气候依次从后移动一个位置
 * 顺序表长度 加1
 */
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i <= 0 || i > L.length + 1) { // 插入位置是否合法
        return false;
    }
    if (L.length >= MAXSIZE) {     // 空间是否已满
        return false;
    }
    for (int j = L.length; i >= j ; j--) {
        L.data[j] = L.data[j-1];    // 将第i个元素及之后的元素向后移动
    }
    L.data[i-1] = e;    // 在位置i处插入e
    L.length++;         // 线性表长度 +1
    return true;
}

//========================== 删除 ==========================

/*
 * 删除顺序表 L LL 中的第 i ii（1<=i<=L.length） 个位置,用引用变量 e ee 返回
 * 判断 i ii 的位置是否合法，否则返回false
 * 合法则将被删除元素赋予引用变量 e,把i+1个元素及其后的所有元素往前移动一个位置，返回true
 */
bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i <= 0 || i > L.length) {
        return false;
    }

    e = L.data[i - 1];   //将被删除的元素赋予e

    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }

    L.length--;
    return true;
}

//========================== 查找 ==========================

/*
 * 在顺序表 L 中查找第一个元素值等于e的元素，并返回其位序
 */
int LocateElem(SqList &L, ElemType &e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;      // 数组下标为e的元素,其位序为  i+1
        }
    }
    return 0;
}

//========================== main ==========================

int main() {
    // insert code here...
    printf("Hello, World!\n");
    
    // 方式一
    SqList L1 = InitList();
  
    // 方式二
    SqList L2;          // 声明一个线性表
    InitList_2(L2);     // 初始化该线性表
    InitList_2_1(&L2);  // 初始化该线性表
    
    // 方式三
    SeqList L3;
    InitList_3(&L3);
    printf("L3最大长度为 %d a",L3.maxSize);
    // 动态扩大空间
    IncreaseSize(L3, 12);
    printf("\nL3动态增加空间后的最大长度为 %d a",L3.maxSize);
    
    return 0;
}
