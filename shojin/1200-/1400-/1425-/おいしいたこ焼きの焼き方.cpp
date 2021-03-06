#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> d[i][j];

    // 累積和
    vector<vector<int>> s(n+1, vector<int>(n+1, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + d[i][j];

    // すべての長方形の面積を計算
    vector<int> val(n*n+1, 0);
    for(int x1=0; x1<n; x1++) {
        for(int x2=x1+1; x2<=n; x2++) {
            for(int y1=0; y1<n; y1++) {
                for(int y2=y1+1; y2<=n; y2++) {
                    int area = (x2-x1) * (y2-y1);
                    int sum = s[x2][y2]-s[x1][y2]-s[x2][y1]+s[x1][y1];
                    val[area] = max(val[area], sum);
                }
            }
        }
    }

    for(int v=0; v<n*n; v++) val[v+1] = max(val[v+1], val[v]);
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int p;
        cin >> p;
        cout << val[p] << endl;
    }
}