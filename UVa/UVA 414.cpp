#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define endl '\n'
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
	
	int t;
	while (cin >> t,t) {
	
		vector<pair<string, int> >store(t);
		string s;
		cin.ignore();
		int mn = INT_MAX;
		rep(i, t) {
			getline(cin, s);
			int spaces = count(all(s), ' ');
			mn = min(mn, spaces);
			store[i] = { s,spaces };
		}
		int ans = 0;
		for (auto i : store)ans += i.second - mn;
		cout << ans << endl;
	}
}
