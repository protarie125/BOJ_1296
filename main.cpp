#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

using pls = pair<ll, string>;

class Comp {
public:
	bool operator()(const pls& l, const pls& r) {
		if (l.first != r.first) {
			return l.first < r.first;
		}

		return r.second < l.second;
	}
};

using PQ = priority_queue<pls, vector<pls>, Comp>;

ll foo(ll l, ll o, ll v, ll e) {
	const auto x = vl{ l + o, l + v, l + e, o + v, o + e, v + e };
	auto ret = ll{ 1 };
	for (const auto& v : x) {
		ret *= v;
		ret %= 100;
	}

	return ret;
}

vl countLove(const string& s) {
	auto l0 = ll{ 0 };
	auto o0 = ll{ 0 };
	auto v0 = ll{ 0 };
	auto e0 = ll{ 0 };
	for (const auto& c : s) {
		if ('L' == c) {
			++l0;
		}

		if ('O' == c) {
			++o0;
		}

		if ('V' == c) {
			++v0;
		}

		if ('E' == c) {
			++e0;
		}
	}

	return vl{ l0, o0, v0, e0 };
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string y;
	cin >> y;

	const auto y0 = countLove(y);

	int n;
	cin >> n;

	PQ q;
	for (auto i = 0; i < n; ++i) {
		string s;
		cin >> s;
		const auto s0 = countLove(s);

		q.push({ foo(y0[0] + s0[0], y0[1] + s0[1], y0[2] + s0[2], y0[3] + s0[3]), s });
	}

	const auto& [val, str] = q.top();
	cout << str;

	return 0;
}