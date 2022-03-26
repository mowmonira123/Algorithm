#include<stdio.h>
#include <stdlib.h>

int main()
{

    int n,q,j,i,temp,k,count1=0,count2=0;
    int arr[100000],arr2[100000],arr3[100000];
    printf("Enter the limit : ");
    scanf("%d",&n);

    for(q = 1; q <= n; q++)
    {
        int t=rand();
        arr[q]=t;
        arr2[q]=t;
        arr3[q]=t;
        printf("%d",arr[q]);
        printf(" ");

    }
    printf("\n\n");
    //insertion sort algorithm
    for(i=2; i<=n; i++)
    {
        temp=arr[i];
        j=i-1;

        while((temp<arr[j])&&(j>0))
        {
            arr[j+1]=arr[j];
            j=j-1;
            count1++;
        }
        arr[j+1]=temp;
    }
    printf("total operation : %d\n\n",count1);


    printf("Sorted elements: ");
    for(i=1; i<=n; i++){
        printf(" %d",arr[i]);
    }
    printf("\n\n");

   mergeSort(arr2, 1, n);

    printf("\nSorted array: \n");
    printArray(arr, n);
    return 0;
}

void mergeSort(int a[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a, p, q, r);
    }
}
 void merge(int A[], int p, int q, int r)
{
    // Create L ← A[p..q] and M ← A[q+1..r] */
    int n1 = q - p + 1;
    int n2 =  r - q;

    int L[n1], M[n2];
    for (int i = 1; i <= n1; i++)
        L[i] = A[p + i];
    for (int j = 1; j <=n2; j++)
        M[j] = A[q + 1 + j];

    /* Maintain current index of sub-arrays and main array */
    int i, j, k, C=0;
    i = 0;
    j = 0;
    k = p;
    /* Until we reach either end of either L or M, pick larger among elements L and M and place them in the correct position at A[p..r] */
   while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            A[k] = L[i];
            i++;
            C++;
        }
        else
        {
            A[k] = M[j];
            j++;
            C++;
        }
        k++;
    }

    /* When we run out of elements in either L or M, pick up the remaining elements and put in A[p..r] */
   while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
        C++;
    }

    while (j < n2)
    {
        A[k] = M[j];
        j++;
        k++;
        C++;
    }
  printf("%d \n\n",C);
}

// function to merge the subarrays
/*void merge(int a[], int p, int q, int r)
{
    int b[5];   //same size of a[]
    int i, j, k;
    k = 0;
    i = p;
    j = q + 1;
    while(i <= q && j <= r)
    {
        if(a[i] < a[j])
        {
            b[k++] = a[i++];    // same as b[k]=a[i]; k++; i++;
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    while(i <= q)
    {
        b[k++] = a[i++];
    }

    while(j <= r)
    {
        b[k++] = a[j++];
    }

    for(i=r; i >= p; i--)
    {
        a[i] = b[--k];  // copying back the sorted list to a[]
    }
}*/

// function to print the array
void printArray(int a[], int size)
{
    int i;
    for (i=1; i <=size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}



