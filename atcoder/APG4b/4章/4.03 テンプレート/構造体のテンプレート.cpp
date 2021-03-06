#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Point {
    T x;
    T y;
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // int型用のPoint構造体
    Point<int> p1 = {0, 1};
    p1.print(); // (0, 1)

    // int型用のPoint構造体
    Point<double> p2 = {2.3, 4.5};
    p2.print(); // (0, 1)

}