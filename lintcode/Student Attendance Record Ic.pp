class Solution {
public:
    /**
     * @param s: a string
     * @return: whether the student could be rewarded according to his attendance record
     */
    bool checkRecord(string &s) {
        int aCount = 0;
        int lCount = 0;

        bool reward = true;
        int size = s.size();
        for(int i = 0; i < size; ++i) {
            if(s[i] == 'A') {
                if(++aCount > 1) {
                    reward = false;
                    break;
                }
            } else if (s[i] == 'L') {
                if(++lCount > 2) {
                    int continuousCount = 1;
                    if(i > 0 && s[i-1] == 'L') {
                        ++continuousCount;
                        if(i > 1 && s[i-2] == 'L') ++continuousCount;
                    }

                    if(i < size && s[i+1] == 'L') {
                        ++continuousCount;
                        if(i < size - 1 && s[i+2] == 'L') ++continuousCount;
                    }
                    if(continuousCount > 2) {
                        reward = false;
                        break;
                    }
                }
            }
        }

        return reward;
    }
};