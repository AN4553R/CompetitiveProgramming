#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define rep(i,n) for(int(i)=0;(i)<(int)n;(i)++)
#define clr(v,idx) memset(v,idx,sizeof(v));
#define vi vector<int>
#define vll vector<ll>
#define max3(a,b,c) max(a,max(b,c));
#define min3(a,b,c) min(a,min(b,c));

#define endl '\n'

//const int dx[] = {1,-1,0,0,1,-1,1,-1};
//const int dy[] = {0,0,1,-1,1,-1,-1,1};
//const int dxhorse[] = {-2,-2,-1,-1,1,1,2,2};
//const int dyhorse[] = {1,-1,2,-2,2,-2,1,-1};

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
const int OO = 0xF4240;

int N, order;


void solve() {
	
	while(1) {
		stack<int> station;
		int original = 0;
		rep(i,N) {
			cin >> order;
			if (!order) return;

			while (original < N && original != order) {
				if (!station.empty() && station.top() == order) break;
				station.push(++original);
			}
			if (station.top() == order) station.pop();
		}
		if (station.empty()) puts("Yes");
		else puts("No");
	}
}
int main()
{
	while(1) {
		cin >> N;
		if (!N) break;
		solve();
		puts("");
	}
	//system("pause");
}
