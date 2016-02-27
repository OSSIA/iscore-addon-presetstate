#pragma once
#include <PresetState/Model.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>
#include <iscore/command/Dispatchers/CommandDispatcher.hpp>
#include <QString>
class QLineEdit;
namespace iscore {
class Document;
struct DocumentContext;
}  // namespace iscore

namespace PresetState
{
class Model;
namespace Inspector
{
class Widget final :
        public Process::StateProcessInspectorWidgetDelegate_T<PresetState::Model>
{
    public:
        explicit Widget(
                const PresetState::Model& object,
                const iscore::DocumentContext& context,
                QWidget* parent);

    private:
        void on_textChange();

        QLineEdit* m_edit{};

        CommandDispatcher<> m_dispatcher;
};
}
}
