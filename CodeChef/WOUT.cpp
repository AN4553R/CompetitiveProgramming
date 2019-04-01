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
#define rall(v) ((v).rbegin()),((v).rend())
#define clr(v,idx) memset(v,idx,sizeof(v))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define dot cout << fixed << setprecision(15);
#define vi vector<int>						
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define sz size()

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int OO = 1e6+6;

int main() {
	int TC; scanf("%d", &TC);
	while (TC--) {
		int n, h; scanf("%d %d", &n, &h);
		ll a[OO], sum[OO] = { 0 };
		fill(a, a + n, n);

		int l, r;
		for (int i = 0; i < n; i++)scanf("%d %d", &l, &r), sum[l] -= 1, sum[r + 1] += 1;

		a[0] += sum[0];
		for (int i = 1; i < n; i++)sum[i] += sum[i - 1], a[i] += sum[i] + a[i - 1];

		ll ans = a[h - 1];

		for (int i = 1; i + h <= n; i++)ans = min(ans, a[h + i - 1] - a[i - 1]);

		printf("%lld\n", ans);
	}
}
