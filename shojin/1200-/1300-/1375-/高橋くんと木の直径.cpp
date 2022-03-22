#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max_d = 0;
    int farthest_e;
    for(int i=1; i<n; i++) {
        int dist;
        cout << "? " << 1 << " " << i+1 << endl;
        cin >> dist;
        if(dist > max_d) {
            max_d = dist;
            farthest_e = i+1;
        }
    }

    max_d = 0;
    for(int i=0; i<n; i++) {
        int dist;
        cout << "? " << farthest_e << " " << i+1 << endl;
        cin >> dist;
        if(dist > max_d) max_d = dist;
    }
    cout << "! " << max_d << endl;
}