#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main() {
    string s;
    vector<string> v;
    getline(std::cin, s);
    istringstream stream(s);
    while ( stream >> s) {
        v.push_back(s);
    }

    int n;
    cin >> n;
    vector<string> ng(n);
    for(int i=0; i<n; i++) cin >> ng[i];

    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<ng.size(); j++) {
            bool flg = true;
            if(v[i].size() != ng[j].size()) continue;
            for(int k=0; k<v[i].size(); k++) {
                if(ng[j][k] == '*') continue;
                if(v[i][k] != ng[j][k]) flg = false;
            }

            if(flg) {
                string t;
                for(int x=0; x<v[i].size(); x++) t.push_back('*');
                v[i] = t;
            }
        }
    }

    for(int i=0; i<v.size(); i++) {
        if(i != v.size()-1) cout << v[i] << " ";
        else cout << v[i] << endl;
    }
}