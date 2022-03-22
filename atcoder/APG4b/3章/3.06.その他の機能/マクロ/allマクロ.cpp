#include<bits/stdc++.h>
using namespace std;

//allマクロの定義
#define all(v) v.begin(), v.end()

int main() {
    vector<int> v = {2, 3, 1};
    sort(all(v));
    cout << v[0] << endl;
}