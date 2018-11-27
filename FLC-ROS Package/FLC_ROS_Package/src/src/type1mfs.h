//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code return a membership value for a traingular, trapezoidal and gaussian type-1 membership functions.

#include <exception>
using namespace std;

#ifndef __type1mfs_h__
#define __type1mfs_h__

// #include "fuzz.h"

class fuzz;
class defuzz;
class type1mfs;

/**
* This is a class of type-1 membership function. When called, it receives input value and returns the membership value for the input.
*/
class type1mfs
{
	/**
	* left edge of the t1MF.
	*/
private: double _left;
		 /**
		 * Middle edge of the t1MF.
		 */
private: double _mid;
		 /**
		 * Right edge of the t1MF.
		 */
private: double _right;
		 /**
		 * Maximum top value of the t1MF.
		 */
private: double _pSlope;
private: double _nSlope;
private: double _mfVal;
private: double _max;
public: fuzz* _unnamed_fuzz_;
public: defuzz* _unnamed_defuzz_;

public: type1mfs();
public: ~type1mfs();

		/// <summary>
		/// When called this function returns the membership of the input. It receives the input value, (model element not found), (model element not found), (model element not found) and (model element not found).
		/// </summary>
public: double trimf(double *aInput, double aP1, double aP2, double aP3, double aMax);
public: double trapmf(double *aInput, double aP1, double aP2, double aP3, double aP4, double aMax);
public: double gaussmf(double *aInput, double aP1, double aP2);
};

#endif

