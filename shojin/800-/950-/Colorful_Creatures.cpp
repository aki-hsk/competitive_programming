#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    long long sum = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        sum += a[i];
        ans = n-i;
        while(i+1 < n && sum*2 >= a[i+1]) {
            sum += a[i+1];
            i++;
        }
    }
    cout << ans << endl;
}