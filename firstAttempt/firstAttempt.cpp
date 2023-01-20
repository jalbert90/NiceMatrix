#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll int solve() {
	int n, m;
	ll int ans = 0;
	cin >> n >> m;

	vector<vector<int>> mt(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			mt[i][j] = input;
		}
	}

	for (int i = 0; i < (n + 1) / 2; i++) {
		for (int j = 0; j < (m + 1) / 2; j++) {
			ll int avg = (mt[i][j] + mt[n - i - 1][j] + mt[i][m - j - 1] + mt[n - i - 1][m - j - 1]) / 4;
			ll int absDiffTR = abs(mt[i][m - j - 1] - avg);
			if (absDiffTR != 0) {
				ans += absDiffTR;
			}
			ll int absDiffBL = abs(mt[n - i - 1][j] - avg);
			if (absDiffBL != 0) {
				ans += absDiffBL;
			}
			ll int absDiffBR = abs(mt[n - i - 1][m - j - 1] - avg);
			if (absDiffBR != 0) {
				ans += absDiffBR;
			}
			ll int absDiffTL = abs(mt[i][j] - avg);
			if (absDiffTL != 0) {
				ans += absDiffTL;
			}
		}
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