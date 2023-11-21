#include<stdio.h>



int partition(int arr[],int l,int h){
	int pivot = arr[l];
	int i=l,j=h;
	while(i<j){
		while(arr[i] <= pivot && i<=h-1){
			i++;
		}
		while(arr[j] > pivot && j>=l+1){
			j--;
		}
		if(i<j){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[l];
	arr[l] = arr[j];
	arr[j] = temp;
	return j;
}

void quickSort(int arr[],int l,int h){
	if(l>=h){
		return;
	}
	int p = partition(arr,l,h);
	quickSort(arr,l,p-1);
	quickSort(arr,p+1,h);
}

int main(){
	int arr[] = {5,4,3,2,1};
	quickSort(arr,0,5);
	for(int i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
