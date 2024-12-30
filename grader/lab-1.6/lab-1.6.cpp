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

	void check_members(int k){
		if(!my_vector.empty()){
			sort(my_vector.begin(),my_vector.end());
			int min=0,left=0,right=0;
			bool check = false;
			for(int i=0;i<my_vector.size();i++){
				for(int j=i+1;j<my_vector.size();j++){
					if((my_vector[j] + my_vector[i]) == k){
						//cout<<my_vector[i]<<" + "<<my_vector[j]<<" = "<<(my_vector[j] + my_vector[i])<<endl;
						if(!check){
							check = true;
							min = (my_vector[j] - my_vector[i]);
							left = my_vector[i];
							right = my_vector[j];
						}else if((my_vector[j] - my_vector[i]) < min){
							check = true;
							min = (my_vector[j] - my_vector[i]);
							left = my_vector[i];
							right = my_vector[j];
						}
					}
				}
			}

			if(check){
				cout<<left<<" "<<right<<endl;
			}
		}
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
	my_class mc;
	int n,k;

	while(true){
		cin>>n>>k;
		if(n >= 2 && n <= 10000 && k > 1 && k <= 100000){
			break;
		}
	}

	int value;
	int i=0;
	while(i < n){
		cin>>value;
		if(value >= 1 && value <= 10000){
			mc.add(value);
			++i;
		}
	}mc.check_members(k);

	return 0;
}