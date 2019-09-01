public static void ShellSort(int[] arr) {
    int length = arr.length;
    //区间
    int gap = 1;
    while (gap < length) {
        gap = gap * 3 + 1;
    }
    while (gap > 0) {
        for (int i = gap; i < length; i++) {
            int tmp = arr[i];
            int j = i - gap;
            //跨区间排序
            while (j >= 0 && arr[j] > tmp) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = tmp;
        }
        gap = gap / 3;
    }
}