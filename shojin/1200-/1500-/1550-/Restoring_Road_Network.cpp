#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// （iからjへの距離）=（iからkへの距離）+（kからjへの距離）のようなkが存在した場合、k経由で迂回しても距離は変わらないので、iからjへの道路は不要
//  ある道路が必要なのはその道路が存在しないことでその道路が結ぶ都市間の最短距離が大きくなってしまう時である。

int main() {
    int n;
    cin >> n;
    vector<vector<long long>> a(n, vector<long long>(n));
    vector<vector<bool>> f(n, vector<bool>(n, true));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> a[i][j];
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(a[i][j] > a[i][k] + a[k][j]) {
                    cout << -1 << endl;
                    return 0;
                }
                else if(a[i][k] + a[k][j] == a[i][j] && i != k && k != j) {
                    f[i][j] = false;
                }
            }
        }
    }


    long long ans = 0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        if(f[i][j]) ans += a[i][j];
    }
    cout << ans / 2 << endl;
    return 0;
}
