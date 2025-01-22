#include <iostream>
#include <cmath>
using namespace std;

long long karatsuba(long long x, long long y, int depth = 0) {
    string indent(depth * 2, ' ');
    cout << indent << "Multiplying " << x << " and " << y << endl;

    if (x < 10 || y < 10) {
        cout << indent << "Base case result: " << x * y << endl;
        return x * y;
    }

    int n = max((int)log10(x) + 1, (int)log10(y) + 1);
    int m = n / 2;

    long long a = x / pow(10, m);
    long long b = x % (long long)pow(10, m);
    long long c = y / pow(10, m);
    long long d = y % (long long)pow(10, m);

    cout << indent << "Split " << x << " into " << a << " and " << b << endl;
    cout << indent << "Split " << y << " into " << c << " and " << d << endl;

    long long ac = karatsuba(a, c, depth + 1);
    long long bd = karatsuba(b, d, depth + 1);
    long long ad_plus_bc = karatsuba(a + b, c + d, depth + 1) - ac - bd;

    long long result = ac * pow(10, 2 * m) + ad_plus_bc * pow(10, m) + bd;

    cout << indent << "Result of " << x << " * " << y << ": " << result << endl;
    return result;
}

int main() {
    long long a = 4568;
    long long b = 3275;

    cout << "Karatsuba Multiplication of " << a << " and " << b << endl;
    long long result = karatsuba(a, b);
    cout << "Final Result: " << result << endl;

    return 0;
}

