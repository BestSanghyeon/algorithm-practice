#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int cache[101][101];

bool match(string wildcard, string str, int w, int s) {
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    int wSize = wildcard.length(), sSize = str.length();
    if(w == wSize && s == sSize) {
        ret = 1;
    }
    else if(wildcard[w] == '*') {
        ret = match(wildcard, str, w + 1, s) || match(wildcard, str, w, s + 1);
    }
    else if(w == wSize && s != sSize || w != wSize && s == sSize) {
        ret = 0;
    }
    else if(wildcard[w] == '?' || wildcard[w] == str[s]) {
        ret = match(wildcard, str, w + 1, s + 1);
    }
    else ret = 0;
    return ret;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        string wildcard;
        cin >> wildcard;
        int n;
        cin >> n;
        vector<string> matches;
        for(int i = 0; i < n; i++) {
            string str;
            cin >> str;
            fill(&cache[0][0], &cache[100][101], -1);
            if(match(wildcard, str, 0, 0)) {
                matches.push_back(str);
            }
        }
        sort(matches.begin(), matches.end());
        for(auto str: matches) {
            cout << str << endl;
        }
    }
    return 0;
}
