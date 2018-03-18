#pragma once
#include <Process/ProcessMetadata.hpp>
#include <QString>
#include <score_addon_presetstate_export.h>

namespace PresetState
{
class Model;
}

PROCESS_METADATA(
        SCORE_ADDON_PRESETSTATE_EXPORT,
        PresetState::Model,
        "e11a7697-a1be-4b98-a5ca-01df7b34489b",
        "PresetState",
        "Preset File State",
        "Control",
        {},
        Process::ProcessFlags::SupportsState
        )
