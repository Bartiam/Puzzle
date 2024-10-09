#include "Board.h"

Board::Board(QWidget *parent) : QWidget::QWidget(parent)
{
    // Создание и установка параметров для QGridLayout.
    gridLayout = new QGridLayout;
    gridLayout->setHorizontalSpacing(3);
    gridLayout->setVerticalSpacing(3);
    setLayout(gridLayout);
    // Создание и установка параметров невидимому виджету.
    hiddenWidget = new QWidget(this);
    hiddenWidget->setObjectName(QString("Hidden"));
    hiddenWidget->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    // Добавление кнопок в QGridLayout.
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
        button->connect(button, &QPushButton::clicked, this, &Board::SwapWidgets);
        gridLayout->addWidget(button, row, col);
        ++col;
        if (col == 4)
        {
            ++row;
            col = 0;
        }
    }
    gridLayout->addWidget(hiddenWidget);
}

bool Board::CheckEqualTextButton(const qint8& randomValue)
{
    auto tempButton = findChild<QPushButton*>(QString::number(randomValue));

    if (tempButton)
        return true;

    return false;
}

// Первый способ перемещения виджетов при нажатии
void Board::SwapWidgets()
{
    PuzzlePiece* buttonSender = qobject_cast<PuzzlePiece*>(sender());

    int indexButtonSender = gridLayout->indexOf(buttonSender);
    int rowSender, colSender, rowSpanSender, colSpanSender;
    gridLayout->getItemPosition(indexButtonSender, &rowSender, &colSender, &rowSpanSender, &colSpanSender);

    QVector<PositionStruct> positions = {PositionStruct(rowSender + 1, colSender), PositionStruct(rowSender - 1, colSender),
                                        PositionStruct(rowSender, colSender + 1), PositionStruct(rowSender, colSender - 1)};

    for (int i = 0; i < positions.size(); ++i)
    {
        auto tempItem = gridLayout->itemAtPosition(positions[i].row, positions[i].col);
        if (tempItem)
        {  
            auto tempNameWidget = tempItem->widget();
            if (tempNameWidget->objectName() == "Hidden")
                {
                    int indexHiddenWidget = gridLayout->indexOf(tempNameWidget);
                    gridLayout->takeAt(indexHiddenWidget);
                    gridLayout->takeAt(indexButtonSender);

                    gridLayout->addWidget(tempNameWidget, rowSender, colSender);
                    gridLayout->addWidget(buttonSender, positions[i].row, positions[i].col);
                }
        }
    }
}
