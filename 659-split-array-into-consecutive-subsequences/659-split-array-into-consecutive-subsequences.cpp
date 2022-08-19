class Solution
{
    public:
        bool isPossible(vector<int> &nums)
        {
            int n = nums.size();
            map<int, int> freq;
            map<int, int> end;
            for (int i = 0; i < n; i++)
            {
                freq[nums[i]]++;
            }
            for(int i=0;i<n;i++){
                int x=nums[i];
                if(freq[x]==0)continue;
                if(end[x-1]){
                    end[x-1]--;
                    freq[x]--;
                    end[x]++;
                }else{
                    if(freq[x+1] && freq[x+2]){
                        freq[x]--;
                        freq[x+1]--;
                        freq[x+2]--;
                        end[x+2]++;
                    }else {
                        // cout<<x<<" \n";
                        return 0;
                    }
                }
            }
            return 1;
            
            return 1;
        }
};