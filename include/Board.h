#pragma once

//
#include "QMainWindow"
#include "QGridLayout"
#include "PuzzlePiece.h"
#include "QRandomGenerator"
#include "deque"
#include "iostream"

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget* parent = nullptr);

private:
    // Private variables
    const qint8 countOfButtons = 15;
    QGridLayout* gridLayout;

    // Private functions
    void AddButtonsToWidget();
    bool CheckEqualTextButton(const qint8& randomValue);
};