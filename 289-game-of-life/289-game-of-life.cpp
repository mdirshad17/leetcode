class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
       int n=board.size();
        int m=board[0].size();
        int xdir[]={-1,1,0,0,1,-1,-1,1};
        int ydir[]={0,0,-1,1,1,-1,1,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==1)
                {
                     int count=0;
                    for(int l=0;l<8;l++)
                    {
                        if(i+xdir[l]<n && j+ydir[l]<m && i+xdir[l]>=0 && j+ydir[l]>=0 )
                        {
                            if(board[i+xdir[l]][j+ydir[l]]>0)
                            {
                                count++;
                            }
                        }
                    }
                    if(count<2||count>3)
                    {
                        board[i][j]=2;
                    }
                    
                }else
                {
                   int count=0;
                    for(int l=0;l<8;l++)
                    {
                        if((i+xdir[l])<n && (j+ydir[l])<m && i+xdir[l]>=0 && j+ydir[l]>=0)
                        {
                            if(board[i+xdir[l]][j+ydir[l]]>0)
                            {
                                count++;
                            }
                        }
                    }
                    if(count==3)
                    {
                        board[i][j]=-1;
                    }
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==2)
                {
                    board[i][j]=0;
                }else if(board[i][j]==-1)
                {
                    board[i][j]=1;
                }
            }
        }
        
    }
};