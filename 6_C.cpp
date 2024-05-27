#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> used;
vector<vector<int>> g;

void dfs(int v, int k) {
	for (int u : g[v]) {
		if (!used[u]) {
			used[u] = k;
			dfs(u, k);
		}
	}
}

int main(){
	int n, m; cin >> n >> m;
	g.assign(n, {});
	used.assign(n, 0);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			k++;
			used[i] = k;
			dfs(i, k);
		}
	}
	cout << k << '\n';
	for (int i = 0; i < n; i++) {
		cout << used[i] << ' ';
	}
}