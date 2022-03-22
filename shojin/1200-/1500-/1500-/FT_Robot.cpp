#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;
    vector<int> ax, ay;

    bool xd = true;
    int i = 0;
    while(i < s.size()) {
        if(s[i] == 'T') {
            xd = !xd;
            i++;
        }
        int cnt = 0;
        while(s[i] == 'F') {
            i++;
            cnt++;
        }
        if(cnt > 0) {
            if(xd) ax.push_back(cnt);
            else ay.push_back(cnt);
        }
    }


    // (10000, 10000)をスタートとする
    const int S = 10000;
    vector<bool> dpx(2*S), dpy(2*S);
    dpx[S] = dpy[S] = true;

    int nx = ax.size();
    int ny = ay.size();

    // dx方向
    for(int i=0; i<nx; i++) {
        vector<bool> px(2*S);
        swap(dpx, px);
        // px -> dpx
        if(i == 0 && s[0] == 'F') {
            dpx[S+ax[0]] = true;
            continue;
        }
        for(int j=0; j<S*2; j++) {
            if(!px[j]) continue;
            dpx[j+ax[i]] = true;
            dpx[j-ax[i]] = true;
        }
    }

    // dy方向
    for(int i=0; i<ny; i++) {
        vector<bool> py(2*S);
        // py -> dpy
        swap(dpy, py);
        for(int j=0; j<S*2; j++) {
            if(!py[j]) continue;
            dpy[j+ay[i]] = true;
            dpy[j-ay[i]] = true;
        }
    }
    if(dpx[S+x] && dpy[S+y]) cout << "Yes" << endl;
    else cout << "No" << endl;
}