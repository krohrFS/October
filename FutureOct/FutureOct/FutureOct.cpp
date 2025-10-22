#include <iostream>
#include <fstream> // allows us to write and read to text files
#include <string> // allows use of getline
#include <vector>
#include "Review.h" // allows us to use the Review class in this file



void MidtermMenuExample()
{

    /*
    Midterm Menu example
        Access menu option without it constantly looping through the menu

        // Going to make something similar but not exact

    // Create a vector of strings that represent menu Options

    */


    std::vector<std::string> menuOptions = { "Hello World", "Sum", "Exit" };

    std::string userInput = ""; // We create this string to hold userInput


    // Start a loop to display the menu, prompt the user, and run some code accordingly
    do
    {
        // We display the menu here


        // We prompt the user here
        std::cout << "Please select a menu option - 1 for hello world, 2 for sum, 3 to exit" << std::endl;
        std::cin >> userInput;

        // We have some decision making code here
        // if or switch for the most part - BUT because we're not working with numbers it has to be an if
        if (userInput == "1")
        {
            // Hello world
            std::cout << "Hello World" << std::endl;
        }
        else if (userInput == "2")
        {
            // sum
            std::cout << "sum" << std::endl;
        }
        else if (userInput == "3")
        {
            // this is the end
            // nothing really needed here
        }
        else
        {
            // user input invalid value
            std::cout << "Please provide 1,2, or 3" << std::endl;
        }



    } while (userInput == "" || userInput != "3"); // Context being the string starts blank so the loop would happen either way
    // and if the user types something that isn't 3, the loop continues, so the end condition(s) of this loop
    // is if the userInput has a non blank value OR userInput has the value of "3".


}


void WriteFile()
{
    std::ofstream file("text.txt", std::ios::app); // Forces the creation of this file and will overwrite it entirely
    file << "My third write" << std::endl;

    // To append we need to provide an additional argument to the ofstream
    // std::ofstream file("filename.type", std::ios::app) that last bit is what appends and not overwrites


    // ofstream is for writing/appending
}

void ReadFile()
{
    // ifstream is for reading
    std::ifstream readFile("text.txt");
    std::string line = ""; // initialize a string variable to read the file line by line

    while (std::getline(readFile, line))
    {
        std::cout << line << std::endl;
    }
}




int main()
{
    //std::cout << "Hello World!\n";

    /*
        Todays lecture is about stuff that you'll see in upcoming classes
        We're going to look at
            Git
            GitHub
            FileIO
            Review

        We'll get started at around 1:15 pm eastern.
        Please visit https://www.github.com and create an account with your student email to get started

        After creating an account, visit https://git-scm.com/downloads/win if you have windows
        You can go through the install process and leave everything to default but I'd recommend watching
        the recording to make sure your install settings are the same as mine, to install git, there's like 20~
        screens of options, most are super simple 1 - 10 options, generally around 3 per screen


        If you're on mac you may already have git installed
        You can confirm this by pressing space and cmd at the same time to bring up spotlight, then type
        terminal and open it, once terminal is open type
        git --version
        if you get a version number returned to you, you have it instaled if you don't
        Visit https://git-scm.com/downloads/mac




        Command Line - Commands
            pwd
                print working directory
                Will show the path to the folder you're currently in, with the command line


            ls
                list?
                Shows all folders and files in the current working directory

                Optional statement for ls
                    ls -la

            cd
                change directory
                cd pathToFolder
                cd Documents
                ~/ is the alias for the user folder
                cd ~/
                .. is the alias for parent folder
                cd ..

            mkdir
                make directory
                mkdir folderName
                if wanting spaces you need to wrap the folder name in " "
                mkdir "multiple words for folder or file"

            touch
                will create a file
                touch readme.txt

            rm
                remove
                rm fileNameOrFolderName
                Will remove
                use this sparingly until you're familar with command line - you can accidentally delete
                stuff needed for your machine if you're running commands with rm that you don't know
                the origin or intent behind
                Optionals
                    rm -r directoryName


            nano
                will open an "easy" text editor in command line - this is way easier than using
                vim or other native text editors for linux/unix style command lines
                nano fileName



        Git commands
            git init
                creates a local repo in the current working directory
                We do not want to do this in anything other than the project folder
                It will cause issues if you do, don't be in your user folder, downloads, etc
                and run this line. Be very aware of the folder you're in, in the command line before running this

            git status
                this will show files that have been altered and are ready for "staging" which is part of the
                process of getting everything ready to upload to github

            git add
                git add .
                git add -A
                git add fileName

                The git add . and git add -A will add all files in the directory to be staged and ready to be commited


            git commit -m "Some meaningful message here"
                Will commit the project and tag it
                    commits will be a collection of files that we've added from the git add command
                    These are now ready to be "pushed" or uploaded to github

            git config --global --edit
                Used later if the easy way doesn't work

            git remote add alias urlGoesHere
                This line is what creates a "connection" between your local (your machines) repo and
                the repo we make on github, without this we can't upload

                To confirm the remotes were added...
                    git remote -v
                        we should see at least 2 if we've added 1 remote
                        1 fetch and 1 push


            git push alias branch
                git push github master
                git push origin master




        Git order of operations
            Once you're in a folder that you want to treat as a project/local repo

            git init
                this is done once per project

            If you have files already in that folder
            
            git add -A
                will add all files in folder to staging, ready to commit

            git commit -m "Some meaningful message here"

            Once commited they are ready to be pushed/uploaded

            to upload you must have a remote set up
                You'll first have to go to github, go to your profile, click repositories, click new
                That will generate a new remote repo and url for you
                Copy that url it gives you
                Then back in command line

           git add remote origin urlGoesHere
                this is done once per remote repo that you want
                most of the time this is done just once

           You can confirm the remote being added via

           git remote -v

           then finally
           git push origin master
                if it's your first pushing and you had the git credential checked during install
                you'll get a pop to authorize your github account with git and you'll be set after that

            
            If you're in a project that has already had git init and a git remote added the steps 
            after you're done editting any files
            git add -A
            git commit -m "Any message"
            git push origin master



    */




    /*
        File IO - Write a file
        ofstream file("name of file here");
        file << "First file io" << std::endl;

    */
    
    //WriteFile();
    //ReadFile();




    // Things we can use this for
    /*
         before getting into databases like mysql, firebase, or mongo (things you'll learn about much later)
         we can use files to store data
            So if we think to our game project
            We could have a method that reads from a text file - think of loading a game
            That file could have a list of all slain monsters, the players fields at the time of save
            And we could as part of this method initialize the player object to that saved state

        Should we have other things that we'd want to change based off a "save state"
            Think of settings - we can change the color of text, size of text, and other things
            about our command prompt programatically


        We can from file, have some decision making code, and based on the decision either leave the colors
        alone or change them completely

        We can also write to the file, over write completely every time we save

        So if we use the game example - we'd probably want to make a main menu with new game, load, exit

        And any time we're not in combat we could have a save option
    */

    // Any review questions before going starting a review from scratch

    // MidterMenuExample
    //MidtermMenuExample(); // Calls the MidtermMenuExample method

/*
    Question: Are we allowed to use .size() for the lab8
    Answer: .size() is something we cover so it is available for use

    
*/




    // Review Section
    Review review; // Calls the constructor of the Review class, this is the same as saying int i;
    // We create a review object that has access to all public members of the Review class, currently
    // the DayOne method

    // We can comment any of these calls out if we don't want to see the output for that day

    // review.DayOne(); // calls the DayOne method off of the review object

    // Day Two
     // review.DayTwo();
    
    // Day Three
     //review.DayThree();
    
    // Day Four
    // review.DayFour();
    
    // Day Five
    // review.DayFive();
    
    // Day Six
    // review.DaySix();
    
    // Day Seven+
     review.DaySeven();

    // . operator examples to see publically accessible things, like we do the day methods above
    // review.
    // We don't see name or number because they are private - private things are only available (natively) in the file
    // they are made in or the class they are made in
    
     // Create a Review object using the overloaded constructor
     Review newReview("bob", 2);

     std::cout << "newReview.name: " << newReview.GetName() << std::endl;
     std::cout << "review.name: " << review.GetName() << std::endl;

     newReview.SetName("Steve");
     review.SetName("Doug");


     std::cout << "newReview.name: " << newReview.GetName() << std::endl;
     std::cout << "review.name: " << review.GetName() << std::endl;

     /*
        Question: we can use this-> right
        Answer: No this-> is not available for use

        Question: Are we making our own includes on the final
        Answer: No, none of the instructions ask you to do that

        Question: Not only are we getting it to run, but we need it to make sense
        Answer: You're going to have to follow all of the ToDos listed in all three files of the final
        Item.h, Inventory.h, and PracticalShop.h, I recommend reading all instructions in those three files
        and FSO before writing any code. I also recommend in order of easy and understanding tackle those files in that order
        as well. Item is the simplest, followed by PracticalShop, with Inventory being the bulk of the work
        however for everything in PracticalShop to work and run, Item and Inventory need to be finished
        You don't need to follow that order, but that is my recommendation

        Question: Can we use const
        Answer: This is explicitly stated in the external material use policy as no you can not
        That policy is found in 0.02 Course Overview in pg3 of the study guide, a version of the policy exists at the 
        beginning and end of each file in the final itself.

     
     
     */







}

