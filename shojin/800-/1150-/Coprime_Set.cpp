#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 3) {
        cout << "6 10 15" << endl;
        return 0;
    }

    int cnt = 0;
    vector<int> ans;
    for(int i=1; i<=10000; i++) {
        if(cnt == n) break;
        if(i % 6 == 0 || i % 15 == 0 || i % 10 == 0) {
            cnt++;
            ans.push_back(i);
        }
    }
    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}