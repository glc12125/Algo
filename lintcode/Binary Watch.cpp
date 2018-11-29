class Solution {
private:
    int checkOnes(int num) {
        int one = 1;
        int count = 0;
        while(num) {
            if(num & one) {
                ++count;
            }
            num = num >> 1;
        }
        return count;
    }
public:
    /**
     * @param num: the number of "1"s on a given timetable
     * @return: all possible time
     */
    vector<string> binaryTime(int num) {
        // For hour
        // 1: 1 - 8
        // 2: 3 - 10
        // 3: 1
        // 1: 32 (100000) 6 width most
        // 2: 32 + 16 (48)(110000)
        // 3: 32 + 16 + 8 (56) (111010)
        // 4: 32 + 16 + 8 + 2 (58) (111010)
        // 5: 32 + 16 + 8 + 2 + 1 (59) (111011)
        // >= 6

        vector<string> result;

        for(int i = 0; i < 12; ++i) {
            int hourOnes = checkOnes(i);
            if(hourOnes > num) continue;

            string candidate = to_string(i) + ':';
            int onesLeft = num - hourOnes;

            for(int j = 0; j < 60; ++j) {
                if(checkOnes(j) == onesLeft) {
                    string timeAnswer = candidate;
                    if(j < 10) {
                        timeAnswer += '0';
                    }
                    timeAnswer += to_string(j);
                    result.emplace_back(timeAnswer);
                }
            }
        }

        return result;
    }
};