int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int m=gridSize;
    int n=*gridColSize;
    int count=0;
    for(int i=0;i<m;i++)
    {
       for(int j=0;j<n;j++)
       {
        if(grid[i][j]<0)
        {
            count++;
        }
       }
    }
    return count;
}