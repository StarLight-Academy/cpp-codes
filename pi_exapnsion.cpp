#include<iostream>
#include<cmath>


using namespace std;

int main(){
	double pi = 1.0;
	int i = 3, j = 1;
	
	while((1.0 / i) > 1e-7){
		pi += pow(-1, j) * (1.0 / i);
		j++;
		i += 2;
	}
	
	cout<<4.0 * pi;
	return 0;
	
}