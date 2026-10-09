
class Solution {
    public String simplifyPath(String path) {
        Deque<String> st = new ArrayDeque<>();
        String[] parts = path.split("/");

        for (String p : parts) {
            if (p.isEmpty() || p.equals(".") || (p.equals("..") && st.isEmpty())) {
                // ignore
                continue;
            }

            if (p.equals("..") && !st.isEmpty()) {
                st.pop();
            } else {
                st.push(p);
            }
        }

        if (st.isEmpty()) {
            // iska mtlb root dir pe hu
            return "/";
        } else {
            // agr stack empty nahi hai toh answer build krlo stringBuilder se
            StringBuilder sb = new StringBuilder();

            while (!st.isEmpty()) {
                sb.append("/");
                sb.append(st.pollLast());
            }

            return sb.toString();
        }
    }
}