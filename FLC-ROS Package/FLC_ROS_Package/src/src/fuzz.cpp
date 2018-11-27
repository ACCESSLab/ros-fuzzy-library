//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code performs fuzzification processes. They return input fuzzy set for a type-1 and inteval type-2 FLSs 
//which are based on both Mamdani and TSK inference techniques

#include <exception>
#include <vector>
#include "fuzz.h"

using namespace std;

fuzzify::fuzzify() {
}
fuzzify::~fuzzify() {
}

t1InputFSs fuzzify::fuzzifyt1(vector<double> *aInputs, MainWindow_t *stData) {
		
		t1fv.vT1FuzzVal.clear();
		//For all inputs for T1
		for (int i = 0; i < stData->vstInputs.size(); i++) {
			t1fv.vT1FuzzVal.clear();
			//Fuzzify T1 MFs 
			for (int j = 0; j < stData->vstInputs[i].vstMF.size(); j++) {

				//InputMF_t stMF = stData->vstInputs[i].vstMF[j];
				if (stData->vstInputs[i].vstMF[j].sType == "tri") {
					t1fv.vT1FuzzVal.push_back(t1mfs.trimf(&(aInputs->at(i)), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				if (stData->vstInputs[i].vstMF[j].sType == "trap") {
					t1fv.vT1FuzzVal.push_back(t1mfs.trapmf(&(aInputs->at(i)), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dP4, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				if (stData->vstInputs[i].vstMF[j].sType == "gauss") {
					t1fv.vT1FuzzVal.push_back(t1mfs.gaussmf(&(aInputs->at(i)), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2));
				}
			}
			st1InputFSs.vstT1FuzzVal.push_back(t1fv);
		}// end of For all inputs for T1
		
	return st1InputFSs;
}

it2InputFSs fuzzify::fuzzifyit2(vector<double> *aInputs, MainWindow_t *stData)
{
	it2fv.vIt2LMFFuzzVal.clear();
	it2fv.vIt2UMFFuzzVal.clear();
	
		//For all inputs for UB
		for (int i = 0; i < stData->vstInputs.size(); i++) {
			it2fv.vIt2LMFFuzzVal.clear();
			it2fv.vIt2UMFFuzzVal.clear();
			//Fuzzify UMFss and LMFs
			for (int j = 0; j < stData->vstInputs[i].vstMF.size(); j++) {

				//InputMF_t stMF = stData->vstInputs[i].vstMF[j];
				if (stData->vstInputs[i].vstMF[j].sType == "utri") {
					it2fv.vIt2UMFFuzzVal.push_back(t1mfs.trimf(&(aInputs->at(i)), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				else if (stData->vstInputs[i].vstMF[j].sType == "utrap") {
					it2fv.vIt2UMFFuzzVal.push_back(t1mfs.trapmf(&(aInputs->at(i)), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dP4, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				else if (stData->vstInputs[i].vstMF[j].sType == "ugauss") {
					it2fv.vIt2UMFFuzzVal.push_back(t1mfs.gaussmf(&(aInputs->at(i)), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2));
				}
				//cout << _u_fuzzified_val[i][j] << endl;
				if (stData->vstInputs[i].vstMF[j].sType == "ltri") {
					it2fv.vIt2LMFFuzzVal.push_back(t1mfs.trimf(&(aInputs->at(i)), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				else if (stData->vstInputs[i].vstMF[j].sType == "ltrap") {
					it2fv.vIt2LMFFuzzVal.push_back(t1mfs.trapmf(&(aInputs->at(i)), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3, stData->vstInputs[i].vstMF[j].dP4, stData->vstInputs[i].vstMF[j].dMaximum));
				}
				else if (stData->vstInputs[i].vstMF[j].sType == "lgauss") {
					it2fv.vIt2LMFFuzzVal.push_back(t1mfs.gaussmf(&(aInputs->at(i)), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2));
				}
				//cout << _u_fuzzified_val[i][j] << endl;
				if (stData->vstInputs[i].vstMF[j].sType == "gausst2") {
					_gausst2MemVal = t2mfs.gausst2mf(&(aInputs->at(i)), stData->vstInputs[i].vstMF[j].dP1, stData->vstInputs[i].vstMF[j].dP2, stData->vstInputs[i].vstMF[j].dP3);
					it2fv.vIt2UMFFuzzVal.push_back(_gausst2MemVal[0]);
					it2fv.vIt2LMFFuzzVal.push_back(_gausst2MemVal[1]);
				}
			}		
			sit2InputFSs.vstIT2FuzzVal.push_back(it2fv);
		}// end of For all inputs for UB for upper bound or NT
		
		return sit2InputFSs;
}