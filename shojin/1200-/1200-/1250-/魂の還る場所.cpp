#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(3);
    for(int i=0; i<n; i++) {
        if(s[i] == 'R') cnt[0]++;
        else if(s[i] == 'G') cnt[1]++;
        else if(s[i] == 'B') cnt[2]++;
    }
    cout << cnt[0] % 2 + cnt[1] % 2 + cnt[2] % 2 << endl;
}