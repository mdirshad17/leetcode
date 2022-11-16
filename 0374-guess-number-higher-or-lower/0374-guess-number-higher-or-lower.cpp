/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    #define ll long long 
    int guessNumber(int n) {
        ll l=1,r=n;
        while(l<=r){
            ll mid=(l+r)/2;
            int gs=guess(mid);
            if(gs==0)return mid;
            if(gs==-1){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
    }
};