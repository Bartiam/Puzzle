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
        
        if (CheckButtonText(randomValue))
        {
            --index;
            delete button;
            continue;
        }
        
        buttons.push_back(button);

        gridLayout->addWidget(button, row, col);
        ++col;
        if (col == 4)
        {
            ++row;
            col = 0;
        }
    }
}

bool Board::CheckButtonText(const qint8 randomValue)
{
    for (qint8 i = 0; i < buttons.size(); ++i)
    {
        if (buttons[i]->text().toInt() == randomValue)
        {
            return true;
        }
    }
    return false;
}
