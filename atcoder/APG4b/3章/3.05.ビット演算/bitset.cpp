#include<bits/stdc++.h>
using namespace std;

int main() {
    bitset<8> a("00011011");
    bitset<8> b("00110101");

    auto c = a & b;
    cout << "1: " << c << endl;         // 00010001
    cout << "2: " << (c<<1) << endl;    // 00100010
    cout << "3: " << (c<<2) << endl;    // 01000100
    cout << "4: " << (c<<3) << endl;    // 10001000
    cout << "5: " << (c<<4) << endl;    // 00010000

    c <<= 4;      //00010000
    c ^= bitset<8>("11010000"); //XOR演算の複合代入演算子
    cout << "6: " << c << endl; //11000000
}