#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
    // k:日数, t:食べた種類
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    for(int i=0; i<t; i++) cin >> a[i];

    int M = *max_element(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0);

    cout << max(0, M-1-(sum-M)) << endl;
}