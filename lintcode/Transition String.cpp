public class Solution {
    /**
     * @param startString:
     * @param endString:
     * @return: Return true or false
     */
    public boolean canTransfer(String startString, String endString) {
        // Write your code here
        int n1 = startString.length();
        int n2 = endString.length();
        if (n1 != n2) {
            return false;
        }

        int[] map = new int[26];
        Arrays.fill(map, -1);
        for (int i = 0; i < n1; i++) {
            int key = startString.charAt(i) - 'a';
            int value = endString.charAt(i) - 'a';
            if (map[key] == -1) {
               map[key] = value;
               continue;
            } else if (map[key] == value) {
                continue;
            } else {
                return false;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (map[i] == i) {
                map[i] = -1;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (map[i] == -1) {
                continue;
            }
            if (isCircle(map, i)) {
                return false;
            }
        }
        return true;
    }


    private boolean isCircle(int[] map, int start) {
        int target = start;
        start = map[start];
        while(start != target) {
            if (start == -1) {
                return false;
            }
            start = map[start];
        }
        return true;
    }

}


