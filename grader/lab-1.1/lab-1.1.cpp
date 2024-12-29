#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class con_count{
	public:
		vector <int> my_vector;
		
	void add(int value){
		my_vector.push_back(value);
	}
	
	int count(){
    	sort(my_vector.begin(),my_vector.end());
    	int count = 1;
    
    	for (int i=1;i<my_vector.size();i++) {
        	if (my_vector[i] != my_vector[i-1] + 1) {
            	++count;
        	}
    	}
    	return count;
	}
	
	void print(){
		if(!my_vector.empty()){
			for(int i=0;i<my_vector.size();i++){
				cout<<my_vector[i]<<" ";
			}cout<<endl;
		}
	}	
};

int main(){
	con_count cc;
	int n,value;
	
	while(true){
		cin>>n;
		if(n > 1 && n < 1000000){
			for(int i=0;i<n;i++){
				cin>>value;
				cc.add(value);
			}
			cout<<cc.count()<<endl;
			break;
		}
	}
	
	return 0;
}
