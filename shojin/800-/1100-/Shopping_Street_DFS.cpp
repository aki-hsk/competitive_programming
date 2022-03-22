#include<iostream>
using namespace std;
int n;
int ans = -(1<<30);
int a[20];
int f[200][12], p[200][12];


void func() {
    int score = 0;
    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j<10; j++) {
            if(a[j] && f[i][j]) cnt++;
        }
        score += p[i][cnt];
    }
    ans = max(ans, score);
}

void dfs(int pos) {
    if(pos == 10) {
        bool flg = false;
        for(int i=0; i<10; i++) {
            if(a[i] == 1) flg = true;
        }
        if(flg) func();
        return;
    }
    a[pos] = 0; dfs(pos + 1);
    a[pos] = 1; dfs(pos + 1);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<10; j++) {
            cin >> f[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<11; j++) {
            cin >> p[i][j];
        }
    }
    dfs(0);
    cout << ans << endl;
}