#include "commands.h"

AddCommand::AddCommand(const ModelData &modelData, DataListModel *model, QUndoCommand *parent):
    QUndoCommand(parent), m_modelData(modelData), m_pModel(model)
{
    Q_ASSERT(m_pModel);
    m_index = m_pModel->rowCount();
}

void AddCommand::undo()
{
    m_pModel->remove(m_index);
}

void AddCommand::redo()
{
    Q_ASSERT(m_pModel);
    m_pModel->insert(m_index, m_modelData);
}



DeleteCommand::DeleteCommand(int index, DataListModel *model, QUndoCommand *parent):
    QUndoCommand(parent), m_index(index), m_pModel(model)
{
    Q_ASSERT(m_pModel);
    m_pModel->modelData(m_index, m_modelData);
}

void DeleteCommand::undo()
{
    Q_ASSERT(m_pModel);
    m_pModel->insert(m_index, m_modelData);
}

void DeleteCommand::redo()
{
    Q_ASSERT(m_pModel);
    m_pModel->remove(m_index);
}
