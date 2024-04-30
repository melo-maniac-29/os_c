#!/bin/sh
echo "Enter a number "
read a
i=1
f=1
while [ $i -le $a ]
do
 f=$((f*i))
 i=$((i+1))
 done
 echo "Factorial: " $f
 
<< comment
1. Shebang Line (#!/bin/sh):

This line specifies that the script should be run using the /bin/sh interpreter, a common Bourne shell interpreter.
2. User Input:

The script prompts the user to enter a number using echo and read commands. The user's input is stored in the variable a.
3. Initialization:

Two variables, i and f, are initialized.
i is set to 1. It will act as a counter in the loop.
f is set to 1. It will store the factorial calculation.
4. While Loop:

The script uses a while loop to calculate the factorial. The loop continues as long as the value of i is less than or equal to the value of a.
Inside the loop:
The current value of f is multiplied by the current value of i and the result is stored back in f. This is how the factorial is calculated incrementally.
The value of i is incremented by 1.
5. Printing the Result:

Once the loop finishes iterating, the script prints "Factorial: " followed by the final value of f, which holds the calculated factorial.
In summary, this script prompts the user for a number, calculates its factorial using a while loop, and then displays the result.

Here's an example of how to use the script:

$ ./factorial.sh
Enter a number 
5
Factorial: 120
comment
