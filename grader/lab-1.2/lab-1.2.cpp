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
	
	int find_max(){
		sort(my_vector.begin(),my_vector.end());
		int max = 1;
		int count = 1;
			
		for(int i=0;i<my_vector.size();i++){
			if(my_vector[i] == my_vector[i+1]){
				++count;
			}else{
				if(count > max){
					max = count;
				}
				count = 1;
			}
		}
		
		return max;
	}
	
	int find_min(int max){
		int min = max;
		int count = 1;
		for(int i=0;i<my_vector.size();i++){
			if(my_vector[i] == my_vector[i+1]){
				++count;
			}else{
				if(count < min){
					min = count;
				}
				count = 1;
			}
		}
		
		return min;
	}
	
	int freq_diff(){
		if(!my_vector.empty()){
			int max = find_max();
			int min = find_min(max);

			return (min);
		}
		
		return -1;
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
	}cout<<mc.freq_diff()<<endl;
	
	return 0;
}
