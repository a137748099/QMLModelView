#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include "datalistmodel.h"

class AddCommand : public QUndoCommand
{
public:
    AddCommand(const ModelData &modelData, DataListModel *model,
               QUndoCommand *parent = nullptr);

    void undo() override;
    void redo() override;

private:
    int m_index = -1;
    ModelData m_modelData;
    DataListModel *m_pModel = nullptr;

};

class DeleteCommand : public QUndoCommand
{
public:
    DeleteCommand(int index, DataListModel *model, QUndoCommand *parent = nullptr);

    void undo() override;
    void redo() override;

private:
    int m_index;
    ModelData m_modelData;
    DataListModel *m_pModel = nullptr;

};

#endif // COMMANDS_H
