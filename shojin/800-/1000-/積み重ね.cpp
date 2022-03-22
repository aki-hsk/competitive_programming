#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;

    for(int i=0; i<n; i++) {
        int w;
        cin >> w;
        if(i == 0 ) {
            v.push_back(w);
            continue;
        }
        int x = -1;
        int m = (1<<30);
        for(int j=0; j<v.size(); j++) {
            if(v[j] < w) continue;
            else if(v[j] < m) {
                x = j;
                m = v[j];
            }
        }
        if(x == -1) v.push_back(w);
        else v[x] = w;
    }
    cout << v.size() << endl;
}