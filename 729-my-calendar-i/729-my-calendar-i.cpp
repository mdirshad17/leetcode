class MyCalendar
{
    public:
#define vi vector < int>
        vi st;
    vi en;
    MyCalendar()
    {
        st.clear();
        en.clear();
    }

    bool book(int start, int end)
    {
        end--;
        for (int i = 0; i < st.size(); i++)
        {
            if(end<st[i]||start>en[i])continue;
            return 0;
        }
        st.push_back(start);
        en.push_back(end);
        return 1;
    }
};

/**
 *Your MyCalendar object will be instantiated and called as such:
 *MyCalendar* obj = new MyCalendar();
 *bool param_1 = obj->book(start,end);
 */