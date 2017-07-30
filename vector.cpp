#include<iostream>
#include<cmath>
#define MAX_SIZE 10000


using namespace std;

class Vector{
	private:
		float coords[MAX_SIZE];
		int dimension;
	public:
		Vector(float coords[], int dimension){
			if(dimension <= 0 || dimension > MAX_SIZE){
				this->dimension = 3;
				this->coords[0] = this->coords[1] = this->coords[2] = 0;
				cout<<"Dimension invalid, Making a zero vector of 3 dimension.";
			}else{
				this->dimension = dimension;
				for(int i = 0; i < dimension; i++){
					this->coords[i] = coords[i];
				}
			}
		}
		
		Vector(){
			this->dimension = 3;
			this->coords[0] = this->coords[1] = this->coords[2] = 0;
		}
		
		Vector(const Vector &v){
			dimension = v.get_dimension();
			for(int i = 0; i < dimension; i++){
				coords[i] = v.get_ith_coord(i);
			}
		}
		
		int get_dimension() const{
			return dimension;
		}
		
		float get_ith_coord(int i) const{
			return coords[i];
		}
	
		int length(){
			return dimension;
		}
		
		Vector operator+(Vector other){
			if(dimension != other.dimension){
				return Vector();
			}
			
			float new_coords[MAX_SIZE];
			for(int i = 0; i < dimension; i++){
				new_coords[i] = coords[i] + other.coords[i];
			}
			
			return Vector(new_coords, dimension);
		}
		
		float operator*(Vector other){
			if(dimension != other.dimension){
				return -1.0;
			}
			
			float scalar_prod = 0.0;
			for(int i = 0; i < dimension; i++){
				scalar_prod += coords[i] * other.coords[i];
			}
			
			return scalar_prod;
		}
		
		float sum(){
			float tot = 0.0;
			for(int i = 0; i < dimension; i++){
				tot += coords[i];
			}
			
			return tot;
		}
		
		float magnitude(){
			float ss = 0.0; //Squared Sum
			for(int i = 0; i < dimension; i++){
				ss += coords[i] * coords[i];
			}
			
			return sqrt(ss);
		}
		
		Vector direction(){
			float mg = magnitude();
			float new_coords[MAX_SIZE];
			
			for(int i = 0; i < dimension; i++){
				new_coords[i] = coords[i] / mg;
			}
			
			return Vector(new_coords, dimension);
		}
		
		void print(){
			cout<<"<";
			for(int i = 0; i < dimension-1; i++){
				cout<<coords[i]<<",";
			}
			
			cout<<coords[dimension-1]<<">";
		}
};


int main(){
	
	float coords[] = {1, 2, 3};
	
	Vector v1(coords, 3);
	Vector v2(coords, 3);
	Vector v = v1 + v2;
	Vector v1_unit = v1.direction();
	
	v.print();
	Vector v3(v);
	cout<<endl;
	v1_unit.print();
	cout<<endl;
	v3.print();
	cout<<"\n"<<v1*v2;
	return 0;
}