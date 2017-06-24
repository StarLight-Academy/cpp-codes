#include<iostream>
#include<time.h>

using namespace std;

/*
 * generate_random_arr: Takes size of the array
 * and generate a random array of given size
 *
 * returns: A pointer to the random array
 */
int* generate_random_arr(int size){
	static int arr[1000];
	time_t t;
	
	// Get current time
	unsigned int sval = (unsigned)time(&t);
	// seed random number generator
	srand(sval);
	for(int i = 0; i < size; i++){
		arr[i] = rand();
	}
	return arr;
}

int main(){
	int size;
	
	// Take size as input
	cout<<"Enter size of the array: ";
	cin>>size;
	
	// Get pointer to the generated array
	int* arr = generate_random_arr(size);
	
	// Print the array
	cout<<"\n\nThe Array is:\n\n";
	for(int i = 0; i < size; i++){
		cout<<*(arr+i)<<" ";
	}
	cout<<endl;
	return 0;
}