#include<iostream>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    string ans = "No";
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++) {
            if(j*(n-i) + i*(m-j) == k) ans = "Yes";
        }
    }
    cout << ans << endl;
}