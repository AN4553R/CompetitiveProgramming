#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<iomanip>
#include<cmath>
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
#define all(v) ((v).begin()),((v).end())
#define rep(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define vint vector<int>
#define vll vector<ll>
#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define MP make_pair
#define max3(a,b,c) max(a,max(b,c));
#define min3(a,b,c) min(a,min(b,c));
#define MOD 1000000007;
#define PI 3.1415926535897
const int OO = (int)1e6;
typedef long long ll;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
//int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
//int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
 
unsigned int gcd(unsigned int n1, unsigned int n2) {
	return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}
 
bool winner(string s) {
// 012
// 345
// 678
	bool row = (s[0] != '.' && s[0] == s[1] && s[1] == s[2]) ||
		       (s[3] != '.' && s[3] == s[4] && s[4] == s[5]) ||
		       (s[6] != '.' && s[6] == s[7] && s[7] == s[8]);
 
	bool clm = (s[0] != '.' && s[0] == s[3] && s[3] == s[6]) ||
		       (s[1] != '.' && s[1] == s[4] && s[4] == s[7]) ||
		       (s[2] != '.' && s[2] == s[5] && s[5] == s[8]);
	bool dig = (s[0] != '.' && s[0] == s[4] && s[4] == s[8]) ||
		       (s[2] != '.' && s[2] == s[4] && s[4] == s[6]);
	return row || clm || dig;
}
int main()
{
		string board;
		while(cin >> board && board!="end") {
 
		string start = ".........";
		queue<pair<string, bool> >q;
		q.push(MP(start, 1));
 
		bool ok = 0;
		while (!q.empty()) {
			string cur = q.front().first;
			bool turn = q.front().second;
			q.pop();
			if (cur == board) {
				ok = 1; break;
			}
			if (winner(cur))continue;
			rep(i, 9) {
				if (cur[i] == '.')
				{
					cur[i] = turn ? 'X' : 'O';
					if (cur[i] == board[i])
						q.push(MP(cur, 1 ^ turn));
					cur[i] = '.';
				}
			}
		}
		if (ok && (board.find('.') == -1 || winner(board)))puts("valid");
			else puts("invalid");
 
	}
} 