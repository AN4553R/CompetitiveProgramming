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

const int OO=1e6+5;

ll arr[OO];
int F[OO];

int main(int argc, char const *argv[])
{
	file();

	int t;cin>>t;

	for(int I=1;I<=t;I++)
	{
		clr(F,0);

		cout<<"Case "<<I<<": ";
		int n,m,k;cin>>n>>m>>k;

		arr[0]=1,arr[1]=2,arr[2]=3;

		for (int i = 3; i < n; ++i)
		{
			arr[i]=(arr[i-1]+arr[i-2]+arr[i-3]) % m + 1;
		}
		
		int ans=n+5,cnt=0;

		for(int l=0,r=-1;l<n && r<n && (l<=r || r==-1);)
		{
			if (cnt==k)
			{
				ans=min(ans,r-l+1);

				F[arr[l]]--;

				cnt-=arr[l]<=k && F[arr[l]]==0;
				l++;
			}
			else 
			{
				r++;
				F[arr[r]]++;
				cnt+=arr[r]<=k && F[arr[r]]==1;
			}

		}
			if (ans == n+5)
				cout<<"sequence nai\n";
			else cout<<ans<< endl;
	}

}
