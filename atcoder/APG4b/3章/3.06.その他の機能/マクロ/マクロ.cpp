#include<bits/stdc++.h>
using namespace std;

// my_coutというマクロを定義
//#define マクロ名 置き換えるプログラム
#define my_cout cout <<

// is_not_5というマクロを定義
#define is_not_5(n) if(n != 5)

//複数行のマクロ
#define my_macro cout << "hello" << endl; \
cout << "AtCoder" << endl; \
cout << "C++" << endl;

// repマクロ
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    // 次の行は cout <<"hello"に置き換わる
    my_cout "hello" << endl;

    is_not_5(10) {
        cout << "NOT 5" << endl;
    }

    my_macro;

    int sum = 0;
    // 0 ~ 9の和
    rep(i, 10) sum += i;
    cout << sum;
}