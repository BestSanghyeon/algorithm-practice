#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double first[500];
double nextTo[500][500];
double recog[500][500];
int wordCnt;
string words[500];
double cache[101][501];
int choice[101][501];

double getNextTo(int a, int b) {
    if(a == -1) return first[b];
    else return nextTo[a][b];
}

double solve(vector<int> &sentence, int index, int prev) {
    if(index == sentence.size()) return 1;
    double &ret = cache[index][prev + 1];
    if(ret > -0.5) return ret;
    for(int i = 0; i < wordCnt; i++) {
        double tmp = recog[i][sentence[index]]*getNextTo(prev, i)*solve(sentence, index + 1, i);
        if(ret < tmp) {
            ret = tmp;
            choice[index][prev + 1] = i;
        }
    }
    return ret;
}

void reconstruct(vector<int> &original, int index, int prev, int n) {
    if(index == n) return;
    original.push_back(choice[index][prev + 1]);
    reconstruct(original, index + 1, choice[index][prev + 1], n);
}

int main() {
    int sentenceCnt;
    cin >> wordCnt >> sentenceCnt;
    for(int i = 0; i < wordCnt; i++) {
        cin >> words[i];
    }
    for(int i = 0; i < wordCnt; i++) {
        cin >> first[i];
    }
    for(int i = 0; i < wordCnt; i++) {
        for(int j = 0; j < wordCnt; j++) {
            cin >> nextTo[i][j];
        }   
    }
    for(int i = 0; i < wordCnt; i++) {
        for(int j = 0; j < wordCnt; j++) {
            cin >> recog[i][j];
        }   
    }
    while(sentenceCnt--) {
        fill(&cache[0][0], &cache[100][501], -1);
        int sentenceLen;
        cin >> sentenceLen;
        vector<int> sentence;
        for(int i = 0; i < sentenceLen; i++) {
            string word;
            cin >> word;
            int index = 0;
            for(int i = 0; i < wordCnt; i++) {
                if(words[i] == word) {
                    index = i;
                    break;
                }
            }
            sentence.push_back(index);
        }
        solve(sentence, 0, -1);
        vector<int> original;
        reconstruct(original, 0, -1, sentence.size());
        for(int word: original) {
            cout << words[word] << " ";
        }
        cout << endl;
    }
}
