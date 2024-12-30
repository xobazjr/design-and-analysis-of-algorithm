#include <iostream>
#include <vector>
using namespace std;

class my_class{
    public:
        vector <int> a; //in
        vector <int> b; //out

    void add_a(int value){
        a.push_back(value);
    }

    void add_b(int value){
        b.push_back(value);
    }

    void print_a(){
        if(!a.empty()){
            for(int i=0;i<a.size();i++){
                cout<<a[i]<<" ";
            }cout<<endl;
        }
    }

    void print_b(){
        if(!b.empty()){
            for(int i=0;i<b.size();i++){
                cout<<b[i]<<" ";
            }cout<<endl;
        }
    }
};

int main(){
    my_class mc;
    int n;

    while(true){
        cin>>n;
        if(n > 1 && n < 100000){
            break;
        }
    }

    int i=0,value;
    while(i < n){
        cin>>value;
        if(value > 0 && value < 1000){
            mc.add_a(value);
            ++i;
        }
    }

    i=0;
    while(i < n){
        cin>>value;
        if(value > 0 && value < 1000 && value >= mc.a[i]){
            mc.add_b(value);
            ++i;
        }
    }

    //mc.print_a();
    //mc.print_b();

    return 0;
}