//Authors: Abel Teklu Hilemichael (athailem@aggies.ncat.edu), Ali Karimoddini (akarimod@ncat.edu)
//About: The work has been done in ACESS Laboratory (http://accesslab.net/) at NC A&T State University
//About: Structure definition of FLS Properties

#ifndef COMMONDEF_H
#define COMMONDEF_H
#include <QString>
#include <QVector>

struct InputMF_t
{
    // name="MF1l" type="Triangular" P1="1" P2="2" P3="3" P4="4" maximum="0.9"
    QString sName;
    QString sType;
    double dP1;
    double dP2;
    double dP3;
    double dP4;
    double dMaximum;
};

struct OutputMF_t
{
    QString sName;
    QString sType;
    double dP1;
    double dP2;
    double dP3;
    double dP4;
    double dMaximum;
    QString sTSKCoefficients;
};

struct Rule_t
{
    QString sAntecedent;
    QString sConsequent;
    QString sInference;
    double dWeight;
};

struct InputData_t
{
    QString sName;
    QString sRange;
    QVector<InputMF_t> vstMF;
};

struct OutputData_t
{
    QString sName;
    QString sRange;
    QVector<OutputMF_t> vstMF;
};


struct MainWindow_t
{
    QString               sFLSName;
    bool                  bType1;//aSetID 0 type1 ---1 was Interval type2
    bool                  bInterval2;
    bool                  bTSK;
    bool                  bMamdani;
    int                   nNumberOfInputs;//_numInputs //_numofMFs we didnt save on the gui(i need to perhaps use qt functionalities to get it)
    int                   nNumberOFOutputs;
    int                   nNumberOfRules;
    QString               sProcessingMethod;//UB
    QString               sAndMethod;
    QString               sOrMethod;
    QString               sAggMethod;
    QString               sImplicationMethod;

    QVector<InputData_t>  vstInputs;
    QVector<OutputData_t> vstOutputs;
    QVector<Rule_t>       vstRules;
};

struct t1FuzzifiedVal
{
	QVector<double>  vT1FuzzVal;
};

struct it2FuzzifiedVal
{
	QVector<double>  vIt2UMFFuzzVal;
	QVector<double>  vIt2LMFFuzzVal;
};

struct t1InputFSs
{
	QVector<t1FuzzifiedVal>  vstT1FuzzVal;
};

struct it2InputFSs
{
	QVector<it2FuzzifiedVal>  vstIT2FuzzVal;
};

struct t1Firing
{
	QVector<double>  vT1FiringL;
};

struct it2Firing
{
	QVector<double>  vIt2UMFFiringL;
	QVector<double>  vIt2LMFFiringL;
};

struct t1MamOutputFS
{
	QVector<double>  vAggregateSet;
	QVector<double>  vDescreteVals;
};

struct t1MamOutputFSs
{
	QVector<t1MamOutputFS>  vstT1OutputFS;
};

struct it2MamOutputFS
{
	QVector<double>  vAggregateSetUMF;
	QVector<double>  vAggregateSetLMF;
	QVector<double>  vDescreteVals;
};

struct it2MamOutputFSs
{
	QVector<it2MamOutputFS>  vstIt2OutputFS;
};

struct t1TSKOutputFS
{
	QVector<double>  vRuleOutput;
};

struct t1TSKOutputFSs
{
	QVector<t1TSKOutputFS>  vstT1TSKOutputFSs;
};

struct it2TSKOutputFS
{
	QVector<double>  vRuleUMFOutput;
	QVector<double>  vRuleLMFOutput;
};

struct it2TSKOutputFSs
{
	QVector<it2TSKOutputFS>  vstIt2TSKOutputFSs;
};

struct it2TSKrOutput
{
	QVector<double>  _y_l_;
	QVector<double>  _y_r_;
};

struct it2TSKrOutputs
{
	QVector<it2TSKrOutput>  ruleOutputs;
};

#endif // COMMONDEF_H


















