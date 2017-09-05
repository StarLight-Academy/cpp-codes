#include<iostream>

using namespace std;

class Polynomial {
	
	protected:
		int num_sides;
		float sum_of_interior_angles;
		void calc_sum_of_interior_angles();
		
	public:
		Polynomial(int);
		int get_num_sides();
		void set_num_sides(int n);
		float get_sum_of_interior_angles();
		virtual float get_area();
};

Polynomial::Polynomial(int num_sides){
	this->num_sides = num_sides;
	calc_sum_of_interior_angles();
}

int Polynomial::get_num_sides(){return num_sides;}

void Polynomial::set_num_sides(int n){
	num_sides = n;
	calc_sum_of_interior_angles();
}

void Polynomial::calc_sum_of_interior_angles(){
	sum_of_interior_angles = (num_sides - 2) * 180;
}

float Polynomial::get_sum_of_interior_angles(){return sum_of_interior_angles;}

float Polynomial::get_area(){
	return -1;
}

class Rectangle:public Polynomial{
	protected:
		float area;
		float l, b;
		void calc_area();
	public:
		Rectangle(float, float);
		void set_length(float);
		void set_breadth(float);
		float get_length();
		float get_breadth();
		float get_area();
};

Rectangle::Rectangle(float l, float b) : Polynomial(4){
	this->l = l;
	this->b = b;
	calc_area();
}

void Rectangle::calc_area(){
	area = l * b;
}

void Rectangle::set_length(float l){
	this->l = l;
	calc_area();
}

void Rectangle::set_breadth(float b){
	this->b = b;
	calc_area();
}

float Rectangle::get_length(){return l;}

float Rectangle::get_breadth(){return b;}

float Rectangle::get_area(){return area;}

class Triangle:public Polynomial{
	protected:
		float area;
		float base, height;
		void calc_area();
	public:
		Triangle(float, float);
		void set_base(float);
		void set_height(float);
		float get_base();
		float get_height();
		float get_area();
};

Triangle::Triangle(float base, float height) : Polynomial(3){
	this->base = base;
	this->height = height;
	calc_area();
}

void Triangle::calc_area(){
	area = 0.5 * base * height;
}

void Triangle::set_base(float base){
	this->base = base;
	calc_area();
}

void Triangle::set_height(float height){
	this->height = height;
	calc_area();
}

float Triangle::get_base(){return base;}

float Triangle::get_height(){return height;}

float Triangle::get_area(){return area;}

int main(){
	
	Polynomial *p;
	Rectangle r(3, 4);
	Triangle t(4, 4);
	
	p = & r;
	cout<< p -> get_area();
	return 0;
}