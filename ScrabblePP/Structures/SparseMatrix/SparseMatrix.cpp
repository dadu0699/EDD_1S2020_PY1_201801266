#include "SparseMatrix.h"

SparseMatrix::SparseMatrix()
{
    root = new SparseMatrixNode(-1, -1, 0, "Root");
}

SparseMatrix::~SparseMatrix()
{
}

SparseMatrixNode *SparseMatrix::searchColumn(int x)
{
    SparseMatrixNode *temp = root;

    while (temp != nullptr)
    {
        if (temp->getX() == x)
        {
            return temp;
        }
        temp = temp->getNextNode();
    }

    return nullptr;
}

SparseMatrixNode *SparseMatrix::searchRow(int y)
{
    SparseMatrixNode *temp = root;

    while (temp != nullptr)
    {
        if (temp->getY() == y)
        {
            return temp;
        }
        temp = temp->getDownNode();
    }

    return nullptr;
}

SparseMatrixNode *SparseMatrix::insertIntoColumn(SparseMatrixNode *node, SparseMatrixNode *headerRow)
{
    SparseMatrixNode *temp = headerRow;
    bool flag = false;

    while (true)
    {
        if (temp->getX() == node->getX())
        {
            temp->setY(node->getY());
            temp->setData(node->getData());
            temp->setScore(node->getScore());
            return temp;
        }
        else if (temp->getX() > node->getX())
        {
            flag = true;
            break;
        }

        if (temp->getNextNode() != nullptr)
        {
            temp = temp->getNextNode();
        }
        else
        {
            // flag = false;
            break;
        }
    }

    if (flag)
    {
        node->setNextNode(temp);
        temp->getPreviousNode()->setNextNode(node);
        node->setPreviousNode(temp->getPreviousNode());
        temp->setPreviousNode(node);
    }
    else
    {
        temp->setNextNode(node);
        node->setPreviousNode(temp);
    }

    return node;
}

SparseMatrixNode *SparseMatrix::insertIntoRow(SparseMatrixNode *node, SparseMatrixNode *headerColumn)
{
    SparseMatrixNode *temp = headerColumn;
    bool flag = false;

    while (true)
    {
        if (temp->getY() == node->getY())
        {
            temp->setX(node->getX());
            temp->setData(node->getData());
            temp->setScore(node->getScore());
            return temp;
        }
        else if (temp->getY() > node->getY())
        {
            flag = true;
            break;
        }

        if (temp->getDownNode() != nullptr)
        {
            temp = temp->getDownNode();
        }
        else
        {
            // flag = false;
            break;
        }
    }

    if (flag)
    {
        node->setDownNode(temp);
        temp->getUpNode()->setDownNode(node);
        node->setUpNode(temp->getUpNode());
        temp->setUpNode(node);
    }
    else
    {
        temp->setDownNode(node);
        node->setUpNode(temp);
    }

    return node;
}

SparseMatrixNode *SparseMatrix::createColumn(int x)
{
    SparseMatrixNode *headerColumn = root;
    SparseMatrixNode *column = insertIntoColumn(new SparseMatrixNode(x, -1, 0, "RootColumn"), headerColumn);
    return column;
}

SparseMatrixNode *SparseMatrix::createRow(int y)
{
    SparseMatrixNode *headerRow = root;
    SparseMatrixNode *row = insertIntoRow(new SparseMatrixNode(-1, y, 0, "RootRow"), headerRow);
    return row;
}

void SparseMatrix::addNode(int x, int y, int score, string data)
{
    SparseMatrixNode *node = new SparseMatrixNode(x, y, score, data);
    SparseMatrixNode *columnNode = searchColumn(x);
    SparseMatrixNode *rowNode = searchRow(y);

    if (columnNode == nullptr && rowNode == nullptr)
    {
        columnNode = createColumn(x);
        rowNode = createRow(y);
        node = insertIntoColumn(node, rowNode);
        node = insertIntoRow(node, columnNode);
        return;
    }
    else if (columnNode == nullptr && rowNode != nullptr)
    {
        columnNode = createColumn(x);
        node = insertIntoColumn(node, rowNode);
        node = insertIntoRow(node, columnNode);
        return;
    }
    else if (columnNode != nullptr && rowNode == nullptr)
    {
        rowNode = createRow(y);
        node = insertIntoColumn(node, rowNode);
        node = insertIntoRow(node, columnNode);
        return;
    }
    else if (columnNode != nullptr && rowNode != nullptr)
    {
        node = insertIntoColumn(node, rowNode);
        node = insertIntoRow(node, columnNode);
        return;
    }
}

void SparseMatrix::printRowHeaders()
{
    SparseMatrixNode *auxiliaryNode = root;
    while (auxiliaryNode != nullptr)
    {
        cout << "^" << endl
             << auxiliaryNode->getX() << "," << auxiliaryNode->getY() << endl;
        auxiliaryNode = auxiliaryNode->getDownNode();
    }
}

void SparseMatrix::printColumnHeaders()
{
    SparseMatrixNode *auxiliaryNode = root;
    while (auxiliaryNode != nullptr)
    {
        cout << auxiliaryNode->getX() << "," << auxiliaryNode->getY() << " -> ";
        auxiliaryNode = auxiliaryNode->getNextNode();
    }
    cout << endl;
}

void SparseMatrix::printRows()
{
    SparseMatrixNode *auxiliaryRow = root->getDownNode();
    SparseMatrixNode *auxiliaryNode = auxiliaryRow;

    while (auxiliaryRow != nullptr)
    {
        while (auxiliaryNode != nullptr)
        {
            cout << auxiliaryNode->getData() << " -> ";
            auxiliaryNode = auxiliaryNode->getNextNode();
        }

        auxiliaryRow = auxiliaryRow->getDownNode();
        auxiliaryNode = auxiliaryRow;
        cout << endl;
    }
    cout << endl;
}

void SparseMatrix::printColumns()
{
    SparseMatrixNode *auxiliaryColumn = root->getNextNode();
    SparseMatrixNode *auxiliaryNode = auxiliaryColumn;

    while (auxiliaryColumn != nullptr)
    {
        while (auxiliaryNode != nullptr)
        {
            cout << "^" << endl
                 << auxiliaryNode->getData() << endl;
            auxiliaryNode = auxiliaryNode->getDownNode();
        }

        auxiliaryColumn = auxiliaryColumn->getNextNode();
        auxiliaryNode = auxiliaryColumn;
        cout << endl;
    }
    cout << endl;
}

void SparseMatrix::report()
{
    ofstream myfile("board.dot");

    if (myfile.is_open())
    {
        if (root != nullptr)
        {
            SparseMatrixNode *rowHeaders = root->getDownNode();
            SparseMatrixNode *columnHeaders = root->getNextNode();
            SparseMatrixNode *auxiliaryRow = root->getDownNode();
            SparseMatrixNode *auxiliaryColumn = root->getNextNode();
            SparseMatrixNode *auxiliaryNode;

            myfile << "digraph Sparce_Matrix {";
            myfile << "node [shape=box]";
            myfile << "Mt[ label = \"Tablero\", width = 1.5, style = filled, group = 1 ];";

            while (rowHeaders != nullptr)
            {
                myfile << "R" << rowHeaders->getY();
                myfile << "[label = \"(" << rowHeaders->getX() << "," << rowHeaders->getY() << ")\"";
                myfile << "width = 1.5 style = filled, fillcolor = bisque1, group = 1 ];";
                rowHeaders = rowHeaders->getDownNode();
            }

            rowHeaders = root->getDownNode();
            while (rowHeaders->getDownNode() != nullptr)
            {
                myfile << "R" << rowHeaders->getY() << "-> R" << rowHeaders->getDownNode()->getY() << ";";
                rowHeaders = rowHeaders->getDownNode();
            }

            while (columnHeaders != nullptr)
            {
                myfile << "C" << columnHeaders->getX();
                myfile << "[label = \"(" << columnHeaders->getX() << "," << columnHeaders->getY() << ")\"";
                myfile << "width = 1.5 style = filled, fillcolor = bisque, group =" << columnHeaders->getX() + 2
                       << "];";
                columnHeaders = columnHeaders->getNextNode();
            }

            columnHeaders = root->getNextNode();
            while (columnHeaders->getNextNode() != nullptr)
            {
                myfile << "C" << columnHeaders->getX() << "-> C" << columnHeaders->getNextNode()->getX() << ";";
                columnHeaders = columnHeaders->getNextNode();
            }

            myfile << "Mt -> R" << root->getDownNode()->getY() << ";";
            myfile << "Mt -> C" << root->getNextNode()->getX() << ";";

            myfile << "{ rank = same; Mt;";
            columnHeaders = root->getNextNode();
            while (columnHeaders != nullptr)
            {
                myfile << "C" << columnHeaders->getX() << ";";
                columnHeaders = columnHeaders->getNextNode();
            }
            myfile << "}";

            while (auxiliaryRow != nullptr)
            {
                auxiliaryNode = auxiliaryRow->getNextNode();
                while (auxiliaryNode != nullptr)
                {
                    myfile << "C" << auxiliaryNode->getX();
                    myfile << "R" << auxiliaryNode->getY();
                    myfile << " [label = \"" << auxiliaryNode->getData() << "\" width = 1.5,";

                    if (auxiliaryNode->getScore() == 3)
                    {
                        myfile << " style = filled, fillcolor = coral1,";
                    }
                    else if (auxiliaryNode->getScore() == 2)
                    {
                        myfile << " style = filled, fillcolor = cyan3,";
                    }
                    else
                    {
                        myfile << " style = filled, fillcolor = cornsilk2,";
                    }

                    myfile << " group = " << auxiliaryNode->getX() + 2 << "];";
                    auxiliaryNode = auxiliaryNode->getNextNode();
                }
                auxiliaryRow = auxiliaryRow->getDownNode();
            }

            auxiliaryRow = root->getDownNode();
            while (auxiliaryRow != nullptr)
            {
                auxiliaryNode = auxiliaryRow;
                while (auxiliaryNode->getNextNode() != nullptr)
                {
                    if (auxiliaryNode->getX() == -1)
                    {
                        myfile << "R" << auxiliaryNode->getY();
                    }
                    else
                    {
                        myfile << "C" << auxiliaryNode->getX();
                        myfile << "R" << auxiliaryNode->getY();
                    }
                    myfile << " -> C" << auxiliaryNode->getNextNode()->getX();
                    myfile << "R" << auxiliaryNode->getNextNode()->getY() << " [dir=\"both\"];";
                    auxiliaryNode = auxiliaryNode->getNextNode();
                }

                myfile << "{ rank = same; ";
                auxiliaryNode = auxiliaryRow;
                while (auxiliaryNode != nullptr)
                {
                    if (auxiliaryNode->getX() == -1)
                    {
                        myfile << " R" << auxiliaryNode->getY() << ";";
                    }
                    else
                    {
                        myfile << " C" << auxiliaryNode->getX();
                        myfile << "R" << auxiliaryNode->getY() << ";";
                    }
                    auxiliaryNode = auxiliaryNode->getNextNode();
                }
                myfile << "}";

                auxiliaryRow = auxiliaryRow->getDownNode();
            }

            while (auxiliaryColumn != nullptr)
            {
                auxiliaryNode = auxiliaryColumn;
                while (auxiliaryNode->getDownNode() != nullptr)
                {
                    if (auxiliaryNode->getY() == -1)
                    {
                        myfile << "C" << auxiliaryNode->getX();
                    }
                    else
                    {
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
        }
    }
    else
    {
        cout << "Unable to open file";
    }
}

SparseMatrixNode *SparseMatrix::getNode(int x, int y)
{
    SparseMatrixNode *columnNode = searchColumn(x);
    SparseMatrixNode *rowNode = searchRow(y);

    if (columnNode != nullptr && rowNode != nullptr)
    {
        SparseMatrixNode *auxiliaryNode = root;
        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getY() == y)
            {
                break;
            }
            auxiliaryNode = auxiliaryNode->getDownNode();
        }

        while (auxiliaryNode != nullptr)
        {
            if (auxiliaryNode->getX() == x)
            {
                return auxiliaryNode;
            }
            auxiliaryNode = auxiliaryNode->getNextNode();
        }
    }
    return nullptr;
}