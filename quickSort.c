#include<stdio.h>

int partition(int arr[],int l, int h){
	int temp,pivot = arr[l];
	int i=l,j=h;
	while(i<j){
		while(arr[i]<=pivot && i<h){
			i++;
		}
		while(arr[j]>pivot && j>l){
			j--;	
		}
		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = pivot;
	arr[l] = arr[j];
	arr[j] = pivot;
	return j;
}

void quickSort(int arr[],int s,int e){
	if(s>=e){
		return;
	}
	int pivot = partition(arr,s,e);
	quickSort(arr,s,pivot-1);
	quickSort(arr,pivot+1,e);
}

int main(){
	int arr[] = {5,4,3,2,1};
	quickSort(arr,0,5);
	for(int i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
