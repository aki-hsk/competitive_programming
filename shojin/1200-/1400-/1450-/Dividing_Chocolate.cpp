#include<iostream>
#include<vector>
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin >> s[i];

    int ans = (1<<30);
    for(int div=0; div<(1<<(h-1)); div++) {
        // グループ数
        int g = 0;
        vector<int> id(h);
        for(int i=0; i<h; i++) {
            id[i] = g;
            if(div >> i&1) ++g;
        }
        ++g;
        vector<vector<int>> c(g, vector<int>(w));
        for(int i=0; i<h; i++) for(int j=0; j<w; j++) {
            c[id[i]][j] += (s[i][j]-'0');
        }
        bool ok = true;
        for(int i=0; i<g; i++) for(int j=0; j<w; j++) {
            if(c[i][j] > k) ok = false;
        }
        if(!ok) continue;
        int num = g-1;
        // グループごとの和
        vector<int> now(g);
        auto add = [&](int j) {
            for(int i=0; i<g; i++) now[i] += c[i][j];
            for(int i=0; i<g; i++) {
                if(now[i] > k) return false;
            }
            return true;
        };

        for(int j=0; j<w; j++) {
            if(!add(j)) {
                num++;
                now = vector<int>(g);
                add(j);
            }
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
    return 0;
}