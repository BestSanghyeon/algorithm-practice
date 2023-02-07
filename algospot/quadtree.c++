#include <iostream>

using namespace std;

string solve(string::iterator& iter) {
    if(*iter != 'x') return string(1, *iter);
    string piece[4];
    for(int i = 0; i < 4; i++) {
        piece[i] = solve(++iter);
    }
    return "x" + piece[2] + piece[3] + piece[0] + piece[1];
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        string str;
        cin >> str;
        auto iter = str.begin();
        cout << solve(iter) << endl;
    }
}
