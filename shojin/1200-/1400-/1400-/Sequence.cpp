#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<long long> s(n);
    s[0] = a[0];
    for(int i=1; i<n; i++) s[i] = s[i] + a[i] + s[i-1];
    vector<long long> tmp = s;

    // + - + -
    long long offset = 0, ans = 0, sum = 0;
    for(int i=0; i<n; i++) {
        tmp[i] += offset;
        if(i % 2 == 0) {
            if(tmp[i] > 0) continue;
            else if(tmp[i] <= 0) {
                offset += -tmp[i] + 1;
                sum += abs(-tmp[i] + 1);
            }
        }
        else if(i % 2 == 1) {
            if(tmp[i] < 0) continue;
            else if(tmp[i] >= 0) {
                offset += -tmp[i] - 1;
                sum += abs(-tmp[i] - 1);
            }
        }
    }
    ans = sum;

    // - + - +
    sum = offset = 0;
    tmp = s;
    for(int i=0; i<n; i++) {
        tmp[i] += offset;
        if(i % 2 == 0) {
            if(tmp[i] < 0) continue;
            else if(tmp[i] >= 0) {
                offset += -tmp[i] - 1;
                sum += abs(-tmp[i] - 1);
            }
        }
        else if(i % 2 == 1) {
            if(tmp[i] > 0) continue;
            else if(tmp[i] <= 0) {
                offset += -tmp[i] + 1;
                sum += abs(-tmp[i] + 1);
            }
        }
    }
    ans = min(ans, sum);
    cout << ans << endl;
    return 0;
}