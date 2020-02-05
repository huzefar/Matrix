#ifndef MATRIX_H
#define MATRIX_H

#include <QObject>

typedef QList<QList<int>> MatrixData;

class Matrix : public QObject
{
    Q_OBJECT
public:
    explicit Matrix(int nRow, int nColumn, QObject *parent = nullptr);

    /*! default matrix is 1x1 matrix */
    explicit Matrix(QObject *parent = nullptr);

    ~Matrix() {;}

    //! getters
    int getRowCount() const { return m_nRows; }
    int getColumnCount() const { return m_nColumns; }

    //! setters
    void setRows(int nRow) { m_nRows = nRow;}
    void setColumns(int nColumn) { m_nColumns = nColumn; }

    bool canMultiply(const Matrix& secondMatrix) const;

    bool populate(const MatrixData &data);

    void multiply(const Matrix& secondMatrix, Matrix &resultMatrix);

    void dump(const QString& str);
private:
    int m_nRows;
    int m_nColumns;
    MatrixData m_data;
};

#endif // MATRIX_H
