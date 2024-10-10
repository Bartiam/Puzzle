#include "PuzzlePiece.h"
// Реализация конструктора класса.
PuzzlePiece::PuzzlePiece(const QString &text, QWidget *parent)
 : QPushButton::QPushButton(text, parent)
{
    // Создание шрифта и уставнока его размера.
    QFont font(QString("Bahnschrift SemiLight Condensed"), 24);
    // Устанавливаем настройки размера как Expanding.
    setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    // Устанавливаем цвет заднего фона и цвет текста кнопки.
    setStyleSheet(QString("background-color: gray; color: blue;"));
    // Устанавливаем шрифт.
    setFont(font);
}

void PuzzlePiece::SetSound(bool bIsWrong)
{
    std::cout << "Result: " << bIsWrong << std::endl;
}
