/// @brief This provides a declaration of the Settings (manager) of the game.

#pragma once

#include <json/json.h>

#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Class that manages settings in the game and operates with theirs file.
 * 
 * - You can create some kind of parameter that you can tweak after build
 * without having to recompile the game.
 * 
 * - You can define a default value for this parameter that could be different
 * on different platforms.
 * 
 * - When you set this value in-game, it will be saved and loaded upon game restart.
 * 
 * When created, Settings do nothing.
 * To load the default settings values and be ready to save them on the drive,
 * you have to call `init()` first.
 * Then, use simple `set(key, value)` / `get(key)` scheme to tweak settings.
 */
class Settings
{
public:
    ~Settings();
    Settings();

    /// @brief Load settings file and create Settings instance.
    ///
    /// At every `set()` call will write updated parameter to file if it's successfully loaded.
    /// Will also call `set()` when setting default value to
    /// parameter which was requested through `get()` and doesn't have value.
    /// @param path_to_settings path to the JSON where user settings are stored.
    /// If doesn't exist - it'll create it. If leave empty, settings affect only the current session.
    /// @param path_to_def_settings path to the JSON where default settings are stored.
    /// If leave empty, all default settings will be considered as 0.
    void init(std::string path_to_settings = "", std::string path_to_def_settings = "");

    /// @brief Set some value at the settings.
    /// Will affect current session and write it to the file if it's loaded.
    /// @param key Name of the parameter to be setted.
    /// @param value Value of the parameter to be setted.
    void set(std::string key, Json::Value value);

    /// @brief Get some value from the settings.
    /// @param key Name of the parameter to be returned.
    /// @return Value of the parameter. If it's not set - set to default value and return it.
    Json::Value get(std::string key);

    /// @brief Clear all the settings (reset them to default).
    void clear();
private:
    /// @brief Game settings loaded as Json Value.
    Json::Value m_Settings;
    /// @brief Predefined game settings loaded as Json Value.
    Json::Value m_DefaultSettings;
    /// @brief Where game settings are located on the drive?
    std::string m_PathToSettings = "";
};
