class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
         int n=board.size();
         int vis[(n*n)+5];
         memset(vis,0,sizeof(vis));
         int maps[(n*n)+5];
         int num=1;
         int f=0;
         for(int i=n-1;i>=0;i--){
             if((f&1)==0){
                //  cout<<"F ";
             for(int j=0;j<n;j++){
                //  cout<<num<<" ";
                 if(board[i][j]==-1){
                     maps[num]=num;
                 }else maps[num]=board[i][j];

                 num++;
             }
             }else{
                //  cout<<"R ";
               for(int j=n-1;j>=0;j--){
                //    cout<<num<<" ";
                 if(board[i][j]==-1){
                     maps[num]=num;
                 }else maps[num]=board[i][j];

                 num++;
             }  
             }
             f=f^1;
            //  cout<<endl;
         }
        //  for(int i=1;i<=n*n;i++){
        //      cout<<maps[i]<<" ";
        //  }cout<<endl;
         memset(vis,0,sizeof(vis));
         vis[1]=1;
         queue<int> q;
         q.push(1);
         int moves=0;
         while(q.size()){
             int ns=q.size();
             while(ns--){
                 int d=q.front();
                //  cout<<d<<" ";
                 if(d==n*n)return moves;
                 q.pop();
                 for(int i=1;i<=6;i++){
                     int num=d+i;
                     if(num>n*n)continue;
                     num=maps[num];
                     if(vis[num])continue;
                     q.push(num);
                     vis[num]=1;

                 }
             }moves++;
            //  cout<<endl;
         } 
         return -1;  
    }
};