#include<iostream>
using namespace std;
#define max_size 1000000
int acc[max_size];
void mult(int n)
{
    int temp,carry=0;
    for(int i=0;i<max_size;i++)
    {
        temp = n*acc[i] + carry;
        carry = temp/10;
        acc[i] = temp%10;
    }
}
void fact(int n)
{
    if(n==0)
    return;
    mult(n);
    fact(n-1);
}
void set()
{
    for(int i=0;i<max_size;i++)
        acc[i]=0;
    acc[0]=1;
}
void display()
{
    bool start = false;
    int digit,zeroes=0,first[10],index=0;
    for(int i=max_size-1;i>=0;i--)
    {
        if(start==false && acc[i]>0)
        {
            start = true;
            digit= i ;
        }
        if(start)
        {
            cout<<acc[i];
            if(index<10)
            {
                first[index]=acc[i];
                index++;
            }
            if(acc[i]==0)
            {
                zeroes++;
            }
            else
            {
                zeroes=0;
            }
        }
    }
     cout<<'\n';
     cout<<"digits = "<<digit<<'\n';
     cout<<"zeroes = "<<zeroes<<'\n';
     cout<<"first 10 digits are \n";
     for(int i=0;i<10;i++)
     {
         cout<<first[i]<<' ';
     }
     cout<<'\n';  
}
int main()
{
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    set();
    fact(n);
    display();
    return 0;
}