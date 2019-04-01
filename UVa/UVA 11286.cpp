/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WaRNINGS*/
#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
typedef unsigned long long ull;
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
#define P 1000000007
#define endl '\n'

const ll dx[] = {1,-1,0,0,1,-1,1,-1};
const ll dy[] = {0,0,1,-1,1,-1,-1,1};

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
	file();
	
	int n;
	while(cin>>n && n){
		map<vi,int>m;
		for (int i = 0; i < n; ++i)
		{
			vi v(5);
			for (int j = 0; j < 5; ++j)
			{
				cin>>v[j];
			}
			sort(all(v));
			m[v]++;
		}
		int mx=0,ans=0;
		for(auto i:m)mx=max(mx,i.second);
		for(auto i:m)ans+=i.second==mx;
		cout<<ans*mx<<endl;
	}
}
