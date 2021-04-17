#pragma once
#include "Others.h"

//[[0,1,1,1,0,1],[0,0,0,0,0,1],[0,0,1,0,0,1],[1,1,0,1,1,0],[1,0,0,1,0,0]]
Array2D numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
{
    // Use Prefix Sum
    int result = 0;
    int mtxSize = matrix.size();
    // Anchor point
    for(int i = 0; i < mtxSize; ++i) // y
    {
        for(int j = 0; j < mtxSize; ++j) // x
        {
            // Sub mtx size
            vector<vector<int>> sub;
            sub.resize(mtxSize - i);
            for(auto& vec : sub)
                vec.resize(mtxSize - j);
            sub[0][0] = matrix[i][j];
            cout << sub[0][0] << " | ";
            
            for(int y = 1; y < mtxSize - i; ++y) // y
                {
                sub[y][0] = sub[y-1][0] + matrix[i+y][j];
                    cout << "y=" << y << "|";
                    cout << sub[y-1][0] << " + " << matrix[i+y][j] << endl;
                }
            for(int x = 1; x < mtxSize - j; ++x) // x
                {
                    sub[0][x] = sub[0][x-1] + matrix[i][j+x];
                    cout << "x=" << x << "|";
                    cout << sub[0][x-1] << " + " << matrix[i][j+x] << endl;
                }
            
            for(int y = 1; y < mtxSize - i; ++y) // y
                for(int x = 1; x < mtxSize - j; ++x) // x
                {
                    sub[y][x] = sub[y - 1][x] + sub[y][x - 1]
                        - sub[y - 1][x - 1] + matrix[i+y][j+x];
                    cout << "x=" << x;
                    cout << "y=" << y;
                    cout << sub[y - 1][x] << " + " << sub[y][x - 1] << " - " << sub[y - 1][x - 1] << " + " << matrix[i+y][j+x] << endl;
                }
                        
            for(int y = 0; y < mtxSize - i; ++y) // y
                for(int x = 0; x < mtxSize - j; ++x) // x
                {
                    cout << sub[y][x] << endl;
                    if(sub[y][x]==target)
                        result++;
                }
            cout << "==" << endl;
        }
    }
    return result;
}

int main()
{
    //std::vector<std::vector<int>> a{{-1,1},{1,-1}};
    std::vector<std::vector<int>> a{{0,1,0},{1,1,1},{0,1,0}};
    //std::vector<std::vector<int>> a{{0,1,1,1,0,1},{0,0,0,0,0,1},{0,0,1,0,0,1},{1,1,0,1,1,0},{1,0,0,1,0,0}};
    
    cout << "final: " << numSubmatrixSumTarget(a,0);

    return 0;
}
