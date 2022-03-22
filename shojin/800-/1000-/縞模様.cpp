#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n, c;
    cin >> n >> c;
    vector<int> a(n);

    int ans = (1<<30);
    for(int i=0; i<n; i++) cin >> a[i];

    // 偶数番目
    for(int i=1; i<=10; i++) {
        // 奇数番目
        for(int j=1; j<=10; j++) {
            // 画用紙
            if(i == j) continue;
            int x = 0;
            for(int k=0; k<n; k++) {
                if(k % 2 == 0 && a[k] != i) x++;
                if(k % 2 == 1 && a[k] != j) x++;
            }
            ans = min(ans, x * c);
        }
    }
    cout << ans << endl;
}