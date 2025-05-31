#include "App.hpp"
#include "front/Frontend.hpp"
#include "player/RawPlayer/RawPlayer.hpp"
#include "utils/EventSystem.hpp"
App::App(){ /* Do nothing */ }
App::~App(){ /* Do nothing */ }

bool App::Init()
{
    bool result;
    player = new RawPlayer(); // Initialize the audio player
    if (!player)
    {
        return false; // Failed to create player
    }
    EventSystem::RegisterEventHandler(EventType::Quit, [this]() { Exit(); });
    result = backend.Init();
    return result;
}

bool App::Run()
{
    while(backend.PreLoop() && !exit)
    {
        frontend.Render();
        EventSystem::ProcessEvents();
        if(!backend.PostLoop())
        {
            break;
        }
    }
    return Shutdown();
}

bool App::Shutdown()
{
    return backend.Shutdown();
}

void App::Exit()
{
    exit = true;
}