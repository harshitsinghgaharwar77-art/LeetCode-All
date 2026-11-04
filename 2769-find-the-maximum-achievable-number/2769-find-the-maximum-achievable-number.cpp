class Solution {
public:
//num ko +1 karna padta hai.
//x ko -1 karna padta hai.
//num aur x ke beech ka difference har operation mein 2 se decrease
//x = num + 2t
    int theMaximumAchievableX(int num, int t) {
        return num + 2 * t;
    }
};