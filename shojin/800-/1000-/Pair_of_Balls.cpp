#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> que;
    vector<queue<int>> a(m);
    vector<vector<int>> mem(n);

    for(int i=0; i<m; i++) {
        int k;
        cin >> k;
        for(int j=0; j<k; j++) {
            int x;
            cin >> x;
            a[i].push(x-1);
        }
        mem[a[i].front()].push_back(i);
    }
    for(int i=0; i<n; i++) {
        if(mem[i].size() == 2) que.push(i);
    }
    while(!que.empty()) {
        int now = que.front(); que.pop();
        for(auto p:mem[now]) {
            a[p].pop();
            if(!a[p].empty()) {
                mem[a[p].front()].push_back(p);
                if(mem[a[p].front()].size() == 2) {
                    que.push(a[p].front());
                }
            }
        }
    }
    for(auto p:a) {
        if(!p.empty()) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}