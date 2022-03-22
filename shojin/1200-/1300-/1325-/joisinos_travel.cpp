#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int M = 205;
long long dist[205][205];

int main() {
    int n, m, R;
    cin >> n >> m >> R;
    vector<int> r(R);
    for(int i=0; i<R; i++) {
        cin >> r[i];
        r[i]--;
    }
    sort(r.begin(), r.end());
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = (1<<30);
        }
    }
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    // Floyd Warshal
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    long long ans = (1LL<<60);
    do {
        long long sum = 0;
        for(int i=0; i<R-1; i++) {
            sum += dist[r[i]][r[i+1]];
        }
        ans = min(ans, sum);
    } while(next_permutation(r.begin(), r.end()));
    cout << ans << endl;
}