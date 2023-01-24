#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll int solve() {
	int n, m;
	ll int ans = 0;
	cin >> n >> m;

	vector<vector<ll int>> mt(n, vector<ll int>(m));
	vector<ll int> list;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ll int input;
			cin >> input;
			mt[i][j] = input;
		}
	}

	for (int i = 0; i < (n + 1) / 2; i++) {
		for (int j = 0; j < (m + 1) / 2; j++) {
			// ll int avg = (ll int)(mt[i][j] + mt[n - i - 1][j] + mt[i][m - j - 1] + mt[n - i - 1][m - j - 1]) / (ll int)4;
			list.push_back(mt[i][j]);
			list.push_back(mt[n - i - 1][j]);
			list.push_back(mt[i][m - j - 1]);
			list.push_back(mt[n - i - 1][m - j - 1]);
			sort(list.begin(), list.end());
			ll int avg = list[1];
			list.clear();
			if (i != n - i - 1 && j != m - j - 1) {
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
			else if (i == n - i - 1 && j != m - j - 1) {
				// top = bottom -- only sum top-left and top-right
				ll int absDiffTL = abs(mt[i][j] - avg);
				if (absDiffTL != 0) {
					ans += absDiffTL;
				}
				ll int absDiffTR = abs(mt[i][m - j - 1] - avg);
				if (absDiffTR != 0) {
					ans += absDiffTR;
				}
			}
			else if (i != n - i - 1 && j == m - j - 1) {
				// left = right -- only sum top-right and bottom-right
				ll int absDiffTR = abs(mt[i][m - j - 1] - avg);
				if (absDiffTR != 0) {
					ans += absDiffTR;
				}
				ll int absDiffBR = abs(mt[n - i - 1][m - j - 1] - avg);
				if (absDiffBR != 0) {
					ans += absDiffBR;
				}
			}
			else {
				// Do nothing?
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