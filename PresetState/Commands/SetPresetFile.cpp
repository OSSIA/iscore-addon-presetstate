#include <PresetState/Model.hpp>
#include <algorithm>

#include "SetPresetFile.hpp"
#include <score/serialization/DataStreamVisitor.hpp>
#include <score/model/path/PathSerialization.hpp>
namespace PresetState
{
SetPresetFile::SetPresetFile(
    const Model& model,
    const QString& text):
  m_model{model},
  m_new{text}
{
    m_old = model.file();
}

void SetPresetFile::undo(const score::DocumentContext& ctx) const
{
    m_model.find(ctx).setFile(m_old);
}

void SetPresetFile::redo(const score::DocumentContext& ctx) const
{
    m_model.find(ctx).setFile(m_new);
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
