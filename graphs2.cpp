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
    }
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    for (auto it = g.begin(); it != g.end(); it++){
        int v = it->first;
        sort(g[v].begin(), g[v].end());
        cout << v << ": ";
        for (int i = 0; i < g[v].size(); i++){
            cout << g[v][i] << ' ';
        }
        cout << '\n';
    }
}