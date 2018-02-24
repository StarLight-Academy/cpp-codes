#include<iostream>
#include<stdlib.h>

using namespace std;

void display(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
	}
}

void bsort(int arr[], int size){
	for(int i = 0; i < size - 1; i++){
		cout<<"\n\nIteration"<<i+1<<" - In: ";
		display(arr, size);
		for(int j = 0; j < size - 1 - i; j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			cout<<endl;
			display(arr, size);
		}
	}
}

void isort(int arr[], int size){
	for(int i = 0; i < size - 1; i++){
		cout<<"\n\nIteration"<<i+1<<" - In: ";
		display(arr, size);
		int key = arr[i+1];
		int j = i;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
		cout<<"\n- Out: ";
		display(arr, size);
	}
}

void ssort(int arr[], int size){
	for(int i = 0; i < size - 1; i++){
		cout<<"\n\nIteration"<<i+1<<" - In: ";
		display(arr, size);
		int small = i;
		for(int j = i + 1; j < size; j++){
			if(arr[j] < arr[small]){
				small = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[small];
		arr[small] = temp;
		cout<<"\n- Out: ";
		display(arr, size);
	}
}

int main(){
	int arr[] = {26, 21, 20, 23, 29, 17};
	int arr1[] = {26, 21, 20, 23, 29, 17};
	int arr2[] = {26, 21, 20, 23, 29, 17};
	int size = 6;
	cout<<"\nBUBBLE SORT";
	bsort(arr, size);
	cout<<"\n\nINSERTION SORT";
	isort(arr1, size);
	cout<<"\n\nSELECTION SORT";
	ssort(arr2, size);
	return 0;
}