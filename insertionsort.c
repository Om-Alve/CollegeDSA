#include<stdio.h>

void insertionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		int j=i;
		while(j>0 && arr[j-1]>arr[j]){
			int temp  = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
}
}
int main(){
	int arr[] = {5,4,3,2,1};
	insertionSort(arr,5);
	for(int i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

