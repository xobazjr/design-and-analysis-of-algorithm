#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class node{
	public:
		vector <int> my_vector;
		int n; //size
		int l; //first
		int r; //last
		int k; //target
		node(int size,int target){
			n = size;
			l = 0;
			r = n - 1;
			k = target;
		}
		
	void add(int value){
		my_vector.push_back(value);
	}
	
	void interpolation(){
		if(!my_vector.empty()){
			int loop = n-1;
			do{
        		int x = l + abs(((k - my_vector[l]) * (r - l)) / (my_vector[r] - my_vector[l]));
        		if(my_vector[x] == k){
            		cout<<x<<" ";
            		break;
        		}else{
            		cout<<x<<" ";
            		l = x + 1;
        		}
        		--loop;
    		}while(loop >= 0);
    		
			cout<<endl;	
		}
	}
};

int main(){
    int n; //members
    int k; //target
    int value;

    while(true){
        cin>>n>>k;
        if(n >= 1 && k <= 1000){
        	node node(n,k);
        	int i=0,loop=n-1;
        	
        	do{
        		cin>>value;
        		if(value >= 1 && value <= 100000){
        			if(!node.my_vector.empty()){
        				if(value > node.my_vector[i] && value >= 1 && value <= 100000){
        					node.add(value);
							--loop;
							++i;	
						}
					}else{
						node.add(value);
						--loop;
					}	
				}
			}while(loop >= 0);

			node.interpolation();
            return 0;
        }
    }
    return 0;
}
