class Solution {
private:
    std::string rotate(const std::string& num) {
        int size = num.size();
        std::string upDown(size, '0');
        for(int i = 0; i < size; ++i) {
            auto c = num[i];
            if(c == '2' || c == '3' || c == '4' || c == '5' || c == '7') return "";
            else if (c == '1' || c == '8' || c == '0') upDown[size-i-1] = c;
            else if (c == '6') upDown[size-i-1] = '9';
            else if (c == '9') upDown[size-i-1] = '6';
        }
        return upDown;
    }    
public:
    /**
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        const auto& upDown = rotate(num);
        if(upDown == "") return false;
        else return num == upDown;
    }
};