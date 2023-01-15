#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll int solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> mt(n, vector<int>(m));
	vector<int> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			mt[i][j] = input;
			l.push_back(input);
		}
	}

	sort(l.begin(), l.end());

	int midIndex = (n * m) / 2;
	int midNum = l[midIndex];
	ll int ans = 0;

	for (int i = 0; i < n * m; i++) {
		ans += abs(l[i] - midNum);
	}

	return ans;
}

int main() {
	int t;
	cin >> t;

	for (;t--;) {
		cout << solve() << endl;
	}
}