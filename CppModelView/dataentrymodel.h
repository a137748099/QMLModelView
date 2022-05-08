#ifndef DATAENTRYMODEL_H
#define DATAENTRYMODEL_H

#include <QAbstractListModel>

class DataEntryModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DataEntryModel(QObject *parent = nullptr);
    ~DataEntryModel();

public: // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
private:
    QList<QString> m_data;
};

#endif // DATAENTRYMODEL_H
