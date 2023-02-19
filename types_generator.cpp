#include <string>
#include <memory>

struct User;
struct Chat;
struct Message;
struct MessageId;
struct MessageEntity;
struct PhotoSize;
struct Animation;
struct Audio;
struct Document;
struct Video;
struct VideoNote;
struct Voice;
struct Contact;
struct Dice;
struct PollOption;
struct PollAnswer;
struct Poll;
struct Location;
struct Venue;
struct WebAppData;
struct ProximityAlertTriggered;
struct MessageAutoDeleteTimerChanged;
struct ForumTopicCreated;
struct ForumTopicClosed;
struct ForumTopicEdited;
struct ForumTopicReopened;
struct GeneralForumTopicHidden;
struct GeneralForumTopicUnhidden;
struct UserShared;
struct ChatShared;
struct WriteAccessAllowed;
struct VideoChatScheduled;
struct VideoChatStarted;
struct VideoChatEnded;
struct VideoChatParticipantsInvited;
struct UserProfilePhotos;
struct File;
struct WebAppInfo;
struct ReplyKeyboardMarkup;
struct KeyboardButton;
struct KeyboardButtonRequestUser;
struct KeyboardButtonRequestChat;
struct KeyboardButtonPollType;
struct ReplyKeyboardRemove;
struct InlineKeyboardMarkup;
struct InlineKeyboardButton;
struct LoginUrl;
struct CallbackQuery;
struct ForceReply;
struct ChatPhoto;
struct ChatInviteLink;
struct ChatAdministratorRights;
struct ChatMember;
struct ChatMemberOwner;
struct ChatMemberAdministrator;
struct ChatMemberMember;
struct ChatMemberRestricted;
struct ChatMemberLeft;
struct ChatMemberBanned;
struct ChatMemberUpdated;
struct ChatJoinRequest;
struct ChatPermissions;
struct ChatLocation;
struct ForumTopic;
struct BotCommand;
struct BotCommandScope;
struct Determining list of commands;
struct BotCommandScopeDefault;
struct BotCommandScopeAllPrivateChats;
struct BotCommandScopeAllGroupChats;
struct BotCommandScopeAllChatAdministrators;
struct BotCommandScopeChat;
struct BotCommandScopeChatAdministrators;
struct BotCommandScopeChatMember;
struct MenuButton;
struct MenuButtonCommands;
struct MenuButtonWebApp;
struct MenuButtonDefault;
struct ResponseParameters;
struct InputMedia;
struct InputMediaPhoto;
struct InputMediaVideo;
struct InputMediaAnimation;
struct InputMediaAudio;
struct InputMediaDocument;
struct InputFile;
struct Sending files;
struct Inline mode objects;
struct Available methods;
struct getMe;
struct logOut;
struct close;
struct sendMessage;
struct Formatting options;
struct MarkdownV2 style;
struct HTML style;
struct Markdown style;
struct forwardMessage;
struct copyMessage;
struct sendPhoto;
struct sendAudio;
struct sendDocument;
struct sendVideo;
struct sendAnimation;
struct sendVoice;
struct sendVideoNote;
struct sendMediaGroup;
struct sendLocation;
struct editMessageLiveLocation;
struct stopMessageLiveLocation;
struct sendVenue;
struct sendContact;
struct sendPoll;
struct sendDice;
struct sendChatAction;
struct getUserProfilePhotos;
struct getFile;
struct banChatMember;
struct unbanChatMember;
struct restrictChatMember;
struct promoteChatMember;
struct setChatAdministratorCustomTitle;
struct banChatSenderChat;
struct unbanChatSenderChat;
struct setChatPermissions;
struct exportChatInviteLink;
struct createChatInviteLink;
struct editChatInviteLink;
struct revokeChatInviteLink;
struct approveChatJoinRequest;
struct declineChatJoinRequest;
struct setChatPhoto;
struct deleteChatPhoto;
struct setChatTitle;
struct setChatDescription;
struct pinChatMessage;
struct unpinChatMessage;
struct unpinAllChatMessages;
struct leaveChat;
struct getChat;
struct getChatAdministrators;
struct getChatMemberCount;
struct getChatMember;
struct setChatStickerSet;
struct deleteChatStickerSet;
struct getForumTopicIconStickers;
struct createForumTopic;
struct editForumTopic;
struct closeForumTopic;
struct reopenForumTopic;
struct deleteForumTopic;
struct unpinAllForumTopicMessages;
struct editGeneralForumTopic;
struct closeGeneralForumTopic;
struct reopenGeneralForumTopic;
struct hideGeneralForumTopic;
struct unhideGeneralForumTopic;
struct answerCallbackQuery;
struct setMyCommands;
struct deleteMyCommands;
struct getMyCommands;
struct setChatMenuButton;
struct getChatMenuButton;
struct setMyDefaultAdministratorRights;
struct getMyDefaultAdministratorRights;
struct Inline mode methods;
struct Updating messages;
struct editMessageText;
struct editMessageCaption;
struct editMessageMedia;
struct editMessageReplyMarkup;
struct stopPoll;
struct deleteMessage;
struct Stickers;
struct Sticker;
struct StickerSet;
struct MaskPosition;
struct sendSticker;
struct getStickerSet;
struct getCustomEmojiStickers;
struct uploadStickerFile;
struct createNewStickerSet;
struct addStickerToSet;
struct setStickerPositionInSet;
struct deleteStickerFromSet;
struct setStickerSetThumb;
struct Inline mode;
struct InlineQuery;
struct answerInlineQuery;
struct InlineQueryResult;
struct InlineQueryResultArticle;
struct InlineQueryResultPhoto;
struct InlineQueryResultGif;
struct InlineQueryResultMpeg4Gif;
struct InlineQueryResultVideo;
struct InlineQueryResultAudio;
struct InlineQueryResultVoice;
struct InlineQueryResultDocument;
struct InlineQueryResultLocation;
struct InlineQueryResultVenue;
struct InlineQueryResultContact;
struct InlineQueryResultGame;
struct InlineQueryResultCachedPhoto;
struct InlineQueryResultCachedGif;
struct InlineQueryResultCachedMpeg4Gif;
struct InlineQueryResultCachedSticker;
struct InlineQueryResultCachedDocument;
struct InlineQueryResultCachedVideo;
struct InlineQueryResultCachedVoice;
struct InlineQueryResultCachedAudio;
struct InputMessageContent;
struct InputTextMessageContent;
struct InputLocationMessageContent;
struct InputVenueMessageContent;
struct InputContactMessageContent;
struct InputInvoiceMessageContent;
struct ChosenInlineResult;
struct answerWebAppQuery;
struct SentWebAppMessage;
struct Payments;
struct sendInvoice;
struct createInvoiceLink;
struct answerShippingQuery;
struct answerPreCheckoutQuery;
struct LabeledPrice;
struct Invoice;
struct ShippingAddress;
struct OrderInfo;
struct ShippingOption;
struct SuccessfulPayment;
struct ShippingQuery;
struct PreCheckoutQuery;
struct Telegram Passport;
struct PassportData;
struct PassportFile;
struct EncryptedPassportElement;
struct EncryptedCredentials;
struct setPassportDataErrors;
struct PassportElementError;
struct PassportElementErrorDataField;
struct PassportElementErrorFrontSide;
struct PassportElementErrorReverseSide;
struct PassportElementErrorSelfie;
struct PassportElementErrorFile;
struct PassportElementErrorFiles;
struct PassportElementErrorTranslationFile;
struct PassportElementErrorTranslationFiles;
struct PassportElementErrorUnspecified;
struct Games;
struct sendGame;
struct Game;
struct CallbackGame;
struct setGameScore;
struct getGameHighScores;
struct GameHighScore;
//This object represents a Telegram user or bot.
struct User{
	int id;
	bool is_bot;
	std::string first_name;
	std::string last_name;
	std::string username;
	std::string language_code;
	bool is_premium;
	bool added_to_attachment_menu;
	bool can_join_groups;
	bool can_read_all_group_messages;
	bool supports_inline_queries;
};

//This object represents a chat.
struct Chat{
	int id;
	std::string type;
	std::string title;
	std::string username;
	std::string first_name;
	std::string last_name;
	bool is_forum;
	std::shared_ptr<ChatPhoto> photo;
	std::string active_usernames;
	std::string emoji_status_custom_emoji_id;
	std::string bio;
	bool has_private_forwards;
	bool has_restricted_voice_and_video_messages;
	bool join_to_send_messages;
	bool join_by_request;
	std::string description;
	std::string invite_link;
	std::shared_ptr<Message> pinned_message;
	std::shared_ptr<ChatPermissions> permissions;
	int slow_mode_delay;
	int message_auto_delete_time;
	bool has_aggressive_anti_spam_enabled;
	bool has_hidden_members;
	bool has_protected_content;
	std::string sticker_set_name;
	bool can_set_sticker_set;
	int linked_chat_id;
	std::shared_ptr<ChatLocation> location;
};

//This object represents a message.
struct Message{
	int message_id;
	int message_thread_id;
	std::shared_ptr<User> from;
	std::shared_ptr<Chat> sender_chat;
	int date;
	std::shared_ptr<Chat> chat;
	std::shared_ptr<User> forward_from;
	std::shared_ptr<Chat> forward_from_chat;
	int forward_from_message_id;
	std::string forward_signature;
	std::string forward_sender_name;
	int forward_date;
	bool is_topic_message;
	bool is_automatic_forward;
	std::shared_ptr<Message> reply_to_message;
	std::shared_ptr<User> via_bot;
	int edit_date;
	bool has_protected_content;
	std::string media_group_id;
	std::string author_signature;
	std::string text;
	std::shared_ptr<MessageEntity> entities;
	std::shared_ptr<Animation> animation;
	std::shared_ptr<Audio> audio;
	std::shared_ptr<Document> document;
	std::shared_ptr<PhotoSize> photo;
	std::shared_ptr<Sticker> sticker;
	std::shared_ptr<Video> video;
	std::shared_ptr<VideoNote> video_note;
	std::shared_ptr<Voice> voice;
	std::string caption;
	std::shared_ptr<MessageEntity> caption_entities;
	bool has_media_spoiler;
	std::shared_ptr<Contact> contact;
	std::shared_ptr<Dice> dice;
	std::shared_ptr<Game> game;
	std::shared_ptr<Poll> poll;
	std::shared_ptr<Venue> venue;
	std::shared_ptr<Location> location;
	std::shared_ptr<User> new_chat_members;
	std::shared_ptr<User> left_chat_member;
	std::string new_chat_title;
	std::shared_ptr<PhotoSize> new_chat_photo;
	bool delete_chat_photo;
	bool group_chat_created;
	bool supergroup_chat_created;
	bool channel_chat_created;
	std::shared_ptr<MessageAutoDeleteTimerChanged> message_auto_delete_timer_changed;
	int migrate_to_chat_id;
	int migrate_from_chat_id;
	std::shared_ptr<Message> pinned_message;
	std::shared_ptr<Invoice> invoice;
	std::shared_ptr<SuccessfulPayment> successful_payment;
	std::shared_ptr<UserShared> user_shared;
	std::shared_ptr<ChatShared> chat_shared;
	std::string connected_website;
	std::shared_ptr<WriteAccessAllowed> write_access_allowed;
	std::shared_ptr<PassportData> passport_data;
	std::shared_ptr<ProximityAlertTriggered> proximity_alert_triggered;
	std::shared_ptr<ForumTopicCreated> forum_topic_created;
	std::shared_ptr<ForumTopicEdited> forum_topic_edited;
	std::shared_ptr<ForumTopicClosed> forum_topic_closed;
	std::shared_ptr<ForumTopicReopened> forum_topic_reopened;
	std::shared_ptr<GeneralForumTopicHidden> general_forum_topic_hidden;
	std::shared_ptr<GeneralForumTopicUnhidden> general_forum_topic_unhidden;
	std::shared_ptr<VideoChatScheduled> video_chat_scheduled;
	std::shared_ptr<VideoChatStarted> video_chat_started;
	std::shared_ptr<VideoChatEnded> video_chat_ended;
	std::shared_ptr<VideoChatParticipantsInvited> video_chat_participants_invited;
	std::shared_ptr<WebAppData> web_app_data;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
};

//This object represents a unique message identifier.
struct MessageId{
	int message_id;
};

//This object represents one special entity in a text message. For example, hashtags, usernames, URLs, etc.
struct MessageEntity{
	std::string type;
	int offset;
	int length;
	std::string url;
	std::shared_ptr<User> user;
	std::string language;
	std::string custom_emoji_id;
};

//This object represents one size of a photo or a <a href="#document">file</a> / <a href="#sticker">sticker</a> thumbnail.
struct PhotoSize{
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int file_size;
};

//This object represents an animation file (GIF or H.264/MPEG-4 AVC video without sound).
struct Animation{
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int duration;
	std::shared_ptr<PhotoSize> thumb;
	std::string file_name;
	std::string mime_type;
	int file_size;
};

//This object represents an audio file to be treated as music by the Telegram clients.
struct Audio{
	std::string file_id;
	std::string file_unique_id;
	int duration;
	std::string performer;
	std::string title;
	std::string file_name;
	std::string mime_type;
	int file_size;
	std::shared_ptr<PhotoSize> thumb;
};

//This object represents a general file (as opposed to <a href="#photosize">photos</a>, <a href="#voice">voice messages</a> and <a href="#audio">audio files</a>).
struct Document{
	std::string file_id;
	std::string file_unique_id;
	std::shared_ptr<PhotoSize> thumb;
	std::string file_name;
	std::string mime_type;
	int file_size;
};

//This object represents a video file.
struct Video{
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int duration;
	std::shared_ptr<PhotoSize> thumb;
	std::string file_name;
	std::string mime_type;
	int file_size;
};

//This object represents a <a href="https://telegram.org/blog/video-messages-and-telescope">video message</a> (available in Telegram apps as of <a href="https://telegram.org/blog/video-messages-and-telescope">v.4.0</a>).
struct VideoNote{
	std::string file_id;
	std::string file_unique_id;
	int length;
	int duration;
	std::shared_ptr<PhotoSize> thumb;
	int file_size;
};

//This object represents a voice note.
struct Voice{
	std::string file_id;
	std::string file_unique_id;
	int duration;
	std::string mime_type;
	int file_size;
};

//This object represents a phone contact.
struct Contact{
	std::string phone_number;
	std::string first_name;
	std::string last_name;
	int user_id;
	std::string vcard;
};

//This object represents an animated emoji that displays a random value.
struct Dice{
	std::string emoji;
	int value;
};

//This object contains information about one answer option in a poll.
struct PollOption{
	std::string text;
	int voter_count;
};

//This object represents an answer of a user in a non-anonymous poll.
struct PollAnswer{
	std::string poll_id;
	std::shared_ptr<User> user;
	int option_ids;
};

//This object contains information about a poll.
struct Poll{
	std::string id;
	std::string question;
	std::shared_ptr<PollOption> options;
	int total_voter_count;
	bool is_closed;
	bool is_anonymous;
	std::string type;
	bool allows_multiple_answers;
	int correct_option_id;
	std::string explanation;
	std::shared_ptr<MessageEntity> explanation_entities;
	int open_period;
	int close_date;
};

//This object represents a point on the map.
struct Location{
	float longitude;
	float latitude;
	float horizontal_accuracy;
	int live_period;
	int heading;
	int proximity_alert_radius;
};

//This object represents a venue.
struct Venue{
	std::shared_ptr<Location> location;
	std::string title;
	std::string address;
	std::string foursquare_id;
	std::string foursquare_type;
	std::string google_place_id;
	std::string google_place_type;
};

//Describes data sent from a <a href="/bots/webapps">Web App</a> to the bot.
struct WebAppData{
	std::string data;
	std::string button_text;
};

//This object represents the content of a service message, sent whenever a user in the chat triggers a proximity alert set by another user.
struct ProximityAlertTriggered{
	std::shared_ptr<User> traveler;
	std::shared_ptr<User> watcher;
	int distance;
};

//This object represents a service message about a change in auto-delete timer settings.
struct MessageAutoDeleteTimerChanged{
	int message_auto_delete_time;
};

//This object represents a service message about a new forum topic created in the chat.
struct ForumTopicCreated{
	std::string name;
	int icon_color;
	std::string icon_custom_emoji_id;
};

//This object represents a service message about a forum topic closed in the chat. Currently holds no information.
struct ForumTopicClosed{
};

//This object represents a service message about an edited forum topic.
struct ForumTopicEdited{
	std::string name;
	std::string icon_custom_emoji_id;
};

//This object represents a service message about a forum topic reopened in the chat. Currently holds no information.
struct ForumTopicReopened{
};

//This object represents a service message about General forum topic hidden in the chat. Currently holds no information.
struct GeneralForumTopicHidden{
};

//This object represents a service message about General forum topic unhidden in the chat. Currently holds no information.
struct GeneralForumTopicUnhidden{
};

//This object contains information about the user whose identifier was shared with the bot using a <a href="#keyboardbuttonrequestuser">KeyboardButtonRequestUser</a> button.
struct UserShared{
	int request_id;
	int user_id;
};

//This object contains information about the chat whose identifier was shared with the bot using a <a href="#keyboardbuttonrequestchat">KeyboardButtonRequestChat</a> button.
struct ChatShared{
	int request_id;
	int chat_id;
};

//This object represents a service message about a user allowing a bot added to the attachment menu to write messages. Currently holds no information.
struct WriteAccessAllowed{
};

//This object represents a service message about a video chat scheduled in the chat.
struct VideoChatScheduled{
	int start_date;
};

//This object represents a service message about a video chat started in the chat. Currently holds no information.
struct VideoChatStarted{
};

//This object represents a service message about a video chat ended in the chat.
struct VideoChatEnded{
	int duration;
};

//This object represents a service message about new members invited to a video chat.
struct VideoChatParticipantsInvited{
	std::shared_ptr<User> users;
};

//This object represent a user&#39;s profile pictures.
struct UserProfilePhotos{
	int total_count;
	std::shared_ptr<PhotoSize> photos;
};

//This object represents a file ready to be downloaded. The file can be downloaded via the link <code>https://api.telegram.org/file/bot&lt;token&gt;/&lt;file_path&gt;</code>. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling <a href="#getfile">getFile</a>.
struct File{
	std::string file_id;
	std::string file_unique_id;
	int file_size;
	std::string file_path;
};

//Describes a <a href="/bots/webapps">Web App</a>.
struct WebAppInfo{
	std::string url;
};

//This object represents a <a href="/bots/features#keyboards">custom keyboard</a> with reply options (see <a href="/bots/features#keyboards">Introduction to bots</a> for details and examples).
struct ReplyKeyboardMarkup{
	std::shared_ptr<KeyboardButton> keyboard;
	bool is_persistent;
	bool resize_keyboard;
	bool one_time_keyboard;
	std::string input_field_placeholder;
	bool selective;
};

//This object represents one button of the reply keyboard. For simple text buttons, <em>String</em> can be used instead of this object to specify the button text. The optional fields <em>web_app</em>, <em>request_user</em>, <em>request_chat</em>, <em>request_contact</em>, <em>request_location</em>, and <em>request_poll</em> are mutually exclusive.
struct KeyboardButton{
	std::string text;
	std::shared_ptr<KeyboardButtonRequestUser> request_user;
	std::shared_ptr<KeyboardButtonRequestChat> request_chat;
	bool request_contact;
	bool request_location;
	std::shared_ptr<KeyboardButtonPollType> request_poll;
	std::shared_ptr<WebAppInfo> web_app;
};

//This object defines the criteria used to request a suitable user. The identifier of the selected user will be shared with the bot when the corresponding button is pressed.
struct KeyboardButtonRequestUser{
	int request_id;
	bool user_is_bot;
	bool user_is_premium;
};

//This object defines the criteria used to request a suitable chat. The identifier of the selected chat will be shared with the bot when the corresponding button is pressed.
struct KeyboardButtonRequestChat{
	int request_id;
	bool chat_is_channel;
	bool chat_is_forum;
	bool chat_has_username;
	bool chat_is_created;
	std::shared_ptr<ChatAdministratorRights> user_administrator_rights;
	std::shared_ptr<ChatAdministratorRights> bot_administrator_rights;
	bool bot_is_member;
};

//This object represents type of a poll, which is allowed to be created and sent when the corresponding button is pressed.
struct KeyboardButtonPollType{
	std::string type;
};

//Upon receiving a message with this object, Telegram clients will remove the current custom keyboard and display the default letter-keyboard. By default, custom keyboards are displayed until a new keyboard is sent by a bot. An exception is made for one-time keyboards that are hidden immediately after the user presses a button (see <a href="#replykeyboardmarkup">ReplyKeyboardMarkup</a>).
struct ReplyKeyboardRemove{
};

//This object represents an <a href="/bots/features#inline-keyboards">inline keyboard</a> that appears right next to the message it belongs to.
struct InlineKeyboardMarkup{
	std::shared_ptr<InlineKeyboardButton> inline_keyboard;
};

//This object represents one button of an inline keyboard. You <strong>must</strong> use exactly one of the optional fields.
struct InlineKeyboardButton{
	std::string text;
	std::string url;
	std::string callback_data;
	std::shared_ptr<WebAppInfo> web_app;
	std::shared_ptr<LoginUrl> login_url;
	std::string switch_inline_query;
	std::string switch_inline_query_current_chat;
	std::shared_ptr<CallbackGame> callback_game;
	bool pay;
};

//This object represents a parameter of the inline keyboard button used to automatically authorize a user. Serves as a great replacement for the <a href="/widgets/login">Telegram Login Widget</a> when the user is coming from Telegram. All the user needs to do is tap/click a button and confirm that they want to log in:
struct LoginUrl{
	std::string url;
	std::string forward_text;
	std::string bot_username;
	bool request_write_access;
};

//This object represents an incoming callback query from a callback button in an <a href="/bots/features#inline-keyboards">inline keyboard</a>. If the button that originated the query was attached to a message sent by the bot, the field <em>message</em> will be present. If the button was attached to a message sent via the bot (in <a href="#inline-mode">inline mode</a>), the field <em>inline_message_id</em> will be present. Exactly one of the fields <em>data</em> or <em>game_short_name</em> will be present.
struct CallbackQuery{
	std::string id;
	std::shared_ptr<User> from;
	std::shared_ptr<Message> message;
	std::string inline_message_id;
	std::string chat_instance;
	std::string data;
	std::string game_short_name;
};

//Upon receiving a message with this object, Telegram clients will display a reply interface to the user (act as if the user has selected the bot&#39;s message and tapped &#39;Reply&#39;). This can be extremely useful if you want to create user-friendly step-by-step interfaces without having to sacrifice <a href="/bots/features#privacy-mode">privacy mode</a>.
struct ForceReply{
};

//This object represents a chat photo.
struct ChatPhoto{
	std::string small_file_id;
	std::string small_file_unique_id;
	std::string big_file_id;
	std::string big_file_unique_id;
};

//Represents an invite link for a chat.
struct ChatInviteLink{
	std::string invite_link;
	std::shared_ptr<User> creator;
	bool creates_join_request;
	bool is_primary;
	bool is_revoked;
	std::string name;
	int expire_date;
	int member_limit;
	int pending_join_request_count;
};

//Represents the rights of an administrator in a chat.
struct ChatAdministratorRights{
	bool is_anonymous;
	bool can_manage_chat;
	bool can_delete_messages;
	bool can_manage_video_chats;
	bool can_restrict_members;
	bool can_promote_members;
	bool can_change_info;
	bool can_invite_users;
	bool can_post_messages;
	bool can_edit_messages;
	bool can_pin_messages;
	bool can_manage_topics;
};

//This object contains information about one member of a chat. Currently, the following 6 types of chat members are supported:
struct ChatMember{
	std::string status;
	std::shared_ptr<User> user;
	bool is_anonymous;
	std::string custom_title;
};

//Represents a <a href="#chatmember">chat member</a> that owns the chat and has all administrator privileges.
struct ChatMemberOwner{
	std::string status;
	std::shared_ptr<User> user;
	bool is_anonymous;
	std::string custom_title;
};

//Represents a <a href="#chatmember">chat member</a> that has some additional privileges.
struct ChatMemberAdministrator{
	std::string status;
	std::shared_ptr<User> user;
	bool can_be_edited;
	bool is_anonymous;
	bool can_manage_chat;
	bool can_delete_messages;
	bool can_manage_video_chats;
	bool can_restrict_members;
	bool can_promote_members;
	bool can_change_info;
	bool can_invite_users;
	bool can_post_messages;
	bool can_edit_messages;
	bool can_pin_messages;
	bool can_manage_topics;
	std::string custom_title;
};

//Represents a <a href="#chatmember">chat member</a> that has no additional privileges or restrictions.
struct ChatMemberMember{
	std::string status;
	std::shared_ptr<User> user;
};

//Represents a <a href="#chatmember">chat member</a> that is under certain restrictions in the chat. Supergroups only.
struct ChatMemberRestricted{
	std::string status;
	std::shared_ptr<User> user;
	bool is_member;
	bool can_send_messages;
	bool can_send_audios;
	bool can_send_documents;
	bool can_send_photos;
	bool can_send_videos;
	bool can_send_video_notes;
	bool can_send_voice_notes;
	bool can_send_polls;
	bool can_send_other_messages;
	bool can_add_web_page_previews;
	bool can_change_info;
	bool can_invite_users;
	bool can_pin_messages;
	bool can_manage_topics;
	int until_date;
};

//Represents a <a href="#chatmember">chat member</a> that isn&#39;t currently a member of the chat, but may join it themselves.
struct ChatMemberLeft{
	std::string status;
	std::shared_ptr<User> user;
};

//Represents a <a href="#chatmember">chat member</a> that was banned in the chat and can&#39;t return to the chat or view chat messages.
struct ChatMemberBanned{
	std::string status;
	std::shared_ptr<User> user;
	int until_date;
};

//This object represents changes in the status of a chat member.
struct ChatMemberUpdated{
	std::shared_ptr<Chat> chat;
	std::shared_ptr<User> from;
	int date;
	std::shared_ptr<ChatMember> old_chat_member;
	std::shared_ptr<ChatMember> new_chat_member;
	std::shared_ptr<ChatInviteLink> invite_link;
};

//Represents a join request sent to a chat.
struct ChatJoinRequest{
	std::shared_ptr<Chat> chat;
	std::shared_ptr<User> from;
	int user_chat_id;
	int date;
	std::string bio;
	std::shared_ptr<ChatInviteLink> invite_link;
};

//Describes actions that a non-administrator user is allowed to take in a chat.
struct ChatPermissions{
	bool can_send_messages;
	bool can_send_audios;
	bool can_send_documents;
	bool can_send_photos;
	bool can_send_videos;
	bool can_send_video_notes;
	bool can_send_voice_notes;
	bool can_send_polls;
	bool can_send_other_messages;
	bool can_add_web_page_previews;
	bool can_change_info;
	bool can_invite_users;
	bool can_pin_messages;
	bool can_manage_topics;
};

//Represents a location to which a chat is connected.
struct ChatLocation{
	std::shared_ptr<Location> location;
	std::string address;
};

//This object represents a forum topic.
struct ForumTopic{
	int message_thread_id;
	std::string name;
	int icon_color;
	std::string icon_custom_emoji_id;
};

//This object represents a bot command.
struct BotCommand{
	std::string command;
	std::string description;
};

//This object represents the scope to which bot commands are applied. Currently, the following 7 scopes are supported:
struct BotCommandScope{
	std::string type;
};

//The following algorithm is used to determine the list of commands for a particular user viewing the bot menu. The first list of commands which is set is returned:
struct Determining list of commands{
};

//Represents the default <a href="#botcommandscope">scope</a> of bot commands. Default commands are used if no commands with a <a href="#determining-list-of-commands">narrower scope</a> are specified for the user.
struct BotCommandScopeDefault{
	std::string type;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all private chats.
struct BotCommandScopeAllPrivateChats{
	std::string type;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all group and supergroup chats.
struct BotCommandScopeAllGroupChats{
	std::string type;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all group and supergroup chat administrators.
struct BotCommandScopeAllChatAdministrators{
	std::string type;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering a specific chat.
struct BotCommandScopeChat{
	std::string type;
	int chat_id;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all administrators of a specific group or supergroup chat.
struct BotCommandScopeChatAdministrators{
	std::string type;
	int chat_id;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering a specific member of a group or supergroup chat.
struct BotCommandScopeChatMember{
	std::string type;
	int chat_id;
	int user_id;
};

//This object describes the bot&#39;s menu button in a private chat. It should be one of
struct MenuButton{
	std::string type;
};

//Represents a menu button, which opens the bot&#39;s list of commands.
struct MenuButtonCommands{
	std::string type;
};

//Represents a menu button, which launches a <a href="/bots/webapps">Web App</a>.
struct MenuButtonWebApp{
	std::string type;
	std::string text;
	std::shared_ptr<WebAppInfo> web_app;
};

//Describes that no specific value for the menu button was set.
struct MenuButtonDefault{
	std::string type;
};

//Describes why a request was unsuccessful.
struct ResponseParameters{
	int migrate_to_chat_id;
	int retry_after;
};

//This object represents the content of a media message to be sent. It should be one of
struct InputMedia{
	std::string type;
	std::string media;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	bool has_spoiler;
};

//Represents a photo to be sent.
struct InputMediaPhoto{
	std::string type;
	std::string media;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	bool has_spoiler;
};

//Represents a video to be sent.
struct InputMediaVideo{
	std::string type;
	std::string media;
	std::string thumb;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	int width;
	int height;
	int duration;
	bool supports_streaming;
	bool has_spoiler;
};

//Represents an animation file (GIF or H.264/MPEG-4 AVC video without sound) to be sent.
struct InputMediaAnimation{
	std::string type;
	std::string media;
	std::string thumb;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	int width;
	int height;
	int duration;
	bool has_spoiler;
};

//Represents an audio file to be treated as music to be sent.
struct InputMediaAudio{
	std::string type;
	std::string media;
	std::string thumb;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	int duration;
	std::string performer;
	std::string title;
};

//Represents a general file to be sent.
struct InputMediaDocument{
	std::string type;
	std::string media;
	std::string thumb;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	bool disable_content_type_detection;
};

//This object represents the contents of a file to be uploaded. Must be posted using multipart/form-data in the usual way that files are uploaded via the browser.
struct InputFile{
	int chat_id;
	int message_thread_id;
	std::string text;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> entities;
	bool disable_web_page_preview;
	bool disable_notification;
	bool protect_content;
	int reply_to_message_id;
	bool allow_sending_without_reply;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
};

//There are three ways to send files (photos, stickers, audio, media, etc.):
struct Sending files{
};

//Objects and methods used in the inline mode are described in the <a href="#inline-mode">Inline mode section</a>.
struct Inline mode objects{
};

//All methods in the Bot API are case-insensitive. We support <strong>GET</strong> and <strong>POST</strong> HTTP methods. Use either <a href="https://en.wikipedia.org/wiki/Query_string">URL query string</a> or <em>application/json</em> or <em>application/x-www-form-urlencoded</em> or <em>multipart/form-data</em> for passing parameters in Bot API requests.<br>On successful call, a JSON-object containing the result will be returned.
struct Available methods{
};

//A simple method for testing your bot&#39;s authentication token. Requires no parameters. Returns basic information about the bot in form of a <a href="#user">User</a> object.
struct getMe{
};

//Use this method to log out from the cloud Bot API server before launching the bot locally. You <strong>must</strong> log out the bot before running it locally, otherwise there is no guarantee that the bot will receive updates. After a successful call, you can immediately log in on a local server, but will not be able to log in back to the cloud Bot API server for 10 minutes. Returns <em>True</em> on success. Requires no parameters.
struct logOut{
};

//Use this method to close the bot instance before moving it from one local server to another. You need to delete the webhook before calling this method to ensure that the bot isn&#39;t launched again after server restart. The method will return error 429 in the first 10 minutes after the bot is launched. Returns <em>True</em> on success. Requires no parameters.
struct close{
};

//Use this method to send text messages. On success, the sent <a href="#message">Message</a> is returned.
struct sendMessage{
};

//The Bot API supports basic formatting for messages. You can use bold, italic, underlined, strikethrough, and spoiler text, as well as inline links and pre-formatted code in your bots&#39; messages. Telegram clients will render them accordingly. You can specify text entities directly, or use markdown-style or HTML-style formatting.
struct Formatting options{
};

//To use this mode, pass <em>MarkdownV2</em> in the <em>parse_mode</em> field. Use the following syntax in your message:
struct MarkdownV2 style{
};

//To use this mode, pass <em>HTML</em> in the <em>parse_mode</em> field. The following tags are currently supported:
struct HTML style{
};

//This is a legacy mode, retained for backward compatibility. To use this mode, pass <em>Markdown</em> in the <em>parse_mode</em> field. Use the following syntax in your message:
struct Markdown style{
};

//Use this method to forward messages of any kind. Service messages can&#39;t be forwarded. On success, the sent <a href="#message">Message</a> is returned.
struct forwardMessage{
};

//Use this method to copy messages of any kind. Service messages and invoice messages can&#39;t be copied. A quiz <a href="#poll">poll</a> can be copied only if the value of the field <em>correct_option_id</em> is known to the bot. The method is analogous to the method <a href="#forwardmessage">forwardMessage</a>, but the copied message doesn&#39;t have a link to the original message. Returns the <a href="#messageid">MessageId</a> of the sent message on success.
struct copyMessage{
};

//Use this method to send photos. On success, the sent <a href="#message">Message</a> is returned.
struct sendPhoto{
};

//Use this method to send audio files, if you want Telegram clients to display them in the music player. Your audio must be in the .MP3 or .M4A format. On success, the sent <a href="#message">Message</a> is returned. Bots can currently send audio files of up to 50 MB in size, this limit may be changed in the future.
struct sendAudio{
};

//Use this method to send general files. On success, the sent <a href="#message">Message</a> is returned. Bots can currently send files of any type of up to 50 MB in size, this limit may be changed in the future.
struct sendDocument{
};

//Use this method to send video files, Telegram clients support MPEG4 videos (other formats may be sent as <a href="#document">Document</a>). On success, the sent <a href="#message">Message</a> is returned. Bots can currently send video files of up to 50 MB in size, this limit may be changed in the future.
struct sendVideo{
};

//Use this method to send animation files (GIF or H.264/MPEG-4 AVC video without sound). On success, the sent <a href="#message">Message</a> is returned. Bots can currently send animation files of up to 50 MB in size, this limit may be changed in the future.
struct sendAnimation{
};

//Use this method to send audio files, if you want Telegram clients to display the file as a playable voice message. For this to work, your audio must be in an .OGG file encoded with OPUS (other formats may be sent as <a href="#audio">Audio</a> or <a href="#document">Document</a>). On success, the sent <a href="#message">Message</a> is returned. Bots can currently send voice messages of up to 50 MB in size, this limit may be changed in the future.
struct sendVoice{
};

//As of <a href="https://telegram.org/blog/video-messages-and-telescope">v.4.0</a>, Telegram clients support rounded square MPEG4 videos of up to 1 minute long. Use this method to send video messages. On success, the sent <a href="#message">Message</a> is returned.
struct sendVideoNote{
};

//Use this method to send a group of photos, videos, documents or audios as an album. Documents and audio files can be only grouped in an album with messages of the same type. On success, an array of <a href="#message">Messages</a> that were sent is returned.
struct sendMediaGroup{
};

//Use this method to send point on the map. On success, the sent <a href="#message">Message</a> is returned.
struct sendLocation{
};

//Use this method to edit live location messages. A location can be edited until its <em>live_period</em> expires or editing is explicitly disabled by a call to <a href="#stopmessagelivelocation">stopMessageLiveLocation</a>. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
struct editMessageLiveLocation{
};

//Use this method to stop updating a live location message before <em>live_period</em> expires. On success, if the message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
struct stopMessageLiveLocation{
};

//Use this method to send information about a venue. On success, the sent <a href="#message">Message</a> is returned.
struct sendVenue{
};

//Use this method to send phone contacts. On success, the sent <a href="#message">Message</a> is returned.
struct sendContact{
};

//Use this method to send a native poll. On success, the sent <a href="#message">Message</a> is returned.
struct sendPoll{
};

//Use this method to send an animated emoji that will display a random value. On success, the sent <a href="#message">Message</a> is returned.
struct sendDice{
};

//Use this method when you need to tell the user that something is happening on the bot&#39;s side. The status is set for 5 seconds or less (when a message arrives from your bot, Telegram clients clear its typing status). Returns <em>True</em> on success.
struct sendChatAction{
};

//Use this method to get a list of profile pictures for a user. Returns a <a href="#userprofilephotos">UserProfilePhotos</a> object.
struct getUserProfilePhotos{
};

//Use this method to get basic information about a file and prepare it for downloading. For the moment, bots can download files of up to 20MB in size. On success, a <a href="#file">File</a> object is returned. The file can then be downloaded via the link <code>https://api.telegram.org/file/bot&lt;token&gt;/&lt;file_path&gt;</code>, where <code>&lt;file_path&gt;</code> is taken from the response. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling <a href="#getfile">getFile</a> again.
struct getFile{
};

//Use this method to ban a user in a group, a supergroup or a channel. In the case of supergroups and channels, the user will not be able to return to the chat on their own using invite links, etc., unless <a href="#unbanchatmember">unbanned</a> first. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
struct banChatMember{
};

//Use this method to unban a previously banned user in a supergroup or channel. The user will <strong>not</strong> return to the group or channel automatically, but will be able to join via link, etc. The bot must be an administrator for this to work. By default, this method guarantees that after the call the user is not a member of the chat, but will be able to join it. So if the user is a member of the chat they will also be <strong>removed</strong> from the chat. If you don&#39;t want this, use the parameter <em>only_if_banned</em>. Returns <em>True</em> on success.
struct unbanChatMember{
};

//Use this method to restrict a user in a supergroup. The bot must be an administrator in the supergroup for this to work and must have the appropriate administrator rights. Pass <em>True</em> for all permissions to lift restrictions from a user. Returns <em>True</em> on success.
struct restrictChatMember{
};

//Use this method to promote or demote a user in a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Pass <em>False</em> for all boolean parameters to demote a user. Returns <em>True</em> on success.
struct promoteChatMember{
};

//Use this method to set a custom title for an administrator in a supergroup promoted by the bot. Returns <em>True</em> on success.
struct setChatAdministratorCustomTitle{
};

//Use this method to ban a channel chat in a supergroup or a channel. Until the chat is <a href="#unbanchatsenderchat">unbanned</a>, the owner of the banned chat won&#39;t be able to send messages on behalf of <strong>any of their channels</strong>. The bot must be an administrator in the supergroup or channel for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
struct banChatSenderChat{
};

//Use this method to unban a previously banned channel chat in a supergroup or channel. The bot must be an administrator for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
struct unbanChatSenderChat{
};

//Use this method to set default chat permissions for all members. The bot must be an administrator in the group or a supergroup for this to work and must have the <em>can_restrict_members</em> administrator rights. Returns <em>True</em> on success.
struct setChatPermissions{
};

//Use this method to generate a new primary invite link for a chat; any previously generated primary link is revoked. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the new invite link as <em>String</em> on success.
struct exportChatInviteLink{
};

//Use this method to create an additional invite link for a chat. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. The link can be revoked using the method <a href="#revokechatinvitelink">revokeChatInviteLink</a>. Returns the new invite link as <a href="#chatinvitelink">ChatInviteLink</a> object.
struct createChatInviteLink{
};

//Use this method to edit a non-primary invite link created by the bot. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the edited invite link as a <a href="#chatinvitelink">ChatInviteLink</a> object.
struct editChatInviteLink{
};

//Use this method to revoke an invite link created by the bot. If the primary link is revoked, a new link is automatically generated. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the revoked invite link as <a href="#chatinvitelink">ChatInviteLink</a> object.
struct revokeChatInviteLink{
};

//Use this method to approve a chat join request. The bot must be an administrator in the chat for this to work and must have the <em>can_invite_users</em> administrator right. Returns <em>True</em> on success.
struct approveChatJoinRequest{
};

//Use this method to decline a chat join request. The bot must be an administrator in the chat for this to work and must have the <em>can_invite_users</em> administrator right. Returns <em>True</em> on success.
struct declineChatJoinRequest{
};

//Use this method to set a new profile photo for the chat. Photos can&#39;t be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
struct setChatPhoto{
};

//Use this method to delete a chat photo. Photos can&#39;t be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
struct deleteChatPhoto{
};

//Use this method to change the title of a chat. Titles can&#39;t be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
struct setChatTitle{
};

//Use this method to change the description of a group, a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
struct setChatDescription{
};

//Use this method to add a message to the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the &#39;can_pin_messages&#39; administrator right in a supergroup or &#39;can_edit_messages&#39; administrator right in a channel. Returns <em>True</em> on success.
struct pinChatMessage{
};

//Use this method to remove a message from the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the &#39;can_pin_messages&#39; administrator right in a supergroup or &#39;can_edit_messages&#39; administrator right in a channel. Returns <em>True</em> on success.
struct unpinChatMessage{
};

//Use this method to clear the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the &#39;can_pin_messages&#39; administrator right in a supergroup or &#39;can_edit_messages&#39; administrator right in a channel. Returns <em>True</em> on success.
struct unpinAllChatMessages{
};

//Use this method for your bot to leave a group, supergroup or channel. Returns <em>True</em> on success.
struct leaveChat{
};

//Use this method to get up to date information about the chat (current name of the user for one-on-one conversations, current username of a user, group or channel, etc.). Returns a <a href="#chat">Chat</a> object on success.
struct getChat{
};

//Use this method to get a list of administrators in a chat, which aren&#39;t bots. Returns an Array of <a href="#chatmember">ChatMember</a> objects.
struct getChatAdministrators{
};

//Use this method to get the number of members in a chat. Returns <em>Int</em> on success.
struct getChatMemberCount{
};

//Use this method to get information about a member of a chat. The method is only guaranteed to work for other users if the bot is an administrator in the chat. Returns a <a href="#chatmember">ChatMember</a> object on success.
struct getChatMember{
};

//Use this method to set a new group sticker set for a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field <em>can_set_sticker_set</em> optionally returned in <a href="#getchat">getChat</a> requests to check if the bot can use this method. Returns <em>True</em> on success.
struct setChatStickerSet{
};

//Use this method to delete a group sticker set from a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field <em>can_set_sticker_set</em> optionally returned in <a href="#getchat">getChat</a> requests to check if the bot can use this method. Returns <em>True</em> on success.
struct deleteChatStickerSet{
};

//Use this method to get custom emoji stickers, which can be used as a forum topic icon by any user. Requires no parameters. Returns an Array of <a href="#sticker">Sticker</a> objects.
struct getForumTopicIconStickers{
};

//Use this method to create a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. Returns information about the created topic as a <a href="#forumtopic">ForumTopic</a> object.
struct createForumTopic{
};

//Use this method to edit name and icon of a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have <em>can_manage_topics</em> administrator rights, unless it is the creator of the topic. Returns <em>True</em> on success.
struct editForumTopic{
};

//Use this method to close an open topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights, unless it is the creator of the topic. Returns <em>True</em> on success.
struct closeForumTopic{
};

//Use this method to reopen a closed topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights, unless it is the creator of the topic. Returns <em>True</em> on success.
struct reopenForumTopic{
};

//Use this method to delete a forum topic along with all its messages in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_delete_messages</em> administrator rights. Returns <em>True</em> on success.
struct deleteForumTopic{
};

//Use this method to clear the list of pinned messages in a forum topic. The bot must be an administrator in the chat for this to work and must have the <em>can_pin_messages</em> administrator right in the supergroup. Returns <em>True</em> on success.
struct unpinAllForumTopicMessages{
};

//Use this method to edit the name of the &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have <em>can_manage_topics</em> administrator rights. Returns <em>True</em> on success.
struct editGeneralForumTopic{
};

//Use this method to close an open &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. Returns <em>True</em> on success.
struct closeGeneralForumTopic{
};

//Use this method to reopen a closed &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. The topic will be automatically unhidden if it was hidden. Returns <em>True</em> on success.
struct reopenGeneralForumTopic{
};

//Use this method to hide the &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. The topic will be automatically closed if it was open. Returns <em>True</em> on success.
struct hideGeneralForumTopic{
};

//Use this method to unhide the &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. Returns <em>True</em> on success.
struct unhideGeneralForumTopic{
};

//Use this method to send answers to callback queries sent from <a href="/bots/features#inline-keyboards">inline keyboards</a>. The answer will be displayed to the user as a notification at the top of the chat screen or as an alert. On success, <em>True</em> is returned.
struct answerCallbackQuery{
};

//Use this method to change the list of the bot&#39;s commands. See <a href="/bots/features#commands">this manual</a> for more details about bot commands. Returns <em>True</em> on success.
struct setMyCommands{
};

//Use this method to delete the list of the bot&#39;s commands for the given scope and user language. After deletion, <a href="#determining-list-of-commands">higher level commands</a> will be shown to affected users. Returns <em>True</em> on success.
struct deleteMyCommands{
};

//Use this method to get the current list of the bot&#39;s commands for the given scope and user language. Returns an Array of <a href="#botcommand">BotCommand</a> objects. If commands aren&#39;t set, an empty list is returned.
struct getMyCommands{
};

//Use this method to change the bot&#39;s menu button in a private chat, or the default menu button. Returns <em>True</em> on success.
struct setChatMenuButton{
};

//Use this method to get the current value of the bot&#39;s menu button in a private chat, or the default menu button. Returns <a href="#menubutton">MenuButton</a> on success.
struct getChatMenuButton{
};

//Use this method to change the default administrator rights requested by the bot when it&#39;s added as an administrator to groups or channels. These rights will be suggested to users, but they are are free to modify the list before adding the bot. Returns <em>True</em> on success.
struct setMyDefaultAdministratorRights{
};

//Use this method to get the current default administrator rights of the bot. Returns <a href="#chatadministratorrights">ChatAdministratorRights</a> on success.
struct getMyDefaultAdministratorRights{
};

//Methods and objects used in the inline mode are described in the <a href="#inline-mode">Inline mode section</a>.
struct Inline mode methods{
};

//The following methods allow you to change an existing message in the message history instead of sending a new one with a result of an action. This is most useful for messages with <a href="/bots/features#inline-keyboards">inline keyboards</a> using callback queries, but can also help reduce clutter in conversations with regular chat bots.
struct Updating messages{
};

//Use this method to edit text and <a href="#games">game</a> messages. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
struct editMessageText{
};

//Use this method to edit captions of messages. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
struct editMessageCaption{
};

//Use this method to edit animation, audio, document, photo, or video messages. If a message is part of a message album, then it can be edited only to an audio for audio albums, only to a document for document albums and to a photo or a video otherwise. When an inline message is edited, a new file can&#39;t be uploaded; use a previously uploaded file via its file_id or specify a URL. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
struct editMessageMedia{
};

//Use this method to edit only the reply markup of messages. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
struct editMessageReplyMarkup{
};

//Use this method to stop a poll which was sent by the bot. On success, the stopped <a href="#poll">Poll</a> is returned.
struct stopPoll{
};

//Use this method to delete a message, including service messages, with the following limitations:<br>- A message can only be deleted if it was sent less than 48 hours ago.<br>- Service messages about a supergroup, channel, or forum topic creation can&#39;t be deleted.<br>- A dice message in a private chat can only be deleted if it was sent more than 24 hours ago.<br>- Bots can delete outgoing messages in private chats, groups, and supergroups.<br>- Bots can delete incoming messages in private chats.<br>- Bots granted <em>can_post_messages</em> permissions can delete outgoing messages in channels.<br>- If the bot is an administrator of a group, it can delete any message there.<br>- If the bot has <em>can_delete_messages</em> permission in a supergroup or a channel, it can delete any message there.<br>Returns <em>True</em> on success.
struct deleteMessage{
};

//The following methods and objects allow your bot to handle stickers and sticker sets.
struct Stickers{
};

//This object represents a sticker.
struct Sticker{
	std::string file_id;
	std::string file_unique_id;
	std::string type;
	int width;
	int height;
	bool is_animated;
	bool is_video;
	std::shared_ptr<PhotoSize> thumb;
	std::string emoji;
	std::string set_name;
	std::shared_ptr<File> premium_animation;
	std::shared_ptr<MaskPosition> mask_position;
	std::string custom_emoji_id;
	int file_size;
};

//This object represents a sticker set.
struct StickerSet{
	std::string name;
	std::string title;
	std::string sticker_type;
	bool is_animated;
	bool is_video;
	std::shared_ptr<Sticker> stickers;
	std::shared_ptr<PhotoSize> thumb;
};

//This object describes the position on faces where a mask should be placed by default.
struct MaskPosition{
	std::string point;
	float x_shift;
	float y_shift;
	float scale;
};

//Use this method to send static .WEBP, <a href="https://telegram.org/blog/animated-stickers">animated</a> .TGS, or <a href="https://telegram.org/blog/video-stickers-better-reactions">video</a> .WEBM stickers. On success, the sent <a href="#message">Message</a> is returned.
struct sendSticker{
};

//Use this method to get a sticker set. On success, a <a href="#stickerset">StickerSet</a> object is returned.
struct getStickerSet{
};

//Use this method to get information about custom emoji stickers by their identifiers. Returns an Array of <a href="#sticker">Sticker</a> objects.
struct getCustomEmojiStickers{
};

//Use this method to upload a .PNG file with a sticker for later use in <em>createNewStickerSet</em> and <em>addStickerToSet</em> methods (can be used multiple times). Returns the uploaded <a href="#file">File</a> on success.
struct uploadStickerFile{
};

//Use this method to create a new sticker set owned by a user. The bot will be able to edit the sticker set thus created. You <strong>must</strong> use exactly one of the fields <em>png_sticker</em>, <em>tgs_sticker</em>, or <em>webm_sticker</em>. Returns <em>True</em> on success.
struct createNewStickerSet{
};

//Use this method to add a new sticker to a set created by the bot. You <strong>must</strong> use exactly one of the fields <em>png_sticker</em>, <em>tgs_sticker</em>, or <em>webm_sticker</em>. Animated stickers can be added to animated sticker sets and only to them. Animated sticker sets can have up to 50 stickers. Static sticker sets can have up to 120 stickers. Returns <em>True</em> on success.
struct addStickerToSet{
};

//Use this method to move a sticker in a set created by the bot to a specific position. Returns <em>True</em> on success.
struct setStickerPositionInSet{
};

//Use this method to delete a sticker from a set created by the bot. Returns <em>True</em> on success.
struct deleteStickerFromSet{
};

//Use this method to set the thumbnail of a sticker set. Animated thumbnails can be set for animated sticker sets only. Video thumbnails can be set only for video sticker sets only. Returns <em>True</em> on success.
struct setStickerSetThumb{
};

//The following methods and objects allow your bot to work in <a href="/bots/inline">inline mode</a>.<br>Please see our <a href="/bots/inline">Introduction to Inline bots</a> for more details.
struct Inline mode{
};

//This object represents an incoming inline query. When the user sends an empty query, your bot could return some default or trending results.
struct InlineQuery{
	std::string id;
	std::shared_ptr<User> from;
	std::string query;
	std::string offset;
	std::string chat_type;
	std::shared_ptr<Location> location;
};

//Use this method to send answers to an inline query. On success, <em>True</em> is returned.<br>No more than <strong>50</strong> results per query are allowed.
struct answerInlineQuery{
};

//This object represents one result of an inline query. Telegram clients currently support results of the following 20 types:
struct InlineQueryResult{
	std::string type;
	std::string id;
	std::string title;
	std::shared_ptr<InputMessageContent> input_message_content;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::string url;
	bool hide_url;
	std::string description;
	std::string thumb_url;
	int thumb_width;
	int thumb_height;
};

//Represents a link to an article or web page.
struct InlineQueryResultArticle{
	std::string type;
	std::string id;
	std::string title;
	std::shared_ptr<InputMessageContent> input_message_content;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::string url;
	bool hide_url;
	std::string description;
	std::string thumb_url;
	int thumb_width;
	int thumb_height;
};

//Represents a link to a photo. By default, this photo will be sent by the user with optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the photo.
struct InlineQueryResultPhoto{
	std::string type;
	std::string id;
	std::string photo_url;
	std::string thumb_url;
	int photo_width;
	int photo_height;
	std::string title;
	std::string description;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to an animated GIF file. By default, this animated GIF file will be sent by the user with optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the animation.
struct InlineQueryResultGif{
	std::string type;
	std::string id;
	std::string gif_url;
	int gif_width;
	int gif_height;
	int gif_duration;
	std::string thumb_url;
	std::string thumb_mime_type;
	std::string title;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to a video animation (H.264/MPEG-4 AVC video without sound). By default, this animated MPEG-4 file will be sent by the user with optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the animation.
struct InlineQueryResultMpeg4Gif{
	std::string type;
	std::string id;
	std::string mpeg4_url;
	int mpeg4_width;
	int mpeg4_height;
	int mpeg4_duration;
	std::string thumb_url;
	std::string thumb_mime_type;
	std::string title;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to a page containing an embedded video player or a video file. By default, this video file will be sent by the user with an optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the video.
struct InlineQueryResultVideo{
	std::string type;
	std::string id;
	std::string video_url;
	std::string mime_type;
	std::string thumb_url;
	std::string title;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	int video_width;
	int video_height;
	int video_duration;
	std::string description;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to an MP3 audio file. By default, this audio file will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the audio.
struct InlineQueryResultAudio{
	std::string type;
	std::string id;
	std::string audio_url;
	std::string title;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::string performer;
	int audio_duration;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to a voice recording in an .OGG container encoded with OPUS. By default, this voice recording will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the the voice message.
struct InlineQueryResultVoice{
	std::string type;
	std::string id;
	std::string voice_url;
	std::string title;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	int voice_duration;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to a file. By default, this file will be sent by the user with an optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the file. Currently, only <strong>.PDF</strong> and <strong>.ZIP</strong> files can be sent using this method.
struct InlineQueryResultDocument{
	std::string type;
	std::string id;
	std::string title;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::string document_url;
	std::string mime_type;
	std::string description;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
	std::string thumb_url;
	int thumb_width;
	int thumb_height;
};

//Represents a location on a map. By default, the location will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the location.
struct InlineQueryResultLocation{
	std::string type;
	std::string id;
	float latitude;
	float longitude;
	std::string title;
	float horizontal_accuracy;
	int live_period;
	int heading;
	int proximity_alert_radius;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
	std::string thumb_url;
	int thumb_width;
	int thumb_height;
};

//Represents a venue. By default, the venue will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the venue.
struct InlineQueryResultVenue{
	std::string type;
	std::string id;
	float latitude;
	float longitude;
	std::string title;
	std::string address;
	std::string foursquare_id;
	std::string foursquare_type;
	std::string google_place_id;
	std::string google_place_type;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
	std::string thumb_url;
	int thumb_width;
	int thumb_height;
};

//Represents a contact with a phone number. By default, this contact will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the contact.
struct InlineQueryResultContact{
	std::string type;
	std::string id;
	std::string phone_number;
	std::string first_name;
	std::string last_name;
	std::string vcard;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
	std::string thumb_url;
	int thumb_width;
	int thumb_height;
};

//Represents a <a href="#games">Game</a>.
struct InlineQueryResultGame{
	std::string type;
	std::string id;
	std::string game_short_name;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
};

//Represents a link to a photo stored on the Telegram servers. By default, this photo will be sent by the user with an optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the photo.
struct InlineQueryResultCachedPhoto{
	std::string type;
	std::string id;
	std::string photo_file_id;
	std::string title;
	std::string description;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to an animated GIF file stored on the Telegram servers. By default, this animated GIF file will be sent by the user with an optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with specified content instead of the animation.
struct InlineQueryResultCachedGif{
	std::string type;
	std::string id;
	std::string gif_file_id;
	std::string title;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to a video animation (H.264/MPEG-4 AVC video without sound) stored on the Telegram servers. By default, this animated MPEG-4 file will be sent by the user with an optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the animation.
struct InlineQueryResultCachedMpeg4Gif{
	std::string type;
	std::string id;
	std::string mpeg4_file_id;
	std::string title;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to a sticker stored on the Telegram servers. By default, this sticker will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the sticker.
struct InlineQueryResultCachedSticker{
	std::string type;
	std::string id;
	std::string sticker_file_id;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to a file stored on the Telegram servers. By default, this file will be sent by the user with an optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the file.
struct InlineQueryResultCachedDocument{
	std::string type;
	std::string id;
	std::string title;
	std::string document_file_id;
	std::string description;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to a video file stored on the Telegram servers. By default, this video file will be sent by the user with an optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the video.
struct InlineQueryResultCachedVideo{
	std::string type;
	std::string id;
	std::string video_file_id;
	std::string title;
	std::string description;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to a voice message stored on the Telegram servers. By default, this voice message will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the voice message.
struct InlineQueryResultCachedVoice{
	std::string type;
	std::string id;
	std::string voice_file_id;
	std::string title;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to an MP3 audio file stored on the Telegram servers. By default, this audio file will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the audio.
struct InlineQueryResultCachedAudio{
	std::string type;
	std::string id;
	std::string audio_file_id;
	std::string caption;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//This object represents the content of a message to be sent as a result of an inline query. Telegram clients currently support the following 5 types:
struct InputMessageContent{
	std::string message_text;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> entities;
	bool disable_web_page_preview;
};

//Represents the <a href="#inputmessagecontent">content</a> of a text message to be sent as the result of an inline query.
struct InputTextMessageContent{
	std::string message_text;
	std::string parse_mode;
	std::shared_ptr<MessageEntity> entities;
	bool disable_web_page_preview;
};

//Represents the <a href="#inputmessagecontent">content</a> of a location message to be sent as the result of an inline query.
struct InputLocationMessageContent{
	float latitude;
	float longitude;
	float horizontal_accuracy;
	int live_period;
	int heading;
	int proximity_alert_radius;
};

//Represents the <a href="#inputmessagecontent">content</a> of a venue message to be sent as the result of an inline query.
struct InputVenueMessageContent{
	float latitude;
	float longitude;
	std::string title;
	std::string address;
	std::string foursquare_id;
	std::string foursquare_type;
	std::string google_place_id;
	std::string google_place_type;
};

//Represents the <a href="#inputmessagecontent">content</a> of a contact message to be sent as the result of an inline query.
struct InputContactMessageContent{
	std::string phone_number;
	std::string first_name;
	std::string last_name;
	std::string vcard;
};

//Represents the <a href="#inputmessagecontent">content</a> of an invoice message to be sent as the result of an inline query.
struct InputInvoiceMessageContent{
	std::string title;
	std::string description;
	std::string payload;
	std::string provider_token;
	std::string currency;
	std::shared_ptr<LabeledPrice> prices;
	int max_tip_amount;
	int suggested_tip_amounts;
	std::string provider_data;
	std::string photo_url;
	int photo_size;
	int photo_width;
	int photo_height;
	bool need_name;
	bool need_phone_number;
	bool need_email;
	bool need_shipping_address;
	bool send_phone_number_to_provider;
	bool send_email_to_provider;
	bool is_flexible;
};

//Represents a <a href="#inlinequeryresult">result</a> of an inline query that was chosen by the user and sent to their chat partner.
struct ChosenInlineResult{
	std::string result_id;
	std::shared_ptr<User> from;
	std::shared_ptr<Location> location;
	std::string inline_message_id;
	std::string query;
};

//Use this method to set the result of an interaction with a <a href="/bots/webapps">Web App</a> and send a corresponding message on behalf of the user to the chat from which the query originated. On success, a <a href="#sentwebappmessage">SentWebAppMessage</a> object is returned.
struct answerWebAppQuery{
};

//Describes an inline message sent by a <a href="/bots/webapps">Web App</a> on behalf of a user.
struct SentWebAppMessage{
	std::string inline_message_id;
};

//Your bot can accept payments from Telegram users. Please see the <a href="/bots/payments">introduction to payments</a> for more details on the process and how to set up payments for your bot. Please note that users will need Telegram v.4.0 or higher to use payments (released on May 18, 2017).
struct Payments{
};

//Use this method to send invoices. On success, the sent <a href="#message">Message</a> is returned.
struct sendInvoice{
};

//Use this method to create a link for an invoice. Returns the created invoice link as <em>String</em> on success.
struct createInvoiceLink{
};

//If you sent an invoice requesting a shipping address and the parameter <em>is_flexible</em> was specified, the Bot API will send an <a href="#update">Update</a> with a <em>shipping_query</em> field to the bot. Use this method to reply to shipping queries. On success, <em>True</em> is returned.
struct answerShippingQuery{
};

//Once the user has confirmed their payment and shipping details, the Bot API sends the final confirmation in the form of an <a href="#update">Update</a> with the field <em>pre_checkout_query</em>. Use this method to respond to such pre-checkout queries. On success, <em>True</em> is returned. <strong>Note:</strong> The Bot API must receive an answer within 10 seconds after the pre-checkout query was sent.
struct answerPreCheckoutQuery{
};

//This object represents a portion of the price for goods or services.
struct LabeledPrice{
	std::string label;
	int amount;
};

//This object contains basic information about an invoice.
struct Invoice{
	std::string title;
	std::string description;
	std::string start_parameter;
	std::string currency;
	int total_amount;
};

//This object represents a shipping address.
struct ShippingAddress{
	std::string country_code;
	std::string state;
	std::string city;
	std::string street_line1;
	std::string street_line2;
	std::string post_code;
};

//This object represents information about an order.
struct OrderInfo{
	std::string name;
	std::string phone_number;
	std::string email;
	std::shared_ptr<ShippingAddress> shipping_address;
};

//This object represents one shipping option.
struct ShippingOption{
	std::string id;
	std::string title;
	std::shared_ptr<LabeledPrice> prices;
};

//This object contains basic information about a successful payment.
struct SuccessfulPayment{
	std::string currency;
	int total_amount;
	std::string invoice_payload;
	std::string shipping_option_id;
	std::shared_ptr<OrderInfo> order_info;
	std::string telegram_payment_charge_id;
	std::string provider_payment_charge_id;
};

//This object contains information about an incoming shipping query.
struct ShippingQuery{
	std::string id;
	std::shared_ptr<User> from;
	std::string invoice_payload;
	std::shared_ptr<ShippingAddress> shipping_address;
};

//This object contains information about an incoming pre-checkout query.
struct PreCheckoutQuery{
	std::string id;
	std::shared_ptr<User> from;
	std::string currency;
	int total_amount;
	std::string invoice_payload;
	std::string shipping_option_id;
	std::shared_ptr<OrderInfo> order_info;
};

//<strong>Telegram Passport</strong> is a unified authorization method for services that require personal identification. Users can upload their documents once, then instantly share their data with services that require real-world ID (finance, ICOs, etc.). Please see the <a href="/passport">manual</a> for details.
struct Telegram Passport{
};

//Describes Telegram Passport data shared with the bot by the user.
struct PassportData{
	std::shared_ptr<EncryptedPassportElement> data;
	std::shared_ptr<EncryptedCredentials> credentials;
};

//This object represents a file uploaded to Telegram Passport. Currently all Telegram Passport files are in JPEG format when decrypted and don&#39;t exceed 10MB.
struct PassportFile{
	std::string file_id;
	std::string file_unique_id;
	int file_size;
	int file_date;
};

//Describes documents or other Telegram Passport elements shared with the bot by the user.
struct EncryptedPassportElement{
	std::string type;
	std::string data;
	std::string phone_number;
	std::string email;
	std::shared_ptr<PassportFile> files;
	std::shared_ptr<PassportFile> front_side;
	std::shared_ptr<PassportFile> reverse_side;
	std::shared_ptr<PassportFile> selfie;
	std::shared_ptr<PassportFile> translation;
	std::string hash;
};

//Describes data required for decrypting and authenticating <a href="#encryptedpassportelement">EncryptedPassportElement</a>. See the <a href="/passport#receiving-information">Telegram Passport Documentation</a> for a complete description of the data decryption and authentication processes.
struct EncryptedCredentials{
	std::string data;
	std::string hash;
	std::string secret;
};

//Informs a user that some of the Telegram Passport elements they provided contains errors. The user will not be able to re-submit their Passport to you until the errors are fixed (the contents of the field for which you returned the error must change). Returns <em>True</em> on success.
struct setPassportDataErrors{
};

//This object represents an error in the Telegram Passport element which was submitted that should be resolved by the user. It should be one of:
struct PassportElementError{
	std::string source;
	std::string type;
	std::string field_name;
	std::string data_hash;
	std::string message;
};

//Represents an issue in one of the data fields that was provided by the user. The error is considered resolved when the field&#39;s value changes.
struct PassportElementErrorDataField{
	std::string source;
	std::string type;
	std::string field_name;
	std::string data_hash;
	std::string message;
};

//Represents an issue with the front side of a document. The error is considered resolved when the file with the front side of the document changes.
struct PassportElementErrorFrontSide{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
};

//Represents an issue with the reverse side of a document. The error is considered resolved when the file with reverse side of the document changes.
struct PassportElementErrorReverseSide{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
};

//Represents an issue with the selfie with a document. The error is considered resolved when the file with the selfie changes.
struct PassportElementErrorSelfie{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
};

//Represents an issue with a document scan. The error is considered resolved when the file with the document scan changes.
struct PassportElementErrorFile{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
};

//Represents an issue with a list of scans. The error is considered resolved when the list of files containing the scans changes.
struct PassportElementErrorFiles{
	std::string source;
	std::string type;
	std::string file_hashes;
	std::string message;
};

//Represents an issue with one of the files that constitute the translation of a document. The error is considered resolved when the file changes.
struct PassportElementErrorTranslationFile{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
};

//Represents an issue with the translated version of a document. The error is considered resolved when a file with the document translation change.
struct PassportElementErrorTranslationFiles{
	std::string source;
	std::string type;
	std::string file_hashes;
	std::string message;
};

//Represents an issue in an unspecified place. The error is considered resolved when new data is added.
struct PassportElementErrorUnspecified{
	std::string source;
	std::string type;
	std::string element_hash;
	std::string message;
};

//Your bot can offer users <strong>HTML5 games</strong> to play solo or to compete against each other in groups and one-on-one chats. Create games via <a href="https://t.me/botfather">@BotFather</a> using the <em>/newgame</em> command. Please note that this kind of power requires responsibility: you will need to accept the terms for each game that your bots will be offering.
struct Games{
};

//Use this method to send a game. On success, the sent <a href="#message">Message</a> is returned.
struct sendGame{
};

//This object represents a game. Use BotFather to create and edit games, their short names will act as unique identifiers.
struct Game{
	std::string title;
	std::string description;
	std::shared_ptr<PhotoSize> photo;
	std::string text;
	std::shared_ptr<MessageEntity> text_entities;
	std::shared_ptr<Animation> animation;
};

//A placeholder, currently holds no information. Use <a href="https://t.me/botfather">BotFather</a> to set up your game.
struct CallbackGame{
};

//Use this method to set the score of the specified user in a game message. On success, if the message is not an inline message, the <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned. Returns an error, if the new score is not greater than the user&#39;s current score in the chat and <em>force</em> is <em>False</em>.
struct setGameScore{
};

//Use this method to get data for high score tables. Will return the score of the specified user and several of their neighbors in a game. Returns an Array of <a href="#gamehighscore">GameHighScore</a> objects.
struct getGameHighScores{
};

//This object represents one row of the high scores table for a game.
struct GameHighScore{
	int position;
	std::shared_ptr<User> user;
	int score;
};

