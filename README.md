# Super-Factorial
A program that calculates and prints the values of factorials till 50000

max_size is defined as 1000000. It is the size of the accumulator array.

int acc[max_size].  It contains the results of the factorials.a[0] contains the one's digit,a[1] contains the ten's digit ..... a[i] contains the 10^i 's digit.

void mult(int n). Multiplies the number n with the acc array digit by digit. Takes the carry to the next digit. And stores the new product in the acc array only.

void fact(int n): It is a recursive function which calls mult(n) and then calls itself as fact(n-1).This function return immediately if n==0.

void set():   This function fills all the positions of the acc array by 0 and sets a[0]=1.This configuration is means that the acc array contains the number 1.And now on the mult() function can be used to multiply numbers in this array.

void display():   This function prints the values of the acc array from the index max_size-1 to 0. This is the exact value of the factorial. This function also prints the number of digits in the result factorial without leading 0s.In the next line the function prints the number of trailing 0s in the factorial.In the last line the function prints the first 10 most siginificant digits of the factorial.


This function is tested to be able to calculate the exact values of factorials of n, where n can be upto 50,000.
To calculate the factorial of 50,000 and print all its digits on the console takes about 3min 50 secs.
