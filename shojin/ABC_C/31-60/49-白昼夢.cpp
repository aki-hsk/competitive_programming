#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    string S;
    cin >> S;
    string ss = "";

    for(int i=S.size()-1; i>=0; i--) {
        ss += S[i];
        if(ss == "maerd") ss="";
        else if(ss=="remaerd") ss="";
        else if(ss=="esare") ss="";
        else if(ss=="resare") ss="";
    }
    if(ss == "") cout << "YES" << endl;
    else cout << "NO" << endl;
}