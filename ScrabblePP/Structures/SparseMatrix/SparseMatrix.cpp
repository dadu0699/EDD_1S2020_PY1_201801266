/*
#include "SparseMatrix.h"

template<class T>
SparseMatrix<T>::SparseMatrix() {
    root = new SparseMatrixNode<T>(-1, -1);
}

template<class T>
SparseMatrix<T>::~SparseMatrix() {
}

template<class T>
SparseMatrixNode<T> *SparseMatrix<T>::searchColumn(int x) {
    SparseMatrixNode<T> *temp = root;

    while (temp != nullptr) {
        if (temp->getX() == x) {
            return temp;
        }
        temp = temp->getNextNode();
    }

    return nullptr;
}

template<class T>
SparseMatrixNode<T> *SparseMatrix<T>::searchRow(int y) {
    SparseMatrixNode<T> *temp = root;

    while (temp != nullptr) {
        if (temp->getY() == y) {
            return temp;
        }
        temp = temp->getDownNode();
    }

    return nullptr;
}

template<class T>
SparseMatrixNode<T> *SparseMatrix<T>::insertIntoColumn(SparseMatrixNode<T> *node, SparseMatrixNode<T> *headerRow) {
    SparseMatrixNode<T> *temp = headerRow;
    bool flag = false;

    while (true) {
        if (temp->getX() == node->getX()) {
            temp->setY(node->getY());
            temp->setObject(node->getObject());
            return temp;
        } else if (temp->getX() > node->getX()) {
            flag = true;
            break;
        }

        if (temp->getNextNode() != nullptr) {
            temp = temp->getNextNode();
        } else {
            // flag = false;
            break;
        }
    }

    if (flag) {
        node->setNextNode(temp);
        temp->getPreviousNode()->setNextNode(node);
        node->setPreviousNode(temp->getPreviousNode());
        temp->setPreviousNode(node);
    } else {
        temp->setNextNode(node);
        node->setPreviousNode(temp);
    }

    return node;
}

template<class T>
SparseMatrixNode<T> *SparseMatrix<T>::insertIntoRow(SparseMatrixNode<T> *node, SparseMatrixNode<T> *headerColumn) {
    SparseMatrixNode<T> *temp = headerColumn;
    bool flag = false;

    while (true) {
        if (temp->getY() == node->getY()) {
            temp->setX(node->getX());
            temp->setObject(node->getObject());
            return temp;
        } else if (temp->getY() > node->getY()) {
            flag = true;
            break;
        }

        if (temp->getDownNode() != nullptr) {
            temp = temp->getDownNode();
        } else {
            // flag = false;
            break;
        }
    }

    if (flag) {
        node->setDownNode(temp);
        temp->getUpNode()->setDownNode(node);
        node->setUpNode(temp->getUpNode());
        temp->setUpNode(node);
    } else {
        temp->setDownNode(node);
        node->setUpNode(temp);
    }

    return node;
}

template<class T>
SparseMatrixNode<T> *SparseMatrix<T>::createColumn(int x) {
    SparseMatrixNode<T> *headerColumn = root;
    SparseMatrixNode<T> *column = insertIntoColumn(new SparseMatrixNode<T>(x, -1), headerColumn);
    return column;
}

template<class T>
SparseMatrixNode<T> *SparseMatrix<T>::createRow(int y) {
    SparseMatrixNode<T> *headerRow = root;
    SparseMatrixNode<T> *row = insertIntoRow(new SparseMatrixNode<T>(-1, y), headerRow);
    return row;
}

template<class T>
void SparseMatrix<T>::addNode(int x, int y, T object) {
    SparseMatrixNode<T> *node = new SparseMatrixNode<T>(x, y, object);
    SparseMatrixNode<T> *columnNode = searchColumn(x);
    SparseMatrixNode<T> *rowNode = searchRow(y);

    if (columnNode == nullptr && rowNode == nullptr) {
        columnNode = createColumn(x);
        rowNode = createRow(y);
        node = insertIntoColumn(node, rowNode);
        node = insertIntoRow(node, columnNode);
        return;
    } else if (columnNode == nullptr && rowNode != nullptr) {
        columnNode = createColumn(x);
        node = insertIntoColumn(node, rowNode);
        node = insertIntoRow(node, columnNode);
        return;
    } else if (columnNode != nullptr && rowNode == nullptr) {
        rowNode = createRow(y);
        node = insertIntoColumn(node, rowNode);
        node = insertIntoRow(node, columnNode);
        return;
    } else if (columnNode != nullptr && rowNode != nullptr) {
        node = insertIntoColumn(node, rowNode);
        node = insertIntoRow(node, columnNode);
        return;
    }
}

template<class T>
void SparseMatrix<T>::printRowHeaders() {
    SparseMatrixNode<T> *auxiliaryNode = root;
    while (auxiliaryNode != nullptr) {
        cout << "^" << endl << auxiliaryNode->getX() << "," << auxiliaryNode->getY() << endl;
        auxiliaryNode = auxiliaryNode->getDownNode();
    }
}

template<class T>
void SparseMatrix<T>::printColumnHeaders() {
    SparseMatrixNode<T> *auxiliaryNode = root;
    while (auxiliaryNode != nullptr) {
        cout << auxiliaryNode->getX() << "," << auxiliaryNode->getY() << " -> ";
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    cout << endl;
}

template<class T>
void SparseMatrix<T>::printRows() {
    SparseMatrixNode<T> *auxiliaryRow = root->getDownNode();
    SparseMatrixNode<T> *auxiliaryNode = auxiliaryRow;

    while (auxiliaryRow != nullptr) {
        while (auxiliaryNode != nullptr) {
            cout << auxiliaryNode->getObject() << " -> ";
            auxiliaryNode = auxiliaryNode->getNextNode();
        }

        auxiliaryRow = auxiliaryRow->getDownNode();
        auxiliaryNode = auxiliaryRow;
        cout << endl;
    }
    cout << endl;
}

template<class T>
void SparseMatrix<T>::printColumns() {
    SparseMatrixNode<T> *auxiliaryColumn = root->getNextNode();
    SparseMatrixNode<T> *auxiliaryNode = auxiliaryColumn;

    while (auxiliaryColumn != nullptr) {
        while (auxiliaryNode != nullptr) {
            cout << "^" << endl << auxiliaryNode->getObject() << endl;
            auxiliaryNode = auxiliaryNode->getDownNode();
        }

        auxiliaryColumn = auxiliaryColumn->getNextNode();
        auxiliaryNode = auxiliaryColumn;
        cout << endl;
    }
    cout << endl;
}

template<class T>
void SparseMatrix<T>::report() {
    ofstream myfile("board.dot");

    if (myfile.is_open()) {
        if (root != nullptr) {
            SparseMatrixNode<T> *rowHeaders = root->getDownNode();
            SparseMatrixNode<T> *columnHeaders = root->getNextNode();
            SparseMatrixNode<T> *auxiliaryRow = root->getDownNode();
            SparseMatrixNode<T> *auxiliaryColumn = root->getNextNode();
            SparseMatrixNode<T> *auxiliaryNode;

            myfile << "digraph Sparce_Matrix {";
            myfile << "node [shape=box]";
            myfile << "Mt[ label = \"Tablero\", width = 1.5, style = filled, group = 1 ];";

            while (rowHeaders != nullptr) {
                myfile << "R" << rowHeaders->getY();
                myfile << "[label = \"(" << rowHeaders->getX() << "," << rowHeaders->getY() << ")\"";
                myfile << "width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];";
                rowHeaders = rowHeaders->getDownNode();
            }

            rowHeaders = root->getDownNode();
            while (rowHeaders->getDownNode() != nullptr) {
                myfile << "R" << rowHeaders->getY() << "-> R" << rowHeaders->getDownNode()->getY() << ";";
                rowHeaders = rowHeaders->getDownNode();
            }

            while (columnHeaders != nullptr) {
                myfile << "C" << columnHeaders->getX();
                myfile << "[label = \"(" << columnHeaders->getX() << "," << columnHeaders->getY() << ")\"";
                myfile << "width = 1.5 style = filled, fillcolor = bisque1, group =" << columnHeaders->getX() + 2
                       << "];";
                columnHeaders = columnHeaders->getNextNode();
            }

            columnHeaders = root->getNextNode();
            while (columnHeaders->getNextNode() != nullptr) {
                myfile << "C" << columnHeaders->getX() << "-> C" << columnHeaders->getNextNode()->getX() << ";";
                columnHeaders = columnHeaders->getNextNode();
            }

            myfile << "Mt -> R" << root->getDownNode()->getY() << ";";
            myfile << "Mt -> C" << root->getNextNode()->getX() << ";";

            myfile << "{ rank = same; Mt;";
            columnHeaders = root->getNextNode();
            while (columnHeaders != nullptr) {
                myfile << "C" << columnHeaders->getX() << ";";
                columnHeaders = columnHeaders->getNextNode();
            }
            myfile << "}";

            while (auxiliaryRow != nullptr) {
                auxiliaryNode = auxiliaryRow->getNextNode();
                while (auxiliaryNode != nullptr) {
                    myfile << "C" << auxiliaryNode->getX();
                    myfile << "R" << auxiliaryNode->getY();
                    myfile << " [label = \"" << auxiliaryNode->getObject() << "\" width = 1.5,";
                    myfile << " group = " << auxiliaryNode->getX() + 2 << "];";
                    auxiliaryNode = auxiliaryNode->getNextNode();
                }
                auxiliaryRow = auxiliaryRow->getDownNode();
            }

            auxiliaryRow = root->getDownNode();
            while (auxiliaryRow != nullptr) {
                auxiliaryNode = auxiliaryRow;
                while (auxiliaryNode->getNextNode() != nullptr) {
                    if (auxiliaryNode->getX() == -1) {
                        myfile << "R" << auxiliaryNode->getY();
                    } else {
                        myfile << "C" << auxiliaryNode->getX();
                        myfile << "R" << auxiliaryNode->getY();
                    }
                    myfile << " -> C" << auxiliaryNode->getNextNode()->getX();
                    myfile << "R" << auxiliaryNode->getNextNode()->getY() << " [dir=\"both\"];";
                    auxiliaryNode = auxiliaryNode->getNextNode();
                }

                myfile << "{ rank = same; ";
                auxiliaryNode = auxiliaryRow;
                while (auxiliaryNode != nullptr) {
                    if (auxiliaryNode->getX() == -1) {
                        myfile << " R" << auxiliaryNode->getY() << ";";
                    } else {
                        myfile << " C" << auxiliaryNode->getX();
                        myfile << "R" << auxiliaryNode->getY() << ";";
                    }
                    auxiliaryNode = auxiliaryNode->getNextNode();
                }
                myfile << "}";

                auxiliaryRow = auxiliaryRow->getDownNode();
            }

            while (auxiliaryColumn != nullptr) {
                auxiliaryNode = auxiliaryColumn;
                while (auxiliaryNode->getDownNode() != nullptr) {
                    if (auxiliaryNode->getY() == -1) {
                        myfile << "C" << auxiliaryNode->getX();
                    } else {
                        myfile << "C" << auxiliaryNode->getX();
                        myfile << "R" << auxiliaryNode->getY();
                    }
                    myfile << " -> C" << auxiliaryNode->getDownNode()->getX();
                    myfile << "R" << auxiliaryNode->getDownNode()->getY() << " [dir=\"both\"];";
                    auxiliaryNode = auxiliaryNode->getDownNode();
                }
                auxiliaryColumn = auxiliaryColumn->getNextNode();
            }

            myfile << "}";
            myfile.close();
            system("dot -Tpng board.dot -o board.png");
            system("board.png");
        } else {
            cout << "Unable to open file";
        }
    }
}
 */