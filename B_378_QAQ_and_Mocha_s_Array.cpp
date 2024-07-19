#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n; cin>>n;

    vector<ll> vec(n);

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    sort(vec.begin(), vec.end());

    ll startIdx = 0;
    ll i = 1;
    
    while(i < n && (vec[i]%vec[0] == 0)){
        i++;
    }
    if(i >= n){
        cout<<"YES"<<endl;
        return;
    }

    ll endIdx = i;

    for(;i < n;i++){
        if((vec[i]%vec[startIdx] != 0) && vec[i]%vec[endIdx] != 0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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