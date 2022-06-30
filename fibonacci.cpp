#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll cache[1000];

// memoization

ll fib(ll n){
    if (n < 2)
        return n;

    if (cache[n] != 0)
        return cache[n];

    cache[n] = fib(n - 1) + fib(n - 2);

    return cache[n];
}

int main(){
    // fast io
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll n;
    cin >> n;

    cout << "The " << n << "th fibonacci number is: " << fib(n);

    return 0;
}
