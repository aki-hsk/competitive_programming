#include <bits/stdc++.h>
using namespace std;

void dfs(int N, string s) {
    if(N == s.size()) {
        cout << s << endl;
        return;
    }
    dfs(N, s+'a');
    dfs(N, s+'b');
    dfs(N, s+'c');
}

int main() {
    int N;
    cin >> N;
    string s = "";
    dfs(N, s);
}