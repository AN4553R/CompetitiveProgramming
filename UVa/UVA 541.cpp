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
	int a[101][101],n;

	while (cin>>n && n) {
		rep(i, n) rep(j, n)cin >> a[i][j];

		int r[100] = { 0 }, c[100] = { 0 };

		rep(i, n) rep(j, n) c[i] += a[i][j], r[i] += a[j][i];
		int ER = 0, EC = 0, er, ec;
		rep(i, n) {
			if (r[i] & 1)	ER++, er = i;
			if (c[i] & 1)	EC++, ec = i;
		}
		if (ER == 0 && EC == 0)
			puts("OK");
		else if (ER == 1 && EC == 1)
			printf("Change bit (%d,%d)\n", ec + 1, er + 1);
		else
			puts("Corrupt");

	}

}
