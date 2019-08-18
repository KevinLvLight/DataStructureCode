/**
 * ADT List
 * 线性表的顺序实现
 */

#include<stdio.h>

#define MaxSize 50                  //定义线性表的最大长度
#define InitSize 100                //线性表长度的初始定义
#define SizeIncrement 10            //动态分配增量

#define FALSE 0
#define TRUE 1

typedef int BOOL;
typedef int ElemType;               //定义数据元素的类型

/**
 * 静态分配
 */
typedef struct{
    ElemType data[MaxSize];         //顺序表的元素，使用了数组
    int length;                     //顺序表的当前长度
}SqList;                            //顺序表类型定义

/**
 * 创建一个空顺序表
 */
void CreateList(SqList *lst){
    lst->length = 0;
}
/* 
/**
 * 动态分配
 * 正确性未知
 */
typedef struct{
    ElemType *data;                 //指示动态分配数组的指针
    int MaxSize;                    //数组的最大容量，即为当前分配的容量
    int length;                     //数组的当前长度
}SeqList;
int InitList_Sq(SeqList *L){
    L->data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
    if(! L-> ) return FALSE;
    L.length = 0;
    L.MaxSize = InitSize;
    return TRUE;
}
*/

/**
 * 顺序表判空
 * 如果顺序表的length为0则为空，返回TRUE
 */
BOOL isEmpty(SqList lst){
    return lst.length == 0;
}
/**
 * 顺序表判满
 * 如果顺序表的length和MaxSize相同则为满，返回TRUE
 */
BOOL isFull(SqList lst){
    return lst.length == MaxSize;
}
/**
 * 获取顺序表的长度
 * 直接返回length值
 */
int getSize(SqList lst){
    return lst.length;
}
/**
 * 移去所有元素，线性表称为空表
 * 直接将length值清零
 */
void Clear(SqList *lst){
    lst->length = 0;
}
/**
 * 插入数据
 */
BOOL insert(SqList *lst, int pos, ElemType x){
    int i;
    if(isFull(*lst)){
        printf("Overflow!");
        return FALSE;
    }
    if(pos < 0 || pos > lst->length){
        printf("Out of Bounds!");
        return FALSE;
    }
    for(i = lst->length - 1; i >= pos; i--){
        lst->data[i + 1] = lst->data[i];
    }
    lst->data[pos] = x;
    lst->length++;
    return TRUE;
}
/**
 * 在原表中删除某元素
 */
BOOL Remove(SqList *lst, int pos, T* x){
    int i;
    if(isFull(*lst)){
        printf("Overflow!");
        return FALSE;
    }
    if(pos < 0 || pos > lst->length){
        printf("Out of Bounds!");
        return FALSE;
    }
    *x = lst->data[pos];
    for(i = pos + 1; i < lst->length; i++){
        lst->data[i-1] = lst->data[i];
    }
    lst->length--;
    return TRUE;
}
/**
 * 赋值表中某位置的数据
 */
BOOL Retrieve(SqList lst, int pos, T* x){
    if(pos < 0 || pos > lst->length){
        printf("Out of Bounds!");
        return FALSE;
    }
    *x = lst->data[pos];
    return TRUE;
}
/**
 * 替换表中某位置的元素值
 */
BOOL Replace(SqList *lst, int pos, T* x){
    if(pos < 0 || pos > lst->length){
        printf("Out of Bounds!");
        return FALSE;
    }
    lst->data[pos] = x;
    return TRUE;
}

/**
 * 按值查找元素，返回坐标
 * 考虑数据不唯一情况
 */
int[] LocateElem(SqList lst, ElemType e){
    int ans[MaxSize];
    int i,j = 0;
    for(i = 0; i < lst.length; i++){
        if(lst.data[i] == e){
            ans[j++] = i + 1;
        }
    }
    return ans;
}

/*----------------------------------------------以下为王道习题------------------------------------- */

/**
 * 顺序表逆置
 */

void Reverse(SqList &L){
    ElemType temp;
    for(i = 0; i < L.length / 2; i++){
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}
/**
 * 从顺序表中删除值为x的元素
 */
void del_x(SqList &L, ElemType x){
    int k = 0;
    int i;
    for(i = 0; i < L.length; i++){
        if(L.data[i] != x){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}
