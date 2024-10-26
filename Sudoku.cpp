#include<iostream>
using namespace std;

#define n 9


void print(int arr[n][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool safe(int arr[n][n],int row,int col,int num){
	for(int i=0;i<n;i++){
		if(arr[row][i]==num){
			return false;
		}
	}
	
	for(int i=0;i<n;i++){
		if(arr[i][col]==num){
			return false;
		}
	}
	
	int strtrow=row - row%3;
	int strtcol=col - col % 3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(arr[i+strtrow][j+strtcol] == num){
				return false;
			}
		}
	}
	
	return true;
}


bool solveSudoku(int arr[n][n], int row, int col){
	if(row==n-1 && col==n){
		return true;
	}
	
	if(col==n){
		row++;
		col=0;
	}
	
	if(arr[row][col]>0){
		return solveSudoku(arr, row, col + 1);
	}
	
	for(int num=1;num<=n;num++){
		if(safe(arr,row,col,num)){
			arr[row][col]=num;
			
			if (solveSudoku(arr, row, col + 1))
                return true;
		}
		arr[row][col]=0;
	}
	return false;
}

int main(){
int arr[n][n] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
                       
                       
cout<<"Given question: "<<endl;
print(arr);
cout<<endl;
cout<<endl;                       
if (solveSudoku(arr, 0, 0)){
	cout<<"Solution: "<<endl;
    print(arr);
}
else
    cout << "no solution  exists " << endl;

return 0;
}