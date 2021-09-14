#include <iostream>
#include <stdio.h>

using namespace std;

void out(double **a,int m, int n)
{
    int i, j;
    double b=0.0;
    for(i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            a[i][j] = b;
            b += 1.2;
            printf("%5.1f",a[i][j]);
        }
        std::cout << std::endl;
    }   

}

void Print(int ** arr, int m, int n){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int i, j, m=2, n=3;
    int **a;
    
    a = new int*[m];
    for (i=0; i<m; i++)
        a[i] = new int[n];

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = i+j;
        }
    }
    
    Print(a,m,n);

    return 1;
}