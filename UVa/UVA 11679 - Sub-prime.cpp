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
	int B, N;
	while (cin >> B >> N && (B||N)) {
		vi VB(B);
		rep(i, B)scanf("%d", &VB[i]);
		int D, C, V;
		rep(i, N) {
			scanf("%d%d%d", &D, &C, &V);
			VB[D - 1] -= V, VB[C - 1] += V;
		}
		bool ok = 1;
		for (int i : VB)
			ok &= i >= 0;
		puts(ok?"S":"N");
	}
}
