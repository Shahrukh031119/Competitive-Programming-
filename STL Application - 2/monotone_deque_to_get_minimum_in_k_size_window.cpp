#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// print minimum in every window of size k
// from a set of n elements
// time - O(nlogk)

// input
// 9 3
// 3 2 1 5 8 7 6 1 2

// output
// 1 1 1 5 6 1 1

// to solve in time - O(N)
// use of monotone deque
// insert from one ened
// get minimum from the other end

struct monotone_deque{
    deque<int> dq;
    void insert(int x){
        while(!dq.empty() && dq.back()>x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x){
        if(!dq.empty() && dq.front()==x){
            dq.pop_front();
        }
    }
    int getmin(){
        return dq.front();
    }
};

void solve(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    monotone_deque mq;
    for(int i=0; i<n; i++){
        mq.insert(arr[i]);
        if((i-k)>=0){
            mq.remove((arr[i-k]));
        }
        if(i+1>=k){
            cout<<mq.getmin()<<" ";
        }
    }
    cout<<endl;
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