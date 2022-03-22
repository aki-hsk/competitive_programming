#include<iostream>
#include<set>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    set<string> st;
    for(int i=1; i<=min(5, (int)s.size()); i++) {
        for(int j=0; j<s.size()-i+1; j++) {
            st.insert(s.substr(j, i));
        }
    }

    int cnt = 0;
    for(auto s:st) {
        cnt++;
        if(cnt == k) {
            cout << s << endl;
            return 0;
        }
    }
}