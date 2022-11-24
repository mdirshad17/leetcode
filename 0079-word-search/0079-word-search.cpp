class Solution {
public:

    bool solve(vector<vector<char>>& board,string word,int i,int r,int c,int n,int m)
    {
         if(i+1>=(word.size()))
         {  
             return true;
         }
          // cout<<i<<" ";
          board[r][c]='$'; 
        // cout<<word[i]<<" "<<board[r][c]<<endl;
         if((r+1)<n && board[r+1][c]==word[i+1])
         {
            if(solve(board,word,i+1,r+1,c,n,m))
            {
                return true;
            }
         } 
          if((r-1)>=0 && board[r-1][c]==word[i+1])
         {
            if(solve(board,word,i+1,r-1,c,n,m))
            {
                return true;
            }
         }
        if((c+1)<m && board[r][c+1]==word[i+1])
         {
            if(solve(board,word,i+1,r,c+1,n,m))
            {
                return true;
            }
         }
        if((c-1)>=0 && board[r][c-1]==word[i+1])
         {
            if(solve(board,word,i+1,r,c-1,n,m))
            {
                return true;
            }
         }
         board[r][c]=word[i];
        return false;
         
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
     int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solve(board,word,0,i,j,n,m))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};