#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<complex>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<bitset>
#include<queue>
#include<map>
#include<numeric>
#include<map>

using namespace std;
typedef long long ll;
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).end()),((v).begin())
#define clr(v,idx) memset(v,idx,sizeof(v))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define dot cout << fixed << setprecision(15);
#define vi vector<int>						
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll,ll>

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {

	int l;
	string s;
	while (cin >> l && l)
	{
		
		cin >> s;

		int ans = l;
		int D = -l, R = -l;

		rep(i,l)
		{
			if (s[i] == 'Z')
			{
				ans = 0;
				break;
			}
			if (s[i] == 'R') ans = min(ans, i - D),R = i;
			else if (s[i] == 'D')ans = min(ans, i - R), D = i;
		}
		cout << ans << endl;
	}
}
