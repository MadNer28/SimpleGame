#ifndef _T_GAME_PROCEDURES_HPP
#define _T_GAME_PROCEDURES_HPP

#include <SFML/Graphics.hpp>
#include "Constants.hpp"

using namespace std;
using namespace sf;

namespace GameProc
{
	//! Класс процедур игры
	class TGameProcedures
	{
		public:

			//! Конструктор
			TGameProcedures(); 
			
			//! Деструктор
			~TGameProcedures();

			//! Функция установки фигур на доске
			void setupFiguresPositionOnBoard();

			//! Функция получения доступа к спрайтам фигур игрока
			//! return - указатель на первый элемент в массиве спрайтов игрока
			Sprite* getPlayerFigureSprites();

			//! Функция получения доступа к спрайтам фигур AI
			//! return - указатель на первый элемент в массиве спрайтов AI
			Sprite* getAiFigureSprites();

			//! Функция получения доступа к спрайту игрового поля
			//! return - спрайт игрового поля
			Sprite getBoardSprite();

		private:

			Texture figureTextures;									//!< Текстуры фигур
			Texture boardTextures;									//!< Текстура доски
			Sprite playerFiguresSprite[numbersOfFigures];	//!< Массив спрайтов фигур игрока
			Sprite aiFiguresSprite[numbersOfFigures];			//!< Массив спрайтов фигур AI
			Sprite gameBoard;											//!< Спрайт игровой доски
	};
};

#endif // !_T_GAME_PROCEDURES_HPP