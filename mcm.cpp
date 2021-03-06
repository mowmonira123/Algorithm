#include<iostream>
#include<climits>
using namespace std;

int matrixChain(int n, int order[])
{
    int i,j,k;
    int tempValue;

    int dp[n+1][n+1];

    //dp[i][j] denotes the minimum number of multiplication operations required to compute the matrix chain product of chain of matrix i to matrix j

    //initialization
    //No multiplication operations will be done if the chain consists of a single matrix
    for(i=1;i<=n;i++)
    {
        dp[i][i]=0;
    }

    //first we will calculate min. operations for a all chains of size of 2, then for all chains of size 3 and finally for the original chain ie., of size n
    for(int size=2;size<=n;size++)
    {
        //i is the first matrix of the chain
        for(i=1;i<=(n-size+1);i++)
        {
            //j is the first matrix of the chain
            j=i+size-1;

            //now, calculate the min. multiplications required to compute product of the chain with matrices i, i+1,...,j
            //First initialize the result to infinity and then replace if lesser results are obtained
            dp[i][j]=INT_MAX;

            //now, divide the chain of matrices i....j into two sub-chains i...k and k+1...j and use the already computed results of these sub-chains to compute the result of original chain
            for(k=i;k<j;k++)
            {
                tempValue=dp[i][k]+dp[k+1][j]+order[i-1]*order[k]*order[j];

                //if tempValue is lesser than the current value of dp[i][j], replace it
                if(tempValue<dp[i][j])
                {
                    dp[i][j]=tempValue;
                }
            }

        }

    }

    //return the min. multiplication operations for the original matrix
    return dp[1][n];

}

int main()
{
    int i,j;
    int n;

    cout<<"Enter the number of matrices in the chain(greater than 1)  ";
    cin>>n;

    int order[n+1];

    //order of matrix i will be given by order[i-1]*order[i]
    cout<<"Enter the order array of the matrix chain ("<<n+1<<" elements)"<<endl;
    for(i=0;i<=n;i++)
    {
        cin>>order[i];
    }

    cout<<"The minimum number of multiplication operations required to multiply the matrix chain is "<<matrixChain(n,order);

    cout<<endl;
    return 0;
}
