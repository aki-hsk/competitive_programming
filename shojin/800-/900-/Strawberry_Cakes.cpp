#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int H, W, K, A[309][309], num;
int cnt[309];
char c[309][309];

void solve(int cl, int cr) {
	vector<int> P;

	// 行でやったことを列でもやる
	for(int i=cl; i<=cr; i++) {
		for(int j=0; j<W; j++) {
			if(c[i][j] == '#') P.push_back(j);
		}
	}
	sort(P.begin(), P.end());

	for(int i=0; i<P.size(); i++) {
		// どの列で切るか
		int v1 = 0, v2 = W-1;
		if(i >= 1) v1 = P[i-1] + 1;
		if(i < P.size() - 1) v2 = P[i];
		num++;
		for(int j=cl; j<=cr; j++) {
			for(int k=v1; k<=v2; k++) A[j][k] = num;
		}
	}
}

int main() {
	cin >> H >> W >> K;
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			cin >> c[i][j];
			// 行ごとにイチゴの個数を保存
			if(c[i][j] == '#') cnt[i]++;
		}
	}

	vector<int> vec;
	// イチゴが一個以上ある行をvecに入れる
	for(int i=0; i<H; i++) if(cnt[i] >= 1) vec.push_back(i);
	// どの行からどの行まで切るか？
	// v1が始め, v2が最後
	for(int i=0; i<vec.size(); i++) {
		int v1 = 0, v2 = H-1;
		// 前のイチゴがあった行の次の行
		if(i >= 1) v1 = vec[i-1] + 1;
		if(i < vec.size() - 1) v2 = vec[i];

		solve(v1, v2);
	}

	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			if(j >= 1) cout << " "; cout << A[i][j];
		}
		cout << endl;
	}
	return 0;
}