#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
}
const int P = (int) 1e9 + 7;
const int MAX = 2e5 + 5;

ll n, k, dp[MAX];

ll fastPower(ll x, ll y)  
{  
    ll res = 1;
  
    x = x % P;  
   
    if (x == 0) return 0;
  
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % P;  
        y = y>>1;
        x = (x*x) % P;  
    }  
    return res;  
}

int main(int argc, char const *argv[])
{
    file();
    // https://codeforces.com/blog/entry/75894?#comment-601667

    memset(dp, 0, sizeof(dp));

    cin>>n>>k;

    for (int gcd = k; gcd >= 1; --gcd)
    {
        int multipliesOfCurrentGCD = k / gcd;
        int numberOfSequences = fastPower(multipliesOfCurrentGCD, n);
        int overCounting = 0;

        for (int i = 2 * gcd; i <= k; i+=gcd)
        {
            overCounting = (overCounting + dp[i]) % P;
        }
        dp[gcd] = (numberOfSequences - overCounting + P) % P;
    }
    
    for (int i = 1; i <= k; ++i)
    {
        dp[0] = (((dp[i] % P * i % P) % P) % P + dp[0] % P)%P;
        dp[0]%=P;
    }
    cout<<dp[0];

}