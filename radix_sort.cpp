#include <bits/stdc++.h>
using namespace std;

static void abs_radix_sort(vector<queue<long>> &qvec, size_t max_value);

void radix_sort(vector<long> &v) {
	vector<queue<long>> neg(2), pos(2);
	size_t neg_max=0, pos_max=0;
	for (auto &e: v) {
		if (e < 0) { neg.back().push(neg_max<-e ? neg_max=-e : -e); }
		else { pos.back().push(pos_max<e ? pos_max=e : e); }
	}
	abs_radix_sort(neg, neg_max);
	abs_radix_sort(pos, pos_max);
	for (size_t i=neg.front().size(); i--; ) {
		v[i] = -neg.front().front(), neg.front().pop();
	}
	for (size_t i=v.size()-pos.front().size(); i<v.size(); ++i) {
		v[i] = pos.front().front(), pos.front().pop();
	}
}

static void abs_radix_sort(vector<queue<long>> &qvec, size_t max_value) {
	size_t base=2, div=1;
	while (base*base < qvec.back().size()) { base<<=1; }
	qvec.resize(base);
	vector<size_t> siz(base);
	while (true) {
		for (size_t i=0; i<base; ++i) {
			siz[i] = qvec[i].size();
		}
		for (size_t i=0; i<base; ++i) {
			while (siz[i]--) {
				size_t val = qvec[i].front();
				qvec[i].pop();
				qvec[val/div%base].push(val);
			}
		}
		if (div > max_value) { break; }
		div *= base;
	}
}
