#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//Writting to CSV file
int main(){
	ofstream f;
	f.open("files/players.csv");
	
	string player_name;
	float rating;
	double income;
	
	f << "Name" << ',' << "Rating" << ',' << "Income" << endl;
	
	cout<<"Enter Player Name, Rating, Income"<<endl;
	cout<<"Press Ctrl+C to quit"<<endl;
	
	while(cin >> player_name >> rating >> income){
		f << player_name << "," << rating << "," << income << endl;
	}
	
	f.close();
	return 0;
}