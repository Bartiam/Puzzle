#pragma once

//
#include "QMainWindow"
#include "QGridLayout"
#include "PuzzlePiece.h"
#include "QRandomGenerator"
#include "deque"

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget* parent = nullptr);

private:
    // Private variables
    const qint8 countOfButtons = 15;
    QGridLayout* gridLayout;
    std::deque<PuzzlePiece*> buttons;

    // Private functions
    void AddButtonsToWidget();
    bool CheckButtonText(const qint8 randomValue);
};