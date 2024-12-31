#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class my_class{
	public:
		vector <int> my_vector;
		
	void add(int value){
		my_vector.push_back(value);
	}
	
	void freq_diff(){
		if(!my_vector.empty()){
			int cal=1;
			vector <int> temp;
			sort(my_vector.begin(),my_vector.end());
			for(int i=0;i<my_vector.size();i++){
				if(my_vector[i] == my_vector[i+1]){				
					++cal;
					//cout<<cal<<endl;
				}else{
					//cout<<cal<<endl;
					temp.push_back(cal);
					cal = 1;
				}
			}

			if(!temp.empty()){
				sort(temp.begin(),temp.end());
				if((temp[temp.size()-1] - temp[0]) > 0){
					cout<<(temp[temp.size()-1] - temp[0])<<endl;
				}
			}
		}
	}
};

int main(){
	my_class mc;
	int n,value;
	
	while(true){
		cin>>n;
		if(n > 1 && n < 1000000){
			break;
		}
	}
	
	for(int i=0;i<n;i++){
		cin>>value;
		mc.add(value);
	}mc.freq_diff();
	
	return 0;
}
