#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
const double pi = 3.14159265358979323846;

double solve(int inside, int outside) {
    return outside * outside * pi - inside * inside * pi;
}

int main() {
    vector<int> a(3);
    for(int i=0; i<3; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int inside = (1<<30);
    int outside = accumulate(a.begin(), a.end(), 0);
    if(a[0] + a[1] > a[2]) inside = 0;
    else {
        inside = abs(a[2]-a[1]-a[0]);
    }
    printf("%.20f\n", solve(inside, outside));
}