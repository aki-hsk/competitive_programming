#include<bits/stdc++.h>
using namespace std;

struct NumString {
    int length;
    string s;
    //コンストラクタ
    NumString(int num) {
        cout << "constructor called" << endl;

        //引数のnumを文字列かしたものをsに代入して、sの文字列をlengthに代入
        s = to_string(num);
        length = s.size();
    }
};

int main() {
    NumString num(12345); //コンストラクタに12345が渡される
    cout << "num.s:" << num.s << endl;
    cout << "num.length:" << num.length << endl;
}