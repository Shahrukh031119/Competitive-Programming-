#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// check if the given string of parenthesis is balanced or not
// input : [{()}])
// output : NO

void solve(){
    string s;cin>>s;
    map<int,int> mp;
    mp['[']=1;
    mp['{']=2;
    mp['(']=3;
    mp[']']=4;
    mp['}']=5;
    mp[')']=6;
    stack<int> st;
    bool isBal=1;
    for(auto i:s){
        int num=mp[i];
        if(num<=3){
            st.push(mp[i]);
        }else{
            if(st.empty() || (mp[i]-st.top())!=3){
                isBal=0;
                break;
            }
            st.pop();
        }
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
