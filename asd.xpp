#include<bits/stdc++.h>
using namespace std; 


int main() 
{
	int n;cin>>n;
	std::map<string, int> map;
	while(n--){
		string s;cin>>s;
		map[s]++;
	}
	priority_queue<pair<int, string> >q;

	for(auto i:map)
		q.push({i.second, i.first});
	int cnt = q.top().first;

	set<string>ans;
	while(!q.empty() && q.top().first == cnt){
		ans.insert(q.top().second);
		q.pop();
	}
	for(auto i:ans)cout<<i<<endl;
} 
