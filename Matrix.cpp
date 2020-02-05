#include <QDebug>
#include "Matrix.h"

Matrix::Matrix(int nRow, int nColumn, QObject *parent)
       : QObject(parent)
       , m_nRows(nRow)
       , m_nColumns(nColumn)
{
}

Matrix::Matrix(QObject *parent)
       : QObject(parent)
       , m_nRows(-1)
       , m_nColumns(-1)
{
}

bool Matrix::populate(const MatrixData& data)
{
    bool returnResult = true;

    //! first check valid rows count
    if (data.count() == m_nRows)
    {
        //! Column count should also match
        for(const QList<int>& list : data)
        {
            if (list.count() == m_nColumns)
            {
               m_data.append(list);
            }
            else {
                returnResult = false;
            }
        }
    }
    else {
        returnResult = false;
    }

//    qDebug() << "Matrix data populated: " << m_data;
    return returnResult;
}


void Matrix::multiply(const Matrix& secondMatrix, Matrix& resultMatrix)
{
    //! Rule: Column in first matrix == rows in second matrix
    if (m_nColumns != secondMatrix.m_nRows)
    {
        qDebug() << "Rule failed for matrix multiplication";
        return;
    }

    //! the result matrix is the rows of first matrix and columns of second matrix
    resultMatrix.setRows(m_nRows);
    resultMatrix.setColumns(secondMatrix.m_nColumns);

    MatrixData resultData;
    for (int i = 0 ; i < m_nRows; ++i)
    {
        QList<int> resultRow;

        QList<int> currentRow = m_data.at(i);

//        qDebug() << "currentRow " << currentRow;

        for (int j = 0; j < secondMatrix.m_nColumns; ++j)
        {
            QList<int> currentColumn;
            for (int k = 0 ; k < secondMatrix.m_nRows; ++k)
            {
                currentColumn << secondMatrix.m_data.at(k).at(j);
            }

//            qDebug() << "current column " << currentColumn;

            //! row count and column count should be same
            Q_ASSERT(currentRow.count() == currentColumn.count());

            int sum = 0;
            for (int h = 0; h < currentRow.count(); ++h)
            {
                sum += (currentRow.at(h) * currentColumn.at(h));
            }

            resultRow << sum;
        }

//        qDebug() << "Result Row" << resultRow;
        resultData.append(resultRow);
    }

    resultMatrix.populate(resultData);
}

void Matrix::dump(const QString& str)
{
    qDebug() << str << m_data;
}
