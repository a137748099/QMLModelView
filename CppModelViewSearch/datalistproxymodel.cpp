#include "datalistproxymodel.h"
#include "datalistmodel.h"

DataListProxyModel::DataListProxyModel(QObject *parent):
    QSortFilterProxyModel(parent)
{

}

void DataListProxyModel::setFilter(const QString &text)
{
    QRegExp regExp(text);
    this->setFilterRegExp(regExp);
}

bool DataListProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex index0 = sourceModel()->index(sourceRow, 0, sourceParent);
    auto typeData = sourceModel()->data(index0, DataListModel::TypeRole).toString();
    auto sizeData = sourceModel()->data(index0, DataListModel::SizeRole1).toString();
    return typeData.contains(filterRegExp()) || sizeData.contains(filterRegExp());
}
