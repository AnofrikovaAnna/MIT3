#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> p;
vector<vector<int>> g;


struct queue{
    int inf;
    queue *next;
};

void pushq(queue *&h, queue *&t, int x){
    queue *r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t){
        h = r;
        t = r;
    }
    else{
        t->next = r;
        t = r;
    }
}

int popq(queue *&h, queue *&t){
    queue *r = h;
    int i = h->inf;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

void bfs(queue *&h, queue *&t, int v, int a){
    while (h){
        int v = popq(h, t);
        int u;
        for (int i = 0; i < g[v].size(); ++i){
            if (p[g[v][i]] == -1){
                u = g[v][i];
                p[u] = v;
                pushq(h, t, u);
            }
        }
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
    int a, b; cin >> a >> b;
    queue *hq = nullptr;
    queue *tq = nullptr;
    p.assign(n, -1);
    p[a] = 0;
    pushq(hq, tq, a);
    bfs(hq, tq, a, a);
    if (p[b] != -1){
        vector<int> ans;
        int w = b;
        while(w != a){
            ans.push_back(w);
            w = p[w];
        }
        ans.push_back(a);
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << ' ';
    }
    else 
        cout << "THERE IS NO WAY";
    cout << "\n";
}