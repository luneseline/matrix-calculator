#include <iostream>
using namespace std;
//addition function to add two matrices
void add(int row1,int column1,int matrix1[50][50],int matrix2[50][50],int result[50][50]){
    for(int i=0;i<row1;i++){
        for(int j=0;j<column1;j++){
            result[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }

}
//sub function to subtract two matrices
void sub(int row1,int column1,int matrix1[50][50],int matrix2[50][50],int result[50][50]){
    for(int i=0;i<row1;i++){
        for(int j=0;j<column1;j++){
            result[i][j]=matrix1[i][j]-matrix2[i][j];
        }
    }

}
//mul function to multiply two matrices
void mul(int row1,int column1,int column2,int matrix1[50][50],int matrix2[50][50],int result[50][50]){
//initialising result matrix
    for(int i=0;i<row1;i++){
        for(int j=0;j<column2;j++){
            result[i][j]=0;
        }
    }

    for(int i=0;i<row1;i++){
        for(int j=0;j<column2;j++){
            for(int k=0;k<column1;k++){
                result[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }

}
// trans function to calculate transpose of both the matrix
void trans(int matrix[50][50],int result[50][50],int row,int col){
     for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result[j][i] = matrix[i][j];
}
//display function to display a matrix
void display(int matrix[50][50],int row,int column){
    for(int i=0;i<row;++i){
        for(int j=0;j<column;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}



int main(){
    //initializing matrix 1
    int row1,column1;
    cout<<"enter number of rows in matrix 1 ";
    cin>>row1;
    cout<<"enter number of columns in matrix 1 ";
    cin>>column1;
    int matrix1[50][50];
    //inputting data of matrix 1
    for(int i=0;i<row1;i++){
        cout<<"enter elements of row "<<i+1<<" ";
        for(int j=0;j<column1;j++){
            cin>>matrix1[i][j];
            
        }
    }
    //displaying matrix 1
    cout<<"the first matrix is "<<endl;
    for(int i=0;i<row1;i++){
        for(int j=0;j<column1;j++){
            cout<<matrix1[i][j]<<' ';
        }
        cout<<endl;
    }
      
    
    // initializing matrix 2
    int row2,column2;
    cout<<"enter number of rows in matrix 2 ";
    cin>>row2;
    cout<<"enter number of columns in matrix 2 ";
    cin>>column2;
    int matrix2[50][50];
    //imputting data for matrix 2
    for(int i=0;i<row2;i++){
        cout<<"enter elements of row"<<i+1<<" ";
        for(int j=0;j<column2;j++){
            cin>>matrix2[i][j];
            
        }
    }
    //displaying matrix 2
    cout<<"the second matrix is "<<endl;
    for(int i=0;i<row2;i++){
        for(int j=0;j<column2;j++){
            cout<<matrix2[i][j]<<' ';
        }
        cout<<endl;
    }
    int choice;
    //displaying menu
    cout<<"enter operation \n 1. addition \n 2. subtraction \n 3. multiplication \n 4. transpose of a matrix  ";
    cin>>choice;
    int result[50][50];

    switch(choice)
    {
        case 1 :
        if(row1==row2&&column1==column2){
            add(row1,column1,matrix1,matrix2,result);
            display(result,row1,column1);
        }
        else
        cout<<"error no of rows and columns of both matrix should be equal";
        break;

        case 2:
        if(row1==row2&&column1==column2){
            sub(row1,column1,matrix1,matrix2,result);
            display(result,row1,column1);
        }
        else
        cout<<"error no. of rows and columns of both matrix should be equal";
        break;

        case 3:
        if(column1==row2){
            mul(row1,column1,column2,matrix1,matrix2,result);
            display(result,row1,column2);
        }
        else
        cout<<"error no. of column in matrix 1 and no of rows in matrix 2 should be equal";
        break;

        case 4:
        cout<<"transpose of matrix1"<<endl;
        trans(matrix1,result,row1,column1);
        display(result,row1,column1);
        cout<<"transpose of matrix2"<<endl;
        trans(matrix2,result,row2,column2);
        display(result,row2,column2);
        break;

        default:
        cout<<"incorrect choice";


    }

   return 0; 


}
