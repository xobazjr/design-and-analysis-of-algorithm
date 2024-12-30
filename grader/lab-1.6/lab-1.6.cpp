#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class my_class{
	public:
		vector <int> my_vector;
	
	void add(int value){
		my_vector.push_back(value);
	}
	
	void find_duplicated(int k){
		if(!my_vector.empty()){
			int min=100001,left,right;
			for(int i=0;i<my_vector.size();i++){
				for(int j=i+1;j<my_vector.size();j++){
					int temp = my_vector[i] + my_vector[j];
					cout<<temp<<endl;
					if(temp == k){
						temp = abs(my_vector[i] - my_vector[j]);
						if(temp < min){
							min = temp;
							left = my_vector[i];
							right = my_vector[j];
						}
					}
				}
			}
			
			if(min !=- 100001){
				if(left < right){
					cout<<left<<" "<<right<<endl;
				}else{
					cout<<right<<" "<<left<<endl;
				}
			}
		}
	}
};

int main(){
	my_class mc;
	int n,k,value;
	
	while(true){
		cin>>n>>k;
		if(n >= 2 && n <= 10000){
			if(k > 1 && k <= 100000){
				break;
			}
		}
	}
	
	int i=0;
	while(i < n){
		cin>>value;
		if(value >= 1 && value <= 10000){
			++i;
			mc.add(value);
		}
	}mc.find_duplicated(k);
	
	return 0;
}
