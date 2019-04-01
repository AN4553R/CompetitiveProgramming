#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
 
bool sortt(pair<int, string> a, pair<int, string>b) {
 
	return (a.first == b.first) ? a.second<b.second:a.first>b.first;
}
 
int main()
{
	int tests; cin >> tests;
	for (int i = 0; i < tests;i++)
	{
		int m, d, n = 0; cin >> m >> d;
		map<string, int>tree;
		vector<string>name(1000);
		vector<int>p(1000, -1);
 
		while (m--) {
			string s; cin >> s;
			if (!tree.count(s))name[n] = s, tree[s] = n++;
 
			int x; cin >> x;
			while (x--) {
				string t; cin >> t;
				if (!tree.count(t))name[n] = t, tree[t] = n++;
				int grand = tree[s];
				int son = tree[t];
				p[son] = grand;
			}
		}
		vector<int>family(n, 0);
		for (int i = 0; i < n;i++) {
			int cur = i;
			for (int i = 0; i < d; i++) {
				cur = p[cur];
				if (cur == -1)break;
			}
			if (cur != -1)family[cur]++;
		}
 
		vector<pair<int, string> >BuildFamily;
		for (int i = 0; i < n; i++)
			if (family[i])
				BuildFamily.push_back({ family[i],name[i] });
 
		sort(BuildFamily.begin(), BuildFamily.end(), sortt);
 
		cout << "Tree " << i + 1 << ":\n";
		int cnt = 0;
		for (int i = 0; i < (int)BuildFamily.size(); i++) {
 
			if (i && BuildFamily[i].first != BuildFamily[i - 1].first)cnt++;
 
			if (cnt > 2 || (i > 2 && BuildFamily[i].first != BuildFamily[i - 1].first))break;
 
			cout << BuildFamily[i].second << " " << BuildFamily[i].first << endl;
		}
		puts("\n");
	}
}