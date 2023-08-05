#include <bits/stdc++.h>
using namespace std;

static void abs_count_sort(vector<int> &v, size_t max_value);

void count_sort(vector<long> &v) {
	vector<long> neg, pos;
	size_t neg_max=0, pos_max=0;
	for (auto &e: v) {
		if (e < 0) { neg.push_back(neg_max<-e ? neg_max=-e : -e); }
		else { pos.push_back(pos_max<e ? pos_max=e : e); }
	}
	abs_count_sort(neg, neg_max);
	abs_count_sort(pos, pos_max);
	for (size_t i=0; neg.size()!=0; ++i) {
		v[i] = -neg.back(), neg.pop_back();
	}
	for (size_t i=v.size(); pos.size()!=0; ) {
		v[--i] = pos.back(), pos.pop_back();
	}
}

static void abs_count_sort(vector<long> &v, size_t max_value) {
	vector<long> cnt(max_value+1);
	for (auto &e: v) { cnt[e]+=1; }
	for (size_t i=0, j=0; i<=max_value; ++i) {
		while (cnt[i]--) { v[j++]=i; }
	}
}
