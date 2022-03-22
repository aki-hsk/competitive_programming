#include<bits/stdc++.h>
using namespace std;

//名前空間::関数名
//名前空間::グローバル変数名
//名前空間::構造体名

// 名前空間A
namespace A {
    void f() {
        cout << "namespace A" << endl;
    }
}

namespace B {
    void f() {
        cout << "namespace B" << endl;
    }
}

int main() {
    A::f(); //名前空間Aの関数fの呼び出し
    B::f(); //名前空間Bの関数fの呼び出し
}