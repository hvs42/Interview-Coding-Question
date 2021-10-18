#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    
    bool safe(int grid[N][N],int n,int row,int col)
    {
        int i,j;
        
        for(i=0;i<N;i++)
        {
            if(grid[i][col]==n || grid[row][i]==n)
            {
                return false;
            }
        }
        
        
        int s=sqrt(N);
        int br=row-row%s;
        int bc=col-col%s;
        
        for(i=0;i<s;i++)
        {
            for(j=0;j<s;j++)
            {
                if(grid[i+br][j+bc]==n)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        int i,j,n;
        
        for(i=0;i<N;i++)
        {
            bool isempty=false;
             
            for(j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                {
                    isempty=true;
                    
                    break;
                }
            }
            
            if(isempty)
            break;
        }
        
        if(i==N && j==N)
        {
            return true;
        }
        
        for(n=1;n<=N;n++)
        {
            if(safe(grid,n,i,j))
            {
                grid[i][j]=n;
                
                if(SolveSudoku(grid))
                {
                    return true;
                }
                
                grid[i][j]=0;
            }
        }
        
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        int i,j;
        
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
