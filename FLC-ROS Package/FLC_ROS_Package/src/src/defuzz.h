//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code performs a defuzzification for both Mamdani and TSK inference techniques.
//Structured output fuzzy sets are receaved and crisp outputs are returned as a vector.

#include <exception>
#include <vector>
#include <iostream>
#include <algorithm>
#include "type1mfs.h"
#include "type2mfs.h"
#include "commondef.h"
#include "XMLReader.h"

using namespace std;

#ifndef __defuzz_h__
#define __defuzz_h__

struct MainWindow_t;

class defuzzify;
class type1mfs;
class type2mfs;

class defuzzify
{
	type1mfs t1mfs;
	type2mfs t2mfs;

	private: double _y_left;
	private: double _y_right;
	private: vector<double> _y_crisp;
	private: vector<double> _uStar;

	public: defuzzify();
	public: ~defuzzify();

	public: vector<double> t1_tsk(t1Firing *aFiring_level, t1TSKOutputFSs *aOutFSet, MainWindow_t *stData);
	public: vector<double> ub(it2TSKOutputFSs *_tskOutputSet, MainWindow_t *stData);
	public: vector<double> centroid(t1MamOutputFSs *_outputSet, MainWindow_t *stData);
	public: vector<double> km();
	public: vector<double> nt(it2MamOutputFSs *_it2_outputFset, MainWindow_t *stData);
	public: vector<double> weightedAvg();
	public: vector<double> height();
	public: vector<double> gaussianMF();
	public: vector<double> triangularMF();
	public: vector<double> trapezoidalMF();
	public: vector<double> it2Gaussian();
};

#endif