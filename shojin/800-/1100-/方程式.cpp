#include<iostream>
#include<set>
using namespace std;

int num_of_digits(long long m) {
    int res = 0;
    while(m) {
        m /= 10;
        res++;
    }
    return res;
}

int sum_of_digits(long long m) {
    int res = 0;
    while(m) {
        res += m % 10;
        m /= 10;
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    int k = num_of_digits(n);
    set<long long> ans;
    for(int j=1; j<=k*9; j++) {
        long long m = n - j;
        if(sum_of_digits(m) != j) continue;
        ans.insert(m);
    }
    cout << ans.size() << endl;
    for(auto a:ans) cout << a << endl;
}