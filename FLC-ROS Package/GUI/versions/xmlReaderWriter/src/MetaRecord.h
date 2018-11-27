#ifndef UTL_META_RECORD_H
#define UTL_META_RECORD_H

#include <QObject>

class QDomElement;
class QStringList;
class QTextStream;
template<class T> class QList;


class MetaRecordItem
{
public:
    MetaRecordItem();
    MetaRecordItem(const QString& name);
    MetaRecordItem(const QString& name, const char* value);
    MetaRecordItem(const QString& name, const QString& value);
    MetaRecordItem(const QString& name, unsigned int value);
    MetaRecordItem(const QString& name, unsigned int v0, unsigned int v1);
    MetaRecordItem(const QString& name, int value);
    MetaRecordItem(const QString& name, int v0, int v1);
    MetaRecordItem(const QString& name, double value);
    MetaRecordItem(const QString& name, bool value);
    MetaRecordItem(const QString& name, double v0, double v1);
    MetaRecordItem(const QString& name, double v0, double v1, double v2);
    MetaRecordItem(const QString& name, const QList<double>& value);
    virtual ~MetaRecordItem();

    const QString& getName() const { return name; }

    void setValue(const char* value);
    void setValue(const QString& value);
    void setValue(unsigned int value);
    void setValue(unsigned int v0, unsigned int v1);
    void setValue(int value);
    void setValue(int v0, int v1);
    void setValue(double value);
    void setValue(bool value);
    void setValue(double v0, double v1);
    void setValue(double v0, double v1, double v2);

    void setValue(const QStringList& value);
    void setValue(const QList<int>& value);
    void setValue(const QList<double>& value);

    const QString& getValue() const;
    unsigned int getValueAsUnsignedInt() const;
    void         getValueAsUnsignedInt2(unsigned int values[2]) const;
    void         getValueAsUnsignedInt2(unsigned int& v0, unsigned int& v1) const;
    int          getValueAsInt() const;
    void         getValueAsInt2(int values[2]) const;
    void         getValueAsInt2(int& v0, int& v1) const;
    double       getValueAsDouble() const;
    bool         getValueAsBool() const;
    void         getValueAsDouble2(double values[2]) const;
    void         getValueAsDouble2(double& v0, double& v1) const;
    void         getValueAsDouble3(double values[3]) const;
    void         getValueAsDouble3(double& v0, double& v1, double& v2) const;
    void         getValueAsDouble4(double values[4]) const;
    void         getValueAsDouble4(double& v0, double& v1, double& v2,
        double& v3) const;
    void         getValueAsDoubleArray(int num, double* array) const;

    const QStringList getValueList() const;
    const QList<int> getValueListAsInt() const;
    const QList<double> getValueListAsDouble() const;

    virtual void addChildItem(MetaRecordItem* item) { }
    virtual MetaRecordItem* getChildItem(const QString& name) const
    {
        return 0;
    }
    virtual QList<MetaRecordItem*>
        getChildItems(const QString& name) const
    {
        return QList<MetaRecordItem*>();
    }
    virtual QList<MetaRecordItem*>* getChildItems() const { return 0; }
    virtual void removeChildItem(const QString& name) {}
    virtual int getNumChildItems() const { return 0; }

    MetaRecordItem& operator=(const MetaRecordItem& other);

private:
    QString name, value;
};


class MetaRecord : public MetaRecordItem
{
public:
    MetaRecord();
    MetaRecord(const QString& name);
    virtual ~MetaRecord();

    MetaRecord* createChildRecord(const QString& name);
    void createChildItem(const QString& name, const char* value);
    void createChildItem(const QString& name, const QString& value);
    void createChildItem(const QString& name, unsigned int value);
    void createChildItem(const QString& name, unsigned int v0, unsigned int v1);
    void createChildItem(const QString& name, int value);
    void createChildItem(const QString& name, int v0, int v1);
    void createChildItem(const QString& name, double value);
    void createChildItem(const QString& name, bool value);
    void createChildItem(const QString& name, double v0, double v1);
    void createChildItem(const QString& name, double v0, double v1, double v2);
    void createChildItem(const QString& name, const QList<double>& value);

    virtual void addChildItem(MetaRecordItem* item);
    virtual MetaRecordItem* getChildItem(const QString& name) const;
    virtual QList<MetaRecordItem*>
        getChildItems(const QString& name) const;
    virtual QList<MetaRecordItem*>* getChildItems() const
    {
        return items;
    }
    virtual void removeChildItem(const QString& name);
    virtual int getNumChildItems() const;

private:
    MetaRecord& operator=(const MetaRecord& other);
private:
    QList<MetaRecordItem*>* items;
};


class MetaRecordReader : public QObject
{
    Q_OBJECT

public:
    MetaRecordReader();
    virtual ~MetaRecordReader();


    void read(const QString& filename);
    const MetaRecordItem* getResult() const { return item; }

signals:
    void error(const QString& message);

private:
    MetaRecordItem* read(const QDomElement& element);

private:
    MetaRecordItem* item;
};


class MetaRecordWriter : public QObject
{
    Q_OBJECT

public:
    MetaRecordWriter();
    virtual ~MetaRecordWriter();

    void write(const QString& fileName, const MetaRecordItem* item);

signals:
    void error(const QString& message);

private:
    void write(QTextStream& stream, const MetaRecordItem* item, int level);
};

#endif