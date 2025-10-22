#pragma once
#include <iostream>
#include <string>
#include <vector>

class Review
{


	// Fields - variables for the class (and each object made from the class)
	std::string name;
	int number;

	// When we creates fields we can provide values here, but we generally don't. We would provide values
	// to the fields via the constructors or getter/setters methods that would be under the public keyword
	// To see that these are actually private we can go over to FutureOct.cpp and try to use the . operator to see
	// them like we do the day methods


	/*
		Question: Can you do something like, 
		private::code 
		Answer: We would not be able to access private data in another file that way
		However we could if wanted to provide the private keyword
		Should you choose to set the access modifier of each member - field or method you could if you wanted to
		You don't need to do this for c++ anything above public is private and anything below public is public
		In other languages however you may need to do this like in c#

	
		
	*/



public: // anything above is private and anything below is public
	// Default constructor - special method that lets us create objects from the class
	Review()
	{
		// provide some "default" values to our two fields, name and number
		// these values can be wahtever you want
		name = "karl";
		number = 3;
		// Instructions that are given to you will probably have the values the defaults should be
		// but if not present you can make up whatever value you want

	}

	// Overloaded Constructor - this will have parameters - usually a number equal to the fields but it does need to be
	Review(std::string _name, int _number)
	{
		// fields = parameters
		name = _name;
		number = _number;
	}


	// Getters/setters
	// These are methods that wil llet us retrieve the private data or alter the private data

	// Getters will retieve/return data - they'll have a return type that matches the field you're returning
	std::string GetName()
	{
		return name;
	}

	int GetNumber()
	{
		return number;
	}

	// Setters allow us to alter the value - no returns typically - should have a parameter that matches the type of the field
	void SetName(std::string _name)
	{
		// field = parameter
		name = _name;
	}

	void SetNumber(int _number)
	{
		// field = parameter
		number = _number;
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
		Message("Welcome to Day4 Review");


		// We'll get started at roughly 1:15 pm eastern.
		/*
			Question: What is static_cast
			Answer: It is a way to cast types just like what we see in day 2 or the review for day 2
			However it is not permitted for use in this class, as it is explictly stated in the External
			Material use policy.
		*/

		/*
			Operators

			+ addition/concatenation
			- subtraction
			* multiplication
			/ division (quotient)
			% mod/modulo/modulus (division for remainder)

			<< insertion
			>> extraction
			:: scope resolution

			> greater than
			>= greater than or equal to
			< less than
			<= less than or equal to
			!= not equals to
			== is equals to

			++ increment
			-- decrement

			&& logical and - all things must be true for the evaluation to be true
			|| logical or - any thing must be true for the evaluation to be true



			if ladder/structure/tree

			if (condition)
			{
				// Anything in here between the { } of this if would happen
				// if this condition is true.
			}


			if (condition)
			{
				//If the condition for this if is true, this code in this section of { } will happen
				// and the else will be skipped
			}
			else
			{
				// However if the condition of this ladder is not true, the above { } will be skipped
				// and the code in this else will happen
			}

			if (condition)
			{
				// if the condition for this if is true the code in here {} will happen and the else 
				// ifs and the else are skipped
			}
			else if (anotherCondition)
			{
				// if the above condition is false and anotherCondition is true this { } will happen
				// the above if { } will not happen, the below else if with someOtherCondition and the else { } will not happen
			}
			else if (someOtherCondition)
			{
				// if the if (condition) is false, and the else if (anotherCondition) is false and this 
				// else if (someOtherCondition) is true, the above if and else if are skipped
				// this { } happens and the else is skipped
			}
			else
			{
				// if no condition apart of this if ladder is true, the else will happen
			}


			Take note on the structure of these, else is always last, if is always first, else ifs are in the "middle'
			you can also have as many else ifs as you want

			For conditions 
			and will true for the conditions of loops as well 
			>, >=, <, <=, ==, !=, &&, || are the only acceptable operators to use for comparision
			
			the difference between 
			= is the assignment operator - you are attempting to provide a value to a variable with this
			== is equal (comparision) we are checking if two values are the same

			Conditions will break down to true or false - another way of saying this is, they'll evaluate to true or false
		*/

		int number1 = 3;
		int number2 = 5;
		std::string word = "yes";
		bool check = true;
		// Above we initialize a bunch of variables we can use to compare for the series of if statements we'll
		// be writing


		// To start with a basic if statement
		if (number1 == number2) // if number1 is equal to number2
		{
			// We know this to be false so the code I put in here won't run
			Message("won't run");
		}

		if (number1 == 3) // if number1 is equal to 3
		{
			// We know this is true because we made number1 have the value of 3
			Message("This is true");
		}

		if (number1 != 2) // if number1 does not equal 2
		{
			// This is also true
			Message("number1 does not equal 2");
		}

		if (check) // if check == true
		{
			Message("check is true");
		}

		if (check == true) // the above is short hand for this
		{
			Message("check is true");
		}



		// Adding the else statement
		// number1 is 3 number2 is 5, word is yes, and check is true
		if (number1 < 3) // if number1 is less than 3
		{
			// we know this to be false
			Message("We won't be seeing this");
		}
		else
		{
			Message("Because the above condition is false, we see this output");
		}

		// Adding in the else if

		if (check == false) // if check is equal to false
		{
			Message("we know check is true");
		}
		else if (number1 != number2) // else if number1 does not equal number2
		{
			Message("number1 does not equal number2");

		}
		else
		{
			Message("We won't see this because the else if is true");
		}

		/*
			Ternary statement
			Short hand if usually to check simple conditions and assign a value based on the evaluation

			double discount = (condition) ? trueValue : falseValue;

			double discount = (check) ? 3.34 : 5.5;

			Because check is true the value of discount would be 3.34;
		
		*/

		double discount = (check) ? 3.34 : 5.5;
		Message(std::to_string(discount)); // Because Message's parameter is specifically string we have to
		// to_string the variable

		check = false;

		discount = (check) ? 3.34 : 5.5;
		Message(std::to_string(discount));

		// We don't need specifically doubles

		bool flag = (check) ? false : true; // if check is true, flag will be false, if check false, flag will be true
		Message(std::to_string(flag)); // this may output as 1 or true

		std::string words = (check) ? "yes" : "no";
		Message(words);
		/*
			Question: Can we go over the structure for TextCodec for lab7
			Answer: The vast majority of the code needed for TextCodec is given on FSO
			Give me a moment to open that up and download a fresh copy of that lab

			Question: What is the ?
			Answer: It is the ternary operator

			Question: Are we allowed to use inheritance features
			Answer: inheritance is not covered in this course

			Question: What are vectors again?
			Answer: They are a collection of the same "type"
			std::vector<int> myIntVector = {1,2,3};
			Think of a variable as a box
			Think of a vector as a kallax shelf from ikea, each row being a vector
			So we if have a kallax 3x3, it would be we could have 3 values per row


			Question: What does util.con.Write(menu) do
			Answer: Without looking at the actual method it self, looks like it a method that is apart of
			whatever con is, and con is apart of whatever util is
			And it probably writes soemthing out, probably whatever menu is
			If I had to wager a guess this is in one of the utilities files provided to you, feel free to look
			do not touch

			Question: can we use the comparison operators as part of a switch
			Answer: No, we're just checking for specific values with a switch, an if is what you'd want should you want to compare values

			Question: The values int the cases "correspond" to the variable in the switch
			Answer: Yes, the values provided in the case statements are what we are looking for and are comparing 
			against the value of the variable in the switch
			switch(x)
			{
				case 1:
					break;
			}

			that case 1 is effectively 
				if (x == 1)



		
		*/


		/*
			Switch Statements
			Switch statements just like ifs are away to have decision making code, 
			so an if and a switch are decision code constructs

			However unlike an if, switches can only test numeric types, so no strings
			We also can not utilize the comparison operators with a switch

			We are checking for specific values

			switch(someVariable)
			{
				case someValue:
					break; // break being the keyword that halts program flow control
				case someOthervalue:
					break;
				case anotherValue:
					break;
				default: // default being the else of a switch - so the catch all
					break;

			}

		
		*/

		// number1 should have value of 3
		
		number1 = 11;
		switch (number1)
		{
			// We can provide any number of case statements that we want inside of a switch
			// For those that are familar with undertale the video game, at one point maybe even still
			// ALL of the dialog for that game was in one giant switch statement
			// I've never played it or looked at the code so I can't confirm, but this is a thing I've heard
			// So can truly have one LARGE switch should you want

		case 0: // if number1 == 0
			Message("number1 has a value of 0");
			break;
		case 1: // if number1 == 1
			Message("number1 has a value of 1");
			break;
		case 2: // if number1 == 2
			Message("number1 has a value of 2");
			break;
		case 3: // if number1 == 3
			Message("number1 has a value of 3");
			break;
		default: // else
			Message("number1 does not have a value of 0, 1, 2, or 3");
			break;
		}

		// Also notice where I am putting the code that would execute, basically where every Message call is


	}

	void DayFive()
	{
		Message("Welcome to Day5 Review");

		/*
			Difference between for loops and while loops
			Answer: while loops are for when we "don't know" how many times the loop will happen
			Example: We accept user input and validate it in some way, if we ask the user for soemthing
			specific and they don't give us that specific thing, we re-prompt them using a loop until they
			do. There is no way to realistically tell how many times a user will input faulty data

			for loops are for when we do know the "end" of the loop. That might know the exact number because
			this could also be user input, but we do know there is an actual end. Typically going through a collection
			like a vector or array.

			Question: Can I also put how to do duplicates in code.
			Answer: Yes but I'll need more context, as in are we using the same identifier in different
			scopes, are we looking for the error of duplicate entries

			Same name in different scope, gotcha

			Question: I know it's not recommend to use == but it is allowed right?
			Answer: == Yes this is allowed to be used, but not recommended for a for loop
			For loops I would recommend anything from, >, >=, <, <=
		
		*/


		std::string userInput = "";

		std::cout << "Please input a number between 1 and 10 inclusive." << std::endl;
		std::cin >> userInput;

		int convertedNumber = stoi(userInput); 

		// we want 1 through 10, so loop if less than 1 or greater than 10
		while (convertedNumber < 1 || convertedNumber > 10)
		{
			// So this loop happens if the user provides us anything
			// less than 1 and greater than 10

			std::cout << "Invalid input..." << std::endl;
			std::cout << "Please input a number between 1 and 10 inclusive." << std::endl;
			std::cin >> userInput;
			convertedNumber = stoi(userInput);
		}
		Line();

		int start = 0;
		int end = 10;

		// int i = 0;

		for (int i = start; i < end; i++)
		{
			// We have a clear starting point
			// and a clear ending point
			// the condition being i < end. end having a value of 10, i starting at 0
			// and each time this loop cycles/iterates i is increased by 1


			std::cout << "i: " << i << std::endl;
		}

		std::cout << "Please input a whole number greater than 0" << std::endl;
		std::cin >> userInput;
		convertedNumber = stoi(userInput); // we're not going validate that they did put in a value that
		// could convert we're just going to test whole numbers greater than 0

		end = convertedNumber;

		for (int i = start; i < end; i++)
		{
			// Here we have another int i, just like in the above for loop it's just scoped
			// to this for loop, so anything made in the () of the for loop OR the { } of the for loop
			// will be scoped to it. 

			// Above we're not concerned with validating that they input a value that could be converted
			// we're just going to type in a whole number greater than 0 when we test this

			std::cout << "i: " << i << std::endl;

			// As stated above we might not "know" the end of a for loop, but it is going to be based off 
			// of some form of counting (most of the time counting up
		}


		/*
			While loops

			while (condition)
			{
				// should the condition above evaluate to true everything in the { } will happen
				// repeatedly until the conditon evaluates to false

				// This is different from an if statement even though it look extremely similar
				// the difference being ifs happen once, whiles happen repeatedly
			}
		
		
		*/

		// While loop - counting example
		int counter = 0;
		while (counter < 10)
		{
			// Currently without changing the value of counter this loop will be infinite
			// Infinite loops "halt" the flow of your project because it will repeat everything in { } 
			// indefinitely until we close the project and fix the logic error that this is.

			Message(std::to_string(counter));

			// To fix an infinite loop we need to be able to alter a value present in the condition
			// of the loop - that said - we can only alter variables, collections, objects, etc
			// we can not alter - "programatically" a literal value

			// So we would be able to change the value of int literal 10 but we could change the value
			// of counter

			// If we wanted to increase the value by one postively each cycle of the loop
			counter++;
			//counter = counter + 1;
			//counter += 1;

			// All of those lines do the same thing, they alter the value of the variable postively by 1

		}


		// Just like the examples of at the beginning of this method we could make this loop based around
		// user input

		Message("What is the starting point? Whole numbers only");
		std::cin >> userInput;

		convertedNumber = stoi(userInput);

		start = convertedNumber;

		Message("What is the end point? Whole numbers only?");
		std::cin >> userInput;
		convertedNumber = stoi(userInput);

		end = convertedNumber;

		while (start <= end) // to see the inclusion of the end value we would have to change the operator to be <=
		{
			// do something


			// Then again to make this not infinite we would need to alter one of the two values that we can in the condition
			// I recommend always changing the thing on the left, so in this case start, that is not a hard set rule, just what I've 
			// done out of practice

			Message(std::to_string(start));

			start = start + 1;
		}


		/*
			Difference between while and do while

			a while loop which we've seen so far in this review - a while will check it's condition first
			and then if true execute any code in the  { }

			if the while's condition is false we see nothing from the { }

			However a do while loop will always run the { } once, then check the condition, from there if the condition of the do while
			is false we only see it run that one time, however it the condition of the do while is true, we see it repeat
			
			This is handy for cases that we want to see the code at least once, for example the user input where ask for a number 
			between 1 and 10 would have a reduced number of lines if it was a do while loop
		
		*/
		//std::string userInput = "";

		//std::cout << "Please input a number between 1 and 10 inclusive." << std::endl;
		//std::cin >> userInput;

		//int convertedNumber = stoi(userInput);

		//// we want 1 through 10, so loop if less than 1 or greater than 10
		//while (convertedNumber < 1 || convertedNumber > 10)
		//{
		//	// So this loop happens if the user provides us anything
		//	// less than 1 and greater than 10

		//	std::cout << "Invalid input..." << std::endl;
		//	std::cout << "Please input a number between 1 and 10 inclusive." << std::endl;
		//	std::cin >> userInput;
		//	convertedNumber = stoi(userInput);
		//}

		// 9 lines or so

		std::string input = "";
		int convInput = 0;

		do
		{
			std::cout << "Please input a number between 1 and 10 inclusive" << std::endl;
			std::cin >> input;
			convInput = stoi(input);


		} while (convInput < 1 || convInput > 10 );

		/*
			For Loops

			for (statement1;statement2;statement3)
			{
			}

			Primary differences between while and for is that a while loop has 1 statement in its ()
			where a for loop has 3

			While loops are for "when we don't know the end" even if might - example being the above do while
			where the user could provide any number of false values - their input being 0 or less or 11 or higher
			any number of times 

			where for loop is usually when "we do know the end" - we might not necissarily know exactly the end point
			but there is an actual end value
			Generally for collections like arrays or vectors
			Or counting in some fashion, 
		
			statement 1 - initializer - start
			statement 2 - evaluation - condition
			statement 3 - update - steps (how we alter something in the condition)

			for (int i = 0; i < 5; i++)
			{
				Message(std::to_string(i));
			}
		*/

		for (int i = 0; i < 5; i++)
		{
			Message("for loop i: " + std::to_string(i));
		}

		// It's important to note that we don't always need to use < we can use any of the other comparisons, I'd recommend
		// not using ==, != for a for loop
		// And we don't always need to ++ the value we can alter it in any we want

		for (int i = 100; i > 0; i /= 2)
		{
			Message("new for i: " + std::to_string(i));
		}

		for (int i = 2; i < 100; i *= 2)
		{
			Message("multi i: " + std::to_string(i));
		}

		for (int i = 10; i > 0; i--)
		{
			Message("sub i: " + std::to_string(i));
		}
	}

	void DaySix()
	{
		Message("Welcome to Day 6 Review");

		/*
			Collections
			for each loop

			Collections can be thought of as a singular identifier that can contain multiple values of the same type
			There are collections later on that can do values of different types but the two types of collections
			covered in pg1 are arrays and vectors

			Arrays in c++ are non mutable (can't change, for the most part) once they are created
			What I mean by that is their size. When an array is created by us we need to provide a size to it
			And that size can not change
			Also arrays do not have any publically accessible fields or methods like a vector does
			They are a little cumbersome to work with but they have their place

			Vectors in c++ are mutable (they can change on the fly very easily) when we create a vector we do not need
			to provide a size but we can, and we even go past that size with speficic methods like push_back or providing a new size
			to the vector. Unlike arrays vectors have a ton of publically accesssible fields and methods. The two that we the most
			are going to be .size() and push_back()

			the size method will return the total number of items (elements) inside of the vector
			and push_back will append a new item (element) as the new last item (element) in the vector
		
		*/

		// Declaring Arrays
		int myIntArr[3]; 
		std::string myStrArr[3];
		bool myBoolArr[3];

		// We can have an array of any type

		// If we wanted to see example of declaring an array with values
		short myShortArr[3] = { 1,2,3 }; 
		long myLongArr[3] = { 123 }; // we provide size and a single value here, even though the array has a size of 3
		// We can provide any number of values as long as it does not exceed the size provided

		int size = 5;

		// double myDoubleArr[size];
		// Can not declare an array with the size from a variable

		// Now to access those variables either for assignment or output

		myIntArr[0] = 123;
		myIntArr[1] = 234;
		myIntArr[2] = 345;

		// Note that all collections the first item/element is at position 0
		// So the myIntArr has a size of 3, index 0 is the first element, index 1 is the second element, and index 2 is the third element

		Message("myIntArr[0]: " + std::to_string(myIntArr[0]));
		Message("myIntArr[1]: " + std::to_string(myIntArr[1]));
		Message("myIntArr[2]: " + std::to_string(myIntArr[2]));

		// However say we have a collection that is absurdly large say 1000 elements - and we want to output them all
		// there's no reason to have 1000 extra lines to output everything in the collection

		// Unfortunately for arrays we don't have any publically accessible method like a vector does with .size()
		// We just have to know the size of the array - for context in this class every array given will also show
		// example data, just count the values
		// There is an equation that you can look later to get the size of the array it self - however it is not needed
		// For the array we're working with it has a size of 3

		// To loop through the array the long way
		for (int i = 0; i < 3; i++)
		{
			std::cout << "myIntArr[" << i << "]: " << myIntArr[i] << std::endl;
		}

		// Now for a for each loop
		// The difference between the use of either a regular for loop or a for each loop is if the position matters to you
		// In the above example i is the variable that we use as the position or index

		// in a for each loop we don't utilize the normal structure of a for loop with the three statements
		/*
			for (type name : theCollection)
			{

			}

			we want the type of the variable to match the type of the collection

			for (int number : myIntArr)
			{

			}

			this will loop from start to end and have a number of iterations equal to the size collection
			even though we don't have a publically accessible way to get the size, the for each will know on execution


		
		*/

		for (int number : myIntArr)
		{
			std::cout << "number: " << number << std::endl;
		}
		

		// We don't always need to output the values stored in a collection we can alter them with the loop as well

		for (int i = 0; i < 3; i++)
		{
			// Prompt the user for a value
			std::cout << "Please input a whole number" << std::endl;
			std::string userInput = "";
			std::cin >> userInput;
			int number = stoi(userInput);
			myIntArr[i] = number;

		}

		for (int number : myIntArr)
		{
			std::cout << "number: " << number << std::endl;
		}

		// Now for vectors
		// We can do everything that we've done for arrays for vectors, they share all of that

		// The only difference in those shared things is the declaration of the vector and the way we loop through a vector
		// For creating the vector we do not need to provide size like we do with an array
		std::vector<int> myIntVector;

		// Like the array we can a vector of any type we want
		std::vector<std::string> myStrVector(3); // we provide size here if we want note the () instead of []
		std::vector<short> myShortVector = { 1,2,34 }; // has a size of 3 by default even though we aren't providing
		// a size with (). We provided three values, so far size is 3

		// Looks like we can't provide values on the same line we provide size on for a vector

		// Now to assign or access values
		// Because myIntVector does not have a size provided we have no elements or index's to output or assign so we'll get that
		// later on with push_back

		// myStrVector has a size of 3 so just like the arrays
		myStrVector[0] = "Hello";
		myStrVector[1] = " ";
		myStrVector[2] = "world!";

		std::cout << "myStrVector[0]: " << myStrVector[0] << std::endl;
		std::cout << "myStrVector[1]: " << myStrVector[1] << std::endl;
		std::cout << "myStrVector[2]: " << myStrVector[2] << std::endl;

		// Now unlike arrays, as stated above vectors have a .size() method, this will always return the number
		// of elements or items in the vector itself so myStrVector will return 3 when we call the size() method from it
		std::cout << "size of myStrVector: " << myStrVector.size() << std::endl;

		// loop a vector pretty easily
		for (int i = 0; i < myStrVector.size(); i++)
		{
			std::cout << "myStrVector[" << i << "]: " << myStrVector[i] << std::endl;
		}

		// And also like a array we can utilize the for each loop

		for (std::string word : myStrVector)
		{
			std::cout << "word: " << word << std::endl;
		}


		



	}

	void DaySeven()
	{
		Message("Welcome to Day 7 Review");
		Message("We've actually been doing day 7 review to a point this entire time");
		/*
			We actually started with a bit of day 7 review
			We created this file to house the different Day methods for our review
			And in the main we included this file at the top with #include "Review.h" which you'll see in the
			FutureOct.cpp file or whatever file your main is in

			Things we haven't covered with this class is going to be members, fields like that
			For the extensive version of that look for the game demo examples in discord

			// What we'er going to start with is going to the very top above the public keyword and creating
			any number of fields we want
		
		*/
	}


};

