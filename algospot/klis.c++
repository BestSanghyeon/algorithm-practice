#include <iostream>
#include <vector>
#include <algorithm>
#define M 3000000000

using namespace std;

vector<int> sequence;
int cache[501];
vector<int> choices[501];
long long cases[501];

bool comp(const int &a, const int &b) {
    return sequence[a] < sequence[b];
}

void sortChoices() {
    for(int i = 0; i < sequence.size(); i++) {
        sort(choices[i].begin(), choices[i].end(), comp);
    }
}

void calcCases() {
    for(int i = sequence.size() - 1; i >= 0; i--) {
        if(choices[i].size() == 0) cases[i] = 1;
        else {
            long long sum = 0;
            for(int index: choices[i]) {
                sum = min(sum + cases[index], (long long)M);
            }
            cases[i] = sum;
        }
    }
}

void reconstruct(vector<int>& klis, int index, int skip) {
    for(int next: choices[index]) {
        if(cases[next] <= skip) {
            skip -= cases[next];
        }
        else {
            klis.push_back(sequence[next]);
            reconstruct(klis, next, skip);
            return;
        }
    }
}

int solve(int index) {
    int &ret = cache[index];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = index + 1; i < sequence.size(); i++) {
        if(sequence[index] < sequence[i]) {
            if(ret < 1 + solve(i)) {
                ret = 1 + solve(i);
                choices[index].clear();
                choices[index].push_back(i);
            }
            else if(ret == 1 + solve(i)) {
                choices[index].push_back(i);
            }
        }
    }
    return ret;
}

int main() {
    int c;
    cin >> c;

    while(c--) {
        sequence.clear();
        sequence.push_back(-987654321);
        fill(cache, cache + 501, -1);
        for(int i = 0; i < 501; i++)
            choices[i].clear();
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            sequence.push_back(tmp);
        }
        cout << solve(0) - 1 << endl;
        calcCases();
        sortChoices();
        vector<int> klis;
        reconstruct(klis, 0, k - 1);
        for(int i = 0; i < klis.size(); i++) {
            cout << klis[i] << ' ';
        }
        cout << endl;
    }
}
