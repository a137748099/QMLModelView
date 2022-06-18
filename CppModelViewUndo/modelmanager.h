#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <QObject>

class DataListModel;
class QUndoStack;
class ModelManager : public QObject
{
    Q_OBJECT
public:
    explicit ModelManager(QObject *parent = nullptr);

    Q_INVOKABLE DataListModel *getModel() const;
    Q_INVOKABLE void add(const QVariantMap &dataMap);
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void undo();
    Q_INVOKABLE void redo();

private:
    DataListModel *m_pDataModel = nullptr;
    QUndoStack *m_pUndoStack = nullptr;

};

#endif // MODELMANAGER_H
