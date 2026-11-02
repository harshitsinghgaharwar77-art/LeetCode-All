class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int row = coordinates[1] - '1';
        int col = coordinates[0] - 'a';
        // har odd pe black hai aur even pe white
        if(((row+col) & 1) == 0) return false;
        else return true;
    }
};