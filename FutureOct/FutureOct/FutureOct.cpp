#include <iostream>
#include <fstream> // allows us to write and read to text files
#include <string> // allows use of getline

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
    */




/*
    File IO - Write a file
    ofstream file("name of file here");
    file << "First file io" << std::endl;

*/

    std::ofstream file("text.txt", std::ios::app); // Forces the creation of this file and will overwrite it entirely
    file << "My third write" << std::endl;

    // To append we need to provide an additional argument to the ofstream
    // std::ofstream file("filename.type", std::ios::app) that last bit is what appends and not overwrites


    // ofstream is for writing/appending

    // ifstream is for reading
    std::ifstream readFile("text.txt");
    std::string line = ""; // initialize a string variable to read the file line by line

    while (std::getline(readFile, line))
    {
        std::cout << line << std::endl;
    }

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




}

