#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// https://www.youtube.com/watch?v=1Z6ofKN03_Y

// m = 4
// a, b    = 4, 3
//         = 4, 1
//         = 2, 2
//         = 1, 4
//         = 1, 2


// 前から見ていくと①給料が多い ②もらえるまでの日数が多い
// これらどちらを優先するべきか定まらない。

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> jobs(m);
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        if(a > m) continue;
        jobs[m-a].push_back(b);
    }
    priority_queue<int> q;
    long long ans = 0;

    for(int i=m-1; i>=0; i--) {
        for(int b:jobs[i]) q.push(b);
        if(!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}