#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<long long> p(a), q(b), r(c);
    for(int i=0; i<a; i++) cin >> p[i];
    for(int i=0; i<b; i++) cin >> q[i];
    for(int i=0; i<c; i++) cin >> r[i];

    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    vector<long long> v = r;
    for(int i=0; i<x; i++) v.push_back(p[i]);
    for(int i=0; i<y; i++) v.push_back(q[i]);
    sort(v.rbegin(), v.rend());
    cout << accumulate(v.begin(), v.begin()+x+y, 0LL) << endl;
}