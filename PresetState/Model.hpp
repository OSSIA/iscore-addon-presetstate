#pragma once
#include <Process/StateProcess.hpp>
#include <PresetState/Metadata.hpp>
namespace PresetState
{
class Model :
        public Process::StateProcess
{
        Q_OBJECT
        ISCORE_SERIALIZE_FRIENDS(PresetState::Model, DataStream)
        ISCORE_SERIALIZE_FRIENDS(PresetState::Model, JSONObject)
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
                Deserializer<Impl>& vis,
                QObject* parent) :
            Process::StateProcess{vis, parent}
        {
            vis.writeTo(*this);
        }


        void setFile(const QString& script);
        const QString& file() const
        { return m_file; }

        UuidKey<Process::StateProcessFactory> concreteFactoryKey() const override
        {
            return Metadata<ConcreteFactoryKey_k, Model>::get();
        }
        void serialize_impl(const VisitorVariant& vis) const override;

    signals:
        void fileChanged();

    private:
        StateProcess* clone(
                const Id<Process::StateProcess>& newId,
                QObject* newParent) const override
        {
            return new Model {*this, newId, newParent};
        }

        QString prettyName() const override
        {
            return Metadata<PrettyName_k, Model>::get();
        }

        QString m_file;
};
}
