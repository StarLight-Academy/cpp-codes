#include<iostream>

using namespace std;

class Trial{
	private:
		char obj_char;
	public:
		Trial(char obj_char){
			this->obj_char = obj_char;
			cout<<"Object "<<obj_char<<" created"<<endl;
		}
		
		
		~Trial(){
			cout<<"Object "<<obj_char<<" destroyed"<<endl;
		}
};

int main(){
	Trial t1('1');
	Trial t2('2');
	{
		Trial t3('3');
	}
	
	Trial t4('4');
	
	return 0;
}