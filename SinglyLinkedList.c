#include<stdio.h>
#include<cstdlib>

#define IS_FULL(ptr) (!(ptr))

/*
//用户自定义的元素类型T
typedef struct entry{
    int Key;
    char Data;
}Entry;
typedef Entry T;
 */
//元素类型也可以简单定义为基本的数据类型
typedef int T;

//单链表每个结点的结构类型
typedef struct node
{
    T Element;
    struct node* Link;
}Node;

//简单定义单链表类型List
typedef Node* List;

//创建元素
T* InputElement(){
    static T a;
    scanf("%d", &a);
    return &a;
}
//显示元素
void PrintElement(T x){
    printf("%d ", x);
}
//构造新结点

//方法一
Node* NewNode(){
    Node* p = (Node*)malloc(sizeof(Node));
    if(IS_FULL(p)){
        fprintf(stderr, "The memory is full!\n");
        exit(1);
    }
    p->Element = *InputElement();
    p->Link = NULL;
    return p;
}
//方法二
Node* NewNode1(){
    Node* p = (Node*)malloc(sizeof(Node));
    if(IS_FULL(p)){
        fprintf(stderr, "The memory is full!\n");
        exit(1);
    }
    
    p->Link = NULL;
    return p;
}
//方法三
Node* NewNode3(T x){
    Node* p = (Node*)malloc(sizeof(Node));
    if(IS_FULL(p)){
        fprintf(stderr, "The memory is full!\n");
        exit(1);
    }
    p->Element = x;
    p->Link = NULL;
    return p;
}
//建立单链表
List BuildList(){
    Node *p;
    Node *r = NULL;
    Node *first = NULL;
    char c;
    printf("Another element?y/n\n");
    while((c = getchar()) == '\n');
    while(tolower(c) != 'n'){
        p = NewNode();
        if(first != NULL)
            r->Link = p;
        else
            first = p;
        r = p;

        printf("Another element?y/n\n");
        while((c = getchar()) == '\n');         
    }
    return first;
}
//输出单链表
void PrintList(List first){
    printf("\nThe list contains:\n");
    for(; first; first = first->Link)
        PrintElement(first->Element);
    printf("\n\n");
}
//清空单链表
void Clear(List* first){
    Node *p = *first;
    while(*first){
        p = (*first)->Link;
        free(*first);
        *first = p;
    }
}

void main(){
    List list;
    list = BuildList();
    PrintList(list);
    Clear(&list);
    PrintList(list);
}