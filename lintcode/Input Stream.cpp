class Solution {
private:
    std::string getFinal(std::string & s) {
        std::string final;
        for(auto c : s) {
            if(c != '<') final += c;
            else {
                if (final.size() > 0) {final.pop_back();}
            }
        }
        return final;
    }
public:
    /**
     * @param inputA: Input stream A
     * @param inputB: Input stream B
     * @return: The answer
     */
    string inputStream(string &inputA, string &inputB) {
        const auto& finalA = getFinal(inputA);
        const auto& finalB = getFinal(inputB);

        return (finalA == finalB ? "YES" : "NO");
    }
};