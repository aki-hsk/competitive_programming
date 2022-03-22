#include<bits/stdc++.h>

int main() {
    std::vector<int> a = {3,4,1,2};
    std::sort(a.begin(), a.end());
    for(int i=0; i<a.size(); i++) {
        std::cout << a.at(i) << std::endl;
    }
}