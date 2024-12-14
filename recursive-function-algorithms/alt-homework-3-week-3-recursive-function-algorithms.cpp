#include <iostream>
#include <cmath>
using namespace std;

class my_recursive{
	public:
		int n;
		int i;
		int sum;
		my_recursive(int value){
			n = value;
			i = 1;
			sum = 0;
		}
		
	float recursive(){
		if(n >= 0){
			if(i > n){
				return sum;
			}else{
				sum += pow(i++,3);
				return recursive();
			}		
		}
		
	}
};

int main(){
	my_recursive m(2);
	cout<<m.recursive()<<endl;
	return 0;
}
