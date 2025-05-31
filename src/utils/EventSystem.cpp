#include "EventSystem.hpp"
#include <iostream>

EventSystem::EventSystem(){ /* Do nothing */ }

EventSystem::~EventSystem(){ /* Do nothing */ }

void EventSystem::ProcessEvents()
{
    while (!eventQueue.empty())
    {
        EventType eventType = eventQueue.front();
        eventQueue.pop();

        // Check if there is a handler for this event type
        auto it = eventHandlers.find(eventType);
        if (it != eventHandlers.end())
        {
            // Call the handler function for the event
            it->second();
        }
        else
        {
            // Handle the case where no handler is registered for this event type
            // This could be logging, throwing an error, or a default action
            // For now, we will just print a message to the console
            switch (eventType)
            {
                case EventType::Play:
                    std::cout << "Play event received but no handler registered." << std::endl;
                    break;
                case EventType::Pause:
                    std::cout << "Pause event received but no handler registered." << std::endl;
                    break;
                case EventType::Stop:
                    std::cout << "Stop event received but no handler registered." << std::endl;
                    break;
                case EventType::VolumeChange:
                    std::cout << "VolumeChange event received but no handler registered." << std::endl;
                    break;
                case EventType::TrackChange:
                    std::cout << "TrackChange event received but no handler registered." << std::endl;
                    break;
                case EventType::Quit:
                    std::cout << "Quit event received but no handler registered." << std::endl;
                    break;
            }
        }
    }
}

void EventSystem::QueryEvent(EventType eventType)
{
    eventQueue.push(eventType);
}

void EventSystem::RegisterEventHandler(EventType eventType, std::function<void()> handler)
{
    eventHandlers[eventType] = handler;
}
void EventSystem::UnregisterEventHandler(EventType eventType)
{
    eventHandlers.erase(eventType);
}
void EventSystem::ClearEventQueue()
{
    while (!eventQueue.empty())
    {
        eventQueue.pop();
    }
}
void EventSystem::ClearEventHandlers()
{
    eventHandlers.clear();
}
void EventSystem::ClearAll()
{
    ClearEventQueue();
    ClearEventHandlers();
}