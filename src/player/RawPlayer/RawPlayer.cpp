#include "RawPlayer.hpp"
#include "utils/EventSystem.hpp"

const char* argv[] = { "RawPlayer", "media/example.mp3" }; // Example file path, replace with actual file path

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
    if (pDecoder == NULL) {
        return;
    }

    ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);

    (void)pInput;
}

RawPlayer::RawPlayer(){ RegisterHandlers(); }
RawPlayer::~RawPlayer(){ /* Do nothing */ }

void RawPlayer::Init()
{
    
}
void RawPlayer::Play(const std::string& filePath)
{
    ma_result result;
    ma_device_config deviceConfig;

    result = ma_decoder_init_file(argv[1], NULL, &decoder);
    if (result != MA_SUCCESS) {
        printf("Could not load file: %s\n", argv[1]);
        initStatus = PlayerInitStatus::FileNotFound;
    }

    deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format   = decoder.outputFormat;
    deviceConfig.playback.channels = decoder.outputChannels;
    deviceConfig.sampleRate        = decoder.outputSampleRate;
    deviceConfig.dataCallback      = data_callback;
    deviceConfig.pUserData         = &decoder;

    if (ma_device_init(NULL, &deviceConfig, &device) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        ma_decoder_uninit(&decoder);
        initStatus = PlayerInitStatus::DeviceError;
    }

    if (ma_device_start(&device) != MA_SUCCESS) {
        printf("Failed to start playback device.\n");
        ma_device_uninit(&device);
        ma_decoder_uninit(&decoder);
        initStatus = PlayerInitStatus::DeviceError;
    }

    initStatus = PlayerInitStatus::Success;
}
void RawPlayer::Pause()
{
    ma_device_stop(&device);
}
void RawPlayer::Stop()
{
    ma_device_uninit(&device);
    ma_decoder_uninit(&decoder);
}
double RawPlayer::GetCurrentPosition() const
{
    // Implementation for getting the current playback position
    return 0.0; // Placeholder return value
}
void RawPlayer::SetCurrentPosition(double position)
{
    // Implementation for setting the current playback position
}
void RawPlayer::RegisterHandlers()
{
    EventSystem::RegisterEventHandler(EventType::Play, [this]() { Play(""); }); // Placeholder for file path
    EventSystem::RegisterEventHandler(EventType::Pause, [this]() { Pause(); });
    EventSystem::RegisterEventHandler(EventType::Stop, [this]() { Stop(); });
}