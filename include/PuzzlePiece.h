#pragma once

#include "QPushButton"

class PuzzlePiece : public QPushButton
{
public:
    PuzzlePiece(const QString &text, QWidget* parent = nullptr);
};