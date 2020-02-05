#include <QCoreApplication>
#include <QDebug>

#include "Matrix.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "starting the matrix multiplication test";

    Matrix matrix(2,2);
    MatrixData tmpData;

    QList<int> firstRow;
    firstRow << 1 << 2;
    QList<int> secondRow;
    secondRow << 3 << 4;

    tmpData.append(firstRow);
    tmpData.append(secondRow);

    bool returnValue = matrix.populate(tmpData);
    matrix.dump("First Matrix");
    if (!returnValue)
    {
        qDebug ()  << "Error populating matrix";
    }

    Matrix matrix2(2,2);
    MatrixData tmpData2;

    QList<int> firstRow2;
    firstRow2 << 5 << 6;
    QList<int> secondRow2;
    secondRow2 << 7 << 8;

    tmpData2.append(firstRow2);
    tmpData2.append(secondRow2);

    returnValue = matrix2.populate(tmpData2);
    matrix2.dump("Second Matrix");
    if (!returnValue)
    {
        qDebug ()  << "Error populating matrix";
    }

    Matrix resultMatrix;
    matrix.multiply(matrix2, resultMatrix);

    resultMatrix.dump("Result Matrix");

    return a.exec();
}
