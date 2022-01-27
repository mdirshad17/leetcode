class Solution {
public:
   class Node
   {
       public:
       Node *left;
       Node *right;
       Node()
       {
           left=NULL;
           right=NULL;
       }
   };
    class Trie
    {
      Node * trie;
        public:
      Trie()
      {
          trie=new Node();
      }
        void insert(int n)
        {
            Node * temp=trie;
            for(int i=31;i>=0;i--)
            {
                int d=(n&(1<<i));
                if(d==0)
                {
                    if(!temp->left)
                    {
                        temp->left=new Node();
                    }
                    temp=temp->left;
                    
                }else
                {
                        if(!temp->right)
                    {
                        temp->right=new Node();
                    }
                    temp=temp->right;
                }
            }
        }
        int max_xor_helper(int n)
        {
            Node * temp=trie;
            int cxor=0;
            for(int i=31;i>=0;i--)
            {
                int d=(n&(1<<i));
                if(d==0)
                {
                   if(temp->right)
                   {
                       cxor+=(1<<i);
                       temp=temp->right;
                   }else temp=temp->left;
                    
                }else
                {
                    if(temp->left)
                   {
                       cxor+=(1<<i);
                       temp=temp->left;
                   }else temp=temp->right;
                }
            }
            return cxor;
        }
        int max_xor(vector<int> & nums)
        {
            int maxans=0;
            for(int x:nums)
            {
                insert(x);
                int ans=max_xor_helper(x);
                maxans=max(maxans,ans);
            }
            return maxans;
        }
    };
    int findMaximumXOR(vector<int>& nums) 
    {
       Trie t;
        int res=t.max_xor(nums);
        return res;
        
    }
};