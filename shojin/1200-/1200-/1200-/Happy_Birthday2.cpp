#include<iostream>
#include<vector>
using namespace std;

void output(int x) {
    int c = 1;
    vector<int> ans;
    while(x) {
        if(x&1) ans.push_back(c);
        x >>= 1;
        c++;
    }
    cout << ans.size();
    for(auto a:ans) cout << " " << a;
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    n = min(8, n);

    vector<int> num(200, -1);
    for(int bit=1; bit<(1<<n); bit++) {
        int res = 0;
        for(int i=0; i<n; i++) {
            if(bit>>i&1) {
                res += a[i];
                res %= 200;
            }
        }
        if(num[res] != -1) {
            cout << "Yes" << endl;
            output(num[res]);
            output(bit);
            return 0;
        }
        num[res] = bit;
    }
    cout << "No" << endl;
    return 0;
}