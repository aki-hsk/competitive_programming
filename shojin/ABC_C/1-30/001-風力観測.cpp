#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> direction = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
    vector<double> wind_power = {0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6, 100.00 };
    double deg, dis;
    cin >> deg >> dis;

    int a = (deg + 112.5) / 225.0;
    string d =  direction[a];
    dis /= 60.0;
    int p;
    // 下2桁四捨五入
    dis = round(dis*10) / 10;
    for(int i=0; i<wind_power.size(); i++) {
        if(dis > wind_power[i]) continue;
        p = i;
        break;
    }

    if(p == 0) cout << "C" << " " << 0 << endl;
    else cout << d << " " << p << endl;
}

