#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fence;  

int solve(int l, int r) {
    if(l == r) return fence[l];
    int m = (l + r) / 2;
    int maxArea = max(solve(l, m), solve(m + 1, r));
    int l_ = m, r_ = m + 1;
    int minHeight = min(fence[l_], fence[r_]);
    maxArea = max(maxArea, (r_ - l_ + 1)*minHeight);
    while(l_ != l || r_ != r) {
        if(l_ == l || (r_ != r && fence[l_ - 1] < fence[r_ + 1])) {
            r_++;
            minHeight = min(minHeight, fence[r_]);
        }
        else {
            l_--;
            minHeight = min(minHeight, fence[l_]);
        }
        maxArea = max(maxArea, (r_ - l_ + 1)*minHeight);
    }
    return maxArea;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int h;
            cin >> h;
            fence.push_back(h);
        }
        cout << solve(0, n - 1) << endl;
        fence.clear();
    }
}
