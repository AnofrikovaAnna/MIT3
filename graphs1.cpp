#include <iostream>
#include <map>
#include <numeric>

using namespace std;

map<int, vector<int>> g;
vector<int> used;

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


void dfs(vector<vector<int>> g, vector<int> &used, stack *&h, int v){
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
            cout << u << " ";
        }
        else pops(h);
    }
}

int main(){
    int n, m; cin >> n >> m;
    while (m--){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int dv; cin >> dv;
    stack *hs = nullptr;
    used.assign(n, 0);
    for (int it = g.begin(); it != g.end(); it++){
        int v = it->first;
        if (used[v] == 0){
            pushs(hs, v);
            used[v] = 0;
            if (v != dv)
            dfs(g, used, hs, v);
        }
    }
}