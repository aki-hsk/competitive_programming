#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(n);
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        p[a].push_back(i);
    }

    for(int i=0; i<n; i++) {
        int pre = -1;
        p[i].push_back(n);
        for(int j:p[i]) {
            if(j-pre > m) {
                cout << i << endl;
                return 0;
            }
            pre = j;
        }
    }
    cout << n << endl;
    return 0;
}