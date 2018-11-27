//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code performs fuzzy inference processes. They return firing level and output fuzzy set for a type-1 and inteval type-2 FLSs 
//which are based on both Mamdani and TSK inference techniques

#include <exception>
#include <vector>
#include "math.h"
#include "commondef.h"
#include "XMLReader.h"
#include <algorithm>
#include "type1mfs.h"
#include "type2mfs.h"
#include <iostream>

using namespace std;

#ifndef __infer_h__
#define __infer_h__

struct MainWindow_t;

class inference;

class type1mfs;
class type2mfs;

class inference
{
	type1mfs t1mfs;
	type2mfs t2mfs;

	private: double _min;
	private: double dVal;
	private: double dValUMF;
	private: double dValLMF;
	private: double dPrecssision;
	private: double dQuantization;
    private: it2TSKrOutput rOutput;
	private: it2TSKrOutputs rOutputs;
	private: double _y_left;
	private: double _y_right;
	private: QVector<double> vValues;
	private: QVector<double> vMFRanges;
	private: QVector<double> vOPRanges;
	private: QVector<double> vAntecedents;
	private: QVector<double> vAntecedentsUMF;
	private: QVector<double> vAntecedentsLMF;
	private: QVector<double> vConsequents;
	private: t1Firing _firing_level;	
	private: it2Firing _firing_level_t2;
	private: it2TSKOutputFS _tskBounds;
	private: it2TSKOutputFSs _tskOutputSet;
	private: t1MamOutputFSs _outputFset;
	private: t1MamOutputFSs _outputSet;
	private: t1MamOutputFS t1MamOFS;
	private: t1MamOutputFS t1MamOFFS;
	private: t1TSKOutputFS _tRuleOutputSet;
	private: t1TSKOutputFSs _toutputSet;
	private: it2MamOutputFS _it2OutputFset;
	private: it2MamOutputFS _outputFsetUMF;
	private: it2MamOutputFS _outputFsetFinal;
	private: it2MamOutputFSs _it2_outputFset;
	private: it2MamOutputFSs _it2_ruleoutputFset;
	//private: QVector<QStringList> slConsTockens2;
	//private: vector<vector<double>> _tskEachOut;
	//private: vector<vector<double>> _tskEachOut;

	public: inference();
	public: ~inference();

	public: t1Firing _t1_firing_level(t1InputFSs *aFuzzified_val, MainWindow_t *stData);
	public: it2Firing _it2_firing_level(it2InputFSs *aFuzzified_val, MainWindow_t *stData);
	public:	t1MamOutputFSs _type1_mamdani_processing(t1Firing *aFiring_level, MainWindow_t *stData);
	public:	t1TSKOutputFSs _type1_tsk_processing(vector<double> *aInputs, MainWindow_t *stData);
	public:	it2MamOutputFSs _it2_mamdani_processing(it2Firing *aFiring_level, MainWindow_t *stData);
	public:	it2TSKOutputFSs _it2_tsk_processing(vector<double> *aInputs, it2Firing *aFiring_level, MainWindow_t *stData);
};

#endif
