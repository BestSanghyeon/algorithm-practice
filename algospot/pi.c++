#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<int> number;
int cache[10001];

int difficulty(int from, int to) {
    int first = number[from];
    int diff = number[from + 1] - first;
    bool same = true, consecutive = diff == 1 || diff == -1, alternative = true, series = true;
    bool alterFlag = false;
    for(int i = from + 1; i <= to; i++) {
        if(number[i] != first) same = false;
        if(number[i] - number[i - 1] != diff) series = consecutive = false;
        if(number[i] - number[i - 1] != diff * (alterFlag ? -1 : 1)) alternative = false;
        alterFlag = !alterFlag;
    }
    if(same) return 1;
    if(consecutive) return 2;
    if(alternative) return 4;
    if(series) return 5;
    return 10;
}

int solve(int from) {
    if(number.size() - from <= 2) return INF;
    if(number.size() - from <= 5) return difficulty(from, number.size() - 1);
    int& ret = cache[from];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 3; i <= 5; i++) {
        ret = min(ret, difficulty(from, from + i - 1) + solve(from + i));
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        string numberStr;
        cin >> numberStr;
        for(char numberChar : numberStr) {
            number.push_back(numberChar - '0');
        }
        fill(&cache[0], &cache[10001], -1);
        cout << solve(0) << endl;
        number.clear();
    }
}
