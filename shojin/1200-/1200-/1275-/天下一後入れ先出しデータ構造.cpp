#include<iostream>
#include<vector>
using namespace std;

int main() {
    long long q, l;
    cin >> q >> l;
    long long cnt = 0;
    // {number, cnt}
    vector<pair<int, int>> vp;
    for(int qi=0; qi<q; qi++) {
        string s;
        cin >> s;
        if(s == "Push") {
            // mをn個追加
            int n, m;
            cin >> n >> m;
            cnt += n;
            if(cnt > l) {
                cout << "FULL" << endl;
                return 0;
            }
            vp.push_back({m, n});
        }
        else if(s == "Pop") {
            // n個取り出す
            int n;
            cin >> n;
            cnt -= n;
            if(cnt < 0) {
                cout << "EMPTY" << endl;
                return 0;
            }
            int siz = vp.size();
            for(int i=siz-1; i>=0; i--) {
                if(n - vp[i].second >= 0) {
                    n -= vp[i].second;
                    vp.pop_back();
                }
                else {
                    vp[i].second -= n;
                    break;
                }
            }
        }
        else if(s == "Top") {
            if(cnt == 0) {
                cout << "EMPTY" << endl;
                return 0;
            }
            cout << vp.back().first << endl;
        }
        else if(s == "Size") {
            cout << cnt << endl;
        }
    }
    cout << "SAFE" << endl;
    return 0;
}