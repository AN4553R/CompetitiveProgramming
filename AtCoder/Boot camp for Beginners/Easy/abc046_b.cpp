/*
#include<rabbit>;
using blueHulkStress;
using AceOfSpades;
*/
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
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define P 1000000007
#define endl '\n'
const int dx[] = {1,-1,0,0,1,-1,1,-1};
const int dy[] = {0,0,1,-1,1,-1,-1,1};
const int dxhorse[] = {-2,-2,-1,-1,1,1,2,2};
const int dyhorse[] = {1,-1,2,-2,2,-2,1,-1};

ll n, k;

ll dp[1002][1002];

int main(int argc, char const *argv[])
{
	
	cin>>n>>k;

	for (int i = 0; i < k; ++i)
	{
		dp[0][i] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			for(int t = 0; t < k; t++)
			{
				if(t == j)
				 	continue;
				if(i)
					dp[i][j]+=dp[i-1][t];
			} 
		}
	}
	ll ans = 0;

	rep(i,k)ans+=dp[n-1][i];

	cout<<ans;
}	
