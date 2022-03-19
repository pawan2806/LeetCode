class Solution
{
    public:
        void setZeroes(vector<vector < int>> &matrix)
        {
            int n = matrix.size();
            int m = matrix[0].size();
            bool check = false;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        check = true;
                        break;
                    }
                }
            }
            if (!check)
            {
                return;
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        int row = i, col = j;
                        for (int a = 0; a < m; a++)
                        {
                            if (matrix[row][a] != 0)
                                matrix[row][a] = -1;
                        }
                        for (int a = 0; a < n; a++)
                        {
                            if (matrix[a][col] != 0)
                                matrix[a][col] = -1;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (matrix[i][j] == 0 || matrix[i][j] == -1)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
};