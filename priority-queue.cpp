#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    priority_queue<int,vector<int> > pq;

    pq.push(9);
    pq.push(10);
    pq.push(5);
    pq.push(4);
    pq.push(8);

    while(!pq.empty()){
        int a = pq.top();
        cout<<a<<" ";
        pq.pop();
    }

    return 0;
}