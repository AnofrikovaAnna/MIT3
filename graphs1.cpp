#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<vector<int>> g;
vector<int> used;
int dv;

struct stack{
    int inf;
    stack *next;
};

void pushs(stack *&h, int x){
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pops(stack *&h){
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}


void dfs(stack *&h, int v){
    while (h){
        bool fl = false;
        int v = h->inf;
        int u;
        for (int i = 0; i < g[v].size(); ++i){
            if (used[g[v][i]] == 0){
                u = g[v][i];
                fl = true;
                break;
            }
        }
        if (fl){
            used[u] = 1;
            pushs(h, u);
            int f = 0;
            for (int j = 0; j < g[dv].size(); j++){
                if (g[dv][j] == u || u == dv){
                    f = 1;
                }
            }
            if (!f) cout << u << ' ';
        }
        else pops(h);
    }
}

int main(){
    int n, m; cin >> n >> m;
    g.assign(n, {});
    while (m--){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> dv;
    stack *hs = nullptr;
    used.assign(n, 0);
    for (int i = 0; i < n; i++){
        if (used[i] == 0){
            int f = 0;
            for (int j = 0; j < g[dv].size(); j++){
                if (g[dv][j] == i || i == dv){
                    f = 1;
                }
            }
            if (!f) cout << i << ' ';
            used[i] = 1;
            pushs(hs, 0);
            dfs(hs, i);
        }
    }
}