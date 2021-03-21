#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix);
private:
    vector<vector<int> > zeroPair;
};

/* 
* 解法一：看错题目了，以为只是上下左右变化，其实是整行整列都变化
* 1.遍历原数组，如果遇到0，查看上下左右。
*    1.1.如果上下左右是0，保持他们是零不变。
*    1.2.如果上下左右是1，将他们变成INT_MAX.
*    1.3.如果上下左右是INT_MAX，说明之这里是1，后来变成了INT_MAX，这次就不再变化了。
* 2.遍历原数组，如果遇到1，直接跳过，不进行处理。
* 3.遍历原数组，如果遇到3，说明之前这里是1，他的上下左右有0，但是这次不进行处理。
* 解法一：修改为把需要修改的行和列保存起来，后面一个大循环统一进行修改。
*/
void Solution::setZeroes(vector<vector<int> >& matrix) 
{
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return; /* invalid input */
    }

    for (int row = 0; row < matrix.size(); ++row) {
        for (int column = 0; column < matrix[0].size(); ++column) {
            if (matrix[row][column] == 0) {
                zeroPair.push_back({row, column});
            }
        }
    }

    for (int num = 0; num < zeroPair.size(); ++num) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            matrix[zeroPair[num][0]][j] = 0;
        }
        for (int i = 0; i < matrix.size(); ++i) {
            matrix[i][zeroPair[num][1]] = 0;
        }
    }
}


int main()
{
    vector<vector<int> > matrix = 
        {{0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}};
    Solution sul;
    sul.setZeroes(matrix);
    // double result = sul.myPow(2.00, -2);
    // cout << result << endl;
	return 0;
}

