#include<iostream>
#include<fstream>
using namespace std;
#define max_size 50732
int acc[max_size];
int power = 9,base;
fstream st;
void set_base()
{
    st.open("fact.txt",ios::out);
    base = 1;
    for(int i=0;i<power;i++)
    base*=10;
}
void mult(int n)
{
    long long temp,carry=0;
    for(int i=0;i<max_size;i++)
    {
        temp = 1LL*n*acc[i] + carry;
        carry = temp/base;
        acc[i] = temp%base;
    }
}
void fact(int n)
{
    for(int i=1;i<=n;i++)
    mult(i);
}
void set()
{
    for(int i=0;i<max_size;i++)
        acc[i]=0;
    acc[0]=1;
}
int get_digits(int number)
{
    if(number==0)
    return 1;
    int cnt = 0;
    while(number>0)
    {
        number/=10;
        cnt+=1;
    }
    return cnt;
}
void put_zeroes(int power,int number)
{
    int digits = get_digits(number);
    for(int i=0;i<power-digits;i++)
    st<<0;
}
void display()
{
    int units = 0;
    bool start = false;
    for(int i=max_size-1;i>=0;i--)
    {
        if(start==false && acc[i]>0)
        {
            start = true;
            st<<acc[i];
        }
        else if(start)
        {
            put_zeroes(power,acc[i]);
            st<<acc[i];
        }
        if(start)
        units++;
     } 
     cout<<"total units = "<<units<<"\n";
}
int main()
{
    set_base();
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    set();
    cout<<"acc set\n";
    fact(n);
    cout<<"fact calculated\n";
    display();
    cout<<"saved in file\n";
    st.close();
    cout<<"done\n";
    return 0;
}
