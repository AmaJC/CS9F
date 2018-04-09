#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Function Prototypes

void InterpretCommands(istream&);

void InterpretUpdate(istream&);

void InterpretList(istream&);

void InterpretBatch(istream&);

void InterpretQuit(istream&);

/**
 * Driver Function
 */
int main()
{
	cout << "Enter commands: ";
    InterpretCommands(cin);
    return 0;
}

/**
 * Repeatedly recognizes and processes commands, by default from the standard input.
 * It can also interpret a file's commands when passed in an input file stream.
 */
void InterpretCommands(istream& cmds)
{
    string line, lineInWord;
    // TODO: Declare other variables here.

    while ( getline(cmds, line) )  // TODO: Get a line.
    {
        istringstream lineIn(line);
        string lineInWord;

        if ( not (lineIn >> lineInWord) ) // TODO: Get the line's first word.
        {
            cerr << "Must enter at least 1 word." << endl;  // TODO: Do something if there weren't any words.
        }
        else if (lineInWord == "update")
        {
            InterpretUpdate (lineIn);
        }
        else if (lineInWord == "list")
        {
            InterpretList (lineIn);
        }
        else if (lineInWord == "batch")
        {
            InterpretBatch (lineIn);
        }
        else if (lineInWord == "quit")
        {
            InterpretQuit(lineIn);
            break;
        }
        else
        {
            cerr << "Unrecognizable command word." << endl; 
        }
    }
}

/**
 * Processes the "update word number" command.
 */
void InterpretUpdate(istream& cmds)
{
	string line, firstWord, secondWord;
	getline(cmds, line);
	istringstream lineIn(line);
	if ( not (lineIn >> firstWord) ) // TODO: Get the line's first word.
    {
        cerr << "The update command must be followed by a word and an integer. " << endl;  // TODO: Do something if there weren't any words.
    }
    else if ( not (lineIn >> secondWord ) )
    {
        cerr << "The update command must be followed by a word and an integer. " << endl;
    } 
    else
    {
    	stringstream supposedInt(secondWord);
    	int num = 0;
    	if ( not (supposedInt >> num) ) {
    		cerr << "The second argument must be an integer." << endl;
    	}
        else 
        {
            cout << "Processed command: update " + firstWord + " " + secondWord + "." << endl;
        }   
    }
}

/**
 * Processes the "list names" or "list quantities" command.
 */
void InterpretList(istream& cmds)
{
	string line, lineInWord, argument_that_shouldnt_exist;
	getline(cmds, line);
	istringstream lineIn(line);
	if ( not (lineIn >> lineInWord) ) // TODO: Get the line's first word.
    {
        cerr << "The list command must be followed by either the word 'names' or the word 'quantities'." << endl;  // TODO: Do something if there weren't any words.
    }
    else if ( lineIn >> argument_that_shouldnt_exist )
    {
        cerr << "The list command must not have more than one word following it." << endl;
    }
    else if (lineInWord == "names")
    {
        cout << "Processed command: list names." << endl;
    } 
    else if (lineInWord == "quantities")
    {
    	cout << "Processed command: list quantities." << endl;
    } 
    else 
    {
    	cerr << "The list command must be followed by either the word 'names' or the word 'quantities'." << endl;
    }
}

/**
 * Processes the "batch file-name" command.
 */
void InterpretBatch(istream& cmds)
{
	string line, filename, argument_that_shouldnt_exist;
	getline(cmds, line);
	istringstream lineIn(line);
	if ( not (lineIn >> filename) ) // TODO: Get the line's first word.
    {
        cerr << "The batch command must be followed by the name of an existing file." << endl;  // TODO: Do something if there weren't any words.
    }
    else if ( lineIn >> argument_that_shouldnt_exist ) 
    {
        cerr << "The batch command only accepts one argument, the file name." << endl;
    }
    else 
    {
    	cout << "Opening file " + filename + "." << endl;
    	ifstream file_stream;
    	file_stream.open(filename);
    	if (!file_stream) 
    	{
    		cerr << "File " + filename + " does not exist." << endl;
    	} 
    	else
    	{   
    		InterpretCommands (file_stream);
            cout << "Processed command: batch " + filename + "." << endl;
    	}
    }
}

/**
 * Processes the "quit" command.
 */
void InterpretQuit(istream& cmds)
{
	string line, argument_that_shouldnt_exist;
    getline(cmds, line);
    istringstream lineIn(line);
    if ( not (lineIn >> argument_that_shouldnt_exist) ) // TODO: Get the line's first word.
    {
        return;
    }
    else 
    {
        cerr << "The quit command must NOT be followed by any other arguments." << endl;
    }
}