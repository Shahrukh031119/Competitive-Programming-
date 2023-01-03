#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// for
// case 1: n<=m
// O(n^n) will work

//case 2:
// but for n>m
// only m possible remainders
// but >m nos are possible 
// therefore using pigeon hole principle
// 2 same remianders whose diff = 0
// therefore final answer is 0

// eg
// input:
// 2 10
// 8 5
// output:
// 3

void solve(){
    int n,m; cin>>n>>m;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(n<=m){
        int res=1;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int diff=abs(arr[i]-arr[j])%m;
                res=(res*diff)%m;
            }
        }
        cout<<res<<endl;
    }else{
        cout<<0<<endl;
    }
}

signed main(){
#ifndef ONLINE_JUDGE
    // FOR GETTING INPUT FROM INPUT.TXT
    freopen("input.txt","r",stdin);
    // FOR WRITING OUTPUT TO OUTPUT.TXT
    freopen("output.txt","w",stdout);
#endif  

    IOS
    // int _t;cin>>_t;
    // string dummy;getline(cin,dummy);
    // while(_t--)
    solve();
}