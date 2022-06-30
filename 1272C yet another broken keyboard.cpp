// problem link: https://codeforces.com/gym/302977/problem/B

// let denote characters that can still be typed on the keyboard as 1 and the broken one as 0
//  -> find all the possible substrings that can be made from these 1 characters
//
// you should try to fix something - the right end point
// 
// state: let f(i) be the number of substrings that consist of only ones that end at i
//
// let a[] be the array contains that bitmask of the string
//
// recurrence: 
// if a[i] = 0 then f(i) = 0    -- there are no substring that consist of only one that end at a 0
//
// if a[i] = 1 then automatically we have at least a substring, all the other substrings that end at a[i] have to end at the previous character
// of a[i] (we can extend them by one to include a[i])
//
// f(i) = f(i - 1) + 1
//
// -> ans = sum of all f(i)
//
// base case: f(0) = 0

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll arrsize = 1e6 + 4265;

int main(){
    ios::sync_with_stdio(false);
    std:: cin.tie(0),std::cout.tie(0);

    // get the input
    
    int n, k;           // length of the string and the number of letters still available on the keyboard
    std::cin >> n >> k;
    
    ll a[arrsize];

    string s;
    std::cin >> s;
    
    bool typeable[26] = {0};

    for (ll i = 0; i < k; i++){
        char c;
        std::cin >> c;

        typeable[c - 'a'] = 1;  //  [a -> z] -> [0 -> 25]
    }

    for (ll i = 0; i < n; i++){
        if (typeable[s[i] - 'a']){
            a[i] = 1;
        }else{
            a[i] = 0;
        }
    }

    ll f[n + 1];
    ll ans = 0;

    f[0] = 0;
    for (ll i = 0; i < n; i++){
        if (a[i] == 0){
            f[i + 1] = 0;
        }else{
            f[i + 1] = f[i] + 1;
        }

        ans += f[i + 1];
    }

    std::cout << ans << "\n";
    return 0;
}
