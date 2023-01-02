#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// check if given string contains balanced parenthesis or not

// solution 
// keeping count of depth of parenthesis
// two conditions
// depth at all level must be >= 0 & last depth=0
// time = O(N)

void solve(){
    string s;cin>>s;
    int depth=0;
    bool isBal=1;
    for(auto v:s){
        if(v=='('){
            depth++;
        }else{
            depth--;
        }
        if(depth<0){
            isBal=0;
            break;
        }
    }
    if(depth!=0){
        isBal=0;
    }
    if(isBal){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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
