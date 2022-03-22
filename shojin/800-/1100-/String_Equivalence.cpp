#include<iostream>
using namespace std;

int n;
void rec(string s, char c) {
    if(s.size() == n) {
        // C言語での文字列表現を取得する。
        printf("%s\n", s.c_str());
        return;
    }
    for(char x='a'; x<=c; x++) {
        rec(s+x, (x == c) ? c+1 : c);
    }
}

int main() {
    cin >> n;
    rec("", 'a');
    return 0;
}