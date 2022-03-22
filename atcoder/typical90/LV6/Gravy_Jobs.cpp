#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Task{
    int d, c, s;
    Task(int d, int c, int s):d(d), c(c), s(s) {}
};

bool compare(Task a, Task b) {
    if(a.d != b.d) return a.d < b.d;
    else if(a.c != b.c) return a.c < b.d;
    else return a.s < b.s;
}

long long dp[5005][5005];

int main() {
    int n;
    cin >> n;
    vector<Task> tasks;
    for(int i=0; i<n; i++) {
        int d, c, s;
        cin >> d >> c >> s;
        tasks.push_back({d, c, s});
    }
    sort(tasks.begin(), tasks.end(), compare);

    for(int i=0; i<n; i++) {
        for(int j=0; j<=5000; j++) {
            // 仕事iをやらない
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            // 仕事iをやる
            if(j+tasks[i].c <= tasks[i].d) {
                dp[i+1][j+tasks[i].c] = max(dp[i+1][j+tasks[i].c], dp[i][j] + tasks[i].s);
            }
        }
    }
    long long ans = 0;
    for(int i=0; i<=5000; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}