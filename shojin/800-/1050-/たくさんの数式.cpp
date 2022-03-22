#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    long long ans = 0;
    for(int bit=0; bit<(1<<(n-1)); bit++) {
        long long sum = 0, num = 0;
        for(int i=0; i<n; i++) {
            num *= 10;
            num += (s[i]-'0');
            if(bit>>i&1) {
                sum += num;
                num = 0;
            }
        }
        sum += num;
        ans += sum;
    }
    cout << ans << endl;
}