#include <mkapplication.h>
#include <vector>

class Screen1: MK::MKScreen
{
  public:
  void Draw() override
  {
    M5.Lcd.clearDisplay();
    M5.Lcd.setCursor(50,50);
    M5.Lcd.setTextSize(4);
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.print("SCREEN 1");
  }
  void OnButtonAPressed()  override
  {
    app->NextScreen();
    app->ActiveScreen->Draw();
  }
};

class Screen2: MK::MKScreen
{
  public:
  void Draw() override
  {
    M5.Lcd.clearDisplay();
    M5.Lcd.setCursor(50,50);
    M5.Lcd.setTextSize(4);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.print("SCREEN 2");
  }

  void OnButtonCPressed()  override
  {
    app->NextScreen();
    app->ActiveScreen->Draw();
  }

};

class Screen3: MK::MKScreen
{
  public:
  void Draw() override
  {
    M5.Lcd.clearDisplay();
    M5.Lcd.setCursor(50,50);
    M5.Lcd.setTextSize(4);
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.print("SCREEN 3");
  }

  void OnButtonBPressed()  override
  {
    app->NextScreen();
    app->ActiveScreen->Draw();
  }
};


class Screen99: MK::MKScreen
{
  public:
  void Draw() override
  {
    M5.Lcd.clearDisplay();
    M5.Lcd.setCursor(50,50);
    M5.Lcd.setTextSize(4);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.print("SCREEN 99");
  }

  void OnButtonAPressed()  override
  {
    app->NextScreen();
    app->ActiveScreen->Draw();
  }
  void OnButtonBPressed()  override
  {
    M5.Lcd.drawRect(20,20,100,100,RED);
  }
  void OnButtonCPressed()  override
  {
    app->NextScreen();
    app->ActiveScreen->Draw();
  }
};


Screen1* scr1;
Screen2* scr2;
Screen3* scr3;
Screen99* scr99;
MK::MKApplication* mk;

void setup(void) {
  M5.begin();
  mk = new MK::MKApplication();
  scr1 = new Screen1();
  scr2 = new Screen2();
  scr3 = new Screen3();
  scr99 = new Screen99();
  
  mk->AddScreen((MK::MKScreen*)scr99);
  mk->AddScreen((MK::MKScreen*)scr1);
  mk->AddScreen((MK::MKScreen*)scr2);
  mk->AddScreen((MK::MKScreen*)scr3);
  mk->ActiveScreen = (MK::MKScreen*)scr99;
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


  delay(500);

}


