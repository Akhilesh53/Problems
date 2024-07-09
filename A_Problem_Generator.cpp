#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n,m; cin>>n>>m;
    string quesLevel; cin>>quesLevel;

    vector<int> quesCount(7,0);

    for(int i=0;i<n;i++){
        quesCount[quesLevel[i]-'A']++;
    }

    ll ans = 0;

    for(int it : quesCount){
        if(it < m){
            ans += m-it;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ll tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }
}