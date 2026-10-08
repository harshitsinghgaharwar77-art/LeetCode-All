class Solution {

    public int minSwaps(String s) {

        // // TC O(n)      SC O(n)

        // Stack<Character> st = new Stack<>();

        // for(char ch : s.toCharArray()){

        //     // cancel out logic

        //     if(ch == ']' && !st.isEmpty() && st.peek() == '['){

        //         st.pop();

        //     }

        //     else{

        //         // push krne ka logic

        //         st.push(ch);

        //     }
        // }

        // // count open and close brackets

        // int open = 0;

        // int close = 0;

        // while(!st.isEmpty()){

        //     if(st.peek() == '['){

        //         open++;

        //     }else{

        //         close++;

        //     }

        //     st.pop();

        // }

        // // find the total number of swaps

        // return (open + 1) / 2;

        // find the total number of reversal as per the formula we discovered

        // even

        // if(open % 2 == 0){
        //
        //     return (open/2) + (close/2);
        //
        // }else{
        //
        //     return (close-1)/2 + 2 + (open-1)/2;
        //
        // }

        // TC O(n)      space optimised O(1)

        // odd len wala case

        if(s.length() == 1) return -1;

int open = 0, close = 0;

for(char ch : s.toCharArray()){

    // cancel out logic

    if(ch == ']' && open > 0) open--;

    else{

        if(ch == '[')open++;

        else if(ch == ']') close++;

    }

}

// find the total number of swaps

return (open + 1) / 2;

    }

}