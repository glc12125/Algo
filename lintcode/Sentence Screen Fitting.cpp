class Solution {
public:
    /**
     * @param sentence: a list of string
     * @param rows: an integer
     * @param cols: an integer
     * @return: return an integer, denote times the given sentence can be fitted on the screen
     */
    int wordsTyping(vector<string> &sentence, int rows, int cols) {
        int sentenceNum = sentence.size();

        int i = 0;
        int count = 0;
        int sentenceIndex = 0;
        while(i < rows) {
            if(i > 0 && sentenceIndex == 0) {
                int completeRowSize = i;
                int multiple = count;
                while(i + completeRowSize < rows) {
                    i += completeRowSize;
                    count += multiple;
                }
            }
            int j = 0;
            while(j + sentence[sentenceIndex].size() <= cols) {
                j += sentence[sentenceIndex].size() + 1;
                ++sentenceIndex;
                if(sentenceIndex == sentenceNum) {
                    sentenceIndex = 0;
                    ++count;
                }
            }
            ++i;
        }
        return count;
    }
};