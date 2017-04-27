#pragma once
#include <Process/StateProcess.hpp>
#include <PresetState/Metadata.hpp>
#include <PresetState/Preset.hpp>
namespace PresetState
{
class Model :
        public Process::StateProcess
{
        Q_OBJECT
        ISCORE_SERIALIZE_FRIENDS
        PROCESS_METADATA_IMPL(Model)

        public:
        explicit Model(
                const Id<Process::StateProcess>& id,
                QObject* parent);

        explicit Model(
                const Model& source,
                const Id<Process::StateProcess>& id,
                QObject* parent):
            Process::StateProcess{id, Metadata<ObjectKey_k, Model>::get(), parent}
        {
            setFile(source.m_file);
        }

        template<typename Impl>
        explicit Model(
                Impl& vis,
                QObject* parent) :
            Process::StateProcess{vis, parent}
        {
            vis.writeTo(*this);
        }


        void setFile(const QString& script);
        const QString& file() const
        { return m_file; }

        const Preset& preset() const
        { return m_preset; }

    signals:
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
