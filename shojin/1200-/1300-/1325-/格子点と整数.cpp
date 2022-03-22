#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for(int i=0; i<n; i++) cin >> x[i] >> y[i];

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                long long s2 = abs((x[i]-x[k])*(y[j]-y[k]) - (x[j]-x[k])*(y[i]-y[k]));
                if(s2 != 0 && s2 % 2 == 0) cnt++;
            }
        }
    }
    cout << cnt << endl;
}