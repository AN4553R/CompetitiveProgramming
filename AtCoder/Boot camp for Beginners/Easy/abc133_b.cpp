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

int n, k;

vi v[20];

double cacl(int r, int c)
{
	ll sum = 0;
	for(int i=0; i<k;i++)
		sum+=(v[r][i] - v[c][i]) * (v[r][i] - v[c][i]);
	return sqrt(sum);
}
int main(int argc, char const *argv[])
{
	
	
	cin>>n>>k;

	for (int i = 0; i < n; ++i)
	{
		v[i].resize(k);
		rep(j,k)cin>>v[i][j];
	}
	ll ans = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		for(int j = i+1; j<n; j++)
		{
			double ret = cacl(i,j);
			ans+=ret == int(ret);
		}
	}
	cout<<ans;
}	
