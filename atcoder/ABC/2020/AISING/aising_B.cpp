#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];
 
    int count = 0;

    for(int i=0; i<v.size(); i++) {
        if(i % 2 == 0 and v[i] % 2 == 1) {
            count++;
        }
    }
    cout << count << endl;
}