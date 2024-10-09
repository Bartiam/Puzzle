#pragma once

//
#include "QMainWindow"
#include "PuzzlePiece.h"
#include "QRandomGenerator"

struct PositionStruct
{
public:
    PositionStruct(const int& row, const int& col)
    {
        this->row = row;
        this->col = col;
    }
    int row;
    int col;
};

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget* parent = nullptr);

private:
    // Приватные переменные
    const qint8 countOfButtons = 15;
    QGridLayout* gridLayout;
    QWidget* hiddenWidget;

    // Приватные функции
    void AddButtonsToWidget();
    bool CheckEqualTextButton(const qint8& randomValue);
private slots:
    // Первый способ перемещения виджетов при нажатии
    void SwapWidgets();
};