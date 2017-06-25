#include<iostream>
#include<cmath>
#include<string.h>

using namespace std;


/*
 * reverse_str: Takes a string as input and finds
 * the reverse of the string.
 *
 * returns: Pointer to the reversed string.
 */
char* reverse_str(char str[]){
	static char reverse[1000];
	int size = strlen(str);
	for(int i = size-1; i >= 0; i--){
		reverse[i] = str[size - i -1];
	}
	reverse[size] = '\0';
	return reverse;
}


/*
 * get_words_of_str: Takes a string and an array 
 * of strings and saves all the words in string 
 * to the array of strings.
 */
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


/*
 * strcat_ext: Takes destination string, source
 * string and the starting point in the destination 
 * string to append source string from that point.
 */
void strcat_ext(char dest[], char src[], int start){
	int size = strlen(src);
	for(int i = 0; i < size; i++){
		dest[start + i] = src[i];
	}
}


/*
 * reverse_words_of_str: Takes 2 string as input
 * and saves the string with words reversed from
 * string src to string reverse.
 */
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
	
	//Take string as input
	cin.getline(str, sizeof(str));
	
	// Find string with words reversed
	reverse_words_of_str(str, reverse);
	
	// Print the result
	cout<<"\nResult: "<<reverse;
	
	return 0;
}