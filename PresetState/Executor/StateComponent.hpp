#pragma once
#include <QString>
#include <memory>
#include <Editor/State.h>
#include <OSSIA/Executor/ProcessElement.hpp>
#include <OSSIA/Executor/ExecutorContext.hpp>
#include <iscore/document/DocumentContext.hpp>
#include <iscore/document/DocumentInterface.hpp>
#include <PresetState/Preset.hpp>

namespace PresetState
{
class Model;
namespace Executor
{
class StateProcessComponent final :
        public RecreateOnPlay::StateProcessComponent
{
    public:
        StateProcessComponent(
                RecreateOnPlay::StateElement& parentState,
                PresetState::Model& element,
                const RecreateOnPlay::Context& ctx,
                const Id<iscore::Component>& id,
                QObject* parent);

    private:
        const Key &key() const override;
};

class StateProcessComponentFactory final :
        public RecreateOnPlay::StateProcessComponentFactory
{
    public:
        virtual ~StateProcessComponentFactory();

        RecreateOnPlay::StateProcessComponent* make(
                RecreateOnPlay::StateElement& cst,
                Process::StateProcess& proc,
                const RecreateOnPlay::Context& ctx,
                const Id<iscore::Component>& id,
                QObject* parent) const override;

        const ConcreteFactoryKey& concreteFactoryKey() const override;

        bool matches(
                Process::StateProcess& proc,
                const RecreateOnPlay::DocumentPlugin&,
                const iscore::DocumentContext &) const override;

        std::shared_ptr<OSSIA::StateElement> make(
                Process::StateProcess& proc,
                const RecreateOnPlay::Context& ctxt) const override;
};
}
}
