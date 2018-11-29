class Solution {
public:
    /**
     * @param Byte:
     * @return: return the answer after flipped
     */
    vector<vector<int>> flippedByte(vector<vector<int>> &Byte) {
        // Write your code here
        int height = Byte.size(), width = Byte[0].size();
        for(int row = 0; row < height; ++row) {
            for(int col = 0; col < width / 2; ++col) {
                int temp1 = Byte[row][col], temp2 = Byte[row][width-1-col];
                Byte[row][col] = (temp2 + 1) % 2;
                Byte[row][width-1-col] = (temp1 + 1) % 2;
            }
            if(width % 2) Byte[row][width/2] = (1 + Byte[row][width/2]) % 2;
        }
        return Byte;
    }
};