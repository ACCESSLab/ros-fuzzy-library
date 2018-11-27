#include "XMLReader.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#define TRUE_TEXT   "True"
#define FALSE_TEXT  "False"
#include <QMessageBox>
#include "MetaRecord.h"

XMLReader::XMLReader(MainWindow_t* pData_i)
{
    m_pstData = pData_i;
}


bool XMLReader::ReadXMLFile(QString sFileName_i)
{
    MetaRecordReader Reader;
    Reader.read(sFileName_i);
    const MetaRecordItem* Record = Reader.getResult();
    if (Record == 0)
        return false;
    MetaRecordItem* pFLS = Record->getChildItem("FLS");
    if (pFLS != 0)
    {
        ReadFLSChildren(pFLS);
    }
    ReadInputs(Record);
    ReadOutputs(Record);
    ReadRules(Record);
    return true;
}

bool XMLReader::ReadFLSChildren(MetaRecordItem* pFLS)
{
    MetaRecordItem* pName = pFLS->getChildItem("Name");
    if (pName != 0)
    {
        m_pstData->sFLSName = pName->getValue();
    }
    MetaRecordItem* pType1 = pFLS->getChildItem("Type1");
    if (pType1 != 0)
    {
        m_pstData->bType1 = (pType1->getValue()==TRUE_TEXT);
    }
    MetaRecordItem* pInterval_T2 = pFLS->getChildItem("Interval_T2");
    if (pInterval_T2 != 0)
    {
        m_pstData->bInterval2 = (pInterval_T2->getValue() == TRUE_TEXT);
    }
    MetaRecordItem* pTSK = pFLS->getChildItem("TSK");
    if (pTSK != 0)
    {
        m_pstData->bTSK = (pTSK->getValue() == TRUE_TEXT);
    }
    MetaRecordItem* pMamdani = pFLS->getChildItem("Mamdani");
    if (pMamdani != 0)
    {
        m_pstData->bMamdani = (pMamdani->getValue() == TRUE_TEXT);
    }
    MetaRecordItem* pNumber_of_Inputs = pFLS->getChildItem("Number_of_Inputs");
    if (pNumber_of_Inputs != 0)
    {
        m_pstData->nNumberOfInputs = pNumber_of_Inputs->getValue().toInt();
    }
    MetaRecordItem* pNumber_of_Outputs = pFLS->getChildItem("Number_of_Outputs");
    if (pNumber_of_Outputs != 0)
    {
        m_pstData->nNumberOFOutputs = pNumber_of_Outputs->getValue().toInt();
    }
    MetaRecordItem* pNumber_of_Rules = pFLS->getChildItem("Number_of_Rules");
    if (pNumber_of_Rules != 0)
    {
        m_pstData->nNumberOfRules = pNumber_of_Rules->getValue().toInt();
    }
    MetaRecordItem* pOutput_Processing_Method = pFLS->getChildItem("Output_Processing_Method");
    if (pOutput_Processing_Method != 0)
    {
        m_pstData->sProcessingMethod = pOutput_Processing_Method->getValue();
    }
    MetaRecordItem* pAnd_method = pFLS->getChildItem("And_method");
    if (pAnd_method != 0)
    {
        m_pstData->sAndMethod = pAnd_method->getValue();
    }
    MetaRecordItem* pOr_method = pFLS->getChildItem("Or_method");
    if (pOr_method != 0)
    {
        m_pstData->sOrMethod = pOr_method->getValue();
    }
    MetaRecordItem* pImplication_method = pFLS->getChildItem("Implication_method");
    if (pImplication_method != 0)
    {
        m_pstData->sImplicationMethod = pImplication_method->getValue();
    }
    MetaRecordItem* pAggregation_method = pFLS->getChildItem("Aggregation_method");
    if (pAggregation_method != 0)
    {
        m_pstData->sAggMethod = pAggregation_method->getValue();
    }
    
    return true;
}


bool XMLReader::ReadInputs(const MetaRecordItem* pSystem_i)
{
    m_pstData->vstInputs.clear();
    int nIdx = 1;
    for (;;)
    {
        MetaRecordItem* pInput = pSystem_i->getChildItem("Input" + QString::number(nIdx++));
        if (pInput == 0)
        {
            break;
        }
        InputData_t stInput;
        MetaRecordItem* pName = pInput->getChildItem("Name");
        if (pName != 0)
        {
            stInput.sName = pName->getValue();
        }
        MetaRecordItem* pRange = pInput->getChildItem("Range");
        if (pRange != 0)
        {
            stInput.sRange = pRange->getValue();
        }
        int nMFIdx = 1;
        for (;;)
        {
            MetaRecordItem* pMF = pInput->getChildItem("MF" + QString::number(nMFIdx++));
            if (pMF == 0)
            {
                break;
            }
            InputMF_t stInMF;
            MetaRecordItem* pMFName = pMF->getChildItem("name");
            if (pMFName != 0)
            {
                stInMF.sName = pMFName->getValue();
            }
            MetaRecordItem* pMFType = pMF->getChildItem("type");
            if (pMFType != 0)
            {
                stInMF.sType = pMFType->getValue();
            }
            MetaRecordItem* pMFP1 = pMF->getChildItem("P1");
            if (pMFP1 != 0)
            {
                stInMF.dP1 = pMFP1->getValue().toDouble();
            }
            MetaRecordItem* pMFP2 = pMF->getChildItem("P2");
            if (pMFP2 != 0)
            {
                stInMF.dP2 = pMFP2->getValue().toDouble();
            }
            MetaRecordItem* pMFP3 = pMF->getChildItem("P3");
            if (pMFP3 != 0)
            {
                stInMF.dP3 = pMFP3->getValue().toDouble();
            }
            MetaRecordItem* pMFP4 = pMF->getChildItem("P4");
            if (pMFP4 != 0)
            {
                stInMF.dP4 = pMFP4->getValue().toDouble();
            }
            MetaRecordItem* pMFMaximum = pMF->getChildItem("maximum");
            if (pMFMaximum != 0)
            {
                stInMF.dMaximum = pMFMaximum->getValue().toDouble();
            }
            stInput.vstMF.push_back(stInMF);
        }
        m_pstData->vstInputs.push_back(stInput);
    }
    return true;
}


bool XMLReader::ReadOutputs(const MetaRecordItem* pSystem_i)
{
    m_pstData->vstOutputs.clear();
    int nIdx = 1;
    for (;;)
    {
        MetaRecordItem* pInput = pSystem_i->getChildItem("Output" + QString::number(nIdx++));
        if (pInput == 0)
        {
            break;
        }
        OutputData_t stOutput;
        MetaRecordItem* pName = pInput->getChildItem("Name");
        if (pName != 0)
        {
            stOutput.sName = pName->getValue();
        }
        MetaRecordItem* pRange = pInput->getChildItem("Range");
        if (pRange != 0)
        {
            stOutput.sRange = pRange->getValue();
        }
        int nMFIdx = 1;
        for (;;)
        {
            MetaRecordItem* pMF = pInput->getChildItem("MF" + QString::number(nMFIdx++));
            if (pMF == 0)
            {
                break;
            }
            OutputMF_t stOutMF;

            QString sMF = pMF->getValue();
            QStringList slItems = sMF.split('~');
            foreach (QString sItem, slItems)
            {
                if (sItem.contains("Antecedent"))
                {
                    stOutMF.sName = sItem.split('\'').at(1);
                }
                else if (sItem.contains("type"))
                {
                    stOutMF.sType = sItem.split('\'').at(1);
                }
                else if (sItem.contains("P1"))
                {
                    stOutMF.dP1 = sItem.split('\'').at(1).toDouble();
                }
                else if (sItem.contains("P2"))
                {
                    stOutMF.dP2 = sItem.split('\'').at(1).toDouble();
                }
                else if (sItem.contains("P3"))
                {
                    stOutMF.dP3 = sItem.split('\'').at(1).toDouble();
                }
                else if (sItem.contains("P4"))
                {
                    stOutMF.dP4 = sItem.split('\'').at(1).toDouble();
                }
                else if (sItem.contains("maximum"))
                {
                    stOutMF.dMaximum = sItem.split('\'').at(1).toDouble();
                }
                else if (sItem.contains("TSK_Coefficients"))
                {
                    stOutMF.sTSKCoefficients = sItem.split('\'').at(1);
                }
            }
        //    MetaRecordItem* pMFName = pMF->getChildItem("name");
        //    if (pMFName != 0)
        //    {
        //        stOutMF.sName = pMFName->getValue();
        //    }
        //    MetaRecordItem* pMFType = pMF->getChildItem("type");
        //    if (pMFType != 0)
        //    {
        //        stOutMF.sType = pMFType->getValue();
        //    }
        //    MetaRecordItem* pMFP1 = pMF->getChildItem("P1");
        //    if (pMFP1 != 0)
        //    {
        //        stOutMF.nP1 = pMFP1->getValue().toDouble();
        //    }
        //    MetaRecordItem* pMFP2 = pMF->getChildItem("P2");
        //    if (pMFP2 != 0)
        //    {
        //        stOutMF.nP2 = pMFP2->getValue().toDouble();
        //    }
        //    MetaRecordItem* pMFP3 = pMF->getChildItem("P3");
        //    if (pMFP3 != 0)
        //    {
        //        stOutMF.nP3 = pMFP3->getValue().toDouble();
        //    }
        //    MetaRecordItem* pMFP4 = pMF->getChildItem("P4");
        //    if (pMFP4 != 0)
        //    {
        //        stOutMF.nP4 = pMFP4->getValue().toDouble();
        //    }
        //    MetaRecordItem* pMFMaximum = pMF->getChildItem("maximum");
        //    if (pMFMaximum != 0)
        //    {
        //        stOutMF.fMaximum = pMFMaximum->getValue().toDouble();
        //    }
        //    MetaRecordItem* pMFTSK_Coefficients = pMF->getChildItem("TSK_Coefficients");
        //    if (pMFTSK_Coefficients != 0)
        //    {
        //        stOutMF.sTSKCoefficients = pMFTSK_Coefficients->getValue();
        //    }
            stOutput.vstMF.push_back(stOutMF);
        }
        m_pstData->vstOutputs.push_back(stOutput);
    }
    return true;
}

bool XMLReader::ReadRules(const MetaRecordItem * pSystem_i)
{
    m_pstData->vstRules.clear();
    MetaRecordItem* pRules = pSystem_i->getChildItem("Rules");
    if (pRules == 0)
        return true;
    int nIdx = 1;
    for (;;)
    {
        MetaRecordItem* pCurrentRule = pRules->getChildItem("R" + QString::number(nIdx++));
        if (pCurrentRule == 0)
        {
            break;
        }
        Rule_t stRule;
        QString sRule = pCurrentRule->getValue();
        QStringList slItems = sRule.split('~');
        foreach (QString sItem , slItems)
        {
            if (sItem.contains("Antecedent"))
            {
                stRule.sAntecedent = sItem.split('\'').at(1);
            }
            else if (sItem.contains("Consequent"))
            {
                stRule.sConsequent = sItem.split('\'').at(1);
            }
            else if (sItem.contains("Inference"))
            {
                stRule.sInference = sItem.split('\'').at(1);
            }
            else if (sItem.contains("Weight"))
            {
                stRule.dWeight = sItem.split('\'').at(1).toDouble();
            }
        }
        //MetaRecordItem* pAntecedent = pCurrentRule->getChildItem("Antecedent");
        //if (pAntecedent != 0)
        //{
        //    stRule.sAntecedent = pAntecedent->getValue();
        //}
        //MetaRecordItem* pConsequent = pCurrentRule->getChildItem("Consequent");
        //if (pConsequent != 0)
        //{
        //    stRule.sConsequent = pConsequent->getValue();
        //}
        //MetaRecordItem* pInference = pCurrentRule->getChildItem("Inference");
        //if (pInference != 0)
        //{
        //    stRule.sInference = pInference->getValue();
        //}
        //MetaRecordItem* pWeight = pCurrentRule->getChildItem("Weight");
        //if (pWeight != 0)
        //{
        //    stRule.dWeight = pWeight->getValue().toDouble();
        //}
        m_pstData->vstRules.push_back(stRule);
    }
    return true;
}
