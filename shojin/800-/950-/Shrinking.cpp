#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> v;

    for(int i=0; i<n; i++) {
        string t = s.substr(i);
        v.push_back(t);
        for(char c='a'; c<='z'; c++) {
            bool flg = true;
            for(int j=0; j<v[i].size(); j++) {
                bool ok = false;
                for(int k=0; k<v.size(); k++) {
                    if(v[k][j] == c) ok = true;
                }
                if(!ok) {
                    flg = false;
                    break;
                }
            }
            if(flg) {
                cout << i << endl;
                return 0;
            }
        }
    }
}