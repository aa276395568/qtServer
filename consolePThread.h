#ifndef CONSOLEPTHREAD_H
#define CONSOLEPTHREAD_H

#include <QTextStream>
#include <QCoreApplication>
#include <QThread>

class consolePThread : public QThread
{
    Q_OBJECT
public:
    explicit consolePThread(QObject *parent = 0);
protected:
    void run();
signals:

public slots:

};


#endif // CONSOLEPTHREAD_H
