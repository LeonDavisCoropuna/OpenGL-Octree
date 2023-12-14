#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QTextStream>
#include "point.h"
#include <chrono>
#include <iostream>

void Read(QString Filename, QVector<float> &vector) {
    QFile mFile(Filename);

    if (!mFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "No pude abrir el archivo";
        return;
    }

    QTextStream in(&mFile);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList strList = line.split(",", QString::SkipEmptyParts);


        for (int i = 0; i < strList.length(); i++) {
            vector.push_back(strList[i].toFloat()/200);
        }
    }

    mFile.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QVector<float> dat;

    QString mFilename = "/home/leon/Documentos/eda/Octree/data/points2.csv";


    Read(mFilename,dat);
    qDebug() <<"puntos: " << dat.size()/3;

    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<dat.size()-3; i=i+3)
    {
        w.qTree->insert(new Point(dat[i],(dat[i+1]),dat[i+2]));
        //mostrar los puntos
        //w.pointsW.push_back(new Point(dat[i],(dat[i+1]),dat[i+2]));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;

    qDebug() << "Tiempo de insersion: " << diff.count() << " s\n";

    w.paintGL();

    w.setTitle("Octree - Leon Davis");
    w.resize(800,800);
    w.show();

    return a.exec();
}
