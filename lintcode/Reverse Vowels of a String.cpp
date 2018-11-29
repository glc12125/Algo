class Solution {
public:
    /**
     * @param s: a string
     * @return: reverse only the vowels of a string
     */
    string reverseVowels(string &s) {
        int front = 0;
        int end = s.size() - 1;
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        bool frontMatch = false;
        bool endMatch = false;
        while(front < end) {
            if(vowels.count(s[front]) == 0) ++front;
            else frontMatch = true;

            if(vowels.count(s[end]) == 0) --end;
            else endMatch = true;

            if(frontMatch && endMatch) {
                int temp = s[front];
                s[front] = s[end];
                s[end] = temp;
                frontMatch = false;
                endMatch = false;
                ++front;
                --end;
            }
        }

        return s;
    }
};