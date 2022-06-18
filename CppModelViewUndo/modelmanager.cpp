#include "modelmanager.h"
#include "datalistmodel.h"
#include "commands.h"
#include "qqml.h"

#include <QUndoStack>

ModelManager::ModelManager(QObject *parent):
    QObject(parent)
{
    m_pUndoStack = new QUndoStack(this);
    m_pDataModel = new DataListModel(this);

    qmlRegisterType<DataListModel>("Model", 1, 0, "myModel");
}

DataListModel *ModelManager::getModel() const
{
    return m_pDataModel;
}

void ModelManager::add(const QVariantMap &dataMap)
{
    QString type = dataMap["type"].toString();
    QString size = dataMap["size"].toString();

    ModelData data(type, size);
    QUndoCommand *addCommand = new AddCommand(data, m_pDataModel);
    m_pUndoStack->push(addCommand);
}

void ModelManager::remove(int index)
{
    QUndoCommand *deleteCommand = new DeleteCommand(index, m_pDataModel);
    m_pUndoStack->push(deleteCommand);
}

void ModelManager::undo()
{
    m_pUndoStack->undo();
}

void ModelManager::redo()
{
    m_pUndoStack->redo();
}
