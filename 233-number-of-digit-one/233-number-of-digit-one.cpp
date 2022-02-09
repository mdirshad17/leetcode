class Solution {
public:
    int dp[15][3];
int pw[12];
void pws() {
	pw[0] = 1;
	pw[1] = 10;
	for (int i = 2; i < 10; i++) {
		pw[i] = (pw[i - 1] * 10LL);
	}
}
long long  sum[12];
int solve(int s, int n, int c, vector<int> & v) {
	if (s >= n) {
		return 0;
	}
	if (dp[s][c] != -1)return dp[s][c];
	int ans = 0;
	if (c == 1) {
		for (int i = 0; i < v[s]; i++) {
			if (i == 1)ans += pw[n - (s + 1)];
			ans += solve(s + 1, n, 0, v);
		}
		if (v[s] == 1)ans += sum[n - (s + 1)];
		ans += solve(s + 1, n, 1, v);

	} else {
		for (int i = 0; i <= 9; i++) {
			if (i == 1)ans += pw[n - (s + 1)];
			ans += solve(s + 1, n, 0, v);
		}
	}
	return dp[s][c] = ans;
}

    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int> v;
	while (n) {
		v.push_back(n % 10);
		n /= 10;
	}
	pws();
	n = v.size();
	reverse(v.begin(),v.end());
    sum[0] = 1;
	long long  tot = 0;
	long long pw = 1;
	for (int i = n - 1; i >= 0; i--) {
		tot = tot + pw * v[i];
		sum[n - i] = tot + 1;
		pw = pw * 10LL;
	}
        int ans = solve(0, v.size(), 1, v);
	// cout << ans << "\n";
        return ans;
    }
};