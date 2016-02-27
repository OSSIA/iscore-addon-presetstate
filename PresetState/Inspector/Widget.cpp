#include "Widget.hpp"
#include <PresetState/Model.hpp>
#include <PresetState/Commands/SetPresetFile.hpp>
#include <iscore/document/DocumentContext.hpp>
#include <QVBoxLayout>
#include <QLineEdit>

namespace PresetState
{
namespace Inspector
{
Widget::Widget(
        const PresetState::Model& model,
        const iscore::DocumentContext& doc,
        QWidget* parent) :
    StateProcessInspectorWidgetDelegate_T {model, parent},
    m_dispatcher{doc.commandStack}
{
    setObjectName("PresetStateInspectorWidget");
    setParent(parent);
    auto lay = new QVBoxLayout;

    m_edit = new QLineEdit{process().file()};
    connect(m_edit, &QLineEdit::editingFinished,
            this, &Widget::on_textChange);

    con(process(), &Model::fileChanged,
        this, [&] {
        m_edit->setText(process().file());
    });

    lay->addWidget(m_edit);
    this->setLayout(lay);
}

void Widget::on_textChange()
{
    auto newTxt = m_edit->text();
    if(newTxt == process().file())
        return;

    auto cmd = new SetPresetFile{process(), newTxt};

    m_dispatcher.submitCommand(cmd);
}
}
}
