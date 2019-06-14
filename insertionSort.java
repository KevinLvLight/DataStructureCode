public void insertionSort(int[] arr){
	
		/**
         * 插入排序
         * 左边部分视为已排序部分，依次插入右部分数据
         * 左边起始只有一个元素
         */
        int len = arr.length;
		
        if(len <= 1) return;
        for(int i = 0; i < len; i++){
            int value = arr[i];
            int j = i - 1;
            for(; j >= 0; j--){
                if(arr[j] > value){
                    arr[j + 1] = arr[j];
                }else{
                    break;
                }
            }
            arr[j + 1] = value;
        }
    }
