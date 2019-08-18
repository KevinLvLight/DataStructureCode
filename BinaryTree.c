typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
/**
 * 二叉树的遍历，递归算法
 */
void PreOrder(BiTree T){
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if (T != NULL)
    {
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if (T != NULL)
    {
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        visit(T);
    }
}
/**
 * 二叉树的遍历，非递归算法
 */
void IPreOrder(BiTree T){
    InitStack(s);
    BiTree p = T;
    push(s, p);
    while (p && !IsEmpty(s))
    {
        pop(s, p);
        visit(p);
        if(p->rchild) push(s, p->rchild);
        if(p->lchild) push(s, p->lchild);
    }
}

void IInOrder(BiTree T){
    InitStack(s);
    BiTree p = T;
    while (p || !IsEmpty(s))
    {
        push(s, p);
        p = p->lchild;
    }else{
        pop(s, p);
        visit(p);
        p = p->rchild;
    }
    
}

void IPostOrder(BiTree T){
    InitStack(s);
    BiTree p = T;
    BiTree r = NULL;
    while (p || !IsEmpty(s))
    {
        push(s, p);
        p = p->lchild;
    }else{
        GetTop(s, p);
        if(p->rchild && p->rchild != r){
            p = p->rchild;
            push(s, p);
            p = p->lchild;
        }else{
            pop(s, p);
            visit(p);
            r = p;
            p = NULL;
        }
    }
}
/**
 * 层次遍历，从上到下，从左到右
 */
void LevelOrder(BiTree T){
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while (!IsEmpty(Q))
    {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild != NULL)
        {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild != NULL)
        {
            EnQueue(Q, p->rchild);
        }
    }
    
}