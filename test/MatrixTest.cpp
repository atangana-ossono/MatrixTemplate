#include "gtest/gtest.h"

#include "../MatrixFactoryType.h"

TEST(MatrixTemplate, testConstructor){
    MatrixTemplate<int> testMatrix(3,3);
    testMatrix.printMatrix();
    bool anwser = true;
    for(int i = 1; i<=testMatrix.getRows(); i++)
        for(int j = 1; j<=testMatrix.getColumns(); j++){
            if(testMatrix.elementPosition(i,j) != 0)
                anwser = false;
            else
                anwser = true;
    }
    ASSERT_EQ(anwser, true);
}

TEST(MatrixTemplate, testConstructorThrowException){
    ASSERT_THROW(MatrixTemplate<int> testMatrix(0,0), std::out_of_range);
}
TEST(MatrixTemplate, testRecMatrix){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* recMatrix = matrixFactory->selectMatrixType(2,3);
    bool anwser = false;

    if(recMatrix->getColumns() != recMatrix->getRows() && recMatrix->getRows() > 1 && recMatrix->getColumns() >1)
        anwser = true;
    ASSERT_EQ(anwser, true);
}
TEST(MatrixTemplate, testSquareMatrix){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* squareMatrix = matrixFactory->selectMatrixType(2,2);
    bool anwser = false;
    if(squareMatrix->getColumns() == squareMatrix->getRows() && squareMatrix->getRows() > 1 && squareMatrix->getColumns() > 1)
        anwser = true;
    ASSERT_EQ(anwser, true);
}
TEST(MatrixTemplate, testSelectRow){
    MatrixTemplate<int> testMatrix(2,2);
    ASSERT_THROW(testMatrix.selectRow(3), std::out_of_range);
    EXPECT_THROW(testMatrix.selectRow(0), std::out_of_range);
}
TEST(MatrixTemplate, testSelectColumn){
    MatrixTemplate<int> testMatrix(2,2);
    ASSERT_THROW(testMatrix.selectRow(3), std::out_of_range);
    EXPECT_THROW(testMatrix.selectRow(0), std::out_of_range);
}
TEST(MatrixTemplate, testTranspose){
    MatrixTemplate<int> firstMatrix(2,2);
    firstMatrix.randomMatrix();
    MatrixTemplate<int> transposeMatrix = firstMatrix.getTranspose();
    ASSERT_EQ(firstMatrix.elementPosition(1,1), transposeMatrix.elementPosition(1,1));
    ASSERT_EQ(firstMatrix.elementPosition(1,2), transposeMatrix.elementPosition(2,1));
    ASSERT_EQ(firstMatrix.elementPosition(2,1), transposeMatrix.elementPosition(1,2));
    ASSERT_EQ(firstMatrix.elementPosition(2,2), transposeMatrix.elementPosition(2,2));
}
TEST(MatrixTemplate, testElementPosition){
    MatrixTemplate<int> firstMatrix(2,2);
    firstMatrix.modifyElement(1,1,1);
    firstMatrix.modifyElement(1,2,1);
    firstMatrix.modifyElement(2,1,1);
    firstMatrix.modifyElement(2,2,1);
    firstMatrix.modifyElement(1,1,5);
    ASSERT_THROW(firstMatrix.modifyElement(1,5,1), std::out_of_range);
    EXPECT_THROW(firstMatrix.modifyElement(1,0,0), std::out_of_range);
    ASSERT_TRUE(firstMatrix.elementPosition(1,1) == 5);
    ASSERT_EQ(5, firstMatrix.elementPosition(1,1));
}
TEST(MatrixTemplate, testMofidyElement){
    MatrixTemplate<int> testMatrix(2,2);
    testMatrix.randomMatrix();
    testMatrix.modifyElement(2,2,200);
    ASSERT_THROW(testMatrix.modifyElement(2,9,4), std::out_of_range);
    ASSERT_THROW(testMatrix.modifyElement(0,0,4), std::out_of_range);
    ASSERT_TRUE(testMatrix.elementPosition(2,2) == 200);
    ASSERT_EQ(200, testMatrix.elementPosition(2,2));
}
TEST(MatrixTemplate, testGetRows){
    MatrixTemplate<int> testMatrix(3,2);
    ASSERT_TRUE(testMatrix.getRows() == 3);
}
TEST(MatrixTemplate, testGetColumns){
    MatrixTemplate<int> testMatrix(3,2);
    ASSERT_TRUE(testMatrix.getColumns() == 2);
}
TEST(MatrixTemplate, testMatrixName){
    MatrixTemplate<int> testMatrix(2,2);
    testMatrix.setMatrixName("TEST");
    ASSERT_EQ("TEST", testMatrix.getMatrixName());
}
TEST(MatrixTemplate, testRestOfSetters){
    MatrixTemplate<int> testMatrix(1,1);
    testMatrix.setMatrixName("TEST");
    testMatrix.setRows(3);
    testMatrix.setColumns(2);
    ASSERT_TRUE(testMatrix.getRows() == 3);
    ASSERT_TRUE(testMatrix.getColumns() == 2);
    ASSERT_TRUE(testMatrix.getMatrixName().compare("TEST") == 0);
}
