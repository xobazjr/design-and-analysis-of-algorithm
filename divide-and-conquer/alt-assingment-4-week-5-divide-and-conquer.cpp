#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class my_class{
    public:
        vector <int> my_array;
        vector <int> left;
        vector <int> right;

    void add(int value){
        my_array.push_back(value);
    }

    int median(){
        if(!my_array.empty()){
            return (0 + (my_array.size() - 1)) / 2;
        }
        return 0;
    }

    void divide_and_conquer(int target){
        if(!my_array.empty()){
            sort(my_array.begin(),my_array.end());
            import_to_array_left();
            import_to_array_right();

            cout<<"anw: "<<(find_mode(left,target) + find_mode(right,target))<<endl;
        }
    }

    int find_mode(vector <int> tpr,int target){
        if(!tpr.empty()){
            int mode = 0;
            for(int i=0;i<tpr.size();i++){
                if(tpr[i] == target){
                    ++mode;
                }
            }

            return mode;
        }

        return 0;
    }

    void import_to_array_left(){
        if(!my_array.empty()){
            for(int i=0;i<=median();i++){
                left.push_back(my_array[i]); 
            }
        }
    }

    void import_to_array_right(){
        if(!my_array.empty()){
            for(int i=(median()+1);i<my_array.size();i++){
                right.push_back(my_array[i]); 
            }
        }
    }

    void print(){
       if(!my_array.empty()){
            for(int i=0;i<my_array.size();i++){
                cout<<my_array[i]<<" ";
            }cout<<endl;
        } 
    }

    void print_left(){
        if(!left.empty()){
            for(int i=0;i<left.size();i++){
                cout<<left[i]<<" ";
            }cout<<endl;
        }
    }

    void print_right(){
        if(!right.empty()){
            for(int i=0;i<right.size();i++){
                cout<<right[i]<<" ";
            }cout<<endl;
        }
    }
};

int main(){
    my_class mc;
    int n,target;
    int value;

    while(true){
        cout<<"size: ";
        cin>>n;
        if(n > 0 && n < 100000){
            break;
        }
    }

    int i=0;

    cout<<"member: ";
    do{
        cin>>value;
        if(value > 0 && value <= 100000){
            mc.add(value);
            ++i;
        }
    }while(i < n);

    cout<<"target: ";
    while(true){
        cin>>target;
        if(target > 0 && target < 100000){
            break;
        }
    }

    mc.divide_and_conquer(target);

    return 0;
}