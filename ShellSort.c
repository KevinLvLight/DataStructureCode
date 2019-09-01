//希尔排序 课本以及王道的都很令人费解
void ShellSort(int arr[], int n){
    int i, j, d, temp;
    d = n/2;
    while (d > 0)
    {
        for ( i = d; i < n; i++)
        {
            j = i - d;
            while (j >= 0 && arr[j] > arr[j + d])
            {
                temp = arr[j];
                arr[j] = arr[j + d];
                arr[j + d] = temp;
                j = j - d;
            }
        }
        d = d / 2;
    }
}

//严蔚敏版
void ShellInsert(int arr[], int dk, int length){
    //arr[0]是暂存单元，应该不存储数据，因此数组的长度length应该比待排序数据总数多1
    int i, j;
    for ( i = dk + 1; i < length; i++)
    {
        if (arr[i] < arr[i - dk])
        {
            arr[0] = arr[i];
            for ( j = i - dk; j > 0 && arr[0] < arr[j]; j -= dk)
            {
                arr[j + dk] = arr[j];
            }
            arr[j + dk] = arr[0];
        }
    }
}
void ShellSort(int arr[], int alta[], int t){
    //dlta是增量序列，长度为t
    int i;
    for ( i = 0; i < t; i++)
    {
        ShellInsert(arr, dlta[i]);
    }
    
}