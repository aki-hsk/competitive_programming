#include<iostream>
#include<vector>
using namespace std;

// https://drken1215.hatenablog.com/entry/2019/04/14/222900

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    //  「1 の個数」「0 の個数」を交互に記録していく
    vector<int> nums;
    if(s[0] == '0') nums.push_back(0);
    for(int i=0; i<s.size();) {
        int j = i;
        while(j < s.size() && s[j] == s[i]) ++j;
        nums.push_back(j-i);
        i = j;
    }
    if(s.back() == '0') nums.push_back(0);

    // 累積和
    vector<int> sums(nums.size()+1, 0);
    for(int i=0; i<nums.size(); i++) sums[i+1] = sums[i] + nums[i];

    int res = 0;
    // 偶数番目の添字から始まる、長さ2K+1の区間の総和のうち、最大値を求める
    for(int left = 0; left < sums.size(); left += 2) {
        int right = left + k*2+1;
        if(right >= sums.size()) right = sums.size()-1;
        res = max(res, sums[right]-sums[left]);
    }
    cout << res << endl;
}