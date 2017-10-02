#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctime>
#include<conio.h>
#include<fstream>
#define MAX_SIZE 1000

using namespace std;


char* COMPANY_NAME = "\t\t\t   ABC pvt. Ltd.\n\t\t\t B2/23, xyz Colony\n\t\t\t New Delhi - 110003";

class Employee {
private:
	int emp_id;
	char name[21];
	char position[21];
	float grade_pay, basic_pay, ta_basic, ma;

	float calc_epf();
	float calc_vpf();
	float calc_itax();
	float calc_deduce();

	float calc_hra();
	float calc_da();
	float calc_total();
	float calc_ta();
	float calc_total_pay();

	void write_to_console(tm *ltm);
	void write_to_file(tm *ltm);
public:
	void get_data(int, char*, char*, float,
			      float, float, float);
	void print_data();
	int get_id(){ return emp_id; }
	
};

float Employee::calc_epf(){
	return 0.12 * basic_pay;
}

float Employee::calc_vpf(){
	return 0.12 * basic_pay;
}

float Employee::calc_itax(){
	return 0.2 * basic_pay;
}

float Employee::calc_hra(){
	return 0.3 * (basic_pay + grade_pay);
}

float Employee::calc_da(){
	return 1.32 * (basic_pay + grade_pay);
}

float Employee::calc_total(){
	return basic_pay + grade_pay +
		   calc_hra() + calc_da();
}

float Employee::calc_ta(){
	return 1.32 * ta_basic;
}

float Employee::calc_total_pay(){
	return basic_pay + grade_pay + calc_hra() +
		   calc_da() + ta_basic + calc_ta() + ma;
}


float Employee::calc_deduce(){
	return calc_epf() + calc_itax() + calc_vpf();
}

void Employee::get_data(int emp_id, char* name, char* position,
						float grade_pay, float basic_pay,
						float ta_basic, float ma){
	this-> emp_id = emp_id;
	this-> grade_pay = grade_pay;
	this-> basic_pay = basic_pay;
	this-> ta_basic = ta_basic;
	this-> ma = ma;

	strcpy(this->name, name);
	strcpy(this->position, position);
}

void Employee::write_to_console(tm *ltm){
	cout<<COMPANY_NAME<<endl;
	
	cout<<"\t\t\t\t\t\tDate: "<<ltm->tm_mday
		  <<"-"<<1+ltm->tm_mon<<"-"<<1900+ltm->tm_year<<endl<<endl;
	cout<<"\n\tEmployee Number: "<<emp_id<<"\tName: "<<name<<"\t Post: "
		<<position<<endl;
	cout<<"\n\t  Payment\t\t\t\tDeduction"<<endl;
	cout<<"\tBasic Pay: "<<basic_pay<<"\t\t\t\tEPF: "<<calc_epf()<<endl;
	cout<<"\tGrade Pay: "<<grade_pay<<"\t\t\t\tVPF: "<<calc_vpf()<<endl;
	cout<<"\tTotal: "<<calc_total()<<"\t\t\t\tITAX: "<<calc_itax()<<endl;
	cout<<"\tHRA: "<<calc_hra()<<endl;
	cout<<"\tDA: "<<calc_da()<<endl;
	cout<<"\tTABASIC: "<<ta_basic<<endl;
	cout<<"\tTA: "<<calc_ta()<<endl;
	cout<<"\tMA: "<<ma<<endl<<endl;
	cout<<"\tTotal Pay: "<<calc_total_pay()<<"\t\tTotal Deduction:"
		<<calc_deduce()<<endl;
}

void Employee::write_to_file(tm *ltm){
	char file_path[1000] = "files/Employees/";
	strcat(file_path, name);
	strcat(file_path, ".txt");
	
	ofstream fout;
	fout.open(file_path);
	
	fout<<COMPANY_NAME<<endl;
	
	fout<<"\t\t\t\t\t\t\t\t\tDate: "<<ltm->tm_mday
		  <<"-"<<1+ltm->tm_mon<<"-"<<1900+ltm->tm_year<<endl<<endl;
	fout<<"\n\tEmployee Number: "<<emp_id<<"\tName: "<<name<<"\t Post: "
		<<position<<endl;
	fout<<"\n\t  Payment\t\t\t\t\t\tDeduction"<<endl;
	fout<<"\tBasic Pay: "<<basic_pay<<"\t\t\t\t\tEPF: "<<calc_epf()<<endl;
	fout<<"\tGrade Pay: "<<grade_pay<<"\t\t\t\t\tVPF: "<<calc_vpf()<<endl;
	fout<<"\tTotal: "<<calc_total()<<"\t\t\t\t\tITAX: "<<calc_itax()<<endl;
	fout<<"\tHRA: "<<calc_hra()<<endl;
	fout<<"\tDA: "<<calc_da()<<endl;
	fout<<"\tTABASIC: "<<ta_basic<<endl;
	fout<<"\tTA: "<<calc_ta()<<endl;
	fout<<"\tMA: "<<ma<<endl<<endl;
	fout<<"\tTotal Pay: "<<calc_total_pay()<<"\t\tTotal Deduction:"
		<<calc_deduce()<<endl;
	fout.close();
}

void Employee::print_data(){
	time_t now = time(0);
	tm *ltm = localtime(&now);

	write_to_console(ltm);
	write_to_file(ltm);
}


int main(){
	system("cls");
	Employee e[MAX_SIZE];
	int current_index = -1;
	int choice;
	char name[21], position[21];
	float grade_pay, basic_pay, ta_basic, ma;
	int emp_id;
	int flag = 0;
	while(1){
		system("cls");
		cout<<"\n\t\tMenu";
		cout<<"\n---------------------------------------------------\n";
		cout<<"\t1. Enter Employee Details\n\t2. Make Employee Pay Slip\n\t3. Exit";
		cout<<"\n---------------------------------------------------\n";
		cout<<"\n\n Enter Your Choice: ";
		cin>>choice;
		
		switch(choice){
		case 1:		cout<<"Name: ";
					cin.ignore();
					cin.getline(name, sizeof(name));
					cout<<"Positon: ";
					cin.getline(position, sizeof(position));
					cout<<"Basic pay: ";
					cin>>basic_pay;
					cout<<"Grade pay: ";
					cin>>grade_pay;
					cout<<"TABASIC : ";
					cin>>ta_basic;
					cout<<"MA: ";
					cin>>ma;
					e[++current_index].get_data(
							current_index, name, position, grade_pay,
							basic_pay, ta_basic, ma);
					break;
		case 2:		cout<<"Enter Employee Id: ";
					cin>>emp_id;
					if(emp_id > current_index){
						cout<<"No Such Employee";
					}else{
						e[emp_id].print_data();
					}
					break;
		case 3:		flag = 1;
					break;
		default:	cout<<"Enter right choice!!";
		}
		if(flag){
			cout<<"\nProgram Terminating";
			return 0;
		}
		getch();
	}
	
	return 0;
}


