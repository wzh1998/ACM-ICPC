/*
* @Author:  zihaowang
* @Email:   zihao.wang1@ucdconnect.ie
* @Website: www.wangzihao.org
* @Date:    2020-08-31 17:31:23
* @Last Modified by:   zihaowang
* @Last Modified time: 2020-08-31 17:31:29
*/

public static void quickSort(int[] arr, int left, int right)  {
		
		if(right <= left) return;
		
		int pivot = arr[left];
		int i, j;
		
		for(i = left, j = right; i < j;) {
			
			while(arr[j] > pivot && i < j) j--;
			
			if(i < j) arr[i++] = arr[j];
			
			while(arr[i] < pivot && i < j) i++;
			
			if(i < j) arr[j--] = arr[i];
		}
		arr[i] = pivot;
		
		quickSort(arr, left, i - 1);
		quickSort(arr, i + 1, right);
		
		return;
	}