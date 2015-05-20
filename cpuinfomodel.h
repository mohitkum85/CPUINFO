#ifndef CPUINFOMODEL_H
#define CPUINFOMODEL_H

#include <QObject>
#include <QStandardItemModel>
class CpuInfoModel : public QStandardItemModel
{

    Q_OBJECT
protected:
    void setRolesName();
     bool fillData();
public:

    enum CpuRoles {
        NameRole = Qt::UserRole + 1,
        ValueRole

    };
    explicit CpuInfoModel(QObject *parent = 0);
    ~CpuInfoModel();

signals:

public slots:
};

#endif // CPUINFOMODEL_H
