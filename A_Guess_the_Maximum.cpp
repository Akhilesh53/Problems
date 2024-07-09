#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n; cin>>n;
    vector<ll> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ll minMaxVal = INT_MAX;
    if(arr[0] >= arr[1]){
        minMaxVal = arr[0];
    }else{
        minMaxVal = arr[1];
    }

    for(ll i =1; i < n-1; i++){
        if(arr[i] >= arr[i+1]){
            minMaxVal = min(minMaxVal, arr[i]);
        }else{
            minMaxVal = min(minMaxVal, arr[i+1]);
        }
    }
    cout<<minMaxVal-1<<endl;
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