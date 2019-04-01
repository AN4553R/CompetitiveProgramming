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
	int n;

	while (cin >> n&& n) {

		vi O;
		rep(i, 31)if ((1 << i) & n) O.push_back(i);
		int a = 0, b = 0;

		rep(i, O.sz)
			if (i % 2) b |= (1 << O[i]);
			else a |= (1 << O[i]);
			cout << a << " " << b << '\n';
	}
	
	/*
		// another solution using bitset
		
		int n;
		while (cin>>n , n) {
		bitset<32>num(n),a,b;
		bool flip = 1;
		for (int i = 0; i < 32; i++)
			if (num[i] && flip)a[i].flip(), flip ^= 1;
			else if (num[i])b[i].flip(), flip ^= 1;
			cout << a.to_ulong()<<" "<<b.to_ulong()<<'\n';
		}
	
	*/

}
