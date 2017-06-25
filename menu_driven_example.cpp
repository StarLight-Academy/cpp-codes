#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

/*
 * The following code is an example of a CLI based
 * menu-driven program to give choice between prime
 * number function or palindrome number function.
 */

 
/*
 * isPrime: Takes input an integer and returns
 * true if the number is prime, else false.
 */
bool isPrime(int n){
	if(n <= 1)
		return false;
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return false;
	return true;
}


/*
 * isPalindrome: Takes input an integer and 
 * returns true if the number is Palindrome, 
 * else false.
 */
bool isPalindrome(int n){
	int reverse = 0, digit, temp;
	temp = n;
	while(temp){
		digit = temp % 10;
		reverse = reverse * 10 + digit;
		temp /= 10;
	}
	
	if(n == reverse)
		return true;
	return false;
}

int main(){
	int choice, num;
	
	while(1){
		
		// Clear the command line.
		system("cls");
		
		// Display the menu
		// 1.Prime Number
		// 2. Palindrome
		// 3. Exit
		cout<<"\n\t\t\tHow can I help you?";
		cout<<"\n-------------------------------------------"
			<<"--------------------------------";
		cout<<"\n\t\t1. Prime Number\n\t\t2. Palindrome\n\t\t3. Exit";
		cout<<"\n-------------------------------------------"
			<<"--------------------------------";
		cout<<"\n\n\tEnter Your Choice: ";
		
		// Take choice of user as input.
		cin>>choice;
		
		// Clear the Screen for processing and output screen
		system("cls");
		
		// switch-case to find the choice and perform necessary 
		// processing
		switch(choice){
			case 1:
					cout<<"Enter the number to check: ";
					cin>>num;
					if(isPrime(num))
						cout<<"\n\nThe entered number is prime";
					else
						cout<<"\n\nThe entered number is not prime";
					break;
			case 2:
					cout<<"Enter the number to check: ";
					cin>>num;
					if(isPalindrome(num))
						cout<<"\n\nThe entered number is palindrome";
					else
						cout<<"\n\nThe entered number is not a palindrome";
					break;
			case 3:
					cout<<"Program terminated!!";
					return 0;
			default:
					cout<<"Enter Right Choice";
		}
		
		// Hold Screen to display result
		cout<<"\n\nPress enter to continue..";
		cin.ignore();
		cin.get();
	}
	return 0;
}