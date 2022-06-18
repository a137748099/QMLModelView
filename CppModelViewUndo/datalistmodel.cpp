#include "datalistmodel.h"

DataListModel::DataListModel(QObject *parent):
    QAbstractListModel(parent)
{

}

int DataListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.count();
}

QVariant DataListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_list.count())
        return QVariant();

    const ModelData &data = m_list[index.row()];
    // qDebug() << "row: " << index.row();

    if (role == TypeRole)
        return data.type();
    else if (role == SizeRole1)
        return data.size();

    return QVariant();
}

void DataListModel::insert(int index, const ModelData &data)
{
    if(index < 0 || index > m_list.count()) {
        return;
    }

    beginInsertRows(QModelIndex(), index, index);
    m_list.insert(index, data);
    endInsertRows();
    emit countChanged(m_list.count());
}

void DataListModel::append(const ModelData &data)
{
    insert(count(), data);
}

void DataListModel::remove(int index)
{
    if(index < 0 || index >= m_list.count()) {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    m_list.removeAt( index );
    endRemoveRows();
    emit countChanged(m_list.count());
}

void DataListModel::append(const QVariantMap map)
{
    QString type = map["type"].toString();
    QString size = map["size"].toString();

    ModelData data(type, size);

    insert(count(), data);
}

bool DataListModel::modelData(int index, ModelData &modelData)
{
    if(index < 0 || index >= m_list.count()) {
        return false;
    }

    modelData = m_list.at(index);
    return true;
}

int DataListModel::count() const
{
    return rowCount(QModelIndex());
}

QHash<int, QByteArray> DataListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[SizeRole1] = "size";
    return roles;
}
