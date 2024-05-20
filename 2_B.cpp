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
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    do {
        for (auto x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
