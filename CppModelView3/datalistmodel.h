#ifndef DATALISTMODEL_H
#define DATALISTMODEL_H

#include <QAbstractListModel>

class ModelData;
class DataListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DataListModel(QObject *parent = nullptr);

    enum AnimalRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole1
    };

    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Q_INVOKABLE void insert(int index, const ModelData &data);
    Q_INVOKABLE void append(const ModelData &data);
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void append(const QVariantMap map);

signals:
    void countChanged(int arg);

private:
    int count() const;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<ModelData> m_list;
};


class ModelData
{
public:
    ModelData(const QString &type, const QString &size):
        m_type(type), m_size(size)
    {

    }

    QString type() const {return m_type;}
    QString size() const {return m_size;}

    void setType(const QString &type) {m_type = type;}
    void setSize(const QString & size) {m_size = size;}

private:
    QString m_type;
    QString m_size;
};

#endif // DATALISTMODEL_H
