#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).end()),((v).begin())
#define clr(v,idx) memset(v,idx,sizeof(v))
#define rep(i,x) for(int i=0;i<(int)x;i++)
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll,ll>
//const int dx[] = {1,-1,0,0,1,-1,1,-1};
//const int dy[] = {0,0,1,-1,1,-1,-1,1};
//const int dxhorse[] = {-2,-2,-1,-1,1,1,2,2};
//const int dyhorse[] = {1,-1,2,-2,2,-2,1,-1};
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}
void fast()
{
std::ios_base::sync_with_stdio(0);
cin.tie(NULL);
cout.tie(NULL);
}

int price[22][22];
int memo[205][22];
int m, c;
int solve(int money,int gar) {
	if (money < 0)return INT_MIN;
	if (gar == c)return m - money;
	int &ret = memo[money][gar];
	if (ret != -1)return ret;
	for (int k = 1; k <= price[gar][0]; k++) {
		ret = max(ret, solve(money - price[gar][k], gar + 1));
	}
	return ret;
}
int main () {
	fast();
	int n; cin >> n;
	for(int i=0;i<n;i++) {
		clr(memo,-1);
		cin >> m >> c;
		for (int i = 0; i < c; i++) {
			cin >> price[i][0]; // we store k in price[i][0];
			for (int t = 1; t <= price[i][0]; t++)
				cin >> price[i][t];
		}
		int total = solve(m, 0);
		if (total < 0)cout << "no solution\n";
		else cout << total << "\n";
	}

}
