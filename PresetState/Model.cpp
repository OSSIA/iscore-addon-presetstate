#include "Model.hpp"
#include <iscore/serialization/VisitorCommon.hpp>

template<>
void Visitor<Reader<DataStream>>::readFrom_impl(
        const PresetState::Model& proc)
{
    m_stream << proc.m_file;
    insertDelimiter();
}

template<>
void Visitor<Writer<DataStream>>::writeTo(PresetState::Model& proc)
{
    QString str;
    m_stream >> str;
    proc.setFile(str);

    checkDelimiter();
}

template<>
void Visitor<Reader<JSONObject>>::readFrom_impl(const PresetState::Model& proc)
{
    m_obj["File"] = proc.m_file;
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(PresetState::Model& proc)
{
    proc.setFile(m_obj["File"].toString());
}


namespace PresetState
{
Model::Model(const Id<Process::StateProcess> &id, QObject *parent):
    Process::StateProcess{id, Metadata<ObjectKey_k, Model>::get(), parent}
{

}

void Model::setFile(const QString& script)
{
    m_file = script;
    emit fileChanged();
}

void Model::serialize_impl(const VisitorVariant &vis) const
{
    serialize_dyn(vis, *this);
}
}
