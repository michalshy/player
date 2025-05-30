#include "backend/Backend.hpp"

int main(int, char**)
{
    
    Backend backend;
    if (!backend.Init())
    {
        backend.Shutdown();
        return 1;
    }
    while (backend.Render())
    {
        continue;
    }
    return 0;
}

