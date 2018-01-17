//_____________________________________________________________________________
// By: Nathanael Fixx
//
// Test Driver: Tests each TurtleProgram function in various scenarios
//_____________________________________________________________________________

#include <iostream>
#include <string>
#include <stdexcept>
#include "turtleprogram.h"

using namespace std;



int main()
{

	cout << "____________________________________________" << endl;
	cout << "Testing Constructor w/ No Parameters: " << endl;
	cout << "Solution should be []" << endl;
	TurtleProgram tp; cout << "Solution: " << tp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Constructor w/ Parameters: " << endl;
	cout << "Solution should be [F 90]" << endl;
	TurtleProgram tp2("F", "90"); cout << "Solution: " << tp2 << endl;
	cout << "____________________________________________" << endl;
	
	cout << "____________________________________________" << endl;
	cout << "Testing Copy Constructor: " << endl;
	cout << "Solution should be [F 90]" << endl;
	TurtleProgram tp3(tp2);
	cout << "Solution: " << tp3 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Assignment Operator (both simple): " << endl;
	cout << "Solution should be [R 120]" << endl;
	TurtleProgram tp4("F", "30"), tp5("R", "120");
	tp4 = tp5;
	cout << "Solution: " << tp4 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Assignment Operator (left empty): " << endl;
	cout << "Solution should be [R 120]" << endl;
	tp = tp5;
	cout << "Solution: " << tp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Assignment Operator (right empty): " << endl;
	cout << "Solution should be []" << endl;
	TurtleProgram tp6;
	tp5 = tp6;
	cout << "Solution: " << tp5 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Assignment Operator (left large): " << endl;
	cout << "Solution should be [F 90]" << endl;
	tp += tp2;
	tp = tp2;
	cout << "Solution: " << tp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Assignment Operator (right large): " << endl;
	cout << "Solution should be [F 90 F 90]" << endl;
	tp += tp2;
	tp2 = tp;
	cout << "Solution: " << tp2 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Assignment Operator (both large): " << endl;
	cout << "Solution should be [R 120 R 120]" << endl;
	tp4 += tp4;
	tp2 = tp4;
	cout << "Solution: " << tp2 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Assignment Operator (both empty): " << endl;
	cout << "Solution should be []" << endl;
	tp5 = tp6;
	cout << "Solution: " << tp5 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Assignment Operator (itself): " << endl;
	cout << "Solution should be [F 90]" << endl;
	tp3 = tp3;
	cout << "Solution: " << tp3 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Equals (two basic): " << endl;
	cout << "Solution should be \"True\"" << endl;
	TurtleProgram tp7("R", "60"), tp8("F", "90");
	cout << "Solution: ";
	if (tp3 == tp8) cout << "True " << endl;
	if (tp3 == tp7) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Equals (left empty): " << endl;
	cout << "Solution should be \"\"" << endl;
	cout << "Solution: ";
	if (tp5 == tp8) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Equals (right empty): " << endl;
	cout << "Solution should be \"\"" << endl;
	cout << "Solution: ";
	if (tp8 == tp5) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Equals (left large): " << endl;
	cout << "Solution should be \"\"" << endl;
	cout << "Solution: ";
	if (tp4 == tp7) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Equals (right large): " << endl;
	cout << "Solution should be \"\"" << endl;
	cout << "Solution: ";
	if (tp7 == tp4) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Equals (both large): " << endl;
	cout << "Solution should be \"True\"" << endl;
	cout << "Solution: ";
	if (tp4 == tp2) cout << "True " << endl;
	if (tp4 == tp) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Equals (both empty): " << endl;
	cout << "Solution should be \"True\"" << endl;
	cout << "Solution: ";
	if (tp5 == tp6) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Equals (itself): " << endl;
	cout << "Solution should be \"True\"" << endl;
	cout << "Solution: ";
	if (tp3 == tp3) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Equals (correct until the second term): ";
	cout << endl;
	cout << "Solution should be \"\"" << endl;
	cout << "Solution: ";
	TurtleProgram tp9 = tp8 + tp7;
	TurtleProgram tp10 = tp8 + tp3;
	if (tp9 == tp10) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Not-Equals (two basic): " << endl;
	cout << "Solution should be \"True\"" << endl;
	cout << "Solution: ";
	if (tp3 != tp7) cout << "True " << endl;
	if (tp3 != tp8) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Not-Equals (left empty): " << endl;
	cout << "Solution should be \"True\"" << endl;
	cout << "Solution: ";
	if (tp5 != tp7) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Not-Equals (right empty): " << endl;
	cout << "Solution should be \"True\"" << endl;
	cout << "Solution: ";
	if (tp3 != tp5) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Not-Equals (left large): " << endl;
	cout << "Solution should be \"True\"" << endl;
	cout << "Solution: ";
	if (tp4 != tp5) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Not-Equals (right large): " << endl;
	cout << "Solution should be \"True\"" << endl;
	cout << "Solution: ";
	if (tp8 != tp4) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Not-Equals (both large): " << endl;
	cout << "Solution should be \"True\"" << endl;
	cout << "Solution: ";
	if (tp4 != tp) cout << "True " << endl;
	if (tp4 != tp2) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Not-Equals (both empty): " << endl;
	cout << "Solution should be \"\"" << endl;
	cout << "Solution: ";
	if (tp5 != tp6) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Not-Equals (both empty): " << endl;
	cout << "Solution should be \"\"" << endl;
	cout << "Solution: ";
	if (tp4 != tp4) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Not-Equals (correct until the second term): ";
	cout << endl;
	cout << "Solution should be \"True\"" << endl;
	cout << "Solution: ";
	if (tp9 != tp10) cout << "True " << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator plus (both basic): " << endl;
	cout << "Solution should be F 90 R 60" << endl;
	cout << "Solution: ";
	TurtleProgram temp;
	temp = tp3 + tp7;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator plus (left empty): " << endl;
	cout << "Solution should be R 60" << endl;
	cout << "Solution: ";
	temp = tp5 + tp7;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator plus (right empty): " << endl;
	cout << "Solution should be R 60" << endl;
	cout << "Solution: ";
	temp = tp7 + tp5;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator plus (both empty): " << endl;
	cout << "Solution should be []" << endl;
	cout << "Solution: ";
	temp = tp5 + tp6;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator plus (left large): " << endl;
	cout << "Solution should be R 120 R 120 F 90" << endl;
	cout << "Solution: ";
	temp = tp4 + tp3;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator plus (right large): " << endl;
	cout << "Solution should be F 90 R 120 R 120" << endl;
	cout << "Solution: ";
	temp = tp3 + tp4;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator plus (both large): " << endl;
	cout << "Solution should be R 120 R 120 R 120 R 120" << endl;
	cout << "Solution: ";
	temp = tp2 + tp4;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator plus (itself): " << endl;
	cout << "Solution should be R 120 R 120 R 120 R 120" << endl;
	cout << "Solution: ";
	temp = tp2 + tp2;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Plus-Equals (both basic): " << endl;
	cout << "Solution should be F 90 R 60" << endl;
	cout << "Solution: ";
	tp3 += tp7;
	cout << tp3 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Plus-Equals (right empty): " << endl;
	cout << "Solution should be R 60" << endl;
	cout << "Solution: ";
	tp7 += tp5;
	cout << tp7 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Plus-Equals (left empty): " << endl;
	cout << "Solution should be R 60" << endl;
	cout << "Solution: ";
	tp5 += tp7;
	cout << tp5 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Plus-Equals (left large): " << endl;
	cout << "Solution should be R 120 R 120 F 90" << endl;
	cout << "Solution: ";
	tp4 += tp8;
	cout << tp4 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Plus-Equals (right large): " << endl;
	cout << "Solution should be R 60 R 120 R 120 F 90" << endl;
	cout << "Solution: ";
	tp7 += tp4;
	cout << tp7 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Plus-Equals (both large): " << endl;
	cout << "Solution should be R 60 R 120 R 120 F 90 R 120 R 120 F 90";
	cout << endl;
	cout << "Solution: ";
	tp7 += tp4;
	cout << tp7 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Plus-Equals (both empty): " << endl;
	cout << "Solution should be []" << endl;
	cout << "Solution: ";
	TurtleProgram tp11;
	tp6 += tp11;
	cout << tp6 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Plus-Equals (itself): " << endl;
	cout << "Solution should be F 90 R 60 F 90 R 60" << endl;
	cout << "Solution: ";
	tp9 += tp9;
	cout << tp9 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Multiplication (basic * int): " << endl;
	cout << "Solution should be F 90 F 90 F 90 F 90" << endl;
	cout << "Solution: ";
	temp = tp8 * 4;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Multiplication (empty * int): " << endl;
	cout << "Solution should be []" << endl;
	cout << "Solution: ";
	temp = tp6 * 4;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Multiplication (large * int): " << endl;
	cout << "Solution should be R 120 R 120 F 90 (x3) " << endl;
	cout << "Solution: ";
	temp = tp4 * 3;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Multiplication (basic * 0): " << endl;
	cout << "Solution should be []" << endl;
	cout << "Solution: ";
	temp = tp8 * 0;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Multiplication (basic * -int): " << endl;
	cout << "Solution should be []" << endl;
	cout << "Solution: ";
	temp = tp8 * -2;
	cout << temp << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Multiplication-Equals (basic * int): ";
	cout << endl;
	cout << "Solution should be R 60 R 60" << endl;
	cout << "Solution: ";
	tp5 *= 2;
	cout << tp5 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Multiplication-Equals (basic * int): ";
	cout << endl;
	cout << "Solution should be []" << endl;
	cout << "Solution: ";
	tp6 *= 76;
	cout << tp6 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Multiplication-Equals (large * int): ";
	cout << endl;
	cout << "Solution should be R 120 R 120 R 120 R 120 R 120 R 120";
	cout << endl;
	cout << "Solution: ";
	tp2 *= 3;
	cout << tp2 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Multiplication-Equals (basic * 0): " << endl;
	cout << "Solution should be []" << endl;
	cout << "Solution: ";
	tp2 *= 0;
	cout << tp2 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing Operator Multiplication-Equals (basic * -int): ";
	cout << endl;
	cout << "Solution should be []" << endl;
	cout << "Solution: ";
	tp7 *= -5;
	cout << tp7 << endl;
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing getLength (basic): " << endl;
	if (tp8.getLength() == 2) {
		cout << "Works" << endl;
	}
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing getLength (large): " << endl;
	if (tp4.getLength() == 6) {
		cout << "Works" << endl;
	}
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	
	cout << "Testing getLength (empty): " << endl;
	if (tp2.getLength() == 0) {
		cout << "Works" << endl;
	}
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	cout << "Testing getIndex (basic): " << endl;
	if (tp4.getIndex(3) == "120") {
		cout << "Works" << endl;
	}
	cout << "____________________________________________" << endl;

	cout << "____________________________________________" << endl;
	
	cout << "Testing setIndex (basic): " << endl;
	tp4.setIndex(0, "F");
	if (tp4.getIndex(0) == "F") {
		cout << "Works" << endl;
	}
	cout << "____________________________________________" << endl;

	return 0;
}


