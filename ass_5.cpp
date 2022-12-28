#include<iostream>
using namespace std;
int n;
#define size 10
template<class T>

void sel(T A[size])
{
    int i,j,min;
    T temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
    cout<<"\nSorted Array :";
    for(i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}

int main()
{
    int choice;
    char C[size];
    int A[size];
    float B[size];

    int i;

    cout<<"------------------------";
    do{
    cout<<"\nEnter: \n1.Integer\n2.Float\n3.Exit\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter total number of integers : ";
        cin>>n;
        cout<<"Enter Elements:";
        for(i=0;i<n;i++)
        {
            cin>>A[i];
        }
        sel(A);
        break;
    case 2:
        cout<<"Enter total number of integers : ";
        cin>>n;
        cout<<"Enter Elements:";
        for(i=0;i<n;i++)
        {
            cin>>B[i];
        }
        sel(B);
    case 3:
        cout<<"Exiting the Program !!";
        exit(0);
        break;
    default:
        cout<<"Wrong input";
        break;
    }
    }while(choice!=4);
    return 0;
}