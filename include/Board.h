#pragma once

//
#include "QMainWindow"
#include "PuzzlePiece.h"
#include "QRandomGenerator"

// Структура для работы метода перемещения виджетов.
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
    const qint8 countOfButtons = 16;
    QGridLayout* gridLayout;
    QWidget* hiddenWidget;

    void AddButtonsToWidget();
    bool CheckEqualTextButton(const qint8& randomValue);
private slots:
    // Перемещение виджетов.
    void SwapWidgets();
};