

#include<iostream>
#include<vector>
using namespace std;

void solveA() {

// A. Binary Imbalance
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given a string s
// , consisting only of characters '0' and/or '1'.

// In one operation, you choose a position i
//  from 1
//  to |s|−1
// , where |s|
//  is the current length of string s
// . Then you insert a character between the i
// -th and the (i+1)
// -st characters of s
// . If si=si+1
// , you insert '1'. If si≠si+1
// , you insert '0'.

// Is it possible to make the number of zeroes in the string strictly greater than the number of ones, using any number of operations (possibly, none)?

// Input
// The first line contains a single integer t
//  (1≤t≤100
// ) — the number of testcases.

// The first line of each testcase contains an integer n
//  (1≤n≤100
// ).

// The second line contains a string s
//  of length exactly n
// , consisting only of characters '0' and/or '1'.

// Output
// For each testcase, print "YES" if it's possible to make the number of zeroes in s
//  strictly greater than the number of ones, using any number of operations (possibly, none). Otherwise, print "NO".

	int n;
	cin >> n;
	
	string s;
	cin >> s;

	int o = 0;
	int z = 0;

	for(auto x: s) {
		if(x == '0') z++;
		else o++;
	}

	if(o == n) {
		cout <<"NO" << endl;
		return;
	}

	cout <<"YES" << endl;
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		solveA();
	}

	return 0;
}