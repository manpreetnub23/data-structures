#include<iostream>
using namespace std;
void print(int arr[],int n)
{
    cout<<"Array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void bubblesort(int arr[],int n)
{
    cout<<"sorted ";
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        print(arr,n);
        cout<<"\n";
    }
}
int main()
{
    int *arr,n;
    cout<<"how many elements are there in the Array.\n";
    cin>>n;
    arr=new int[n];
    cout<<"what are the elements of the Array.\n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    print(arr,n);
    cout<<"\n";
    bubblesort(arr,n);
}