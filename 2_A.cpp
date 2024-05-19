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
    set<int> a;
    int mi = 1001, ma = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
        mi = min(mi, x);
        ma = max(ma, x);
    }
    if (int(a.size()) == n && mi == 1 && ma == n)
        cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
