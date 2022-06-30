// o My, co cac loai dong xu (penny: 1c, nickel: 5c, dime: 10c, quarter: 25c, half-dollar: 50c). Dem so cach
// ket hop cac loai dong xu sao cho tong bang mot luong tien de bai cho

#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;

int main(){
    vector<long long> dp(Max);
    int coin[] = {1, 5, 10, 25, 50};

    dp[0] = 1;
    for (int i = 0; i < 5; i++){
        for (int j = coin[i]; j <= MAX; j++){
            dp[j] += dp[j - coin[i]];
        }
    }

    int n;
    while(cin >> n){
        assert(0 <= n && n < max);
        if (dp[n] != 1)
            cout << "There are " << dp[n] << "ways to produce " << n << " cents change.\n";
        else
            cout << "There is only 1 way to produce " << n << " cents change.\n";
    }
}
