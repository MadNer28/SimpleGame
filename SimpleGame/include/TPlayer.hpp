#ifndef _T_PLAYER_HPP_
#define _T_PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include "Constants.hpp"

using namespace std;
using namespace sf;

namespace Player
{
   //! Класс игрока
   class TPlayer
   {
      public:

         //! Конструктор
         TPlayer();
         
         //! Деструктор
         ~TPlayer();

         //! Движение игрока
         //! currentEvent - текущее игровое событие
         //! plFiguresSprite - спрайты фигур игрока
         //! aiFiguresSprite - спрайты фигур AI
         //! mousePosition - позиция курсора мыши на доске
         //! return - результат движения игрока
         bool playerMove( Event currentEvent, Sprite*& plFiguresSprite, Sprite*& aiFiguresSprite, Vector2i mousePosition );

         //! Анимация перетаскивания фигур
         //! plFiguresSprite - спрайты фигур игрока
         //! mousePosition - позиция курсора мыши на доске
         void dragDropAnimation( Sprite* figuresSprite, Vector2i mousePosition );

         //! Функция получения текущего идентификатра фигуры игрока
         //! return - индекс текущей фигуры игрока
         int getCurrentFigureId();

      private:

         bool isMove;                                    //!< Флаг движения фигуры за курсором мыши
         bool isCanStand;                                //!< Флаг нахождения фигуры в новой позиции
         float positionDeltaX, positionDeltaY;           //!< Значение изменения положения фигуры при перетаскивании
         Vector2f newFigurePosition, oldFigurePosition;  //!< Новая и старая позиция фигуры
         int currentFigureId;                            //!< Индекс текущей зайдействованой фигуры 
   };


};

#endif // !_T_PLAYER_HPP_