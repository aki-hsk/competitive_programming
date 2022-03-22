#include<bits/stdc++.h>
using namespace std;

namespace A {
    namespace B {
        void f() {
            cout << "A::B::f" << endl;
        }
    }
    void f() {
        cout << "A::f" << endl;
    }
}



int main() {
    A::f();
    A::B::f();
}
