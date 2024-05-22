#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <string>
#include <set>
#include <vector>

using namespace std;

const int N = 1e5 + 20;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(N), res(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        res[i] = ++b[a[i]];
    }
    for (int i = 1; i < N; i++) {
        if (b[i] > b[i - 1]) {
            cout << -1;
            return;
        }
    }
    int kl = *max_element(res.begin(), res.end());
    cout << kl << '\n';
    for (auto x : res) cout << x << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
