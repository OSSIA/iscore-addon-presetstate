#include <Inspector/InspectorWidgetFactoryInterface.hpp>
#include "WidgetFactory.hpp"
#include "Widget.hpp"
#include <PresetState/Model.hpp>

namespace PresetState
{
namespace Inspector
{
Factory::Factory()
{

}

Factory::~Factory()
{

}

Process::StateProcessInspectorWidgetDelegate* Factory::make(
        const Process::StateProcess& process,
        const iscore::DocumentContext& doc,
        QWidget* parent) const
{
    return new Widget{
        static_cast<const PresetState::Model&>(process),
                doc,
                parent};
}

bool Factory::matches(const Process::StateProcess& process) const
{
    return dynamic_cast<const PresetState::Model*>(&process);
}

}
}
