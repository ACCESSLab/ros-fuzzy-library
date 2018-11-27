//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code performs a fuzzy logic operation (fuzzification, inference and defuzzification) based on both Mamdani and TSK inference techniques.
//Crisp inputs are receaved as a vector and crisp outputs are returned as a vector. 

#include <exception>
#include <vector>
#include <iostream>
#include "fuzz.h"
#include "infer.h"
#include "defuzz.h"
#include "commondef.h"
#include "XMLReader.h"

using namespace std;

#ifndef __flslib_h__
#define __flslib_h__

struct MainWindow_t;
struct t1FuzzifiedVal;
struct it2FuzzifiedVal;
struct t1InputFSs;
struct it2InputFSs;

class flslib;

/**
 * This class subscribes for ROS inputs to the fuzzy toolbox. It also publishes the final crisp values to the ROS master. This class also reads parameters.
 */
class flslib
{
	private: fuzzify _fuz;
	private: inference _infr;
	private: defuzzify _defuz;

	private: t1Firing _t1FiringLevel;
	private: it2Firing _it2FiringLevel;
	private: t1InputFSs _fuzzifiedVal;
	private: it2InputFSs _it2FuzzifiedVal;
	private: t1TSKOutputFSs _tskOutputSet;
	private: it2TSKOutputFSs _it2TSKOutputSet;
	private: t1MamOutputFSs _mamdaniOutputSet;
	private: it2MamOutputFSs _IT2mamdaniOutputSet;
	private: vector<double> _output;

	public: flslib();
	public: ~flslib();
	/// <summary>
	/// This operation publishes crisp outputs which are defined in readParams() : void to ROS master.
	/// </summary>
	//public: void getParams();
	public: vector<double> runFuzzy(vector<double> aInputs, MainWindow_t *stData);
};

#endif
