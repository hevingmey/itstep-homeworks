#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
class Matrix {
private:
    int rows;
    int cols;
    T* data;

public:

    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        if (rows > 0 && cols > 0)
            data = new T[rows * cols]{};
        else
            data = nullptr;
    }

    Matrix(const Matrix& obj) : rows(obj.rows), cols(obj.cols) {
        data = new T[rows * cols];
        for (int i = 0; i < rows * cols; i++)
            data[i] = obj.data[i];
    }

    Matrix& operator=(const Matrix& obj) {
        if (this == &obj) return *this;

        delete[] data;

        rows = obj.rows;
        cols = obj.cols;

        data = new T[rows * cols];
        for (int i = 0; i < rows * cols; i++)
            data[i] = obj.data[i];

        return *this;
    }

    ~Matrix() {
        delete[] data;
    }

    T& at(int r, int c) {
        return data[r * cols + c];
    }

    const T& at(int r, int c) const {
        return data[r * cols + c];
    }

    void input() {
        cout << "Введiть " << rows * cols << " елементiв:\n";
        for (int i = 0; i < rows * cols; i++)
            cin >> data[i];
    }

    void fillRandom(T minV, T maxV) {
        for (int i = 0; i < rows * cols; i++)
            data[i] = minV + rand() % (maxV - minV + 1);
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << at(i, j) << "\t";
            cout << "\n";
        }
    }

    T minElement() const {
        T m = data[0];
        for (int i = 1; i < rows * cols; i++)
            if (data[i] < m) m = data[i];
        return m;
    }

    T maxElement() const {
        T m = data[0];
        for (int i = 1; i < rows * cols; i++)
            if (data[i] > m) m = data[i];
        return m;
    }

    Matrix operator+(const Matrix& obj) const {
        Matrix r(rows, cols);
        for (int i = 0; i < rows * cols; i++)
            r.data[i] = data[i] + obj.data[i];
        return r;
    }

    Matrix operator-(const Matrix& obj) const {
        Matrix r(rows, cols);
        for (int i = 0; i < rows * cols; i++)
            r.data[i] = data[i] - obj.data[i];
        return r;
    }

    Matrix operator*(const Matrix& obj) const {
        Matrix r(rows, cols);
        for (int i = 0; i < rows * cols; i++)
            r.data[i] = data[i] * obj.data[i];
        return r;
    }

    Matrix operator/(const Matrix& obj) const {
        Matrix r(rows, cols);
        for (int i = 0; i < rows * cols; i++)
            r.data[i] = data[i] / obj.data[i]; 
        return r;
    }
};

int main() {
    srand(time(nullptr));

    Matrix<int> A(3, 3);
    Matrix<int> B(3, 3);

    A.fillRandom(1, 9);
    B.fillRandom(1, 9);

    cout << "A:\n";
    A.print();

    cout << "\nB:\n";
    B.print();

    Matrix<int> C = A + B;
    cout << "\nA + B:\n";
    C.print();

    cout << "\nMin(A) = " << A.minElement() << endl;
    cout << "Max(A) = " << A.maxElement() << endl;

    return 0;
}
