#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

#define llmax LLONG_MAX;
#define llmin LLONG_MIN;
#define imax INT_MAX;
#define imin INT_MIN;
#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i < b; i++)

void __print(int x){cerr << x;}
void __print(long x){cerr << x;}
void __print(long long  x){cerr << x;}
void __print(unsigned x){cerr << x;}
void __print(unsigned long x){cerr << x;}
void __print(unsigned long long x){cerr << x;}
void __print(float x){cerr << x;}
void __print(double x){cerr << x;}
void __print(long double x){cerr << x;}
void __print(char x){cerr << x;}
void __print(const char *x){cerr << '\"' << x << '\"';}
void __print(const string &x){cerr << '\"' << x << '\"';}
void __print(bool x){cerr << (x ? "true" : "false");}
 
template<typename T,typename U>
void __print(const pair<T,U> &x){cerr << "{"; __print(x.first); cerr << ","; __print(x.second);cerr << "}";}
template<typename T>
void __print(const T &x){int f = 0; cerr << '{';for(auto &i: x) cerr << (f++ ? "," : ""), __print(i);cerr << "}";}
void _print() {cerr << "]\n";}
template<typename T,typename... V>
void _print(T t,V... v){__print(t); if(sizeof...(v)) cerr << ", "; _print(v...);}
#define debug(x...) cerr << "[" << #x << "] = [";_print(x);

ll pow0(ll a,ll b);
ll pow1(ll a,ll b,ll mod);

void line(){
	cout << "\n-------------------------------------------------------------------------\n";
}

// Recursive function to return gcd of a and b
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void yes()
{
	cout << "YES\n";
}

void no()
{
	cout << "NO\n";
}

ll max(int a,int b){
	return a >= b ? a : b;
}

ll min(int a,int b){
	return a <= b ? a : b;
}

long long factorial(long long n)
{
    long long res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

template<typename T,typename U,typename V>
void debugt3(tuple<T,U,V> a)
{
	auto x = get<0>(a);auto y = get<1>(a); auto z=get<2>(a);
	printf("{");
	cout << x << "," << y << "," << z << "}\n";
}

template<typename T,typename U,typename V>
void debugvt3(vector<tuple<T,U,V> >& a)
{
	cout << "[" << "tuple" << "] = [";
	for(int i=0;i<a.size();i++){
		auto x = get<0>(a[i]);auto y = get<1>(a[i]); auto z=get<2>(a[i]);
		printf("{");
		cout << x << "," << y << "," << z << "} , ";
	}
	cout << "]\n";
}

void padj(int** grid,int r,int c,int indexing){
	for(int i=indexing;i<r;i++){
		for(int j=indexing;j<c;j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void dfs(int** adj,int index,vector<bool>& visited){
	if(visited[index] == true)return;
	cout << index << " ";

	visited[index] = true;
	for(int i=1;i<visited.size();i++){
		if(adj[index][i] == 1){
			if(visited[i] == false){
				dfs(adj,i,visited);
			}
		}
	}
}

bool sortbysec(const tuple<string, int, int>& a, 
               const tuple<string, int, int>& b)
{
    // return (get<1>(a) < get<1>(b));
    if(get<1>(a) < get<1>(b))return true;
    else if(get<1>(a) == get<1>(b)){
    	return get<2>(a)<get<2>(b);
    }else{
    	return false;
    }
}

//--------------------------------------------------------CODE--------------------------------------------


/* Codeforces Practice Rating 1600 - #2
	Problem link:  https://codeforces.com/contest/1175/problem/B
	B. Catch Overflow
*/
ll mv = 4294967295;

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
		if(s[0] == 'f'){
			ll x; cin >> x;
			ll res = v[v.size()-1] * x;
			int siz = v.size();
			if(v[siz-1] == -1){ // overflow continues
				v.push_back(-1);
			}else if(res/x != v[siz-1] || res>mv){ // overflow starts
				v.push_back(-1);
			}else{ // not overflow
				v.push_back(v[siz-1]*x);
			}
		}else if(s[0] == 'e'){
			v.pop_back();
		}else{
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

//--------------------------------------------------------------------------------------------------------

int main()
{
	int t = 1;int i=1;
	// cin >> t;
	while(t--){
		// printf("Case #%d: ",i);
		solve();
		i++;
	}
}

ll pow0(ll a,ll b)
{
	if(b == 0) return (ll)1;
	if(b == 1) return a;
	int arr[100];int i = 0;ll val = a;ll ans = 1;
	while(b>0){arr[i] = (int)b%2;i++;b /= 2;}
	for(int j=0;j<i;j++){if(arr[j] == 1){ans *= val;}val *= val;}
	return ans;
}
 
ll pow1(ll a,ll b,ll mod)
{
	if(b == 0) return (ll)1;
	if(b == 1) return a;
	int arr[100];int i = 0;ll val = a;ll ans = 1;
	while(b>0){arr[i] = (int)b%2;i++;b /= 2;}
	for(int j=0;j<i;j++){if(arr[j] == 1){ans *= val;ans %= mod;}val *= val;val %= mod;}
	return ans;
}

/*
	Compilation flag ; -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector

*/