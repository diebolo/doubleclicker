#define _WIN32_WINNT 0x500
#include <iostream>
#include <windows.h>

using namespace std;
// String creation
int choice(0);
int sleepingTime(0);

void mouseLeftClick ()
{
     INPUT Input = {0};
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
     ::SendInput(1,&Input,sizeof(INPUT));
     ::ZeroMemory(&Input,sizeof(INPUT));
     Input.type = INPUT_MOUSE;
     Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
     ::SendInput(1,&Input,sizeof(INPUT));
}

int main()
{
    //Boot menu
    SetConsoleTitle( "DOUBLE CLICKER v0.1" );
    cout << "\n\n       AUTO DOUBLE CLICKER\n";
    bool gameOn = true;
    while (gameOn != false){
        cout << endl
        << " 1 - Activate script.\n"
        << " 2 - Exit Program.\n"
        << " Enter your choice and press Enter: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << endl
                << "Script active\n";
                while(true){
					//Virtual Key i'm trying to make a selection menu for
                    if(GetKeyState(VK_MENU) & 0x8000){
                        if(GetKeyState(VK_LBUTTON) & 0x8000)
                                {
                                sleepingTime = rand() % 10 + 25;
                                Sleep(sleepingTime);
                                mouseLeftClick();
                                }
                            }
                        }
                    return 0;
                break;
            case 2:
                cout << "End of program.\n";
                gameOn = false;
                break;
            default:
                //fall back
                cout << "Invalid number... please try again:" << endl;
                cin >> choice;
                break;
        }
    }
}
