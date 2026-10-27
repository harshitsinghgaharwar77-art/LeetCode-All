
import java.util.*;

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Deque<Integer> st = new ArrayDeque<>();

        for(int ast : asteroids){
            if(ast >= 0) st.push(ast);
            else{
                // ast < 0
                // there may be 2 cases
                // directly insert kardo stack me, no additional check
                // additional check needed value compare, explode

                boolean destroyed = false;

                while(!st.isEmpty() && st.peek() > 0){
                    // collision hoga

                    if(st.peek() < -ast){
                        // st.peek wala asteroid explode hojayega
                        st.pop();
                    }
                    else if(st.peek() == -ast){
                        // dono asteroid explode ho jayenge
                        st.pop();
                        destroyed = true;
                        break;
                    }
                    else{
                        // ast destroyed hojayega
                        destroyed = true;
                        break;
                    }
                }

                if(destroyed == false) st.push(ast);
            }
        }

        // mere stack mein ans pade hue hai
        int[] ans = new int[st.size()];

        for(int i = st.size()-1; i >= 0; i--){
            ans[i] = st.pop();
        }

        return ans;
    }
}
