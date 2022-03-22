#include<iostream>
#include<vector>
using namespace std;

int main() {
    string x;
    long long m;
    cin >> x >> m;
    if(x.size() == 1) {
        if(stoi(x) <= m) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    int d = 0;
    for(char c:x) d = max(d, int(c-'0'));
    long long l = d, r = m + 1;

    while(r-l > 1) {
        long long mid = (l + r) / 2;
        // mid真数で見たときにm以下かどうか
        long long v = 0;
        for(char c:x) {
            if(v > m/mid) v = m+1;
            else v = v * mid + (c-'0');
        }
        if(v <= m) l = mid;
        else r = mid;
    }
    cout << l-d << endl;
    return 0;
}