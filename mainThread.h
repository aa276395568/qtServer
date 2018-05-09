#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include <QCoreApplication>
#include <QPluginLoader>
#include <QThread>
#include <QHash>

class mainThread : public QCoreApplication
{
    Q_OBJECT
public:
    explicit mainThread(int & argc, char ** argv);
    ~mainThread();

    void init();
    void release();
};

#endif // MAINTHREAD_H
