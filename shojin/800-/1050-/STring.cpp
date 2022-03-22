#include<iostream>
#include<stack>
using namespace std;

int main() {
    string x;
    cin >> x;
    stack<char> st;
    for(auto c:x) {
        if(st.size() && st.top() == 'S' && c == 'T') st.pop();
        else st.push(c);
    }
    cout << st.size() << endl;
}