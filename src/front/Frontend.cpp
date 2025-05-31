#include "Frontend.hpp"
#include "imgui.h"
#include "utils/EventSystem.hpp"

Frontend::Frontend(){ /* Do nothing */ }
Frontend::~Frontend(){ /* Do nothing */ }

void Frontend::Render()
{
    ImGuiIO& io = ImGui::GetIO();
    static float f = 0.5f; // Volume
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoSavedSettings | 
                                ImGuiWindowFlags_NoFocusOnAppearing |
                                ImGuiWindowFlags_NoNavFocus |
                                ImGuiWindowFlags_NoTitleBar;
    // Exit button as a cross in the top-right corner of the Music Player window
    ImGui::Begin("Music Player", nullptr, window_flags);
    ImGui::Text("🎵 Music Player");
    ImGui::Separator();
    ImVec2 win_pos = ImGui::GetWindowPos();
    ImVec2 win_size = ImGui::GetWindowSize();
    float button_sz = 20.0f;
    ImGui::SetCursorScreenPos(ImVec2(win_pos.x + win_size.x - button_sz - 4, win_pos.y + 4));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 2.0f);
    ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(200, 60, 60, 255));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(255, 80, 80, 255));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(180, 40, 40, 255));
    if (ImGui::Button("x", ImVec2(button_sz, button_sz))) {
        EventSystem::QueryEvent(EventType::Quit);
    }
    ImGui::PopStyleColor(3);
    ImGui::PopStyleVar();
    ImGui::SetCursorScreenPos(ImVec2(win_pos.x + 16, win_pos.y + 40));
    if (ImGui::Button("Play")) 
    {
        EventSystem::QueryEvent(EventType::Play);
    }
    ImGui::SameLine();
    if (ImGui::Button("Pause")) 
    {
        EventSystem::QueryEvent(EventType::Pause);
    }
    ImGui::SameLine();
    if (ImGui::Button("Stop")) 
    {
        EventSystem::QueryEvent(EventType::Stop);
    }
    ImGui::SliderFloat("Volume", &f, 0.0f, 1.0f, "%.2f");
    ImGui::Separator();
    ImGui::Text("Now Playing: <Track Name>");
    ImGui::ProgressBar(0.3f, ImVec2(-1, 0), "01:23 / 04:56");
    ImGui::End();
}