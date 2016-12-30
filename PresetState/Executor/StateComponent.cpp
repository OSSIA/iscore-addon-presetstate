#include "StateComponent.hpp"
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <Engine/iscore2OSSIA.hpp>
#include <PresetState/Model.hpp>
#include <ossia/editor/state/state_element.hpp>
#include <Engine/iscore2OSSIA.hpp>


namespace PresetState
{
namespace Executor
{
static void convert(
        const Preset& p,
        ossia::state& state,
        const Device::DeviceList& lst)
{
    for(auto& message : p)
    {
        state.add(Engine::iscore_to_ossia::message(message, lst));
    }
}

//// Component ////
StateProcessComponent::StateProcessComponent(
        Engine::Execution::StateComponent& parentConstraint,
        Model& element,
        const Engine::Execution::Context& ctx,
        const Id<iscore::Component>& id,
        QObject* parent):
    Engine::Execution::StateProcessComponent_T<PresetState::Model>{
        parentConstraint, element, ctx, id, "PresetStateComponent", parent}
{
    ossia::state state;

    // We just add messages
    convert(element.preset(), state, ctx.devices.list());

    m_ossia_state = std::move(state);
}

ossia::state_element StateProcessComponent::make(
        Process::StateProcess &proc,
        const Engine::Execution::Context &ctx)
{
    ossia::state state;
    convert(static_cast<Model&>(proc).preset(), state, ctx.devices.list());
    return state;
}

}
}
