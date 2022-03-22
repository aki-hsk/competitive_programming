#include<iostream>
#include<vector>
using namespace std;
// https://blog.hamayanhamayan.com/entry/2017/07/30/030601

vector<long long> build(long long k) {
    vector<long long> ans;

    long long d = k % 50;
    for(int i=0; i<50; i++) {
        if(i < d) ans.push_back(50);
        else ans.push_back(49-d);
    }
    long long a = k / 50;
    for(int i=0; i<50; i++) ans[i] += a;
    return ans;
}

int main() {
    long long k;
    cin >> k;
    vector<long long> ans = build(k);
    cout << ans.size() << endl;;
    for(int i=0; i<50; i++) {
        cout << ans[i] << (i == 49 ? "\n" : " ");
    }
}