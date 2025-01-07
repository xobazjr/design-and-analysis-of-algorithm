#include <iostream>
using namespace std;

class my_class{
	public:
		int *a;
		int *b;
		int n;
		int max;
		my_class(int *a,int n,int max){
			this->a = a;
			this->max = max + 1;
			this->b = new int[max];
			this->n = n;
		}

	void import_zero_to_b(){ //import 0 to array b
		for(int i=0;i<max;i++){
			b[i] = 0;
		}
	}

	void check_array_a(){ //import check members a to b
		for(int i=0;i<n;i++){
			b[a[i]] += 1;
		}
	}

	void print(){ //print array b
		import_zero_to_b();
		check_array_a();

		for(int i=0;i<max;i++){
			if(b[i] > 0){
				while(b[i] != 0){
					cout<<i<<" ";
					--b[i];
				}
			}
		}cout<<endl;
	}
};

int main(){
	int n = 9;
	int a[n] = {551,220,551,912,81,32,745,613,109};
	int max = 912;

	my_class mc(a,n,max);
	mc.print();

	return 0;
}