#include<iostream>
#include<vector>
#include<set>
using namespace std;

long long divisor_sum(long long n) {
    set<long long> st;
    for(long long i=1; i*i<=n; i++) {
        if(n % i == 0) {
            st.insert(i);
            st.insert(n/i);
        }
    }
    long long res = 0;
    for(auto s:st) res += s;
    return res;
}

int main() {
    long long n;
    cin >> n;
    long long sum = divisor_sum(n);
    if(n*2 == sum) cout << "Perfect" << endl;
    else if(n*2 < sum) cout << "Abundant" << endl;
    else cout << "Deficient" << endl;
}