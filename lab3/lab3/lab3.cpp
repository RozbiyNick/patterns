#include "App.h"

int main()
{
    App app = App();
    cout << "Default settings:\n";
    app.getNotificationsPreferences().printState();
    cout << "\n";

    app.updateNotificationsPreferences({1, 0, 1});
    cout << "Settings after update:\n";
    app.getNotificationsPreferences().printState();
    cout << "\n";

    app.backupNotificationsPreferences();
    cout << "Settings after backup:\n";
    app.getNotificationsPreferences().printState();
    cout << "\n";
}

