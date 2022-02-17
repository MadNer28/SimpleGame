#include "../include/TArtificialIntelligence.hpp"

namespace AI
{
   TArtificialIntellegence::TArtificialIntellegence()
   {
      oldFigurePosition = Vector2f( 0, 0 );
      newFigurePosition = Vector2f( 0, 0 );;
      isCanStand = false;
      currentFigureId = -1;

      endCondition = false;
      standCondition = false;
      firstBorderCondition = false;
      secondBorderCondition = false;

      for ( int i = 0; i < boardSize; ++i )
         for ( int j = 0; j < boardSize; ++j )
         {
            coordTable[i][j].x = j * figureSizeInPixels;
            coordTable[i][j].y = i * figureSizeInPixels;
         }
   };

   TArtificialIntellegence::~TArtificialIntellegence()
   {
   };

   bool TArtificialIntellegence::aiMove( Sprite *plFiguresSprite, Sprite *aiFiguresSprite )
   {
      endCondition = true;
      double minDistance = 555.0, minDistanceCalc = 0.0;
      int minDistanceXId = -1, minDistanceYId = -1;

      for ( int i = 0; i < numbersOfFigures; ++i )
      {
         for ( int j = 0; j < numbersOfFigures; ++j )
            if ( aiFiguresSprite[j].getPosition() != coordTable[aiTargetTable.at( j ).first][aiTargetTable.at( j ).second] )
            {
               minDistanceCalc = sqrt( pow( ( coordTable[aiTargetTable.at( j ).first][aiTargetTable.at( j ).second].x - aiFiguresSprite[j].getPosition().x ), 2 ) +
                                       pow( ( coordTable[aiTargetTable.at( j ).first][aiTargetTable.at( j ).second].y - aiFiguresSprite[j].getPosition().y ), 2 ) );

               if ( minDistanceCalc < minDistance )
               {
                  minDistance = minDistanceCalc;
                  currentFigureId = j;
               }
            }

         oldFigurePosition = aiFiguresSprite[currentFigureId].getPosition();

         if ( aiFiguresSprite[currentFigureId].getPosition() != coordTable[aiTargetTable.at( currentFigureId ).first][aiTargetTable.at( currentFigureId ).second] )
         {
            standCondition = checkNextState( plFiguresSprite, aiFiguresSprite, currentFigureId, figureSizeInPixels );

            if ( !standCondition )
               standCondition = checkNextState( plFiguresSprite, aiFiguresSprite, currentFigureId, -figureSizeInPixels );
         }

         firstBorderCondition = ( newFigurePosition.x + figureSizeInPixels > boardSize * figureSizeInPixels ) || ( newFigurePosition.y + figureSizeInPixels > boardSize * figureSizeInPixels );
         secondBorderCondition = ( newFigurePosition.x < 0 ) || ( newFigurePosition.y < 0 );

         if ( standCondition )
         {
            if ( firstBorderCondition )
               isCanStand = false;
            else if ( secondBorderCondition )
               isCanStand = false;
            else
               isCanStand = true;
         }
         else
            isCanStand = false;

         if ( isCanStand )
         {
            aiFiguresSprite[currentFigureId].setPosition( newFigurePosition );

            return false;
         }
         else
         {
            aiFiguresSprite[currentFigureId].setPosition( oldFigurePosition );
            endCondition = false;
         }
      }

      return false;
   };

   int TArtificialIntellegence::getCurrentFigureId()
   {
      return currentFigureId;
   };

   bool TArtificialIntellegence::checkNextState( Sprite *plFiguresSprite, Sprite *aiFiguresSprite, int figId, int directionSign )
   {
      bool localCondition = false;
      float distanceX = abs( aiFiguresSprite[figId].getPosition().x - coordTable[aiTargetTable.at( figId ).first][aiTargetTable.at( figId ).second].x );
      float distanceY = abs( aiFiguresSprite[figId].getPosition().y - coordTable[aiTargetTable.at( figId ).first][aiTargetTable.at( figId ).second].y );

      if ( distanceX > distanceY )
         newFigurePosition = Vector2f( aiFiguresSprite[figId].getPosition().x + directionSign, aiFiguresSprite[figId].getPosition().y );
      else
         newFigurePosition = Vector2f( aiFiguresSprite[figId].getPosition().x, aiFiguresSprite[figId].getPosition().y + directionSign );

      for ( int j = 0; j < numbersOfFigures; ++j )
         if ( aiFiguresSprite[j].getGlobalBounds().contains( newFigurePosition ) || plFiguresSprite[j].getGlobalBounds().contains( newFigurePosition ) )
            return false;

      return true;
   };
};

