#pragma once
#include <vector>
#include <iostream>

using namespace std;

class NotificationsPreferences;

class NotificationsPreferences
{
	bool allowMessageNotifications;
	bool allowGroupMessageNotifications;
	bool allowNewTaskNotifications;

public:

	class NotificationsSnapshot {
		NotificationsPreferences* prefs;
		bool allowMessageNotifications;
		bool allowGroupMessageNotifications;
		bool allowNewTaskNotifications;
		
	public:
		NotificationsSnapshot() {
			this->prefs = NULL;
			this->allowMessageNotifications = true;
			this->allowGroupMessageNotifications = true;
			this->allowNewTaskNotifications = true;
		}

		NotificationsSnapshot(NotificationsPreferences* prefs, bool allowMessageNotifications, bool allowGroupMessageNotifications, bool allowNewTaskNotifications) {
			this->prefs = prefs;
			this->allowMessageNotifications = allowMessageNotifications;
			this->allowGroupMessageNotifications = allowGroupMessageNotifications;
			this->allowNewTaskNotifications = allowNewTaskNotifications;
		}

		vector<bool> getState() {
			return { this->allowMessageNotifications , this->allowGroupMessageNotifications , this->allowNewTaskNotifications };
		}
	};

	NotificationsPreferences() {
		this->allowMessageNotifications = true;
		this->allowGroupMessageNotifications = true;
		this->allowNewTaskNotifications = true;
	}

	NotificationsPreferences(bool allowMessageNotifications, bool allowGroupMessageNotifications, bool allowNewTaskNotifications) {
		this->allowMessageNotifications = allowMessageNotifications;
		this->allowGroupMessageNotifications = allowGroupMessageNotifications;
		this->allowNewTaskNotifications = allowNewTaskNotifications;
	}

	void setState(vector<bool> state) {
		this->allowMessageNotifications = state[0];
		this->allowGroupMessageNotifications = state[1];
		this->allowNewTaskNotifications = state[2];
	}

	NotificationsSnapshot save() {
		return NotificationsSnapshot(this, this->allowMessageNotifications, this->allowGroupMessageNotifications, this->allowNewTaskNotifications);
	}

	void restore(NotificationsSnapshot snapshot) {
		this->setState(snapshot.getState());
	}

	void printState() {
		cout << "allowMessageNotifications: \t\t" << this->allowMessageNotifications << '\n';
		cout << "allowGroupMessageNotifications: \t" << this->allowGroupMessageNotifications << '\n';
		cout << "allowNewTaskNotifications: \t\t" << this->allowNewTaskNotifications << '\n';
	}
};

