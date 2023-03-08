#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000100000

using namespace std;

int len[51];

void preCalc() {
    len[0] = 1;
    int add = 3;
    for(int i = 1; i <= 50; i++) {
        len[i] = min(len[i - 1] + add, MAX);
        add = min(add*2, MAX);
    }
}

char dragon(int gen, int skip, string init) {
    if(gen == 0)
        return init[skip];
        
    for(int i = 0; i < init.length(); i++) {
        if(init[i] == 'X') {
            if(len[gen] <= skip)
                skip -= len[gen];
            else
                return dragon(gen - 1, skip, "X+YF");
        }
        else if(init[i] == 'Y') {
            if(len[gen] <= skip)
                skip -= len[gen];
            else
                return dragon(gen - 1, skip, "FX-Y");
        }
        else if(skip == 0)
            return init[i];
        else
            skip--;
    }
}

int main() {
    int c;
    cin >> c;
    preCalc();
    while(c--) {
        int n, p, l;
        cin >> n >> p >> l; 
        for(int i = p; i < p + l; i++)
            cout << dragon(n, i - 1, "FX");
        cout << endl;
    }
    return 0;
}
