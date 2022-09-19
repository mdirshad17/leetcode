class Solution
{
    public:
        vector<vector < string>> findDuplicate(vector<string> &P)
        {

            vector<vector < string>> R;
            int n = P.size();
            map<string, vector < string>> M;
            for (int i = 0; i < n; i++)
            {

                string D;
                int f = 0;
                string file;
                for (int j = 0; j < P[i].size(); j++)
                {
                    if (!f)
                    {
                        if (P[i][j] == ' ')
                        {
                            D.push_back('/');
                        }
                        else if (P[i][j] == '(')
                        {
                            f = 1;
                        }
                        else D.push_back(P[i][j]);
                    }
                    else
                    {
                        if (P[i][j] == ')')
                        {
                            // cout<<file<<" \n";
                            M[file].push_back(D);
                            while(D.size() && D.back()!='/'){
                             D.pop_back();
                             f=0;   
                            }
                            D.pop_back();
                            file = "";
                        }
                        else if (P[i][j] == '(')
                        {
                            continue;
                        }else file.push_back(P[i][j]);
                    }
                }
            }
            for (auto x: M)
            {
                if(x.second.size()>1){
                R.push_back(x.second);
                }
            }
            return R;
        }
};