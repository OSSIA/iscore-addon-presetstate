#pragma once
#include <Process/ProcessFactory.hpp>
#include <PresetState/Model.hpp>
#include <PresetState/Metadata.hpp>
#include <iscore/serialization/VisitorCommon.hpp>
#include <Process/StateProcessFactory.hpp>
namespace PresetState
{
class Factory : public Process::StateProcessFactory
{
    public:
        QString prettyName() const override
        { return Metadata<PrettyName_k, Model>::get(); }

        const UuidKey<Process::StateProcessFactory>& concreteFactoryKey() const override
        { return Metadata<ConcreteFactoryKey_k, Model>::get(); }

        Model* make(const Id<Process::StateProcess>& id, QObject* parent) override
        { return new Model{id, parent}; }

        Process::StateProcess* load(
                const VisitorVariant& vis,
                QObject* parent) override
        {
            return deserialize_dyn(vis, [&] (auto&& deserializer)
            { return new Model{deserializer, parent};});
        }
};

}
