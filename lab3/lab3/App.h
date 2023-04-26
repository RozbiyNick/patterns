#pragma once
#include "NotificationsPreferences.h"

class App
{
	NotificationsPreferences notificationPreferences;
	vector<NotificationsPreferences::NotificationsSnapshot> history;

public:
	App() {
		this->notificationPreferences = NotificationsPreferences();
		this->history = vector< NotificationsPreferences::NotificationsSnapshot>(0);
		this->history.push_back(this->notificationPreferences.save());
	}

	void updateNotificationsPreferences(vector<bool> state) {
		this->notificationPreferences.setState(state);
		history.push_back(this->notificationPreferences.save());
	}

	void backupNotificationsPreferences() {
		this->history.pop_back();
		this->notificationPreferences.restore(this->history.back());
	}

	NotificationsPreferences getNotificationsPreferences() {
		return this->notificationPreferences;
	}
};

