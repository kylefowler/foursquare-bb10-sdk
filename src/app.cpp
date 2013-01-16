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
#include <bb/data/JsonDataAccess>
#include <bb/system/SystemToast>
using namespace bb::cascades;
using namespace bb::system;
using namespace bb::data;

App::App() {
	QmlDocument *qml = QmlDocument::create("asset:///main.qml");
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

	SystemToast* t = new SystemToast(this);
	if(doneMessage.dataType().compare("application/json") == 0) {
		//the data type from the venue search card is application/json
		//so we need to convert the json data to a map here. This will match
		//the json format from the foursquare docs at http://developer.foursquare.com
		JsonDataAccess jda;
		const QVariantMap venueMap = jda.loadFromBuffer(doneMessage.data()).toMap();
		t->setBody(QString("User Picked: ") + venueMap.value("name","").toString());
	} else {
		t->setBody(doneMessage.data());
	}
	t->show();
}

void App::onVenueSearch() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://venues/search");

	invokeManager->invoke(cardRequest);
}

void App::onShowProfile() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://users/self/update");

	invokeManager->invoke(cardRequest);
}

void App::onFriendRequests() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://users/requests");

	invokeManager->invoke(cardRequest);
}

void App::onSSO() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.sso.card");
	cardRequest.setAction("bb.action.VIEW");
	cardRequest.setMimeType("sso/foursquare");

	/*Pass in your CLIENT_ID from your Foursquare API consumer. This card will call back to your childCardDone slot with the
	 * appropriate response for the actions the user took.
	 *
	 * If the user authorizes your app or has already authorized you:
	 * The response reason will be "success" and the data block will have a json encoded access token which you can use
	 * for authenticated Foursquare requests. That response string looks something like this:
	 * { access_token: "masdfvasvawefafawvwef90we0900990092012" }
	 *
	 * If the user denies the authentication: the response reason will be "denied".
	 * If the user cancels the login without any action: the reason message will be "canceled"
	 */
	cardRequest.setData(QString("KZVMPWA403INWP4FSVVUO4DORGUZR5VEJLZZH3BSUGNC33Q4").toUtf8());

	invokeManager->invoke(cardRequest);
}

void App::onVenueSearchCard() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.venuesearch.card");
	cardRequest.setAction("bb.action.VIEW");
	cardRequest.setMimeType("venuesearch/foursquare");

	/* If you want to prime the search with a query, pass a query string into the data param
	 */
	cardRequest.setData(QString("best buy").toUtf8());

	invokeManager->invoke(cardRequest);
}

void App::onPageSuggestions() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://users/suggest?type=page");

	invokeManager->invoke(cardRequest);
}


void App::onFriendSuggestions() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://users/suggest?type=friend");

	invokeManager->invoke(cardRequest);
}


void App::onCheckinReminder() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://venues/explore");

	invokeManager->invoke(cardRequest);
}


void App::onAddFriends() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://users/addfriends?from=phonebook");

	invokeManager->invoke(cardRequest);
}

void App::onOpenVenue() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://venues/4ef0e7cf7beb5932d5bdeb4e");

	invokeManager->invoke(cardRequest);
}

void App::onOpenCheckin() {
	InvokeRequest cardRequest;
	cardRequest.setTarget("com.foursquare.blackberry.uri");
	cardRequest.setAction("bb.action.OPEN");
	cardRequest.setUri("foursquare://checkins/50a08609e4b04c46ea54446d");

	invokeManager->invoke(cardRequest);
}

