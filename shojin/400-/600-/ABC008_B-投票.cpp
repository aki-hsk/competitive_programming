#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    rep(i, n) {
        string s;
        cin >> s;
        mp[s]++;
    }

    string ans;
    int max_bote = 0;
    for(auto m:mp) {
        if(max_bote < m.second) {
            ans = m.first;
            max_bote = m.second;
        }
    }
    cout << ans << endl;





    // mapで末尾のイテレータを取る
    // map降順
    // https://cpprefjp.github.io/reference/map/map/rbegin.html
    auto i = mp.rbegin();
    cout << i->first << endl;

    std::map<int,char>::reverse_iterator i = mp.rbegin();
    for( ; i != mp.rend() ; ++i ) std::cout << i->first << " " << i->second << std::endl;
}
