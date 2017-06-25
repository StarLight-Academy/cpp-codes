#include<iostream>
#include<cmath>

using namespace std;

/*
 * sqrt_: Takes a float number and returns its 
 * square root without using built in function
 * sqrt()
 * 
 * returns: square root of number is possible
 * else returns -1.0.
 */
float sqrt_(float num){
	float low = 1, high = num, mid;
	while(low <= high){
		mid = (low+high)/2;
		float sq = mid * mid;
		if(abs(num - sq) < 0.00001)
			return mid;
		else if (num - sq > 0)
			low = mid;
		else
			high = mid;
	}
	return -1.0;
}


int main(){
	float num, res;
	
	//Take input
	cout<<"\n Enter number to find Square root: ";
	cin>>num;
	
	// Find Square Root
	res = sqrt_(num);
	
	// Display N/A if the root is not applicable
	// Else print result
	if(res < 0){
		cout<<"\n N/A";
	}else{
		cout<<"\n The square root of "<<num<<" is: "<<res;
	}
	
	return 0;
}