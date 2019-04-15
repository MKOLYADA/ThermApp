#include <mkscreen.h>
#include <vector>

namespace MK
{
    class MKApplication
    {
        public:
            MKApplication()
            {
                Screens = {};
            };
        
        std::vector<MKScreen*> Screens;

        MKScreen* ActiveScreen = nullptr;    

        void AddScreen(MKScreen* scr)
        {
            Screens.push_back(scr);
            scr->app = this;
            
        }


        void NextScreen()
        {
           if (ActiveScreen == nullptr) return;
           bool found = false;
           for (MKScreen* s : Screens)
           {
               if (found)
               {
                   ActiveScreen=s;
                   return;
               }
               if (s==ActiveScreen) found = true;
               
           }
           if (found) ActiveScreen=Screens.at(0);
        }

        void OnButtonAPressed()
        {
            ActiveScreen->OnButtonAPressed();    
        }

        void OnButtonBPressed()
        {
            ActiveScreen->OnButtonBPressed();    
        }
        void OnButtonCPressed()
        
        {
            ActiveScreen->OnButtonCPressed();    
        }
        



    };
    
}