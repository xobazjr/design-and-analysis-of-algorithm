#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class my_class {
public:
    vector<int> my_array;

    void add(int value) {
        my_array.push_back(value);
    }

    int find_mode_dnc(vector<int>& arr, int left, int right, int target) {
        if (left > right) {
            return 0; 
        }
        if (left == right) {
            return arr[left] == target ? 1 : 0;
        }

        int mid = left + (right - left) / 2;
        int left_count = find_mode_dnc(arr, left, mid, target);
        int right_count = find_mode_dnc(arr, mid + 1, right, target);

        return left_count + right_count;
    }

    void divide_and_conquer(int target) {
        if (!my_array.empty()) {
            sort(my_array.begin(), my_array.end()); 
            int count = find_mode_dnc(my_array, 0, my_array.size() - 1, target);
            cout << "Answer: " << count << endl;
        } else {
            cout << "Array is empty." << endl;
        }
    }

    void print() {
        if (!my_array.empty()) {
            for (int val : my_array) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    my_class mc;
    int n, target, value;

    while (true) {
        cout << "Size: ";
        cin >> n;
        if (n > 0 && n < 100000) {
            break;
        }
    }

    cout << "Members: ";
    for (int i = 0; i < n; ++i) {
        while (true) {
            cin >> value;
            if (value > 0 && value <= 100000) {
                mc.add(value);
                break;
            }
        }
    }
    cout << "Target: ";
    while (true) {
        cin >> target;
        if (target > 0 && target < 100000) {
            break;
        }
    }

    mc.divide_and_conquer(target);

    return 0;
}