#include<bits/stdc++.h>
using namespace std;

void mergekor(int *arr,int low,int hi)
{
    int mid = (low+hi)/2;
    int len1 = mid-low+1;
    int len2 = hi-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayindex =low;
    for(int i=0;i<len1;i++)
    {
        first[i] = arr[mainArrayindex++];
    }
     mainArrayindex =mid+1;
    for(int i=0;i<len2;i++)
    {
        second[i] = arr[mainArrayindex++];
    }

    //merge 2 sorted array
    int index1 =0;
    int index2=0;
    mainArrayindex = low;
    while(index1<len1 && index2<len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainArrayindex++] = first[index1++];
        }
        else{
            arr[mainArrayindex++] = second[index2++];
        }
    }

    while(index1<len1)
    {
        arr[mainArrayindex++] = first[index1++];
    }
     while(index2<len2)
    {
        arr[mainArrayindex++] = second[index2++];
    }
}

void mergesort(int *arr,int low,int hi)
{

    if(low>=hi)
        return;
    int mid =(low+hi)/2;
    //left side theke pathachi
    mergesort(arr,low,mid);

    //right side theke pathachi
    mergesort(arr,mid+1,hi);

    // ekdm last e merge kora lgbe to

    mergekor(arr,low,hi);


}

int main()
{

    int arr[5] = {5,4,3,2,1};
    int n=5;
    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
