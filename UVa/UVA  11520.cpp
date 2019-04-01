#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WaRNINGS
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

char v[11][11];

int main(int argc, char const *argv[])
{
	file();
	
	int t;cin>>t;

	for(int C = 1; C<=t;C++)
	{
		cout<<"Case "<<C<<":\n";
		int n;cin>>n;
		rep(i,n)rep(j,n)cin>>v[i][j];

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(v[i][j]!='.')
					cout<<v[i][j];
				else
				{
					std::vector<char> a;

					if(i+1<n && isalpha(v[i+1][j]))	a.push_back(v[i+1][j]);

					if(i-1>=0&& isalpha(v[i-1][j]))	a.push_back(v[i-1][j]);
					
					if(j+1<n&& isalpha(v[i][j+1]))	a.push_back(v[i][j+1]);

					if(j-1>=0&& isalpha(v[i][j-1]))	a.push_back(v[i][j-1]);
					
					if(a.empty())
					{
						v[i][j]='A', cout<<v[i][j];
					}

					else
					{
						for(char k='A';k<='Z';k++)
						{
							if(!count(all(a),k))
							{
								v[i][j]=k, cout<<k;
								break;
							}
						}
					}

					
				}
			}
			cout<<endl;
		}
	}
}
