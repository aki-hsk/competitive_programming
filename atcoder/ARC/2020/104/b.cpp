#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for(int i=0; i<N; i++) {
        int c1=0, c2=0;
        for(int j=i; j<N; j++) {
            if(S[j] == 'A')
                c1++;
            else if(S[j] == 'T')
                c1--;
            else if(S[j] == 'G')
                c2++;
            else
                c2--;
            if(c1 == 0 && c2 == 0) ans++;
        }
    }
    cout << ans << endl;
}