/* Codeforces Practice Rating 1600 - #1
	Problem link:  https://codeforces.com/contest/1175/problem/B
	B. Catch Overflow
*/
#include<bits/stdc++.h>
using namespace std;

ll mv = 4294967295; // 2^32 - 1

void solve()
{
	int n;
	cin >> n;

	ll ans = 0;
	vector<ll> v;
	v.push_back(1);

	bool overflow = false;

	for(int i=0;i<n;i++){
		
    string s; cin >> s;
		
    if(s[0] == 'f'){ // for int
			ll x;
      cin >> x;
			
      ll res = v[v.size()-1] * x;
			int siz = v.size();
		
      if(v[siz-1] == -1){ // overflow continues
				v.push_back(-1);
			}
      else if(res/x != v[siz-1] || res>mv){ // overflow starts
				v.push_back(-1);
			}
      else{ // not overflow
				v.push_back(v[siz-1]*x);
			}
		}
    else if(s[0] == 'e'){ // end
			v.pop_back();
		}
    else{ // add
			if(v[v.size()-1] == -1){
				overflow = true;
				continue;
			}else{
				ans += v[v.size()-1];
			}
		}
	} 

	if(overflow || ans>mv){
		printf("OVERFLOW!!!\n");
		return;
	}else{
		printf("%lld\n",ans);
	}
}

int main(){
  int t = 1; 
//   cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
