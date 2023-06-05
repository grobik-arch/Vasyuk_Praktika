#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    double tmp, d;
    cout << "Введите размер матрицы:\n";
    cout << "n = ";
    cin >> n;
    double** a = new double* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
    }
    cout << "Введите элемент матрицы:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = -a[i][k] / a[k][k];
            for (int j = 0; j < n; j++) {
                a[i][j] += a[k][j] * tmp;
            }
        }
    }
    
    d = 1;
    cout.precision(2);
    for (int i = 0; i < n; i++) {
        d *= a[i][i];
    }
    cout << fixed << "\nОпределитель матрицы: " << d << "\n";

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}