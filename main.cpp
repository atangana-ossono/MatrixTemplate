#include "headers.h"
#include "MatrixTemplate.h"
#include "MatrixFactory.h"
#include "MatrixFactoryType.h"

int intMatrix();
void floatMatrix();

int main(int argc, char **argv){
    MatrixFactoryType<int>* matrixfactorytype = new MatrixFactoryType<int>();
    int rows = 0,columns = 0;
    int value = 0;
    int posCol = 0, posRow = 0, newValue = 0;
    int selCol = 0, selRow = 0;

    do {
        std::cout << "\nEnter matrix rows: ";std::cin >> rows;
        std::cout << "Enter matrix columns: "; std::cin >> columns;
    }while(rows <= 0 || columns <=0);
    MatrixTemplate<int>* newMatrix = matrixfactorytype->createMatrix(rows,columns);
    newMatrix->manualInsertValues();
    newMatrix->printMatrix();
    int numero = 0;
    std:: string avanti= "si" ;
    std:: string comp = "";
    std::cout <<"questo è l'elenco delle operazioni possibili con le matrici " << std::endl;
    came:
        std::cout <<"1) prodotto di una matrice per un valore"<<std::endl;
        std::cout <<"2) prodotto fra due matrici"<<std::endl;
        std::cout <<"3) modifica di un elemento della matrice"<<std::endl;
        std::cout <<"4) selezione della riga e della colonna di una matrice"<<std::endl;
    
        std::cout<<"seleziona il numero dell'operazione: ";std::cin >> numero;
    

    switch (numero){

        case 1 :

            std::cout << "\nMULTIPLY MATRIX WITH VALUE" << std::endl;
            std::cout << "==========================" << std::endl;
            std::cout << "Enter multiply value: "; std::cin >> value;
            *newMatrix = (*newMatrix)*value;
            newMatrix->printMatrix();
            std::cout<<"se vuoi effetuare un'altra operazione premi si"; std::cin >>comp;
            if (avanti.compare(comp)==0)
                goto came ;
            break ;

        case 2 : {

            std::cout << "\nMULTIPLYING TWO MATRIX" << std::endl;
            std::cout << "======================" << std::endl;
            MatrixTemplate<int> *secondMatrix = matrixfactorytype->createMatrix(3,3);
            MatrixTemplate<int> *firstMatrix = matrixfactorytype->createMatrix(3,3);
            firstMatrix->randomMatrix();
            secondMatrix->randomMatrix();
            firstMatrix->setMatrixName("First matrix");
            secondMatrix->setMatrixName("Second matrix");
            firstMatrix->printMatrix();
            secondMatrix->printMatrix();
            MatrixTemplate<int> *prodMatrix = matrixfactorytype->createMatrix(3,3);
            *prodMatrix = (*firstMatrix) * (*secondMatrix);
            prodMatrix->printMatrix("Product matrix");
            std::cout<<"se vuoi effetuare un'altra operazione premi si"; std::cin >>comp;
            if (avanti.compare(comp)==0)
                goto came ;
        }
        break;

        case 3 : {

            std::cout << "\nEDIT A MATRIX ELEMENT" << std::endl;
            std::cout << "=====================" << std::endl;
            newMatrix->printMatrix();

            std::cout << "\nEnter columns position: ";
            std::cin >> posCol;
            std::cout << "Enter rows position: ";
            std::cin >> posRow;
            std::cout << "Enter new value: ";
            std::cin >> newValue;
            newMatrix->modifyElement(posCol, posRow, newValue);
            newMatrix->printMatrix();
        }
        std::cout<<"se vuoi effetuare un'altra operazione premi si"; std::cin >>comp;
        if (avanti.compare(comp)==0)
            goto came ;
        break;

        case 4 : {

            std::cout << "\nSELECTION ROW AND COLUMN OF MATRIX" << std::endl;
            std::cout << "==================================" << std::endl;

            std::cout << "Select column of matrix: ";
            std::cin >> selCol;
            std::cout << "Select row of matrix: ";
            std::cin >> selRow;

            MatrixTemplate<int> *rowMatrix = matrixfactorytype->createMatrix(columns,rows);
            *rowMatrix = (*newMatrix).selectRow(selRow);
            rowMatrix->printMatrix();

            MatrixTemplate<int> *columnMatrix = matrixfactorytype->createMatrix(columns,rows);
            *columnMatrix = (*newMatrix).selectColumn(selCol);
            columnMatrix->printMatrix();
        }
        std::cout<<"se vuoi effetuare un'altra operazione premi si"; std::cin >>comp;
        if (avanti.compare(comp)==0)
            goto came ;
        break;
    }





    return 0;

}

