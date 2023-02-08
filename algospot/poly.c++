#include <iostream>
#include <algorithm>
#define M 10000000

using namespace std;

int cache[101][101];

int solve(int n, int len) {
    int& ret = cache[n][len];
    if(ret != -1) return ret;
    if(n == 0) return 1;
    ret = 0;
    for(int i = 1; i <= n; i++) {
        ret = (ret + (len ? i + len - 1 : 1)*solve(n - i, i)) % M;
    } 
    return ret;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        fill(&cache[0][0], &cache[100][101], -1);
        cout << solve(n, 0) << endl;
    }
    return 0;
}
