//
//
//

#ifndef MATRIXABSFACTORY_MATRIXFACTORY_H
#define MATRIXABSFACTORY_MATRIXFACTORY_H

#include "MatrixTemplate.h"
#include <memory>

template <class T>
class MatrixFactory {
public:
    MatrixFactory();
    virtual ~MatrixFactory();


protected:
    virtual MatrixTemplate<T>* createMatrix(int r, int c) throw(std::out_of_range) = 0;
};

template <class T>
MatrixFactory<T>::MatrixFactory() {
    std::cout << "\nLoading matrix resources..." << std::endl;
}
template <class T>
MatrixFactory<T>::~MatrixFactory() {

}


#endif //MATRIXABSFACTORY_MATRIXFACTORY_H
