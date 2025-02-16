#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> Node;

int main(){
    vector <Node> v1;

    v1.push_back(make_pair(0,10));

    cout<<v1[0].first<<" "<<v1[0].second<<endl;

    return 0;
}