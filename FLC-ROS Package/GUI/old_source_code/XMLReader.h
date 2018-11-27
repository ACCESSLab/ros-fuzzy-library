#ifndef XMLREADER_H
#define XMLREADER_H

#include "commondef.h"
class MetaRecordItem;
class XMLReader
{
public:
    XMLReader(MainWindow_t* pData_i);//{m_pstData = pData_i;};
    bool ReadXMLFile(QString sFileName_i);
private:
    bool ReadFLSChildren(MetaRecordItem* pFLS);
    bool ReadInputs(const MetaRecordItem* pSystem_i);
    bool ReadOutputs(const MetaRecordItem* pSystem_i);
    bool ReadRules(const MetaRecordItem* pSystem_i);
private:
    MainWindow_t* m_pstData;
};

#endif // XMLREADER_H
