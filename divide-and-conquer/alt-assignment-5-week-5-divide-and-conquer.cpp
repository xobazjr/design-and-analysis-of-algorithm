#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

class MyClass {
public:
    vector<int> a;  
    int K;  

    MyClass(vector<int> a, int K) {
        this->a = a;
        this->K = K;
    }

    double find_top_K_average() {
        sort(a.rbegin(), a.rend());  

        int sum = 0;
        for (int i = 0; i < K; ++i) {
            sum += a[i];
        }

        return (double)sum / K;
    }
};

int main() {
    int n, K;

    cout << "Enter the number of scores: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter the scores: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> K;

    if (K > n) {
        return 1;
    }

    MyClass obj(a, K);
    double result = obj.find_top_K_average();
    cout << "The average of the top " << K << " scores: " << result << endl;

    return 0;
}
