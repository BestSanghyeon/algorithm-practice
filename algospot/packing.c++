#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    int volume;
    int weight;
};

vector<Item> items;
int n, w;
int cache[101][1001];
bool choice[101][1001];

int solve(int index, int leftV) {
    if(index == n) return 0;
    int& ret = cache[index][leftV];
    if(ret != -1) return ret;
    ret = solve(index + 1, leftV);
    if(leftV >= items[index].volume) {
        int whenChose = items[index].weight + solve(index + 1, leftV - items[index].volume);
        if(whenChose > ret) {
            ret = whenChose;
            choice[index][leftV] = true;
        }
    }
    return ret;
}

void reconstruct(int index, int leftV, vector<string>& itemList) {
    if(index == n) return;
    if(choice[index][leftV]) {
        itemList.push_back(items[index].name);
        reconstruct(index + 1, leftV - items[index].volume, itemList);
    } else {
        reconstruct(index + 1, leftV, itemList);
    }
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        items.clear();
        fill(&cache[0][0], &cache[100][1001], -1);
        fill(&choice[0][0], &choice[100][1001], false);
        cin >> n >> w;
        for(int i = 0; i < n; i++) {
            string name;
            int volume, weight;
            cin >> name >> volume >> weight;
            Item item = { name, volume, weight };
            items.push_back(item);
        }
        int maxWeight = solve(0, w);
        vector<string> itemList;
        reconstruct(0, w, itemList);
        cout << maxWeight << " " << itemList.size() << endl;
        for(string name: itemList) {
            cout << name << endl;
        }
    }
}
