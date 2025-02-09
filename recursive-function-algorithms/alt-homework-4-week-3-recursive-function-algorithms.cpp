#include <iostream>
using namespace std;

class my_recurive{
	public:
		int n;
		int *A;
		int i;
		int sum;
		my_recurive(int value, int *arr){
			n = value;
			A = arr;
			i = 0;
			sum = 0;
		}
		
	void recursive(){
		if(i >= n){
			cout<<sum<<endl;
		}else{
			sum += A[i++];
			return recursive();
		}
	}
};

int main(){
	int n = 5;
	int A[] = {5,2,9,10,3};
	
	my_recurive m(n,A);
	m.recursive();
	
	return 0;
}
