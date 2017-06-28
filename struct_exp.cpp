#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

using namespace std;

struct Book{
	int bNo;
	char bName[21];
	char author[21];
	float price;
};

void input_book(Book &book){
	cout<<"\nBook No.: ";
	cin>>book.bNo;
	cout<<"\nBook Name: ";
	cin.ignore();
	cin.getline(book.bName, sizeof(book.bName));
	cout<<"\nAuthor: ";
	cin.getline(book.author, sizeof(book.author));
	cout<<"\nPrice: ";
	cin>>book.price;
}

void input_books(Book books[], int size){
	cout<<"\t\nEnter Details of Books"
		<<"\n===================================================================\n";
	for(int i = 0; i < size; i++){
		cout<<"\nEnter Book "<<i+1<<endl;
		input_book(books[i]);
		cout<<"\n-------------------------------------------------------------------\n";
	}
}

void display_book(Book book){
	cout<<"\nBook No: "<<book.bNo;
	cout<<"\nBook Name: "<<book.bName;
	cout<<"\nAuthor: "<<book.author;
	cout<<"\nPrice: "<<book.price;
}

void display_books(Book books[], int size){
	cout<<"\t\nDetails of Books"
		<<"\n===================================================================\n";
	for(int i = 0; i < size; i++){
		cout<<"\nBook "<<i+1<<endl;
		display_book(books[i]);
		cout<<"\n-------------------------------------------------------------------\n";
	}
}

void search_book_using_bno(Book books[], int size, int bNo){
	bool isFound = false;
	for(int i = 0; i < size; i++){
		if(books[i].bNo == bNo){
			cout<<"\t\nDetails of the Book:"
				<<"\n===================================================================\n";
			display_book(books[i]);
			isFound = true;
			break;
		}
	}
	if(!isFound)
		cout<<"\n\tBook Not Found!!\n\t";
}

int search_book_using_bname(Book books[], int size, char bName[]){
	bool isFound = false;
	for(int i = 0; i < size; i++){
		if(strcmp(books[i].bName, bName) == 0){
			cout<<"\t\nDetails of the Book:"
				<<"\n===================================================================\n";
			display_book(books[i]);
			isFound = true;
		}
	}
	if(!isFound)
		cout<<"\n\tBook Not Found!!\n\t";
}

int main(){
	
	Book books[MAX_SIZE];
	int size=0, choice, bNo;
	char bName[21];
	
	while(1){
		system("cls");
		
		cout<<"\n\t\t\tHow can I help you?";
		cout<<"\n---------------------------------------------------------------------------";
		cout<<"\n\t\t1. Enter Books Array\n\t\t2. Display Books\n\t\t3. Display Book of given Book No."
			<<"\n\t\t4. Display all Books of given Name\n\t\t5. Exit";
		cout<<"\n---------------------------------------------------------------------------";
		cout<<"\n\n\tEnter Your Choice: ";
		
		cin>>choice;
		
		system("cls");
		switch(choice){
			case 1:
					cout<<"\n\tEnter Size of the Array: ";
					cin>>size;
					while(size<=0){
						system("cls");
						cout<<"\n\tEnter valid size: ";
						cin>>size;
					}
					input_books(books, size);
					cout<<"\n\n---------------------------Books Entered---------------------------\n";
					break;
			case 2:
					if(size==0){
						cout<<"\nMake sure you entered the array first.";
					}else{
						display_books(books, size);
					}
					break;
			case 3:
					if(size==0){
						cout<<"\nMake sure you entered the array first.";
					}else{
						cout<<"\n Book no: ";
						cin>>bNo;
						search_book_using_bno(books, size, bNo);
					}
					break;
			case 4:
					if(size==0){
						cout<<"\nMake sure you entered the array first.";
					}else{
						cout<<"\n Book name: ";
						cin.ignore();
						cin.getline(bName, sizeof(bName));
						search_book_using_bname(books, size, bName);
					}
					break;
			case 5:
					cout<<"\n Program terminated!!";
					return 0;
		}
		
		cout<<"\nPress Enter to continue";
		cin.ignore();
		cin.get();
	}
}