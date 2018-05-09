#include "consolePThread.h"

consolePThread::consolePThread(QObject *parent) :
    QThread(parent)
{

}

void consolePThread::run()
{
    qDebug() << QString::fromLatin1("%1, thread: %2, thread id: %3")
                .arg(__FUNCTION__)
                .arg(QString::number((quintptr) QThread::currentThread(), 16))
                .arg(QString::number((quintptr) QThread::currentThreadId(), 16));
    QTextStream stdin_stream(stdin, QIODevice::ReadOnly);
    QTextStream stdout_stream(stdout, QIODevice::WriteOnly);
    QString strIn;
    while (true)
    {
        stdout_stream << ">>> ";
        stdout_stream.flush();
        stdin_stream >> strIn;
        if (strIn.compare("quit()", Qt::CaseSensitive) == 0)
        {
            qDebug() << QString("%1: quit").arg(__FUNCTION__);
            break;
        }
        else
        {
            stdout_stream << ">>> use quit() to exit" << endl;
        }
    }
}
