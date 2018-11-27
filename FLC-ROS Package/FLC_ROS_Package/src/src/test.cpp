//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: Test Code

#include "iostream"
#include <vector>
#include <algorithm>
#include "flslib.h"
#include <ctime>
#include "commondef.h"
#include "XMLReader.h"
//#include <QMessageBox>

using namespace std;
std::string sFIleName_i;

//fuzzy fuz;
flslib fuz;

int main() {
	clock_t begin = clock();
	//cout << "Hello World";
	//fuz.publishOutput();
	/*fuz.fuzzify();
	fuz.infer();
	fuz.defuzzify();*/
	MainWindow_t stData;
	XMLReader Reader(&stData);
	sFIleName_i = "C:/Users/Abel/Transporter/Transporter/Abel Hailemichael/Workspace/FLS Library/FLS_Library_workspace/src/Example.xml";
	//sFIleName_i = "C:/Users/Abel/Desktop/hi.xml";
	Reader.ReadXMLFile(QString(sFIleName_i.c_str()));
	
	//cout << stData.vstInputs.size() << endl << 1200 << endl;
	for (int i = 0; i < stData.vstRules.size(); i++) {
		//cout << stData.vstRules[i].sAntecedent.toStdString() << endl;
	}
	double z;
	/*cout << stData.vstInputs[0].sName.toStdString() << endl;
	cout << stData.vstInputs[0].vstMF[0].sName.toStdString() << endl;
	cout << stData.vstInputs[0].vstMF[0].dP3 << endl;
	z = stData.vstInputs[0].vstMF[0].dP3;
	cout << z << endl;*/
	//int *a;//
	//int a = 3;
	//cout << &a << "-" << *a << "-" << endl;
	vector<double> input = {4,4};
	vector<double> output= fuz.runFuzzy(input, &stData);
	
	cout << output[0] << endl;
	/*output = fuz.runFuzzy(input);
	cout << output[0] <<endl;
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_secs << endl;
	system("pause");*/
	system("pause");
	return 0; 
}