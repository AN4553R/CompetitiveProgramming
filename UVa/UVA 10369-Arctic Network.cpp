#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int OO = 1 << 24;

#define all(v) ((v).begin()),((v).end())
#define rep(i,n) for(int(i)=0;(i)<(int)n;(i)++)
#define clr(v,idx) memset(v,idx,sizeof(v));
#define vi vector<int>



struct unionFind {
	vi rank, parent,sz;
	int forests;
	unionFind(int nodes) {
		rank = vi(nodes + 1), parent = vi(nodes + 1),sz=vi(nodes+1,1);
		forests = nodes;
		for (int i = 0; i <= nodes; i++)parent[i] = i, rank[i] = 1;
	}
	int find_parent(int x) {
		if (x == parent[x])return x;
		return parent[x] = find_parent(parent[x]);
	}
	void merge(int x, int y) {
		if (rank[x] > rank[y])swap(x, y);
		parent[x] = y;
		sz[y] += sz[x];
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
	int siz(int x) { return sz[find_parent(x)]; }
};

struct edge {
	int from, to;
	double w;
	edge(int from, int to, double w) :from(from), to(to), w(w) {};
	bool operator < (const edge & e)const {
		return w > e.w;
	}
};
bool comp(edge a, edge b) {
	return a.w < b.w;
}

int x[10005], y[10005];
double calc(int i, int t) {
	double a = x[i] - x[t];
	double b = y[i] - y[t];
	return hypot(a,b);
}

int main()
{
	int t; cin >> t;
	while (t--) {
		int s, p; cin >> s >> p;
		for (int i = 1; i <= p; i++) {
			cin >> x[i] >> y[i];
		}
		vector<edge>web;
		for (int i = 1; i < p; i++)
			for (int t = i + 1; t <= p; t++)
				web.push_back(edge(i, t, calc(i, t)));
		sort(all(web), comp);
		unionFind uf(p);
		double ans = 0;
		int c = p;
		for (int i = 0; i < (int)web.size() && c != s; i++)
			if (uf.union_sets(web[i].from, web[i].to))ans = web[i].w, c--;
		printf("%.2lf\n", ans);
	}
}
