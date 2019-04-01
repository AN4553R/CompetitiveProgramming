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
#define endl '\n';
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
	string s, tmp="",asd="";
	
	while (getline(cin, s)) {
		deque<string>ans;
		bool back = 1;
		string save = "";
		rep(i, s.size()) {

			if (s[i] == ']') { back = 1; continue; }
			if (s[i] == '[') { if(!save.empty())ans.push_front(save); save = ""; back = 0; continue; }

			if (back) { ans.push_front(save); save = ""; string tmp = ""; tmp += s[i]; ans.push_back(tmp); continue; }
			save += s[i];
		}
		if (!save.empty())cout << save;
		for (auto i : ans)cout << i;
		cout << endl;
	}
}
