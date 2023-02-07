#include <iostream>

using namespace std;

int h, w;

int block[4][3][2] = {
    {
        { 0, 0 },
        { 0, 1 },
        { 1, 1 }
    },
    {
        { 0, 0 },
        { 1, 0 },
        { 1, -1 }
    },
    {
        { 0, 0 },
        { 1, 0 },
        { 1, 1 }
    },
    {
        { 0, 0 },
        { 0, 1 },
        { 1, 0 }
    }
};

bool inRange(int y, int x) {
    if(y < 0 || y >= h) return false;
    if(x < 0 || x >= w) return false;
    return true;
}

bool canFill(bool board[][20], int y, int x, int n) {
    for(int i = 0; i < 3; i++) {
        int currentY = y + block[n][i][0];
        int currentX = x + block[n][i][1];
        if(!inRange(currentY, currentX) || board[currentY][currentX])
            return false;
    }
    return true;
}

bool fill(bool board[][20], int y, int x, int n, bool to) {
    for(int i = 0; i < 3; i++) {
        int currentY = y + block[n][i][0];
        int currentX = x + block[n][i][1];
        board[currentY][currentX] = to;
    }
}

int solve(bool board[][20]) {
    int y = -1, x = -1;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(!board[i][j]) {
                y = i;
                x = j;
                goto breakPoint;
            }
        }
    }
breakPoint:
    if(y == -1) return 1;
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(canFill(board, y, x, i)) {
            fill(board, y, x, i, true);
            cnt += solve(board);
            fill(board, y, x, i, false);
        }
    }
    return cnt;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        bool board[20][20];
        cin >> h >> w;
        for(int i = 0; i < h; i++) {
            string row;
            cin >> row;
            for(int j = 0; j < w; j++) {
                if(row[j] == '#') board[i][j] = true;
                else board[i][j] = false;
            }
        }
        cout << solve(board) << endl;
    }
}
