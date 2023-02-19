///Time Complexity O(log(M*N))
///Space Complexity O(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = row*col-1;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(matrix[mid/col][mid%col] == target)
                return true;
            if(matrix[mid/col][mid%col] < target)
                left = mid + 1;
            if(matrix[mid/col][mid%col] > target)
                right = mid - 1;

        }
        return false;
    }
};
