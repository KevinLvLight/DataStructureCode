//小根堆
typedef struct minheap
{
    int Size, MaxHeap;
    int Elements[MaxSize];
}MinHeap;

void AdjustDown(int heap[], int r, int n){
    int child = 2*r;
    int temp = heap[r];
    while (child <= n)
    {
        if (child < n && heap[child] > heap[child + 1])
        {
            child++;
        }
        if (temp <= heap[child])
        {
            break;
        }
        heap[child/2] = heap[child];
        child*=2;
    }
    heap[child/2] = temp;
}

void CreateMinHeap(MinHeap *hp){
    int i;
    int n = hp->Size;
    for ( i = n/2; i > 0; i--)
    {
        AdjustDown(hp->Elements, i, n);
    }
    
}

