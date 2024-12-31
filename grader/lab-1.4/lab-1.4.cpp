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
			for(int i=1;i<my_vector.size();i++){
				if(my_vector[i-1] > my_vector[i]){
					//cout<<my_vector[i-1]<<" > "<<my_vector[i]<<endl;
					return 1;
				}else{
					//cout<<my_vector[i-1]<<" < "<<my_vector[i]<<endl;
				}
			}
		}

		return 0;
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
	
	if(!son.checksort(0)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	
	return 0;
}
