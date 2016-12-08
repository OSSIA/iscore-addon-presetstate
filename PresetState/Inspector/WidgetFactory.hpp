#pragma once
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>
#include <PresetState/Model.hpp>
#include <PresetState/Inspector/Widget.hpp>

namespace PresetState
{
namespace Inspector
{
class Factory final :
        public Process::StateProcessInspectorWidgetDelegateFactory_T<Model, Widget>
{
        ISCORE_CONCRETE("577bc362-e279-488c-b0ac-5972851ea291")
};
}
}
