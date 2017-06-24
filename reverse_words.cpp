#include<iostream>
#include<cmath>
#include<string.h>

using namespace std;

char* reverse_str(char str[]){
	static char reverse[1000];
	int size = strlen(str);
	for(int i = size-1; i >= 0; i--){
		reverse[i] = str[size - i -1];
	}
	reverse[size] = '\0';
	return reverse;
}

int get_words_of_str(char str[], char words[][20]){
	int curr_word = 0, curr_index = 0;
	int size = strlen(str);
	for(int  i = 0; i < size+1; i++){
		if(str[i] == ' '){
			words[curr_word][curr_index] = '\0';
			curr_index = 0;
			curr_word += 1;
			continue;
		}
		words[curr_word][curr_index++] = str[i];
	}
	return curr_word+1;
}

void strcat_ext(char dest[], char src[], int start){
	int size = strlen(src);
	for(int i = 0; i < size; i++){
		dest[start + i] = src[i];
	}
}

void reverse_words_of_str(char str[], char reverse[]){
	char words[50][20];
	int num_of_words = get_words_of_str(str, words);
	int curr_index = 0;
	char space = ' '; 
	for(int  i = 0; i < num_of_words; i++){
		strcat_ext(reverse, reverse_str(words[i]), curr_index);
		curr_index += strlen(words[i]);
		strcat_ext(reverse, &space, curr_index);
		curr_index += 1;
	}
	reverse[strlen(str)] = '\0';
}

int main(){
	char str[1000], reverse[1000];
	
	cout<<"Enter the string to reverse: ";
	
	cin.ignore();
	cin.getline(str, sizeof(str));
	
	reverse_words_of_str(str, reverse);
	
	cout<<"\nResult: "<<reverse;
	
	return 0;
}