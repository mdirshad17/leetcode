class Solution
{
public:
#define ll long long
	int numberOfArithmeticSlices(vector<int> &nums)
	{
		int n = nums.size();
		map<pair<int, ll>, ll> mp;
		int ans = 0;
		for (ll i = 1; i < n; i++)
		{
			for (ll j = i - 1; j >= 0; j--)
			{
				ll diff = nums[i] * 1LL - nums[j] * 1LL;
				ll len =mp.count({j,diff})?mp[{j, diff}]:0;
				ans = ans + len;
				mp[{i, diff}] += 1 + len;
			}
		}
		return ans;
	}
};