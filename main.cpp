#include <QCoreApplication>
#include <QTextCodec>
#include <QMetaType>
#include <QFile>
#include <QDebug>
#include <QMutexLocker>
#include <QSettings>
#include <QMutex>
#include <stdio.h>
#include <stdlib.h>
#include <QTime>
#include <QDebug>

#include "mainThread.h"

bool LogFlag = FALSE;

enum{
   log_ALL = 0,
   log_WARNING,
   log_DEBUG,
   log_FATAL,
   log_ERROR
};

class InitParamRead
{
public:
    InitParamRead();
    ~InitParamRead();

    QString serverHost;
    int serverPort;


    int read_ini_File();
};

int main(int argc, char *argv[])
{
    printf("----------------------------------------------------\n");

    fprintf(stdout, "Built with Qt %s running on %s\n", QT_VERSION_STR, qVersion());

    fprintf(stdout, "Program init time: %s\n", QDate::currentDate().toString("yyyy-MM-dd").toAscii().data());

    fprintf(stdout, "Version : 1.0.0\n");

    fprintf(stdout, "Author : FL  Tel : 1805816**** ");

    printf("\n----------------------------------------------------\n");

    fprintf(stdout, "Server init......\n");

    if (argc >= 2) {
        if (strcmp(argv[1], "-d") == 0) {
            LogFlag = FALSE;
        } else if (strcmp(argv[1], "-D") == 0) {
            LogFlag = TRUE;
        }
    }

    InitParamRead iniRead =  InitParamRead();

    if(iniRead.read_ini_File()){
        fprintf(stdout, "\nServer IP set: %s ,  port set: %d\n", iniRead.serverHost.toAscii().data(), iniRead.serverPort);
    }

    mainThread a(argc, argv);
    
    return a.exec();
}

InitParamRead::InitParamRead()
{

}

InitParamRead::~InitParamRead()
{

}

int InitParamRead::read_ini_File()
{
    QSettings *configIniRead = new QSettings("./config/Server.ini", QSettings::IniFormat);

    serverHost = configIniRead->value("/ip/local").toString();

    serverPort = configIniRead->value("/port/default").toString().toAscii().toInt();

    delete configIniRead;

    return TRUE;
}

