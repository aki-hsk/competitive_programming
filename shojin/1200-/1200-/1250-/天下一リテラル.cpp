#include<iostream>
#include<regex>
using namespace std;

int main() {
    string s;
    cin >> s;
    int b = 0;

    if(s == "{}") {
        cout << "dict" << endl;
        return 0;
    }

    for(int i=0; i<s.size(); i++) {
        if(b == 1 && s[i] == ':') {
            cout << "dict" << endl;
            return 0;
        }
        else if(s[i] == '{') b++;
        else if(s[i] == '}') b--;
    }
    cout << "set" << endl;
    return 0;
}