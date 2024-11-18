/**
 * @brief PS Vita Implementation for Controls.
 * 
 * Uses native PS Vita functions to know which buttons are pressed.
 * 
 * Used only in PS Vita build.
 */

#include "../controls.hpp"

/// @brief PS Vita Controls specific data.
struct ControlsSpecific {};

Controls::Controls() {}
Controls::~Controls() {}

void Controls::check()
{

}

bool Controls::getQuit()            { return Controls::isQuit; }

bool Controls::getMenuUp()          { return Controls::isMenuUp; }
bool Controls::getMenuDown()        { return Controls::isMenuDown; }
bool Controls::getMenuLeft()        { return Controls::isMenuLeft; }
bool Controls::getMenuRight()       { return Controls::isMenuRight; }
