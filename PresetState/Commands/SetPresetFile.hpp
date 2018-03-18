#pragma once
#include <PresetState/Commands/PresetStateCommandFactoryKey.hpp>
#include <score/command/Command.hpp>
#include <QString>

#include <score/model/path/Path.hpp>

namespace PresetState
{
class Model;
class SetPresetFile final : public score::Command
{
        SCORE_COMMAND_DECL(PresetState::CommandFactoryName(), SetPresetFile, "Load a preset")
    public:
        SetPresetFile(
                const Model& model,
                const QString& text);

    private:
        void undo(const score::DocumentContext& ctx) const override;
        void redo(const score::DocumentContext& ctx) const override;

        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

        Path<Model> m_model;
        QString m_old, m_new;
};
}
