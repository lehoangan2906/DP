// there is a nxm grid. You are standing at cell (1, 1) and your goal is to finish at cell (n, m)
//
// You can move to the neighboring cells to the right or down. In othe words, suppose you are standing at cell (x, y). You can:
//  - Move right to the cell (x, y + 1) - it costs x burles.
//  - Move down to the cewll (x + 1, y) - it costs y burles.
//
// Can you reach cell (n, m) spending exactly k burles?


// idea: note that whichever path you choose, the total cost will be the same (prove below). If you know that the cost is the same,
// then it's not hard to calculate it. It's equal to n * m - 1. So the task is to check: is k equal to n * m - 1 or not.
//
// The constant cost may be proved by induction on n + m: For n = m = 1, cost is  1 * 1 - 1 = 0.
// For a fixed (n, m), there are only two last steps you can make:
//  - Either from (n, m - 1) with cost n: The total cost is n * (m - 1) - 1 + n = n * m - 1
//  - Or from (n - 1, m) with cost m: the total cost is (n - 1) * m - 1 + m = n * m - 1
//
//  So, whichever path you choose, the toal cost is the same

#include <bits/stdc++.h>
using namespace std;


int main(){
    
}
