#include <M5Stack.h>


namespace MK
{
    class MKApplication;
    class MKScreen
    {
        public:
            MKScreen()
            {

            };
            virtual void Draw();
            virtual void OnButtonAPressed() {};
            virtual void OnButtonBPressed() {};
            virtual void OnButtonCPressed() {};
            MKApplication* app;
    };
}