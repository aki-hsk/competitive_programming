#include<iostream>
#include<queue>
using namespace std;

int main() {
    string s;
    cin >> s;
    deque<char> que;
    for(int i=0; i<s.size(); i++) que.push_back(s[i]);
    int ans = 0;

    while(que.size() > 1) {
        if(que.front() == que.back()) {
            que.pop_front();
            que.pop_back();
        }
        else if(que.front() == 'x') {
            que.push_back('x');
            ans++;
        }
        else if(que.back() == 'x') {
            que.push_front('x');
            ans++;
        }
        else if(que.front() != que.back()) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}