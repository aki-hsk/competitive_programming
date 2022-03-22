#include<iostream>
using namespace std;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int board[h][w];
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) board[i][j] = -1;

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(i < b && j < a) board[i][j] = 0;
            if(i < b && j >= a) board[i][j] = 1;
            if(i >= b && j < a) board[i][j] = 1;
            if(i >= b && j >= a) board[i][j] = 0;
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}