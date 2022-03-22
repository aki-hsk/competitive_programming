#include<iostream>
#include<vector>
using namespace std;
const int INF = (1<<30);

int main() {
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++) cin >> t[i];
    vector<pair<int, int>> vp;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(t[i][j] == '#') vp.push_back({i, j});

    for(int k=0; k<4; k++) {
        vector<string> s2 = s;
        // 90度回転
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                s2[j][n-i-1] = s[i][j];

        int cnt = 0;
        bool flg = true;
        long long div_y = INF, div_x = INF;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(s[i][j] == '#') {
                    int ay = vp[cnt].first - i;
                    int ax = vp[cnt].second - j;
                    if(div_y == INF || div_x == INF) {
                        div_y = ay;
                        div_x = ax;
                    }
                    else if(div_y != ay || div_x != ax) {
                        flg = false;
                        break;
                    }
                    cnt++;
                }
            }
        }
        if(vp.size() != cnt) flg = false;
        if(flg) {
            cout << "Yes" << endl;
            return 0;
        }
        s = s2;
    }
    cout << "No" << endl;
    return 0;
}