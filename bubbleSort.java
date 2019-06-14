public void bubbleSort(int[] arr){
		/**
         * 冒泡排序
         * flag为标志，如果某次排序过程中无数据交换，则视为已有序。
         */

		int len = arr.length;
		boolean flag = false;
		
        if(len <= 1) return;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len - i - 1; j++){
                if(arr[j] > arr[j + 1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    flag = true;
                }
            }
            if(!flag) break;
        }

}