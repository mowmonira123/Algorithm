#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{

    int n,q,j,i,temp,k;
    int arr[100000];
    printf("Enter the limit : ");
    scanf("%d",&n);

    for(q = 1; q <= n; q++)
    {
        int t=rand()%n;
        arr[q]=t;
        printf("%d",arr[q]);
        printf(" ");

    }
    printf("\n\n");
    // Implementation of insertion sort algorithm
    for(i=2; i<=n; i++)
    {
        temp=arr[i];
        j=i-1;

        while((temp<arr[j])&&(j>0))
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }

    printf("Sorted elements: ");
    for(i=1; i<=n; i++)
        printf(" %d",arr[i]);

    return 0;
}

