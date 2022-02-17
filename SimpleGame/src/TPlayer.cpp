#include "../include/TPlayer.hpp"

namespace Player
{
   TPlayer::TPlayer()
   {
      isMove = false;
      isCanStand = false;
      positionDeltaX = 0, positionDeltaY = 0;
      currentFigureId = 0;
   };

   TPlayer::~TPlayer()
   {
   };

   bool TPlayer::playerMove( Event currentEvent, Sprite *&plFiguresSprite, Sprite *&aiFiguresSprite, Vector2i mousePosition )
   {
      if ( currentEvent.type == Event::MouseButtonPressed && currentEvent.key.code == Mouse::Left )
         for ( int i = 0; i < numbersOfFigures; ++i )
            if ( plFiguresSprite[i].getGlobalBounds().contains( mousePosition.x, mousePosition.y ) )
            {
               isMove = true;
               currentFigureId = i;
               positionDeltaX = mousePosition.x - plFiguresSprite[i].getPosition().x;
               positionDeltaY = mousePosition.y - plFiguresSprite[i].getPosition().y;
               oldFigurePosition = plFiguresSprite[i].getPosition();
               break;
            }

      if ( currentEvent.type == Event::MouseButtonReleased && currentEvent.key.code == Mouse::Left )
         for ( int i = 0; i < numbersOfFigures; ++i )
         {
            if ( plFiguresSprite[i].getGlobalBounds().contains( mousePosition.x, mousePosition.y ) )
            {
               isMove = false;
               newFigurePosition = Vector2f( figureSizeInPixels * int( mousePosition.x / figureSizeInPixels ), figureSizeInPixels * int( mousePosition.y / figureSizeInPixels ) );

               if ( abs( newFigurePosition.x - oldFigurePosition.x ) > figureSizeInPixels )
                  if ( newFigurePosition.x - oldFigurePosition.x > 0 )
                     newFigurePosition.x = oldFigurePosition.x + figureSizeInPixels;
                  else
                     newFigurePosition.x = oldFigurePosition.x - figureSizeInPixels;

               if ( abs( newFigurePosition.y - oldFigurePosition.y ) > figureSizeInPixels )
                  if ( newFigurePosition.y - oldFigurePosition.y > 0 )
                     newFigurePosition.y = oldFigurePosition.y + figureSizeInPixels;
                  else
                     newFigurePosition.y = oldFigurePosition.y - figureSizeInPixels;

               for ( int j = 0; j < numbersOfFigures; ++j )
                  if ( j != currentFigureId )
                     if (  plFiguresSprite[j].getGlobalBounds().contains( newFigurePosition ) || aiFiguresSprite[j].getGlobalBounds().contains( newFigurePosition ) )
                     {
                        isCanStand = false;
                        break;
                     }
                     else
                        isCanStand = true;

               if ( isCanStand && ( newFigurePosition != oldFigurePosition ) )
               {
                  plFiguresSprite[currentFigureId].setPosition( newFigurePosition );

                  return true;
               }
               else
               {
                  plFiguresSprite[currentFigureId].setPosition( oldFigurePosition );

                  return false;
               }
            }
         }

      dragDropAnimation( plFiguresSprite, mousePosition );

      return false;
   };

   void TPlayer::dragDropAnimation( Sprite *figuresSprite, Vector2i mousePosition )
   {
      if ( isMove )
         figuresSprite[currentFigureId].setPosition( mousePosition.x - positionDeltaX, mousePosition.y - positionDeltaY );
   };

   int TPlayer::getCurrentFigureId()
   {
      return currentFigureId;
   };
};