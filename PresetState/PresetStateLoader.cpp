#include "PresetStateLoader.hpp"
#include <State/ValueConversion.hpp>
#include <QJsonDocument>
#include <QJsonObject>
namespace PresetState
{

static void loadPreset_rec(
    Preset& preset,
    const State::Address& current,
    const QJsonObject& currentObj)
{
  for(const auto& key : currentObj.keys())
  {
    State::Address next = current;
    next.path.push_back(key);
    const auto& val = currentObj[key];
    if(val.isObject())
    {
      loadPreset_rec(preset, next, val.toObject());
    }
    else
    {
      preset.emplace_back(next, State::convert::fromQJsonValue(val));
    }
  }
}

Preset loadPresetFromJson(const QByteArray& json)
{
  Preset preset;

  auto doc = QJsonDocument::fromJson(json);
  if(!doc.isObject())
    return {};

  loadPreset_rec(preset, {}, doc.object());

  return preset;
}
}
