#include <bits/stdc++.h>
using namespace std;

static void abs_radix_sort(vector<queue<int>>& qvec);

void radix_sort(vector<int>& v) {
	vector<queue<int>> neg(2), pos(2);
	for (auto& e : v)
		if (e < 0)
			neg.back().push(-e);
		else
			pos.back().push(e);
	abs_radix_sort(neg);
	abs_radix_sort(pos);
	for (int i = neg.front().size(); i--; )
		v[i] = -neg.front().front(), neg.front().pop();
	for (int i = v.size() - pos.front().size(); i < (int) v.size(); ++i)
		v[i] = pos.front().front(), pos.front().pop();
}

static void abs_radix_sort(vector<queue<int>>& qvec) {
	int base = 2, n = qvec.back().size();
	while (base * base < n)
		base <<= 1;
	qvec.resize(base);
	vector<int> siz(base);
	int div = 1;
	while ((int) qvec[0].size() < n) {
		for (int i = 0; i < base; ++i)
			siz[i] = qvec[i].size();
		for (int i = 0; i < base; ++i) {
			while (siz[i]--) {
				int val = qvec[i].front(); qvec[i].pop();
				qvec[val / div % base].push(val);
			}
		}
		div *= base;
	}
}
