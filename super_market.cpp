#include<iostream>
#include<fstream>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class Product {
private:
	int p_no;
	char name[31];
	float amount, tax, discount;
public:
	Product(){
		p_no = 0;
		amount = 0;
		tax = 0;
		discount = 0;
		strcpy(name, "NULL");
	}

	Product(int p_no, char name[], float amount, float tax, float discount){
		this->p_no = p_no;
		this->amount = amount;
		this->tax = tax;
		this->discount = discount;
		strcpy(this->name, name);
	}

	void display(){
		cout<<"\n Product No.: "<<p_no;
		cout<<"\n Name: "<<name;
		cout<<"\n Price: "<<amount;
		cout<<"\n Tax: "<<tax;
		cout<<"\n Discount: "<<discount;
	}

	int return_p_no(){
		return p_no;
	}

	float return_amount(){
		return amount;
	}

	float return_discount(){
		return discount;
	}

	char* return_name(){
		return name;
	}

	float return_price(){
		return amount + amount * (tax / 100) - amount * (discount / 100);
	}

	void write_to_file(char* file_name){
		fstream fp;
		fp.open(file_name, ios::out|ios::app|ios::binary);
		fp.write((char*)this, sizeof(Product));
		fp.close();
	}

	void read_from_file(char* file_name){
		fstream fp;
		fp.open(file_name, ios::in|ios::binary);
		fp.read((char*)this, sizeof(Product));
		fp.close();
	}
};

Product find_product(int p_no, char* file_name){
	fstream fp;
	fp.open(file_name, ios::in|ios::binary);
	Product pr;
	while(fp.read((char*)&pr, sizeof(Product))){
		if(pr.return_p_no() == p_no){
			fp.close();
			return pr;
		}
	}
	fp.close();
	return Product();
}

int delete_product(int p_no, char* file_name){
	fstream fp, temp;
	fp.open(file_name, ios::in);
	temp.open("Temp.dat", ios::out);
	Product pr;
	int flag = 0;
	while(fp.read((char*)&pr, sizeof(Product))){
		if(pr.return_p_no() == p_no){
			flag = 1;
			continue;
		}
		temp.write((char*)&pr, sizeof(Product));
	}
	fp.close();
	temp.close();
	remove(file_name);
	rename("Temp.dat", file_name);
	return flag;
}

int update_product(int p_no, char* file_name){
	fstream fp;
	fp.open(file_name, ios::in|ios::out);
	Product pr;
	while(fp.read((char*)&pr, sizeof(Product))){
		if(pr.return_p_no() == p_no){
			int p_no;
			float amount, discount, tax;
			char name[31];
			cout<<"\n Name: ";
			gets(name);
			cout<<"\n Number: ";
			cin>>p_no;
			cout<<"\n Price: ";
			cin>>amount;
			cout<<"\n Tax: ";
			cin>>tax;
			cout<<"\n Discount: ";
			cin>>discount;
			Product p(p_no, name, amount, tax, discount);

			fp.seekg(-1 * sizeof(Product));
			fp.write((char*)&p, sizeof(Product));
			fp.close();

			return 1;
		}
	}
	fp.close();
	return 0;
}

void display_all_products(char* file_name){
	fstream fp;
	fp.open(file_name, ios::in|ios::out);
	Product pr;
	while(fp.read((char*)&pr, sizeof(Product))){
		pr.display();
		cout<<"\n\n==============================\n\n";
	}
}

void print_invoice(int prod_nos[], int qty[], int size, char* file_name){
	float total = 0;
	cout<<"\n\n-------------------------INVOICE-------------------------\n";
	cout<<"\tP. No.\t\tName\t\tQty.\t\tAmount"<<endl;
	for(int i = 0; i < size; i++){
		Product p = find_product(prod_nos[i], file_name);
		if(strcmp(p.return_name(), "NULL") == 0){
			cout<<"\t"<<prod_nos[i]<<" NOT FOUND------------------"<<endl;
		}else{
			float amt = p.return_price() * qty[i];
			cout<<"\t"<<prod_nos[i]<<"\t"<<p.return_name()<<"\t\t"<<qty[i]<<"\t\t"<<amt<<endl;
			total += amt;
		}
	}
	cout<<"\t\t\t\t\t\tTotal Amount: "<<total;
}

void menu(char* file_name){
	fstream fp;
	fp.open(file_name, ios::in|ios::out);
	Product pr;
	cout<<"\n\n-------------------------INVOICE-------------------------\n";
	cout<<"\tP. No.\t\tName\t\tAmount"<<endl;
	while(fp.read((char*)&pr, sizeof(Product))){
		cout<<"\t"<<pr.return_p_no()<<"\t"<<pr.return_name()<<"\t\t"<<pr.return_amount()<<endl;
	}
}

void place_order(char* file_name){
	menu(file_name);
	int prod_nos[10], qty[10];
	int order_index = 0;
	char ch = 'y';
	while(ch == 'Y' || ch == 'y'){
		cout<<"\n Enter the Product number: ";
		cin>>prod_nos[order_index];
		cout<<"\n Enter Quantity: ";
		cin>>qty[order_index++];
		cout<<"\n\n Want to enter more products?(y/n): ";
		cin>>ch;
	}
	print_invoice(prod_nos, qty, order_index, file_name);
}

void admin_menu(char* file_name){
	int choice, p_no, deleted, updated;
	float amount, tax, discount;
	char name[31];
	Product p;
	while(1){
		system("cls");
		cout<<"\n\n\t -------------Admin Menu----------------";
		cout<<"\n\t\t1. Create Product";
		cout<<"\n\t\t2. Delete Product";
		cout<<"\n\t\t3. Display All Products";
		cout<<"\n\t\t4. Update Product";
		cout<<"\n\t\t5. Display Product Menu";
		cout<<"\n\t\t6. Search Product";
		cout<<"\n\t\t7. Back to Main Menu";
		cout<<"\n\t-----------------------------------------";
		cout<<"\n\nEnter your choice: ";
		cin>>choice;

		switch(choice){
			case 1: cout<<"\nEnter Product Details";
					cout<<"\nNumber: ";
					cin>>p_no;
					cout<<"\nName: ";
					gets(name);
					cout<<"\nAmount: ";
					cin>>amount;
					cout<<"\nTax: ";
					cin>>tax;
					cout<<"\nDiscount: ";
					cin>>discount;
					p = Product(p_no, name, amount, tax, discount);
					p.write_to_file(file_name);
					cout<<"\nProduct Saved";
					break;
			case 2: cout<<"\nEnter the product Number to delete: ";
					cin>>p_no;
					deleted = delete_product(p_no, file_name);
					if(!deleted){
						cout<<"\nProduct Not found!!";
					}else{
						cout<<"\nProduct Deleted!!";
					}
					break;
			case 3: display_all_products(file_name);
					break;
			case 4: cout<<"\nEnter the product Number to Update: ";
					cin>>p_no;
					updated = update_product(p_no, file_name);
					if(!updated){
						cout<<"\nProduct Not found!!";
					}else{
						cout<<"\nProduct Updated!!";
					}
					break;
			case 5: menu(file_name);
					break;
			case 6: cout<<"\nEnter the product Number to Search: ";
					cin>>p_no;
					p = find_product(p_no, file_name);
					if(strcmp(p.return_name(), "NULL") == 0){
						cout<<"\nProduct Not found!!";
					}else{
						cout<<endl;
						p.display();
					}
			case 7: return;
			default: cout<<"\nEnter right choice!!";
		}
		cout<<"\nPress enter to continue!!";
		cin.ignore();
		cin.get();
	}
}

void intro(){
	system("cls");
	cout<<"\n\n\t====================SUPERMARKET====================";
	cout<<"\n\t\t\tBilling Project";
	cout<<"\n\t\t\t\t\t\tMade By";
	cout<<"\n\t\t\t\t\t\tAdd your Name Here";
	cout<<"\n\t===================================================";
	cout<<"\n\nPress enter to continue";
	cin.get();
}

int main(){
	intro();
	/*int p_no;
	float amount, discount, tax;
	char name[31];
	gets(name);
	cin>>p_no;
	cin>>amount;
	cin>>tax;
	cin>>discount;
	Product p(p_no, name, amount, tax, discount);
	p.display();
	p.write_to_file("Shop.dat");
	Product p2 = find_product(12, "Shop.dat");
	p2.display();
	delete_product(12, "Shop.dat");
	p2 = find_product(12, "Shop.dat");
	p2.display();
	display_all_products("Shop.dat");
	return 0;*/
	char* file_name = "Shop.dat";
	int choice;
	while(1){
		system("cls");
		cout<<"\n\n\t-----------------MAIN MENU-----------------";
		cout<<"\n\t\t1. Customer";
		cout<<"\n\t\t2. Administrator";
		cout<<"\n\t\t3. Exit";
		cout<<"\n\t-------------------------------------------";
		cout<<"\n\nEnter your Choice: ";
		cin>>choice;

		switch(choice){
			case 1: place_order(file_name);
					break;
			case 2: admin_menu(file_name);
					break;
			case 3: return 0;
			default: cout<<"\nEnter your choice!!";
		}
		cout<<"\nPress Enter to continue!!";
		cin.ignore();
		cin.get();
	}
	return 0;
}



