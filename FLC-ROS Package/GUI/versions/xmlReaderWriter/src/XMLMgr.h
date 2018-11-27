#ifndef XMLMGR_H
#define XMLMGR_H

#include "common.h"
class QXmlStreamWriter;
class QXmlStreamReader;
class UtlMetaRecordItem;
class XMLMgr
{
public:
    XMLMgr(MainWindow_t* pData_i);//{m_pstData = pData_i;};

    bool SaveXMLFile();
    bool ReadXMLFile();
private:
    bool ReadFLSChildren(UtlMetaRecordItem* pFLS);
    bool ReadInputs(const UtlMetaRecordItem* pSystem_i);
    bool ReadOutputs(const UtlMetaRecordItem* pSystem_i);
    bool ReadRules(const UtlMetaRecordItem* pSystem_i);
    bool WriteMainWindowData( QXmlStreamWriter& xmlWriter_io );
    bool WriteInputsData( QXmlStreamWriter& xmlWriter_io );
    bool WriteOutputsData( QXmlStreamWriter& xmlWriter_io );
    bool WriteRulesData( QXmlStreamWriter& xmlWriter_io );

private:
    MainWindow_t* m_pstData;
};

#endif // XMLMGR_H
