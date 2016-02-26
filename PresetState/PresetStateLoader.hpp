#pragma once
#include <State/Message.hpp>
namespace PresetState
{
using Preset = std::vector<State::Message>;

Preset loadPresetFromJson(const QByteArray& json);
}
