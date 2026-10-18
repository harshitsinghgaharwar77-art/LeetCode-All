class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        // find the first event that starts after or st the smae time of {start, end}
        auto it = st.lower_bound({startTime, endTime});
        // check if he current event overlaps with the next event
        if(it != st.end() && it -> first < endTime){
            return false;
        }
        // check if the current event overlaps with the previous event
        if(it != st.begin()){
            auto prevIt = prev(it);
            if(startTime < prevIt -> second){
                return false;
            }
        }
        st.insert({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */