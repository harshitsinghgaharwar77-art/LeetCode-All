
import java.util.*;

class BrowserHistory {
    Deque<String> currHistory;
    Deque<String> forwardHistory;

    public BrowserHistory(String homepage) {
        currHistory = new ArrayDeque<>();
        forwardHistory = new ArrayDeque<>(); // O(1)
        currHistory.push(homepage);
    }

    public void visit(String url) {
        // visit karo and forward history clean karo
        currHistory.push(url);
        // while(!forwardHistory.isEmpty()){
        //     forwardHistory.pop();
        // }
        forwardHistory = new ArrayDeque<>(); // O(1)
    }

    public String back(int steps) {
        // homepage se back nhi karunga, rest back krrte raho
        while(steps > 0){
            steps--;
            if(currHistory.size() > 1){
                // mai back kr sakta hu
                String curr = currHistory.pop();
                forwardHistory.push(curr);
            }
            else{
                // mai back nhi kar sakta hu
                break;
            }
        }
        return currHistory.peek();
    }

    public String forward(int steps) {
        // agar forward history mein tab toh forward karunga wrna nhi karunga
        while(steps > 0){
            steps--;
            if(forwardHistory.size() > 0){
                String forwardTab = forwardHistory.pop();
                currHistory.push(forwardTab);
            }else{
                // forwardHistory mein koyi nhi hai forward jane ke liye
                break;
            }
        }
        return currHistory.peek();
    }
}
