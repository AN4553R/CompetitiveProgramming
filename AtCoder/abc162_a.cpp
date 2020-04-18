// using no_way as a way
// using no_limitation as a limitation

// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
typedef unsigned long long ull;
#define flush fflush(stdout), cout.flush()
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define clr(v,line) memset(v,line,sizeof(v))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define RT(x) return cout<<x, 0;
//#define lcm(a,b) (a*(b/__gcd(a,b)))
#define P 1000000007
#define endl '\n'
// const int dx[] = {1,-1,0,0,1,-1,1,-1};
// const int dy[] = {0,0,1,-1,1,-1,-1,1};
// const int dxhorse[] = {-2,-2,-1,-1,1,1,2,2};
// const int dyhorse[] = {1,-1,2,-2,2,-2,1,-1};
 
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


int main(int argc, char const *argv[])
{
   
    fast();
    
    string s; cin>>s;
    cout<<(count(all(s), '7')?"Yes":"No");
}
