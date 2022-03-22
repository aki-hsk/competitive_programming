#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<string> c = {"A", "B", "X", "Y"};
    vector<string> v;
    for(auto a:c) {
        for(auto b:c) {
            string t = a + b;
            v.push_back(t);
        }
    }

    int ans = n;
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            if(i == j) continue;
            int cnt = 0;
            for(int k=0; k<s.size()-1; k++) {
                string t = s.substr(k, 2);
                if(t == v[i] || t == v[j]) {
                    cnt++;
                    k++;
                }
            }
            ans = min(ans, n-cnt);
        }
    }
    cout << ans << endl;
}