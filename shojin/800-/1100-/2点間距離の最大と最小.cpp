#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i=0; i<n; i++) cin >> d[i];
    sort(d.begin(), d.end());

    int M = d.back();
    int sum = accumulate(d.begin(), d.end()-1, 0);
    int m_ans, M_ans = sum + M;
    if(sum >= M) m_ans = 0;
    else m_ans = M - sum;

    cout << M_ans << endl;
    cout << m_ans << endl;
}