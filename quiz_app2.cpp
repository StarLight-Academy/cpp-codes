#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>

using namespace std;

class Question {
	private:
			char question[151];
			char choices[4][101];
			int answer;
	
	public:
		
		Question(){}
		
		Question(char *question, char choices[][101], int index){
			setQuestion(question);
			setChoices(choices);
			setAnswer(index);
		}
		
		Question(Question &q){
			setQuestion(q.getQuestion());
			for(int i = 0; i < 4; i++)
				strcpy(choices[i], q.getChoice(i));
			setAnswer(q.getAnswer());
		}
		
		void copy_question(Question q){
			setQuestion(q.getQuestion());
			for(int i = 0; i < 4; i++)
				strcpy(choices[i], q.getChoice(i));
			setAnswer(q.getAnswer());
		}
		
		void setQuestion(char *question){
			strcpy(this->question, question);
		}
		
		char* getQuestion(){
			return question;
		}
		
		void setChoices(char choices[][101]){
			for(int i = 0 ; i < 4; i++){
				strcpy(this->choices[i], choices[i]);
			}
		}
		
		char* getChoice(int choice_no){
			return choices[choice_no];
		}
		
		void setAnswer(int index){
			if(index >= 0 && index <= 3){
				answer = index;
			}else{
				answer = -1;
			}
		}
		
		int getAnswer(){
			if(answer == -1){
				cout<<"\n return code = -1; First Enter a valid Choice as answer";
			}
			
			return answer;
		}
		
		void display_question(){
			cout<<"\n"<<question<<endl;
			cout<<"\n\t1. "<<choices[0]<<"\n\t2. "<<choices[1]<<endl;
			cout<<"\t3. "<<choices[2]<<"\n\t4. "<<choices[3]<<endl;
		}
};


void get_sub_str(char* str, int pos_start, int pos_end, char* res){
	for(int i = pos_start; i < pos_end; i++){
		res[i - pos_start] = str[i];
	}
	res[pos_end - pos_start] = '\0';
}


Question split_str(char* str){
	char question[151];
	char choices[4][101];
	char ans[2];
	int answer;

	int pos_delim[5];
	int k = 0;
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == ',')
			pos_delim[k++] = i;
	}

	get_sub_str(str, 0, pos_delim[0], question);
	get_sub_str(str, pos_delim[0] + 1, pos_delim[1], choices[0]);
	get_sub_str(str, pos_delim[1] + 1, pos_delim[2], choices[1]);
	get_sub_str(str, pos_delim[2] + 1, pos_delim[3], choices[2]);
	get_sub_str(str, pos_delim[3] + 1, pos_delim[4], choices[3]);
	get_sub_str(str, pos_delim[4] + 1, strlen(str), ans);
	answer = ((int)ans[0]) - 49;
	Question q(question, choices, answer);
	return q;
}


void read_questions(char* file_name, Question qs[]){
	ifstream file;
	file.open(file_name);

	
	char question_ans[400];
	int i = 0;
	while(file.getline(question_ans, sizeof(question_ans))){
		qs[i++] = split_str(question_ans);
	}
	file.close();
}


void display_instructions(int n_ques){
	cout<<"\n\n--------------------Instructions--------------------\n";
	cout<<"1. The quiz contains "<<n_ques<<" MCQs. In which only one answer is correct"<<endl;
	cout<<"2. Answer Choices \"1\", \"2\", \"3\" or \"4\". Anyother choice will be considered incorrect."<<endl;
	cout<<"3. Every Correct Answer Results in 4 points and every wrong answer Results in -1"<<endl;
	cout<<"\n Press Enter to continue";
	getch();
}


void play(Question questions[], int size){
	int choice, index;
	int correct = 0;
	char user_name[31];
	int used_indices[size];
	for(int i = 0; i < size; i++) used_indices[i] = 0;
	cin.ignore();
	cout<<"Enter Your Name: ";
	cin.getline(user_name, sizeof(user_name));
	system("cls");

	cout<<"Hello! "<<user_name;
	display_instructions(size+1);
	system("cls");
	for(int i = 0; i < size; i++){
		index = rand() % size;
		while(used_indices[index]){
			index = rand() % size;
		}
		used_indices[index] += 1;
		system("cls");
		questions[index].display_question();
		cout<<"\n\nEnter Your Choice: ";
		cin>>choice;
		if(choice-1 == questions[i].getAnswer()){
			cout<<"\n\n Write Choice";
			correct+=4;
		}else{
			cout<<"\n\n Wrong Choice";
			correct -= 1;
		}
		cout<<"\n Press Enter to continue";
		getch();
	}
	system("cls");
	cout<<"\n End of Quiz.. Thanks for Playing!";
	cout<<"\n Total Score: "<<correct;
}


int main(){

	int choice;
	int num_ques = 11;
	Question questions[num_ques];
	read_questions("files/questions.csv", questions);
	while(1){
		system("cls");
		cout<<"\n\n\t\tMenu\n";
		cout<<"-------------------------------------------------------------";
		cout<<"\n\t1. Start Quiz\n\t2. Exit\n";
		cout<<"-------------------------------------------------------------";
		cout<<"\n\nEnter your Choice: ";
		cin>>choice;

		if(choice == 1){
			play(questions, num_ques);
		}else if(choice == 2){
			break;
		}else{
			cout<<"Enter the right Choice";
		}
		cout<<"\nPress Enter to continue";
		getch();
	}
}

