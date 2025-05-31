#ifndef RAWPLAYER_HPP
#define RAWPLAYER_HPP

#include "../IPlayer.hpp"
#include "miniaudio.h"

class RawPlayer : public IPlayer
{
public:
    RawPlayer();
    ~RawPlayer();
    void Init();
    void Play(const std::string& filePath) override;
    void Pause() override;
    void Stop() override;
    double GetCurrentPosition() const override;
    void SetCurrentPosition(double position) override;
    void RegisterHandlers() override;
private:
    ma_device device;
    ma_decoder decoder;
    PlayerInitStatus initStatus = PlayerInitStatus::Idle; // Flag to check if the player is initialized
    static void* pMyCustomData; // Custom data pointer for the device
};

#endif