/*
Instead of changing the array every time we can just use the fact that if x was the xor of previos k-1 queries
then this query will be q[k] ^ x on original array
now a binary trie is used to store the initial numbers
NOTE: When we consider ith bit (0 indexed) there can be 2^i numbers with ith bit as 1 and 2^i numbers with ith bit as 0
*/
#include <bits/stdc++.h>
using namespace std;


struct trie{
	struct trie* left;
	struct trie* right;
	int count = 0; //number of elements which pass through this point
};

struct trie *getNode(){
	struct trie *node = new trie;
	node->left = NULL;
	node->right = NULL;
	node->count = 0;
	return node;
}

void init(struct trie *root, int count){
	if(count > 0){
		root->left = getNode();
		root->right = getNode();
		init(root->left, count - 1);
		init(root->right, count - 1);
	}
}

void insert(struct trie *root, int key){
	struct trie *crawl = root;
	for(int i = 20; i >= 0; --i){
		if(key & (1 << i)){
			if(!crawl->right){
				crawl->right = getNode();
			}
			crawl = crawl->right;
			crawl->count++;
		}
		else{
			if(!crawl->left){
				crawl->left = getNode();
			}
			crawl = crawl->left;
			crawl->count++;
		}
	}
}

bool search(struct trie *root, int key){
	struct trie *crawl = root;
	for(int i = 20; i >= 0; --i){
		if(key & (1 << i)){
			if(!crawl->right)
				return false;
			crawl = crawl->right;
		}
		else{
			if(!crawl->left)
				return false;
			crawl = crawl->left;
		}
	}
	return true;
}

int mex(struct trie *root, int xo){
	struct trie *crawl = root;
	string s = "000000000000000000000";
	for(int i = 20; i >= 0; --i){

		if(xo & (1 << i)){
			if(crawl->right->count >= (1 << (i))){
				s[20-i] = '1';
				crawl = crawl->left;
			}
			else{
				s[20-i] = '0';
				crawl = crawl->right;
			}
		}
		else{
			if(crawl->left->count >= (1 << (i))){
				s[20-i] = '1';
				crawl = crawl->right;
			}
			else{
				s[20-i] = '0';
				crawl = crawl->left;
			}
		}
	}

	int ans = 0;

	for(int i = 20; i >= 0; --i){
		if(s[i] == '1')
			ans = ans + (1 << (20-i));
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int i, n, q, x;
	cin >> n >> q;
	int xo = 0;
	int a[n];
	struct trie* root = getNode();
	
	init(root, 21);
	set<int>s;

	for(i = 0; i < n; ++i){
		cin >> a[i];
		s.insert(a[i]);
	}

	for(auto it: s)
		insert(root, it);

	for(i = 0; i < q; ++i){
		cin >> x;
		xo = xo ^ x;
		int ans = mex(root, xo);
		cout << ans << endl;		
	}

	return 0;
}
