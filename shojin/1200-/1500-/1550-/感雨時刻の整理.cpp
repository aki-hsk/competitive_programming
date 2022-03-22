#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);

    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        string a = s.substr(0, 4);
        string b = s.substr(5);
        int A = stoi(a) - stoi(a) % 5;
        int B = (stoi(b) + 4) / 5 * 5;
        if(B % 100 == 60) {
            B = (B/100+1) * 100;
        }
        vp[i] = {A, B};
    }

    sort(vp.begin(), vp.end());
    vector<pair<int, int>> ans;
    int left = -1, right = -1;
    for(int i=0; i<n; i++) {
        int a = vp[i].first;
        int b = vp[i].second;
        if(right > b) continue;
        else if(a <= right) right = b;
        else if(right < a) {
            if(right != -1) ans.push_back({left, right});
            left = a;
            right = b;
        }
    }
    ans.push_back({left, right});

    for(auto p:ans) {
        printf("%04d-%04d\n", p.first, p.second);
    }
}