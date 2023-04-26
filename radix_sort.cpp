#include <bits/stdc++.h>
using namespace std;

static void abs_radix_sort(vector<queue<int>>& qvec, int max_value);

void radix_sort(vector<int>& v) {
	vector<queue<int>> neg(2), pos(2);
	int neg_max = 0, pos_max = 0;
	for (auto& e : v)
		if (e < 0)
			neg.back().push(neg_max < -e ? neg_max = -e : -e);
		else
			pos.back().push(pos_max < e ? pos_max = e : e);
	abs_radix_sort(neg, neg_max);
	abs_radix_sort(pos, pos_max);
	for (int i = neg.front().size(); i--; )
		v[i] = -neg.front().front(), neg.front().pop();
	for (int i = v.size() - pos.front().size(); i < (int) v.size(); ++i)
		v[i] = pos.front().front(), pos.front().pop();
}

static void abs_radix_sort(vector<queue<int>>& qvec, int max_value) {
	int base = 2;
	while (base * base < (int) qvec.back().size())
		base <<= 1;
	qvec.resize(base);
	vector<int> siz(base);
	int div = 1;
	while (true) {
		for (int i = 0; i < base; ++i)
			siz[i] = qvec[i].size();
		for (int i = 0; i < base; ++i)
			while (siz[i]--) {
				int val = qvec[i].front(); qvec[i].pop();
				qvec[val / div % base].push(val);
			}
		if (div > max_value)
			break;
		div *= base;
	}
}
