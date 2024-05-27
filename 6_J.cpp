#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

vector<set<int>> g;
vector<int> d;
vector<int> used;
int n, m, id, fl;

void dfs(int v) {
	used[v] = 1;
	++id;
	for (int i = 0; i < int(g[v].size()); ++i) {
		if (id == n) break;
		if (g[v].empty() || g[v].find(d[id]) == g[v].end()) {
			for (int u : g[v]) {
				if (used[u] == 0) {
					fl = false;
				}
			}
			return;
		}
		else {
			if (used[d[id]] == 0) {
				dfs(d[id]);
			}
			else fl = false;
		}
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		d.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> d[i];
			--d[i];
		}
		g.assign(n, {});
		used.assign(n, 0);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			--a;
			--b;
			g[a].insert(b);
			g[b].insert(a);
		}
		id = 0;
		fl = true;
		dfs(d[0]);
		if (fl) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
}