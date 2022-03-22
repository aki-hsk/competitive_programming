#include<iostream>
#include<vector>
using namespace std;

bool include(string s, char c) {
    for(int i=0; i<s.size(); i++) {
        if(s[i] == c) return true;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> d(k);
    for(int i=0; i<k; i++) cin >> d[i];

    for(int i=n; i<=100000; i++) {
        bool ok = true;
        for(int j=0; j<k; j++) {
            if(include(to_string(i), d[j]+'0')) ok = false;
        }
        if(ok) {
            cout << i << endl;
            return 0;
        }
    }
}