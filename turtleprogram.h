//_____________________________________________________________________________
// By: Nathanael Fixx
//
// allows creation of turtleprogram objects. The user can specify the starting 
// values for the program. The user can also find the length of a program,
// get the value at a specific location of a program, and modify the value at
// a specific location of the program. The operators =, ==, !=, +, +=, *,
// and *= have all been overloaded.
//_____________________________________________________________________________ 

#ifndef TURTLE_PROGRAM
#define TURTLE_PROGRAM

#include <string>

using namespace std;

class TurtleProgram
{

public:
	// Default values for constructor are an initial size of 0
	// and a current length of 0
	TurtleProgram();

	// Constructor, user chooses the two values to be put in the array
	TurtleProgram(string dir, string val);

	// copy constructor, uses assigment opperator
	TurtleProgram(const TurtleProgram & rhs);

	// outputs the designated program in the format [string string]
	friend ostream& operator<<(ostream & outstream, const TurtleProgram & t);

	// sets one program equal to another. Programs are equal if they
	// both have the exact same values.
	TurtleProgram & operator =(const TurtleProgram & rhs);

	// checks if two programs are equivalent (have the exact same values)
	bool operator ==(const TurtleProgram & rhs);

	// checks if two programs are not equivalent
	// (do not have the exact same values)
	bool operator !=(const TurtleProgram & rhs);

	// combines two programs together. The values in the second program
	// are added to the end of the first program.
	TurtleProgram operator +(const TurtleProgram & rhs);

	// combines two programs together and sets the first program equal to
	// the combined value. The values in the second program
	// are added to the end of the first program.
	TurtleProgram operator +=(const TurtleProgram rhs);

	// creates a larger program where the same program is repeated that
	// many times
	TurtleProgram operator *(int mult);

	// creates a larger program where the same program is repeated that
	// many times. The first program is set equal to the new program.
	TurtleProgram operator *=(int mult);

	// returns the length of a program (the number of values stored)
	int getLength();

	// returns the value at the specified index
	string getIndex(int num);

	// allows the user to change the values at a specific index
	void setIndex(int index, string val);

	//destructor
	~TurtleProgram();

private:
	int initialSize; //starting size of array
	string * tArray; 
	int currentLength; //variable storing the current length of array
	void growArray(int newLength); //function to grow array
};

#endif
