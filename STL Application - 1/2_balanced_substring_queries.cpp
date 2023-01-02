#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// check if, for the given string 
// the queries with l-r range
// satisfy balanced parenthesis condition

// solution 
// keeping count of depth of parenthesis
// two conditions
// depth at all level must be >= 0 & last depth=0
// time = O(N)

void solve(){
    string s;cin>>s;
    int q;cin>>q;
    vector<int> D;
    D.push_back(0);
    int depth=0;
    for(auto i:s){
        if(i=='('){
            depth++;
        }else{
            depth--;
        }
        D.push_back(depth);
    }
    for(auto i:D){
        cout<<i<<" ";
    }
    cout<<endl;
    while(q--){
        int l,r;cin>>l>>r;
        bool isBal=1;
        if(D[l]==D[r+1]){
            for(int i=l+1; i<=r; i++){
                if(D[i]<D[l]){
                    isBal=0;
                    break;
                }
            }
        }else{
            isBal=0;
        }
        if(isBal){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
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
