#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class MyClass
{
public:
    vector<int> a;
    int k;
    int m;

    MyClass(int k, int m)
    {
        this->k = k;
        this->m = m;
    }

    void k_nearest()
    {
        vector<pair<int, int>> distances;
        for (int i = 0; i < a.size(); i++)
        {
            distances.push_back({abs(a[i] - m), a[i]});
        }

        sort(distances.begin(), distances.end());

        cout << "m = " << m << ": ";
        for (int i = 0; i < min(k, (int)distances.size()); i++)
        {
            cout << distances[i].second << " ";
        }
        cout << endl;
    }

    void add(int value)
    {
        a.push_back(value);
    }
};

int main()
{
    int n, value, k, m;
    cout << "n: ";
    cin >> n;

    cout << "k: ";
    cin >> k;

    cout << "m: ";
    cin >> m;

    MyClass mc(k, m);

    cout << "members " << n << ": ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        mc.add(value);
    }

    mc.k_nearest();

    return 0;
}