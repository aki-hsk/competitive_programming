#include<iostream>
#include<vector>
using namespace std;

int a, b;
vector<vector<char>> ans(100, vector<char>(100, '.'));

void paint_white(int i, int j) {
    for(int y=0; y<3; y++) {
        for(int x=0; x<3; x++) {
            if(x == 1 && y == 1) continue;
            else ans[y+i][x+j] = '#';
        }
    }
}

void paint_black(int i, int j) {
    for(int y=0; y<3; y++) {
        for(int x=0; x<3; x++) {
            ans[y+i][x+j] = '#';
        }
    }
}

int main() {
    cin >> a >> b;
    bool rev = false;
    if(a > b) {
        rev = true;
        swap(a, b);
    }
    int i = 0, j = 0;
    a--;
    while(a || b) {
        if(j >= 100) {
            if(b > 0) i += 4;
            else i += 3;
            j = 0;
        }
        if(a) paint_white(i, j);
        else paint_black(i, j);

        if(a) a--;
        if(b) b--;

        if(b) j += 4;
        else j += 3;
    }

    cout << 100 << " " << 100 << endl;
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(rev) {
                if(ans[i][j] == '.') cout << "#";
                else cout << ".";
            }
            else cout << ans[i][j];
        }
        cout << endl;
    }
}