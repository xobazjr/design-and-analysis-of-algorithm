#include <iostream>
#include <algorithm>
using namespace std;

class my_class{
    public:
        int* D;
        int n;
        int w;
    my_class(int D[],int n,int w){
        this->n = n;
        this->D = new int[n];
        this->D = D;
        this->w = w;
    }

    void sort(){
        for(int i=0;i<n;i++){
            for(int j=i;j<n-1;j++){
                if(D[j] > D[j+1]){
                    int temp = D[j];
                    D[j] = D[j+1];
                    D[j+1] = temp;
                }
            }
        }
    }

    int result() {
        sort();  // เรียงลำดับเหรียญก่อนใช้
        int i = n - 1, cnts = 0;
    
        while (w > 0) {  // ตรวจสอบให้แน่ใจว่าไม่ออกนอกขอบเขตอาร์เรย์
            int coin = w / D[i];  // คำนวณจำนวนเหรียญที่ใช้
            cnts += coin;         // เพิ่มจำนวนเหรียญที่ใช้
            w -= coin * D[i];     // อัปเดตจำนวนเงินที่เหลือ
            i--;
        }
    
        return cnts;  // ถ้าใช้เหรียญลงตัวให้คืนค่าจำนวนเหรียญ, ถ้าใช้ไม่ได้คืน -1
    }

    void print(){
        sort();
        for(int i=0;i<n;i++){
            cout<<D[i]<<" ";
        }cout<<endl;
    }
};

int main(){
    int n = 4;
    int w = 13;
    int D[] = {1,5,2,10};

    my_class mc(D,n,w);
    cout<<mc.result()<<endl;

    return 0;
}