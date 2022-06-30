// If the sum of all the weights is not divisible by two, then it is impossible to divide the candies between two people. If the sum is
// divisible, then let's count the number of candies with a weight of 1 and 2. Now, if we can find a way to collect half the sum with 
// some candies, then these candies can be given to Alice, and all the rest can be given to Bob.
//
// Simple solution — let's iterate through how many candies of weight 2 we will give to Alice, then the remaining weight should be filled
// by candies of weight 1. If there are enough of them, then we have found a way of division.
//
// In fact, if the sum is even and there are at least two candies with weight 1 (there can't be one candy), then the answer is always "YES"
// (we can collect the weight as close to half as possible with weight 2 and then add weight 1). If there are no candies with weight 1, then 
// you need to check whether 𝑛 is even (since all the candies have the same weight, you just need to divide them in half).


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;          // number of candies they received
    cin >> n;

    int cnt1 = 0, cnt2 = 0;     // variables to count number of weight 1 and weight 2

    for (int i = 0; i < n; i++){
        int c;      // input the candy
        cin >> c;

        if (c == 1){
            cnt1++;     // count weight 1 candy
        }else{
            cnt2++;     // count weight 2 candy
        }
    }

    if ((cnt1 + 2 * cnt2) % 2 != 0){
        cout << "NO\n";
    }else{
        int sum = (cnt1 + 2 * cnt2) / 2;

        if (sum % 2 == 0 || (sum % 2 == 1 && cnt1 != 0)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}

int main(){
    int t;      // number of testcases
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}
