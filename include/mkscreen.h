#pragma once

#include <M5Stack.h>
#include <vector>

enum Actions  {ACTION_NONE,ACTION_NEXT_SCREEN,ACTION_UP,ACTION_DOWN,ACTION_OK};
namespace MK
{
    class MKApplication;

    class MKScreen
    {
        public:
            MKScreen()
            {

            };
            Actions ABtnAction = ACTION_NONE;
            Actions BBtnAction = ACTION_NONE;
            Actions CBtnAction = ACTION_NONE;
            
            virtual void Draw();
            virtual void OnButtonAPressed() {};
            virtual void OnButtonBPressed() {};
            virtual void OnButtonCPressed() {};
            MKApplication* app;

            virtual void DrawButtons()
            {
                switch(ABtnAction)
                {
                    case ACTION_NONE:
                        break;
                    default:
                        DrawButton(0,ABtnAction);    
                        break;
                    
                }
                switch(BBtnAction)
                {
                    case ACTION_NONE:
                        break;
                    default:
                        DrawButton(1,BBtnAction);    
                        break;
                    
                }
                switch(CBtnAction)
                {
                    case ACTION_NONE:
                        break;
                    default:
                        DrawButton(2,CBtnAction);    
                        break;
                    
                }
            };
            
            virtual void DrawButton(int number, Actions action)
            {
                int width = 100;
                int height = 12;
                int x = (M5.Lcd.width()/3-width)/2+M5.Lcd.width()/3*number;
                int y = M5.Lcd.height() - 1 - height;
                switch(action)
                {
                    case ACTION_NEXT_SCREEN:
                        M5.Lcd.fillRoundRect(x,y,width,height,3, WHITE);
                        M5.Lcd.setCursor(x+15,y+2);
                        M5.Lcd.setTextSize(1);
                        M5.Lcd.setTextColor(BLACK);
                        
                        M5.Lcd.print("NEXT SCREEN");


                        break;
                    case ACTION_UP:
                        M5.Lcd.fillRoundRect(x,y,width,height,3, WHITE);
                        M5.Lcd.setCursor(x+15,y+2);
                        M5.Lcd.setTextSize(1);
                        M5.Lcd.setTextColor(BLACK);
                        
                        M5.Lcd.print("< UP >");


                        break;
                    case ACTION_DOWN:
                        M5.Lcd.fillRoundRect(x,y,width,height,3, WHITE);
                        M5.Lcd.setCursor(x+15,y+2);
                        M5.Lcd.setTextSize(1);
                        M5.Lcd.setTextColor(RED);
                        
                        M5.Lcd.print("<DOWN>");


                        break;
                    default:
                        break;
                } 
            };





    };

  }