#include "cpuinfomodel.h"
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QStandardItem>
#include <QTableView>
CpuInfoModel::CpuInfoModel(QObject *parent) : QStandardItemModel(parent)
{
    setRolesName();

    fillData();
    setColumnCount(1);
}

CpuInfoModel::~CpuInfoModel()
{

}

void CpuInfoModel::setRolesName()
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name",
            roles[ValueRole]= "value";


    setItemRoleNames(roles);
}

bool CpuInfoModel::fillData()
{
    bool result=false;

#ifdef Q_OS_LINUX
        QFile cpu_file("/proc/cpuinfo");
#endif

#ifdef Q_OS_WIN
        QFile cpu_file("cpuinfo");
#endif
        if(cpu_file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&cpu_file);
            QString line = in.readLine();
            while (!line.isNull()) {
                qDebug()<<line;
                if(line.split(":").count()==2)
                { QStringList keyvaluelist=line.split(":");
                    QStandardItem *item = new QStandardItem();
                    item->setData(keyvaluelist.at(0),NameRole);
                    item->setData(keyvaluelist.at(1),ValueRole);
                    setRowCount(rowCount()+1);
                    qDebug()<<rowCount();
                    insertRow(rowCount(),item);
                }
                line = in.readLine();


            }
            result =true;
        }
        else
            qWarning()<<cpu_file.errorString();

    return result;
}
