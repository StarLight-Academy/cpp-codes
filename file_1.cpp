#include<iostream>
#include<fstream>

using namespace std;

//Writting to file
int main(){
	ofstream f;
	f.open("files/trial.txt");
	
	f << "Does this Work?";
	
	f.close();
	return 0;
}