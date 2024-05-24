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
    vector<int> a(n), used(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            int v = i;
            int kl = 0;
            while (a[v] != i) {
                used[v] = (kl % 2) + 1;
                v = a[v];
                kl++;
            }
            used[v] = (kl % 2) + 1;
            if (kl % 2 == 0) {
                cout << -1;
                return;
            }
        }
    }
    for (auto x : used) {
        cout << x << ' ';
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
