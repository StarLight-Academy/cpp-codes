#include<iostream>
#include<time.h>

using namespace std;

int* generate_random_arr(int size){
	static int arr[1000];
	time_t t;
	unsigned int sval = (unsigned)time(&t);
	srand(sval);
	for(int i = 0; i < size; i++){
		arr[i] = rand();
	}
	return arr;
}

int main(){
	int size;
	cout<<"Enter size of the array: ";
	cin>>size;
	int* arr = generate_random_arr(size);
	cout<<"\n\nThe Array is:\n\n";
	for(int i = 0; i < size; i++){
		cout<<*(arr+i)<<" ";
	}
	cout<<endl;
	return 0;
}