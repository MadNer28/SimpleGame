#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_

#include <SFML/System/Vector2.hpp>
#include <map>

using namespace std;
using namespace sf;

const int figureSizeInPixels = 56;              //!< Размер спрайта фигруы в пикселях
const int numbersOfFigures = 9;                 //!< Общее количество фигур
const Vector2f boardPositionOffset( 28, 28 );   //!< Сдвиг в пикселях

const int boardSize = 8;   //!< Размер игрового поля

//! Массив игрового поля для расстановки фигур
const int setupBoard[boardSize][boardSize] =
{ -1, -1, -1, 0, 0, 0, 0, 0,
  -1, -1, -1, 0, 0, 0, 0, 0,
  -1, -1, -1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 1, 1,
  0, 0, 0, 0, 0, 1, 1, 1,
  0, 0, 0, 0, 0, 1, 1, 1 };

//! Таблица соответствия индексов фигур AI и координат целевых клеток
const map<int, pair<int, int>> aiTargetTable =
{ {0, {7, 7}}, {1, {7, 6}}, {2, {7, 5}}, 
  {3, {6, 7}}, {4, {6, 6}}, {5, {6, 5}}, 
  {6, {5, 7}}, {7, {5, 6}}, {8, {5, 5}} };

#endif // !_CONSTANTS_HPP_