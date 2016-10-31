#include "save.h"

Save::saveScore()
{
    saveFile = "UsrSave.txt";
    save = saveFile;

    save << "#Jacked\n";
    save << "level " <<
}
