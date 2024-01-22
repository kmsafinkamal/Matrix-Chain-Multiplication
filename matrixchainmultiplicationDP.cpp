//Matrix Chain Multiplication using DP

#include<bits/stdc++.h>
using namespace std;
int dp[100][100];

void Parenthesis(int i, int j, int n, int *bracket, char &name)
{

    if (i == j)
    {
        cout << name++;
        return;
    }

    cout << "(";

    // Recursively put brackets around subexpression

    Parenthesis(i, *((bracket+i*n)+j), n, bracket, name); //*((bracket+i*n)+j) means bracket[i][j]

    Parenthesis(*((bracket+i*n)+j) + 1, j, n, bracket, name);
    cout << ")";
}

int matrixChain(int p[], int n)
{

    int bracket[n][n];//stores optimal break point in

    for (int i=1; i<n; i++)
        dp[i][i] = 0;  // cost is zero when multiplying one matrix.

    for (int x=2; x<n; x++)
    {
        for (int i=1; i<n-x+1; i++)
        {
            int j = i+x-1;
            dp[i][j] = INT_MAX;
            for (int k=i; k < j; k++)
            {
                int q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < dp[i][j])
                {
                    dp[i][j] = q;

                    bracket[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    cout << "Output: \n";
    cout << "parameterization is : ";
    Parenthesis(1, n-1, n, (int *)bracket, name);
    cout << "\n";

    return dp[1][n-1];
}

int main()
{
    int n,x,y,z=0;

    cout<<"Enter number of matrix ";
    cin>>y;

    x=y*2;//there will be 2 values (row and column) for each matrix

    int ar[x];//to store row and column

    cout<<"Enter number of Row and column\n";
    for(int i=1;i<=x;i++){
        cin>>ar[i];//putting row and column in ar[] array
    }

    n=y+1;
    int arr[n];

    //to put the row number of every matrix and
    // column number of last matrix for calculation purpose
    for(int i=1;i<=x;i++)
        {
        if(i%2!=0 || i==x){
        arr[z]=ar[i];
        z++;
        }
    }
    cout << "Minimum number of arithmetic operations is "
         <<matrixChain(arr, n);
    return 0;
}



