#include <iostream>

using namespace std;

bool isFriend[10][10];
bool isPaired[10];
int n;

void reset() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            isFriend[i][j] = false;
        }    
        isPaired[i] = false;
    }
}

int solve(bool* isPaired) {
    int first = -1;
    for(int i = 0; i < n; i++) {
        if(!isPaired[i]) {
            first = i;
            break;
        }
    }
    if(first == -1) return 1;
    int cnt = 0;
    isPaired[first] = true;
    for(int i = first + 1; i < n; i++) {
        if(!isPaired[i] && isFriend[first][i]) {
            isPaired[i] = true;
            cnt += solve(isPaired);
            isPaired[i] = false;
        }
    }
    isPaired[first] = false;
    return cnt;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        reset();
        int m;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            isFriend[a][b] = isFriend[b][a] = true;
        }
        cout << solve(isPaired) << endl;
    }
}
