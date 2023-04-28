#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>& v) {
	int seq = 1, n = v.size();
	vector<vector<int>> vv(2);
	vv[0] = std::move(v);
	vv[1].resize(vv[0].size());
	while ((1 << (seq - 1)) < n) {
		int cur = 0, unit = 1 << seq, half = unit >> 1;
		while (cur < n) {
			int i = cur, l = cur, r = cur + half;
			int ll = min(r, n), rr = min(cur + unit, n);
			while (l < ll || r < rr)
				if (l < ll && r < rr)
					vv[seq & 1][i++] = (vv[!(seq & 1)][l] < vv[!(seq & 1)][r] ? vv[!(seq & 1)][l++] : vv[!(seq & 1)][r++]);
				else if (l < ll)
					vv[seq & 1][i++] = vv[!(seq & 1)][l++];
				else
					vv[seq & 1][i++] = vv[!(seq & 1)][r++];
			cur += unit;
		}
		++seq;
	}
	v = std::move(vv[!(seq & 1)]);
}
