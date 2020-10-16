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

string a, b;

int main(int argc, char const *argv[])
{
    // file();

    cin>>a>>b;

    deque<char>d;
    d.push_back('.');
    for (int i = (int)a.size() - 1; i > b.size(); --i)
    {
        d.push_front(a[i]);
    }
    for (int i = (int)a.size(); i >= 0; --i)
    {
        d.pop_back();
        d.push_front(a[i]);
        int cnt = 0;
        for (int j = 0; j < b.size(); ++j)
        {
            if (b[j] == d[j] or d[j] == '?')
            {
                cnt++;
            }
            else break;
        }
        if (cnt == (int)b.size())
        {
            for(int j = 0; j < i; j++)
                cout<<(a[j] == '?'?'a':a[j]);
            cout<<b;
            for(int j = b.size() + i; j < a.size(); j++)
                cout<<(a[j] == '?'?'a':a[j]);
            return 0;
        }
    }
    cout<<"UNRESTORABLE";

}
