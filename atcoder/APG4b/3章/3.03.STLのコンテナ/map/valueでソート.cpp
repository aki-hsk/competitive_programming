using namespace std;
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
int main()
{
    map<string, int> mp;
    mp["apple"] = 7;
    mp["orange"] = 3;
    mp["melon"] = 5;
    mp["peach"] = 0;
    mp["suica"] = 9;

    vector<pair<int, string>> v;

    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        v.push_back({ it->second, it->first });
    }
    sort(v.begin(), v.end());
    return 0;
}