
class SORTracker {
public:
    struct compare {
        // worse location comes first in pq_top
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    struct compare2 {
        // better location comes first in pq_other
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq_top;

    priority_queue<pair<int, string>, vector<pair<int, string>>, compare2> pq_other;

    SORTracker() {
        
    }
    
    void add(string name, int score) {
        pair<int, string> p = {score,name};
        pq_other.push(p);

        if(!pq_top.empty() && compare2()(pq_top.top(), pq_other.top())){
            auto it = pq_other.top();
            pq_other.pop();

            pq_top.push(it);

            // move the worst selected location back
            pq_other.push(pq_top.top());
            pq_top.pop();
        }
    }
    
    string get() {
        auto it = pq_other.top();
        pq_other.pop();

        pq_top.push(it);

        return it.second;
    }
};
