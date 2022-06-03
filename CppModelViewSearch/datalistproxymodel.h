#ifndef DATALISTPROXYMODEL_H
#define DATALISTPROXYMODEL_H

#include <QSortFilterProxyModel>

class DataListProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit DataListProxyModel(QObject *parent = nullptr);

    Q_INVOKABLE void setFilter(const QString &text);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
};

#endif // DATALISTPROXYMODEL_H
