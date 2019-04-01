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
const int OO = 600;

int main() {
	fast();
	int TC; cin >> TC;
	for (int I=1;I<=TC;I++)
	{
		string a, b; cin >> a >> b;
		map<string, string>o, n;
		stringstream first(a), second(b);
		char bracket;
		first >> bracket;
		string keyandvalue;

		while (getline(first, keyandvalue, ',')) {
			stringstream cut(keyandvalue);
			string key;
			string value;
			getline(cut, key, ':'), getline(cut, value, '}');
			o[key] = value;
		}
		second >> bracket;
		while (getline(second, keyandvalue, ',')) {
			stringstream cut(keyandvalue);
			string key;
			string value;
			getline(cut, key, ':'), getline(cut, value, '}');
			n[key] = value;
		}
		map<string, bool>vis;
		bool zero = 1;
		int cnt = 0;
		for (auto i : n) {
			if (!o.count(i.first)) {
				cout << (zero ? '+' : ',') << i.first;
				if (zero)zero ^= 1;
				vis[i.first] = 1;
			}
		}
		if (!zero)zero ^= 1, cout << '\n',cnt++;
		
		for (auto i : o) {
			if (!n.count(i.first)) {
				cout << (zero ? '-' : ',') << i.first;
				if (zero)zero ^= 1;
				vis[i.first] = 1;
			}
		}
		if (!zero)zero ^= 1, cout << '\n',cnt++;
		
		for (auto i : o) {
			for(auto j:n)
			if (i.first==j.first  && i.second!=j.second && !vis.count(i.first)) {
				cout << (zero ? '*' : ',') << i.first;
				if (zero)zero ^= 1;
			}
		}
		if (!zero)zero ^= 1, cout << '\n', cnt++;
		if (cnt == 0)cout << "No changes\n";
		if (I < TC)cout << '\n';
	}
}
