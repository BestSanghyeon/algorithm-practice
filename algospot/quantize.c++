#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> number;
int cache[101][11];

int getMean(int from, int to) {
    int sum = 0;
    for(int i = from; i <= to; i++) {
        sum += number[i];
    }
    return float(sum)/(to - from + 1) + 0.5;
}

int minError(int from, int to) {
    int error = 0;
    int mean = getMean(from, to);
    for(int i = from; i <= to; i++) {
        error += (number[i] - mean)*(number[i] - mean);
    }
    return error;
}

int solve(int from, int s) {
    if(from == number.size()) return 0;
    if(s == 1) return minError(from, number.size() - 1);
    int& ret = cache[from][s];
    if(ret != -1) return ret;
    ret = 987654321;
    for(int i = from; i < number.size(); i++) {
        ret = min(ret, minError(from, i) + solve(i + 1, s - 1));
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n, s;
        cin >> n >> s;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            number.push_back(tmp);
        }
        sort(number.begin(), number.end());
        fill(&cache[0][0], &cache[100][11], -1);
        cout << solve(0, s) << endl;
        number.clear();
    }
}
