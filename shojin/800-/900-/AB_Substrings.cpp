#include<iostream>
#include<vector>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    int both = 0, a = 0, b = 0;
    rep(i, n) {
        cin >> v[i];
        if(v[i][0] == 'B' && v[i].back() == 'A') both++;
        else if(v[i].back() == 'A') a++;
        else if(v[i][0] == 'B') b++;
    }

    int cnt = 0;
    rep(i, n) rep(j, v[i].size()-1) {
        if(v[i][j] == 'A' && v[i][j+1] == 'B') cnt++;
    }

    if(both == 0) cnt += min(a, b);
    else if(a + b > 0) cnt += both + min(a, b);
    else if(a + b == 0) cnt += both - 1;
    cout << cnt << endl;
}