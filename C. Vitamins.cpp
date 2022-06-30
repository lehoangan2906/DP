// Problem link: https://codeforces.com/gym/302977/problem/C
// Berland shop sells n kinds of juices. Each juice includes some set of vitamins in it.
// There are three types of vitamins: A, B, C. Each juice can contain one, two or all three of them
// 
// What is the minimum total price of juices that Petya has to buy to contain all three vitamin?
//
//
// Idea:
//  we have some function f(x) where x is the state that we are trying to find the answer for 
//  In a state, we need to know: do we have the A vitamin? the B or the C?  -> store by the binary values (1 if we have it, 0 if we don't)
//  
//  How to store them in f? -> bitmasking
//
//  f(mask) represent the lowest cost to satisfy the mask
//
//
//

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;      // the number of juices
    cin >> n;
    
    ll f[n + 1][8];
    const ll inf = 1e17;

    for (ll i = 0; i <= n; i++){
        for (ll j = 0; j < 8; j++){
            f[i][j] = inf; 
        }
    }

//    ll ans = inf;

    for (ll i = 0; i < n; i++){
        ll cost;
        string s;
        cin >> cost >> s;

        int string_mask = 0;
        for (int pos = 0; pos < 2; pos++){
            char c = 'C' - pos;
            bool have = 0;
            for (char d: s){
                if (c == d){
                    have = 1;
                }
            }

            if (have){
                string_mask += (1 << pos);      // 2^pos
            }
        }

        for (ll mask = 0; mask < 8; mask++){
            f[i + 1][mask] = min(f[i + 1][mask], f[i][mask]);
            f[i + 1][mask | string_mask] = min(f[i + 1][mask | string_mask] + cost);
      }
    }

    ll ans = f[n][7];
    if (ans == inf) ans = -1;
    cout << ans << "\n";

    return 0;
}
