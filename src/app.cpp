//-- Default empty project template
#include "app.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/system/InvokeManager>
#include <bb/cascades/InvokeActionItem>
#include <bb/cascades/InvokeQuery>
#include <bb/cascades/ActionBarPlacement>
#include <bb/system/CardDoneMessage>
#include <bb/PpsObject>
#include <bb/cascades/Page>
using namespace bb::cascades;
using namespace bb::system;

App::App() {
	QmlDocument *qml = QmlDocument::create("asset:///main.qml");
	//-- setContextProperty expose C++ object in QML as an variable
	//-- uncomment next line to introduce 'this' object to QML name space as an 'app' variable
	qml->setContextProperty("app", this);

	Page *root = qml->createRootObject<Page>();
	Application::instance()->setScene(root);
	invokeManager = new InvokeManager();
	connect(invokeManager,
			SIGNAL(childCardDone(const bb::system::CardDoneMessage&)), this,
			SLOT(childCardDone(const bb::system::CardDoneMessage&)));
}

void App::childCardDone(const bb::system::CardDoneMessage &doneMessage) {
	qDebug() << "reason" << doneMessage.reason();
	qDebug() << "data: " << doneMessage.data();
}

void App::onShowHelloCard() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://venues/search");

	invokeManager->invoke(cardRequest);
}

void App::onShowProfile() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://users/self/update");

	invokeManager->invoke(cardRequest);
}

void App::onFriendRequests() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://users/requests");

	invokeManager->invoke(cardRequest);
}

void App::onSSO() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.sso.card");
	cardRequest.setAction("bb.action.VIEW");
	cardRequest.setMimeType("sso/foursquare");
	cardRequest.setData(QString("KZVMPWA403INWP4FSVVUO4DORGUZR5VEJLZZH3BSUGNC33Q4").toUtf8());

	invokeManager->invoke(cardRequest);
}


void App::onPageSuggestions() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://users/suggest?type=page");

	invokeManager->invoke(cardRequest);
}


void App::onFriendSuggestions() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://users/suggest?type=friend");

	invokeManager->invoke(cardRequest);
}


void App::onCheckinReminder() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://venues/explore");

	invokeManager->invoke(cardRequest);
}


void App::onAddFriends() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://users/addfriends?from=phonebook");

	invokeManager->invoke(cardRequest);
}

void App::onOpenVenue() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://venues/4ef0e7cf7beb5932d5bdeb4e");

	invokeManager->invoke(cardRequest);
}

void App::onOpenCheckin() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://checkins/50a08609e4b04c46ea54446d");

	invokeManager->invoke(cardRequest);
}

