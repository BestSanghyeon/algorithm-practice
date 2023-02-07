#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> A, B;
int cache[101][101];

int solve(int n, int m) {
    int& ret = cache[n][m];
    if(ret != -1) return ret;
    int bigger = max(A[n], B[m]);
    ret = 2;
    for(int i = n + 1; i < A.size(); i++) {
        if(A[i] > bigger)
            ret = max(ret, 1 + solve(i, m));
    }
    for(int i = m + 1; i < B.size(); i++) {
        if(B[i] > bigger)
            ret = max(ret, 1 + solve(n, i));
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n, m;
        cin >> n >> m;
        A.push_back(INT_MIN); B.push_back(INT_MIN);
        fill(&cache[0][0], &cache[100][101], -1);
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            A.push_back(tmp);
        }
        for(int i = 0; i < m; i++) {
            int tmp;
            cin >> tmp;
            B.push_back(tmp);
        }
        cout << solve(0, 0) - 2 << endl;
        A.clear(); B.clear();
    }
}
