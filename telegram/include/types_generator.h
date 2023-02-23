#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

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
struct Stickers;
struct Sticker;
struct StickerSet;
struct MaskPosition;
struct InlineQuery;
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
struct SentWebAppMessage;
struct Payments;
struct LabeledPrice;
struct Invoice;
struct ShippingAddress;
struct OrderInfo;
struct ShippingOption;
struct SuccessfulPayment;
struct ShippingQuery;
struct PreCheckoutQuery;
struct PassportData;
struct PassportFile;
struct EncryptedPassportElement;
struct EncryptedCredentials;
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
struct Game;
struct CallbackGame;
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
	std::vector<std::shared_ptr<MessageEntity>> entities;
	std::shared_ptr<Animation> animation;
	std::shared_ptr<Audio> audio;
	std::shared_ptr<Document> document;
	std::vector<std::shared_ptr<PhotoSize>> photo;
	std::shared_ptr<Sticker> sticker;
	std::shared_ptr<Video> video;
	std::shared_ptr<VideoNote> video_note;
	std::shared_ptr<Voice> voice;
	std::string caption;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	bool has_media_spoiler;
	std::shared_ptr<Contact> contact;
	std::shared_ptr<Dice> dice;
	std::shared_ptr<Game> game;
	std::shared_ptr<Poll> poll;
	std::shared_ptr<Venue> venue;
	std::shared_ptr<Location> location;
	std::vector<std::shared_ptr<User>> new_chat_members;
	std::shared_ptr<User> left_chat_member;
	std::string new_chat_title;
	std::vector<std::shared_ptr<PhotoSize>> new_chat_photo;
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
	std::vector<std::shared_ptr<PollOption>> options;
	int total_voter_count;
	bool is_closed;
	bool is_anonymous;
	std::string type;
	bool allows_multiple_answers;
	int correct_option_id;
	std::string explanation;
	std::vector<std::shared_ptr<MessageEntity>> explanation_entities;
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
	std::vector<std::shared_ptr<User>> users;
};

//This object represent a user&#39;s profile pictures.
struct UserProfilePhotos{
	int total_count;
	std::vector<std::shared_ptr<PhotoSize>> photos;
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
	std::vector<std::shared_ptr<KeyboardButton>> keyboard;
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
	std::vector<std::shared_ptr<InlineKeyboardButton>> inline_keyboard;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	bool has_spoiler;
};

//Represents a photo to be sent.
struct InputMediaPhoto{
	std::string type;
	std::string media;
	std::string caption;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	bool has_spoiler;
};

//Represents a video to be sent.
struct InputMediaVideo{
	std::string type;
	std::string media;
	std::string thumb;
	std::string caption;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	bool disable_content_type_detection;
};

//This object represents the contents of a file to be uploaded. Must be posted using multipart/form-data in the usual way that files are uploaded via the browser.
struct InputFile{
	int chat_id;
	int message_thread_id;
	std::string text;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> entities;
	bool disable_web_page_preview;
	bool disable_notification;
	bool protect_content;
	int reply_to_message_id;
	bool allow_sending_without_reply;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
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
	std::vector<std::shared_ptr<Sticker>> stickers;
	std::shared_ptr<PhotoSize> thumb;
};

//This object describes the position on faces where a mask should be placed by default.
struct MaskPosition{
	std::string point;
	float x_shift;
	float y_shift;
	float scale;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
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
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
};

//This object represents the content of a message to be sent as a result of an inline query. Telegram clients currently support the following 5 types:
struct InputMessageContent{
	std::string message_text;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> entities;
	bool disable_web_page_preview;
};

//Represents the <a href="#inputmessagecontent">content</a> of a text message to be sent as the result of an inline query.
struct InputTextMessageContent{
	std::string message_text;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> entities;
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
	std::vector<std::shared_ptr<LabeledPrice>> prices;
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

//Describes an inline message sent by a <a href="/bots/webapps">Web App</a> on behalf of a user.
struct SentWebAppMessage{
	std::string inline_message_id;
};

//Your bot can accept payments from Telegram users. Please see the <a href="/bots/payments">introduction to payments</a> for more details on the process and how to set up payments for your bot. Please note that users will need Telegram v.4.0 or higher to use payments (released on May 18, 2017).
struct Payments{
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
	std::vector<std::shared_ptr<LabeledPrice>> prices;
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

//Describes Telegram Passport data shared with the bot by the user.
struct PassportData{
	std::vector<std::shared_ptr<EncryptedPassportElement>> data;
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
	std::vector<std::shared_ptr<PassportFile>> files;
	std::shared_ptr<PassportFile> front_side;
	std::shared_ptr<PassportFile> reverse_side;
	std::shared_ptr<PassportFile> selfie;
	std::vector<std::shared_ptr<PassportFile>> translation;
	std::string hash;
};

//Describes data required for decrypting and authenticating <a href="#encryptedpassportelement">EncryptedPassportElement</a>. See the <a href="/passport#receiving-information">Telegram Passport Documentation</a> for a complete description of the data decryption and authentication processes.
struct EncryptedCredentials{
	std::string data;
	std::string hash;
	std::string secret;
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

//This object represents a game. Use BotFather to create and edit games, their short names will act as unique identifiers.
struct Game{
	std::string title;
	std::string description;
	std::vector<std::shared_ptr<PhotoSize>> photo;
	std::string text;
	std::vector<std::shared_ptr<MessageEntity>> text_entities;
	std::shared_ptr<Animation> animation;
};

//A placeholder, currently holds no information. Use <a href="https://t.me/botfather">BotFather</a> to set up your game.
struct CallbackGame{
};

//This object represents one row of the high scores table for a game.
struct GameHighScore{
	int position;
	std::shared_ptr<User> user;
	int score;
};

void from_json(const json& j, User& name);
void to_json(json&  j, User& name);
void from_json(const json& j, Chat& name);
void to_json(json&  j, Chat& name);
void from_json(const json& j, Message& name);
void to_json(json&  j, Message& name);
void from_json(const json& j, MessageId& name);
void to_json(json&  j, MessageId& name);
void from_json(const json& j, MessageEntity& name);
void to_json(json&  j, MessageEntity& name);
void from_json(const json& j, PhotoSize& name);
void to_json(json&  j, PhotoSize& name);
void from_json(const json& j, Animation& name);
void to_json(json&  j, Animation& name);
void from_json(const json& j, Audio& name);
void to_json(json&  j, Audio& name);
void from_json(const json& j, Document& name);
void to_json(json&  j, Document& name);
void from_json(const json& j, Video& name);
void to_json(json&  j, Video& name);
void from_json(const json& j, VideoNote& name);
void to_json(json&  j, VideoNote& name);
void from_json(const json& j, Voice& name);
void to_json(json&  j, Voice& name);
void from_json(const json& j, Contact& name);
void to_json(json&  j, Contact& name);
void from_json(const json& j, Dice& name);
void to_json(json&  j, Dice& name);
void from_json(const json& j, PollOption& name);
void to_json(json&  j, PollOption& name);
void from_json(const json& j, PollAnswer& name);
void to_json(json&  j, PollAnswer& name);
void from_json(const json& j, Poll& name);
void to_json(json&  j, Poll& name);
void from_json(const json& j, Location& name);
void to_json(json&  j, Location& name);
void from_json(const json& j, Venue& name);
void to_json(json&  j, Venue& name);
void from_json(const json& j, WebAppData& name);
void to_json(json&  j, WebAppData& name);
void from_json(const json& j, ProximityAlertTriggered& name);
void to_json(json&  j, ProximityAlertTriggered& name);
void from_json(const json& j, MessageAutoDeleteTimerChanged& name);
void to_json(json&  j, MessageAutoDeleteTimerChanged& name);
void from_json(const json& j, ForumTopicCreated& name);
void to_json(json&  j, ForumTopicCreated& name);
void from_json(const json& j, ForumTopicClosed& name);
void to_json(json&  j, ForumTopicClosed& name);
void from_json(const json& j, ForumTopicEdited& name);
void to_json(json&  j, ForumTopicEdited& name);
void from_json(const json& j, ForumTopicReopened& name);
void to_json(json&  j, ForumTopicReopened& name);
void from_json(const json& j, GeneralForumTopicHidden& name);
void to_json(json&  j, GeneralForumTopicHidden& name);
void from_json(const json& j, GeneralForumTopicUnhidden& name);
void to_json(json&  j, GeneralForumTopicUnhidden& name);
void from_json(const json& j, UserShared& name);
void to_json(json&  j, UserShared& name);
void from_json(const json& j, ChatShared& name);
void to_json(json&  j, ChatShared& name);
void from_json(const json& j, WriteAccessAllowed& name);
void to_json(json&  j, WriteAccessAllowed& name);
void from_json(const json& j, VideoChatScheduled& name);
void to_json(json&  j, VideoChatScheduled& name);
void from_json(const json& j, VideoChatStarted& name);
void to_json(json&  j, VideoChatStarted& name);
void from_json(const json& j, VideoChatEnded& name);
void to_json(json&  j, VideoChatEnded& name);
void from_json(const json& j, VideoChatParticipantsInvited& name);
void to_json(json&  j, VideoChatParticipantsInvited& name);
void from_json(const json& j, UserProfilePhotos& name);
void to_json(json&  j, UserProfilePhotos& name);
void from_json(const json& j, File& name);
void to_json(json&  j, File& name);
void from_json(const json& j, WebAppInfo& name);
void to_json(json&  j, WebAppInfo& name);
void from_json(const json& j, ReplyKeyboardMarkup& name);
void to_json(json&  j, ReplyKeyboardMarkup& name);
void from_json(const json& j, KeyboardButton& name);
void to_json(json&  j, KeyboardButton& name);
void from_json(const json& j, KeyboardButtonRequestUser& name);
void to_json(json&  j, KeyboardButtonRequestUser& name);
void from_json(const json& j, KeyboardButtonRequestChat& name);
void to_json(json&  j, KeyboardButtonRequestChat& name);
void from_json(const json& j, KeyboardButtonPollType& name);
void to_json(json&  j, KeyboardButtonPollType& name);
void from_json(const json& j, ReplyKeyboardRemove& name);
void to_json(json&  j, ReplyKeyboardRemove& name);
void from_json(const json& j, InlineKeyboardMarkup& name);
void to_json(json&  j, InlineKeyboardMarkup& name);
void from_json(const json& j, InlineKeyboardButton& name);
void to_json(json&  j, InlineKeyboardButton& name);
void from_json(const json& j, LoginUrl& name);
void to_json(json&  j, LoginUrl& name);
void from_json(const json& j, CallbackQuery& name);
void to_json(json&  j, CallbackQuery& name);
void from_json(const json& j, ForceReply& name);
void to_json(json&  j, ForceReply& name);
void from_json(const json& j, ChatPhoto& name);
void to_json(json&  j, ChatPhoto& name);
void from_json(const json& j, ChatInviteLink& name);
void to_json(json&  j, ChatInviteLink& name);
void from_json(const json& j, ChatAdministratorRights& name);
void to_json(json&  j, ChatAdministratorRights& name);
void from_json(const json& j, ChatMember& name);
void to_json(json&  j, ChatMember& name);
void from_json(const json& j, ChatMemberOwner& name);
void to_json(json&  j, ChatMemberOwner& name);
void from_json(const json& j, ChatMemberAdministrator& name);
void to_json(json&  j, ChatMemberAdministrator& name);
void from_json(const json& j, ChatMemberMember& name);
void to_json(json&  j, ChatMemberMember& name);
void from_json(const json& j, ChatMemberRestricted& name);
void to_json(json&  j, ChatMemberRestricted& name);
void from_json(const json& j, ChatMemberLeft& name);
void to_json(json&  j, ChatMemberLeft& name);
void from_json(const json& j, ChatMemberBanned& name);
void to_json(json&  j, ChatMemberBanned& name);
void from_json(const json& j, ChatMemberUpdated& name);
void to_json(json&  j, ChatMemberUpdated& name);
void from_json(const json& j, ChatJoinRequest& name);
void to_json(json&  j, ChatJoinRequest& name);
void from_json(const json& j, ChatPermissions& name);
void to_json(json&  j, ChatPermissions& name);
void from_json(const json& j, ChatLocation& name);
void to_json(json&  j, ChatLocation& name);
void from_json(const json& j, ForumTopic& name);
void to_json(json&  j, ForumTopic& name);
void from_json(const json& j, BotCommand& name);
void to_json(json&  j, BotCommand& name);
void from_json(const json& j, BotCommandScope& name);
void to_json(json&  j, BotCommandScope& name);
void from_json(const json& j, BotCommandScopeDefault& name);
void to_json(json&  j, BotCommandScopeDefault& name);
void from_json(const json& j, BotCommandScopeAllPrivateChats& name);
void to_json(json&  j, BotCommandScopeAllPrivateChats& name);
void from_json(const json& j, BotCommandScopeAllGroupChats& name);
void to_json(json&  j, BotCommandScopeAllGroupChats& name);
void from_json(const json& j, BotCommandScopeAllChatAdministrators& name);
void to_json(json&  j, BotCommandScopeAllChatAdministrators& name);
void from_json(const json& j, BotCommandScopeChat& name);
void to_json(json&  j, BotCommandScopeChat& name);
void from_json(const json& j, BotCommandScopeChatAdministrators& name);
void to_json(json&  j, BotCommandScopeChatAdministrators& name);
void from_json(const json& j, BotCommandScopeChatMember& name);
void to_json(json&  j, BotCommandScopeChatMember& name);
void from_json(const json& j, MenuButton& name);
void to_json(json&  j, MenuButton& name);
void from_json(const json& j, MenuButtonCommands& name);
void to_json(json&  j, MenuButtonCommands& name);
void from_json(const json& j, MenuButtonWebApp& name);
void to_json(json&  j, MenuButtonWebApp& name);
void from_json(const json& j, MenuButtonDefault& name);
void to_json(json&  j, MenuButtonDefault& name);
void from_json(const json& j, ResponseParameters& name);
void to_json(json&  j, ResponseParameters& name);
void from_json(const json& j, InputMedia& name);
void to_json(json&  j, InputMedia& name);
void from_json(const json& j, InputMediaPhoto& name);
void to_json(json&  j, InputMediaPhoto& name);
void from_json(const json& j, InputMediaVideo& name);
void to_json(json&  j, InputMediaVideo& name);
void from_json(const json& j, InputMediaAnimation& name);
void to_json(json&  j, InputMediaAnimation& name);
void from_json(const json& j, InputMediaAudio& name);
void to_json(json&  j, InputMediaAudio& name);
void from_json(const json& j, InputMediaDocument& name);
void to_json(json&  j, InputMediaDocument& name);
void from_json(const json& j, InputFile& name);
void to_json(json&  j, InputFile& name);
void from_json(const json& j, Stickers& name);
void to_json(json&  j, Stickers& name);
void from_json(const json& j, Sticker& name);
void to_json(json&  j, Sticker& name);
void from_json(const json& j, StickerSet& name);
void to_json(json&  j, StickerSet& name);
void from_json(const json& j, MaskPosition& name);
void to_json(json&  j, MaskPosition& name);
void from_json(const json& j, InlineQuery& name);
void to_json(json&  j, InlineQuery& name);
void from_json(const json& j, InlineQueryResult& name);
void to_json(json&  j, InlineQueryResult& name);
void from_json(const json& j, InlineQueryResultArticle& name);
void to_json(json&  j, InlineQueryResultArticle& name);
void from_json(const json& j, InlineQueryResultPhoto& name);
void to_json(json&  j, InlineQueryResultPhoto& name);
void from_json(const json& j, InlineQueryResultGif& name);
void to_json(json&  j, InlineQueryResultGif& name);
void from_json(const json& j, InlineQueryResultMpeg4Gif& name);
void to_json(json&  j, InlineQueryResultMpeg4Gif& name);
void from_json(const json& j, InlineQueryResultVideo& name);
void to_json(json&  j, InlineQueryResultVideo& name);
void from_json(const json& j, InlineQueryResultAudio& name);
void to_json(json&  j, InlineQueryResultAudio& name);
void from_json(const json& j, InlineQueryResultVoice& name);
void to_json(json&  j, InlineQueryResultVoice& name);
void from_json(const json& j, InlineQueryResultDocument& name);
void to_json(json&  j, InlineQueryResultDocument& name);
void from_json(const json& j, InlineQueryResultLocation& name);
void to_json(json&  j, InlineQueryResultLocation& name);
void from_json(const json& j, InlineQueryResultVenue& name);
void to_json(json&  j, InlineQueryResultVenue& name);
void from_json(const json& j, InlineQueryResultContact& name);
void to_json(json&  j, InlineQueryResultContact& name);
void from_json(const json& j, InlineQueryResultGame& name);
void to_json(json&  j, InlineQueryResultGame& name);
void from_json(const json& j, InlineQueryResultCachedPhoto& name);
void to_json(json&  j, InlineQueryResultCachedPhoto& name);
void from_json(const json& j, InlineQueryResultCachedGif& name);
void to_json(json&  j, InlineQueryResultCachedGif& name);
void from_json(const json& j, InlineQueryResultCachedMpeg4Gif& name);
void to_json(json&  j, InlineQueryResultCachedMpeg4Gif& name);
void from_json(const json& j, InlineQueryResultCachedSticker& name);
void to_json(json&  j, InlineQueryResultCachedSticker& name);
void from_json(const json& j, InlineQueryResultCachedDocument& name);
void to_json(json&  j, InlineQueryResultCachedDocument& name);
void from_json(const json& j, InlineQueryResultCachedVideo& name);
void to_json(json&  j, InlineQueryResultCachedVideo& name);
void from_json(const json& j, InlineQueryResultCachedVoice& name);
void to_json(json&  j, InlineQueryResultCachedVoice& name);
void from_json(const json& j, InlineQueryResultCachedAudio& name);
void to_json(json&  j, InlineQueryResultCachedAudio& name);
void from_json(const json& j, InputMessageContent& name);
void to_json(json&  j, InputMessageContent& name);
void from_json(const json& j, InputTextMessageContent& name);
void to_json(json&  j, InputTextMessageContent& name);
void from_json(const json& j, InputLocationMessageContent& name);
void to_json(json&  j, InputLocationMessageContent& name);
void from_json(const json& j, InputVenueMessageContent& name);
void to_json(json&  j, InputVenueMessageContent& name);
void from_json(const json& j, InputContactMessageContent& name);
void to_json(json&  j, InputContactMessageContent& name);
void from_json(const json& j, InputInvoiceMessageContent& name);
void to_json(json&  j, InputInvoiceMessageContent& name);
void from_json(const json& j, ChosenInlineResult& name);
void to_json(json&  j, ChosenInlineResult& name);
void from_json(const json& j, SentWebAppMessage& name);
void to_json(json&  j, SentWebAppMessage& name);
void from_json(const json& j, Payments& name);
void to_json(json&  j, Payments& name);
void from_json(const json& j, LabeledPrice& name);
void to_json(json&  j, LabeledPrice& name);
void from_json(const json& j, Invoice& name);
void to_json(json&  j, Invoice& name);
void from_json(const json& j, ShippingAddress& name);
void to_json(json&  j, ShippingAddress& name);
void from_json(const json& j, OrderInfo& name);
void to_json(json&  j, OrderInfo& name);
void from_json(const json& j, ShippingOption& name);
void to_json(json&  j, ShippingOption& name);
void from_json(const json& j, SuccessfulPayment& name);
void to_json(json&  j, SuccessfulPayment& name);
void from_json(const json& j, ShippingQuery& name);
void to_json(json&  j, ShippingQuery& name);
void from_json(const json& j, PreCheckoutQuery& name);
void to_json(json&  j, PreCheckoutQuery& name);
void from_json(const json& j, PassportData& name);
void to_json(json&  j, PassportData& name);
void from_json(const json& j, PassportFile& name);
void to_json(json&  j, PassportFile& name);
void from_json(const json& j, EncryptedPassportElement& name);
void to_json(json&  j, EncryptedPassportElement& name);
void from_json(const json& j, EncryptedCredentials& name);
void to_json(json&  j, EncryptedCredentials& name);
void from_json(const json& j, PassportElementError& name);
void to_json(json&  j, PassportElementError& name);
void from_json(const json& j, PassportElementErrorDataField& name);
void to_json(json&  j, PassportElementErrorDataField& name);
void from_json(const json& j, PassportElementErrorFrontSide& name);
void to_json(json&  j, PassportElementErrorFrontSide& name);
void from_json(const json& j, PassportElementErrorReverseSide& name);
void to_json(json&  j, PassportElementErrorReverseSide& name);
void from_json(const json& j, PassportElementErrorSelfie& name);
void to_json(json&  j, PassportElementErrorSelfie& name);
void from_json(const json& j, PassportElementErrorFile& name);
void to_json(json&  j, PassportElementErrorFile& name);
void from_json(const json& j, PassportElementErrorFiles& name);
void to_json(json&  j, PassportElementErrorFiles& name);
void from_json(const json& j, PassportElementErrorTranslationFile& name);
void to_json(json&  j, PassportElementErrorTranslationFile& name);
void from_json(const json& j, PassportElementErrorTranslationFiles& name);
void to_json(json&  j, PassportElementErrorTranslationFiles& name);
void from_json(const json& j, PassportElementErrorUnspecified& name);
void to_json(json&  j, PassportElementErrorUnspecified& name);
void from_json(const json& j, Games& name);
void to_json(json&  j, Games& name);
void from_json(const json& j, Game& name);
void to_json(json&  j, Game& name);
void from_json(const json& j, CallbackGame& name);
void to_json(json&  j, CallbackGame& name);
void from_json(const json& j, GameHighScore& name);
void to_json(json&  j, GameHighScore& name);
