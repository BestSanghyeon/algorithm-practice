#include <iostream>
#include <algorithm>

using namespace std;

bool connected[51][51];
double cache[101][51];
int connectedNum[51];

void preCalculate(int n) {
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(connected[i][j]) cnt++;
        }
        connectedNum[i] = cnt;
    }
}

double solve(int n, int prison, int pos, int day) {
    if(day == 0) return pos == prison ? 1 : 0;
    double& ret = cache[day][pos];
    if(ret > -0.5) return ret;
    ret = 0;
    for(int i = 0; i < n; i++) {
        if(connected[pos][i]) {
            ret += solve(n, prison, i, day - 1) / connectedNum[i];
        }
    }
    return ret;
}

int main() {
    cout.precision(8);
    int c;
    cin >> c;
    while(c--) {
        fill(&cache[0][0], &cache[100][51], -1);
        int n, d, p;
        cin >> n >> d >> p;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int tmp;
                cin >> tmp;
                connected[i][j] = tmp;
            }
        }
        preCalculate(n);
        int t;
        cin >> t;
        while(t--) {
            int q;
            cin >> q;
            cout << solve(n, p, q, d) << ' ';
        }
        cout << endl;
    }
    return 0;
}
