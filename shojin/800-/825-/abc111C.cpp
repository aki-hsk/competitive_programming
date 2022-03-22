#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), odd(100001, 0), even(100001, 0);
    rep(i, n) {
        cin >> v[i];
        if(i % 2 == 1) odd[v[i]]++;
        else even[v[i]]++;
    }
    auto odd_iter = max_element(odd.begin(), odd.end());
    int odd_index = distance(odd.begin(), odd_iter);
    auto even_iter = max_element(even.begin(), even.end());
    int even_index = distance(even.begin(), even_iter);

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    int ans;
    if(odd_index == even_index) {
        ans = min(n-odd[0]-even[1], n-even[0]-odd[1]);
    }
    else ans = n - odd[0] - even[0];
    cout << ans << endl;
}