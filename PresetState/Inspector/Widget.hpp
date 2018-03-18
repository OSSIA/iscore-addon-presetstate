#pragma once
#include <PresetState/Model.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>
#include <score/command/Dispatchers/CommandDispatcher.hpp>
#include <QString>
class QLineEdit;
namespace score {
class Document;
struct DocumentContext;
}  // namespace score

namespace PresetState
{
class Model;
namespace Inspector
{
class Widget final :
        public Process::InspectorWidgetDelegate_T<PresetState::Model>
{
    public:
        explicit Widget(
                const PresetState::Model& object,
                const score::DocumentContext& context,
                QWidget* parent);

    private:
        void on_textChange();

        QLineEdit* m_edit{};

        CommandDispatcher<> m_dispatcher;
};
}
}
