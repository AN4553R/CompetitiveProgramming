#define _CRT_SECURE_NO_WaRNINGS
#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
#define flush fflush(stdout), cout.flush()
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define clr(v,idx) memset(v,idx,sizeof(v))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define endl '\n'
//const ll dx[] = {1,-1,0,0,1,-1,1,-1};
//const ll dy[] = {0,0,1,-1,1,-1,-1,1};
void courage() {
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
 
const int OO=1e5+5;
int n;
vi v[OO];

int dp[OO][2];

int solve(int node,int p,int token){
	 
	 int &ret=dp[node][token];
	 if(ret!=-1)
	 	return ret;
	 ret=token;
	 for(auto i:v[node]){
	 	if(i==p)
	 		continue;
	 	if(token)
	 	{
	 		ret+=min(solve(i,node,1),solve(i,node,0));
	 	}
	 	else
	    	{
	    		ret+=solve(i,node,1);
	 	}
	 }
	 return ret;
}
int main(int argc, char const *argv[])
{
	courage();
	clr(dp,-1);
 	cin>>n;
 	for (int i = 0,l,r; i < n-1; ++i)
 	{
 		cin>>l>>r;
 		v[l].push_back(r);
 		v[r].push_back(l);
 	}
 	int ans=min(solve(1,-1,0),solve(1,-1,1));
 	cout<<ans;
}
