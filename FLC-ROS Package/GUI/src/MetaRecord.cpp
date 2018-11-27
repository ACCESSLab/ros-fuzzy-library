#include "MetaRecord.h"
#include <QDomElement>
#include <QFile>
#include <QIODevice>
#include <QStringList>
#include <QTextStream>


MetaRecordItem::MetaRecordItem()
{
    this->name = "Null";
}

MetaRecordItem::MetaRecordItem(const QString& name)
{
    this->name = name;
}

MetaRecordItem::MetaRecordItem(const QString& name, const char* value)
{
    this->name = name;
    setValue(value);
}

MetaRecordItem::MetaRecordItem(const QString& name, const QString& value)
{
    this->name = name;
    setValue(value);
}

MetaRecordItem::MetaRecordItem(const QString& name, unsigned int value)
{
    this->name = name;
    setValue(value);
}

MetaRecordItem::MetaRecordItem(const QString& name,
    unsigned int v0, unsigned int v1)
{
    this->name = name;
    setValue(v0, v1);
}

/******************************************************************************/
/*                                                                            */
/******************************************************************************/

MetaRecordItem::MetaRecordItem(const QString& name, int value)
{
    this->name = name;
    setValue(value);
}

MetaRecordItem::MetaRecordItem(const QString& name, int v0, int v1)
{
    this->name = name;
    setValue(v0, v1);
}

MetaRecordItem::MetaRecordItem(const QString& name, double value)
{
    this->name = name;
    setValue(value);
}

MetaRecordItem::MetaRecordItem(const QString& name, bool value)
{
    this->name = name;
    setValue(value);
}

MetaRecordItem::MetaRecordItem(const QString& name,
    double v0, double v1)
{
    this->name = name;
    setValue(v0, v1);
}

/******************************************************************************/
/*                                                                            */
/******************************************************************************/

MetaRecordItem::MetaRecordItem(const QString& name,
    double v0, double v1, double v2)
{
    this->name = name;
    setValue(v0, v1, v2);
}


MetaRecordItem::MetaRecordItem(const QString& name,
    const QList<double>& value)
{
    this->name = name;
    setValue(value);
}


MetaRecordItem::~MetaRecordItem()
{
}


void
MetaRecordItem::setValue(const char* value)
{
    this->value = QString(value);
}

/******************************************************************************/
/*                                                                            */
/******************************************************************************/

void MetaRecordItem::setValue(const QString& value)
{
    this->value = value;
}


void MetaRecordItem::setValue(unsigned int value)
{
    this->value = QString::number(value);
}

void
MetaRecordItem::setValue(unsigned int v0, unsigned int v1)
{
    value = QString::number(v0) + "," + QString::number(v1);
}

void
MetaRecordItem::setValue(int value)
{
    this->value = QString::number(value);
}


void
MetaRecordItem::setValue(int v0, int v1)
{
    value = QString::number(v0) + "," + QString::number(v1);
}


void
MetaRecordItem::setValue(double value)
{
    this->value = QString::number(value);
}


void
MetaRecordItem::setValue(bool value)
{
    this->value = QString::number(value);
}


void
MetaRecordItem::setValue(const QStringList& value)
{
    this->value = value.join(",");
}


void
MetaRecordItem::setValue(double v0, double v1)
{
    value = QString::number(v0) + "," + QString::number(v1);
}


void
MetaRecordItem::setValue(double v0, double v1, double v2)
{
    value = QString::number(v0) + "," + QString::number(v1) + "," +
        QString::number(v2);
}


void
MetaRecordItem::setValue(const QList<int>& value)
{
    // 1st convert the integer list into a string list, then call overloaded
    // setValue to string the integer strings out into a single string, with
    // comma separation
    QStringList stringList;
    for (int i = 0; i < value.size(); ++i)
        stringList << QString::number(value.at(i));
    setValue(stringList);
}


void
MetaRecordItem::setValue(const QList<double>& value)
{
    // 1st convert the double list into a string list, then call overloaded
    // setValue to string the double strings out into a single string, with
    // comma separation
    QStringList stringList;
    for (int i = 0; i < value.size(); ++i)
        stringList << QString::number(value.at(i));
    setValue(stringList);
}


const QString&
MetaRecordItem::getValue() const
{
    return value;
}


unsigned int
MetaRecordItem::getValueAsUnsignedInt() const
{
    return value.toUInt();
}


void
MetaRecordItem::getValueAsUnsignedInt2(unsigned int values[2]) const
{
    getValueAsUnsignedInt2(values[0], values[1]);
}


void
MetaRecordItem::getValueAsUnsignedInt2(unsigned int& v0,
    unsigned int& v1) const
{
    QStringList stringList = getValueList();
    if (stringList.count() != 2)
        return;

    v0 = stringList.at(0).toUInt();
    v1 = stringList.at(1).toUInt();
}


int
MetaRecordItem::getValueAsInt() const
{
    return value.toInt();
}


void
MetaRecordItem::getValueAsInt2(int values[2]) const
{
    getValueAsInt2(values[0], values[1]);
}


void
MetaRecordItem::getValueAsInt2(int& v0, int& v1) const
{
    QStringList stringList = getValueList();
    if (stringList.count() != 2)
        return;

    v0 = stringList.at(0).toInt();
    v1 = stringList.at(1).toInt();
}


double
MetaRecordItem::getValueAsDouble() const
{
    return value.toDouble();
}


bool
MetaRecordItem::getValueAsBool() const
{
    return (value == "1");
}


void
MetaRecordItem::getValueAsDouble2(double values[2]) const
{
    getValueAsDouble2(values[0], values[1]);
}


void
MetaRecordItem::getValueAsDouble2(double& v0, double& v1) const
{
    QStringList stringList = getValueList();
    if (stringList.count() != 2)
        return;

    v0 = stringList.at(0).toDouble();
    v1 = stringList.at(1).toDouble();
}


void
MetaRecordItem::getValueAsDouble3(double values[3]) const
{
    getValueAsDouble3(values[0], values[1], values[2]);
}


void
MetaRecordItem::getValueAsDouble3(double& v0, double& v1,
    double& v2) const
{
    QStringList stringList = getValueList();
    if (stringList.count() != 3)
        return;

    v0 = stringList.at(0).toDouble();
    v1 = stringList.at(1).toDouble();
    v2 = stringList.at(2).toDouble();
}


void
MetaRecordItem::getValueAsDouble4(double values[4]) const
{
    getValueAsDouble4(values[0], values[1], values[2], values[3]);
}


void
MetaRecordItem::getValueAsDouble4(double& v0, double& v1,
    double& v2, double& v3) const
{
    QStringList stringList = getValueList();
    if (stringList.count() != 4)
        return;

    v0 = stringList.at(0).toDouble();
    v1 = stringList.at(1).toDouble();
    v2 = stringList.at(2).toDouble();
    v3 = stringList.at(3).toDouble();
}


void
MetaRecordItem::getValueAsDoubleArray(int num, double* array) const
{
    QStringList stringList = getValueList();
    if (stringList.count() < num)
        num = stringList.count();

    for (int i = 0; i < num; i++)
        array[i] = stringList.at(i).toDouble();
}


const QStringList
MetaRecordItem::getValueList() const
{
    return value.split(",");
}


const QList<int>
MetaRecordItem::getValueListAsInt() const
{
    QList<int> value;
    QStringList stringList = getValueList();
    for (int i = 0; i < stringList.size(); ++i)
        value << stringList.at(i).toInt();
    return value;
}


const QList<double>
MetaRecordItem::getValueListAsDouble() const
{
    QList<double> value;
    QStringList stringList = getValueList();
    for (int i = 0; i < stringList.size(); ++i)
        value << stringList.at(i).toDouble();
    return value;
}


MetaRecordItem&
MetaRecordItem::operator=(const MetaRecordItem& other)
{
    name = other.name;
    value = other.value;
    return *this;
}


MetaRecord::MetaRecord()
{
    items = new QList<MetaRecordItem*>();
}


MetaRecord::MetaRecord(const QString& name)
    : MetaRecordItem(name)
{
    items = new QList<MetaRecordItem*>();
}

MetaRecord::~MetaRecord()
{
    qDeleteAll(items->begin(), items->end());
    delete items;
}


MetaRecord*
MetaRecord::createChildRecord(const QString& name)
{
    MetaRecord* record = new MetaRecord(name);
    items->append(record);
    return record;
}


void
MetaRecord::createChildItem(const QString& name, const char* value)
{
    items->append(new MetaRecordItem(name, value));
}


void
MetaRecord::createChildItem(const QString& name, const QString& value)
{
    items->append(new MetaRecordItem(name, value));
}


void
MetaRecord::createChildItem(const QString& name, unsigned int value)
{
    items->append(new MetaRecordItem(name, value));
}


void
MetaRecord::createChildItem(const QString& name,
    unsigned int v0, unsigned int v1)
{
    items->append(new MetaRecordItem(name, v0, v1));
}


void
MetaRecord::createChildItem(const QString& name, int value)
{
    items->append(new MetaRecordItem(name, value));
}


void
MetaRecord::createChildItem(const QString& name, int v0, int v1)
{
    items->append(new MetaRecordItem(name, v0, v1));
}


void
MetaRecord::createChildItem(const QString& name, double value)
{
    items->append(new MetaRecordItem(name, value));
}


void
MetaRecord::createChildItem(const QString& name, bool value)
{
    items->append(new MetaRecordItem(name, value));
}


void
MetaRecord::createChildItem(const QString& name, double v0, double v1)
{
    items->append(new MetaRecordItem(name, v0, v1));
}


void
MetaRecord::createChildItem(const QString& name, double v0,
    double v1, double v2)
{
    items->append(new MetaRecordItem(name, v0, v1, v2));
}


void
MetaRecord::createChildItem(const QString& name,
    const QList<double>& value)
{
    items->append(new MetaRecordItem(name, value));
}


void
MetaRecord::addChildItem(MetaRecordItem* item)
{
    items->append(item);
}


MetaRecordItem*
MetaRecord::getChildItem(const QString& name) const
{
    QListIterator<MetaRecordItem*> it(*items);
    while (it.hasNext())
    {
        MetaRecordItem* item = it.next();
        if (item->getName() == name)
            return item;
    }
    return NULL;
}


QList<MetaRecordItem*>
MetaRecord::getChildItems(const QString& name) const
{
    QList<MetaRecordItem*> retItems;

    QListIterator<MetaRecordItem*> it(*items);
    while (it.hasNext())
    {
        MetaRecordItem* item = it.next();
        if (item->getName() == name)
            retItems.append(item);
    }
    return retItems;
}


void
MetaRecord::removeChildItem(const QString& name)
{
    MetaRecordItem* item = getChildItem(name);
    if (item != NULL)
        items->removeAll(item);
    delete item;
}


int MetaRecord::getNumChildItems() const
{
    return items->size();
}



MetaRecordReader::MetaRecordReader()
{
    item = NULL;
}

MetaRecordReader::~MetaRecordReader()
{
    if (item != NULL)
        delete item;
}


void
MetaRecordReader::read(const QString& filename)
{
    QDomDocument document;

    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    document.setContent(&file);
    file.close();

    QDomElement element = document.documentElement();
    if (!element.isNull())
    {
        if (item != NULL)
            delete item;
        item = read(element);
    }
}


MetaRecordItem*
MetaRecordReader::read(const QDomElement& element)
{
    bool hasChildItems = false;
    QDomNodeList nodeList = element.childNodes();
    for (int i = 0; i < nodeList.count(); i++)
    {
        QDomNode node = nodeList.item(i);
        if (node.isElement())
        {
            hasChildItems = true;
            break;
        }
    }

    if (hasChildItems)
        // Recursively traverse the branch
    {
        MetaRecordItem* item = new MetaRecord(element.tagName());
        for (int i = 0; i < nodeList.count(); i++)
        {
            QDomNode node = nodeList.item(i);
            if (node.isElement())
                item->addChildItem(read(node.toElement()));
        }
        return item;
    }
    else
        // Reached a leaf
        return new MetaRecordItem(element.tagName(), element.text());
}



MetaRecordWriter::MetaRecordWriter()
{
}


MetaRecordWriter::~MetaRecordWriter()
{
}


void
MetaRecordWriter::write(const QString& filename,
    const MetaRecordItem* item)
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QTextStream stream(&file);
    write(stream, item, 0);

    file.close();
}


void
MetaRecordWriter::write(QTextStream& stream,
    const MetaRecordItem* item, int level)
{
    if (item->getNumChildItems() == 0)
    {
        for (int i = 0; i < level; i++)
            stream << "    ";
        stream << "<" << item->getName() << ">";
        stream << item->getValue();
        stream << "</" << item->getName() << ">\n";
    }
    else
    {
        for (int i = 0; i < level; i++)
            stream << "    ";
        stream << "<" << item->getName() << ">\n";

        QList<MetaRecordItem*>* childItems = item->getChildItems();
        if (childItems != 0)
            for (int i = 0; i < childItems->size(); ++i)
                write(stream, childItems->at(i), level + 1);

        for (int i = 0; i < level; i++)
            stream << "    ";
        stream << "</" << item->getName() << ">\n";
    }
}