#include "App.hpp"

int main(int, char**)
{
    App app;
    if (!app.Init())
    {
        app.Shutdown();
        return 1;
    }
    (void)app.Run();
    
    return 0;
}

