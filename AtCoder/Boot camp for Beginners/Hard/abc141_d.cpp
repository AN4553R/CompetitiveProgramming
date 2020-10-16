#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long

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

ll n, m, ans = 0;
priority_queue<ll>q;

int main(int argc, char const *argv[])
{
    // file();

    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        int x; cin>>x;
        q.push(x);
    }
    while(m-- and !q.empty())
    {
        ll cur = q.top();
        q.pop();
        q.push(cur>>1);
    }
    while(!q.empty())ans+=q.top(), q.pop();
    cout<<ans;

}
