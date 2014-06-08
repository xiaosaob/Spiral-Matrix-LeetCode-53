// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int m = matrix.size();
        if(!m) return res;
        int n = matrix[0].size();
        if(!n) return res;
        int top = 0, bottom = m-1, left = 0, right = n-1;
        while(true) {
            for(int i = left; i <= right; ++i)
                res.push_back(matrix[top][i]);
            if(++top > bottom) break;
            for(int i = top; i <= bottom; ++i)
                res.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; --i)
                res.push_back(matrix[bottom][i]);
            if(--bottom < top) break;
            for(int i = bottom; i >= top; --i)
                res.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return res;
    }
};
