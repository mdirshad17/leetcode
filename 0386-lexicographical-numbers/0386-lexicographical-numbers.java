class Solution {
    List<Integer> res;
    void solve(int n,int sum){
        if(sum>n) return;
        if(sum!=0){
            res.add(sum);
        }
        // int val=(sum=)
        for(int i=(sum==0?1:0);i<=9;i++){
             solve(n,(sum*10)+i);   
        }
    }
    public List<Integer> lexicalOrder(int n) {
        res=new ArrayList<>();
        solve(n,0);
        return res;
    }
}