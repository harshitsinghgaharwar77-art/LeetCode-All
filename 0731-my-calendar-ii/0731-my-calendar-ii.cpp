class MyCalendarTwo {
public:
    vector<pair<int, int>> doubleBooking;
    vector<pair<int, int>> overAllbookings;

    bool checkOverlap(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }
    pair<int, int> findOverlappedregion(int start1, int end1, int start2,
                                        int end2) {
        return {max(start1, start2), min(end1, end2)};
    }
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        // check if triple booking is created or not
        for (pair<int, int> booking : doubleBooking) {
            if (checkOverlap(booking.first, booking.second, startTime,
                             endTime)) {
                return false; // tripple booking is craeted
            }
        }
        // check if it is creating double booking
        for (pair<int, int> booking : overAllbookings) {
            if (checkOverlap(booking.first, booking.second, startTime,
                             endTime)) {
                doubleBooking.push_back(findOverlappedregion(
                    booking.first, booking.second, startTime, endTime));
            }
        }

        overAllbookings.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */