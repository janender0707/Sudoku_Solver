#include<iostream>
#include<math.h>
using namespace std;

bool canwesolve(int mat[][9],int i,int j,int n,int number)
{
    for(int x=0;x<n;x++){
        if(mat[x][j]==number || mat[i][x]==number){
            return false;
        }
    }

    int sqr = sqrt(n);
    int sx=(i/sqr)*sqr;
    int sy=(j/sqr)*sqr;

    for(int x=sx;x<sx+sqr;x++){
        for(int y=sy;y<sy+sqr;y++){
            if(mat[x][y]==number){
                return false;
            }
        }
    }
    return true;
}

bool solvesudoku(int mat[][9],int i,int j,int n)
{
    //base cases
    if(i==n){
            //print
            for(int i=0;i<n;i++){
                for(j=0;j<n;j++){
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }
        return true;
    }

    if(j==n){
        return solvesudoku(mat,i+1,0,n);//j is to be made 0 in the next row
    }

    if(mat[i][j]!=0){
        return solvesudoku(mat,i,j+1,n);
    }

    for(int number=1;number<=n;number++){
        if(canwesolve(mat,i,j,n,number)){
            mat[i][j]=number;
            bool nextnumber = solvesudoku(mat,i,j+1,n);
            if(nextnumber==true){ //say you are at j=1, when j+1 fn() runs, if statement continues and
                                  //if j+1 value fits true in its position(it doesn't return false from base cases)
                                  // then we return true and continue for next iteration
            return true;
            }
        }
    }
    //backtracking
    mat[i][j]=0;
    return false;

}

int main()
{
    int mat[9][9] = {
                {5,3,0,0,7,0,0,0,0},
                {6,0,0,1,9,5,0,0,0},
                {0,9,8,0,0,0,0,6,0},
                {8,0,0,0,6,0,0,0,3},
                {4,0,0,8,0,3,0,0,1},
                {7,0,0,0,2,0,0,0,6},
                {0,6,0,0,0,0,2,8,0},
                {0,0,0,4,1,9,0,0,5},
                {0,0,0,0,8,0,0,7,9},
    };
    int n=9;
    solvesudoku(mat,0,0,n);


    return 0;
}
