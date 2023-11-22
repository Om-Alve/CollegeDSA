#include<stdio.h>

void merge(int arr[],int s,int m,int e){
	int temp[e-s];
	int i=s,j=m+1,k=0;
	while(i<=m && j<=e){
		if(arr[i]<arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	while(i<=m){
		temp[k++] = arr[i++];
	}
	while(j<=e){
		temp[k++] = arr[j++];
	}
	for(int i=s;i<=e;i++){
		arr[i] = temp[i-s];
	}
}


void mergeSort(int arr[],int s,int e){
	if(s >= e){
		return;
	}
	int mid = (s+e)/2;
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);
	merge(arr,s,mid,e);
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
