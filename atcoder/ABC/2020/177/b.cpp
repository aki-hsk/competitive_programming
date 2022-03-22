#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    string S, T;
    cin >> S >> T;
    int max_count = 0;
    for(int i=0; i<=S.size()-T.size(); i++) {
        int count=0;
        for(int j=0; j<T.size(); j++) {
            if(S[i+j] == T[j]) count++;
        }
        max_count = max(max_count, count);
    }
    cout << T.size()-max_count << endl;
}