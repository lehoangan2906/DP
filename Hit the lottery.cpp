// Allen has a LOT of money. He has n dollars in the bank. For security reasons, he wants to
// withdraw it in cash (we will not disclose the resons here). The denominations for dollar bills
// are 1, 5, 10, 20, 100. What is the minimum number of bills Allen could receive after 
// withdrawing his entire balance?

// idea:
// The problem is to minimiz x1 + x2 + x3 + x4 + x5 given that x1 + 5x2 + 10x3 + 20x4 + 100x5 = n.
// It is pretty simple to see that we can operate greedily: take as many 100 as we can, then 20, then 10, etc.
//
// -> loop through the set of bill that Allen has, for each type of bill, take as many as possible
//
// The solution works because each number in the sequence 1, 5, 10, 20, 100 is a divisor of the number after it

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    int a[] = {100, 20, 10, 5, 1};

    cin >> n;   // amount of money Allen has

    for (int i = 0; i < 5; i++){
        ans += n/a[i];
        n = n % a[i];
    }

    cout << ans << endl;
    return 0;
}
