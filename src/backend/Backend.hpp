#ifndef BACKEND_HPP
#define BACKEND_HPP


#include <d3d11.h>
#include <tchar.h>

class Backend
{
public:
    Backend();
    ~Backend();
    bool Init();
    bool Render();
    void Shutdown();
    
    static UINT g_ResizeWidth, g_ResizeHeight;
private:
    WNDCLASSEXW wc;
    HWND hwnd;
    
    ID3D11Device* g_pd3dDevice = nullptr;
    ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
    IDXGISwapChain* g_pSwapChain = nullptr;
    bool g_SwapChainOccluded = false;
    ID3D11RenderTargetView* g_mainRenderTargetView = nullptr;

    bool CreateDeviceD3D(HWND hWnd);
    void CleanupDeviceD3D();
    void CreateRenderTarget();
    void CleanupRenderTarget();
};

#endif