// #include<iostream>
// using namespace std;

// void Print(int * arr, int m, int n){
//     for(int i = 0; i<m; i++){
//         for(int j = 0; j<n; j++){
//             cout << arr[i*m+j] << " ";
//         }
//         cout << endl;
//     }
// }

// int main(){
//     int arr[3][2] = {1,2,3,4,5,6};
//     Print(arr,3,2);
//     return 0;
// }

#include<stdio.h>

void print3(int *arr, int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", arr[i*row+j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9};
	print3(arr, 3, 3);
	return 0;
}

