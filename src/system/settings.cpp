#include "settings.hpp"

Settings::~Settings() {}
Settings::Settings() {}

void Settings::init(std::string pathToSettings, std::string pathToDefSettings)
{
    Settings::m_Settings = Json::Value();
    Settings::m_DefaultSettings = Json::Value();

    if (pathToSettings != "")
    {
        Settings::m_PathToSettings = pathToSettings;

        std::ifstream ifs(Settings::m_PathToSettings);
        Json::Reader reader;
        reader.parse(ifs, Settings::m_Settings);
    }
    if (pathToDefSettings != "")
    {
        std::ifstream ifs(pathToDefSettings);
        Json::Reader reader;
        reader.parse(ifs, Settings::m_DefaultSettings);
    }
}

void Settings::set(std::string key, Json::Value value)
{
    Settings::m_Settings[key] = value;

    if (Settings::m_PathToSettings != "")
    {
        std::ofstream out_stream;
        out_stream.open(Settings::m_PathToSettings);

        Json::StreamWriterBuilder builder;
        builder["commentStyle"] = "None";
        builder["indentation"] = "    ";

        std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
        writer->write(Settings::m_Settings, &out_stream);

        out_stream.close();
    }
}

Json::Value Settings::get(std::string key)
{
    if (!Settings::m_Settings.isMember(key))
    {
        if (Settings::m_DefaultSettings.isMember(key))
            Settings::set(key, Settings::m_DefaultSettings[key]);
        else
            Settings::set(key, Json::Value(0));
    }

    return Settings::m_Settings[key];
}

void Settings::clear()
{
    Settings::m_Settings = Json::Value();

    if (Settings::m_PathToSettings != "")
    {
        std::ofstream out_stream;
        out_stream.open(Settings::m_PathToSettings, std::ofstream::out | std::ofstream::trunc);
        out_stream.close();
    }
}
