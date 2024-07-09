#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n,a,b; cin>>n>>a>>b;

    if(a > b){
        cout<<a*n<<endl;
    }else{
        ll k = min(b-a,n);
        ll ans = (n-k)*a;
        ll sumB = (b*(b+1))/2;
        ll rest = b-k;
        ll sumRest = (rest*(rest+1))/2;
       // cout<<k<<" "<<ans<<" "<<sumB<<" "<<rest<<" "<<sumRest<<" "<<endl;
        ans += sumB - sumRest;
        cout<<ans<<endl;
    }
    //9+8+7+6+5+4+3+2+1 - ()
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