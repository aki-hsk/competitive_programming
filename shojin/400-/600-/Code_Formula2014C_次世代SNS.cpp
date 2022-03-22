#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    // 1行分を入力
    getline(cin, S);
    S.push_back(' ');
    set<string> se;

    for(int i=1; i<S.size(); i++) {
        if(S[i-1] == '@') {
            string t;
            while(isalpha(S[i])) {
                t.push_back(S[i]);
                i++;
            }
            if(t.size() == 0) continue;
            se.insert(t);
        }
    }
    for(auto s:se) {
        cout << s << endl;
    }
}
