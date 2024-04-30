#!/bin/sh
echo "Enter two numbers "
read a
read b
echo "Enter 1 to add , 2 to subract , 3 to multiply , 4 to divide"
read c
case $c in
1)
	s=$((a+b))
	echo "Result = " $s
	;;
	
2)
	s=$((a-b))
	echo "Result = " $s
	;;
3)
	s=$((a*b))
	echo "Result = " $s
	;;
4) 
	s=$((a/b))
	echo "Result = " $s
	;;
*)
	echo "Invalid "
esac

<< comment

Shebang Line (#! /bin/sh):

The first line #!/bin/sh is called a shebang line. It tells the system that this script should be executed using the /bin/sh interpreter, which is a common Bourne shell interpreter.
Taking User Input:

The script then prompts the user to enter two numbers using the echo and read commands. The echo command is used to display a message to the user, and the read command is used to store the user's input in the variables a and b.
Prompting for Operation:

Next, the script prompts the user to enter a number (1, 2, 3, or 4) to indicate the desired operation (addition, subtraction, multiplication, or division) using echo and read commands again. The user's input is stored in the variable c.
Performing Calculations using Case Statement:

The script uses a case statement to perform different calculations based on the value of the variable c.
If c is 1, the script adds the values of a and b and stores the result in the variable s. Then, it prints the result using the echo command.
If c is 2, the script subtracts the value of b from the value of a and stores the result in the variable s. Then, it prints the result using the echo command.
If c is 3, the script multiplies the values of a and b and stores the result in the variable s. Then, it prints the result using the echo command.
If c is 4, the script divides the value of a by the value of b and stores the result in the variable s. Then, it prints the result using the echo command.
If c is any other value, the script prints an "Invalid" message using the echo command.
In summary, this shell script is a simple calculator that can perform addition, subtraction, multiplication, and division of two user-provided numbers.

Here's an example of how to use the script:

$ ./calculator.sh
Enter two numbers 
5
3
Enter 1 to add , 2 to subract , 3 to multiply , 4 to divide
2
Result = 2
comment

