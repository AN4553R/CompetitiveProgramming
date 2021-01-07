#include<bits/stdc++.h>
using namespace std; 

int main(int argc, char const *argv[])
{
	string s; cin>>s;
	long long w = 0, ans = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'W')
		{
			ans+=i - w, w++;
		}
	}
	cout<<ans;
}
