//-- Default empty project template
import bb.cascades 1.0

// creates one page with a label

Page {
    ScrollView {
        scrollViewProperties {
            scrollMode: ScrollMode.Vertical
        }
        Container {
            Button {
                id: showSSOButton
                text: "SSO"
                onCreationCompleted: {
                    showSSOButton.clicked.connect(app.onSSO);
                }
            }
            Button {
                id: showCardButton
                text: "Venue Search"
                onCreationCompleted: {
                    showCardButton.clicked.connect(app.onShowHelloCard);
                }
            }
            Button {
                id: showProfileButton
                text: "Show Profile"
                onCreationCompleted: {
                    showProfileButton.clicked.connect(app.onShowProfile);
                }
            }
            Button {
                id: showFriendsButton
                text: "Show Friends requests"
                onCreationCompleted: {
                    showFriendsButton.clicked.connect(app.onFriendRequests);
                }
            }
            Button {
                id: showPageSuggestionsButton
                text: "Show page suggestions"
                onCreationCompleted: {
                    showPageSuggestionsButton.clicked.connect(app.onPageSuggestions);
                }
            }
            Button {
                id: showFriendSuggestionsButton
                text: "Show friend suggestions"
                onCreationCompleted: {
                    showFriendSuggestionsButton.clicked.connect(app.onFriendSuggestions);
                }
            }
            Button {
                id: showCheckinReminderButton
                text: "Explore"
                onCreationCompleted: {
                    showCheckinReminderButton.clicked.connect(app.onCheckinReminder);
                }
            }
            Button {
                id: showAddFriendsButton
                text: "Show add friends"
                onCreationCompleted: {
                    showAddFriendsButton.clicked.connect(app.onAddFriends);
                }
            }
            Button {
                id: showOpenVenueButton
                text: "Open Venue"
                onCreationCompleted: {
                    showOpenVenueButton.clicked.connect(app.onOpenVenue);
                }
            }
            Button {
                id: showOpenCheckinButton
                text: "Open Checkin"
                onCreationCompleted: {
                    showOpenCheckinButton.clicked.connect(app.onOpenCheckin);
                }
            }
        }
    }
}
