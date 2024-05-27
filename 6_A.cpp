#include <iostream>
#include <vector>

using namespace std;

vector<int> p;
vector<vector<int>> g;

void dfs(int v) {
	for (int u : g[v]) {
		if (p[u] == -1) {
			p[u] = v;
			dfs(u);
		}
	}
}

int main(){
	int n, v1, v2; cin >> n >> v1 >> v2;
	int x;
	v1--;
	v2--;
	g.assign(n, {});
	p.assign(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x == 1) {
				g[i].push_back(j);
			}
		}
	}
	p[v1] = 0;
	dfs(v1);
	if (p[v2] == -1)
		cout << -1;
	else {
	    vector<int> r;
		while (v2 != v1) {
			r.push_back(v2 + 1);
			v2 = p[v2];
		}
		r.push_back(v1 + 1);
		int k = r.size();
		cout << k - 1 << '\n';
		for (int i = k - 1; i >= 0; i--)
			cout << r[i] << ' ';
	}
}