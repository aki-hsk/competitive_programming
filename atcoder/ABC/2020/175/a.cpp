#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    string s;
    cin >> s;
    int count = 0, max_count = 0;

    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'R') {
            count++;
        }
        else {
            count = 0;
        }
        max_count = max(count, max_count);
    }
    cout << max_count << endl;
}