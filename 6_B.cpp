#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> used;
vector<vector<int>> g;

void dfs(int v) {
	for (int u : g[v]) {
		if (!used[u]) {
			used[u] = 1;
			dfs(u);
		}
	}
}

int main(){
	int n, m; cin >> n >> m;
	g.assign(n, {});
	used.assign(n, 0);
	if (n - 1 != m)
		cout << "NO";
	else {
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			g[a - 1].push_back(b - 1);
			g[b - 1].push_back(a - 1);
		}
		used[0] = 1;
		dfs(0);
		if (count(used.begin(), used.end(), 1) == n)
			cout << "YES";
		else
			cout << "NO";
	}
}