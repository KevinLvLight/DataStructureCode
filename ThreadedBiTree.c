#define MAX_NODE 50

typedef enum{
    Link,//表示指针
    Thread//表示线索
}PointerTag;

typedef int ElemType;

typedef struct BiThrNode
{
    ElemType data;
    struct BiThrNode *Lchild, *Rchild;
    PointerTag Ltag, Rtag;
}BiThrNode;

void preorder_Threading(BiThrNode *T){
    BiThrNode *stack[MAX_NODE];
    BiThrNode *last = NULL, *p;
    int top = 0;
    if (T != NULL)
    {
        stack[++top] = T;
        while (top > 0)
        {
            p = stack[top--];
            if (p->Lchild != NULL)
            {
                p->Ltag = 0;
            }else
            {
                p->Ltag = 1;
                p->Lchild = last;
            }
            if (last != NULL)
            {
                if (last->Rchild != NULL)
                {
                    last->Rtag = 0;
                }else
                {
                    last->Rtag = 1;
                    last->Rchild = p;
                }
            }
            last = p;
            if (p->Rchild != NULL)
            {
                stack[++top] = p->Rchild;
            }
            if (p->Lchild != NULL)
            {
                stack[++top] = p->Lchild;
            }   
        }
        
    }
    
}

void inorder_Threading(BiThrNode *T){
    BiThrNode *stack[MAX_NODE];
    BiThrNode *last = NULL, *p;
    int top = 0;
    while (p != NULL || top > 0)
    {
        if (p != NULL)
        {
            stack[++top] = p;
            p = p->Lchild;
        }else
        {
            p = stack[top--];
            if (p->Lchild != NULL)
            {
                p->Ltag = 0;
            }else
            {
                p->Ltag = 1;
                p->Lchild = last;
            }
            if (last != NULL)
            {
                if (p->Rchild != NULL)
                {
                    p->Rtag = 0;
                }else
                {
                    p->Rtag = 1;
                    p->Rchild = last;
                }
            }
            last = p;
            p = p->Rchild;
        }
        last->Rtag = 1;
    }
}