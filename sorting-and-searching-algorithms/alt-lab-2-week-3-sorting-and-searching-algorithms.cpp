#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class node{
    public:
        vector <int> my_vector;
        int size;
        node(int n){
            size = n;
        }

        void add(int value){
            my_vector.push_back(value);
        }

        void sort(){
            if(!my_vector.empty()){
                for(int i=0;i<size;i++){
                    for(int j=i+1;j<my_vector.size();j++){
                        if(my_vector[j] < my_vector[i]){
                            int temp = my_vector[i];
                            my_vector[i] = my_vector[j];
                            my_vector[j] = temp; 
                        }
                    }
                }
            }
        }

        void find_target(int k){
            if(!my_vector.empty()){
                int min=0;
                for(int i=0;i<size;i++){
                    if((my_vector[i] + my_vector[i+1]) == k){
                        int temp = my_vector[i] - my_vector[i+1];
                        if(temp < min){
                            min = temp;
                        }
                    }
                }cout<<abs(min)<<endl;
            }
        }

        void print(){
            if(!my_vector.empty()){
                for(int i=0;i<size;i++){
                    cout<<my_vector[i]<<" ";
                }cout<<endl;
            }
        }
};

int main(){
    int n;
    int k;
    int value;

    while(true){
        cin>>n>>k;
        if(n >= 2 && n <= 10000){
            node node(n);
            int loop = n - 1;
            int i=0;

            do{
                cin>>value;
                if(value <= 10000){
                    node.add(value);
                    ++i;
                    --loop;
                }
            }while(loop >= 0);

            node.sort();
            node.find_target(k);

            return 0;
        }
    }

    return 0;
}
