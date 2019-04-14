#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WaRNINGS
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
typedef unsigned long long ull;
#define flush fflush(stdout), cout.flush()
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define clr(v,line) memset(v,line,sizeof(v))
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define P 1000000007
#define endl '\n'

const ll dx[] = {1,-1,0,0,1,-1,1,-1};
const ll dy[] = {0,0,1,-1,1,-1,-1,1};

void file() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const int OO=5000;

ll v[OO];

int main(int argc, char const *argv[])
{
	file();
	fast();

	v[0]=0;

	for (int i = 1; i < OO; ++i)
	{
		v[i]=i+v[i-1];
	}

	int n;
	while(cin>>n){

		int line=upper_bound(v,v+OO,n)-v;

		line-=line && v[line-1]==n;

		cout<<"TERM "<<n<<" IS ";

		if (line & 1)
		{
			cout<<1+v[line]-n<<"/"<<line-(v[line]-n)<<endl;
		}
		else 
			cout<<line-(v[line]-n)<<"/"<<1+v[line]-n<<endl;
	}

}
