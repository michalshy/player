#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include <string>

enum class PlayerInitStatus {
    Idle,
    Success,
    FileNotFound,
    UnsupportedFormat,
    DeviceError,
    UnknownError
};

class IPlayer {
public:
    virtual ~IPlayer() = default;
    virtual void Play(const std::string& filePath) = 0;
    virtual void Pause() = 0;
    virtual void Stop() = 0;
    virtual double GetCurrentPosition() const = 0;
    virtual void SetCurrentPosition(double position) = 0;
    virtual void RegisterHandlers() = 0;
};

#endif // IPLAYER_HPP