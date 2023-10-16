class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        int currElems = 2;
        while (rowIndex--) {
            vector<int> newRes(currElems);
            newRes[0] = 1; newRes[currElems - 1] = 1;
            for (int i = 1; i < currElems - 1; i++) {
                newRes[i] = res[i - 1] + res[i];
            }
            res = newRes;
            currElems++;
        }
        return res;
    }
};