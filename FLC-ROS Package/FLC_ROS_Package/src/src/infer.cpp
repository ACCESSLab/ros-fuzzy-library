//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code performs fuzzy inference processes. They return firing level and output fuzzy set for a type-1 and inteval type-2 FLSs 
//which are based on both Mamdani and TSK inference techniques

using namespace std;

#include "infer.h"
inference::inference() {
	//_outputFset = { { { 0 } } };
}
inference::~inference() {
}

t1Firing inference::_t1_firing_level(t1InputFSs *aFuzzified_val, MainWindow_t *stData) {

	_firing_level.vT1FiringL.clear();

	//for all rules, calculate the firing level
		for (int i = 0; i < stData->vstRules.size(); i++)
		{
			//get antecedents from each rule and extract them
			QString sString = stData->vstRules[i].sAntecedent;
			QStringList slTockens = sString.split(",");
			vAntecedents.clear();
			vValues.clear();

			for (int j = 0; j < slTockens.size(); j++)
			{
				vAntecedents.push_back((double &)(aFuzzified_val->vstT1FuzzVal[j].vT1FuzzVal[slTockens[j].toInt()-1]));
			}

			//Calculate the firing level according to configuration
			if (stData->vstRules[i].sInference == "And" && stData->sAndMethod == "Min") {
				foreach(int var, vAntecedents)
				{
					dVal = *std::min_element(vAntecedents.constBegin(), vAntecedents.constEnd());//find the minimum tnotm 
					//cout << "\n" << var;
				}
				_firing_level.vT1FiringL.push_back(dVal);
			}
			if (stData->vstRules[i].sInference == "And" && stData->sAndMethod == "Prod") {
				dVal = vAntecedents[0];
				for (int k = 1; k < vAntecedents.size(); k++)
				{
					dVal = dVal*vAntecedents[k];//find the product tnotm 
					//cout << "\n" << var;
				}
				_firing_level.vT1FiringL.push_back(dVal);
			}
			if (stData->vstRules[i].sInference == "Or") {
				foreach(int var, vAntecedents)
				{
					dVal = *std::max_element(vAntecedents.constBegin(), vAntecedents.constEnd());//find the maximum tnotm 
					//cout << "\n" << var;
				}
				_firing_level.vT1FiringL.push_back(dVal);
			}
		}//end of calculating type-1 firing levels
	
	return _firing_level;
}

t1MamOutputFSs inference::_type1_mamdani_processing(t1Firing *aFiring_level, MainWindow_t *stData) {
	double maxVal;
	_outputSet.vstT1OutputFS.clear();
		for (int i = 0; i < stData->vstOutputs.size(); i++) {//for all outputs
			//OutputData_t stOutput = stData->vstOutputs[i];
			vMFRanges.clear();
			vOPRanges.clear();
			_outputFset.vstT1OutputFS.clear();
			_outputSet.vstT1OutputFS.clear();
			t1MamOFS.vAggregateSet.clear();
			t1MamOFS.vDescreteVals.clear();

			QString sOString = stData->vstOutputs[i].sRange;
			QStringList slTockens = sOString.split(",");

			//vOPRanges.push_back(abs(slTockens[1].toInt()) - abs(slTockens[0].toInt()));//Store the range to find the maximum for knowing the size of the agg set vector

			for (int j = 0; j < stData->vstOutputs[i].vstMF.size(); j++) {//find the smallest MF
				//OutputMF_t stOMF = stData->vstOutputs[i].vstMF[j];
				if (stData->vstOutputs[i].vstMF[j].sType == "tri") {
					vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP3) - abs(stData->vstOutputs[i].vstMF[j].dP1));
				}
				if (stData->vstOutputs[i].vstMF[j].sType == "trap") {
					vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP4) - abs(stData->vstOutputs[i].vstMF[j].dP1));
				}
				if (stData->vstOutputs[i].vstMF[j].sType == "gauss") {
					vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP2));
				}
			}
		//}
		
		dQuantization = (*std::min_element(vMFRanges.constBegin(), vMFRanges.constEnd()) / 100); //get quantization = smallest MF/100
		dPrecssision = (abs(slTockens[1].toDouble()) - abs(slTockens[0].toDouble())) / dQuantization; //Get precession = Largest O/P range / quantization
		vector<double> zeros(dPrecssision, 0);
		vector<double> zeros1 = zeros;
	
			for (int _r = 0; _r < stData->vstRules.size(); _r++) {//for all rules
				t1MamOFFS.vAggregateSet.clear();
				t1MamOFFS.vAggregateSet.clear();
				if ((double *)(&aFiring_level->vT1FiringL[_r]) != 0) {//save computation time if firing level is zero. If so, all output membership values will be zero.

					QString sConsString = stData->vstRules[_r].sConsequent;//get the rule consequent from the configuration file
					QStringList slConsTockens = sConsString.split(",");//parse and extract the consequents
					double oFval = slTockens[0].toDouble();//the minimum range is the start point
					double oFuzVal = 0.0;
					for (int rOutput = 0; rOutput < int(dPrecssision); rOutput++)//for all discrete levels, find membership value and perform implication for the given rule
					{
						//find the membership value
						//if (stOMF.sType == "tri") {
						//int cons = slConsTockens[i].toInt();
						if (stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType ==  "tri") {
							oFuzVal=(t1mfs.trimf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));
							
						}
						else if (stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType == "trap") {
							oFuzVal=(t1mfs.trapmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));
							
						}
						else if (stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].sType == "gauss") {
							oFuzVal=(t1mfs.gaussmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2));
							
						}

						//do min clipping/implication
						if (oFuzVal >= *((double *)(&aFiring_level->vT1FiringL[_r]))) {
							t1MamOFFS.vAggregateSet.push_back(*((double *)(&aFiring_level->vT1FiringL[_r])));
							t1MamOFFS.vDescreteVals.push_back(oFval);
						}
						else { 
							t1MamOFFS.vAggregateSet.push_back(oFuzVal);
							t1MamOFFS.vDescreteVals.push_back(oFval);
						}
						oFval += dQuantization;
					}
				}
				else{ 
					double oFval = slTockens[0].toDouble();//the minimum range is the start point
					double oFuzVal = 0.0;
					for (int rOutput = 0; rOutput < int(dPrecssision); rOutput++)//for all discrete levels, find membership value and perform implication for the given rule
					{
						t1MamOFFS.vAggregateSet.push_back(0.0);
						t1MamOFFS.vDescreteVals.push_back(oFval);
						oFval += dQuantization;
					}					
				}
				_outputFset.vstT1OutputFS.push_back(t1MamOFFS);
			}
			//Find the Aggregate Set
			for (int l = 0; l < dPrecssision; l++) {
				maxVal = 0;
				for (int _r = 0; _r < stData->vstRules.size(); _r++) {
					maxVal = max(_outputFset.vstT1OutputFS[_r].vAggregateSet[l], maxVal);
				}
				t1MamOFS.vAggregateSet.push_back(maxVal);
				t1MamOFS.vDescreteVals.push_back(t1MamOFFS.vDescreteVals[l]);
			}	
			_outputSet.vstT1OutputFS.push_back(t1MamOFS);
		}
		return _outputSet;		
}
//Interval Type-2 System Inference

t1TSKOutputFSs inference::_type1_tsk_processing(vector<double> *aInputs, MainWindow_t *stData) {
	double tskOutput;
	_toutputSet.vstT1TSKOutputFSs.clear();
		
	for (int i = 0; i < stData->vstOutputs.size(); i++) {//for all outputs
		tskOutput = 0;
		_tRuleOutputSet.vRuleOutput.clear();
			for (int _r = 0; _r < stData->vstRules.size(); _r++) {//for all rules			
				QString sConsString = stData->vstRules[_r].sConsequent;//get the rule consequent from the configuration file
					QStringList slConsTockens = sConsString.split(":");//parse and extract the consequents for all rule outputs
					for (int j = 0; j < stData->vstInputs.size(); j++) {//for all inputs
							tskOutput += (slConsTockens[j].toDouble() * *(&(aInputs->at(i))));//add the configured tsk coefficients multiplied by the respective inputs
						}
					_tRuleOutputSet.vRuleOutput.push_back(tskOutput);//push the tsk output for all outputs of a single rule
					}
			_toutputSet.vstT1TSKOutputFSs.push_back(_tRuleOutputSet);
		}
	return _toutputSet;
}

it2Firing inference::_it2_firing_level(it2InputFSs *aFuzzified_val, MainWindow_t *stData) {

	_firing_level_t2.vIt2LMFFiringL.clear();
	_firing_level_t2.vIt2UMFFiringL.clear();

	//for all rules, calculate the firing level
	for (int i = 0; i < stData->vstRules.size(); i++)
	{
		//get antecedents from each rule and extract them
		QString sString = stData->vstRules[i].sAntecedent;
		//cout << sString.toStdString() << endl;
		QStringList slTockens = sString.split(",");
		vAntecedentsUMF.clear();
		vAntecedentsLMF.clear();
		vValues.clear();

		for (int j = 0; j < slTockens.size(); j++)
		{
			vAntecedentsUMF.push_back((double &)(aFuzzified_val->vstIT2FuzzVal[j].vIt2UMFFuzzVal[slTockens[j].toInt()-1]));//push the UMF fuzzified values
			//cout << (double &)(aFuzzified_val->vstIT2FuzzVal[j].vIt2UMFFuzzVal[slTockens[j].toInt() - 1]) <<endl;
			vAntecedentsLMF.push_back((double &)(aFuzzified_val->vstIT2FuzzVal[j].vIt2LMFFuzzVal[slTockens[j].toInt()-1]));//push the LMF fuzzified values
			//cout << (double &)(aFuzzified_val->vstIT2FuzzVal[j].vIt2LMFFuzzVal[slTockens[j].toInt() - 1]) << endl;
		}

		//Calculate the firing level according to configuration
		if (stData->vstRules[i].sInference == "And" && stData->sAndMethod == "Min") {
			//foreach(int var, vAntecedentsUMF)//note that UMF and LMF have the same numbers
			{
				dValUMF = *std::min_element(vAntecedentsUMF.constBegin(), vAntecedentsUMF.constEnd());//find the minimum tnotm for UMF
				//cout << dValUMF << endl;
				dValLMF = *std::min_element(vAntecedentsLMF.constBegin(), vAntecedentsLMF.constEnd());//find the minimum tnotm for LMF																			 
				//cout << dValLMF << endl;
			}
			_firing_level_t2.vIt2UMFFiringL.push_back(dValUMF); //cout << dValUMF << endl;
			_firing_level_t2.vIt2LMFFiringL.push_back(dValLMF); //cout << dValLMF << endl;
		}
		if (stData->vstRules[i].sInference == "And" && stData->sAndMethod == "Prod") {
			dValUMF = vAntecedentsUMF[0];
			dValLMF = vAntecedentsLMF[0];
			for (int k = 1; k < vAntecedentsUMF.size(); k++)
			{
				dValUMF = dValUMF*vAntecedentsUMF[k];//find the product tnotm 
				dValLMF = dValLMF*vAntecedentsLMF[k];//find the product tnotm 
			}
			_firing_level_t2.vIt2UMFFiringL.push_back(dValUMF);
			_firing_level_t2.vIt2LMFFiringL.push_back(dValLMF);
		}
		if (stData->vstRules[i].sInference == "Or") {
			//foreach(int var, vAntecedentsUMF)
			{
				dValUMF = *std::max_element(vAntecedentsUMF.constBegin(), vAntecedentsUMF.constEnd());//find the maximum tnotm 
				dValLMF = *std::max_element(vAntecedentsLMF.constBegin(), vAntecedentsLMF.constEnd());//find the maximum tnotm
			}
			_firing_level_t2.vIt2UMFFiringL.push_back(dValUMF);
			_firing_level_t2.vIt2LMFFiringL.push_back(dValLMF);
		}
	}//end of calculating interval type-2 firing level
	return _firing_level_t2;
}

it2MamOutputFSs inference::_it2_mamdani_processing(it2Firing *aFiring_level, MainWindow_t *stData) {
	double maxValUMF, maxValLMF, oFval;

	for (int i = 0; i < stData->vstOutputs.size(); i++) {//for all outputs
		vMFRanges.clear();
		//vOPRanges.clear();
		_outputFset.vstT1OutputFS.clear();
		_outputFsetFinal.vAggregateSetLMF.clear();
		_outputFsetFinal.vAggregateSetUMF.clear();
		_outputFsetFinal.vDescreteVals.clear();
		_it2_ruleoutputFset.vstIt2OutputFS.clear();

		QString sOString = stData->vstOutputs[i].sRange;//get the output range
		QStringList slTockens = sOString.split(",");

		//vOPRanges.push_back(abs(slTockens[1].toInt()) - abs(slTockens[0].toInt()));//Store the range to find the maximum for knowing the size of the agg set vector

		for (int j = 0; j < stData->vstOutputs[i].vstMF.size(); j++) {//find the smallest MF
																	  //OutputMF_t stOMF = stData->vstOutputs[i].vstMF[j];
			if (stData->vstOutputs[i].vstMF[j].sType == "utri" || stData->vstOutputs[i].vstMF[j].sType == "ltri") {
				vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP3) - abs(stData->vstOutputs[i].vstMF[j].dP1));
			}
			else if (stData->vstOutputs[i].vstMF[j].sType == "utrap" || stData->vstOutputs[i].vstMF[j].sType == "ltrap") {
				vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP4) - abs(stData->vstOutputs[i].vstMF[j].dP1));
			}
			else if (stData->vstOutputs[i].vstMF[j].sType == "ugauss" || stData->vstOutputs[i].vstMF[j].sType == "lgauss") {
				vMFRanges.push_back(abs(stData->vstOutputs[i].vstMF[j].dP2));
			}
		}
		//}
		//cout << *std::min_element(vMFRanges.constBegin(), vMFRanges.constEnd()) << endl;
		dQuantization = (*std::min_element(vMFRanges.constBegin(), vMFRanges.constEnd()) / 100); //get quantization = smallest MF/100
		dPrecssision = (abs(slTockens[1].toDouble()) - abs(slTockens[0].toDouble())) / dQuantization; //Get precession = Largest O/P range / quantization
		vector<double> zeros(dPrecssision, 0);
		vector<double> zeros1 = zeros;
		//oFval = slTockens[0].toDouble();//[0] is the starting point of the output range

		for (int _r = 0; _r < stData->vstRules.size(); _r++) {//for all rules
			_it2OutputFset.vAggregateSetUMF.clear();
			_it2OutputFset.vAggregateSetLMF.clear();
			_it2OutputFset.vDescreteVals.clear();

			if ((double *)(&aFiring_level->vIt2UMFFiringL[_r]) != 0 || (double *)(&aFiring_level->vIt2LMFFiringL[_r]) != 0) {//save computation time if firing level is zero. If so, all output membership values will be zero.

				QString sConsString = stData->vstRules[_r].sConsequent;//get the rule consequent from the configuration file
				QStringList slConsTockens = sConsString.split(",");//parse and extract the consequents
				double oFuzValUMF, oFuzValLMF;
				//for (int oMfs = 0; oMfs < stData->vstOutputs[i].vstMF.size(); oMfs++) {
					oFval = slTockens[0].toDouble();//[0] is the starting point of the output range
					for (int rOutput = 0; rOutput < int(dPrecssision); rOutput++)//for all discrete levels, find membership value and perform implication for the given rule
					{
						//find the membership value
						//if (stOMF.sType == "tri") {
						//int cons = slConsTockens[i].toInt();
						if (stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt())*2)-2].sType == "utri" ) {//index the selected output MF...all outputs for now need to be defined in order
							oFuzValUMF = (t1mfs.trimf((double *)(&oFval), stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dP1, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dP2, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dP3, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dMaximum));
							//oFuzValLMF = (t1mfs.trimf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));
							//cout << oFuzValUMF << endl;
						}
						else if (stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].sType == "utrap") {
							oFuzValUMF = (t1mfs.trapmf((double *)(&oFval), stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dP1, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dP2, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dP3, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dP3, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dMaximum));
							//oFuzValLMF = (t1mfs.trapmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));

						}
						else if (stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].sType == "ugauss") {
							oFuzValUMF = (t1mfs.gaussmf((double *)(&oFval), stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dP1, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 2].dP2));
							//oFuzValLMF = (t1mfs.gaussmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2));
						}
						if (stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].sType == "ltri") {
							//oFuzValUMF = (t1mfs.trimf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));
							oFuzValLMF = (t1mfs.trimf((double *)(&oFval), stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dP1, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dP2, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dP3, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dMaximum));
							//cout << oFuzValUMF << endl;
						}
						else if (stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].sType == "ltrap") {
							//oFuzValUMF = (t1mfs.trapmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP3, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dMaximum));
							oFuzValLMF = (t1mfs.trapmf((double *)(&oFval), stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dP1, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dP2, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dP3, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dP3, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dMaximum));

						}
						else if (stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].sType == "ugauss") {
							//oFuzValUMF = (t1mfs.gaussmf((double *)(&oFval), stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP1, stData->vstOutputs[i].vstMF[slConsTockens[i].toInt()].dP2));
							oFuzValLMF = (t1mfs.gaussmf((double *)(&oFval), stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dP1, stData->vstOutputs[i].vstMF[((slConsTockens[i].toInt()) * 2) - 1].dP2));
						}

						//do clipping/implication for UMF
						if (oFuzValUMF > *((double *)(&aFiring_level->vIt2UMFFiringL[_r]))) {
							_it2OutputFset.vAggregateSetUMF.push_back(*((double *)(&aFiring_level->vIt2UMFFiringL[_r])));
							//cout << oFuzValUMF << endl;
						}
						else {
							_it2OutputFset.vAggregateSetUMF.push_back(oFuzValUMF);
							//cout << oFuzValUMF << endl;
						}
						//do clipping/implication for LMF
						if (oFuzValLMF > *((double *)(&aFiring_level->vIt2LMFFiringL[_r]))) {
							_it2OutputFset.vAggregateSetLMF.push_back(*((double *)(&aFiring_level->vIt2LMFFiringL[_r])));
						}
						else { _it2OutputFset.vAggregateSetLMF.push_back(oFuzValLMF); }
						_it2OutputFset.vDescreteVals.push_back(oFval);
						oFval += dQuantization;
						//cout << _it2OutputFset.vAggregateSetLMF[rOutput] << "\t"<< oFval << endl;
					}	//end of for precession	
				//}//end of for all mfs
			}
			else { 
				for (int rOutput = 0; rOutput < int(dPrecssision); rOutput++)//for all discrete levels, find membership value and perform implication for the given rule
				{
					_it2OutputFset.vAggregateSetUMF.push_back(0);
					_it2OutputFset.vAggregateSetLMF.push_back(0);
					_it2OutputFset.vDescreteVals.push_back(oFval);
					oFval += dQuantization;
				}
				}
			_it2_ruleoutputFset.vstIt2OutputFS.push_back(_it2OutputFset);
		}//end of for all rules
		//Find the Aggregate Set
		for (int l = 0; l < dPrecssision; l++) {
			maxValUMF = 0; maxValLMF = 0;
			for (int _r = 0; _r < stData->vstRules.size(); _r++) {
				maxValUMF = max(_it2_ruleoutputFset.vstIt2OutputFS[_r].vAggregateSetUMF[l], maxValUMF);
				maxValLMF = max(_it2_ruleoutputFset.vstIt2OutputFS[_r].vAggregateSetLMF[l], maxValLMF);
			}
			_outputFsetFinal.vAggregateSetUMF.push_back(maxValUMF);
			_outputFsetFinal.vAggregateSetLMF.push_back(maxValLMF);
			_outputFsetFinal.vDescreteVals.push_back(_it2OutputFset.vDescreteVals[l]);
			//cout << maxValUMF << "\t"<<maxValLMF<<"\t"<< _it2OutputFset.vDescreteVals[l]<<endl;
		}
		_it2_outputFset.vstIt2OutputFS.push_back(_outputFsetFinal);
	}
	return _it2_outputFset;
}

it2TSKOutputFSs inference::_it2_tsk_processing(vector<double> *aInputs, it2Firing *aFiring_level, MainWindow_t *stData) {
	double tskOutputl, tskOutputu;
	QStringList slConsTockens1, slConsTockens2, slConsTockens3, slConsTockens4;
	//vector<double> _y_l;
	//vector<double> _y_r;
	_outputSet.vstT1OutputFS.clear();
	//Example 1 input 1 output IT2 TSK rule output....0,1:2,3|0,1:2,3
	//for (int i = 0; i < stData->vstOutputs.size(); i++) {//for all outputs
	for (int _r = 0; _r < stData->vstRules.size(); _r++) {//for all rules
		QString sConsString = stData->vstRules[_r].sConsequent;//get the rule consequent from the configuration file
		QStringList _sConsString = sConsString.split(",");
		QString sConsStringtskco = stData->vstOutputs[sConsString_]
		QStringList slConsTockens = sConsString.split("|");//parse and extract the consequents for all rule outputs
		for (int i = 0; i < stData->vstOutputs.size(); i++) {//for all outputs
			QStringList slConsTockens2 = slConsTockens[i].split(":");//parse and extract the consequents
			slConsTockens3 = slConsTockens2[0].split(",");
			tskOutputl = slConsTockens3[0].toDouble();//get col
			tskOutputu = slConsTockens3[1].toDouble();//get cor
			for (int j = 0; j < stData->vstInputs.size(); j++) {//for all inputs
				//slConsTockens3 = slConsTockens[j].split("|");
				slConsTockens4 = slConsTockens2[j+1].split(",");
				tskOutputl += (slConsTockens4[0].toDouble() * *(&(aInputs->at(i))));
				tskOutputu += (slConsTockens4[1].toDouble() * *(&(aInputs->at(i))));//add the configured tsk coefficients multiplied by the respective inputs
			}
			//for each rule, yl = Col + C1l*Input1 + C2l*Input2 + ... Cpl*Inputp, yr = Cor + C1r*Input1 + C2r*Input2 + ... Cpr*Inputp
			rOutputs.ruleOutputs[i]._y_l_.push_back(min(tskOutputl, tskOutputu));//push the yl tsk output for all outputs of a single rule
			rOutputs.ruleOutputs[i]._y_r_.push_back(max(tskOutputl, tskOutputu));//push the yr tsk output for all outputs of a single rule
			
		}
	}

	//for all outputs, get the crisp output using UB output processing technique
	for (int _out = 0; _out < stData->vstOutputs.size(); _out++) {
		//construct yl and yr from rule
		//vector<double> _y_l;// = rOutputs.ruleOutputs[0]._y_l_;
		//vector<double> _y_r;
		//double _y_l_ = 0, _y_r_ = 0;
		double fl_yl = 0, fh_yl = 0, fl_yr = 0, fh_yr = 0.0;
		double A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;
		double yl_hi = 0, yr_lo = 0, yl_lo = 0, yr_hi = 0, sum_lfiring_level = 0, sum_ufiring_level = 0;
		
		//Inner Bounds Calculation
		for (int i = 0; i < stData->vstRules.size(); i++) {
			fl_yl = fl_yl + *((double *)(&aFiring_level->vIt2LMFFiringL[i])) * rOutputs.ruleOutputs[i]._y_l_[i];//aLfiring_level[i]
			fh_yl = fh_yl + *((double *)(&aFiring_level->vIt2UMFFiringL[i])) * rOutputs.ruleOutputs[i]._y_l_[i];//aUfiring_level[i]
			fl_yr = fl_yr + *((double *)(&aFiring_level->vIt2LMFFiringL[i])) * rOutputs.ruleOutputs[i]._y_r_[i];//aLfiring_level[i]
			fh_yr = fh_yr + *((double *)(&aFiring_level->vIt2UMFFiringL[i])) * rOutputs.ruleOutputs[i]._y_r_[i];//aUfiring_level[i]
			sum_lfiring_level = sum_lfiring_level + *((double *)(&aFiring_level->vIt2LMFFiringL[i]));
			sum_ufiring_level = sum_ufiring_level + *((double *)(&aFiring_level->vIt2UMFFiringL[i]));
		}
		if (sum_lfiring_level != 0 && sum_ufiring_level != 0) {//if these values are 0, it will generate _nan this is a drawback of UB
			fl_yl = fl_yl / sum_lfiring_level;
			fh_yl = fh_yl / sum_ufiring_level;
			fl_yr = fl_yr / sum_lfiring_level;
			fh_yr = fh_yr / sum_ufiring_level;

			yl_hi = min(fl_yl, fh_yl);
			yr_lo = max(fh_yr, fl_yr);

			//Outer Bounds Calculation
			for (int i = 0; i < stData->vstRules.size(); i++) {
				A = A + *((double *)(&aFiring_level->vIt2UMFFiringL[i])) - *((double *)(&aFiring_level->vIt2LMFFiringL[i]));//aUfiring_level[i] - aLfiring_level[i]
				C = C + *((double *)(&aFiring_level->vIt2UMFFiringL[i])) * (rOutputs.ruleOutputs[i]._y_l_[i] - rOutputs.ruleOutputs[i]._y_l_[0]);
				D = D + *((double *)(&aFiring_level->vIt2UMFFiringL[i])) * (rOutputs.ruleOutputs[i]._y_l_[stData->vstRules.size() - 1] - rOutputs.ruleOutputs[i]._y_l_[i]);
				E = E + *((double *)(&aFiring_level->vIt2UMFFiringL[i])) * (rOutputs.ruleOutputs[i]._y_r_[i] - rOutputs.ruleOutputs[i]._y_r_[0]);
				F = F + *((double *)(&aFiring_level->vIt2UMFFiringL[i])) * (rOutputs.ruleOutputs[i]._y_r_[stData->vstRules.size() - 1] - rOutputs.ruleOutputs[i]._y_r_[i]);
			}	B = sum_lfiring_level * sum_ufiring_level;
			if (B != 0 && (C + D) != 0 && (E + F) != 0) {
				yl_lo = yl_hi - ((A / B) * (C*D) / (C + D));
				yr_hi = yr_lo + ((A / B) * (E*F) / (E + F));
			}
			else {//if _nan, output is set to 0
				yl_lo = 0;
				yr_hi = 0;
			}
		}
		else {//if _nan, output is set to 0
			yl_lo = 0;
			yr_hi = 0;
		}
		//Final Uncertainty Bounds
		_y_left = (yl_hi + yl_lo) / 2;
		_y_right = (yr_hi + yr_lo) / 2;

		_tskBounds.vRuleLMFOutput.push_back(_y_left);
		_tskBounds.vRuleUMFOutput.push_back(_y_right);
		_tskOutputSet.vstIt2TSKOutputFSs.push_back(_tskBounds);
	}
	return _tskOutputSet;
}