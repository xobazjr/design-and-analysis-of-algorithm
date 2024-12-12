#include <iostream>
using namespace std;

void sum(int *A,int n,int x){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(A[i] + A[j] == x){
				cout<<A[i]<<", "<<A[j]<<endl;
			}	
		}
	}
}

int main(){
	int n=7,x=20;
	int A[n] = {5,15,-30,10,-5,40,10};
	sum(A,n,x);
	return 0;
}
