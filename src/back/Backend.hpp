#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <d3d11.h>
#include <tchar.h>

class Backend
{
public:
    Backend();

    bool Init();
    bool PreLoop();
    bool PostLoop();
    bool Shutdown();
    
    ~Backend() = default;
    
private:
    WNDCLASSEXW wc;
    HWND hwnd;
    ID3D11Device* pd3dDevice;
    ID3D11DeviceContext* pd3dDeviceContext;
    IDXGISwapChain* pSwapChain;
    bool swapChainOccluded;
    ID3D11RenderTargetView* mainRenderTargetView;

    bool CreateDeviceD3D(HWND hWnd);
    void CleanupDeviceD3D();
    void CreateRenderTarget();
    void CleanupRenderTarget();
};

#endif