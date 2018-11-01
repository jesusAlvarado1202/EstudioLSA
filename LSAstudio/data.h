#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QVector>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(QObject *parent = 0);

    QVector<double> vframe,vcode,vcode1,vmed_code;
    QVector< QVector<int> > vtable_med_code;


signals:

public slots:

    void manageData(int frame_rate, int filter_sz);
    void initilizeData(int vector_length);
    QVector<double> filterData(QVector<double> vdata, int w_size);


};

#endif // DATA_H
