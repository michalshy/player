#ifndef APP_HPP
#define APP_HPP

#include "back/Backend.hpp"
#include "front/Frontend.hpp"
#include "player/IPlayer.hpp"
class App
{
public:
    App();
    ~App();
    bool Init();
    bool Run();
    bool Shutdown();
    void Exit();
private:
    IPlayer* player = nullptr; // Pointer to the audio player

    Backend backend;
    Frontend frontend;

    bool exit = false;

    void Render();
};

#endif