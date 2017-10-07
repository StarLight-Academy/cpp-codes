#include<iostream>

using namespace std;

int main() {
	int *ptr;
	int a;
	cin >> a;
	cout<<"\n Address of a: "<<&a;
	ptr = &a;
	cout<<"\n Ptr Value: "<< ptr;
	*ptr += 10;
	cout<<"\n Value of a: "<<a;
	return 0;
}