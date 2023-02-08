#include <iostream>
#include <algorithm>
#define M 1000000007

using namespace std;

int cache[101];

int solve(int n) {
    int& ret = cache[n];
    if(ret != -1) return ret;
    if(n <= 1) return 1;
    return ret = (solve(n - 1) + solve(n - 2)) % M;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        fill(cache, cache + 101, -1);
        int ans = ((solve(n) - (n % 2 ? solve(n/2) : solve((n-2)/2) + solve(n/2))) % M);
        if(ans < 0) ans += M;
        cout << ans << endl; 
    }
    return 0;
}
