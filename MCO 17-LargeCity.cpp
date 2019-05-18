/*
Idea same as the public solution
The idea is to make a set of reachable intervals in current and previous row as if we have no restriction
Now the previous row reachable cells do impact on the current row
We have to find the cells reachable in the current row
For the large test case to pass, we have to notice that most of the rows will be empty and can be skipped 
*/

/*
When you walk through a storm
Hold your head up high
And don't be afraid of the dark
At the end of the storm
There's a golden sky
And the sweet silver song
of the lark
Walk on, through the wind
Walk on, through the rain
Though your dreams be tossed
and blown
Walk on, walk on
With hope in your heart
And you'll never walk alone
YNWA
*/

//hell_hacker
//IT TAKES EVERYTHING and IT IS NOT LUCK
//PICK ME LAST -- COME OUT OF N^WHERE
//WHY NOT?

/*
And you came my way on a winner's day
Shouted loudly come out and play
Can't you tell I got news for you
Sun is shining and so are you
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)
#define forr(i,n) for(i=n-1;i>=0;--i)
#define rep(i,a,b) for(i=a;i<=b;++i)
#define per(i,a,b) for(i=b;i>=a;--i)

#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits
#define popcll(a) __builtin_popcountll(a) //count set bits for long long int

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define yolo "debug_statement"

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const ll inf = 1e9;
const ld eps = 1e-9;
const ld pi=acos(-1);
const ll mod=1000000007;

ll powmod(ll a,ll b,ll mo=mod){ll res=1;a%=mo; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}

inline ll inv_(ll a) {return powmod(a, mod-2, mod);}
inline ll add(ll a, ll b){a%=mod; b%=mod; a+=b;if(a>=mod)a-=mod;return a;}
inline ll mul(ll a, ll b){a%=mod; b%=mod; return a*1ll*b%mod;}
inline ll sub(ll a, ll b){a%=mod; b%=mod; a-=b;if(a<0)a+=mod;return a;}

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

/*USAGE
ordered_set X;
X.insert(1);
X.insert(3);
cout << *X.find_by_order(1) << endl; //3
cout << X.order_of_key(-5) << endl; //0
cout << X.order_of_key(1) << endl; //0
cout << (end(X) == X.order_of_key(100)) << endl; //true since utne elements nahi hai
*/

#if DEBUG && !ONLINE_JUDGE

    #define debug(args...)     (Debugger()) , args

    class Debugger
    {
        public:
        Debugger(const std::string& _separator = ", ") :
        first(true), separator(_separator){}

        template<typename ObjectType>
        Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std::cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std::cerr << endl;}

        private:
        bool first;
        std::string separator;
    };

    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }

    template <typename T1, unsigned long int N>
    inline std::ostream& operator << (std::ostream& os, const std::array<T1, N>& a){
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < N; i++)
        {
            if(!first)
                os << ", ";
            os << a[i];
            first = false;
        }
        return os << "]";   
    }

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
        {
            if(!first)
                os << ", ";
            os << *iii;
            first = false;
        }
        return os << "]";
    }

    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
        {
            if(!first)
                os << ", ";
            os << *iii ;
            first = false;
        }
        return os << "]";
    }

#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

bool cmp(pair<int,int>&lhs, pair<int,int>&rhs){
	if(lhs.fi == rhs.fi)return lhs.se < rhs.se;
	else return lhs.fi < rhs.fi;
}

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    vii v;
	int n, m, x, y;
	cin >> n >> m;


	set<int>usefulrows;

	// usefulrows.insert(1);
	for(int i = 0; i < m; ++i){
		cin >> x >> y;
		usefulrows.insert(x);
		if(x < n)usefulrows.insert(x + 1);
		v.pb({x, y});
	}            
	// usefulrows.insert(3);

	sort(all(v), cmp);

	set<pair<int,int>>S, T, I;

	ll ans = 0;
	ll curans = 0;

	int be = 1;
	int vctr = 0;
	for( ; be <= n && vctr < sz(v); ++vctr){
		if(v[vctr].fi > v[0].fi)break;
		if(v[vctr].se == be)be++;
		else{
			S.insert({be, v[vctr].se - 1});
			be = v[vctr].se + 1;
			if(v[0].fi == 1)
				break;
		}
	}
	if(be <= n){
		if(v[0].fi == 1 && be == 1)S.insert({be, n});
		else if(v[0].fi > 1)S.insert({be, n});
	}

	ans = n*1ll*(v[0].fi - 1);
	for(auto it: S){
		ans = ans + it.se - it.fi + 1;
	}
	int prev = v[0].fi;
	ll prevans = ans;

	for(auto usefulrowitr: usefulrows){
		if(usefulrowitr == v[0].fi)continue;
		curans = 0;
		//calculate T
		be = 1;
		for( ; be <= n && vctr < sz(v); ++vctr){
			while(vctr < sz(v) && v[vctr].fi < usefulrowitr){
				vctr++;
			}
			if(v[vctr].fi > usefulrowitr)break;
			if(v[vctr].se == be)be++;
			else{
				T.insert({be, v[vctr].se - 1});
				be = v[vctr].se + 1;
			}
		}
		if(be <= n)
			T.insert({be, n});

		//solve to find set I
		set<pair<int,int>>::iterator it1 = S.begin();
		set<pair<int,int>>::iterator it2 = T.begin();
		while(it1 != S.end() && it2 != T.end()){
			if(it1->se < it2->fi)it1++;
			else if(it2->se < it1->fi)it2++;
			else if(it1->fi >= it2->fi && it1->se <= it2->se){
				I.insert({it1->fi, it2->se});
				curans = curans + it2->se - it1->fi + 1;
				it1++;
				it2++;
			}
			else if(it1->fi <= it2->fi && it1->se <= it2->se){
				I.insert({it2->fi, it2->se});
				curans = curans + it2->se - it2->fi + 1;
				it1++;
				it2++;				
			}
			else if(it2->fi <= it1->fi && it2->se <= it1->se){
				I.insert({it1->fi, it2->se});
				curans = curans + it2->se - it1->fi + 1;
				it2++;
			}
			else if(it2->fi >= it1->fi && it2->se <= it1->se){
				I.insert({it2->fi, it2->se});
				curans = curans + it2->se - it2->fi + 1;
				it2++;
			}
		}

		//S = I and T ko clear
		S = I;
		T.clear();
		I.clear();
		ans = ans + (usefulrowitr - prev - 1)*prevans;
		ans = ans + curans;
		prev = usefulrowitr;
		prevans = curans;
	}


	ans = ans + (n - prev)*curans;

	cout << ans << endl;

    //#if !ONLINE_JUDGE
    //    cout << fixed << setprecision(12) << "-------------------------------------------------\n";
    //    cout << double(clock())/CLOCKS_PER_SEC << " seconds" << endl;
    //#endif
    return 0;
}

