#include<iostream>

using namespace std;

void print_arr(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout<<*(arr+i)<<" at address "<<arr<<endl;
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	print_arr(arr, 8);
	return 0;
}