#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//Reading From file
int main(){
	ifstream f;
	f.open("files/trial.txt");
	
	string str, str2;
	
	while(f >> str){
		str2 += str;
		str2 += " ";
	}
	
	cout << str2;
	
	f.close();
	return 0;
}