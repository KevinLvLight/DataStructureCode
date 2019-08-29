/**
 * 首先定义简单的二叉树的结点类型
 * 程序中使用的指向结点类型的指针类型形式参数，其实也可以直接生命成BTree类型
*/
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *lchild;
    struct node *rchild;
}BTNode, *BTree;

/**
 * 以下将递归非递归放在一起
*/

void PreOrder(BTNode *b){
    if(b != NULL){
        printf("%c", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

//非递归，借助一个栈，每次都是栈顶先出栈，即栈顶是最先访问的数据
//先序遍历的思想是先根，再左孩子，再右孩子
//此处及以后栈简单地使用数组表示

void IPreOrder(BTNode *b){
    BTNode *St[MaxSize], *p;
    int top = -1;
    if(b != NULL){
        top++;
        St[top] = b;
        while (top > -1)
        {
            p = St[top];
            top--;
            printf("%c", p->data);
            if(p->rchild) St[top++] = p->rchild;
            if(p->lchild) St[top++] = p->lchild;
        }
    }
    printf("\n");
}

void InOrder(BTNode *b){
    if(b != NULL){
        InOrder(b->lchild);
        printf("%c", b->data);
        InOrder(b->rchild);
    }
}

void IInOrder(BTNode *b){
    BTNode *St[MaxSize], *p;
    int top = -1;
    if (b != NULL)
    {
        p = b;
        while (top > -1 || p != NULL)
        {
            while (p != NULL)
            {
                top++;
                St[top] = p;
                p = p->lchild;
            }
            if(top > -1){
                p = St[top];
                top--;
                printf("%c", p->data);
                p = p->rchild;
            }
        }
         printf("\n");
    }
}

void PostOrder(BTNode *b){
    if(b != NULL){
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c", b->data);
    }
}

void IPostOrder(BTNode *b){
    BTNode *St[MaxSize], *p;
    int top = -1;
    int flag;
    if (b != NULL)
    {
        do
        {
            while (b != NULL) // send all left child into stack
            {
                top++;
                St[top] = b;
                b = b->lchild;
            }

            p = NULL; // a pointer to the previous visited node of current node
            flag = 1; // note the node of b has been visited

            while (top != -1 && flag)
            {
                b = St[top]; // get the current node
                if (b->rchild == p) // if right child is not existed or has been visited, then visit the current node
                {
                    printf("%c", b->data);
                    top--;
                    p = b;
                }else{
                    b = b->rchild; // b point to the right child
                    flag = 0; //set not visited
                }
            }  
        } while (top != -1);
    } 
}

/**
 * 层次遍历
*/

void TraverseLevel(BTNode *b){
    BTNode *Qu[MaxSize];
    int front, rear;
    front = rear = 0;
    if (b != NULL)
    {
        printf("%c", b->data);
    }
    rear++;
    Q[rear] = b;
    while (rear != front)
    {
        front = (front + 1) % MaxSize;
        b = Qu[front];
        if (b->lchild != NULL)
        {
            printf("%c", b->lchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->lchild;
        }
        if (b->rchild != NULL)
        {
            printf("%c", b->rchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->rchild;
        }  
    }
    printf("\n");
}