#ifndef _T_ARTIFICIL_INTELLEGENCE_HPP_
#define _T_ARTIFICIL_INTELLEGENCE_HPP_

#include <SFML/Graphics.hpp>
#include "Constants.hpp"

using namespace std;
using namespace sf;

namespace AI
{
   //! Класс AI
   class TArtificialIntellegence
   {
      public:
         //! Конструктор
         TArtificialIntellegence();

         //! Деструктор
         ~TArtificialIntellegence();

         //! Движение AI
         //! plFiguresSprite - спрайты фигур игрока
         //! aiFiguresSprite - спрайты фигур AI
         //! return - результат движения AI
         bool aiMove( Sprite* plFiguresSprite, Sprite* aiFiguresSprite );

         //! Получения индекса текущей фигуры AI
         //! return - индекс текущей фигуры AI
         int getCurrentFigureId();

      private:

         Vector2f newFigurePosition, oldFigurePosition;  //!< Новая и старая позиция фигуры
         bool isCanStand;                                //!< Флаг нахождения фигуры в новой позиции
         int currentFigureId;                            //!< Индекс текущей зайдействованой фигуры 
         Vector2f coordTable[boardSize][boardSize];      //!< Массив непосредственно координат поля
         bool endCondition;                              //!< Результат условия окончания цикла хода AI
         bool standCondition;                            //!< Результат условия проверки новой позиции
         bool firstBorderCondition;                      //!< Первое граничное условие
         bool secondBorderCondition;                     //!< Второе граничное условие

         //! Функция проверки следущей позиции
         //! plFiguresSprite - спрайты фигур игрока
         //! aiFiguresSprite - спрайты фигур AI
         //! figId - индекс текущей фигуры
         //! directionSign - знак направления движения
         //! return - результат проверки
         bool checkNextState( Sprite *plFiguresSprite, Sprite *aiFiguresSprite, int figId, int directionSign );
   };
};

#endif // !_T_ARTIFICIL_INTELLEGENT_HPP_