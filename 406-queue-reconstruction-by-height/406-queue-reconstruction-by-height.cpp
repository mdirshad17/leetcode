class Solution
{
    public:
        vector<vector < int>> reconstructQueue(vector<vector < int>> &people)
        {
            auto compare =[](vector<int> &a, vector<int> &b)
            {
                if (a[1] == b[1]) return a[0] < b[0];
                return a[1] < b[1];
            };
            sort(people.begin(), people.end(), compare);
            int n=people.size();
            for (int i = 1; i < n; i++)
            {
                int cnt = people[i][1];
                int ht = people[i][0];
                if(cnt==0)continue;
                int idx = i;
                int sum = 0;
                for (int j = 0; j < i; j++)
                {
                    sum += (people[j][0] >= ht);
                    if (sum > cnt)
                    {
                        idx = j;
                        break;
                    }
                }
                for(int j=i;j>idx;j--){
                    people[j][0]=people[j-1][0];
                    people[j][1]=people[j-1][1];
                }
                people[idx][0]=ht;
                people[idx][1]=cnt;
                
            }
            return people;
        }
};