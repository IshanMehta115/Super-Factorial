# Super-Factorial
## A program that calculates and prints the values of factorials till 100,000 😲😲😲

max_size is defined as 50732. It is the size of the accumulator array.

int power : power = max number of digits allowed in one element of accumulator array.

int base : base = 10^power , it is the base in which the final and intermediate factorial results are represented.

int acc[max_size].  It contains the final and intermediate results of the factorials.

If we have to store a number x in the accumulator array , then we first represent it in the base defined above. That is x = base^n * an + base^(n-1) * a(n-1) ..... base^0 * a0

Then the accumulator value at index i is simply ai from the above expression. Doing this helps reduce the max_size of the accumulator array by 9 times (because each element now contains 9 times more digits).

void mult(int n). Multiplies the number n with the acc array digit by digit. Takes the carry to the next digit. And stores the new product in the acc array only.

void fact(int n): This function has a loop running from i = 1 to n , in each iteration it calls mult(i) which multiplies i to the accumulator array.

void set():   This function fills all the positions of the acc array by 0 and sets a[0]=1.This configuration is means that the acc array contains the number 1.And now on the mult() function can be used to multiply numbers in this array.

void display():   This function stores the values of the acc array from the index max_size-1 to 0 in a file fact.txt. This is the exact value of the factorial.

## Addition information is also printed on the console.

1. acc set : It means that the main accumulator is initialised.

2. fact calculated : It means that the value of the factorial is calculated and stored in the accumulator array.

3. total units = x : Here x means the number of elements of the accumulator array of size max_size which are actually used.

4. saved in file : It means the factorial value is saved in fact.txt

5. done : All steps completed and program ends successfully.


This function is tested to be able to calculate the exact values of factorials of n, where n can be upto 100,000.
To calculate the factorial of 100,000 and stores all its digits in the file fact.txt in takes about a minute.
