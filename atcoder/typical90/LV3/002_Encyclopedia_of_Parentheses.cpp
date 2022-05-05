#include<iostream>
#include<vector>
using namespace std;

void rec(int left, int right, string s, int siz) {
    if(s.size() == siz) {
        if(left == right) printf("%s\n", s.c_str());
        return;
    }
    rec(left + 1, right, s + '(', siz);
    if(left > right) rec(left, right + 1, s + ')', siz);
}

int main() {
    int n;
    cin >> n;
    if(n % 2 == 1) return 0;
    rec(0, 0, "", n);
}