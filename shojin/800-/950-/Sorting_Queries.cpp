#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> p_que;
    deque<int> d_que;
    rep(k, q) {
        int c;
        cin >> c;
        if(c == 1) {
            int x;
            cin >> x;
            d_que.push_back(x);
        }
        else if(c == 2) {
            if(!p_que.empty()) {
                cout << p_que.top() << endl;
                p_que.pop();
            }
            else {
                cout << d_que.front() << endl;
                d_que.pop_front();
            }
        }
        else {
            for(auto d:d_que) p_que.push(d);
            d_que.clear();
        }
    }
}