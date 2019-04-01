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

	string s;
	while (getline(cin, s)) {
		stringstream check(s);
		string inter;
		int space = 0;
		while (getline(check, inter, ' '))
		{
			reverse(all(inter));
			if (space)cout << " ";
			cout << inter, ++space;
		}
		cout<<endl;
	}
}
