#include<iostream>
using namespace std;

// O(nlogn)
long long solve1(int m) {
    long long res = 0;
    for(int i=1; i<=m; i++) {
        for(int j=i; j<=m; j+=i) {
            res += j;
        }
    }
    return res;
}

// O(n)
long long solve2(int m) {
    long long res = 0;
    for(long long i=1; i<=m; i++) {
        res += i*(m/i*(m/i+1))/2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << solve1(n) << endl;
    cout << solve2(n) << endl;
}