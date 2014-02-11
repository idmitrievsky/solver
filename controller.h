#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include "mainwindow.h"
#include "connectionwindow.h"
#include "taskwindow.h"
#include "model.h"

#define CONNECTION_SUCC "Connection successful"
#define CONNECTION_ERR  "Error occured"

class Controller : public QWidget
{
    Q_OBJECT
public:
    explicit Controller(QWidget *parent = 0);

signals:
    /* Inform the user about some changes */
    void statusChanged(QString status, int timeout);

    /* Connection related */
    void retrieveDrivers(QStringList &drivers);
    void displayDrivers(QStringList &drivers);
    void attemptToConnect(QHash<QString, QString> &options, bool &result);

    /* */
    void retrieveTaskTypes(QStringList &taskTypes);
    void displayTaskTypes(QStringList &taskTypes);

    /* */
    void retrieveTaskHistory(int taskTypeId, QStringList &taskHistory);
    void displayTaskHistory(QStringList &taskHistory);

public slots:
    void initialize(MainWindow *_mainWindow, ConnectionWindow *_connectionWindow, TaskWindow *_taskWindow, Model *_model);

    void showConnectionWindow();
    void processConnectionOptions();

    void showTaskWindow();

    void showTaskTypes(bool connectionExists);
    void showTaskHistory(int taskTypeIndex);

private:
    MainWindow *mainWindow;
    ConnectionWindow *connectionWindow;
    TaskWindow *taskWindow;
    Model *model;
};

#endif // CONTROLLER_H
