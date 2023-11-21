#include<stdio.h>

void merge(int arr[],int low,int mid,int high){
	int temp[(int)(sizeof(arr)/sizeof(arr[0]))];
	int k=0,i = low,j=mid+1;
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=high){
		temp[k++] = arr[j++];
	}
	
	for(int i=low;i<=high;i++){
		arr[i] = temp[i-low];
	}
}


void mergeSort(int arr[],int low,int high){
	if(low>=high){
		return;
	}
	int mid = (low + high)/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
}



int main(){
	int arr[] = {5,4,3,2,1};
	int n = 5;
	mergeSort(arr,0,n);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
