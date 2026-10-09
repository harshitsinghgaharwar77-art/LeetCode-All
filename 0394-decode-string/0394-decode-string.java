
import java.util.*;

class Solution {
    public String decodeString(String s) {
        Deque<Integer> countStack = new ArrayDeque<>();
        Deque<StringBuilder> stringStack = new ArrayDeque<>();
        int number = 0;
        StringBuilder curr = new StringBuilder();

        for (char ch : s.toCharArray()) {
            // case 1: digit
            if (Character.isDigit(ch)) {
                number = number * 10 + (ch - '0');
            }
            else if (ch == '[') { // case 2
                countStack.push(number);
                stringStack.push(curr);

                // Initialise a new string
                number = 0;
                curr = new StringBuilder();
            }
            else if (ch == ']') { // case 3
                int repeatCnt = countStack.pop();
                StringBuilder prev = stringStack.pop();

                // Append curr repeatCnt times
                for (int i = 1; i <= repeatCnt; i++) {
                    prev.append(curr);
                }

                // Update current string
                curr = prev;
            }
            else {
                // case 4: alphabet
                curr.append(ch);
            }
        }

        return curr.toString();
    }
}