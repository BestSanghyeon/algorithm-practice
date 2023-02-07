#include <iostream>
#include <vector>

using namespace std;

int clocks[16];
vector<vector<int> > button({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});

bool aligned() {
    for(int i = 0; i < 16; i++) {
        if(clocks[i] != 12)
            return false;
    }
    return true;
}

void click(int n) {
    for(int i = 0; i < button[n].size(); i++) {
        clocks[button[n][i]] = (clocks[button[n][i]] + 3) % 12;
        if(clocks[button[n][i]] == 0) clocks[button[n][i]] = 12;
    }
}

int solve(int n) {
    if(n == 10) {
        if(aligned()) return 0;
        else return -1;
    }
    int min = 987654321;
    for(int i = 0; i < 4; i++) {
        int remain = solve(n + 1);
        click(n);
        if(remain == -1) continue;
        if(min > remain + i) min = remain + i;
    }
    if(min == 987654321) return -1;
    return min;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        for(int i = 0; i < 16; i++) {
            cin >> clocks[i];
        }
        cout << solve(0) << endl;
    }
}
