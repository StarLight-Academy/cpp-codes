#include<iostream>
#include<cmath>

using namespace std;

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
	
	cout<<"\n Enter number to find Square root: ";
	cin>>num;
	
	res = sqrt_(num);
	
	if(res < 0){
		cout<<"\n N/A";
	}else{
		cout<<"\n The square root of "<<num<<" is: "<<res;
	}
	
	return 0;
}