//
//
//

#ifndef MATRIXABSFACTORY_MATRIXTEMPLATE_H
#define MATRIXABSFACTORY_MATRIXTEMPLATE_H

#include "headers.h"

template <class T>
class MatrixTemplate {
public:
    /*Constructors and Destructor.*/
    MatrixTemplate(int r, int c) throw(std::out_of_range); /*tested*/
    MatrixTemplate(const MatrixTemplate& mt);/*tested*/
    virtual ~MatrixTemplate(); /*tested*/

    /*Matrix Operations*/
    virtual MatrixTemplate getTranspose() const;/*tested* OK*/
    virtual MatrixTemplate<T> selectRow(int rowNum) const throw(std::out_of_range);/*tested OK THROW TEST*/
    virtual MatrixTemplate<T> selectColumn(int colNum) const throw(std::out_of_range);/*tested OK THROW TEST*/
    virtual T elementPosition(int rowPos, int colPos) const throw(std::out_of_range); /*tested OK THROW TEST*/
    virtual void modifyElement(int rowNum, int colNum, const T& newValue) throw(std::out_of_range); /*tested OK THROW TEST*/
    virtual void manualInsertValues(MatrixTemplate& newMatrixTemplate); /*tested*/
    virtual void matrixOfZeros(); /*tested*/
    virtual void randomMatrix(); /*tested*/
    virtual void sequenceMatrix(); /*tested*/
    virtual void manualInsertValues(); /*tested*/
    virtual void printMatrix(MatrixTemplate& matrixTemplate); /*tested*/
    virtual void printMatrix(std::string matrixName); /*tested*/
    virtual void printMatrix(); /*tested*/

    /*Operator overloading*/
    virtual MatrixTemplate<T> operator+(const MatrixTemplate<T>& mt) const throw(std::out_of_range);/*tested OK THROW TEST*/
    virtual MatrixTemplate<T> operator*(const MatrixTemplate<T>& mt) const throw(std::out_of_range); /*tested OK THROW TEST*/
    virtual MatrixTemplate<T> operator-(const MatrixTemplate<T>& mt) const throw(std::out_of_range);/*tested OK*/
    virtual MatrixTemplate<T> operator*(const T& num); /*tested OK*/
    virtual MatrixTemplate<T>& operator=(const MatrixTemplate<T>& mt);/*tested OK*/
    virtual MatrixTemplate<T> operator/(const T& num); /*tested OK*/
    virtual bool operator==(const MatrixTemplate<T>& mt) const;/*tested OK*/
    virtual bool operator!=(const MatrixTemplate<T>& mt) const;/*tested OK*/

    /*Getters and setters*/
    virtual int getRows() const ; /*tested OK*/
    virtual int getColumns() const ; /*tested OK*/
    virtual const std::string &getMatrixName() const; /*tested OK*/
    virtual void setMatrixName(const std::string &_matrixName); /*tested OK*/
    virtual void setRows(int _rows); /*tested OK*/
    virtual void setColumns(int _columns); /*testd OK*/
    virtual void setMatrixId(int matrixId); /*tested*/
    virtual int getMatrixId(); /*tested*/
    T *get_buffer() const;

protected:
    int _rows, _columns;
    T* _buffer;
    std::string _matrixName;
    int matrixId;

    void copier(const MatrixTemplate& mt);

};

/*=================================IMPLEMENTATION/*=================================*/

/*Constructors and Destructors.*/
template <class T>
MatrixTemplate<T>::MatrixTemplate(int r, int c) throw(std::out_of_range) : _rows(r), _columns(c) {
    if(this->_rows <= 0 || this->_columns <= 0)
        throw std::out_of_range("Number of rows and columns must be positive.");
    _buffer = new T[_rows * _columns];
    srand((unsigned)time(0));
    for(int i = 0; i <_rows*_columns; i++)
        //_buffer[i] = (rand()%10)+1;
        _buffer[i] = 0;
}
template <class T>
MatrixTemplate<T>::MatrixTemplate(const MatrixTemplate &mt) {
    copier(mt);
}
template <class T>
MatrixTemplate<T>::~MatrixTemplate() {
    if(_buffer)
        delete[] _buffer;
}

/*Matrix operations.*/
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::getTranspose() const{
    MatrixTemplate<T> tmp(_columns, _rows);
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _columns; j++)
            tmp._buffer[tmp._columns * j + i] = _buffer[_columns * i + j];
    return tmp;
}
template <class T>
void MatrixTemplate<T>::printMatrix(MatrixTemplate &matrixTemplate) {
    for(int i = 0; i<_rows; i++) {
        for (int j = 0; j < _columns; j++)
            std::cout << "\t[" << _buffer[j + i * _columns] << "]";
        std::cout << std::endl;
    }
}
template <class T>
void MatrixTemplate<T>::printMatrix(std::string matrixName) {
    std::cout << "\n\t" << matrixName << " MATRIX   " << std::endl;
    std::cout << "\t";
    for(unsigned short int i =0; i != matrixName.size(); i++)
        std::cout << "-";
    std::cout << "-------" << std::endl;
    for(int i = 0; i<_rows; i++) {
        for (int j = 0; j < _columns; j++)
            std::cout << "\t[" << _buffer[j + i * _columns] << "]";
        std::cout << std::endl;
    }
}
template <class T>
void MatrixTemplate<T>::printMatrix() {
    std::cout << "\n\t" << this->_matrixName << " MATRIX" << std::endl;
    std::cout << "\t";
    for(unsigned short int i =0; i != this->_matrixName.size(); i++)
        std::cout << "-";
    std::cout << "-------" << std::endl;
    for(int i = 0; i<_rows; i++) {
        for (int j = 0; j < _columns; j++)
            std::cout << "\t[" << _buffer[j + i * _columns] << "]";
        std::cout << std::endl;
    }

}
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::selectRow(int rowNum) const throw(std::out_of_range) {
    if(rowNum <= 0 || rowNum > _rows)
        throw std::out_of_range("Invalid row selection.");

    MatrixTemplate<T> rowMatrix(1, _columns);
    for(int i = 0; i<_columns; i++)
        rowMatrix._buffer[i] = _buffer[i+_columns*(rowNum-1)];
    return rowMatrix;
}
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::selectColumn(int colNum) const throw(std::out_of_range) {
    if(colNum <= 0 || colNum > _columns)
        throw std::out_of_range("Invalid columns selection.");

    MatrixTemplate<T> columnMatrix(_rows, 1);
    for(int j = 0; j<_rows; j++)
        columnMatrix._buffer[j] = _buffer[j*_rows];
    return columnMatrix;
}
template <class T>
void MatrixTemplate<T>::modifyElement(int rowNum, int colNum, const T& newValue) throw(std::out_of_range) {
    if(rowNum<=0 || rowNum > _rows || colNum <= 0 || colNum > _columns)
        throw std::out_of_range("Invalid row or columns selection.");
    if(_rows <= 0 || rowNum > _rows|| _columns <= 0 || colNum > _columns)
        throw std::out_of_range("Invalid number index.");
    _buffer[(rowNum-1)* _columns + (colNum-1)] = newValue;
}
template <class T>
T MatrixTemplate<T>::elementPosition(int rowPos, int colPos) const throw(std::out_of_range) {
    if(rowPos<=0 || rowPos > _rows || colPos <= 0 || colPos > _columns)
        throw std::out_of_range("Invalid row or columns selection.");
    T element = _buffer[(colPos-1) + (rowPos-1) * _columns];
    return element;
}
template<class T>
void MatrixTemplate<T>::manualInsertValues(MatrixTemplate &newMatrixTemplate) {
    std::cout << std:: endl;
    T value;
    for(int i = 0; i<_rows; i++){
        for(int j = 0; j <_columns; j++){
            std::cout << "Insert element at Matrix[" << i+1 << "]["<< j+1 << "]:"; std::cin >> value;
            _buffer[j+i*_columns] = value;
        }
    }
}
template <class T>
void MatrixTemplate<T>::matrixOfZeros() {
    for(int i = 0; i <_rows*_columns; i++)
        _buffer[i] = 0;
}
template <class T>
void MatrixTemplate<T>::randomMatrix() {
    srand((unsigned)time(0));
    for(int i = 0; i <_rows*_columns; i++)
        _buffer[i] = (rand()%10)+1;
}
template <class T>
void MatrixTemplate<T>::sequenceMatrix() {
    for(int i = 0; i<_rows*_columns; i++)
        _buffer[i] = i+1;
}
template<class T>
void MatrixTemplate<T>::manualInsertValues() {
    T value;
    std::cout << std::endl;
    for(int i = 0; i<_rows; i++){
        for(int j = 0; j <_columns; j++){
            std::cout << "Insert element at Matrix[" << i+1 << "]["<< j+1 << "]:"; std::cin >> value;
            _buffer[j+i*_columns] = value;
        }
    }
}

/*Operator overloading.*/
template <class T>
MatrixTemplate<T>& MatrixTemplate<T>::operator=(const MatrixTemplate<T>& mt) {
    if(this != &mt){
        delete[] _buffer;
        copier(mt);
    }
    return *this;
}
template <class T>
bool MatrixTemplate<T>::operator==(const MatrixTemplate<T>& mt) const{
    if(_rows == mt._rows || _columns == mt._columns) {
        for (int i = 0; i < _rows * _columns; i++)
            if (_buffer[i] != mt._buffer[i])
                return false;
    }
    return true;
}
template <class T>
bool MatrixTemplate<T>::operator!=(const MatrixTemplate<T>& mt) const {
    return !(*this == mt);
}
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator+(const MatrixTemplate<T>& mt) const throw(std::out_of_range){
    if(this->_rows != mt._rows || this->_columns != mt._columns)
        throw std::out_of_range("Not compatible matrix for addition operation.");
    MatrixTemplate<T> sumMatrix(_rows, _columns);
    for (int i = 0; i < _rows * _columns; i++) {
        sumMatrix._buffer[i] = _buffer[i] + mt._buffer[i];
    }
    return sumMatrix;
}
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator*(const MatrixTemplate<T> &mt) const throw(std::out_of_range){
    if(this->_columns != mt._rows)
        throw std::out_of_range("Now compatible columns and rows for moltiplication.");
    MatrixTemplate<T> prodMatrix(_rows, mt._columns);
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < mt._columns; j++) {
            prodMatrix._buffer[i * mt._columns + j] = 0;
            for (int h = 0; h < _columns; h++)
                prodMatrix._buffer[i * mt._columns + j] +=
                        _buffer[i * _columns + h] * mt._buffer[h * mt._columns + j];
        }
    return prodMatrix;
}
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator*(const T& num){
    MatrixTemplate<T> prodNum(_rows,_columns);
    for(int i = 0; i<_rows*_columns; i++)
        prodNum._buffer[i] = num * _buffer[i];
    return prodNum;
}
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator/(const T &num) {
    MatrixTemplate<T> divNum(_rows,_columns);
    for(int i = 0; i <_rows*_columns; i++)
        divNum._buffer[i] = _buffer[i]/num;
    return divNum;
}
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator-(const MatrixTemplate<T>& mt) const throw(std::out_of_range){
    if(this->_rows != mt._rows || this->_columns != mt._columns)
        throw std::out_of_range("Not compatible matrix for subtraction operation.");
    MatrixTemplate<T> subMatrix(_rows, _columns);
    for (int i = 0; i < _rows * _columns; i++) {
        subMatrix._buffer[i] = _buffer[i] - mt._buffer[i];
    }
    return subMatrix;
}

/*Getters and setters.*/
template <class T>
int MatrixTemplate<T>::getRows() const {
    return _rows;
}
template <class T>
int MatrixTemplate<T>::getColumns() const {
    return _columns;
}
template <class T>
void MatrixTemplate<T>::copier(const MatrixTemplate &mt) {
    _rows = mt._rows;
    _columns = mt._columns;
    _buffer = new T[_rows * _columns];
    for(int i = 0; i <_rows*_columns; i++)
        _buffer[i] = mt._buffer[i];
}
template<class T>
const std::string &MatrixTemplate<T>::getMatrixName() const {
    return _matrixName;
}
template<class T>
void MatrixTemplate<T>::setMatrixName(const std::string &_matrixName) {
    this->_matrixName = _matrixName;
}
template<class T>
void MatrixTemplate<T>::setRows(int _rows) {
    this->_rows = _rows;
}
template<class T>
void MatrixTemplate<T>::setColumns(int _columns) {
    this->_columns = _columns;
}
template <class T>
void MatrixTemplate<T>::setMatrixId(int matrixId) {
    this->matrixId = matrixId;
}
template <class T>
int MatrixTemplate<T>::getMatrixId() {
    return matrixId;
}
template<class T>
T *MatrixTemplate<T>::get_buffer() const {
    return _buffer;
}


#endif //MATRIXABSFACTORY_MATRIXTEMPLATE_H