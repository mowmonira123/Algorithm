#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<time.h>
using namespace std;
vector<int>array,arr;

int main()
{

   long long int n,q,first,last,middle,j,i,a,temp,k;
   clock_t starttime = clock();

    //srand(time(0));
    cout<<"Enter the limit: ";
    cin>>n;
    /*long long int array[n];*/
    for(q = 0; q < n; q++)
    {
        int temp=(rand()%n);
        array.push_back(temp);
        arr.push_back(temp);
    }
    cout<<"set_1 :{";
    for(q=0;q<n;q++)
    {
        cout<<array[q]<<" ";
    }
    cout<<"}"<<endl<<endl;
    for(i=0; i<n; i++)
    {

        for(j=i+1; j<n; j++)
        {
            if(arr[i] == arr[j])
            {
                /* Delete the current duplicate element */
                for(k=j; k<n; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
            }

            else if(arr[i] > arr[j])
            {
                temp     = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }

    }
   cout<<"Elements of array in ascending order: "<<endl;
    for(i=0; i<n; i++)
    {
       cout<< arr[i]<<" ";
    }
    cout<<endl<<endl;
    //srand (time(NULL));

    a=rand() % n;
    cout<<"Search value: "<<a<<endl;
    cout<<"Linear search ";

    for (q = 0; q < n; q++)
    {
        if (array[q] == a)
        {
            cout<<a<<" is present at location "<<q+1<<endl;
             clock_t endtime = clock();
        double t= (double)(endtime - starttime)/CLOCKS_PER_SEC;
        double tn= t*1000000000;
       cout<<"time (s): "<<t<<endl;
       cout<<"time (ns): "<<tn<<endl<<endl;
            break;
        }
    }
    /*if (q == n){
        cout<<a<<" isn't present in the array "<<endl<<endl;
    }*/

    cout<<"For binary search "<<endl;
    first = 0;
    last = n - 1;
    middle = (first+last)/2;

    while (first <= last)
    {
        if (arr[middle] < a)
            first = middle + 1;\
        else if (arr[middle] == a)
        {
            cout<<a<<" found at location "<<middle+1<<endl;
             clock_t endtime = clock();
        double t= (double)(endtime - starttime)/CLOCKS_PER_SEC;
        double tn= t*1000000000;
       cout<<"time (s): "<<t<<endl;
       cout<<"time (ns): "<<tn<<endl;
            break;
        }
        else
            last = middle - 1;

        middle = (first + last)/2;
    }
    if (first > last)
        cout<<"Not found! isn't present in the list "<<a<<endl;



}
