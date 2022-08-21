class Solution {
public:
	int match (string & S, string & T, int pos)
	{
		int count = 0;
		for (int i = 0; i < S.size(); i++)
		{
			char c = T[pos + i];
			if (c == '?')
				continue;
			else if (c == S[i])
				count++;
			else
				return -1;
		}
		return count;
	}
	vector<int> movesToStamp(string S, string T) {
		vector<int> res;
		int sz = S.size();
		// S T forward, then backward, store index
		for (int i = 0; i + sz <= T.size(); i++)
		{
			if (match (S, T, i) >= 1)
			{
				fill (T.begin() + i, T.begin() + i + sz, '?');
				res.push_back(i);
			}
		}

		reverse(S.begin(), S.end());
		reverse(T.begin(), T.end());

		for (int i = 0; i + sz <= T.size(); i++)
		{
			if (match (S, T, i) >= 1)
			{
				fill (T.begin() + i, T.begin() + i + sz, '?');
				res.push_back(T.size() - i - sz);
			}
		}

		if (T != string(T.size(), '?'))
			return vector<int>();

		reverse (res.begin(), res.end());
		return res;

	}
};