#ifndef EVENTSYSTEM_HPP
#define EVENTSYSTEM_HPP

#include <unordered_map>
#include <functional>
#include <queue>

enum class EventType
{
    Play,
    Pause,
    Stop,
    VolumeChange,
    TrackChange,
    Quit,
};

class EventSystem
{
public:
    EventSystem();
    static void ProcessEvents();
    static void QueryEvent(EventType eventType);
    static void RegisterEventHandler(EventType eventType, std::function<void()> handler);
    static void UnregisterEventHandler(EventType eventType);
    static void ClearEventQueue();
    static void ClearEventHandlers();
    static void ClearAll();
    ~EventSystem();
private:
    static inline std::queue<EventType> eventQueue; // Queue to hold events
    static inline std::unordered_map<EventType, std::function<void()>> eventHandlers; // Map to hold event names and their handlers
};

#endif