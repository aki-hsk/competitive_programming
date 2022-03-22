#include<iostream>
using namespace std;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    string ans;
    for(int i=0; i<ty-sy; i++) ans += 'U';
    for(int j=0; j<tx-sx; j++) ans += 'R';
    for(int i=0; i<ty-sy; i++) ans += 'D';
    for(int j=0; j<tx-sx; j++) ans += 'L';
    ans += 'L';
    for(int i=0; i<ty-sy+1; i++) ans += 'U';
    for(int j=0; j<tx-sx+1; j++) ans += 'R';
    ans += 'D';
    ans += 'R';
    for(int i=0; i<ty-sy+1; i++) ans += 'D';
    for(int j=0; j<tx-sx+1; j++) ans += 'L';
    ans += 'U';
    cout << ans << endl;
}