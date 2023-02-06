Last cell in a Matrix
Easy

Matrix

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        int d = 1, i = 0,j =0;
        if(matrix[i][j]==1)
                d++,matrix[i][j] = 0;
        while(i>=0 && j>=0 && i<R && j<C)
        {
            if(d==0) i--;
            else if(d==1) j++;
            else if(d==2) i++;
            else j--;
            
            if(i>=0 && j>=0 && i<R && j<C && matrix[i][j]==1)
                d++,matrix[i][j] = 0;
            d%=4;
        }
        if(d==0) i++;
        else if(d==1) j--;
        else if(d==2) i--;
        else j++;
        return {i,j};
        
    }
};