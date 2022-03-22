#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N, count=0;
    cin >> N;
    vector<int> V(N);
    for(int i=0; i<N;i++) cin >> V[i];
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int k=j+1; k<N; k++) {
                if(V[i] == V[j] || V[i] == V[k] || V[j] == V[k]) continue;
                if(V[k] < V[i] + V[j] && V[i] < V[j]+V[k] && V[j] < V[i] + V[k]) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}