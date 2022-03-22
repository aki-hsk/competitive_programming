#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque<int> dq = {n};
    for(int i=n-1; i>=0; i--) {
        if(s[i] == 'L') dq.push_back(i);
        else dq.push_front(i);
    }
    for(auto x:dq) cout << x << endl;
    return 0;
}