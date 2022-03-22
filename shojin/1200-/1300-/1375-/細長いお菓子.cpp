#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int right = 0, ans = 0;
    vector<int> v(100005);
    for(int left=0; left<n; left++) {
        while(right < n && v[a[right]] == 0) {
            v[a[right]]++;
            right++;
        }
        if(left == right) right++;
        v[a[left]]--;
        ans = max(ans, right - left);
    }
    cout << ans << endl;
}