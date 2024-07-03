#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<bool> primes(10000005,true);

void sieveOfErosthenes(int n){

    for(int i=2; i*i<=n; i++){
        for(int j=i*i; j<=n; j+=i){
            primes[j] = false;
        }
    }
}

void solve()
{
    sieveOfErosthenes(10000005);
    ll n; cin>> n;

    for(int i=1; i<=10000005; i+=n){
        if(primes[i] == false){
            cout<< (i-1)/n << endl;
            break;
        }
    }

}

int main(){
    solve();
}