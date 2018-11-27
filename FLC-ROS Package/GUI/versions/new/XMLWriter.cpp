#include "XMLWriter.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#define TRUE_TEXT   "True"
#define FALSE_TEXT  "False"
#include <QMessageBox>
#include "MetaRecord.h"

XMLWriter::XMLWriter(MainWindow_t* pData_i)
{
    m_pstData = pData_i;
}

bool XMLWriter::SaveXMLFile(QString sFileName_i)
{
    QFile File(sFileName_i );
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

bool XMLWriter::WriteMainWindowData( QXmlStreamWriter& xmlWriter_io )
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

bool XMLWriter::WriteInputsData( QXmlStreamWriter& xmlWriter_io )
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
                //xmlWriter_io.writeStartElement( "MF" +QString::number(nMF++));
                //{
                //    // name="MF1l" type="Triangular" P1="1" P2="2" P3="3" P4="4" maximum="0.9"
                //    xmlWriter_io.writeTextElement("name", stMF.sName);
                //    xmlWriter_io.writeTextElement("type", stMF.sType);
                //    xmlWriter_io.writeTextElement("P1", QString::number(stMF.nP1));
                //    xmlWriter_io.writeTextElement("P2", QString::number(stMF.nP2));
                //    xmlWriter_io.writeTextElement("P3", QString::number(stMF.nP3));
                //    xmlWriter_io.writeTextElement("P4", QString::number(stMF.nP4));
                //    xmlWriter_io.writeTextElement("maximum", QString::number(stMF.fMaximum));

                //}
                //xmlWriter_io.writeEndElement();

                QString sMF = "name='" + stMF.sName + "'~" +
                    "type='" + stMF.sType + "'~" +
                    "P1='" + QString::number(stMF.dP1) + "'~" +
                    "P2='" + QString::number(stMF.dP2) + "'~" +
                    "P3='" + QString::number(stMF.dP3) + "'~" +
                    "P4='" + QString::number(stMF.dP4) + "'~" +
                    "maximum='" + QString::number(stMF.dMaximum) + "'";
                xmlWriter_io.writeTextElement("MF" + QString::number(nMF++), sMF);
            }
        }
        xmlWriter_io.writeEndElement();
    }
    return true;
}

bool XMLWriter::WriteOutputsData( QXmlStreamWriter& xmlWriter_io )
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
                //xmlWriter_io.writeStartElement( "MF" +QString::number(nMF++));
                //{
                //    xmlWriter_io.writeTextElement("name", stMF.sName);
                //    xmlWriter_io.writeTextElement("type", stMF.sType);
                //    xmlWriter_io.writeTextElement("P1", QString::number(stMF.nP1));
                //    xmlWriter_io.writeTextElement("P2", QString::number(stMF.nP2));
                //    xmlWriter_io.writeTextElement("P3", QString::number(stMF.nP3));
                //    xmlWriter_io.writeTextElement("P4", QString::number(stMF.nP4));
                //    xmlWriter_io.writeTextElement("maximum", QString::number(stMF.fMaximum));
                //    xmlWriter_io.writeTextElement("TSK_Coefficients", stMF.sTSKCoefficients );
                //}
                //xmlWriter_io.writeEndElement();
                QString sMF = "name='" + stMF.sName +"'~" +
                              "type='" + stMF.sType + "'~" +
                              "P1='" + QString::number(stMF.dP1) + "'~" +
                              "P2='" + QString::number(stMF.dP2) + "'~" +
                              "P3='" + QString::number(stMF.dP3) + "'~" +
                              "P4='" + QString::number(stMF.dP4) + "'~" +
                              "maximum='" + QString::number(stMF.dMaximum) + "'~" +
                              "TSK_Coefficients='" + stMF.sTSKCoefficients + "'";
                xmlWriter_io.writeTextElement("MF" + QString::number(nMF++), sMF);
            }
        }
        xmlWriter_io.writeEndElement();
    }
    return true;
}

bool XMLWriter::WriteRulesData( QXmlStreamWriter& xmlWriter_io )
{
    if(m_pstData->vstRules.empty())
        return true;
    xmlWriter_io.writeStartElement("Rules");
    {
        int nIdx = 1;
        foreach( Rule_t stRule, m_pstData->vstRules )
        {
            //xmlWriter_io.writeStartElement( "R" +QString::number(nIdx++));
            //{
            //    xmlWriter_io.writeTextElement("Antecedent", stRule.sAntecedent);
            //    xmlWriter_io.writeTextElement("Consequent", stRule.sConsequent);
            //    xmlWriter_io.writeTextElement("Inference", stRule.sInference);
            //    xmlWriter_io.writeTextElement("Weight", QString::number(stRule.dWeight));
            //}
            //xmlWriter_io.writeEndElement();
            QString sText = "Antecedent='" + stRule.sAntecedent + "'~" +
                            "Consequent='" + stRule.sConsequent + "'~" +
                            "Inference='"  + stRule.sInference + "'~" +
                            "Weight='"     + QString::number(stRule.dWeight) + "'";
            xmlWriter_io.writeTextElement("R" + QString::number(nIdx++), sText);
        }
    }
    xmlWriter_io.writeEndElement();
    return true;
}
