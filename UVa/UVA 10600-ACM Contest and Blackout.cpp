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
#include<assert.h>
#include<vector>
#include<stack>
#include <utility>
#include<set>
#include<bitset>
#include<queue>
#include<map>
#include<valarray>
#include<numeric>
using namespace std;
const int OO = 1<<25;
const double PI = acos(-1.0);
const double EPS = (1e-9);
typedef long long ll;
typedef complex<double> point;
#define all(v) ((v).begin()),((v).end())
#define rep(i,n) for(int(i)=0;(i)<(int)n;(i)++)
#define clr(v,idx) memset(v,idx,sizeof(v));
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define MP make_pair
#define max3(a,b,c) max(a,max(b,c));
#define min3(a,b,c) min(a,min(b,c));
#define MOD 1000000007;
//const int dx[] = {1,-1,0,0,1,-1,1,-1};
//const int dy[] = {0,0,1,-1,1,-1,-1,1};
//const int dxhorse[] = {-2,-2,-1,-1,1,1,2,2};
//const int dyhorse[] = {1,-1,2,-2,2,-2,1,-1};
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

struct unionFind {
	vi rank, parent;
	int forests;
	unionFind(int nodes) {
		rank = vi(nodes + 1), parent = vi(nodes + 1);
		forests = nodes;
		for (int i = 0; i <= nodes;i++)parent[i] = i, rank[i] = 1;
	}
	int find_parent(int x) {
		if (x == parent[x])return x;
		return parent[x] = find_parent(parent[x]);
	}
	void merge(int x, int y) {
		if (rank[x] > rank[y])swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])rank[y]++;
	}
	bool union_sets(int x, int y) {
		x = find_parent(x), y = find_parent(y);
		if (x != y) {
			merge(x, y);
			forests--;
		}
		return x != y;
	}
};

struct edge {
	int from, to, w;
	edge(int from, int to, int w) :from(from), to(to), w(w) {};
	bool operator < (const edge & e)const {
		return w > e.w;
	}
};
bool comp(edge a, edge b) {
	return a.w < b.w;
}
bool inMST[10000];
pair<int,vector<edge> > MST_kruskal(vector<edge>list, int nodes) {
	unionFind uf(nodes);
	vector<edge>edges;
	int mstCost = 0;
	rep(i,list.size()) {
		edge e = list[i];
		if (uf.union_sets(e.from, e.to))
			mstCost += e.w, edges.push_back(e),inMST[i]=1;
	}
	if (uf.forests != 1)return make_pair( -OO,vector<edge>());
	return{ mstCost,edges };
}
int second(vector<edge>list,int nodes,int skip) {
	unionFind u(nodes);
	int cost = 0,taken=0;
	rep(i, list.size()) {
		if (i != skip && u.union_sets(list[i].from, list[i].to))
			cost += list[i].w,taken++;
	}
	if (u.forests != 1)return OO;
	return cost;
}

int main() {
	int t; cin >> t;
	while (t--) {
		clr(inMST, 0);
		vector<edge>schools;
		int n, m; cin >> n >> m;
		rep(i, m) {
			int a, b, c; cin >> a >> b >> c;
			schools.push_back(edge(a, b, c));
		}
		sort(all(schools), comp);
		pair<int, vector<edge>>mst1= MST_kruskal(schools, n);
		vector<edge>tmp = mst1.second;
		int mst2 = OO;
		rep(i, m) {
			if(inMST[i])mst2=min(mst2,second(schools, n, i));
		}
		cout << mst1.first << " " << mst2 << endl;
	}
}
