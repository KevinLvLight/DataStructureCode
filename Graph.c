#define INFINITY MAX_VAL
#define MAX_VEX 30
typedef int InfoType;
typedef int VexType;
typedef int ArcValType;
typedef int ArcInfoType;
typedef enum{
    DG, AG, WDG, WAG
}GraphKind;// different kinds of Graph
//邻接表
typedef struct LinkNode
{
    int adjvex;
    InfoType info;
    struct LinkNode *nextarc;
}LinkNode;
typedef struct VexNode
{
    VexType data;
    int degree;
    LinkNode *firstarc;
}VexNode;
typedef struct ArcType
{
    VexType vex1, vex2;
    InfoType info;
}ArcType;
typedef struct 
{
    GraphKind kind;
    int vexnum;
    VexNode AdjList[MAX_VEX];
}ALGraph;

//结点定位
int LocateVex(ALGraph *G, VexType *vp){
    int k;
    for (k = 0; k < G->vexnum; k++)
        if (G->AdjList[k].data == *vp) return k;
    return -1;
}
//添加节点
int AddVertex(ALGraph *G, VexType *vp){
    int k, j;
    if (G->vexnum >= MAX_VEX)
    {
        printf("Vertex Overflow!\n");
        return -1;
    }
    if (LocateVex(G, vp) != -1)
    {
        printf("Vertex has existed!\n");
        return -1;
    }
    G->AdjList[G->vexnum].data = *vp;
    G->AdjList[G->vexnum].degree = 0;
    G->AdjList[G->vexnum].firstarc = NULL;
    k = ++G->vexnum;
    return k;
}
//添加弧
int AddArc(ALGraph *G, ArcType *arc){
    int k, j;
    LinkNode *p, *q;
    k = LocateVex(G, &arc->vex1);
    j = LocateVex(G, &arc->vex2);
    if (k == -1 || j == -1)
    {
        printf("Arc's Vertex do not existed!\n");
        return -1;
    }
    p = (LinkNode*)malloc(sizeof(LinkNode));
    p->adjvex = arc->vex1;
    p->info = arc->info;
    p->nextarc = NULL;
    if (G->kind == AG || G->kind == WAG)
    {
        q->nextarc = G->AdjList[k].firstarc;
        G->AdjList[k].firstarc = q;
        q->nextarc = G->AdjList[j].firstarc;
        G->AdjList[j].firstarc = p;
    }else
    {
        q->nextarc = G->AdjList[k].firstarc;
        G->AdjList[k].firstarc = q;
    }
    return 1;
}

//邻接矩阵
typedef struct AdjType
{
    ArcValType ArcVal;
    ArcInfoType ArcInfo;
}AdjType;
typedef struct ArcType
{
    VexType vex1,vex2;
    ArcValType ArcVal;
    ArcInfoType ArcInfo;
}ArcType;
typedef struct 
{
    GraphKind kind;
    int vexnum, arcnum;
    VexType vexs[MAX_VEX];
    AdjType adj[MAX_VEX][MAX_VEX];
}MGraph;

int LocateVex(MGraph *G, VexType *vp){
    int k;
    for ( k = 0; k < G->vexnum; k++)
    {
        if (G->vexs[k] == *vp)
        {
            return k;
        }
    }
    return -1;
}

int AddVertex(MGraph *G, VexType *vp){
    int k, j;
    if (G->vexnum >= MAX_VEX)
    {
        printf("Vextex Overflow!\n");
        return -1;
    }
    if(LocateVex(G, vp) != -1){
        printf("Vertex has existed!\n");
        return -1;
    }
    k = G->vexnum;
    G->vexs[G->vexnum++] = *vp;
    if(G->kind == DG || G->kind == AG){
        for ( j = 0; j < G->vexnum; j++)
        {
            G->adj[j][k].ArcVal = G->adj[k][j].ArcVal = 0;
        }else{
            for ( j = 0; j < G->vexnum; j++)
            {
                G->adj[j][k] = INFINITY;
                G->adj[k][j] = INFINITY;
            }
        }
    }
    return k;
}

//邻接表深度优先
typedef enum{FALSE, TRUE} BOOLEAN;
BOOLEAN visited[MAX_VEX];
void DFS(ALGraph *G, int v){
    LinkNode *p;
    visited[v] = TRUE;
    Visit[v];//访问函数，可以为打印输出值
    p = G->AdjList[v].firstarc;
    while (p != NULL)
    {
        if (!visited[p->adjvex])
        {
            DFS(G, p->adjvex);
        }
        p = p->nextarc;     
    }   
}
void DFS_traverse_Graph(ALGraph *G){
    int v;
    for ( v = 0; v < G->vexnum; v++)
    {
        visited[v] = FALSE;
    }
    for ( v = 0; v < G->vexnum; v++)
    {
        if (!visited[v])
        {
            DFS(G, v);
        }
    }
}

//邻接表广度优先
typedef struct Queue
{
    int elem[MAX_VEX];
    int front, rear;
}Queue;

void BFS_traverse_Graph(ALGraph *G){
    int k, v, w;
    LinkNode *p;
    Queue *Q;
    Q = (Queue*)malloc(sizeof(Queue));
    Q->front = Q->rear = 0;
    for ( k = 0; k < G->vexnum; k++)
    {
        visited[k] = FALSE;
    }
    for ( k = 0; k < G->vexnum; k++)
    {
        v = G->AdjList[k].data;
        if (!visited[v])
        {
            Visit[v];
            visited[v] = TRUE;
            Q->elem[++Q->rear] = v;
            while (Q->front != Q->rear)
            {
                w = Q->front != Q->rear;
                p = G->AdjList[w].firstarc;
                while (p != NULL) 
                {
                    if (! visited[p->adjvex])
                    {
                        Visit[p->adjvex];
                        visited[p->adjvex] = TRUE;
                        Q->elem[++Q->rear] = p->adjvex;
                        p = p->nextarc;
                    }
                }
            }
        }
    }
}

//一种简单的图的定义
typedef struct 
{
    int num;//顶点编号
    InfoType info;//顶点其他信息
}VertexType;
typedef struct 
{
    int edges[MAX_VEX][MAX_VEX];
    int n, e;//顶点数，边数
    VertexType vexs[MAX_VEX];
}MGraph;


