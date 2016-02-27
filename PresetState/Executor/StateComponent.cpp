#include "StateComponent.hpp"
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <OSSIA/iscore2OSSIA.hpp>
#include <PresetState/Model.hpp>
#include <Editor/Message.h>
#include <OSSIA/iscore2OSSIA.hpp>


namespace PresetState
{
namespace Executor
{
static void convert(
        const Preset& p,
        OSSIA::State& state,
        const Device::DeviceList& lst)
{
    for(auto& message : p)
    {
        auto mess = iscore::convert::message(message, lst);
        if(mess)
            state.stateElements().push_back(std::move(mess));
    }
}

//// Component ////
StateProcessComponent::StateProcessComponent(
        RecreateOnPlay::StateElement& parentConstraint,
        Model& element,
        const RecreateOnPlay::Context& ctx,
        const Id<iscore::Component>& id,
        QObject* parent):
    RecreateOnPlay::StateProcessComponent{
        parentConstraint, element, id, "PresetStateComponent", parent}
{
    auto state = OSSIA::State::create();

    // We just add messages
    convert(element.preset(), *state, ctx.devices.list());

    m_ossia_process = state;
}

const iscore::Component::Key& StateProcessComponent::key() const
{
    // TODO these should be uuids !!!!!
    static iscore::Component::Key k("a59c1b9a-c7aa-41b0-a521-26d364670188");
    return k;
}



//// Factory ////
StateProcessComponentFactory::~StateProcessComponentFactory()
{

}

RecreateOnPlay::StateProcessComponent* StateProcessComponentFactory::make(
        RecreateOnPlay::StateElement& cst,
        Process::StateProcess& proc,
        const RecreateOnPlay::Context& ctx,
        const Id<iscore::Component>& id,
        QObject* parent) const
{
    return new StateProcessComponent{cst, static_cast<Model&>(proc), ctx, id, parent};
}

const StateProcessComponentFactory::ConcreteFactoryKey&
StateProcessComponentFactory::concreteFactoryKey() const
{
    static ConcreteFactoryKey k("ec509448-d97a-4145-801b-1b06ecde4430");
    return k;
}

bool StateProcessComponentFactory::matches(
        Process::StateProcess& proc,
        const RecreateOnPlay::DocumentPlugin&,
        const iscore::DocumentContext&) const
{
    return dynamic_cast<Model*>(&proc);
}

std::shared_ptr<OSSIA::StateElement> StateProcessComponentFactory::make(
        Process::StateProcess &proc,
        const RecreateOnPlay::Context &ctx) const
{
    auto state = OSSIA::State::create();
    convert(static_cast<Model&>(proc).preset(), *state, ctx.devices.list());
    return state;
}

}
}
