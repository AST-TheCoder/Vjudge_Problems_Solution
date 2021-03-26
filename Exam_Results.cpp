//Problem link: https://vjudge.net/contest/428714#problem/D

//Solution:

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll power(ll n,ll p,ll val){
	if(p==1) return n;
	if(p%2){
		ll x=power(n,p-1,val);
		//cout<<x<<endl;;
		if(x>val) return val+1;
		return x*n;
	}
	ll x=power(n,p/2,val);
	//cout<<x<<endl;
	if(x>val) return val+1;
	return x*x;
}

int main()
{	
	ll t,ii=0;
	cin>>t;
	while(t--){
		ll n,p;
		cin>>n>>p;

		pair<ll,ll> a[n];
		vector<ll> x,s,e;
		ll st=0,ans=0;
		for(ll i=0;i<n;i++){
			cin>>a[i].first>>a[i].second;
			if(a[i].first>a[i].second) swap(a[i].first,a[i].second);
			x.pb(a[i].first);
			x.pb(a[i].second);
			ll u=(a[i].first*100LL)/p;
			if(u<a[i].second){
				s.pb(a[i].first);
				e.pb(u);
				u=(a[i].second*100LL)/p;
				s.pb(a[i].second);
				e.pb(u);
			}
			else{
				u=(a[i].second*100LL)/p;
				s.pb(a[i].first);
				e.pb(u);
			}
			st=max(st,a[i].first);
		}
		sort(all(s));
		sort(all(e));
		for(ll i=0;i<x.size();i++){
			if(x[i]<st) continue;
			ll u=upper_bound(all(s),x[i])-s.begin();
			u=s.size()-u;
			ll v=lower_bound(all(e),x[i])-e.begin();
			ans=max(ans,(ll)s.size()-(u+v));
		}
		cout<<"Case #"<<++ii<<": "<<ans<<endl;
	}
	return 0;
}
