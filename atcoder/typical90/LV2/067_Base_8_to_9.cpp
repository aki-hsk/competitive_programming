#include<iostream>
#include<string>
using namespace std;

long long base8_to_long(string s) {
  long long res = 0;
  for(int i=0; i<s.size(); i++) {
    res = res * 8 + int(s[i] - '0');
  }
  return res;
}

string long_to_base9(long long n) {
  if(n == 0) return "0";
  string res;
  while(n) {
    res = char(n % 9 + '0') + res;
    n /= 9;
  }
  return res;
}

int main() {
  string s;
  int k;
  cin >> s >> k;
  for(int i=0; i<k; i++) {
    s = long_to_base9(base8_to_long(s));
    for(int j=0; j<s.size(); j++) {
      if(s[j] == '8') s[j] = '5';
    }
  }
  cout << s << endl;
}