/**
 * C语言实现冒泡排序，直接实现优化后的情况
 * 优化是指：设置一个标记，当某趟排序中未发生交换即视为排序完成
*/
void bubbleSort(int arr[], int n){
    int i, j;
    int temp;
    int flag = 0;
    for ( i = 0; i < n - 1; i++)
    {
        for ( j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1]) // 此处可根据排序要求进行改变
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;

                flag = 1;
            }
        }

        if (!flag)
        {
            break;
        }
    }
}