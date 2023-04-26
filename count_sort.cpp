#include <bits/stdc++.h>
using namespace std;

static void abs_count_sort(vector<int>& v, int max_value);

void count_sort(vector<int>& v) {
	vector<int> neg, pos;
	int neg_max = 0, pos_max = 0;
	for (auto& e : v)
		if (e < 0)
			neg.push_back(neg_max < -e ? neg_max = -e : -e);
		else
			pos.push_back(pos_max < e ? pos_max = e : e);
	abs_count_sort(neg, neg_max);
	abs_count_sort(pos, pos_max);
	for (int i = 0; i < (int) neg.size(); ++i)
		v[i] = -neg.back(), neg.pop_back();
	for (int i = v.size() - pos.size(), j = 0; i < (int) v.size(); ++i, ++j)
		v[i] = pos[j];
}

static void abs_count_sort(vector<int>& v, int max_value) {
	vector<int> cnt(max_value + 1);
	for (auto& e : v)
		++cnt[e];
	for (int i = 0, j = 0; i <= max_value; ++i)
		while (cnt[i]--)
			v[j++] = i;
}
