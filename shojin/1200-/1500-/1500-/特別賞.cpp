#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]] = i+1;
    }
    priority_queue<int> pq;
    for(int i=0; i<k; i++) pq.push(a[i]);
    cout << mp[pq.top()] << endl;
    for(int i=k; i<n; i++) {
        int t_score = pq.top();
        if(a[i] < t_score) {
            pq.pop();
            pq.push(a[i]);
        }
        cout << mp[pq.top()] << endl;
    }
    return 0;
}