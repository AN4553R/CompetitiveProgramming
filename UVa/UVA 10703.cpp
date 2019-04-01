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

bool board[505][505];

int main(int argc, char const *argv[])
{
	file();

	int W,H,N;

	while(cin>>W>>H>>N && W && H && clr(board,0))
	{
		for (int i = 0; i < N; ++i)
		{
			int x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2;

			if (x1>x2)
				swap(x1,x2);

			if (y1>y2)
				swap(y1,y2);
			for (int j = x1; j <= x2; ++j)
			{
				for (int t = y1; t <= y2; ++t)
				{	
					board[j][t]|=1;
				}
			}

		}
		int ans=0;
		for (int i = 1; i <= W; ++i)
		{
			for (int j = 1; j <= H; ++j)
			{
				ans+=!board[i][j];
			}
		}
		if (!ans)
		{
			cout<<"There is no empty spots.\n";
		}
		else if (ans==1)
		{
			cout<<"There is one empty spot.\n";
		}
		else
			cout<<"There are "<<ans<<" empty spots.\n";
	}

}
