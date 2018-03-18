#pragma once
#include <Process/Process.hpp>
#include <PresetState/Metadata.hpp>
#include <PresetState/Preset.hpp>
namespace PresetState
{
class Model :
        public Process::ProcessModel
{
        Q_OBJECT
        SCORE_SERIALIZE_FRIENDS
        PROCESS_METADATA_IMPL(Model)

        public:
        explicit Model(
                TimeVal t,
                const Id<Process::ProcessModel>& id,
                QObject* parent);

        template<typename Impl>
        explicit Model(
                Impl& vis,
                QObject* parent) :
            Process::ProcessModel{vis, parent}
        {
            vis.writeTo(*this);
        }


        void setFile(const QString& script);
        const QString& file() const
        { return m_file; }

        const Preset& preset() const
        { return m_preset; }

    Q_SIGNALS:
        void fileChanged();

    private:
        QString prettyName() const override
        {
            return Metadata<PrettyName_k, Model>::get();
        }

        QString m_file;
        Preset m_preset;
};
}
