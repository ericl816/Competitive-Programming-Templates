#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10005;

// Using solution to Polynomial Madness as template for code

class poly{
public:
	void init(int n){
		poly.resize(n);
	}
	void set(int x , int vl){
		poly[x] = vl;
	}
	int eval(int vl){

		int x = poly.size();
		int ans = 0;
		for(int j = x - 1 ;  j >= 0 ; j--){
			int y = 1;
			for(int w = 0 ; w < j ; w++) y *= vl;
			ans += y*poly[j];
		}
		return ans;
	}
	void divide(int vl){
		deque<int> newpoly;
		int x = poly.size();
		for(int j = x - 1 ; j > 0 ; j--){
			int r = poly[j];
			newpoly.push_back(r);
			poly[j-1] -= vl*r;
		}
		poly.clear();
		for(auto w : newpoly){
			poly.push_back(w);
		}
		reverse(poly.begin() , poly.end());
	}
	bool tem(){
		if(poly.size() == 0) return 0;
		bool can = false;
		for(auto w : poly){
			if(w != 0) can = true;
		}
		return can;
	}
	void addroot(int vl){
		roots.push_back(vl);
	}
	void printroot(){
		for(auto w : roots){
			cout<<w<<" ";
		}
		cout<<endl;
	}
deque<int> poly;
deque<int> roots;
};

vector<poly> v;

int32_t main(){
	int n;
	cin>>n;
	v.resize(n);
	for(int i = 0 ; i < n; i ++){
		int sz;
		cin>>sz;
		v[i].init(sz + 1);
		for(int j = sz ; j >=0 ; j--){
			int x;
			cin>>x;
			v[i].set(j,x);
		}
		for(int w = -150 ; w <= 150 ; w++){
			while(v[i].tem() && v[i].eval(w) == 0){
				v[i].divide(-w);
				v[i].addroot(w);
			}
		}
	}
	for(int i = 0 ; i < n; i ++) v[i].printroot();
}