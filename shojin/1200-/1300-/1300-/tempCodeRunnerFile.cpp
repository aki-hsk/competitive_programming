#include<iostream>
#include<vector>
using namespace std;

class BIT {
public:
    // データの長さ
    long long n;
    vector<long long> a;
    // コンストラクタ
    BIT(long long n):n(n), a(n+1, 0) {}
    //a[i]にxを加算する
    void add(long long i, long long x) {
        i++;
        if(i == 0) return;
        for(int k=i; k<=n; k+=(k & -k)) {
            a[k] += x;
        }
    }
    //a[i]+a[i+1]+…+a[j]を求める
    long long sum(long long i, long long j) {
        return sum_sub(j)-sum_sub(i-1);
    }
    long long sum_sub(long long i) {
        i++;
        long long s = 0;
        if(i == 0) return s;
        for(long long k=i; k>0; k-=(k & -k)) {
            s += a[k];
        }
        return s;
    }
};


int main() {
    long long n;
    cin >> n;
    vector<long long> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    long long ans = 0;
    BIT bit(n);
    for(long long a:A) {
        ans += bit.sum(a, n);
        bit.add(a, 1);
    }
    for(long long a:A) {
        cout << ans << "\n";
        ans += n-1-a*2;
    }
}