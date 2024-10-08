#include "Board.h"

Board::Board(QWidget *parent) : QWidget::QWidget(parent)
{
    gridLayout = new QGridLayout;
    gridLayout->setHorizontalSpacing(3);
    gridLayout->setVerticalSpacing(3);
    setLayout(gridLayout);
    
    AddButtonsToWidget();
}

void Board::AddButtonsToWidget()
{
    qint8 row = 0;
    qint8 col = 0;

    for (qint8 index = 0; index < countOfButtons; ++index)
    {
        qint8 randomValue = QRandomGenerator::global()->generate() % 15 + 1;
        PuzzlePiece* button = new PuzzlePiece(QString::number(randomValue));
        button->setObjectName(QString::number(randomValue));
        
        if (CheckEqualTextButton(randomValue))
        {
            --index;
            delete button;
            continue;
        }

        button->setParent(this);

        gridLayout->addWidget(button, row, col);
        ++col;
        if (col == 4)
        {
            ++row;
            col = 0;
        }
    }
}

bool Board::CheckEqualTextButton(const qint8& randomValue)
{
    auto tempButton = findChild<QPushButton*>(QString::number(randomValue));

    if (tempButton)
        return true;

    return false;
}
