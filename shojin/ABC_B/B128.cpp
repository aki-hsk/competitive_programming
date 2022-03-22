#include <bits/stdc++.h>
using namespace std;

char in[120];
pair<pair<string, int>, int> p[110];

int main() {
    int a;
    cin >> a;
    for(int i=0; i<a; i++) {
        int t;
        cin >> t;
        string tmp = in;
        p[i] = make_pair(make_pair(in, -t), i);
    }
    sort(p, p+a);
    for(int i=0; i<a; i++) cout << p[i];
}