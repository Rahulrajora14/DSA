#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int ans =0;
bool canwego(int i, int j ,int n, int m,vector<vector<int>> & grid){
    if(i>=0 && j>=0 && i<n && j<n && grid[i][j]==0){
        return true;

    }
}

    void paths(int i , int j , int n, int m,vector<vector<int>>&grid){
        if(i==n-1 && j==m-1){
            ans = ans+1;
            return;
        }

        grid[i][j]=2;
        if(canwego(i,j-1,n,m,grid)){
            paths(i,j-1,n,m,grid)):
        }
        if(canwego(i-1,j,n,m,grid)){
            paths(i-1,j,n,m,grid);
        }
        if(canwego(i,j+1,n,m,grid)){
            paths(i,j+1,n,m,grid);
        }
        if(canwego(i+1,j,n,m,grid)){
            paths(i+1,j,n,m,grid);
        }
        grid[i][j]= 0;

    }

int ratinmaze(vector<vector<int>>&grid){
    int n = grid.size();
    int m = grid[0].size();
    paths(0,0,n,m,grid);
    return ans;
}
int main(){
    vector<vector<int>>grid = {{0,0,0},
                                {0,1,0},
                                {0,0,0}};
    cout<<ratinmaze(grid);

    return 0;
}