// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
// #define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
//const double PI = acos(-1.0);
//const double EPS = (1e-9);
typedef long long ll;
typedef unsigned long long ull;
//#define flush fflush(stdout), cout.flush()
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define CASET int ___T; scanf("%d", &___T); for(int TC=1;TC<=___T;TC++)

//#define clr(v,line) memset(v,line,sizeof(v))
//#define RT(x) return x, 0;
//#define lcm(a,b) (a*(b/__gcd(a,b)))
//#define P 1000000007
#define endl '\n'
// const int dx[] = {1,-1,0,0,1,-1,1,-1};
// const int dy[] = {0,0,1,-1,1,-1,-1,1};
// const int dxhorse[] = {-2,-2,-1,-1,1,1,2,2};
// const int dyhorse[] = {1,-1,2,-2,2,-2,1,-1};

// void file() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
// }

void fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
}


int n, limit;

std::vector<vector<int>> graph(1e5);
std::vector<short> cats(1e5);
bool vis[100001] = {0};

int dfs(int idx, int cnt){
	if (cnt > limit || idx == n){
		return 0;
	}
	if (graph[idx].size() == 1 && vis[graph[idx][0]]){
		return 1;
	}
	
	vis[idx] = 1;
	int ret = 0;

	for(auto i:graph[idx]){
		if (!vis[i]){
			ret+=dfs(i, (cnt + cats[i]) * cats[i]);
		}
	}
	return ret;

}
int main(int argc, char const *argv[])
{   

	cin>>n>>limit;
	for (int i = 0; i < n; ++i){
		cin>>cats[i];
	}
	for (int i = 0; i < n - 1; ++i){
		int u, v;cin>>u>>v;
		u--,v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout<<dfs(0, cats[0]);
}
