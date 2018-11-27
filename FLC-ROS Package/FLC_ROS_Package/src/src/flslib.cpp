//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code performs a fuzzy logic operation (fuzzification, inference and defuzzification) based on both Mamdani and TSK inference techniques.
//Crisp inputs are receaved as a vector and crisp outputs are returned as a vector. 

using namespace std;

#include "flslib.h"

flslib::flslib() {}
flslib::~flslib() {}


vector<double> flslib::runFuzzy(vector<double> aInputs, MainWindow_t *stData) {
	//XMLReader Reader(&stSysData);
	//Reader.ReadXMLFile("C:/Users/X1/Desktop/config.xml");
		
	if (stData->bType1 == true && stData->bInterval2 == false) {//if it is t1 system
		_fuzzifiedVal = _fuz.fuzzifyt1(&aInputs, stData);
		_t1FiringLevel = _infr._t1_firing_level( &_fuzzifiedVal, stData);

		if (stData->bMamdani == false && stData->bTSK == true) {
			_tskOutputSet = _infr._type1_tsk_processing(&aInputs, stData);
			_output = _defuz.t1_tsk(&_t1FiringLevel, &_tskOutputSet, stData);
		}

		else if (stData->bMamdani == true && stData->bTSK == false) {//inference is mamdani
			_mamdaniOutputSet = _infr._type1_mamdani_processing(&_t1FiringLevel, stData);
			_output = _defuz.centroid(&_mamdaniOutputSet, stData);
		}
		else { throw("Wrong configuration!"); }
	}
	else if (stData->bType1 == false && stData->bInterval2 == true) {//if it is interval type-2 system
		//cout << (&aInputs) << endl;
		_it2FuzzifiedVal = _fuz.fuzzifyit2(&aInputs, stData);
		/*cout << _it2FuzzifiedVal.vstIT2FuzzVal[0].vIt2UMFFuzzVal[0] << endl;
		cout << _it2FuzzifiedVal.vstIT2FuzzVal[0].vIt2UMFFuzzVal[1] << endl;
		cout << _it2FuzzifiedVal.vstIT2FuzzVal[0].vIt2LMFFuzzVal[0] << endl;
		cout << _it2FuzzifiedVal.vstIT2FuzzVal[0].vIt2LMFFuzzVal[1] << endl;
		cout << _it2FuzzifiedVal.vstIT2FuzzVal[1].vIt2UMFFuzzVal[0] << endl;
		cout << _it2FuzzifiedVal.vstIT2FuzzVal[1].vIt2UMFFuzzVal[1] << endl;
		cout << _it2FuzzifiedVal.vstIT2FuzzVal[1].vIt2LMFFuzzVal[0] << endl;
		cout << _it2FuzzifiedVal.vstIT2FuzzVal[1].vIt2LMFFuzzVal[1] << endl;*/
	//	std::copy(_it2FuzzifiedVal.begin(), _it2FuzzifiedVal.end(), std::ostream_iterator<int>(std::cout << " "));
		
		_it2FiringLevel = _infr._it2_firing_level(&_it2FuzzifiedVal, stData);
		/*cout << _it2FiringLevel.vIt2UMFFiringL[0] << endl;
		cout << _it2FiringLevel.vIt2UMFFiringL[1] << endl;
		cout << _it2FiringLevel.vIt2UMFFiringL[2] << endl;
		cout << _it2FiringLevel.vIt2UMFFiringL[3] << endl;
		cout << _it2FiringLevel.vIt2LMFFiringL[0] << endl;
		cout << _it2FiringLevel.vIt2LMFFiringL[1] << endl;
		cout << _it2FiringLevel.vIt2LMFFiringL[2] << endl;
		cout << _it2FiringLevel.vIt2LMFFiringL[3] << endl;*/
		if (stData->bMamdani == false && stData->bTSK == true) {
			_it2TSKOutputSet = _infr._it2_tsk_processing(&aInputs, &_it2FiringLevel, stData);
			_output = _defuz.ub(&_it2TSKOutputSet, stData);
		}
			
		else if (stData->bMamdani == true && stData->bTSK == false) {//inference is mamdani
			_IT2mamdaniOutputSet = _infr._it2_mamdani_processing(&_it2FiringLevel, stData);
			_output = _defuz.nt(&_IT2mamdaniOutputSet, stData);
			//cout << _output[0] << endl;
		}
		else { throw("Wrong configuration!"); }
	}
	else { throw("Wrong configuration!"); }
	return _output;
}