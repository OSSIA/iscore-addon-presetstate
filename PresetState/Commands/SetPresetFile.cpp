#include <PresetState/Model.hpp>
#include <algorithm>

#include "SetPresetFile.hpp"
#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/model/path/PathSerialization.hpp>
namespace PresetState
{
SetPresetFile::SetPresetFile(
    Path<Model>&& model,
    const QString& text):
  m_model{std::move(model)},
  m_new{text}
{
    m_old = m_model.find().file();
}

void SetPresetFile::undo() const
{
    m_model.find().setFile(m_old);
}

void SetPresetFile::redo() const
{
    m_model.find().setFile(m_new);
}

void SetPresetFile::serializeImpl(DataStreamInput& s) const
{
    s << m_model << m_old << m_new;
}

void SetPresetFile::deserializeImpl(DataStreamOutput& s)
{
    s >> m_model >> m_old >> m_new;
}
}
