//-- Default empty project template
#ifndef APP_H
#define APP_H

#include <QObject>
#include <bb/system/InvokeManager>
/*!
 * @brief Application GUI object
 */
class App: public QObject {
Q_OBJECT
public:
	App();
public slots:
	void onVenueSearch();
	void onShowProfile();
	void onFriendRequests();
	void onPageSuggestions();
	void onFriendSuggestions();
	void onCheckinReminder();
	void onAddFriends();
	void onOpenVenue();
	void onOpenCheckin();
	void onVenueSearchCard();
	void onSSO();
	void childCardDone(const bb::system::CardDoneMessage &doneMessage);
private:
	bb::system::InvokeManager *invokeManager;
};

#endif // ifndef APP_H
