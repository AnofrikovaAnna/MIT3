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
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            int v = i;
            while (a[v] != i) {
                used[v] = 1;
                v = a[v];
            }
            used[v] = 1;
            kl++;
        }
    }
    cout << kl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
