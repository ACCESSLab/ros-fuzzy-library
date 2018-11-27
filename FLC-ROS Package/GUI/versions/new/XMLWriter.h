#ifndef XMLMGR_H
#define XMLMGR_H

#include "commondef.h"
class QXmlStreamWriter;
class QXmlStreamReader;
class MetaRecordItem;
class XMLWriter
{
public:
    XMLWriter(MainWindow_t* pData_i);//{m_pstData = pData_i;};

    bool SaveXMLFile(QString sFileName_i);
private:
    bool WriteMainWindowData( QXmlStreamWriter& xmlWriter_io );
    bool WriteInputsData( QXmlStreamWriter& xmlWriter_io );
    bool WriteOutputsData( QXmlStreamWriter& xmlWriter_io );
    bool WriteRulesData( QXmlStreamWriter& xmlWriter_io );

private:
    MainWindow_t* m_pstData;
};

#endif // XMLMGR_H
