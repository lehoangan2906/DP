// Problem link: https://codeforces.com/problemset/problem/1182/A
// You have a given integer n. Find the number of ways to fill all 3 x n tiles with the shape
// described in the picture. Upon filling, no empty spaces are allowed. Shapes cannot overlap.


#include <bits/stdc++.h>
using namespace std;

// let the state be the state of the columns
// -> base case: f(0) = 1 : there are one way to fill 0 column - fill nothing
// -> base case 2: f(1) = 0 : there are no way to fill only 1 column
// transition: after every move, there are 2 solumns less to consider, and there are 2 possible
// cases to consider - > f(n) = f(n - 2) + f(n - 2)

#define ll long long
ll n;

void solve(int tc = 0){
    cin >> n;

    ll f[n + 1];

    f[0] = 1;
    f[1] = 0;
    for (ll i = 2; i <= n; i++){
        f[i] = 2 * f[i - 2];
    }

    cout << f[n] << "\n";
}

int main(){
    // fast io
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    for (int t = 0; t < tc; t++) solve(t);
    return 0;
}
