#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class my_class{
	public:
		vector <int> my_vector;
		
	void add(int value){
		my_vector.push_back(value);
	}
	
	int count(){
		if(!my_vector.empty()){
			sort(my_vector.begin(),my_vector.end());
			int count = 1;
			for(int i=1;i<my_vector.size();i++){
				if(my_vector[i-1] != my_vector[i]){
					++count;
				}
			}
			return count;
		}
		return -1;
	}
};

int main(){
	my_class mc;
	int n,value,i=0;
	
	while(true){
		cin>>n;
		if(n >= 1 && n <= 10000){
			break;
		}
	}
	
	while(i < n){
		cin>>value;
		if(value >= 1 && value <= 10000){
			mc.add(value);
			++i;
		}
	}cout<<mc.count()<<endl;
	
	return 0;
}
