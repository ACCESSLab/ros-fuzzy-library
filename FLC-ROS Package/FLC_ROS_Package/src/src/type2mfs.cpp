//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: The operations in this code return the membership value for the upper and lower embedded type-1 memberships of 
// an interval type-2 membership function.

#include "type2mfs.h"

type2mfs::type2mfs() {
}

type2mfs::~type2mfs() {
}

vector<double> type2mfs::gausst2mf(double *aInput, double aP1, double aP2, double aP3) {
	//p1 mean 1, p2 mean2, p3 sd
	//_mfval vector. first elemenet is umf while 2nd element is lmf
	_mfVal.clear();
	if (*aInput < aP1) {
		_mfVal.push_back(exp((-pow((*aInput - aP1), 2)) / (2 * (pow(aP3, 2)))));
	}
	if (*aInput >= aP1 && *aInput <= aP2) {
		_mfVal.push_back(1);
	}
	else {
		_mfVal.push_back(exp((-pow((*aInput - aP2), 2)) / (2 * (pow(aP3, 2)))));
	}

	if (*aInput <= ((aP1 + aP2)/2)) {
		_mfVal.push_back(exp((-pow((*aInput - aP2), 2)) / (2 * (pow(aP3, 2)))));
	}
	else {
		_mfVal.push_back(exp((-pow((*aInput - aP1), 2)) / (2 * (pow(aP3, 2)))));
	}

	return (_mfVal);
}