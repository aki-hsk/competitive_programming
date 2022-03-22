#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, a;
    string s;
    cin >> n >> a >> s;
    a--;
    vector<int> b(n);
    for(int i=0; i<n; i++) {
        cin >> b[i];
        b[i]--;
    }

    if(s.size() <= 6 && stoll(s) <= n) {
        int x = a;
        for(int i=0; i<stoll(s); i++) {
            x = b[x];
        }
        cout << x + 1 << endl;
        return 0;
    }

    // ループに入る場合
    // いつか循環するので先に % で計算しても問題なさそう
    // もし足りなかったらmodを加える
    vector<int> id(n, -1);
    int x = a, l = 0;
    while(id[x] == -1) {
        id[x] = l;
        x = b[x];
        l++;
    }
    int len = l-id[x];
    int r = 0;
    for(int i=0; i<s.size(); i++) {
        r = (r * 10 + (s[i]-'0')) % len;
    }

    while(r < id[x]) r += len;
    x = a;
    for(int i=0; i<r; i++) {
        x = b[x];
    }
    cout << x + 1 << endl;
    return 0;
}