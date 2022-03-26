#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int arr[1000],n,l,r;

int partition1(int l,int r)
{
    int pivot=arr[l];
    int i=l;
    int j=r;
    if(l != r){

        while(1)
        {
            while(arr[i]< pivot){
                i++;
            }


            while(arr[j]>pivot){
                j--;
            }


            if(i<j){
                swap(arr[i],arr[j]);
            }

            else{
                swap(pivot,arr[j]);
                return j;
            }
        }
    }
}

void quicksort(int l,int r)
{
    int p;
    if(l<r)
    {
        p=partition1(l,r);

        quicksort(l,p);
        quicksort(p+1,r);
    }
}

int main()
{
    int s;
    cin>>s;


    for(int i=0; i<s; i++)
    {

        arr[i] = rand()%100;

    }
    for(int i=0; i<s; i++)
    {

        cout<<arr[i]<<" ";

    }
    cout<<endl;
    quicksort(0,s-1);
    for(int i=0; i<s; i++)
    {

        cout<<arr[i]<<" ";

    }

    return 0;

}
