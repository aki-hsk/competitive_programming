#include<iostream>
#include<map>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<string, bool> mp;
  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    if(mp.find(s) == mp.end()) {
      cout << i+1 << endl;
      mp[s] = true;
    }
  }
}