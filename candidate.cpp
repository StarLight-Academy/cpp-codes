#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class CANDIDATE{
private:
	int Cno;
	char Cname[21];
	int Score;
public:
	void Enter(int Cno, char* Cname, int Score);
	void Display();
	int RScore(){return Score;}
	int RCno(){return Cno;}
	char* RCname(){return Cname;}
};

void CANDIDATE::Enter(int Cno, char* Cname, int Score){
	this->Cno = Cno;
	strcpy(this->Cname, Cname);
	this->Score = Score;
}

void CANDIDATE::Display(){
	cout<<"NO: "<<Cno<<"\tName: "<<Cname<<"\tScore: "<<Score<<endl;
}

void Enrol(CANDIDATE candidate_list[], int size){
	ofstream file;
	file.open("files/CANDIDATE.dat", ios::out | ios::app);

	for(int i = 0; i < size; i++){
		file.write((char *)(&candidate_list[i]), sizeof(candidate_list[i]));
	}

	file.close();
}

void GetPass(){
	CANDIDATE candidate;
	ifstream file;
	file.open("files/CANDIDATE.dat");
	int cno, score;
	char Cname[21];

	while(file.read((char *)(&candidate), sizeof(candidate))){
		if(candidate.RScore() >= 33){
			candidate.Display();
		}
	}
	file.close();
}

int main(){
	int choice;
	CANDIDATE candidate[1000];
	int cur_index = 0;
	int cno, score;
	char Cname[21];
	int flag = 0;
	while(1){
		system("cls");
		cout<<"\n\t\t\tMenu\n";
		cout<<"--------------------------------------------";
		cout<<"\n\t1. Add Candidate\n\t2. Enrol Added Candidates\n\t3. Get Passed Candidates\n\t4.Exit\n";
		cout<<"--------------------------------------------";
		cout<<"\n\nEnter Your Choice: ";
		cin>>choice;

		system("cls");
		switch(choice){
			case 1:		cout<<"NO: ";
						cin>>cno;
						cout<<"Name: ";
						cin.ignore();
						cin.getline(Cname, sizeof(Cname));
						cout<<"Score: ";
						cin>>score;
						candidate[cur_index++].Enter(cno, Cname, score);
						break;
			case 2:		Enrol(candidate, cur_index);
						cout<<"\nEnrolled!!";
						break;
			case 3:		GetPass();
						break;
			case 4:		flag = 1;
						break;
			default:	cout<<"\nEnter Right Choice";
		}

		if(flag){
			break;
		}
		
		cout<<"\nPress Enter to Continue";
		getch();
	}
	return 0;
}