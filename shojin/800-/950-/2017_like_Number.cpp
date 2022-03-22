#include<iostream>
#include<vector>
using namespace std;

const int MAX = 100005;

// エラトステネスの篩
void sieve_of_eratosthenes(vector<bool> &prime) {
    prime[0] = prime[1] = false;
    for(int i=2; i*i<MAX; i++) {
        if(!prime[i]) continue;
        for(int j=i+i; j<=MAX; j+=i) {
            prime[j] = false;
        }
    }
}

int main() {
    int q;
    cin >> q;
    vector<bool> prime(MAX, true);
    sieve_of_eratosthenes(prime);
    vector<int> sum(MAX, 0);
    for(int i=2; i<MAX; i++) {
        sum[i] = sum[i-1];
        if(prime[i] && prime[(i+1)/2]) sum[i]++;
    }

    for(int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        cout << sum[r]-sum[l-1] << endl;
    }
    return 0;
}