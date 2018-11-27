//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code return the membership value for the upper and lower embedded type-1 memberships of 
// an interval type-2 membership function.

#include <exception>
#include <vector>
using namespace std;

#ifndef __type2mfs_h__
#define __type2mfs_h__

// #include "fuzz.h"

class fuzz;
class defuzz;
class type2mfs;

/**
* This is a class of type-1 membership function. When called, it receives input value and returns the membership value for the input.
*/
class type2mfs
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
private: vector<double> _mfVal;
private: double _max;
public: fuzz* _unnamed_fuzz_;
public: defuzz* _unnamed_defuzz_;

public: type2mfs();
public: ~type2mfs();

		/// <summary>
		/// When called this function returns the membership of the input. It receives the input value, (model element not found), (model element not found), (model element not found) and (model element not found).
		/// </summary>
public: vector<double> gausst2mf(double *aInput, double aP1, double aP2, double aP3);
};

#endif