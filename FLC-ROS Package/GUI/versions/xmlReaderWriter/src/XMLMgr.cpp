#include "XMLMgr.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#define TRUE_TEXT   "True"
#define FALSE_TEXT  "False"
#include <QMessageBox>
#include "UtlMetaRecord.h"

XMLMgr::XMLMgr(MainWindow_t* pData_i)
{
    m_pstData = pData_i;
}

bool XMLMgr::SaveXMLFile()
{
    QFile File( "D:/TestXML11.xml" );
    File.open( QIODevice::WriteOnly );
    if( !File.isOpen())
        return false;
    QXmlStreamWriter xmlWriter( &File );
    xmlWriter.setAutoFormatting( true );
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("System"); // - system
    if( !WriteMainWindowData( xmlWriter ))
    {
        File.close();
        return false;
    }
    if( !WriteInputsData( xmlWriter ))
    {
        File.close();
        return false;
    }
    if( !WriteOutputsData( xmlWriter ))
    {
        File.close();
        return false;
    }
    if( !WriteRulesData( xmlWriter ))
    {
        File.close();
        return false;
    }
    xmlWriter.writeEndElement();           // - system
    xmlWriter.writeEndDocument();
    File.close();
    return true;
}

bool XMLMgr::ReadXMLFile()
{
    UtlMetaRecordReader Reader;
    Reader.read("D:/TestXML.xml");
    const UtlMetaRecordItem* Record = Reader.getResult();
    if (Record == 0)
        return false;
    UtlMetaRecordItem* pFLS = Record->getChildItem("FLS");
    if (pFLS != 0)
    {
        ReadFLSChildren(pFLS);
    }
    ReadInputs(Record);
    ReadOutputs(Record);
    ReadRules(Record);
    return true;
}

bool XMLMgr::ReadFLSChildren(UtlMetaRecordItem* pFLS)
{
    UtlMetaRecordItem* pName = pFLS->getChildItem("Name");
    if (pName != 0)
    {
        m_pstData->sFLSName = pName->getValue();
    }
    UtlMetaRecordItem* pType1 = pFLS->getChildItem("Type1");
    if (pType1 != 0)
    {
        m_pstData->bInterval2 = (pType1->getValue()==TRUE_TEXT);
    }
    UtlMetaRecordItem* pInterval_T2 = pFLS->getChildItem("Interval_T2");
    if (pInterval_T2 != 0)
    {
        m_pstData->bInterval2 = (pInterval_T2->getValue() == TRUE_TEXT);
    }
    UtlMetaRecordItem* pTSK = pFLS->getChildItem("TSK");
    if (pTSK != 0)
    {
        m_pstData->bTSK = (pTSK->getValue() == TRUE_TEXT);
    }
    UtlMetaRecordItem* pMamdani = pFLS->getChildItem("Mamdani");
    if (pMamdani != 0)
    {
        m_pstData->bMamdani = (pMamdani->getValue() == TRUE_TEXT);
    }
    UtlMetaRecordItem* pNumber_of_Inputs = pFLS->getChildItem("Number_of_Inputs");
    if (pNumber_of_Inputs != 0)
    {
        m_pstData->nNumberOfInputs = pNumber_of_Inputs->getValue().toInt();
    }
    UtlMetaRecordItem* pNumber_of_Outputs = pFLS->getChildItem("Number_of_Outputs");
    if (pNumber_of_Outputs != 0)
    {
        m_pstData->nNumberOFOutputs = pNumber_of_Outputs->getValue().toInt();
    }
    UtlMetaRecordItem* pNumber_of_Rules = pFLS->getChildItem("Number_of_Rules");
    if (pNumber_of_Rules != 0)
    {
        m_pstData->nNumberOfRules = pNumber_of_Rules->getValue().toInt();
    }
    UtlMetaRecordItem* pOutput_Processing_Method = pFLS->getChildItem("Output_Processing_Method");
    if (pOutput_Processing_Method != 0)
    {
        m_pstData->sProcessingMethod = pOutput_Processing_Method->getValue();
    }
    UtlMetaRecordItem* pAnd_method = pFLS->getChildItem("And_method");
    if (pAnd_method != 0)
    {
        m_pstData->sAndMethod = pAnd_method->getValue();
    }
    UtlMetaRecordItem* pOr_method = pFLS->getChildItem("Or_method");
    if (pOr_method != 0)
    {
        m_pstData->sOrMethod = pOr_method->getValue();
    }
    UtlMetaRecordItem* pImplication_method = pFLS->getChildItem("Implication_method");
    if (pImplication_method != 0)
    {
        m_pstData->sImplicationMethod = pImplication_method->getValue();
    }
    UtlMetaRecordItem* pAggregation_method = pFLS->getChildItem("Aggregation_method");
    if (pAggregation_method != 0)
    {
        m_pstData->sAggMethod = pAggregation_method->getValue();
    }
    
    return true;
}


bool XMLMgr::ReadInputs(const UtlMetaRecordItem* pSystem_i)
{
    m_pstData->vstInputs.clear();
    int nIdx = 1;
    for (;;)
    {
        UtlMetaRecordItem* pInput = pSystem_i->getChildItem("Input" + QString::number(nIdx++));
        if (pInput == 0)
        {
            break;
        }
        InputData_t stInput;
        UtlMetaRecordItem* pName = pInput->getChildItem("Name");
        if (pName != 0)
        {
            stInput.sName = pName->getValue();
        }
        UtlMetaRecordItem* pRange = pInput->getChildItem("Range");
        if (pRange != 0)
        {
            stInput.sRange = pRange->getValue();
        }
        int nMFIdx = 1;
        for (;;)
        {
            UtlMetaRecordItem* pMF = pInput->getChildItem("MF" + QString::number(nMFIdx++));
            if (pMF == 0)
            {
                break;
            }
            InputMF_t stInMF;
            UtlMetaRecordItem* pMFName = pMF->getChildItem("name");
            if (pMFName != 0)
            {
                stInMF.sName = pMFName->getValue();
            }
            UtlMetaRecordItem* pMFType = pMF->getChildItem("type");
            if (pMFType != 0)
            {
                stInMF.sType = pMFType->getValue();
            }
            UtlMetaRecordItem* pMFP1 = pMF->getChildItem("P1");
            if (pMFP1 != 0)
            {
                stInMF.nP1 = pMFP1->getValue().toDouble();
            }
            UtlMetaRecordItem* pMFP2 = pMF->getChildItem("P2");
            if (pMFP2 != 0)
            {
                stInMF.nP2 = pMFP2->getValue().toDouble();
            }
            UtlMetaRecordItem* pMFP3 = pMF->getChildItem("P3");
            if (pMFP3 != 0)
            {
                stInMF.nP3 = pMFP3->getValue().toDouble();
            }
            UtlMetaRecordItem* pMFP4 = pMF->getChildItem("P4");
            if (pMFP4 != 0)
            {
                stInMF.nP4 = pMFP4->getValue().toDouble();
            }
            UtlMetaRecordItem* pMFMaximum = pMF->getChildItem("maximum");
            if (pMFMaximum != 0)
            {
                stInMF.fMaximum = pMFMaximum->getValue().toDouble();
            }
            stInput.vstMF.push_back(stInMF);
        }
        m_pstData->vstInputs.push_back(stInput);
    }
    return true;
}


bool XMLMgr::ReadOutputs(const UtlMetaRecordItem* pSystem_i)
{
    m_pstData->vstOutputs.clear();
    int nIdx = 1;
    for (;;)
    {
        UtlMetaRecordItem* pInput = pSystem_i->getChildItem("Output" + QString::number(nIdx++));
        if (pInput == 0)
        {
            break;
        }
        OutputData_t stOutput;
        UtlMetaRecordItem* pName = pInput->getChildItem("Name");
        if (pName != 0)
        {
            stOutput.sName = pName->getValue();
        }
        UtlMetaRecordItem* pRange = pInput->getChildItem("Range");
        if (pRange != 0)
        {
            stOutput.sRange = pRange->getValue();
        }
        int nMFIdx = 1;
        for (;;)
        {
            UtlMetaRecordItem* pMF = pInput->getChildItem("MF" + QString::number(nMFIdx++));
            if (pMF == 0)
            {
                break;
            }
            OutputMF_t stOutMF;
            UtlMetaRecordItem* pMFName = pMF->getChildItem("name");
            if (pMFName != 0)
            {
                stOutMF.sName = pMFName->getValue();
            }
            UtlMetaRecordItem* pMFType = pMF->getChildItem("type");
            if (pMFType != 0)
            {
                stOutMF.sType = pMFType->getValue();
            }
            UtlMetaRecordItem* pMFP1 = pMF->getChildItem("P1");
            if (pMFP1 != 0)
            {
                stOutMF.nP1 = pMFP1->getValue().toDouble();
            }
            UtlMetaRecordItem* pMFP2 = pMF->getChildItem("P2");
            if (pMFP2 != 0)
            {
                stOutMF.nP2 = pMFP2->getValue().toDouble();
            }
            UtlMetaRecordItem* pMFP3 = pMF->getChildItem("P3");
            if (pMFP3 != 0)
            {
                stOutMF.nP3 = pMFP3->getValue().toDouble();
            }
            UtlMetaRecordItem* pMFP4 = pMF->getChildItem("P4");
            if (pMFP4 != 0)
            {
                stOutMF.nP4 = pMFP4->getValue().toDouble();
            }
            UtlMetaRecordItem* pMFMaximum = pMF->getChildItem("maximum");
            if (pMFMaximum != 0)
            {
                stOutMF.fMaximum = pMFMaximum->getValue().toDouble();
            }
            UtlMetaRecordItem* pMFTSK_Coefficients = pMF->getChildItem("TSK_Coefficients");
            if (pMFTSK_Coefficients != 0)
            {
                stOutMF.sTSKCoefficients = pMFTSK_Coefficients->getValue();
            }
            stOutput.vstMF.push_back(stOutMF);
        }
        m_pstData->vstOutputs.push_back(stOutput);
    }
    return true;
}

bool XMLMgr::ReadRules(const UtlMetaRecordItem * pSystem_i)
{
    m_pstData->vstRules.clear();
    UtlMetaRecordItem* pRules = pSystem_i->getChildItem("Rules");
    if (pRules == 0)
        return true;
    int nIdx = 1;
    for (;;)
    {
        UtlMetaRecordItem* pCurrentRule = pRules->getChildItem("R" + QString::number(nIdx++));
        if (pCurrentRule == 0)
        {
            break;
        }
        Rule_t stRule;
        UtlMetaRecordItem* pAntecedent = pCurrentRule->getChildItem("Antecedent");
        if (pAntecedent != 0)
        {
            stRule.sAntecedent = pAntecedent->getValue();
        }
        UtlMetaRecordItem* pConsequent = pCurrentRule->getChildItem("Consequent");
        if (pConsequent != 0)
        {
            stRule.sConsequent = pConsequent->getValue();
        }
        UtlMetaRecordItem* pInference = pCurrentRule->getChildItem("Inference");
        if (pInference != 0)
        {
            stRule.sInference = pInference->getValue();
        }
        UtlMetaRecordItem* pWeight = pCurrentRule->getChildItem("Weight");
        if (pWeight != 0)
        {
            stRule.dWeight = pWeight->getValue().toDouble();
        }
        m_pstData->vstRules.push_back(stRule);
    }
    return true;
}


bool XMLMgr::WriteMainWindowData( QXmlStreamWriter& xmlWriter_io )
{
    xmlWriter_io.writeStartElement( "FLS" );
    {
        // <Name>Some_name</Name>
        xmlWriter_io.writeTextElement( "Name"   , m_pstData->sFLSName);
        // <Type1>True</Type1>
        xmlWriter_io.writeTextElement( "Type1", (m_pstData->bType1) ? TRUE_TEXT : FALSE_TEXT );
        // <Interval_T2>False</Interval_T2>
        xmlWriter_io.writeTextElement( "Interval_T2", (m_pstData->bInterval2) ? TRUE_TEXT : FALSE_TEXT );
        // <TSK>False</TSK>
        xmlWriter_io.writeTextElement( "TSK", (m_pstData->bTSK) ? TRUE_TEXT : FALSE_TEXT );
        // <Mamdani>True</Mamdani>
        xmlWriter_io.writeTextElement( "Mamdani", (m_pstData->bMamdani) ? TRUE_TEXT : FALSE_TEXT );

        // <Number_of_Inputs>2</Number_of_Inputs>
        xmlWriter_io.writeTextElement( "Number_of_Inputs"   , QString::number(m_pstData->nNumberOfInputs));
        // <Number_of_Outputs>1</Number_of_Outputs>
        xmlWriter_io.writeTextElement( "Number_of_Outputs"   , QString::number(m_pstData->nNumberOFOutputs));
        // <Number_of_Rules>6</Number_of_Rules>
        xmlWriter_io.writeTextElement( "Number_of_Rules"   , QString::number(m_pstData->nNumberOfRules));
        // <Output_Processing_Method>Centroid></Output_Processing_Method>
        xmlWriter_io.writeTextElement( "Output_Processing_Method"   , m_pstData->sProcessingMethod);
        // <And_method>Min</And_method>
        xmlWriter_io.writeTextElement( "And_method"   , m_pstData->sAndMethod);
        // <Or_method>Max</Or_method>
        xmlWriter_io.writeTextElement( "Or_method"   , m_pstData->sOrMethod);
        // <Implication_method>Min</Implication_method>
        xmlWriter_io.writeTextElement( "Implication_method"   , m_pstData->sImplicationMethod);
        // <Aggregation_method>Max</Aggregation_method>
        xmlWriter_io.writeTextElement( "Aggregation_method"   , m_pstData->sAggMethod);
    }
    xmlWriter_io.writeEndElement();
    return true;
}

bool XMLMgr::WriteInputsData( QXmlStreamWriter& xmlWriter_io )
{
    int nIdx = 1;
    foreach( InputData_t stInput, m_pstData->vstInputs )
    {
        xmlWriter_io.writeStartElement( "Input" +QString::number(nIdx++));
        {
            xmlWriter_io.writeTextElement("Name", stInput.sName);
            xmlWriter_io.writeTextElement("Range", stInput.sRange);
            int nMF = 1;
            foreach(InputMF_t stMF, stInput.vstMF)
            {
                xmlWriter_io.writeStartElement( "MF" +QString::number(nMF++));
                {
                    // name="MF1l" type="Triangular" P1="1" P2="2" P3="3" P4="4" maximum="0.9"
                    xmlWriter_io.writeTextElement("name", stMF.sName);
                    xmlWriter_io.writeTextElement("type", stMF.sType);
                    xmlWriter_io.writeTextElement("P1", QString::number(stMF.nP1));
                    xmlWriter_io.writeTextElement("P2", QString::number(stMF.nP2));
                    xmlWriter_io.writeTextElement("P3", QString::number(stMF.nP3));
                    xmlWriter_io.writeTextElement("P4", QString::number(stMF.nP4));
                    xmlWriter_io.writeTextElement("maximum", QString::number(stMF.fMaximum));

                }
                xmlWriter_io.writeEndElement();
            }
        }
        xmlWriter_io.writeEndElement();
    }
    return true;
}

bool XMLMgr::WriteOutputsData( QXmlStreamWriter& xmlWriter_io )
{
    int nIdx = 1;
    foreach( OutputData_t stOutput, m_pstData->vstOutputs )
    {
        xmlWriter_io.writeStartElement( "Output" +QString::number(nIdx++));
        {
            xmlWriter_io.writeTextElement("Name", stOutput.sName);
            xmlWriter_io.writeTextElement("Range", stOutput.sRange);
            int nMF = 1;
            foreach(OutputMF_t stMF, stOutput.vstMF)
            {
                xmlWriter_io.writeStartElement( "MF" +QString::number(nMF++));
                {
                    xmlWriter_io.writeTextElement("name", stMF.sName);
                    xmlWriter_io.writeTextElement("type", stMF.sType);
                    xmlWriter_io.writeTextElement("P1", QString::number(stMF.nP1));
                    xmlWriter_io.writeTextElement("P2", QString::number(stMF.nP2));
                    xmlWriter_io.writeTextElement("P3", QString::number(stMF.nP3));
                    xmlWriter_io.writeTextElement("P4", QString::number(stMF.nP4));
                    xmlWriter_io.writeTextElement("maximum", QString::number(stMF.fMaximum));
                    xmlWriter_io.writeTextElement("TSK_Coefficients", stMF.sTSKCoefficients );
                }
                xmlWriter_io.writeEndElement();
            }
        }
        xmlWriter_io.writeEndElement();
    }
    return true;
}

bool XMLMgr::WriteRulesData( QXmlStreamWriter& xmlWriter_io )
{
    if(m_pstData->vstRules.empty())
        return true;
    xmlWriter_io.writeStartElement("Rules");
    {
        int nIdx = 1;
        foreach( Rule_t stRule, m_pstData->vstRules )
        {
            xmlWriter_io.writeStartElement( "R" +QString::number(nIdx++));
            {
                xmlWriter_io.writeTextElement("Antecedent", stRule.sAntecedent);
                xmlWriter_io.writeTextElement("Consequent", stRule.sConsequent);
                xmlWriter_io.writeTextElement("Inference", stRule.sInference);
                xmlWriter_io.writeTextElement("Weight", QString::number(stRule.dWeight));
            }
            xmlWriter_io.writeEndElement();
        }
    }
    xmlWriter_io.writeEndElement();
    return true;
}
