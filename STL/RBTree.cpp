// CREDITS:
// https://codeforces.com/blog/entry/47935
// https://codeforces.com/blog/entry/15729
#include<bits/stdc++.h>
#include "debug.cpp"
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ordered_set<int>  s;
	s.insert(1); 
	s.insert(3);
	cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
    cout << s.order_of_key(3) << endl;
    cout << s.order_of_key(4) << endl;
	cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)
}