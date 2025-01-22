#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int> > data;
    int size;

public:
    Matrix(int n) : size(n) {
        data.resize(n, vector<int>(n, 0));
    }

    int getSize() const {
        return size;
    }

    vector<int>& operator[](int index) {
        return data[index];
    }

    const vector<int>& operator[](int index) const {
        return data[index];
    }

    Matrix operator+(const Matrix &other) const {
        Matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = data[i][j] + other[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix &other) const {
        Matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = data[i][j] - other[i][j];
            }
        }
        return result;
    }

    void split(Matrix &A11, Matrix &A12, Matrix &A21, Matrix &A22) const {
        int newSize = size / 2;
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                A11[i][j] = data[i][j];
                A12[i][j] = data[i][j + newSize];
                A21[i][j] = data[i + newSize][j];
                A22[i][j] = data[i + newSize][j + newSize];
            }
        }
    }

    void merge(const Matrix &C11, const Matrix &C12, const Matrix &C21, const Matrix &C22) {
        int newSize = size / 2;
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                data[i][j] = C11[i][j];
                data[i][j + newSize] = C12[i][j];
                data[i + newSize][j] = C21[i][j];
                data[i + newSize][j + newSize] = C22[i][j];
            }
        }
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Strassen {
public:
    static Matrix multiply(const Matrix &A, const Matrix &B) {
        int n = A.getSize();
        if (n == 1) {
            Matrix C(1);
            C[0][0] = A[0][0] * B[0][0];
            return C;
        }

        int newSize = n / 2;

        Matrix A11(newSize), A12(newSize), A21(newSize), A22(newSize);
        Matrix B11(newSize), B12(newSize), B21(newSize), B22(newSize);

        A.split(A11, A12, A21, A22);
        B.split(B11, B12, B21, B22);

        Matrix M1 = multiply(A11 + A22, B11 + B22);
        Matrix M2 = multiply(A21 + A22, B11);
        Matrix M3 = multiply(A11, B12 - B22);
        Matrix M4 = multiply(A22, B21 - B11);
        Matrix M5 = multiply(A11 + A12, B22);
        Matrix M6 = multiply(A21 - A11, B11 + B12);
        Matrix M7 = multiply(A12 - A22, B21 + B22);

        Matrix C11 = M1 + M4 - M5 + M7;
        Matrix C12 = M3 + M5;
        Matrix C21 = M2 + M4;
        Matrix C22 = M1 + M3 - M2 + M6;

        Matrix C(n);
        C.merge(C11, C12, C21, C22);

        return C;
    }
};

int main() {
    int n;
    cin >> n;

    Matrix A(n), B(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    Matrix C = Strassen::multiply(A, B);

    C.print();

    return 0;
}

