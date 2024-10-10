#pragma once

#include "QPushButton"
#include "QGridLayout"
#include "iostream"

class PuzzlePiece : public QPushButton
{
    Q_OBJECT

public:
    PuzzlePiece(const QString &text, QWidget* parent = nullptr);
    
    void SetSound(bool bIsWrong);
};