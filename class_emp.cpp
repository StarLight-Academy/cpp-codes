#include<iostream>
#include<string.h>

using namespace std;

class Item{
	private:
		char item_name[30];
		int no_of_items;
		float amount_per_item;
	
	public:
		Item(){
			strcpy(item_name, "");
			no_of_items = 0;
			amount_per_item = 0.0;
		}
		
		Item(char item_name[], float amount_per_item){
			strcpy(this->item_name, item_name);
			this->amount_per_item = amount_per_item;
			no_of_items = 0;
		}
		
		char* get_item_name(){
			return item_name;
		}
		
		void set_no_of_items(int no_of_items){
			this->no_of_items = no_of_items;
		}
		
		int get_no_of_items(){
			return no_of_items;
		}
		
		float get_amount_per_item(){
			return amount_per_item;
		}
		
		~Item(){
			if(strcmp(item_name, "")){
				cout<<"Item "<<item_name<<" destroyed"<<endl;
			}
		}
};

class OrderList{
	private:
		Item item_list[10];
		int current_index;
		float total_amount;
	
	
		void update_amount(float amount_of_item){
			total_amount += amount_of_item;
		}
	
	public:
		OrderList(){
			for(Item item : item_list){
				item = Item();
			}
			total_amount = 0;
			current_index = -1;
		}
		
		void add_item(Item item){
			if(current_index + 1 == 10){
				return;
			}
			item_list[++current_index] = item;
			update_amount(item.get_amount_per_item());
		}
		
		Item get_item(int index){
			if(index > current_index)
				return Item();
			return item_list[index];
		}
		
		~OrderList(){
			cout<<"OrderList Destroyed"<<endl;
		}
};

int main(){
	Item i1("Soap", 20.5);
	Item i2("Mobile", 30000);
	Item i3("Case", 300);
	
	OrderList o;
	o.add_item(i1);
	o.add_item(i2);
	o.add_item(i3);
	
	Item i = o.get_item(2);
	cout<<i.get_item_name()<<endl;
}