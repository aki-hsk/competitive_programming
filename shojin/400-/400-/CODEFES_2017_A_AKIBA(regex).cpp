#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main() {
    string S;
    cin >> S;
    bool flg = regex_match(S, regex("A?KIHA?BA?RA?"));
    cout << (flg ? "YES" : "NO") << endl;
}
