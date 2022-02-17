#include "../include/TGameProcedures.hpp"

namespace GameProc
{
	TGameProcedures::TGameProcedures()
	{
      figureTextures.loadFromFile( "../Textures/figures.png" );
      boardTextures.loadFromFile( "../Textures/board.png" );

      for ( int i = 0; i < numbersOfFigures; ++i )
      {
         playerFiguresSprite[i].setTexture( figureTextures );
         aiFiguresSprite[i].setTexture( figureTextures );
      }

      gameBoard.setTexture( boardTextures );
	};

	TGameProcedures::~TGameProcedures()
	{
	};

	void TGameProcedures::setupFiguresPositionOnBoard()
	{
      int k = 0, l = 0, i = 0, j = 0;
      int boardPos = 0, pawnPosInColunmTextures = 0;
      const int pawnPosInRowTextures = 5;

      for ( i = 0; i < boardSize; ++i )
         for ( j = 0; j < boardSize; ++j )
         {
            boardPos = setupBoard[i][j];

            if ( boardPos == 0 )
               continue;
               
            pawnPosInColunmTextures = boardPos > 0 ? 1 : 0;

            if ( pawnPosInColunmTextures )
            {
               playerFiguresSprite[k].setTextureRect( IntRect( figureSizeInPixels * pawnPosInRowTextures, figureSizeInPixels * pawnPosInColunmTextures, figureSizeInPixels, figureSizeInPixels ) );
               playerFiguresSprite[k].setPosition( figureSizeInPixels * i, figureSizeInPixels * j );
               ++k;
            }
            else if ( !pawnPosInColunmTextures )
            {
               aiFiguresSprite[l].setTextureRect( IntRect( figureSizeInPixels * pawnPosInRowTextures, figureSizeInPixels * pawnPosInColunmTextures, figureSizeInPixels, figureSizeInPixels ) );
               aiFiguresSprite[l].setPosition( figureSizeInPixels * i, figureSizeInPixels * j );
               ++l;
            }
         }
	};

   Sprite* TGameProcedures::getPlayerFigureSprites()
   {
      return &playerFiguresSprite[0];
   };

   Sprite *TGameProcedures::getAiFigureSprites()
   {
      return &aiFiguresSprite[0];
   };

   Sprite TGameProcedures::getBoardSprite()
   {
      return gameBoard;
   };
};