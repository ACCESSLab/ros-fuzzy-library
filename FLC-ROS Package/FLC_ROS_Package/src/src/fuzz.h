//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code performs fuzzification processes. They return input fuzzy set for a type-1 and inteval type-2 FLSs 
//which are based on both Mamdani and TSK inference techniques

#include <exception>
#include <vector>
#include <iostream>
#include "commondef.h"
#include "XMLReader.h"
#include "type2mfs.h"
#include "type1mfs.h"
#include <qvector.h>

using namespace std;

#ifndef __fuzz_h__
#define __fuzz_h__

struct MainWindow_t;
struct t1FuzzifiedVal;
struct it2FuzzifiedVal;
struct t1InputFSs;
struct it2InputFSs;

class fuzzify;
class type1mfs;
class type2mfs;

//does this has to be typedef? lol yes

typedef vector<vector<vector<double>>> sometypename;

/**
 * This class initially reads parameters defined by a user. This class then accepts inputs and calculates membership values for each inputs corresponding membership functions. The information is passed as a structure with assigned attribute values to be used by the inference system.
 */
class fuzzify
{	
	t1FuzzifiedVal t1fv;
	it2FuzzifiedVal it2fv;
	t1InputFSs st1InputFSs;
	it2InputFSs sit2InputFSs;

	type1mfs t1mfs;
	type2mfs t2mfs;

	private: vector<double> _gausst2MemVal;
			 
	public: fuzzify();
	public: ~fuzzify();

	/// <summary>
	/// This operation fuzzifies the inputs using the membership function classes. For each membership function defined by (model element not found), it generates the primary membership value for all inputs. The membership values are stored and passed as a pointer to vector.
	/// </summary>
	public: t1InputFSs fuzzifyt1(vector<double> *aInputs, MainWindow_t *stData);
	public:	it2InputFSs	fuzzifyit2(vector<double> *aInputs, MainWindow_t *stData);
		
};

#endif
