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
	
	ll n;
	while (cin >> n) {
		
		vll value(1<<n);

		for (ll i = 0; i < (1 << n); i++)cin >> value[i];
		
		// save each corner's potency.

		vll save(1 << n);

		for (ll corner = 0; corner < 1 << n; corner++) {
			ll pot = 0;
			
			/* 
				Potency of the corner is the sum of weights of all neighbouring corners
				tow points are neighbours if they share the same x or y axis
				x x or y y
				0 0 = 1
				0 1 = 0
				1 0 = 0
				1 1 = 1
				that's the XOR operation 
			*/

			for (ll digit = 0; digit < n; digit++)
					pot += value[corner ^ (1 << digit)];
			save[corner] = pot;
 		}

		// find the maximum potencies sum

		ll mx = 0;
		for (ll cor = 0; cor < 1 << n; cor++)
			for (ll dig = 0; dig < n; dig++)
				mx = max(mx, save[cor] + save[cor ^ (1 << dig)]);
		cout << mx << endl;
	}
}
