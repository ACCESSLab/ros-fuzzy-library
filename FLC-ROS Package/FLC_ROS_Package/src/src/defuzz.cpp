//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code performs a defuzzification for both Mamdani and TSK inference techniques.
//Structured output fuzzy sets are receaved and crisp outputs are returned as a vector. 

#include "defuzz.h"
defuzzify::defuzzify() {
}
defuzzify::~defuzzify() {
}


vector<double> defuzzify::t1_tsk(t1Firing *aFiring_level, t1TSKOutputFSs *aOutFSet, MainWindow_t *stData) {
	//for all outputs, get the crisp output using weighted average defuzzification
				for (int _out = 0; _out < stData->vstOutputs[_out].vstMF.size(); _out++) {
					//construct yl and yr from rule
					vector<double> _y;
					double _y_ = 0, _Y_t1 = 0;
					double f_y = 0, sum_firing_level =0;
						
					for (int i = 0; i < stData->vstRules.size(); i++) {
						f_y = f_y + *((double *)(&aFiring_level->vT1FiringL[i])) * *((double *)(&aOutFSet->vstT1TSKOutputFSs[_out].vRuleOutput[i]));
						sum_firing_level = sum_firing_level + *((double *)(&aFiring_level->vT1FiringL[i]));
					}
					//Defuzzification Weighted Average for TSK
					_Y_t1 = f_y / sum_firing_level;
					_y_crisp.push_back(_Y_t1);//prepare output vector
				}//end of for all outputs
				 //Defuzzification
	return _y_crisp;
}

vector<double> defuzzify::ub(it2TSKOutputFSs *_tskOutputSet, MainWindow_t *stData) {
	//for all outputs, get the crisp output using UB output processing technique
				for (int _out = 0; _out < stData->vstOutputs[_out].vstMF.size(); _out++) {
				//Defuzzification
					_y_crisp.push_back((*((double *)(&_tskOutputSet->vstIt2TSKOutputFSs[_out].vRuleUMFOutput)) + *((double *)(&_tskOutputSet->vstIt2TSKOutputFSs[_out].vRuleLMFOutput))) / 2);//prepare output vector
				}//end of for all outputs		
	return _y_crisp;
}

vector<double> defuzzify::centroid(t1MamOutputFSs *_outputSet, MainWindow_t *stData) {
	//throw "not";
	//for all outputs, get the crisp output using centroid defuzzification technique
	for (int _out = 0; _out < stData->vstOutputs.size(); _out++) {
		
		double _temp =  0, _temp2 = 0;
		
		for (int i = 0; i < _outputSet->vstT1OutputFS[_out].vDescreteVals.size(); i++) {
			_temp = _temp + *((double *)(&_outputSet->vstT1OutputFS[_out].vAggregateSet[i])) * *((double *)(&_outputSet->vstT1OutputFS[_out].vDescreteVals[i]));
			_temp2 = _temp2 + *((double *)(&_outputSet->vstT1OutputFS[_out].vAggregateSet[i]));
		}

		//Store the output
		_y_crisp.push_back(_temp / _temp2);
	}//end of for all outputs

	return _y_crisp;
}

vector<double> defuzzify::nt(it2MamOutputFSs *_it2_outputFset, MainWindow_t *stData) {
	//for all outputs, get the crisp output using NT type reduction and defuzzification technique
	for (int _out = 0; _out < stData->vstOutputs.size(); _out++) {

		_uStar.clear();
		double _temp = 0, _temp2 = 0;

		for (int i = 0; i < _it2_outputFset->vstIt2OutputFS[_out].vDescreteVals.size(); i++) {
			_uStar.push_back((*((double *)(&_it2_outputFset->vstIt2OutputFS[_out].vAggregateSetUMF[i])) + *((double *)(&_it2_outputFset->vstIt2OutputFS[_out].vAggregateSetLMF[i]))) / 2);
			//cout << (*((double *)(&_it2_outputFset->vstIt2OutputFS[_out].vAggregateSetUMF[i])) + *((double *)(&_it2_outputFset->vstIt2OutputFS[_out].vAggregateSetLMF[i]))) / 2 << endl;
		}
		//Do Defuzzification
		for (int i = 0; i < _it2_outputFset->vstIt2OutputFS[_out].vDescreteVals.size(); i++) {
			_temp = _temp + *((double *)(&_it2_outputFset->vstIt2OutputFS[_out].vDescreteVals[i])) * ((double)(_uStar[i]));
			_temp2 = _temp2 + *((double *)(&_uStar[i]));
		}

		//Store the output
		if (_temp != 0){
			_y_crisp.push_back(_temp / _temp2);
		}
		else {
			_y_crisp.push_back(0);
		}

	}//end of for all outputs

	return _y_crisp;
}

vector<double> defuzzify::km() {
	throw "Not yet implemented";
}

vector<double> defuzzify::weightedAvg() {
	throw "Not yet implemented";
}

vector<double> defuzzify::height() {
	throw "Not yet implemented";
}

vector<double> defuzzify::gaussianMF() {
	throw "Not yet implemented";
}

vector<double> defuzzify::triangularMF() {
	throw "Not yet implemented";
}

vector<double> defuzzify::trapezoidalMF() {
	throw "Not yet implemented";
}

vector<double> defuzzify::it2Gaussian() {
	throw "Not yet implemented";
}