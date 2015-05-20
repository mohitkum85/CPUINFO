#include <QApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "cpuinfomodel.h"
#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QQuickView>
#include<QQmlContext>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();
    CpuInfoModel *classmodel=new CpuInfoModel();
    ctxt->setContextProperty("myModel",classmodel);



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();

}
