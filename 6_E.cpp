#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> p, used;
vector<vector<int>> g;

bool dfs(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		if (used[u] == 0) {
			p[u] = v;
			if (!dfs(u)) return false;
		}
		else if (used[u] == 1) {
			int w = v;
			vector<int> r;
			while (w != u) {
				r.push_back(w + 1);
				w = p[w];
			}
			r.push_back(u + 1);
			cout << "NO" << '\n';
			cout << r.size() << '\n';
			for (int i = int(r.size()) - 1; i >= 0; i--)
				cout << r[i] << ' ';
			cout << u + 1 << ' ';
			cout << '\n';
			return false;
		}
	}
	used[v] = 2;
	return true;
}

int main(){
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		g.assign(n, {});
		p.assign(n, -1);
		used.assign(n, 0);
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			g[a - 1].push_back(b - 1);
		}
		if (dfs(0))
			cout << "YES" << '\n';
	}
	
}