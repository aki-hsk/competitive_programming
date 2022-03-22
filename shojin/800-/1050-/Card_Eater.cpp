#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int even_cnt = 0;
    for(auto m:mp) {
        if(m.second % 2 == 1 || m.second == 0) continue;
        else even_cnt++;
    }

    int ans = mp.size();
    if(even_cnt % 2 == 1) ans--;
    cout << ans << endl;

}