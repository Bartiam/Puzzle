#include "Board.h"

// Реализация конструктора класса.
Board::Board(QWidget *parent) : QWidget::QWidget(parent)
{
    // Создание и установка параметров для QGridLayout.
    gridLayout = new QGridLayout;
    gridLayout->setHorizontalSpacing(3);
    gridLayout->setVerticalSpacing(3);
    setLayout(gridLayout);
    // Создание и установка параметров невидимому виджету.
    hiddenWidget = new QWidget(this);
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
        // Получение рандомного значения.
        qint8 randomValue = QRandomGenerator::global()->generate() % countOfButtons + 1;
        // Проверка на совпадение текста новой кнопки и уже существующей.
        if (CheckEqualTextButton(randomValue))
        {
            --index;
            continue;
        }

        if (randomValue == countOfButtons)
        {
            gridLayout->addWidget(hiddenWidget, row, col);
            hiddenWidget->setObjectName(QString::number(randomValue));
        }
        else
        {
            // Установка рандомного значения как текст кнопки.
            PuzzlePiece* button = new PuzzlePiece(QString::number(randomValue));
            // Установка имени объекту.
            button->setObjectName(QString::number(randomValue));
            // Установка родительского виджета для кнопки.
            button->setParent(this);
            // Соединение сигнала clicked с методом класса Board::SwapWidgets.
            button->connect(button, &QPushButton::clicked, this, &Board::SwapWidgets);
            // Добавление виджета к gridLayout.
            gridLayout->addWidget(button, row, col);
        }
        // Изменение значений row и col для правильного расположения кнопок.
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
    auto tempButton = findChild<QWidget*>(QString::number(randomValue));

    if (tempButton)
        return true;

    return false;
}

// Перемещение виджетов.
void Board::SwapWidgets()
{
    // Каст кнопки которая издала сигнал clicked.
    auto buttonSender = qobject_cast<PuzzlePiece*>(sender());
    // Получение индекса buttonSender.
    int indexButtonSender = gridLayout->indexOf(buttonSender);
    // Переменные для нахождения row и col у buttonSender.
    int rowSender, colSender, rowSpanSender, colSpanSender;
    // Получение позиции buttonSender
    gridLayout->getItemPosition(indexButtonSender, &rowSender, &colSender, &rowSpanSender, &colSpanSender);
    // Создание вектора PositionStruct.
    QVector<PositionStruct> positions = {PositionStruct(rowSender + 1, colSender), PositionStruct(rowSender - 1, colSender),
                                        PositionStruct(rowSender, colSender + 1), PositionStruct(rowSender, colSender - 1)};

    for (int i = 0; i < positions.size(); ++i)
    {
        // Получение QLayoutItem по указанной позиции.
        auto tempItem = gridLayout->itemAtPosition(positions[i].row, positions[i].col);
        // Проверка, что tempItem != nullptr.
        if (tempItem)
        {
            // Если tempItem != nullptr, то получаем из него QWidget.
            auto tempNameWidget = tempItem->widget();
            // Проверка на то, что имя этого виджета == "пустой" ячейке.
            if (tempNameWidget->objectName() == "16")
            {
                // Если имя виджета == "Hidden" то меняем местами нажатую кнопку и "невидимый" виджет.
                int indexHiddenWidget = gridLayout->indexOf(tempNameWidget);
                gridLayout->takeAt(indexHiddenWidget);
                gridLayout->takeAt(indexButtonSender);

                gridLayout->addWidget(tempNameWidget, rowSender, colSender);
                gridLayout->addWidget(buttonSender, positions[i].row, positions[i].col);
                break;
             }
        }
    }
}
///////////////////////////////////////////////////////