#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define rep(i,n) for(int(i)=0;(i)<(int)n;(i)++)
#define clr(v,idx) memset(v,idx,sizeof(v));
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
void SneakPeek() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

ll merge(int A[], int start, int mid, int end) {

	int p = start, q = mid + 1;
	vector<int> Arr(end - start + 1);
	int k = 0;
	ll ret = 0;

	for (int i = start; i <= end; i++) {

		if (p > mid)
			Arr[k++] = A[q++];

		else if (q > end)
			Arr[k++] = A[p++];

		else if (A[p] <= A[q])
			Arr[k++] = A[p++];

		else
		{
			Arr[k++] = A[q++];
			ret += mid - p + 1;
		}

	}
	for (int p = 0; p < k; p++) {

		A[start++] = Arr[p];
	}
	return ret;
}

ll merge_sort(int A[], int start, int end)
{
	ll count = 0;
	if (start < end) {
		int mid = (start + end) / 2;
		count += merge_sort(A, start, mid);
		count += merge_sort(A, mid + 1, end);
		count += merge(A, start, mid, end);
	}
	return count;
}
int main()
{
	SneakPeek(); fast();
	int TC; cin >> TC;
	while (TC--)
	{
		int arr[200002];
		int x; cin >> x;
		rep(i, x)cin >> arr[i];
		cout << merge_sort(arr, 0, x - 1)<<endl;
	}
}
