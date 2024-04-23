#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


int main(){
    int n, m; cin >> n >> m;
    map<int, vector<int>> g;
    while (m--){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (auto it = g.begin(); it != g.end(); it++){
        int v = it->first;
        cout << v << ": " << g[v].size() << '\n';
    }
}