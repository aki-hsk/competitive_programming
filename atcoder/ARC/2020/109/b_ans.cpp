#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	ll left = 0, right = (ll)3e9;

	while(right - left > 1) {
		ll mid = (right + left) / 2;
		ll x = (mid * (mid + 1)) / 2;
		if(x <= n + 1) left = mid;
		else right = mid;
	}

	cout << n + 1 - left << endl;
}