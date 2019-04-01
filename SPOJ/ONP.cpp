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
	
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		stack<string>k;
		bool back = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') back = 0;
			if (s[i] == ')') back = 1;

			if (s[i] == ')') {
				string op2 = k.top();
				k.pop();
				string oper = k.top();
				k.pop();
				string op1 = k.top();
				k.pop();
				k.push(string(op1 + op2 + oper));
				
			}
			else {
				if (s[i] != '(')
				{
					string tmp = "";
					tmp += s[i];
					k.push(tmp);
				}
			}
		}
		while (!k.empty())cout << k.top(), k.pop();
		cout << endl;
	}
}
