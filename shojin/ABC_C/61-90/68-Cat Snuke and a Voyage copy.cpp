#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    int N, M;
    int a, b;
    cin >> N >> M;
    vector<bool> a1(N,false);
    vector<bool> an(N,false);

    for(int i=0; i<M; i++) {
        cin >> a >> b;
        if(a>b){
            swap(a,b);
        }
        if(a==1) a1[b]=true;
        if(b==N) an[a]=true;
    }

    for(int i=0; i<M; i++) {
        if(a1[i] && an[i]){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}