#pragma once
#include <iostream>
#include <string>
#include <vector>

class Review
{
	// Fields - variables for the class (and each object made from the class)



public: // anything above is private and anything below is public
	// Default constructor - special method that lets us create objects from the class
	Review()
	{

	}


	void Line()
	{
		std::cout << "=================================" << std::endl;

	}

	void Message(std::string words)
	{
		Line();
		std::cout << words << std::endl;
		Line();
	}

	// First method of the day with a return type
	// Our parameters do NOT need to match the return type
	// but when we return a value which we will need to when a type is present on a method
	// we must return a value of that type

	int Sum(int number1, int number2)
	{
		// Goal is to return the sum of the parameters
		return number1 + number2;
	}

	// Now we can overload this method - changing the types of the parameters - we'll leave the return type aloen
	int Sum(double number1, double number2)
	{
		// Goal is to return the sum of the parameters
		return number1 + number2;

		// When we call this version of Sum, we can have non whole numbers be passed to the parameters
		// However the returned value will truncate any decimal places off and just return a whole number
		// it won't round either way
	}

	// We could also overload this method by added any parameters - the parameter list for each overloaded method must be different
	int Sum(int number1, int number2, int number3)
	{
		// Goal is to return the sum of the parameters
		return number1 + number2 + number3;

	}


	void DayOne()
	{
		// Declaring Variables
		int wholeNumber;
		std::string words;
		bool choice;
		float notWholeNumber;
		double someTimesCurrency;
		char letter;

		// Pattern: keyword identifier;
		// Creates the variable in memory ready to be used/assigned later

		// Initializing Variables
		int otherNumber = 3; 
		bool flag = true;
		std::string otherWord = "Hello";

		// Pattern: keyword identifier = value; 
		// assigns a value to the variable we create on the same line

		// Defining/Assigning variables
		wholeNumber = 3;
		letter = 'A';
		words = "hello world";

		// pattern: variable = value;
		// Notice no use of the type keyword here

		// output
		std::cout << "Hello and welcome to day 1 review" << std::endl; // outputs to the console

		// input
		std::cin >> otherWord; // allows user to type in to the console

		// Output some variables
		std::cout << "words: " << words << std::endl;
		std::cout << "wholeNumber: " << wholeNumber << std::endl;

		// endl ends the iostream and creates a newline


	}

	void DayTwo()
	{
		std::cout << "Welcome to day 2 review" << std::endl;

		// Errors
		/*
			1) Syntax errors - issue with what you've written is not recognized by the langauge/compiler
			denoted with red squiggle and error list

			2) Run Time errors - no syntax issue, but will crash when running once the line with the issue
			is reached. Typically found when accessing data from collections when that data or index doesn't 
			exist or reading from a file that doesn't exist, or depending on 3rd party source that is broken

			3) Logic errors - no crashing or build errors, however this will lead to behaviour or output that
			doesn't match your intentions. You'll have to find the last "correct" output and start from there
			to find the logic error

			Breakpoints are debugging tools that we can utilize to analyze data from variables or objects
			placed in a column to the left of line numbers and placed on lines with executable code
			When you run the project, your project will halt at each break point. You can use the Step Into button
			(F11) or the blue arrow pointing down button that will apear during run time. This will run the code manually
			and the play button or "Local Windows Debugger" will turn into the "Continue" button.

			when utilizing break points you'll see autos/locals tabs at the bottom left, they'll be 
			broken into three columns, one for the name of the variable/object, the value(s) of it, and the type of it
			when you step into you'll see changes to the values in red text.


		
		
		*/

		// Casting
		/*
			When we think of the different numeric types or things that can be treated as a numeric type
				i.e char

			We can think of them as buckets or boxes whatever analogy words for you
			
			We have...
				short
				int
				long
				float
				double
				and char

				All of these are numeric or can be treated as numeric

				Each of these (mostly in order) have value ranges ranging from -32,000 to some absurdly large number

				If we boil each down into buckets...

				short is a 1 gallon bucket
				int is a 5 gallon bucket
				long is a 10 gallon bucket

				when we cast values we're also attempting to utilize that value in some way, usually in the form
				of assignment

				so if we have a short we can always cast it to an int or a long
				the value range of a short is much smaller than the others
				Same deal when going from int to long

				HOWEVER we can work backwords, long->short, long->int
				long's value range is large, it exceeds that of a short and an int
				we need to be careful when we "Cast down" from long to a smaller type
				Because depending on the value we can make this work just fine or it could "break" the end value

				If you pour a full 10 gallon bucket into a 1 gallon bucket you have 9 gallons of wasted material
				You'll end up with some negative value close to the min range of the target type 
				casting from long to short, say the long has a value of 33999 so 1999 higher than the max range of a short
				Your short value will be around -32000 give or take

				// Next is the style of cast that we want, you have seen static_cast in external materials or even linked materials
				// However in 0.02 Course Overview - pg3 of the study guide specifically calls out not to use static_cast

				What we want and are looking for is a c-style cast
				long someNumber = 32;
				short someSmallNumber = 0;

				someSmallNumber = (short)someNumber;

				variable = (typeOfVariable)someOtherVariable;

		
		
		*/
		long someNumber = 32;
		short someSmallNumber = 0;
		someSmallNumber = (short)someNumber; // We put a break point on this line because we can't see
		// the change without it

		// Also to see a cast example with char
		char letter = 'A';
		int castLetter = (int)letter;

		castLetter = castLetter + 1;

		letter = (char)castLetter; // B



		// Converting
		/*
			Converting is going from any type to string
			or string to a target type

			to_string(someValue); will turn the someValue into a string type
			stoi string to int
			stof string to float
			stod string to double

			
		*/

		std::string number = "33";

		int convertedNumber = stoi(number); // calls the stoi method and it forces a conversion of whatever
		// is in the () for that method to an int, if it can't we get a run time error, if it does we can
		// use a break point or output to see the value;
		// All of the string to methods operate in the same maner
		// just change the type around so if we have stod

		double myConvertedNumber = stod(number);


		// to_string
		// The reason to use the to_string method is because when we output if we're concatenating
		// numeric types it could treat it as addition and give us a logic error
		// it's to ensure everything in the output is typed as a string to prevent this and similar things 
		// from happening
		std::cout << "myConvertedNumber: " << std::to_string(myConvertedNumber) << std::endl;



	}

	void DayThree()
	{
		Message("Welcome to Day 3 Review"); // this calls the Message method and passes in
		// the string literal of Welcome to Day 3 Review

		std::cout << "Starting with the head/signature of a method" << std::endl;
		std::cout << "methods get types just like variables and if one is present we must have a return line in the method itself" << std::endl;
		std::cout << "next is going to be the name of the method then the parameter list" << std::endl;
		std::cout << "int ExampleMethod(int number1)" << std::endl;
		std::cout << "the above is an example of a method head/signature" << std::endl;
		/*
			Now methods when created in a class must be in the class { } and ideally under public keyword
			methods created in something like our demo projects can be put above the main as well
			In this case the DayThree method is apart of the Review class and is publically accessible
			via the review object we created in the FutureOct.cpp file

			We're going to create void Line(), void Message(std::string words), and various Sum methods 
		
		*/
		Line();

		Sum(2, 2); // adds the two arguments passed together 2 and 2 and would return 4
		// however this line doesn't store the returned value anywhere so it gets lost with no way to retrieve it currently
		// This is going to be true for any method that returns a value.

		std::cout << Sum(2, 2) << std::endl;

		// To be able to store the value we'll need a variable of the same type as the return type of the method
		int storedValue = Sum(2, 2); // we initialize an int variable identified a storedValue and set it's value 
		// to the returned value of the Sum method call, where we pass 2 and 2 as arguments

		std::cout << "storedValue: " << storedValue << std::endl;
		
		storedValue = Sum(1, 2, 3); // Calls the second overloaded version of Sum, the one with three int parameters

		std::cout << "storedValue: " << storedValue << std::endl;

		// Call the version of Sum that has 2 double parameters
		storedValue = Sum(2.8, 3.3);

		std::cout << "storedValue: " << storedValue << std::endl;

	}


	void DayFour()
	{

	}

	void DayFive()
	{

	}

	void DaySix()
	{

	}

	void DaySeven()
	{

	}


};

