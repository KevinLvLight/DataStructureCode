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
//单链表遍历
void traverse_List(Node* pHead){
    Node* p;
    if(pHead == NULL || pHead->Link == NULL){
        printf("LinkList is NULL\n");
    }

    p = pHead;
    while(p->Link){
        printf("%d ", p->Link->Element);
        p = p->Link;
    }
}
//查找数据为value的结点
Node* find_List(List pHead, int value){
    Node* pTmp;
    if(pHead == NULL || pHead->Link == NULL){
        printf("Node is NULL\n");
        return NULL;
    }
    pTmp = pHead;
    while(pTmp->Link){
        //printf("%d ", pTmp->Link->Element);
        if(pTmp->Link->Element == value){
            pTmp = pTmp->Link;
            return pTmp;
        }
        pTmp = pTmp->Link;
    }
    return NULL;
}
//单链表插入,此例子从头结点后插入
void insert_Node(Node *p){
	T i;
	Node* node;
	printf("请输入结点数据值：\n");
	scanf("%d", &i);
    node = NewNode3(i);
    //node->Element = i;
    node->Link = p->Link;
    p->Link = node;
	return;
}
//删除某值
void delete_List(Node* pHead, int data){
    if(pHead == NULL || pHead->Link == NULL){
        printf("Node is NULL\n");
        return;
    }
    while(1){
        int flag = -1;
        Node* pCur;
        Node* pPre;
        pCur = pHead->Link;
        pPre = pHead;
        while(pCur){
            if(pCur->Element == data){
                pPre->Link = pCur->Link;
                flag = 1;
                break;
            }

            pCur = pCur->Link;
            pPre = pPre->Link;
        }

        if(flag == 1){
            free(pCur);
            printf("结点删除成功！\n");
			return;
        }else
        {
            printf("此链表找不到此值！\n");
			return;
        }
        
    }
}
//单链表逆序,非递归方式
Node* reverseLinkList(List list){
    Node* p = NULL;
    Node* pNd = NULL;
    Node* pTmp = NULL;
    if(list == NULL || list->Link == NULL){     
        return list;
    }
    p = list;
    while(p){
        pTmp = p->Link;
        p->Link = pNd;
        pNd = p;
        p = pTmp;
    }
	return pNd;

}
//单链表逆序，递归方式
Node* In_reverseLinkList(List list){
    
    Node* pNd = NULL;
    
    if(list == NULL || list->Link == NULL){     
        return list;
    }
	//循环指向最后一个
    pNd = In_reverseLinkList(list->Link);
	//颠倒了链表方向
	list->Link->Link = list;
	list->Link = NULL;
    //返回倒置后链表头，即倒置前链表最后一个节点
	return pNd;

}
void main(){
    List list;
    list = BuildList();
    PrintList(list);
    //Clear(&list);
    //PrintList(list);
    PrintList(In_reverseLinkList(list));
}
