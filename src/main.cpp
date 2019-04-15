#include <mkapplication.h>
#include <vector>

MK::MKApplication* mk;

uint16_t GREY = 0x98959b;
float TBoilerOUT;
float TBoilerIN;
float TFloorOUT;
float TFloorIN;
float TBoilerOT;
float TGarageOUT;

void DrawMSTemp(String param,int line, int column, float temp, uint16_t color)
{
  
  M5.Lcd.drawRect((column-1)*160,(line-1)*75,160,75, GREY);

  M5.Lcd.setCursor(25+(column-1)*160,2+(line-1)*75);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print(param);
  M5.Lcd.setCursor(10+(column-1)*160,20+(line-1)*75);
  M5.Lcd.setTextColor(color);
  M5.Lcd.setTextSize(6);
  M5.Lcd.printf("%g",temp);
  
}

void DrawMainScreen(void)
{
  DrawMSTemp("Boiler OUT",1,1,TBoilerOUT,GREEN);
  DrawMSTemp("Floor IN",1,2,TFloorIN,RED);
  DrawMSTemp("Boiler IN",2,1,TBoilerIN,GREEN);
  DrawMSTemp("Floor OUT",2,2,TFloorOUT,BLUE);
  DrawMSTemp("Boiler Temp",3,1,TBoilerOT,BLUE);
  DrawMSTemp("Garage OUT",3,2,TGarageOUT,RED);
}

void GetTemp(void)
{
  TBoilerOUT = 20 + random(10);
  TBoilerIN = 20 + random(10) ;
  TFloorOUT =  20 + random(10);
  TFloorIN =  20 + random(10);
  TBoilerOT=  20 + random(10);
  TGarageOUT=  20 + random(10);
  
}


int CC = 35;
int DD = 2;
class ScreenSetFloorTemp: MK::MKScreen
{
  public:
  ScreenSetFloorTemp()
  {
    ABtnAction = ACTION_NEXT_SCREEN;
    BBtnAction = ACTION_DOWN;
    CBtnAction = ACTION_UP;
    mk->AddScreen((MK::MKScreen*)this);
  
  }

  void Draw() override
  {
    M5.Lcd.clearDisplay();
    M5.Lcd.setCursor(20,20);
    M5.Lcd.setTextSize(3);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.print("Set floor temp C");
    M5.Lcd.setCursor(70,100);
    M5.Lcd.setTextSize(8);
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.print(String(CC));
    

    DrawButtons();
  }
  void OnButtonAPressed()  override
  {
    app->NextScreen();
    app->ActiveScreen->Draw();
  }

  void OnButtonBPressed()  override
  {
    CC--;
    Draw();
  }
  void OnButtonCPressed()  override
  {
    CC++;
    Draw();
  }

};

class ScreenSetFloorDelta: MK::MKScreen
{
  public:
  ScreenSetFloorDelta()
  {
    ABtnAction = ACTION_NEXT_SCREEN;
    BBtnAction = ACTION_DOWN;
    CBtnAction = ACTION_UP;
    mk->AddScreen((MK::MKScreen*)this);
  }

  void Draw() override
  {
    M5.Lcd.clearDisplay();
    M5.Lcd.setCursor(20,20);
    M5.Lcd.setTextSize(3);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.print("Set floor delta");
    M5.Lcd.setCursor(70,100);
    M5.Lcd.setTextSize(8);
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.print(String(DD));
    

    DrawButtons();
  }
  void OnButtonAPressed()  override
  {
    app->NextScreen();
    app->ActiveScreen->Draw();
  }

  void OnButtonBPressed()  override
  {
    DD--;
    Draw();
  }


void OnButtonCPressed()  override
  {
    DD++;
    Draw();
  }

};

class Screen1: MK::MKScreen
{
  public:
  Screen1()
  {
    ABtnAction = ACTION_NEXT_SCREEN;
    mk->AddScreen((MK::MKScreen*)this);

  }

  void Draw() override
  {
    M5.Lcd.clearDisplay();
    GetTemp();
    DrawMainScreen();
    DrawButtons();
  }

  void OnButtonAPressed()  override
  {
    app->NextScreen();
    app->ActiveScreen->Draw();
  }

};



Screen1* scr1;
ScreenSetFloorTemp* screenSetFloorTemp;
ScreenSetFloorDelta* screenSetFloorDelta; 





void setup(void) 
{
  M5.begin();
  mk = new MK::MKApplication();
  scr1 = new Screen1();
  screenSetFloorTemp = new ScreenSetFloorTemp();
  screenSetFloorDelta = new ScreenSetFloorDelta();
  
  //mk->AddScreen((MK::MKScreen*)screenSetFloorTemp);
  //mk->AddScreen((MK::MKScreen*)screenSetFloorDelta);
  mk->ActiveScreen = (MK::MKScreen*)scr1;
  mk->ActiveScreen->Draw();
  

}



void loop()
{
  M5.update();
  if (M5.BtnA.wasPressed())
  {
    mk->OnButtonAPressed();
    
  }

  if (M5.BtnB.wasPressed())
  {
    mk->OnButtonBPressed();
    
  }

  if (M5.BtnC.wasPressed())
  {
    mk->OnButtonCPressed();
    
  }


  delay(100);

}


