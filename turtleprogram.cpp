//_____________________________________________________________________________
// By: Nathanael Fixx
//
// allows creation of turtleprogram objects. The user can specify the starting 
// values for the program. The user can also find the length of a program,
// get the value at a specific location of a program, and modify the value at
// a specific location of the program. The operators =, ==, !=, +, +=, *,
// and *= have all been overloaded.
//_____________________________________________________________________________

#include "turtleprogram.h"
#include <stdexcept>
#include <iostream>
using namespace std;

//_____________________________________________________________________________
// Default Constructor
//
// Initial size is set to 0, and the current length is set to 0. Array is
// created of size 0.
//_____________________________________________________________________________
TurtleProgram::TurtleProgram()
{
	initialSize = 0;
	currentLength = 0;

	tArray = new string[initialSize];
	
}

//_____________________________________________________________________________
// Constructor
//
// User chooses the two values to put in the array
//_____________________________________________________________________________
TurtleProgram::TurtleProgram(string dir, string val)
{
	currentLength = 0;
	initialSize = 2; // initial size is set to 2 since we know the
                         // array will now have two elements
	
	tArray = new string[initialSize];
	tArray[0] = dir;
	tArray[1] = val;
	currentLength += 2;
}

//_____________________________________________________________________________
// Copy constructor
//
// Uses the assignment opperator
//_____________________________________________________________________________
TurtleProgram::TurtleProgram(const TurtleProgram & rhs)
{
	tArray = NULL; // making sure no memory leak
	*this = rhs;
}

//_____________________________________________________________________________
// Overloaded << operator
//
// Iterates through the array and sends each value to the ostream. Displays
// the values in the form of [ values ]
//_____________________________________________________________________________
ostream & operator<<(ostream & outstream, const TurtleProgram & t)
{
	outstream << "[";

	for (int i = 0; i < t.currentLength; i++) {
		outstream << t.tArray[i];

		if (i != t.currentLength - 1) {
			outstream << " ";
		}
	}
	
	
	outstream << "]";
	return outstream;
}

//_____________________________________________________________________________
// Overloaded assignment operator
//
// If the two programs are equal, the left program is returned. If not, the
// array is deleted and a new, blank array that is the same size as the 
// right hand side array is created. All the information from the right hand
// side is copied into the new blank array.
//_____________________________________________________________________________
TurtleProgram & TurtleProgram::operator=(const TurtleProgram &rhs)
{
	if (this != &rhs) {

		if (tArray != NULL) {
			delete[] tArray;  // deleting left hand side
		}

		currentLength = rhs.currentLength;
		tArray = new string[currentLength];

		for (int i = 0; i < currentLength; i++) {
			tArray[i] = rhs.tArray[i];
		}

	}

	return *this;
}

//_____________________________________________________________________________
// Overloaded == operator
//
// Iterates through both arrays and checks if each value is equal. If not, it
// returns false
//_____________________________________________________________________________
bool TurtleProgram::operator==(const TurtleProgram & rhs)
{
	if (currentLength != rhs.currentLength) { // if the programs are not
		return false;                     // of equal length, they
	}					  // can't be equal

	for (int i = 0; i < currentLength; i++) {
		if (tArray[i] != rhs.tArray[i]) {
			return false;
		}
	}
	
	return true;
}

//_____________________________________________________________________________
// Overloaded operator !=
//
// Iterates through each element of the two arrays and checks to see it they 
// are the same. As soon as it finds a pair that is not the same, it returns
// true.
//_____________________________________________________________________________
bool TurtleProgram::operator!=(const TurtleProgram & rhs)
{
	if (currentLength != rhs.currentLength) {	
		return true; // if the programs aren't the same length, they
	}                    // are not equal

	for (int i = 0; i < currentLength; i++) {
		if (tArray[i] != rhs.tArray[i]) {
			return true;
		}
	}

	return false;
}

//_____________________________________________________________________________
// Overloaded plus operator
//
// Creates a new, temp turtleprogram and resizes to the exact size it will
// need to be to hold the sum of both programs. It then copies the information
// from the first turtle program and then the second turtle program. Returns
// the temp turtle program.
//_____________________________________________________________________________
 TurtleProgram TurtleProgram::operator+(const TurtleProgram & rhs)
{
	int i = 0, j = 0;
	int oldLength = currentLength;
	TurtleProgram temp;
	int newLength = currentLength + rhs.currentLength;
    
	temp.growArray(newLength);

	while (i < oldLength) { // copying data from first array
		temp.tArray[i] = tArray[i];
		i++;
	}

	while (j < rhs.currentLength) { // copying data from second array
		temp.tArray[i] = rhs.tArray[j];
			i++;
		    j++;
	}

	return temp;
}

//_____________________________________________________________________________
// Overloaded += Operator
//
// Determines the combined length of the two programs and resizes the
// left-hand array to this size. Copies all of the data from the right hand
// side array into the, now expanded, left hand side array. rhs array is not
// passed by const reference in case the user wants to perform the +=
// operation on the same program. Ex. tp4 += tp4;
//_____________________________________________________________________________
TurtleProgram TurtleProgram::operator+=(const TurtleProgram rhs)							
{

	int oldLength = currentLength;
	int newLength = currentLength + rhs.currentLength; // getting new length

	growArray(newLength);
	
	// copying data from the second array into the first array
	for (int j = 0; j < rhs.currentLength; j++) {
		tArray[oldLength] = rhs.tArray[j]; 
		oldLength++;
	}

	return *this;
}

//_____________________________________________________________________________
// Overloaded multiplication operator
//
// Creates a temp turtleprogram and grows it to the correct length. Then
// copies the designated program into the temp program the specified number of
// times
//_____________________________________________________________________________
TurtleProgram TurtleProgram::operator*(int mult)
{
	if (mult < 0) mult = 0;

	int newLength = mult * currentLength; //getting new length 
	int j = 0;
	TurtleProgram temp;
	
	temp.growArray(newLength);

	for (int i = 0; i < temp.currentLength; i++) { // copying data
		if (j == currentLength) j = 0;
		temp.tArray[i] = tArray[j];
		j++;
	}

	return temp;
}

//_____________________________________________________________________________
// Overloaded operator *=
//
// Grows the array to the necessary legth and then copies the data into it
// as many times as possible
//_____________________________________________________________________________ 
TurtleProgram TurtleProgram::operator*=(int mult)
{
	if (mult <= 0) {  // if they try to multiply by a negative.
		          // program will return an empty program.
		mult = 0;
		currentLength = 0;
	}
		//throw std::out_of_range("Undefined");
		

	int oldLength = currentLength;
	int newLength = currentLength * mult; //calculating new length
	growArray(newLength);

	int i = oldLength;
	
	for (int j = 0; i < currentLength; j++) { //copying data
		tArray[i] = tArray[j];
		i++;
	}
	
	return *this;
}

//_____________________________________________________________________________
// getLength
//
// Returns the currentLength value
//_____________________________________________________________________________
int TurtleProgram::getLength()
{
	return currentLength;
}

//_____________________________________________________________________________
// getIndex
//
// Returns the value at the given index of the array.
//_____________________________________________________________________________
string TurtleProgram::getIndex(int num)
{
	return tArray[num];
}

//_____________________________________________________________________________
// setIndex
//
// Changes the value at the specified index to the value that the user decides.
//_____________________________________________________________________________
void TurtleProgram::setIndex(int index, string val)
{
	//can only change index that exists
	if (index < 0 || index >= currentLength) {
		cout << "OUT OF RANGE" << endl; 
		return;
	}

	tArray[index] = val;
}

//_____________________________________________________________________________
// growArray
//
// Creates a temp pointer to a new array of the length that was passed in.
// Then copies the data from the turtleprogram that the function was called on.
// The array for the turtleprogram is then deleted and replaced with the temp
// array.
//_____________________________________________________________________________
void TurtleProgram::growArray(int newLength)
{
	string * temp = new string[newLength];

	for (int i = 0; i < currentLength; i++) {
		temp[i] = tArray[i];
	}

	delete[] tArray;
	tArray = temp;
	currentLength = newLength;
}

//_____________________________________________________________________________
// Destructor
//_____________________________________________________________________________
TurtleProgram::~TurtleProgram()
{
	delete[] tArray;
}
