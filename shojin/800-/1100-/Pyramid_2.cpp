#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vx(n), vy(n), vh(n);
    int si = -1;
    for(int i=0; i<n; i++) {
        cin >> vx[i] >> vy[i] >> vh[i];
        if(vh[i] > 0) si = i;
    }

    for(int x=0; x<=100; x++) {
        for(int y=0; y<=100; y++) {
            int h = vh[si]+abs(x-vx[si])+abs(y-vy[si]);
            bool ok = true;
            for(int i=0; i<n; i++) {
                if(vh[i] > 0 && h-vh[i] != abs(x-vx[i]) + abs(y-vy[i])) {
                    ok = false;
                }
                if(vh[i] == 0 && h>abs(x-vx[i])+abs(y-vy[i])) {
                    ok = false;
                }
            }
            if(ok) {
                cout << x << " " << y << " " << h << endl;
                return 0;
            }
        }
    }
}