#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n, C;
    cin >> n >> C;
    int d[C][C];
    for(int i=0; i<C; i++) {
        for(int j=0; j<C; j++) {
            cin >> d[i][j];
        }
    }
    vector<vector<int>> cnt(3, vector<int>(C));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int c;
            cin >> c;
            c--;
            cnt[(i+j)%3][c]++;
        }
    }
    int ans = (1<<30);
    for(int i=0; i<C; i++) {
        for(int j=0; j<C; j++) {
            for(int k=0; k<C; k++) {
                if(i == j || j == k || k == i) continue;
                int res = 0;
                // c[0]をi色にc[1]をj色にc[2]をk色に変える
                for(int l=0; l<C; l++) {
                    res += cnt[0][l] * d[l][i];
                    res += cnt[1][l] * d[l][j];
                    res += cnt[2][l] * d[l][k];
                }
                ans = min(ans, res);
            }
        }
    }
    cout << ans << endl;
    return 0;
}