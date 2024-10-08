#include "PuzzlePiece.h"

PuzzlePiece::PuzzlePiece(const QString &text, QWidget *parent)
 : QPushButton::QPushButton(text, parent)
{
    QFont font(QString("Bahnschrift SemiLight Condensed"), 24);
    setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    setStyleSheet(QString("background-color: gray; color: blue;"));
    setFont(font);
}
