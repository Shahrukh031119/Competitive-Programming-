#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7;

class dataStructure {
private:
	multiset<int> ms;
	int sum;

public:
	dataStructure(): sum(0LL) {};

	void add(int x){
		ms.insert(x);
		sum+=x;
	}

	void remove(int x){
		if(ms.find(x)!=ms.end()){
			ms.erase(ms.find(x));
			sum-=x;
        }
		return;
	}

	void getMin(){
		if(ms.empty()){
			cout<<-1<<endl;
		}else{
			cout<<*ms.begin()<<endl;
		}
	}

	void getMax(){
		if(ms.empty()){
			cout<<-1<<endl;
		}else{
			cout<<*ms.rbegin()<<endl;
		}
	}

	void getSum(){
		cout<<sum<<endl;
	}
};

void solve(){
	int q;cin>>q;
	dataStructure ds;
	while(q--){
		int s_no;cin>>s_no;
		switch(s_no){
			case 1:
				int x;cin>>x;
				ds.add(x);
				break;
			case 2:
				int y;cin>>y;
				ds.remove(y);
				break;
			case 3:
				char c;cin>>c;
				ds.getMin();
				break;
			case 4:
				char d;cin>>d;
				ds.getMax();
				break;
			case 5:
				char e;cin>>e;
				ds.getSum();
				break;
			default:
				cout<<"Wrong input"<<endl;
				break;
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