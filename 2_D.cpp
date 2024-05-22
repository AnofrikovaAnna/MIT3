#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <string>
#include <set>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), used(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    int kl = 0;
    vector<vector<int>> r;
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            int v = i;
            r.push_back({});
            while (a[v] != i) {
                r.back().push_back(v);
                used[v] = 1;
                v = a[v];
            }
            used[v] = 1;
            r.back().push_back(v);
            kl++;
        }
    }
    cout << kl << '\n';
    for (int i = 0; i < kl; i++) {
        for (int j = 0; j < int(r[i].size()); j++) {
            cout << r[i][j] + 1;
            if (j != int(r[i].size()) - 1) {
                cout << " -> ";
            }
        }
        cout << '\n';
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
