#include<iostream>
#include<string.h>
#include<cmath>
#define SIZE 1000

using namespace std;

struct Point {
	float x;
	float y;
};


class SalesMan {
private:
	char name[31];
	Point pth_followed[SIZE];
	int total_points;

	int compare_points(Point p1, Point p2, int choice=0){
		if(choice == 0){
			return p1.x > p2.x;
		}
		
		return p1.y > p2.y;
	}
	
	double distance(Point p1, Point p2){
		double delta_x = p1.x - p2.x;
		double delta_y = p1.y - p2.y;
		return sqrt(delta_x * delta_x + delta_y * delta_y);
	}

public:
	SalesMan(char* n, Point point_arr[], int size){
		strcpy(name, n);
		total_points = size;
		for(int i = 0; i < total_points; i++){
			pth_followed[i] = point_arr[i];
		}
	}
	
	void sort_using_dimension(int choice=0){
		Point temp;
		for(int i = 1; i < total_points; i++){
			for(int j = 0; j < total_points - i -1; j++){
				if(compare_points(pth_followed[j], pth_followed[j+1], choice)){
					temp = pth_followed[j];
					pth_followed[j] = pth_followed[j+1];
					pth_followed[j+1] = temp;
				}
			}
		}
	}

	void sort_using_distance_from_point(Point p){
		Point temp;
		for(int i = 1; i < total_points; i++){
			for(int j = 0; j < total_points - i; j++){
				if(distance(pth_followed[j], p) > 
				   distance(pth_followed[j+1], p)){

					temp = pth_followed[j];
					pth_followed[j] = pth_followed[j+1];
					pth_followed[j+1] = temp;
				}
			}
		}
	}
	
	void display_path(){
		cout<<"Path Followed is: "<<endl;
		for(int i = 0; i < total_points; i++){
			cout<<"->";
			cout<<"("<<pth_followed[i].x<<", "<<pth_followed[i].y<<")";
		}
	}
};

int main(){
	char name[31];
	cout<<"Name: ";
	cin.getline(name, sizeof(name));
	
	Point p1[5];
	for(int i = 0; i < 5; i++){
		cout<<"Input Point "<<i+1<<endl;
		cout<<"x: ";
		cin>>p1[i].x;
		cout<<"y: ";
		cin>>p1[i].y;
		cout<<endl;
	}
	
	SalesMan s(name, p1, 5);
	s.display_path();
	s.sort_using_dimension();
	cout<<endl;
	s.display_path();
	s.sort_using_dimension(1);
	cout<<endl;
	s.display_path();
	
	Point p;
	p.x = 2;
	p.y = 5;
	s.sort_using_distance_from_point(p);
	cout<<endl;
	s.display_path();
}
