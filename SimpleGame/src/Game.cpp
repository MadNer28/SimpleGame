#include <SFML/Graphics.hpp>
#include "../include/TGameProcedures.hpp"
#include "../include/TPlayer.hpp"
#include "../include/TArtificialIntelligence.hpp"

using namespace std;
using namespace sf;

int main()
{
   RenderWindow window( VideoMode( 504, 504 ), "The Simple Game!", Style::Titlebar | Style::Close );
   GameProc::TGameProcedures gameProc;
   Player::TPlayer player;
   AI::TArtificialIntellegence ai;

   gameProc.setupFiguresPositionOnBoard();

   Sprite *playerFiguresSprite = gameProc.getPlayerFigureSprites();
   Sprite *aiFiguresSprite = gameProc.getAiFigureSprites();
   Sprite sBoard = gameProc.getBoardSprite();
   bool queueFalg = true;

   Event currentEvent;
   Vector2i mousePosition;

   while ( window.isOpen() )
   {
      mousePosition = Mouse::getPosition( window ) - Vector2i( boardPositionOffset );

      while ( window.pollEvent( currentEvent ) )
      {
         if ( currentEvent.type == Event::Closed )
            window.close();

         queueFalg = player.playerMove( currentEvent, playerFiguresSprite, aiFiguresSprite, mousePosition );
         
         if ( queueFalg )
            queueFalg = ai.aiMove( playerFiguresSprite, aiFiguresSprite );
      }

      window.clear();
      window.draw( sBoard );

      for ( int i = 0; i < numbersOfFigures; i++ )
      {
         playerFiguresSprite[i].move( boardPositionOffset );
         aiFiguresSprite[i].move( boardPositionOffset );
      }
         

      for ( int i = 0; i < numbersOfFigures; i++ )
      {
         window.draw( playerFiguresSprite[i] );
         window.draw( aiFiguresSprite[i] );
      }

      for ( int i = 0; i < numbersOfFigures; i++ )
      {
         playerFiguresSprite[i].move( -boardPositionOffset );
         aiFiguresSprite[i].move( -boardPositionOffset );
      }
      window.display();
   }

   return 0;
};
