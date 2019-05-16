//
//
//

#ifndef MATRIXABSFACTORY_MATRIXFACTORYTYPE_H
#define MATRIXABSFACTORY_MATRIXFACTORYTYPE_H

#include "MatrixFactory.h"

template <class T>
class MatrixFactoryType : public MatrixFactory<T>{
public:
    virtual MatrixTemplate<T>* createMatrix(int c, int r) throw(std::out_of_range) override;
};

template <class T>
MatrixTemplate<T>* MatrixFactoryType<T>::createMatrix(int r, int c) throw(std::out_of_range){
    MatrixTemplate<T>* matrixTemplate;
    std::cout << std::endl;
    if(r == 1 && c > 0) {
        matrixTemplate = new MatrixTemplate<T>(1, c);
        std::cout << "You have selected a row (" <<r <<  "x" << c <<  ") matrix." << std::endl;
        matrixTemplate->setMatrixName("ROW");
    }else if(r > 0 && c == 1) {
        matrixTemplate = new MatrixTemplate<T>(r, 1);
        std::cout << "You have selected a column (" <<r <<  "x" << c <<  ") matrix." << std::endl;
        matrixTemplate->setMatrixName("COLUMN");
    }else if(r == c) {
        matrixTemplate = new MatrixTemplate<T>(r, c);
        std::cout << "You have selected a square (" <<r <<  "x" << c <<  ") matrix." << std::endl;
        matrixTemplate->setMatrixName("SQUARE");
    }else if(r > 0 && c > 0 && r !=c ) {
        matrixTemplate = new MatrixTemplate<T>(r, c);
        std::cout << "You have selected a rectangular (" <<r <<  "x" << c <<  ") matrix." << std::endl;
        matrixTemplate->setMatrixName("RECTANGULAR");
    }else{
        throw std::out_of_range("Rows and columns must be positive.");
    }
    return matrixTemplate;
}


#endif //MATRIXABSFACTORY_MATRIXFACTORYTYPE_H
