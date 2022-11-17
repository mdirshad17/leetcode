class Solution
{
    public:
        int calc(int a, int b, int c, int d)
        {
            int len = abs(c - a);
            int brd = abs(d - b);
            return (len *brd);
        }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area1 = calc(ax1, ay1, ax2, ay2);
        int area2 = calc(bx1, by1, bx2, by2);
        int xx=min(ax2,bx2)-max(ax1,bx1);
        xx=max(xx,0);
        int yy=min(ay2,by2)-max(by1,ay1);
        yy=max(yy,0);
        return (area1+area2-(xx*yy));
        
    }
};