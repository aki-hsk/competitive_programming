#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// 入れれる筒のうち最も末尾が大きいものに入れていく
// dequeの各要素は筒の末尾
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    deque<int> d;
    for(int i=0; i<n; i++) {
        int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if(p == 0) {
            d.push_front(a[i]);
        }
        else d[p-1] = a[i];
    }
    cout << d.size() << endl;
    return 0;
}