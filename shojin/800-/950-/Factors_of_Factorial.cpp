#include<iostream>
#include<vector>
using namespace std;

long long num[1001];

void num_of_div(long long n) {
    for(long long a=2; a*a<=n; a++) {
        if(n % a != 0) continue;
        int res = 0;
        while(n % a == 0) {
            n /= a;
            res++;
        }
        num[a] += res;
    }
    if(n != 1) num[n]++;
}

int main() {
    int n;
    cin >> n;

    long long ans = 1;
    for(int i=1; i<=n; i++) num_of_div(i);
    long long res = 1;
    for(int i=1; i<=n; i++) {
        res *= num[i]+1;
        res %= 1000000007;
    }
    cout << res << endl;
}