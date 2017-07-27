#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Student{
	char first_name[21];
	char last_name[21];
	char enroll_no[16];
	float marks[5];
	char grade = 'E';
};



float average_marks(float marks[], int size=5){
	float total = 0.0;
	for(int i = 0; i < size; i++)
		total += marks[i];
	return total/size;
}


char calculate_grade(float marks[], int size=5){
	float avg = average_marks(marks);

	if(avg >= 85)
		return 'A';
	if(avg >= 65)
		return 'B';
	if(avg >= 50)
		return 'C';
	if(avg >= 33)
		return 'D';
	return 'E';
}


Student input_student(){
	Student s;
	cout<<"\n First Name: ";
	cin.ignore();
	cin.getline(s.first_name, sizeof(s.first_name));
	cout<<"\n Last Name: ";
	cin.getline(s.last_name, sizeof(s.last_name));
	cout<<"\n Enrollment No: ";
	cin.getline(s.enroll_no, sizeof(s.enroll_no));
	cout<<"\n Marks:";
	for(int i = 0; i < 5; i++){
		cout<<"\n\tMarks "<<i+1<<":";
		cin>>s.marks[i];
	}
	s.grade = calculate_grade(s.marks);
	return s;
}


void input_students(Student students[], int size){
	for(int i = 0; i < size; i++){
		students[i] = input_student();
	}
}


void display_student(Student s){
	cout<<"\n First Name: "<<s.first_name;
	cout<<"\n Last Name: "<<s.last_name;
	cout<<"\n Enrollment No: "<<s.enroll_no;
	cout<<"\n Marks:";
	for(int i = 0; i < 5; i++){
		cout<<"\n\tMarks "<<i+1<<" :"<<s.marks[i];
	}
	cout<<"\n Grade: "<<s.grade;
}


void display_student_using_enroll_no(Student students[], int size, char *enroll_no){
	for(int i = 0; i < size; i++){
		if(!strcmp(students[i].enroll_no, enroll_no))
			display_student(students[i]);
	}
}

float average_marks_using_enroll_no(Student students[], int size, char *enroll_no){
	for(int i = 0; i < size; i++){
		if(!strcmp(students[i].enroll_no, enroll_no))
			return average_marks(students[i].marks);
	}
}


int main(){
	int choice, num, size;
	Student students[100];
	char enroll_no[16];
	float avg;
	
	while(1){
		
		system("cls");
		
		cout<<"\n\t\t\tHow can I help you?";
		cout<<"\n---------------------------------------------------------------------------";
		cout<<"\n\t\t1. Input Students\n\t\t2. Display Student\n\t\t3. Find Average Marks\n\t\t4. Exit";
		cout<<"\n---------------------------------------------------------------------------";
		cout<<"\n\n\tEnter Your Choice: ";
		
		cin>>choice;
		
		system("cls");
		
		switch(choice){
			case 1:
					cout<<"Enter the number of students: ";
					cin>>size;
					cout<<"Enter Students Data: ";
					input_students(students, size);
					break;
			case 2:
					cout<<"Enter the Student Enrollment no: ";
					cin.ignore();
					cin.getline(enroll_no, sizeof(enroll_no));
					display_student_using_enroll_no(students, size, enroll_no);
					break;
			case 3:
					cout<<"Enter the Student Enrollment no: ";
					cin.ignore();
					cin.getline(enroll_no, sizeof(enroll_no));
					avg = average_marks_using_enroll_no(students, size, enroll_no);
					cout<<"\n Average Marks: "<<avg;
					break;
			case 4:
					cout<<"\n Program Terminated!!";
					return 0;
			default:
					cout<<"Enter Right Choice";
		}
		
		cout<<"\n\nPress enter to continue..";
		cin.ignore();
		cin.get();
	}
	return 0;
}