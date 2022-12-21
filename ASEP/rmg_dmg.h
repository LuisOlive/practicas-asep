#include "../classes/Subconductores.h"

#ifndef RMG_DMG_H
#define RMG_DMG_H

void dmgRmg()
{
    puts("Conductor 1:");
    Subconductores c1;
    hr();

    puts("Conductor 2:");
    Subconductores c2;
    hr();

    cout << "DMG entre los conductores: " << fmtIng(c1.dmg(c2), c1.unidad) << endl;

    cout << "RMG en el conductor 1: " << fmtIng(c1.rmg(), c1.unidad) << endl;
    cout << "RMG en el conductor 2: " << fmtIng(c2.rmg(), c2.unidad) << endl;
}

#endif