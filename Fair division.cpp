// Alice and Bob received n candies from their parents. Each candy weights either 1 gram or 2 grams. Now they want ot divide all
// candies among themselves fairly so that the total weight of Alice's candies is equal to the total weight of Bob's candies.
//
// Check if they can do that.
//
// Note that candies are not allowed to be cut in half.
//
// Link: https://codeforces.com/problemset/problem/1472/B
//
// Idea:


#include <bits/stdc++.h>
using namespace std;

int main(){
    //fast io
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;      // number of testcases
    cin >> t;

    while (t--){
        int n;  // the number of candies that Alice and Bob received
        cin >> n;

        vector<int> arr(n);    // weights of the candies
        for (auto &e : arr){
            cin >> e;
        }

        // dp[i] is the absolute difference between alice and bob considering the first i candies.
        vector<int> dp(n + 1);
        dp[0] = arr[0];
        int count_ones = arr[0] == 1 ? 1 : 0;

        for (int i = 1; i < n; i++){
            if (arr[i] == 1){
                count_ones += 1;
            }

            dp[i] = abs(dp[i - 1] - arr[i]);

            if (dp[i] == 2 && count_ones >= 2){
                dp[i] = 0;
            }
        }

        cout << "\n";

        if (dp[n - 1] == 0){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
}

