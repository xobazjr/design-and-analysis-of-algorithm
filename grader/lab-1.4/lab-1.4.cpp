#include <iostream>
#include <vector>
using namespace std;

class sortornot{
	public:
		vector <int> my_vector;
		
	void add(int value){
		my_vector.push_back(value);
	}
	
	bool checksort(int i){
		if(!my_vector.empty()){
			if(i < my_vector.size()){
				if(my_vector[i] > my_vector[i+1]){
					return 0;
				}else{
					return checksort(i+=1);
				}
			}
		}
		
		return 1;
	}	
		
};

int main(){
	sortornot son;
	int n,value;
	
	while(true){
		cin>>n;
		if(n > 1 && n < 1000000){
			break;
		}
	}
	
	for(int i=0;i<n;i++){
		cin>>value;
		son.add(value);
	}
	
	if(son.checksort(0)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	
	return 0;
}
