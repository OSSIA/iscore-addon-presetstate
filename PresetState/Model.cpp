#include "Model.hpp"
#include <iscore/serialization/VisitorCommon.hpp>
#include <QFile>

template <>
void DataStreamReader::read(
        const PresetState::Model& proc)
{
    m_stream << proc.m_file;
    insertDelimiter();
}

template <>
void DataStreamWriter::writeTo(PresetState::Model& proc)
{
    QString str;
    m_stream >> str;
    proc.setFile(str);

    checkDelimiter();
}

template <>
void JSONObjectReader::read(const PresetState::Model& proc)
{
    obj["File"] = proc.m_file;
}

template <>
void JSONObjectWriter::writeTo(PresetState::Model& proc)
{
    proc.setFile(obj["File"].toString());
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

    QFile f{m_file};
    if(f.open(QFile::ReadOnly))
    {
        m_preset = loadPresetFromJson(f.readAll());
    }

    emit fileChanged();
}

}
