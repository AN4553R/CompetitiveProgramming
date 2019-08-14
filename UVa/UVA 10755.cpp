/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS*/
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
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 <<endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
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

const int N = 22;

ll dp[N][N][N],TC, x, y, z, ans;

int main(int argc, char const *argv[])
{
	file();

	cin>>TC;
	rep(I,TC)
	{
		ans = LLONG_MIN;

		cin>>x>>y>>z;

		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				for (int k = 0; k < z; ++k)
				{
					ll x; cin>>x;

					// IE principle
					if(i)x+=dp[i - 1][j][k];
					if(j)x+=dp[i][j - 1][k];
					if(k)x+=dp[i][j][k - 1];

					if(i && j)x-=dp[i - 1][j - 1][k];
					if(j && k)x-=dp[i][j - 1][k - 1];
					if(k && i)x-=dp[i - 1][j][k - 1];

					if(i && j && k)x+=dp[i-1][j-1][k-1];
					
					dp[i][j][k] = x;
				}
			}
		}

		for (int i = 0; i < x; ++i) // start x
		{
			for (int j = 0; j < y; ++j) // start y
			{
				for (int k = 0; k < z; ++k) // start z
				{
					for (int _i = i; _i < x; ++_i) // end x
					{
						for (int _j = j; _j < y; ++_j) // end y
						{
							for (int _k = k; _k < z; ++_k) // end z
							{
								ll cur = dp[_i][_j][_k];

								if(i)cur-=dp[i - 1][_j][_k];
								if(j)cur-=dp[_i][j - 1][_k];
								if(k)cur-=dp[_i][_j][k - 1];

								if(i && j)cur+=dp[i - 1][j - 1][_k];
								if(j && k)cur+=dp[_i][j - 1][k - 1];
								if(k && i)cur+=dp[i - 1][_j][k - 1];

								if(i && j && k) cur-=dp[i - 1][j - 1][k - 1];

								if(cur > ans)ans = cur;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		if(I < TC - 1)cout<<endl;
	}
	
}
