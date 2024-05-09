#include <iostream>
#include <sstream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <iomanip>

using namespace std;

typedef long long li;

int n;
vector<vector<int>> g;
vector<int> pr;
vector<int> d;


void dfs(int v, int p = -1) {
    pr[v] = p;
    if (p == -1) d[v] = 0;
    else d[v] = d[p] + 1;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
}

void solve() {
    cin >> n;
    g.assign(n, {});
    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    pr.assign(n, -1);
    d.assign(n, 0);
    dfs(0);
    int id = max_element(d.begin(), d.end()) - d.begin();
    pr.assign(n, -1);
    dfs(id);
    int id2 = max_element(d.begin(), d.end()) - d.begin();
    int ln = d[id2], i = 0;
    if (ln % 2 == 0){
        cout << 1 << '\n';
        if (id2 == id)
            cout << id2 + 1 << '\n';
        while (id2 != id) {
            if (ln / 2 == i++){
                cout << id2 + 1 << '\n';
                break;
            }
            id2 = pr[id2];
        }
    }
    else{
        vector<int> c;
        cout << 2 << '\n';
        while (id2 != id) {
            if (ln / 2 == i || (ln + 1) / 2 == i){
                c.push_back(id2 + 1);
            }
            i++;
            id2 = pr[id2];
        }
        if (id2 == id && (ln / 2 == i || (ln + 1) / 2 == i))
            c.push_back(id2 + 1);
        sort(c.begin(), c.end());
        cout << c[0] << ' ' << c[1] << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}