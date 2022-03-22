#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 半分全列挙

int main() {
    int n;
    long long S;
    cin >> n >> S;
    vector<long long> num(n);
    for(int i=0; i<n; i++) cin >> num[i];

    vector<long long> a;
    for(int bit=0; bit<(1<<n/2); bit++) {
        long long sum = 0;
        for(int i=0; i<(n/2); i++) {
            if(bit>>i&1) sum += num[i];
        }
        a.push_back(sum);
    }

    vector<long long> b;
    for(int bit=0; bit<(1<<(n-n/2)); bit++) {
        long long sum = 0;
        for(int i=0; i<(n-n/2); i++) {
            if(bit>>i&1) sum += num[n/2+i];
        }
        b.push_back(sum);
    }
    sort(b.begin(), b.end());
    long long ans = 0;
    for(auto x:a) {
        if(S - x >= 0) {
            long long b_sum = *(upper_bound(b.begin(), b.end(), S-x)-1);
            ans = max(ans, x + b_sum);
        }
    }
    cout << ans << endl;
}