#include <iostream>
#include <cmath>
using namespace std;

class my_class{
    public:
        int n;
        my_class(int n){
            this->n = n;
        }

    int sqrt_n(){
        return abs(sqrt(n));
    }
};

int main(){
    int n;

    while(true){
        cin>>n;
        if(n >= 1 && n <= 100000){
            break;
        }
    }my_class mc(n);

    return 0;
}