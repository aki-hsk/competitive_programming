#include<iostream>
using namespace std;

int n;
void rec(int left, string s) {
    if(s.size() == n) {
        if(left == n-left) printf("%s\n", s.c_str());
        return;
    }
    int right = s.size() - left;
    rec(left + 1, s + "(");
    if(right < left) rec(left, s + ")");
    return;
}

int main() {
    cin >> n;
    rec(0, "");
}