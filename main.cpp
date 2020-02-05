#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "Matrix.h"

void createMatrix(QString& name, Matrix& matrix)
{
    name.prepend("Matrix ");

    int row = 0, column = 0;
    qDebug() << QString("Enter number of rows for %1: ").arg(name);
    std::cin >> row;

    qDebug() << QString("Enter number of columns for %1: ").arg(name);
    std::cin >> column;

    /*! Resize the default matrix based on user input */
    matrix.setRows(row);
    matrix.setColumns(column);

    MatrixData tmpData;

    qDebug() << QString("Enter %1 data for population").arg(name);
    for (int i = 0; i < row; ++i)
    {
        QList<int> rowData;
        for (int j = 0; j < column; ++j)
        {
            int value = 0;
            qDebug() << QString("Enter value for row : %1, column : %2 ").arg(i+1).arg(j+1);
            std::cin >> value;
            rowData << value;
        }
        tmpData.append(rowData);
    }

    bool returnValue = matrix.populate(tmpData);
    matrix.dump(name);
    if (!returnValue)
    {
        qDebug ()  << QString("Error populating %1").arg(name);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "********* Starting the Matrix multiplication test *********";

    Matrix matrix1;
    QString name("1");
    createMatrix(name, matrix1);

    Matrix matrix2;
    name = QStringLiteral("2");
    createMatrix(name, matrix2);

    Matrix resultMatrix;
    matrix1.multiply(matrix2, resultMatrix);

    resultMatrix.dump("Result Matrix");

    qDebug() << "********* Ending the matrix multiplication test *********";
    return a.exec();
}
