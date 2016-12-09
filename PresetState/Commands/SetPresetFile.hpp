#pragma once
#include <PresetState/Commands/PresetStateCommandFactoryKey.hpp>
#include <iscore/command/Command.hpp>
#include <QString>

#include <iscore/tools/ModelPath.hpp>

namespace PresetState
{
class Model;
class SetPresetFile final : public iscore::Command
{
        ISCORE_COMMAND_DECL(PresetState::CommandFactoryName(), SetPresetFile, "Load a preset")
    public:
        SetPresetFile(
                Path<Model>&& model,
                const QString& text);

    private:
        void undo() const override;
        void redo() const override;

        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

        Path<Model> m_model;
        QString m_old, m_new;
};
}
