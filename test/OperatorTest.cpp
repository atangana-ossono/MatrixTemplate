//
//
//

#include "gtest/gtest.h"

#include "../MatrixFactoryType.h"

TEST(MatrixTemplate, testOperatorMul){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(2,2);
    firstMatrix->randomMatrix();
    firstMatrix->modifyElement(1,1,2);
    firstMatrix->modifyElement(1,2,2);
    firstMatrix->modifyElement(2,1,2);
    firstMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(2,2);
    secondMatrix->modifyElement(1,1,2);
    secondMatrix->modifyElement(1,2,2);
    secondMatrix->modifyElement(2,1,2);
    secondMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* resMatrix = matrixFactory->selectMatrixType(2,2);
    (*resMatrix) = (*firstMatrix)*(*secondMatrix);
    ASSERT_EQ(8,resMatrix->elementPosition(1,1));
    ASSERT_EQ(8,resMatrix->elementPosition(1,2));
    ASSERT_EQ(8,resMatrix->elementPosition(2,1));
    ASSERT_EQ(8,resMatrix->elementPosition(2,2));

    MatrixTemplate<int> testFirstMatrix(2,2);
    MatrixTemplate<int> testSecondMatrix(3,3);

    EXPECT_THROW(testFirstMatrix*testSecondMatrix, std::out_of_range);
    delete matrixFactory;
    delete firstMatrix;
    delete secondMatrix;
    delete resMatrix;
}
TEST(MatrixTemplate, testOperatorPlus){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(2,2);
    firstMatrix->randomMatrix();
    firstMatrix->modifyElement(1,1,2);
    firstMatrix->modifyElement(1,2,2);
    firstMatrix->modifyElement(2,1,2);
    firstMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(2,2);
    secondMatrix->modifyElement(1,1,2);
    secondMatrix->modifyElement(1,2,2);
    secondMatrix->modifyElement(2,1,2);
    secondMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* resMatrix = matrixFactory->selectMatrixType(2,2);
    (*resMatrix) = (*firstMatrix)+(*secondMatrix);
    ASSERT_EQ(4,resMatrix->elementPosition(1,1));
    ASSERT_EQ(4,resMatrix->elementPosition(1,2));
    ASSERT_EQ(4,resMatrix->elementPosition(2,1));
    ASSERT_EQ(4,resMatrix->elementPosition(2,2));

    MatrixTemplate<int> testFirstMatrix(2,2);
    MatrixTemplate<int> testSecondMatrix(3,3);

    EXPECT_THROW(testFirstMatrix+testSecondMatrix, std::out_of_range);
    delete matrixFactory;
    delete firstMatrix;
    delete secondMatrix;
    delete resMatrix;

}
TEST(MatrixTemplate, testOperatorSub){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(2,2);
    firstMatrix->randomMatrix();
    firstMatrix->modifyElement(1,1,2);
    firstMatrix->modifyElement(1,2,2);
    firstMatrix->modifyElement(2,1,2);
    firstMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(2,2);
    secondMatrix->modifyElement(1,1,2);
    secondMatrix->modifyElement(1,2,2);
    secondMatrix->modifyElement(2,1,2);
    secondMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* resMatrix = matrixFactory->selectMatrixType(2,2);
    (*resMatrix) = (*firstMatrix)-(*secondMatrix);
    ASSERT_EQ(0,resMatrix->elementPosition(1,1));
    ASSERT_EQ(0,resMatrix->elementPosition(1,2));
    ASSERT_EQ(0,resMatrix->elementPosition(2,1));
    ASSERT_EQ(0,resMatrix->elementPosition(2,2));

    MatrixTemplate<int> testFirstMatrix(2,2);
    MatrixTemplate<int> testSecondMatrix(3,3);

    EXPECT_THROW(testFirstMatrix-testSecondMatrix, std::out_of_range);
    delete matrixFactory;
    delete firstMatrix;
    delete secondMatrix;
    delete resMatrix;
}
TEST(MatrixTemplate, testOperatorMulNum){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(2,2);
    firstMatrix->randomMatrix();
    firstMatrix->modifyElement(1,1,2);
    firstMatrix->modifyElement(1,2,2);
    firstMatrix->modifyElement(2,1,2);
    firstMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(2,2);
    *secondMatrix = (*firstMatrix)*2;
    ASSERT_EQ(4,secondMatrix->elementPosition(1,1));
    ASSERT_EQ(4,secondMatrix->elementPosition(1,2));
    ASSERT_EQ(4,secondMatrix->elementPosition(2,1));
    ASSERT_EQ(4,secondMatrix->elementPosition(2,2));
    delete matrixFactory;
    delete firstMatrix;
    delete secondMatrix;
}
TEST(MatrixTemplate, testOperatorDivNum){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(2,2);
    firstMatrix->randomMatrix();
    firstMatrix->modifyElement(1,1,2);
    firstMatrix->modifyElement(1,2,2);
    firstMatrix->modifyElement(2,1,2);
    firstMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(2,2);
    *secondMatrix = (*firstMatrix)/2;
    ASSERT_EQ(1,secondMatrix->elementPosition(1,1));
    ASSERT_EQ(1,secondMatrix->elementPosition(1,2));
    ASSERT_EQ(1,secondMatrix->elementPosition(2,1));
    ASSERT_EQ(1,secondMatrix->elementPosition(2,2));
}
TEST(MatrixTemplate, testOperatorEqual){
    MatrixTemplate<int> firstMatrix(2,2);
    firstMatrix.modifyElement(1,1,2);
    firstMatrix.modifyElement(1,2,2);
    firstMatrix.modifyElement(2,1,2);
    firstMatrix.modifyElement(2,2,2);
    MatrixTemplate<int> secondMatrix = firstMatrix;
    ASSERT_TRUE(firstMatrix==secondMatrix);
}
TEST(MatrixTemplate, testOperatorNotEquall){
    MatrixTemplate<int> firstMatrix(2,2);
    firstMatrix.modifyElement(1,1,2);
    firstMatrix.modifyElement(1,2,2);
    firstMatrix.modifyElement(2,1,2);
    firstMatrix.modifyElement(2,2,2);
    MatrixTemplate<int> secondMatrix(2,2);
    secondMatrix.modifyElement(1,1,2);
    secondMatrix.modifyElement(1,2,2);
    secondMatrix.modifyElement(2,1,2);
    secondMatrix.modifyElement(2,2,1);
    ASSERT_TRUE(firstMatrix!=secondMatrix);
}
TEST(MatrixTemplate, testSignOperator){
    MatrixTemplate<int> originalMatrix(2,2);
    originalMatrix.randomMatrix();
    MatrixTemplate<int> copyMatrix = originalMatrix;
    ASSERT_TRUE(originalMatrix == copyMatrix);
}