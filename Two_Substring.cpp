// problem link: https://codeforces.com/problemset/problem/550/A

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for (int i = s; i < e; i++)

typedef long double ld;

const int maxN = 100*1000 + 5;
const int mod = 1000*1000*1000+7;
const int maxM = 400000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; 
    cin >> s;
    
    if (s.find("BA") == string::npos || s.find("AB") == string::npos){
        cout << "NO" << "\n";
        return 0;
    }

    int pos = s.find("BA");

    if (s.find("AB" ,pos + 2) != string::npos){
        cout << "YES" << "\n";
        return 0;
    }

    pos = s.find("AB");

    if (s.find("BA", pos + 2) != string::npos){
        cout << "YES" << "\n";
        return 0;
    }

    cout << "NO" << "\n";
    return 0;
}
