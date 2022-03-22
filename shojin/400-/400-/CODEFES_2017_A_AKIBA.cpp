#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    cin >> s;

    vector<string> v = {"AKIHABARA", "KIHABARA", "AKIHBARA", "AKIHABRA", "AKIHABAR", "KIHBARA","KIHABRA", "KIHABAR", "AKIHBRA", "AKIHBAR", "AKIHABR", "KIHBRA", "KIHBAR", "KIHABR", "AKIHBR", "KIHBR"};
    rep(i, v.size()) {
        if(s == v[i]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}