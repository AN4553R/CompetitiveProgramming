#pragma comment(linker, "/stack:200000000")
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define rep(i,n) for(int(i)=0;(i)<(int)n;(i)++)
#define clr(v,idx) memset(v,idx,sizeof(v));
#define vi vector<int>
#define vll vector<ll>
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
	
	int TC, n, m; cin >> TC;

	while (TC--)
	{
		cin >> n >> m;
		vi v(n);
		rep(i, n)cin >> v[i];
		bool ok = 1;

		for (int i = 0; i < (1<<n); i++)
		{
			int sum = 0;
			for(int j=0;j<n;j++)
				if (i & (1 << j))sum += v[j];
			if (sum == m) { cout << "Yes\n"; ok = 0; break; }
		}
		if (ok)cout << "No\n";
	}		
}
