#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
#define flush fflush(stdout), cout.flush()
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define rep(i,n) for(int(i)=0;(i)<(int)n;(i)++)
#define repl(i,n) for(ll(i)=0;(i)<(ll)n;(i)++)
#define clr(v,idx) memset(v,idx,sizeof(v));
#define vi vector<int>
#define vll vector<ll>
#define max3(a,b,c) max(a,max(b,c));
#define min3(a,b,c) min(a,min(b,c));

#define endl '\n'

//const int dx[] = {1,-1,0,0,1,-1,1,-1};
//const int dy[] = {0,0,1,-1,1,-1,-1,1};
//const int dxhorse[] = {-2,-2,-1,-1,1,1,2,2};
//const int dyhorse[] = {1,-1,2,-2,2,-2,1,-1};
void SneakPeek() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}


int main()
{
	SneakPeek(); fast();

}
