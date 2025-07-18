class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        int n=hand.length;
        int m=groupSize;
        if((n%m)!=0) return false;
        Arrays.sort(hand);
        Map<Integer,Integer> mp=new HashMap<>();
        for(int i=0;i<n;i++){
            mp.putIfAbsent(hand[i],0);
            mp.put(hand[i],mp.get(hand[i])+1);
        }

        for(int i=0;i<n;i++){
            if(mp.get(hand[i])==0){
                // Already part of something
                // hand[i]=-1;
                continue;
            }else{
                for(int j=hand[i];j<hand[i]+m;j++){
                    if(!mp.containsKey(j)||mp.get(j)==0){
                        // we couldn't find its list
                        return false;
                    }
                    mp.put(j,mp.get(j)-1);
                    // hand[i]=-1;
                }
            }

        }
        // for(int i=0;i<n;i++){
        //     if(mp.get(hand[i])!=0) return false;
        // }
        return true;

    }
}