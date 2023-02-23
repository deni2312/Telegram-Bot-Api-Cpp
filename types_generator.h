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
struct User {
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
struct Chat {
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
struct Message {
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
struct MessageId {
    int message_id;
};

//This object represents one special entity in a text message. For example, hashtags, usernames, URLs, etc.
struct MessageEntity {
    std::string type;
    int offset;
    int length;
    std::string url;
    std::shared_ptr<User> user;
    std::string language;
    std::string custom_emoji_id;
};

//This object represents one size of a photo or a <a href="#document">file</a> / <a href="#sticker">sticker</a> thumbnail.
struct PhotoSize {
    std::string file_id;
    std::string file_unique_id;
    int width;
    int height;
    int file_size;
};

//This object represents an animation file (GIF or H.264/MPEG-4 AVC video without sound).
struct Animation {
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
struct Audio {
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
struct Document {
    std::string file_id;
    std::string file_unique_id;
    std::shared_ptr<PhotoSize> thumb;
    std::string file_name;
    std::string mime_type;
    int file_size;
};

//This object represents a video file.
struct Video {
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
struct VideoNote {
    std::string file_id;
    std::string file_unique_id;
    int length;
    int duration;
    std::shared_ptr<PhotoSize> thumb;
    int file_size;
};

//This object represents a voice note.
struct Voice {
    std::string file_id;
    std::string file_unique_id;
    int duration;
    std::string mime_type;
    int file_size;
};

//This object represents a phone contact.
struct Contact {
    std::string phone_number;
    std::string first_name;
    std::string last_name;
    int user_id;
    std::string vcard;
};

//This object represents an animated emoji that displays a random value.
struct Dice {
    std::string emoji;
    int value;
};

//This object contains information about one answer option in a poll.
struct PollOption {
    std::string text;
    int voter_count;
};

//This object represents an answer of a user in a non-anonymous poll.
struct PollAnswer {
    std::string poll_id;
    std::shared_ptr<User> user;
    int option_ids;
};

//This object contains information about a poll.
struct Poll {
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
struct Location {
    float longitude;
    float latitude;
    float horizontal_accuracy;
    int live_period;
    int heading;
    int proximity_alert_radius;
};

//This object represents a venue.
struct Venue {
    std::shared_ptr<Location> location;
    std::string title;
    std::string address;
    std::string foursquare_id;
    std::string foursquare_type;
    std::string google_place_id;
    std::string google_place_type;
};

//Describes data sent from a <a href="/bots/webapps">Web App</a> to the bot.
struct WebAppData {
    std::string data;
    std::string button_text;
};

//This object represents the content of a service message, sent whenever a user in the chat triggers a proximity alert set by another user.
struct ProximityAlertTriggered {
    std::shared_ptr<User> traveler;
    std::shared_ptr<User> watcher;
    int distance;
};

//This object represents a service message about a change in auto-delete timer settings.
struct MessageAutoDeleteTimerChanged {
    int message_auto_delete_time;
};

//This object represents a service message about a new forum topic created in the chat.
struct ForumTopicCreated {
    std::string name;
    int icon_color;
    std::string icon_custom_emoji_id;
};

//This object represents a service message about a forum topic closed in the chat. Currently holds no information.
struct ForumTopicClosed {
};

//This object represents a service message about an edited forum topic.
struct ForumTopicEdited {
    std::string name;
    std::string icon_custom_emoji_id;
};

//This object represents a service message about a forum topic reopened in the chat. Currently holds no information.
struct ForumTopicReopened {
};

//This object represents a service message about General forum topic hidden in the chat. Currently holds no information.
struct GeneralForumTopicHidden {
};

//This object represents a service message about General forum topic unhidden in the chat. Currently holds no information.
struct GeneralForumTopicUnhidden {
};

//This object contains information about the user whose identifier was shared with the bot using a <a href="#keyboardbuttonrequestuser">KeyboardButtonRequestUser</a> button.
struct UserShared {
    int request_id;
    int user_id;
};

//This object contains information about the chat whose identifier was shared with the bot using a <a href="#keyboardbuttonrequestchat">KeyboardButtonRequestChat</a> button.
struct ChatShared {
    int request_id;
    int chat_id;
};

//This object represents a service message about a user allowing a bot added to the attachment menu to write messages. Currently holds no information.
struct WriteAccessAllowed {
};

//This object represents a service message about a video chat scheduled in the chat.
struct VideoChatScheduled {
    int start_date;
};

//This object represents a service message about a video chat started in the chat. Currently holds no information.
struct VideoChatStarted {
};

//This object represents a service message about a video chat ended in the chat.
struct VideoChatEnded {
    int duration;
};

//This object represents a service message about new members invited to a video chat.
struct VideoChatParticipantsInvited {
    std::vector<std::shared_ptr<User>> users;
};

//This object represent a user&#39;s profile pictures.
struct UserProfilePhotos {
    int total_count;
    std::vector<std::shared_ptr<PhotoSize>> photos;
};

//This object represents a file ready to be downloaded. The file can be downloaded via the link <code>https://api.telegram.org/file/bot&lt;token&gt;/&lt;file_path&gt;</code>. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling <a href="#getfile">getFile</a>.
struct File {
    std::string file_id;
    std::string file_unique_id;
    int file_size;
    std::string file_path;
};

//Describes a <a href="/bots/webapps">Web App</a>.
struct WebAppInfo {
    std::string url;
};

//This object represents a <a href="/bots/features#keyboards">custom keyboard</a> with reply options (see <a href="/bots/features#keyboards">Introduction to bots</a> for details and examples).
struct ReplyKeyboardMarkup {
    std::vector<std::shared_ptr<KeyboardButton>> keyboard;
    bool is_persistent;
    bool resize_keyboard;
    bool one_time_keyboard;
    std::string input_field_placeholder;
    bool selective;
};

//This object represents one button of the reply keyboard. For simple text buttons, <em>String</em> can be used instead of this object to specify the button text. The optional fields <em>web_app</em>, <em>request_user</em>, <em>request_chat</em>, <em>request_contact</em>, <em>request_location</em>, and <em>request_poll</em> are mutually exclusive.
struct KeyboardButton {
    std::string text;
    std::shared_ptr<KeyboardButtonRequestUser> request_user;
    std::shared_ptr<KeyboardButtonRequestChat> request_chat;
    bool request_contact;
    bool request_location;
    std::shared_ptr<KeyboardButtonPollType> request_poll;
    std::shared_ptr<WebAppInfo> web_app;
};

//This object defines the criteria used to request a suitable user. The identifier of the selected user will be shared with the bot when the corresponding button is pressed.
struct KeyboardButtonRequestUser {
    int request_id;
    bool user_is_bot;
    bool user_is_premium;
};

//This object defines the criteria used to request a suitable chat. The identifier of the selected chat will be shared with the bot when the corresponding button is pressed.
struct KeyboardButtonRequestChat {
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
struct KeyboardButtonPollType {
    std::string type;
};

//Upon receiving a message with this object, Telegram clients will remove the current custom keyboard and display the default letter-keyboard. By default, custom keyboards are displayed until a new keyboard is sent by a bot. An exception is made for one-time keyboards that are hidden immediately after the user presses a button (see <a href="#replykeyboardmarkup">ReplyKeyboardMarkup</a>).
struct ReplyKeyboardRemove {
};

//This object represents an <a href="/bots/features#inline-keyboards">inline keyboard</a> that appears right next to the message it belongs to.
struct InlineKeyboardMarkup {
    std::vector<std::shared_ptr<InlineKeyboardButton>> inline_keyboard;
};

//This object represents one button of an inline keyboard. You <strong>must</strong> use exactly one of the optional fields.
struct InlineKeyboardButton {
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
struct LoginUrl {
    std::string url;
    std::string forward_text;
    std::string bot_username;
    bool request_write_access;
};

//This object represents an incoming callback query from a callback button in an <a href="/bots/features#inline-keyboards">inline keyboard</a>. If the button that originated the query was attached to a message sent by the bot, the field <em>message</em> will be present. If the button was attached to a message sent via the bot (in <a href="#inline-mode">inline mode</a>), the field <em>inline_message_id</em> will be present. Exactly one of the fields <em>data</em> or <em>game_short_name</em> will be present.
struct CallbackQuery {
    std::string id;
    std::shared_ptr<User> from;
    std::shared_ptr<Message> message;
    std::string inline_message_id;
    std::string chat_instance;
    std::string data;
    std::string game_short_name;
};

//Upon receiving a message with this object, Telegram clients will display a reply interface to the user (act as if the user has selected the bot&#39;s message and tapped &#39;Reply&#39;). This can be extremely useful if you want to create user-friendly step-by-step interfaces without having to sacrifice <a href="/bots/features#privacy-mode">privacy mode</a>.
struct ForceReply {
};

//This object represents a chat photo.
struct ChatPhoto {
    std::string small_file_id;
    std::string small_file_unique_id;
    std::string big_file_id;
    std::string big_file_unique_id;
};

//Represents an invite link for a chat.
struct ChatInviteLink {
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
struct ChatAdministratorRights {
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
struct ChatMember {
    std::string status;
    std::shared_ptr<User> user;
    bool is_anonymous;
    std::string custom_title;
};

//Represents a <a href="#chatmember">chat member</a> that owns the chat and has all administrator privileges.
struct ChatMemberOwner {
    std::string status;
    std::shared_ptr<User> user;
    bool is_anonymous;
    std::string custom_title;
};

//Represents a <a href="#chatmember">chat member</a> that has some additional privileges.
struct ChatMemberAdministrator {
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
struct ChatMemberMember {
    std::string status;
    std::shared_ptr<User> user;
};

//Represents a <a href="#chatmember">chat member</a> that is under certain restrictions in the chat. Supergroups only.
struct ChatMemberRestricted {
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
struct ChatMemberLeft {
    std::string status;
    std::shared_ptr<User> user;
};

//Represents a <a href="#chatmember">chat member</a> that was banned in the chat and can&#39;t return to the chat or view chat messages.
struct ChatMemberBanned {
    std::string status;
    std::shared_ptr<User> user;
    int until_date;
};

//This object represents changes in the status of a chat member.
struct ChatMemberUpdated {
    std::shared_ptr<Chat> chat;
    std::shared_ptr<User> from;
    int date;
    std::shared_ptr<ChatMember> old_chat_member;
    std::shared_ptr<ChatMember> new_chat_member;
    std::shared_ptr<ChatInviteLink> invite_link;
};

//Represents a join request sent to a chat.
struct ChatJoinRequest {
    std::shared_ptr<Chat> chat;
    std::shared_ptr<User> from;
    int user_chat_id;
    int date;
    std::string bio;
    std::shared_ptr<ChatInviteLink> invite_link;
};

//Describes actions that a non-administrator user is allowed to take in a chat.
struct ChatPermissions {
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
struct ChatLocation {
    std::shared_ptr<Location> location;
    std::string address;
};

//This object represents a forum topic.
struct ForumTopic {
    int message_thread_id;
    std::string name;
    int icon_color;
    std::string icon_custom_emoji_id;
};

//This object represents a bot command.
struct BotCommand {
    std::string command;
    std::string description;
};

//This object represents the scope to which bot commands are applied. Currently, the following 7 scopes are supported:
struct BotCommandScope {
    std::string type;
};

//Represents the default <a href="#botcommandscope">scope</a> of bot commands. Default commands are used if no commands with a <a href="#determining-list-of-commands">narrower scope</a> are specified for the user.
struct BotCommandScopeDefault {
    std::string type;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all private chats.
struct BotCommandScopeAllPrivateChats {
    std::string type;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all group and supergroup chats.
struct BotCommandScopeAllGroupChats {
    std::string type;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all group and supergroup chat administrators.
struct BotCommandScopeAllChatAdministrators {
    std::string type;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering a specific chat.
struct BotCommandScopeChat {
    std::string type;
    int chat_id;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all administrators of a specific group or supergroup chat.
struct BotCommandScopeChatAdministrators {
    std::string type;
    int chat_id;
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering a specific member of a group or supergroup chat.
struct BotCommandScopeChatMember {
    std::string type;
    int chat_id;
    int user_id;
};

//This object describes the bot&#39;s menu button in a private chat. It should be one of
struct MenuButton {
    std::string type;
};

//Represents a menu button, which opens the bot&#39;s list of commands.
struct MenuButtonCommands {
    std::string type;
};

//Represents a menu button, which launches a <a href="/bots/webapps">Web App</a>.
struct MenuButtonWebApp {
    std::string type;
    std::string text;
    std::shared_ptr<WebAppInfo> web_app;
};

//Describes that no specific value for the menu button was set.
struct MenuButtonDefault {
    std::string type;
};

//Describes why a request was unsuccessful.
struct ResponseParameters {
    int migrate_to_chat_id;
    int retry_after;
};

//This object represents the content of a media message to be sent. It should be one of
struct InputMedia {
    std::string type;
    std::string media;
    std::string caption;
    std::string parse_mode;
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    bool has_spoiler;
};

//Represents a photo to be sent.
struct InputMediaPhoto {
    std::string type;
    std::string media;
    std::string caption;
    std::string parse_mode;
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    bool has_spoiler;
};

//Represents a video to be sent.
struct InputMediaVideo {
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
struct InputMediaAnimation {
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
struct InputMediaAudio {
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
struct InputMediaDocument {
    std::string type;
    std::string media;
    std::string thumb;
    std::string caption;
    std::string parse_mode;
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    bool disable_content_type_detection;
};

//This object represents the contents of a file to be uploaded. Must be posted using multipart/form-data in the usual way that files are uploaded via the browser.
struct InputFile {
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
struct Stickers {
};

//This object represents a sticker.
struct Sticker {
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
struct StickerSet {
    std::string name;
    std::string title;
    std::string sticker_type;
    bool is_animated;
    bool is_video;
    std::vector<std::shared_ptr<Sticker>> stickers;
    std::shared_ptr<PhotoSize> thumb;
};

//This object describes the position on faces where a mask should be placed by default.
struct MaskPosition {
    std::string point;
    float x_shift;
    float y_shift;
    float scale;
};

//This object represents an incoming inline query. When the user sends an empty query, your bot could return some default or trending results.
struct InlineQuery {
    std::string id;
    std::shared_ptr<User> from;
    std::string query;
    std::string offset;
    std::string chat_type;
    std::shared_ptr<Location> location;
};

//This object represents one result of an inline query. Telegram clients currently support results of the following 20 types:
struct InlineQueryResult {
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
struct InlineQueryResultArticle {
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
struct InlineQueryResultPhoto {
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
struct InlineQueryResultGif {
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
struct InlineQueryResultMpeg4Gif {
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
struct InlineQueryResultVideo {
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
struct InlineQueryResultAudio {
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
struct InlineQueryResultVoice {
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
struct InlineQueryResultDocument {
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
struct InlineQueryResultLocation {
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
struct InlineQueryResultVenue {
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
struct InlineQueryResultContact {
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
struct InlineQueryResultGame {
    std::string type;
    std::string id;
    std::string game_short_name;
    std::shared_ptr<InlineKeyboardMarkup> reply_markup;
};

//Represents a link to a photo stored on the Telegram servers. By default, this photo will be sent by the user with an optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the photo.
struct InlineQueryResultCachedPhoto {
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
struct InlineQueryResultCachedGif {
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
struct InlineQueryResultCachedMpeg4Gif {
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
struct InlineQueryResultCachedSticker {
    std::string type;
    std::string id;
    std::string sticker_file_id;
    std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    std::shared_ptr<InputMessageContent> input_message_content;
};

//Represents a link to a file stored on the Telegram servers. By default, this file will be sent by the user with an optional caption. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the file.
struct InlineQueryResultCachedDocument {
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
struct InlineQueryResultCachedVideo {
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
struct InlineQueryResultCachedVoice {
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
struct InlineQueryResultCachedAudio {
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
struct InputMessageContent {
    std::string message_text;
    std::string parse_mode;
    std::vector<std::shared_ptr<MessageEntity>> entities;
    bool disable_web_page_preview;
};

//Represents the <a href="#inputmessagecontent">content</a> of a text message to be sent as the result of an inline query.
struct InputTextMessageContent {
    std::string message_text;
    std::string parse_mode;
    std::vector<std::shared_ptr<MessageEntity>> entities;
    bool disable_web_page_preview;
};

//Represents the <a href="#inputmessagecontent">content</a> of a location message to be sent as the result of an inline query.
struct InputLocationMessageContent {
    float latitude;
    float longitude;
    float horizontal_accuracy;
    int live_period;
    int heading;
    int proximity_alert_radius;
};

//Represents the <a href="#inputmessagecontent">content</a> of a venue message to be sent as the result of an inline query.
struct InputVenueMessageContent {
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
struct InputContactMessageContent {
    std::string phone_number;
    std::string first_name;
    std::string last_name;
    std::string vcard;
};

//Represents the <a href="#inputmessagecontent">content</a> of an invoice message to be sent as the result of an inline query.
struct InputInvoiceMessageContent {
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
struct ChosenInlineResult {
    std::string result_id;
    std::shared_ptr<User> from;
    std::shared_ptr<Location> location;
    std::string inline_message_id;
    std::string query;
};

//Describes an inline message sent by a <a href="/bots/webapps">Web App</a> on behalf of a user.
struct SentWebAppMessage {
    std::string inline_message_id;
};

//Your bot can accept payments from Telegram users. Please see the <a href="/bots/payments">introduction to payments</a> for more details on the process and how to set up payments for your bot. Please note that users will need Telegram v.4.0 or higher to use payments (released on May 18, 2017).
struct Payments {
};

//This object represents a portion of the price for goods or services.
struct LabeledPrice {
    std::string label;
    int amount;
};

//This object contains basic information about an invoice.
struct Invoice {
    std::string title;
    std::string description;
    std::string start_parameter;
    std::string currency;
    int total_amount;
};

//This object represents a shipping address.
struct ShippingAddress {
    std::string country_code;
    std::string state;
    std::string city;
    std::string street_line1;
    std::string street_line2;
    std::string post_code;
};

//This object represents information about an order.
struct OrderInfo {
    std::string name;
    std::string phone_number;
    std::string email;
    std::shared_ptr<ShippingAddress> shipping_address;
};

//This object represents one shipping option.
struct ShippingOption {
    std::string id;
    std::string title;
    std::vector<std::shared_ptr<LabeledPrice>> prices;
};

//This object contains basic information about a successful payment.
struct SuccessfulPayment {
    std::string currency;
    int total_amount;
    std::string invoice_payload;
    std::string shipping_option_id;
    std::shared_ptr<OrderInfo> order_info;
    std::string telegram_payment_charge_id;
    std::string provider_payment_charge_id;
};

//This object contains information about an incoming shipping query.
struct ShippingQuery {
    std::string id;
    std::shared_ptr<User> from;
    std::string invoice_payload;
    std::shared_ptr<ShippingAddress> shipping_address;
};

//This object contains information about an incoming pre-checkout query.
struct PreCheckoutQuery {
    std::string id;
    std::shared_ptr<User> from;
    std::string currency;
    int total_amount;
    std::string invoice_payload;
    std::string shipping_option_id;
    std::shared_ptr<OrderInfo> order_info;
};

//Describes Telegram Passport data shared with the bot by the user.
struct PassportData {
    std::vector<std::shared_ptr<EncryptedPassportElement>> data;
    std::shared_ptr<EncryptedCredentials> credentials;
};

//This object represents a file uploaded to Telegram Passport. Currently all Telegram Passport files are in JPEG format when decrypted and don&#39;t exceed 10MB.
struct PassportFile {
    std::string file_id;
    std::string file_unique_id;
    int file_size;
    int file_date;
};

//Describes documents or other Telegram Passport elements shared with the bot by the user.
struct EncryptedPassportElement {
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
struct EncryptedCredentials {
    std::string data;
    std::string hash;
    std::string secret;
};

//This object represents an error in the Telegram Passport element which was submitted that should be resolved by the user. It should be one of:
struct PassportElementError {
    std::string source;
    std::string type;
    std::string field_name;
    std::string data_hash;
    std::string message;
};

//Represents an issue in one of the data fields that was provided by the user. The error is considered resolved when the field&#39;s value changes.
struct PassportElementErrorDataField {
    std::string source;
    std::string type;
    std::string field_name;
    std::string data_hash;
    std::string message;
};

//Represents an issue with the front side of a document. The error is considered resolved when the file with the front side of the document changes.
struct PassportElementErrorFrontSide {
    std::string source;
    std::string type;
    std::string file_hash;
    std::string message;
};

//Represents an issue with the reverse side of a document. The error is considered resolved when the file with reverse side of the document changes.
struct PassportElementErrorReverseSide {
    std::string source;
    std::string type;
    std::string file_hash;
    std::string message;
};

//Represents an issue with the selfie with a document. The error is considered resolved when the file with the selfie changes.
struct PassportElementErrorSelfie {
    std::string source;
    std::string type;
    std::string file_hash;
    std::string message;
};

//Represents an issue with a document scan. The error is considered resolved when the file with the document scan changes.
struct PassportElementErrorFile {
    std::string source;
    std::string type;
    std::string file_hash;
    std::string message;
};

//Represents an issue with a list of scans. The error is considered resolved when the list of files containing the scans changes.
struct PassportElementErrorFiles {
    std::string source;
    std::string type;
    std::string file_hashes;
    std::string message;
};

//Represents an issue with one of the files that constitute the translation of a document. The error is considered resolved when the file changes.
struct PassportElementErrorTranslationFile {
    std::string source;
    std::string type;
    std::string file_hash;
    std::string message;
};

//Represents an issue with the translated version of a document. The error is considered resolved when a file with the document translation change.
struct PassportElementErrorTranslationFiles {
    std::string source;
    std::string type;
    std::string file_hashes;
    std::string message;
};

//Represents an issue in an unspecified place. The error is considered resolved when new data is added.
struct PassportElementErrorUnspecified {
    std::string source;
    std::string type;
    std::string element_hash;
    std::string message;
};

//Your bot can offer users <strong>HTML5 games</strong> to play solo or to compete against each other in groups and one-on-one chats. Create games via <a href="https://t.me/botfather">@BotFather</a> using the <em>/newgame</em> command. Please note that this kind of power requires responsibility: you will need to accept the terms for each game that your bots will be offering.
struct Games {
};

//This object represents a game. Use BotFather to create and edit games, their short names will act as unique identifiers.
struct Game {
    std::string title;
    std::string description;
    std::vector<std::shared_ptr<PhotoSize>> photo;
    std::string text;
    std::vector<std::shared_ptr<MessageEntity>> text_entities;
    std::shared_ptr<Animation> animation;
};

//A placeholder, currently holds no information. Use <a href="https://t.me/botfather">BotFather</a> to set up your game.
struct CallbackGame {
};

//This object represents one row of the high scores table for a game.
struct GameHighScore {
    int position;
    std::shared_ptr<User> user;
    int score;
};

inline void from_json(const json &j, User &name);

inline void to_json(json &j, User &name);

inline void from_json(const json &j, Chat &name);

inline void to_json(json &j, Chat &name);

inline void from_json(const json &j, Message &name);

inline void to_json(json &j, Message &name);

inline void from_json(const json &j, MessageId &name);

inline void to_json(json &j, MessageId &name);

inline void from_json(const json &j, MessageEntity &name);

inline void to_json(json &j, MessageEntity &name);

inline void from_json(const json &j, PhotoSize &name);

inline void to_json(json &j, PhotoSize &name);

inline void from_json(const json &j, Animation &name);

inline void to_json(json &j, Animation &name);

inline void from_json(const json &j, Audio &name);

inline void to_json(json &j, Audio &name);

inline void from_json(const json &j, Document &name);

inline void to_json(json &j, Document &name);

inline void from_json(const json &j, Video &name);

inline void to_json(json &j, Video &name);

inline void from_json(const json &j, VideoNote &name);

inline void to_json(json &j, VideoNote &name);

inline void from_json(const json &j, Voice &name);

inline void to_json(json &j, Voice &name);

inline void from_json(const json &j, Contact &name);

inline void to_json(json &j, Contact &name);

inline void from_json(const json &j, Dice &name);

inline void to_json(json &j, Dice &name);

inline void from_json(const json &j, PollOption &name);

inline void to_json(json &j, PollOption &name);

inline void from_json(const json &j, PollAnswer &name);

inline void to_json(json &j, PollAnswer &name);

inline void from_json(const json &j, Poll &name);

inline void to_json(json &j, Poll &name);

inline void from_json(const json &j, Location &name);

inline void to_json(json &j, Location &name);

inline void from_json(const json &j, Venue &name);

inline void to_json(json &j, Venue &name);

inline void from_json(const json &j, WebAppData &name);

inline void to_json(json &j, WebAppData &name);

inline void from_json(const json &j, ProximityAlertTriggered &name);

inline void to_json(json &j, ProximityAlertTriggered &name);

inline void from_json(const json &j, MessageAutoDeleteTimerChanged &name);

inline void to_json(json &j, MessageAutoDeleteTimerChanged &name);

inline void from_json(const json &j, ForumTopicCreated &name);

inline void to_json(json &j, ForumTopicCreated &name);

inline void from_json(const json &j, ForumTopicClosed &name);

inline void to_json(json &j, ForumTopicClosed &name);

inline void from_json(const json &j, ForumTopicEdited &name);

inline void to_json(json &j, ForumTopicEdited &name);

inline void from_json(const json &j, ForumTopicReopened &name);

inline void to_json(json &j, ForumTopicReopened &name);

inline void from_json(const json &j, GeneralForumTopicHidden &name);

inline void to_json(json &j, GeneralForumTopicHidden &name);

inline void from_json(const json &j, GeneralForumTopicUnhidden &name);

inline void to_json(json &j, GeneralForumTopicUnhidden &name);

inline void from_json(const json &j, UserShared &name);

inline void to_json(json &j, UserShared &name);

inline void from_json(const json &j, ChatShared &name);

inline void to_json(json &j, ChatShared &name);

inline void from_json(const json &j, WriteAccessAllowed &name);

inline void to_json(json &j, WriteAccessAllowed &name);

inline void from_json(const json &j, VideoChatScheduled &name);

inline void to_json(json &j, VideoChatScheduled &name);

inline void from_json(const json &j, VideoChatStarted &name);

inline void to_json(json &j, VideoChatStarted &name);

inline void from_json(const json &j, VideoChatEnded &name);

inline void to_json(json &j, VideoChatEnded &name);

inline void from_json(const json &j, VideoChatParticipantsInvited &name);

inline void to_json(json &j, VideoChatParticipantsInvited &name);

inline void from_json(const json &j, UserProfilePhotos &name);

inline void to_json(json &j, UserProfilePhotos &name);

inline void from_json(const json &j, File &name);

inline void to_json(json &j, File &name);

inline void from_json(const json &j, WebAppInfo &name);

inline void to_json(json &j, WebAppInfo &name);

inline void from_json(const json &j, ReplyKeyboardMarkup &name);

inline void to_json(json &j, ReplyKeyboardMarkup &name);

inline void from_json(const json &j, KeyboardButton &name);

inline void to_json(json &j, KeyboardButton &name);

inline void from_json(const json &j, KeyboardButtonRequestUser &name);

inline void to_json(json &j, KeyboardButtonRequestUser &name);

inline void from_json(const json &j, KeyboardButtonRequestChat &name);

inline void to_json(json &j, KeyboardButtonRequestChat &name);

inline void from_json(const json &j, KeyboardButtonPollType &name);

inline void to_json(json &j, KeyboardButtonPollType &name);

inline void from_json(const json &j, ReplyKeyboardRemove &name);

inline void to_json(json &j, ReplyKeyboardRemove &name);

inline void from_json(const json &j, InlineKeyboardMarkup &name);

inline void to_json(json &j, InlineKeyboardMarkup &name);

inline void from_json(const json &j, InlineKeyboardButton &name);

inline void to_json(json &j, InlineKeyboardButton &name);

inline void from_json(const json &j, LoginUrl &name);

inline void to_json(json &j, LoginUrl &name);

inline void from_json(const json &j, CallbackQuery &name);

inline void to_json(json &j, CallbackQuery &name);

inline void from_json(const json &j, ForceReply &name);

inline void to_json(json &j, ForceReply &name);

inline void from_json(const json &j, ChatPhoto &name);

inline void to_json(json &j, ChatPhoto &name);

inline void from_json(const json &j, ChatInviteLink &name);

inline void to_json(json &j, ChatInviteLink &name);

inline void from_json(const json &j, ChatAdministratorRights &name);

inline void to_json(json &j, ChatAdministratorRights &name);

inline void from_json(const json &j, ChatMember &name);

inline void to_json(json &j, ChatMember &name);

inline void from_json(const json &j, ChatMemberOwner &name);

inline void to_json(json &j, ChatMemberOwner &name);

inline void from_json(const json &j, ChatMemberAdministrator &name);

inline void to_json(json &j, ChatMemberAdministrator &name);

inline void from_json(const json &j, ChatMemberMember &name);

inline void to_json(json &j, ChatMemberMember &name);

inline void from_json(const json &j, ChatMemberRestricted &name);

inline void to_json(json &j, ChatMemberRestricted &name);

inline void from_json(const json &j, ChatMemberLeft &name);

inline void to_json(json &j, ChatMemberLeft &name);

inline void from_json(const json &j, ChatMemberBanned &name);

inline void to_json(json &j, ChatMemberBanned &name);

inline void from_json(const json &j, ChatMemberUpdated &name);

inline void to_json(json &j, ChatMemberUpdated &name);

inline void from_json(const json &j, ChatJoinRequest &name);

inline void to_json(json &j, ChatJoinRequest &name);

inline void from_json(const json &j, ChatPermissions &name);

inline void to_json(json &j, ChatPermissions &name);

inline void from_json(const json &j, ChatLocation &name);

inline void to_json(json &j, ChatLocation &name);

inline void from_json(const json &j, ForumTopic &name);

inline void to_json(json &j, ForumTopic &name);

inline void from_json(const json &j, BotCommand &name);

inline void to_json(json &j, BotCommand &name);

inline void from_json(const json &j, BotCommandScope &name);

inline void to_json(json &j, BotCommandScope &name);

inline void from_json(const json &j, BotCommandScopeDefault &name);

inline void to_json(json &j, BotCommandScopeDefault &name);

inline void from_json(const json &j, BotCommandScopeAllPrivateChats &name);

inline void to_json(json &j, BotCommandScopeAllPrivateChats &name);

inline void from_json(const json &j, BotCommandScopeAllGroupChats &name);

inline void to_json(json &j, BotCommandScopeAllGroupChats &name);

inline void from_json(const json &j, BotCommandScopeAllChatAdministrators &name);

inline void to_json(json &j, BotCommandScopeAllChatAdministrators &name);

inline void from_json(const json &j, BotCommandScopeChat &name);

inline void to_json(json &j, BotCommandScopeChat &name);

inline void from_json(const json &j, BotCommandScopeChatAdministrators &name);

inline void to_json(json &j, BotCommandScopeChatAdministrators &name);

inline void from_json(const json &j, BotCommandScopeChatMember &name);

inline void to_json(json &j, BotCommandScopeChatMember &name);

inline void from_json(const json &j, MenuButton &name);

inline void to_json(json &j, MenuButton &name);

inline void from_json(const json &j, MenuButtonCommands &name);

inline void to_json(json &j, MenuButtonCommands &name);

inline void from_json(const json &j, MenuButtonWebApp &name);

inline void to_json(json &j, MenuButtonWebApp &name);

inline void from_json(const json &j, MenuButtonDefault &name);

inline void to_json(json &j, MenuButtonDefault &name);

inline void from_json(const json &j, ResponseParameters &name);

inline void to_json(json &j, ResponseParameters &name);

inline void from_json(const json &j, InputMedia &name);

inline void to_json(json &j, InputMedia &name);

inline void from_json(const json &j, InputMediaPhoto &name);

inline void to_json(json &j, InputMediaPhoto &name);

inline void from_json(const json &j, InputMediaVideo &name);

inline void to_json(json &j, InputMediaVideo &name);

inline void from_json(const json &j, InputMediaAnimation &name);

inline void to_json(json &j, InputMediaAnimation &name);

inline void from_json(const json &j, InputMediaAudio &name);

inline void to_json(json &j, InputMediaAudio &name);

inline void from_json(const json &j, InputMediaDocument &name);

inline void to_json(json &j, InputMediaDocument &name);

inline void from_json(const json &j, InputFile &name);

inline void to_json(json &j, InputFile &name);

inline void from_json(const json &j, Stickers &name);

inline void to_json(json &j, Stickers &name);

inline void from_json(const json &j, Sticker &name);

inline void to_json(json &j, Sticker &name);

inline void from_json(const json &j, StickerSet &name);

inline void to_json(json &j, StickerSet &name);

inline void from_json(const json &j, MaskPosition &name);

inline void to_json(json &j, MaskPosition &name);

inline void from_json(const json &j, InlineQuery &name);

inline void to_json(json &j, InlineQuery &name);

inline void from_json(const json &j, InlineQueryResult &name);

inline void to_json(json &j, InlineQueryResult &name);

inline void from_json(const json &j, InlineQueryResultArticle &name);

inline void to_json(json &j, InlineQueryResultArticle &name);

inline void from_json(const json &j, InlineQueryResultPhoto &name);

inline void to_json(json &j, InlineQueryResultPhoto &name);

inline void from_json(const json &j, InlineQueryResultGif &name);

inline void to_json(json &j, InlineQueryResultGif &name);

inline void from_json(const json &j, InlineQueryResultMpeg4Gif &name);

inline void to_json(json &j, InlineQueryResultMpeg4Gif &name);

inline void from_json(const json &j, InlineQueryResultVideo &name);

inline void to_json(json &j, InlineQueryResultVideo &name);

inline void from_json(const json &j, InlineQueryResultAudio &name);

inline void to_json(json &j, InlineQueryResultAudio &name);

inline void from_json(const json &j, InlineQueryResultVoice &name);

inline void to_json(json &j, InlineQueryResultVoice &name);

inline void from_json(const json &j, InlineQueryResultDocument &name);

inline void to_json(json &j, InlineQueryResultDocument &name);

inline void from_json(const json &j, InlineQueryResultLocation &name);

inline void to_json(json &j, InlineQueryResultLocation &name);

inline void from_json(const json &j, InlineQueryResultVenue &name);

inline void to_json(json &j, InlineQueryResultVenue &name);

inline void from_json(const json &j, InlineQueryResultContact &name);

inline void to_json(json &j, InlineQueryResultContact &name);

inline void from_json(const json &j, InlineQueryResultGame &name);

inline void to_json(json &j, InlineQueryResultGame &name);

inline void from_json(const json &j, InlineQueryResultCachedPhoto &name);

inline void to_json(json &j, InlineQueryResultCachedPhoto &name);

inline void from_json(const json &j, InlineQueryResultCachedGif &name);

inline void to_json(json &j, InlineQueryResultCachedGif &name);

inline void from_json(const json &j, InlineQueryResultCachedMpeg4Gif &name);

inline void to_json(json &j, InlineQueryResultCachedMpeg4Gif &name);

inline void from_json(const json &j, InlineQueryResultCachedSticker &name);

inline void to_json(json &j, InlineQueryResultCachedSticker &name);

inline void from_json(const json &j, InlineQueryResultCachedDocument &name);

inline void to_json(json &j, InlineQueryResultCachedDocument &name);

inline void from_json(const json &j, InlineQueryResultCachedVideo &name);

inline void to_json(json &j, InlineQueryResultCachedVideo &name);

inline void from_json(const json &j, InlineQueryResultCachedVoice &name);

inline void to_json(json &j, InlineQueryResultCachedVoice &name);

inline void from_json(const json &j, InlineQueryResultCachedAudio &name);

inline void to_json(json &j, InlineQueryResultCachedAudio &name);

inline void from_json(const json &j, InputMessageContent &name);

inline void to_json(json &j, InputMessageContent &name);

inline void from_json(const json &j, InputTextMessageContent &name);

inline void to_json(json &j, InputTextMessageContent &name);

inline void from_json(const json &j, InputLocationMessageContent &name);

inline void to_json(json &j, InputLocationMessageContent &name);

inline void from_json(const json &j, InputVenueMessageContent &name);

inline void to_json(json &j, InputVenueMessageContent &name);

inline void from_json(const json &j, InputContactMessageContent &name);

inline void to_json(json &j, InputContactMessageContent &name);

inline void from_json(const json &j, InputInvoiceMessageContent &name);

inline void to_json(json &j, InputInvoiceMessageContent &name);

inline void from_json(const json &j, ChosenInlineResult &name);

inline void to_json(json &j, ChosenInlineResult &name);

inline void from_json(const json &j, SentWebAppMessage &name);

inline void to_json(json &j, SentWebAppMessage &name);

inline void from_json(const json &j, Payments &name);

inline void to_json(json &j, Payments &name);

inline void from_json(const json &j, LabeledPrice &name);

inline void to_json(json &j, LabeledPrice &name);

inline void from_json(const json &j, Invoice &name);

inline void to_json(json &j, Invoice &name);

inline void from_json(const json &j, ShippingAddress &name);

inline void to_json(json &j, ShippingAddress &name);

inline void from_json(const json &j, OrderInfo &name);

inline void to_json(json &j, OrderInfo &name);

inline void from_json(const json &j, ShippingOption &name);

inline void to_json(json &j, ShippingOption &name);

inline void from_json(const json &j, SuccessfulPayment &name);

inline void to_json(json &j, SuccessfulPayment &name);

inline void from_json(const json &j, ShippingQuery &name);

inline void to_json(json &j, ShippingQuery &name);

inline void from_json(const json &j, PreCheckoutQuery &name);

inline void to_json(json &j, PreCheckoutQuery &name);

inline void from_json(const json &j, PassportData &name);

inline void to_json(json &j, PassportData &name);

inline void from_json(const json &j, PassportFile &name);

inline void to_json(json &j, PassportFile &name);

inline void from_json(const json &j, EncryptedPassportElement &name);

inline void to_json(json &j, EncryptedPassportElement &name);

inline void from_json(const json &j, EncryptedCredentials &name);

inline void to_json(json &j, EncryptedCredentials &name);

inline void from_json(const json &j, PassportElementError &name);

inline void to_json(json &j, PassportElementError &name);

inline void from_json(const json &j, PassportElementErrorDataField &name);

inline void to_json(json &j, PassportElementErrorDataField &name);

inline void from_json(const json &j, PassportElementErrorFrontSide &name);

inline void to_json(json &j, PassportElementErrorFrontSide &name);

inline void from_json(const json &j, PassportElementErrorReverseSide &name);

inline void to_json(json &j, PassportElementErrorReverseSide &name);

inline void from_json(const json &j, PassportElementErrorSelfie &name);

inline void to_json(json &j, PassportElementErrorSelfie &name);

inline void from_json(const json &j, PassportElementErrorFile &name);

inline void to_json(json &j, PassportElementErrorFile &name);

inline void from_json(const json &j, PassportElementErrorFiles &name);

inline void to_json(json &j, PassportElementErrorFiles &name);

inline void from_json(const json &j, PassportElementErrorTranslationFile &name);

inline void to_json(json &j, PassportElementErrorTranslationFile &name);

inline void from_json(const json &j, PassportElementErrorTranslationFiles &name);

inline void to_json(json &j, PassportElementErrorTranslationFiles &name);

inline void from_json(const json &j, PassportElementErrorUnspecified &name);

inline void to_json(json &j, PassportElementErrorUnspecified &name);

inline void from_json(const json &j, Games &name);

inline void to_json(json &j, Games &name);

inline void from_json(const json &j, Game &name);

inline void to_json(json &j, Game &name);

inline void from_json(const json &j, CallbackGame &name);

inline void to_json(json &j, CallbackGame &name);

inline void from_json(const json &j, GameHighScore &name);

inline void to_json(json &j, GameHighScore &name);

inline void from_json(const json &j, User &name) {
    name.id = j.contains("id") ? j.at("id").get<int>() : 0;
    name.is_bot = j.contains("is_bot") ? j.at("is_bot").get<bool>() : false;
    name.first_name = j.contains("first_name") ? j.at("first_name").get<std::string>() : "";
    name.last_name = j.contains("last_name") ? j.at("last_name").get<std::string>() : "";
    name.username = j.contains("username") ? j.at("username").get<std::string>() : "";
    name.language_code = j.contains("language_code") ? j.at("language_code").get<std::string>() : "";
    name.is_premium = j.contains("is_premium") ? j.at("is_premium").get<bool>() : false;
    name.added_to_attachment_menu = j.contains("added_to_attachment_menu") ? j.at(
            "added_to_attachment_menu").get<bool>() : false;
    name.can_join_groups = j.contains("can_join_groups") ? j.at("can_join_groups").get<bool>() : false;
    name.can_read_all_group_messages = j.contains("can_read_all_group_messages") ? j.at(
            "can_read_all_group_messages").get<bool>() : false;
    name.supports_inline_queries = j.contains("supports_inline_queries") ? j.at(
            "supports_inline_queries").get<bool>() : false;
}

inline void to_json(json &j, const User &name) {
    j = json::object();
    j["id"] = name.id;
    j["is_bot"] = name.is_bot;
    j["first_name"] = name.first_name;
    j["last_name"] = name.last_name;
    j["username"] = name.username;
    j["language_code"] = name.language_code;
    j["is_premium"] = name.is_premium;
    j["added_to_attachment_menu"] = name.added_to_attachment_menu;
    j["can_join_groups"] = name.can_join_groups;
    j["can_read_all_group_messages"] = name.can_read_all_group_messages;
    j["supports_inline_queries"] = name.supports_inline_queries;
}

inline void from_json(const json &j, Chat &name) {
    name.id = j.contains("id") ? j.at("id").get<int>() : 0;
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.username = j.contains("username") ? j.at("username").get<std::string>() : "";
    name.first_name = j.contains("first_name") ? j.at("first_name").get<std::string>() : "";
    name.last_name = j.contains("last_name") ? j.at("last_name").get<std::string>() : "";
    name.is_forum = j.contains("is_forum") ? j.at("is_forum").get<bool>() : false;
    name.photo = j.contains("photo") ? std::make_shared<ChatPhoto>(j.at("photo").get<ChatPhoto>()) : nullptr;
    name.active_usernames = j.contains("active_usernames") ? j.at("active_usernames").get<std::string>() : "";
    name.emoji_status_custom_emoji_id = j.contains("emoji_status_custom_emoji_id") ? j.at(
            "emoji_status_custom_emoji_id").get<std::string>() : "";
    name.bio = j.contains("bio") ? j.at("bio").get<std::string>() : "";
    name.has_private_forwards = j.contains("has_private_forwards") ? j.at("has_private_forwards").get<bool>()
                                                                   : false;
    name.has_restricted_voice_and_video_messages = j.contains("has_restricted_voice_and_video_messages") ? j.at(
            "has_restricted_voice_and_video_messages").get<bool>() : false;
    name.join_to_send_messages = j.contains("join_to_send_messages") ? j.at("join_to_send_messages").get<bool>()
                                                                     : false;
    name.join_by_request = j.contains("join_by_request") ? j.at("join_by_request").get<bool>() : false;
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.invite_link = j.contains("invite_link") ? j.at("invite_link").get<std::string>() : "";
    name.pinned_message = j.contains("pinned_message") ? std::make_shared<Message>(
            j.at("pinned_message").get<Message>()) : nullptr;
    name.permissions = j.contains("permissions") ? std::make_shared<ChatPermissions>(
            j.at("permissions").get<ChatPermissions>()) : nullptr;
    name.slow_mode_delay = j.contains("slow_mode_delay") ? j.at("slow_mode_delay").get<int>() : 0;
    name.message_auto_delete_time = j.contains("message_auto_delete_time") ? j.at(
            "message_auto_delete_time").get<int>() : 0;
    name.has_aggressive_anti_spam_enabled = j.contains("has_aggressive_anti_spam_enabled") ? j.at(
            "has_aggressive_anti_spam_enabled").get<bool>() : false;
    name.has_hidden_members = j.contains("has_hidden_members") ? j.at("has_hidden_members").get<bool>() : false;
    name.has_protected_content = j.contains("has_protected_content") ? j.at("has_protected_content").get<bool>()
                                                                     : false;
    name.sticker_set_name = j.contains("sticker_set_name") ? j.at("sticker_set_name").get<std::string>() : "";
    name.can_set_sticker_set = j.contains("can_set_sticker_set") ? j.at("can_set_sticker_set").get<bool>() : false;
    name.linked_chat_id = j.contains("linked_chat_id") ? j.at("linked_chat_id").get<int>() : 0;
    name.location = j.contains("location") ? std::make_shared<ChatLocation>(j.at("location").get<ChatLocation>())
                                           : nullptr;
}

inline void to_json(json &j, const Chat &name) {
    j = json::object();
    j["id"] = name.id;
    j["type"] = name.type;
    j["title"] = name.title;
    j["username"] = name.username;
    j["first_name"] = name.first_name;
    j["last_name"] = name.last_name;
    j["is_forum"] = name.is_forum;
    to_json(j["photo"], *name.photo);
    j["active_usernames"] = name.active_usernames;
    j["emoji_status_custom_emoji_id"] = name.emoji_status_custom_emoji_id;
    j["bio"] = name.bio;
    j["has_private_forwards"] = name.has_private_forwards;
    j["has_restricted_voice_and_video_messages"] = name.has_restricted_voice_and_video_messages;
    j["join_to_send_messages"] = name.join_to_send_messages;
    j["join_by_request"] = name.join_by_request;
    j["description"] = name.description;
    j["invite_link"] = name.invite_link;
    to_json(j["pinned_message"], *name.pinned_message);
    to_json(j["permissions"], *name.permissions);
    j["slow_mode_delay"] = name.slow_mode_delay;
    j["message_auto_delete_time"] = name.message_auto_delete_time;
    j["has_aggressive_anti_spam_enabled"] = name.has_aggressive_anti_spam_enabled;
    j["has_hidden_members"] = name.has_hidden_members;
    j["has_protected_content"] = name.has_protected_content;
    j["sticker_set_name"] = name.sticker_set_name;
    j["can_set_sticker_set"] = name.can_set_sticker_set;
    j["linked_chat_id"] = name.linked_chat_id;
    to_json(j["location"], *name.location);
}

inline void from_json(const json &j, Message &name) {
    name.message_id = j.contains("message_id") ? j.at("message_id").get<int>() : 0;
    name.message_thread_id = j.contains("message_thread_id") ? j.at("message_thread_id").get<int>() : 0;
    name.from = j.contains("from") ? std::make_shared<User>(j.at("from").get<User>()) : nullptr;
    name.sender_chat = j.contains("sender_chat") ? std::make_shared<Chat>(j.at("sender_chat").get<Chat>())
                                                 : nullptr;
    name.date = j.contains("date") ? j.at("date").get<int>() : 0;
    name.chat = j.contains("chat") ? std::make_shared<Chat>(j.at("chat").get<Chat>()) : nullptr;
    name.forward_from = j.contains("forward_from") ? std::make_shared<User>(j.at("forward_from").get<User>())
                                                   : nullptr;
    name.forward_from_chat = j.contains("forward_from_chat") ? std::make_shared<Chat>(
            j.at("forward_from_chat").get<Chat>()) : nullptr;
    name.forward_from_message_id = j.contains("forward_from_message_id") ? j.at(
            "forward_from_message_id").get<int>() : 0;
    name.forward_signature = j.contains("forward_signature") ? j.at("forward_signature").get<std::string>() : "";
    name.forward_sender_name = j.contains("forward_sender_name") ? j.at("forward_sender_name").get<std::string>()
                                                                 : "";
    name.forward_date = j.contains("forward_date") ? j.at("forward_date").get<int>() : 0;
    name.is_topic_message = j.contains("is_topic_message") ? j.at("is_topic_message").get<bool>() : false;
    name.is_automatic_forward = j.contains("is_automatic_forward") ? j.at("is_automatic_forward").get<bool>()
                                                                   : false;
    name.reply_to_message = j.contains("reply_to_message") ? std::make_shared<Message>(
            j.at("reply_to_message").get<Message>()) : nullptr;
    name.via_bot = j.contains("via_bot") ? std::make_shared<User>(j.at("via_bot").get<User>()) : nullptr;
    name.edit_date = j.contains("edit_date") ? j.at("edit_date").get<int>() : 0;
    name.has_protected_content = j.contains("has_protected_content") ? j.at("has_protected_content").get<bool>()
                                                                     : false;
    name.media_group_id = j.contains("media_group_id") ? j.at("media_group_id").get<std::string>() : "";
    name.author_signature = j.contains("author_signature") ? j.at("author_signature").get<std::string>() : "";
    name.text = j.contains("text") ? j.at("text").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> entities;
    if (j.contains("entities")) {
        for (auto a: j.at("entities").get<std::vector<MessageEntity>>()) {
            entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.entities = entities;
    name.animation = j.contains("animation") ? std::make_shared<Animation>(j.at("animation").get<Animation>())
                                             : nullptr;
    name.audio = j.contains("audio") ? std::make_shared<Audio>(j.at("audio").get<Audio>()) : nullptr;
    name.document = j.contains("document") ? std::make_shared<Document>(j.at("document").get<Document>()) : nullptr;
    std::vector<std::shared_ptr<PhotoSize>> photo;
    if (j.contains("photo")) {
        for (auto a: j.at("photo").get<std::vector<PhotoSize>>()) {
            photo.push_back(std::make_shared<PhotoSize>(a));
        }
    }
    name.photo = photo;
    name.sticker = j.contains("sticker") ? std::make_shared<Sticker>(j.at("sticker").get<Sticker>()) : nullptr;
    name.video = j.contains("video") ? std::make_shared<Video>(j.at("video").get<Video>()) : nullptr;
    name.video_note = j.contains("video_note") ? std::make_shared<VideoNote>(j.at("video_note").get<VideoNote>())
                                               : nullptr;
    name.voice = j.contains("voice") ? std::make_shared<Voice>(j.at("voice").get<Voice>()) : nullptr;
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.has_media_spoiler = j.contains("has_media_spoiler") ? j.at("has_media_spoiler").get<bool>() : false;
    name.contact = j.contains("contact") ? std::make_shared<Contact>(j.at("contact").get<Contact>()) : nullptr;
    name.dice = j.contains("dice") ? std::make_shared<Dice>(j.at("dice").get<Dice>()) : nullptr;
    name.game = j.contains("game") ? std::make_shared<Game>(j.at("game").get<Game>()) : nullptr;
    name.poll = j.contains("poll") ? std::make_shared<Poll>(j.at("poll").get<Poll>()) : nullptr;
    name.venue = j.contains("venue") ? std::make_shared<Venue>(j.at("venue").get<Venue>()) : nullptr;
    name.location = j.contains("location") ? std::make_shared<Location>(j.at("location").get<Location>()) : nullptr;
    std::vector<std::shared_ptr<User>> new_chat_members;
    if (j.contains("new_chat_members")) {
        for (auto a: j.at("new_chat_members").get<std::vector<User>>()) {
            new_chat_members.push_back(std::make_shared<User>(a));
        }
    }
    name.new_chat_members = new_chat_members;
    name.left_chat_member = j.contains("left_chat_member") ? std::make_shared<User>(
            j.at("left_chat_member").get<User>()) : nullptr;
    name.new_chat_title = j.contains("new_chat_title") ? j.at("new_chat_title").get<std::string>() : "";
    std::vector<std::shared_ptr<PhotoSize>> new_chat_photo;
    if (j.contains("new_chat_photo")) {
        for (auto a: j.at("new_chat_photo").get<std::vector<PhotoSize>>()) {
            new_chat_photo.push_back(std::make_shared<PhotoSize>(a));
        }
    }
    name.new_chat_photo = new_chat_photo;
    name.delete_chat_photo = j.contains("delete_chat_photo") ? j.at("delete_chat_photo").get<bool>() : false;
    name.group_chat_created = j.contains("group_chat_created") ? j.at("group_chat_created").get<bool>() : false;
    name.supergroup_chat_created = j.contains("supergroup_chat_created") ? j.at(
            "supergroup_chat_created").get<bool>() : false;
    name.channel_chat_created = j.contains("channel_chat_created") ? j.at("channel_chat_created").get<bool>()
                                                                   : false;
    name.message_auto_delete_timer_changed = j.contains("message_auto_delete_timer_changed")
                                             ? std::make_shared<MessageAutoDeleteTimerChanged>(
                    j.at("message_auto_delete_timer_changed").get<MessageAutoDeleteTimerChanged>()) : nullptr;
    name.migrate_to_chat_id = j.contains("migrate_to_chat_id") ? j.at("migrate_to_chat_id").get<int>() : 0;
    name.migrate_from_chat_id = j.contains("migrate_from_chat_id") ? j.at("migrate_from_chat_id").get<int>() : 0;
    name.pinned_message = j.contains("pinned_message") ? std::make_shared<Message>(
            j.at("pinned_message").get<Message>()) : nullptr;
    name.invoice = j.contains("invoice") ? std::make_shared<Invoice>(j.at("invoice").get<Invoice>()) : nullptr;
    name.successful_payment = j.contains("successful_payment") ? std::make_shared<SuccessfulPayment>(
            j.at("successful_payment").get<SuccessfulPayment>()) : nullptr;
    name.user_shared = j.contains("user_shared") ? std::make_shared<UserShared>(
            j.at("user_shared").get<UserShared>()) : nullptr;
    name.chat_shared = j.contains("chat_shared") ? std::make_shared<ChatShared>(
            j.at("chat_shared").get<ChatShared>()) : nullptr;
    name.connected_website = j.contains("connected_website") ? j.at("connected_website").get<std::string>() : "";
    name.write_access_allowed = j.contains("write_access_allowed") ? std::make_shared<WriteAccessAllowed>(
            j.at("write_access_allowed").get<WriteAccessAllowed>()) : nullptr;
    name.passport_data = j.contains("passport_data") ? std::make_shared<PassportData>(
            j.at("passport_data").get<PassportData>()) : nullptr;
    name.proximity_alert_triggered = j.contains("proximity_alert_triggered")
                                     ? std::make_shared<ProximityAlertTriggered>(
                    j.at("proximity_alert_triggered").get<ProximityAlertTriggered>()) : nullptr;
    name.forum_topic_created = j.contains("forum_topic_created") ? std::make_shared<ForumTopicCreated>(
            j.at("forum_topic_created").get<ForumTopicCreated>()) : nullptr;
    name.forum_topic_edited = j.contains("forum_topic_edited") ? std::make_shared<ForumTopicEdited>(
            j.at("forum_topic_edited").get<ForumTopicEdited>()) : nullptr;
    name.forum_topic_closed = j.contains("forum_topic_closed") ? std::make_shared<ForumTopicClosed>(
            j.at("forum_topic_closed").get<ForumTopicClosed>()) : nullptr;
    name.forum_topic_reopened = j.contains("forum_topic_reopened") ? std::make_shared<ForumTopicReopened>(
            j.at("forum_topic_reopened").get<ForumTopicReopened>()) : nullptr;
    name.general_forum_topic_hidden = j.contains("general_forum_topic_hidden")
                                      ? std::make_shared<GeneralForumTopicHidden>(
                    j.at("general_forum_topic_hidden").get<GeneralForumTopicHidden>()) : nullptr;
    name.general_forum_topic_unhidden = j.contains("general_forum_topic_unhidden")
                                        ? std::make_shared<GeneralForumTopicUnhidden>(
                    j.at("general_forum_topic_unhidden").get<GeneralForumTopicUnhidden>()) : nullptr;
    name.video_chat_scheduled = j.contains("video_chat_scheduled") ? std::make_shared<VideoChatScheduled>(
            j.at("video_chat_scheduled").get<VideoChatScheduled>()) : nullptr;
    name.video_chat_started = j.contains("video_chat_started") ? std::make_shared<VideoChatStarted>(
            j.at("video_chat_started").get<VideoChatStarted>()) : nullptr;
    name.video_chat_ended = j.contains("video_chat_ended") ? std::make_shared<VideoChatEnded>(
            j.at("video_chat_ended").get<VideoChatEnded>()) : nullptr;
    name.video_chat_participants_invited = j.contains("video_chat_participants_invited")
                                           ? std::make_shared<VideoChatParticipantsInvited>(
                    j.at("video_chat_participants_invited").get<VideoChatParticipantsInvited>()) : nullptr;
    name.web_app_data = j.contains("web_app_data") ? std::make_shared<WebAppData>(
            j.at("web_app_data").get<WebAppData>()) : nullptr;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
}

inline void to_json(json &j, const Message &name) {
    j = json::object();
    j["message_id"] = name.message_id;
    j["message_thread_id"] = name.message_thread_id;
    to_json(j["from"], *name.from);
    to_json(j["sender_chat"], *name.sender_chat);
    j["date"] = name.date;
    to_json(j["chat"], *name.chat);
    to_json(j["forward_from"], *name.forward_from);
    to_json(j["forward_from_chat"], *name.forward_from_chat);
    j["forward_from_message_id"] = name.forward_from_message_id;
    j["forward_signature"] = name.forward_signature;
    j["forward_sender_name"] = name.forward_sender_name;
    j["forward_date"] = name.forward_date;
    j["is_topic_message"] = name.is_topic_message;
    j["is_automatic_forward"] = name.is_automatic_forward;
    to_json(j["reply_to_message"], *name.reply_to_message);
    to_json(j["via_bot"], *name.via_bot);
    j["edit_date"] = name.edit_date;
    j["has_protected_content"] = name.has_protected_content;
    j["media_group_id"] = name.media_group_id;
    j["author_signature"] = name.author_signature;
    j["text"] = name.text;
    for (auto a: j.at("entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["entities"].push_back(u);
    }
    to_json(j["animation"], *name.animation);
    to_json(j["audio"], *name.audio);
    to_json(j["document"], *name.document);
    for (auto a: j.at("photo").get<std::vector<PhotoSize>>()) {
        auto u = json::object();
        to_json(u, a);
        j["photo"].push_back(u);
    }
    to_json(j["sticker"], *name.sticker);
    to_json(j["video"], *name.video);
    to_json(j["video_note"], *name.video_note);
    to_json(j["voice"], *name.voice);
    j["caption"] = name.caption;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["has_media_spoiler"] = name.has_media_spoiler;
    to_json(j["contact"], *name.contact);
    to_json(j["dice"], *name.dice);
    to_json(j["game"], *name.game);
    to_json(j["poll"], *name.poll);
    to_json(j["venue"], *name.venue);
    to_json(j["location"], *name.location);
    for (auto a: j.at("new_chat_members").get<std::vector<User>>()) {
        auto u = json::object();
        to_json(u, a);
        j["new_chat_members"].push_back(u);
    }
    to_json(j["left_chat_member"], *name.left_chat_member);
    j["new_chat_title"] = name.new_chat_title;
    for (auto a: j.at("new_chat_photo").get<std::vector<PhotoSize>>()) {
        auto u = json::object();
        to_json(u, a);
        j["new_chat_photo"].push_back(u);
    }
    j["delete_chat_photo"] = name.delete_chat_photo;
    j["group_chat_created"] = name.group_chat_created;
    j["supergroup_chat_created"] = name.supergroup_chat_created;
    j["channel_chat_created"] = name.channel_chat_created;
    to_json(j["message_auto_delete_timer_changed"], *name.message_auto_delete_timer_changed);
    j["migrate_to_chat_id"] = name.migrate_to_chat_id;
    j["migrate_from_chat_id"] = name.migrate_from_chat_id;
    to_json(j["pinned_message"], *name.pinned_message);
    to_json(j["invoice"], *name.invoice);
    to_json(j["successful_payment"], *name.successful_payment);
    to_json(j["user_shared"], *name.user_shared);
    to_json(j["chat_shared"], *name.chat_shared);
    j["connected_website"] = name.connected_website;
    to_json(j["write_access_allowed"], *name.write_access_allowed);
    to_json(j["passport_data"], *name.passport_data);
    to_json(j["proximity_alert_triggered"], *name.proximity_alert_triggered);
    to_json(j["forum_topic_created"], *name.forum_topic_created);
    to_json(j["forum_topic_edited"], *name.forum_topic_edited);
    to_json(j["forum_topic_closed"], *name.forum_topic_closed);
    to_json(j["forum_topic_reopened"], *name.forum_topic_reopened);
    to_json(j["general_forum_topic_hidden"], *name.general_forum_topic_hidden);
    to_json(j["general_forum_topic_unhidden"], *name.general_forum_topic_unhidden);
    to_json(j["video_chat_scheduled"], *name.video_chat_scheduled);
    to_json(j["video_chat_started"], *name.video_chat_started);
    to_json(j["video_chat_ended"], *name.video_chat_ended);
    to_json(j["video_chat_participants_invited"], *name.video_chat_participants_invited);
    to_json(j["web_app_data"], *name.web_app_data);
    to_json(j["reply_markup"], *name.reply_markup);
}

inline void from_json(const json &j, MessageId &name) {
    name.message_id = j.contains("message_id") ? j.at("message_id").get<int>() : 0;
}

inline void to_json(json &j, const MessageId &name) {
    j = json::object();
    j["message_id"] = name.message_id;
}

inline void from_json(const json &j, MessageEntity &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.offset = j.contains("offset") ? j.at("offset").get<int>() : 0;
    name.length = j.contains("length") ? j.at("length").get<int>() : 0;
    name.url = j.contains("url") ? j.at("url").get<std::string>() : "";
    name.user = j.contains("user") ? std::make_shared<User>(j.at("user").get<User>()) : nullptr;
    name.language = j.contains("language") ? j.at("language").get<std::string>() : "";
    name.custom_emoji_id = j.contains("custom_emoji_id") ? j.at("custom_emoji_id").get<std::string>() : "";
}

inline void to_json(json &j, const MessageEntity &name) {
    j = json::object();
    j["type"] = name.type;
    j["offset"] = name.offset;
    j["length"] = name.length;
    j["url"] = name.url;
    to_json(j["user"], *name.user);
    j["language"] = name.language;
    j["custom_emoji_id"] = name.custom_emoji_id;
}

inline void from_json(const json &j, PhotoSize &name) {
    name.file_id = j.contains("file_id") ? j.at("file_id").get<std::string>() : "";
    name.file_unique_id = j.contains("file_unique_id") ? j.at("file_unique_id").get<std::string>() : "";
    name.width = j.contains("width") ? j.at("width").get<int>() : 0;
    name.height = j.contains("height") ? j.at("height").get<int>() : 0;
    name.file_size = j.contains("file_size") ? j.at("file_size").get<int>() : 0;
}

inline void to_json(json &j, const PhotoSize &name) {
    j = json::object();
    j["file_id"] = name.file_id;
    j["file_unique_id"] = name.file_unique_id;
    j["width"] = name.width;
    j["height"] = name.height;
    j["file_size"] = name.file_size;
}

inline void from_json(const json &j, Animation &name) {
    name.file_id = j.contains("file_id") ? j.at("file_id").get<std::string>() : "";
    name.file_unique_id = j.contains("file_unique_id") ? j.at("file_unique_id").get<std::string>() : "";
    name.width = j.contains("width") ? j.at("width").get<int>() : 0;
    name.height = j.contains("height") ? j.at("height").get<int>() : 0;
    name.duration = j.contains("duration") ? j.at("duration").get<int>() : 0;
    name.thumb = j.contains("thumb") ? std::make_shared<PhotoSize>(j.at("thumb").get<PhotoSize>()) : nullptr;
    name.file_name = j.contains("file_name") ? j.at("file_name").get<std::string>() : "";
    name.mime_type = j.contains("mime_type") ? j.at("mime_type").get<std::string>() : "";
    name.file_size = j.contains("file_size") ? j.at("file_size").get<int>() : 0;
}

inline void to_json(json &j, const Animation &name) {
    j = json::object();
    j["file_id"] = name.file_id;
    j["file_unique_id"] = name.file_unique_id;
    j["width"] = name.width;
    j["height"] = name.height;
    j["duration"] = name.duration;
    to_json(j["thumb"], *name.thumb);
    j["file_name"] = name.file_name;
    j["mime_type"] = name.mime_type;
    j["file_size"] = name.file_size;
}

inline void from_json(const json &j, Audio &name) {
    name.file_id = j.contains("file_id") ? j.at("file_id").get<std::string>() : "";
    name.file_unique_id = j.contains("file_unique_id") ? j.at("file_unique_id").get<std::string>() : "";
    name.duration = j.contains("duration") ? j.at("duration").get<int>() : 0;
    name.performer = j.contains("performer") ? j.at("performer").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.file_name = j.contains("file_name") ? j.at("file_name").get<std::string>() : "";
    name.mime_type = j.contains("mime_type") ? j.at("mime_type").get<std::string>() : "";
    name.file_size = j.contains("file_size") ? j.at("file_size").get<int>() : 0;
    name.thumb = j.contains("thumb") ? std::make_shared<PhotoSize>(j.at("thumb").get<PhotoSize>()) : nullptr;
}

inline void to_json(json &j, const Audio &name) {
    j = json::object();
    j["file_id"] = name.file_id;
    j["file_unique_id"] = name.file_unique_id;
    j["duration"] = name.duration;
    j["performer"] = name.performer;
    j["title"] = name.title;
    j["file_name"] = name.file_name;
    j["mime_type"] = name.mime_type;
    j["file_size"] = name.file_size;
    to_json(j["thumb"], *name.thumb);
}

inline void from_json(const json &j, Document &name) {
    name.file_id = j.contains("file_id") ? j.at("file_id").get<std::string>() : "";
    name.file_unique_id = j.contains("file_unique_id") ? j.at("file_unique_id").get<std::string>() : "";
    name.thumb = j.contains("thumb") ? std::make_shared<PhotoSize>(j.at("thumb").get<PhotoSize>()) : nullptr;
    name.file_name = j.contains("file_name") ? j.at("file_name").get<std::string>() : "";
    name.mime_type = j.contains("mime_type") ? j.at("mime_type").get<std::string>() : "";
    name.file_size = j.contains("file_size") ? j.at("file_size").get<int>() : 0;
}

inline void to_json(json &j, const Document &name) {
    j = json::object();
    j["file_id"] = name.file_id;
    j["file_unique_id"] = name.file_unique_id;
    to_json(j["thumb"], *name.thumb);
    j["file_name"] = name.file_name;
    j["mime_type"] = name.mime_type;
    j["file_size"] = name.file_size;
}

inline void from_json(const json &j, Video &name) {
    name.file_id = j.contains("file_id") ? j.at("file_id").get<std::string>() : "";
    name.file_unique_id = j.contains("file_unique_id") ? j.at("file_unique_id").get<std::string>() : "";
    name.width = j.contains("width") ? j.at("width").get<int>() : 0;
    name.height = j.contains("height") ? j.at("height").get<int>() : 0;
    name.duration = j.contains("duration") ? j.at("duration").get<int>() : 0;
    name.thumb = j.contains("thumb") ? std::make_shared<PhotoSize>(j.at("thumb").get<PhotoSize>()) : nullptr;
    name.file_name = j.contains("file_name") ? j.at("file_name").get<std::string>() : "";
    name.mime_type = j.contains("mime_type") ? j.at("mime_type").get<std::string>() : "";
    name.file_size = j.contains("file_size") ? j.at("file_size").get<int>() : 0;
}

inline void to_json(json &j, const Video &name) {
    j = json::object();
    j["file_id"] = name.file_id;
    j["file_unique_id"] = name.file_unique_id;
    j["width"] = name.width;
    j["height"] = name.height;
    j["duration"] = name.duration;
    to_json(j["thumb"], *name.thumb);
    j["file_name"] = name.file_name;
    j["mime_type"] = name.mime_type;
    j["file_size"] = name.file_size;
}

inline void from_json(const json &j, VideoNote &name) {
    name.file_id = j.contains("file_id") ? j.at("file_id").get<std::string>() : "";
    name.file_unique_id = j.contains("file_unique_id") ? j.at("file_unique_id").get<std::string>() : "";
    name.length = j.contains("length") ? j.at("length").get<int>() : 0;
    name.duration = j.contains("duration") ? j.at("duration").get<int>() : 0;
    name.thumb = j.contains("thumb") ? std::make_shared<PhotoSize>(j.at("thumb").get<PhotoSize>()) : nullptr;
    name.file_size = j.contains("file_size") ? j.at("file_size").get<int>() : 0;
}

inline void to_json(json &j, const VideoNote &name) {
    j = json::object();
    j["file_id"] = name.file_id;
    j["file_unique_id"] = name.file_unique_id;
    j["length"] = name.length;
    j["duration"] = name.duration;
    to_json(j["thumb"], *name.thumb);
    j["file_size"] = name.file_size;
}

inline void from_json(const json &j, Voice &name) {
    name.file_id = j.contains("file_id") ? j.at("file_id").get<std::string>() : "";
    name.file_unique_id = j.contains("file_unique_id") ? j.at("file_unique_id").get<std::string>() : "";
    name.duration = j.contains("duration") ? j.at("duration").get<int>() : 0;
    name.mime_type = j.contains("mime_type") ? j.at("mime_type").get<std::string>() : "";
    name.file_size = j.contains("file_size") ? j.at("file_size").get<int>() : 0;
}

inline void to_json(json &j, const Voice &name) {
    j = json::object();
    j["file_id"] = name.file_id;
    j["file_unique_id"] = name.file_unique_id;
    j["duration"] = name.duration;
    j["mime_type"] = name.mime_type;
    j["file_size"] = name.file_size;
}

inline void from_json(const json &j, Contact &name) {
    name.phone_number = j.contains("phone_number") ? j.at("phone_number").get<std::string>() : "";
    name.first_name = j.contains("first_name") ? j.at("first_name").get<std::string>() : "";
    name.last_name = j.contains("last_name") ? j.at("last_name").get<std::string>() : "";
    name.user_id = j.contains("user_id") ? j.at("user_id").get<int>() : 0;
    name.vcard = j.contains("vcard") ? j.at("vcard").get<std::string>() : "";
}

inline void to_json(json &j, const Contact &name) {
    j = json::object();
    j["phone_number"] = name.phone_number;
    j["first_name"] = name.first_name;
    j["last_name"] = name.last_name;
    j["user_id"] = name.user_id;
    j["vcard"] = name.vcard;
}

inline void from_json(const json &j, Dice &name) {
    name.emoji = j.contains("emoji") ? j.at("emoji").get<std::string>() : "";
    name.value = j.contains("value") ? j.at("value").get<int>() : 0;
}

inline void to_json(json &j, const Dice &name) {
    j = json::object();
    j["emoji"] = name.emoji;
    j["value"] = name.value;
}

inline void from_json(const json &j, PollOption &name) {
    name.text = j.contains("text") ? j.at("text").get<std::string>() : "";
    name.voter_count = j.contains("voter_count") ? j.at("voter_count").get<int>() : 0;
}

inline void to_json(json &j, const PollOption &name) {
    j = json::object();
    j["text"] = name.text;
    j["voter_count"] = name.voter_count;
}

inline void from_json(const json &j, PollAnswer &name) {
    name.poll_id = j.contains("poll_id") ? j.at("poll_id").get<std::string>() : "";
    name.user = j.contains("user") ? std::make_shared<User>(j.at("user").get<User>()) : nullptr;
    name.option_ids = j.contains("option_ids") ? j.at("option_ids").get<int>() : 0;
}

inline void to_json(json &j, const PollAnswer &name) {
    j = json::object();
    j["poll_id"] = name.poll_id;
    to_json(j["user"], *name.user);
    j["option_ids"] = name.option_ids;
}

inline void from_json(const json &j, Poll &name) {
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.question = j.contains("question") ? j.at("question").get<std::string>() : "";
    std::vector<std::shared_ptr<PollOption>> options;
    if (j.contains("options")) {
        for (auto a: j.at("options").get<std::vector<PollOption>>()) {
            options.push_back(std::make_shared<PollOption>(a));
        }
    }
    name.options = options;
    name.total_voter_count = j.contains("total_voter_count") ? j.at("total_voter_count").get<int>() : 0;
    name.is_closed = j.contains("is_closed") ? j.at("is_closed").get<bool>() : false;
    name.is_anonymous = j.contains("is_anonymous") ? j.at("is_anonymous").get<bool>() : false;
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.allows_multiple_answers = j.contains("allows_multiple_answers") ? j.at(
            "allows_multiple_answers").get<bool>() : false;
    name.correct_option_id = j.contains("correct_option_id") ? j.at("correct_option_id").get<int>() : 0;
    name.explanation = j.contains("explanation") ? j.at("explanation").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> explanation_entities;
    if (j.contains("explanation_entities")) {
        for (auto a: j.at("explanation_entities").get<std::vector<MessageEntity>>()) {
            explanation_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.explanation_entities = explanation_entities;
    name.open_period = j.contains("open_period") ? j.at("open_period").get<int>() : 0;
    name.close_date = j.contains("close_date") ? j.at("close_date").get<int>() : 0;
}

inline void to_json(json &j, const Poll &name) {
    j = json::object();
    j["id"] = name.id;
    j["question"] = name.question;
    for (auto a: j.at("options").get<std::vector<PollOption>>()) {
        auto u = json::object();
        to_json(u, a);
        j["options"].push_back(u);
    }
    j["total_voter_count"] = name.total_voter_count;
    j["is_closed"] = name.is_closed;
    j["is_anonymous"] = name.is_anonymous;
    j["type"] = name.type;
    j["allows_multiple_answers"] = name.allows_multiple_answers;
    j["correct_option_id"] = name.correct_option_id;
    j["explanation"] = name.explanation;
    for (auto a: j.at("explanation_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["explanation_entities"].push_back(u);
    }
    j["open_period"] = name.open_period;
    j["close_date"] = name.close_date;
}

inline void from_json(const json &j, Location &name) {
    name.longitude = j.contains("longitude") ? j.at("longitude").get<float>() : 0;
    name.latitude = j.contains("latitude") ? j.at("latitude").get<float>() : 0;
    name.horizontal_accuracy = j.contains("horizontal_accuracy") ? j.at("horizontal_accuracy").get<float>() : 0;
    name.live_period = j.contains("live_period") ? j.at("live_period").get<int>() : 0;
    name.heading = j.contains("heading") ? j.at("heading").get<int>() : 0;
    name.proximity_alert_radius = j.contains("proximity_alert_radius") ? j.at("proximity_alert_radius").get<int>()
                                                                       : 0;
}

inline void to_json(json &j, const Location &name) {
    j = json::object();
    j["longitude"] = name.longitude;
    j["latitude"] = name.latitude;
    j["horizontal_accuracy"] = name.horizontal_accuracy;
    j["live_period"] = name.live_period;
    j["heading"] = name.heading;
    j["proximity_alert_radius"] = name.proximity_alert_radius;
}

inline void from_json(const json &j, Venue &name) {
    name.location = j.contains("location") ? std::make_shared<Location>(j.at("location").get<Location>()) : nullptr;
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.address = j.contains("address") ? j.at("address").get<std::string>() : "";
    name.foursquare_id = j.contains("foursquare_id") ? j.at("foursquare_id").get<std::string>() : "";
    name.foursquare_type = j.contains("foursquare_type") ? j.at("foursquare_type").get<std::string>() : "";
    name.google_place_id = j.contains("google_place_id") ? j.at("google_place_id").get<std::string>() : "";
    name.google_place_type = j.contains("google_place_type") ? j.at("google_place_type").get<std::string>() : "";
}

inline void to_json(json &j, const Venue &name) {
    j = json::object();
    to_json(j["location"], *name.location);
    j["title"] = name.title;
    j["address"] = name.address;
    j["foursquare_id"] = name.foursquare_id;
    j["foursquare_type"] = name.foursquare_type;
    j["google_place_id"] = name.google_place_id;
    j["google_place_type"] = name.google_place_type;
}

inline void from_json(const json &j, WebAppData &name) {
    name.data = j.contains("data") ? j.at("data").get<std::string>() : "";
    name.button_text = j.contains("button_text") ? j.at("button_text").get<std::string>() : "";
}

inline void to_json(json &j, const WebAppData &name) {
    j = json::object();
    j["data"] = name.data;
    j["button_text"] = name.button_text;
}

inline void from_json(const json &j, ProximityAlertTriggered &name) {
    name.traveler = j.contains("traveler") ? std::make_shared<User>(j.at("traveler").get<User>()) : nullptr;
    name.watcher = j.contains("watcher") ? std::make_shared<User>(j.at("watcher").get<User>()) : nullptr;
    name.distance = j.contains("distance") ? j.at("distance").get<int>() : 0;
}

inline void to_json(json &j, const ProximityAlertTriggered &name) {
    j = json::object();
    to_json(j["traveler"], *name.traveler);
    to_json(j["watcher"], *name.watcher);
    j["distance"] = name.distance;
}

inline void from_json(const json &j, MessageAutoDeleteTimerChanged &name) {
    name.message_auto_delete_time = j.contains("message_auto_delete_time") ? j.at(
            "message_auto_delete_time").get<int>() : 0;
}

inline void to_json(json &j, const MessageAutoDeleteTimerChanged &name) {
    j = json::object();
    j["message_auto_delete_time"] = name.message_auto_delete_time;
}

inline void from_json(const json &j, ForumTopicCreated &name) {
    name.name = j.contains("name") ? j.at("name").get<std::string>() : "";
    name.icon_color = j.contains("icon_color") ? j.at("icon_color").get<int>() : 0;
    name.icon_custom_emoji_id = j.contains("icon_custom_emoji_id") ? j.at("icon_custom_emoji_id").get<std::string>()
                                                                   : "";
}

inline void to_json(json &j, const ForumTopicCreated &name) {
    j = json::object();
    j["name"] = name.name;
    j["icon_color"] = name.icon_color;
    j["icon_custom_emoji_id"] = name.icon_custom_emoji_id;
}

inline void from_json(const json &j, ForumTopicClosed &name) {
}

inline void to_json(json &j, const ForumTopicClosed &name) {
    j = json::object();
}

inline void from_json(const json &j, ForumTopicEdited &name) {
    name.name = j.contains("name") ? j.at("name").get<std::string>() : "";
    name.icon_custom_emoji_id = j.contains("icon_custom_emoji_id") ? j.at("icon_custom_emoji_id").get<std::string>()
                                                                   : "";
}

inline void to_json(json &j, const ForumTopicEdited &name) {
    j = json::object();
    j["name"] = name.name;
    j["icon_custom_emoji_id"] = name.icon_custom_emoji_id;
}

inline void from_json(const json &j, ForumTopicReopened &name) {
}

inline void to_json(json &j, const ForumTopicReopened &name) {
    j = json::object();
}

inline void from_json(const json &j, GeneralForumTopicHidden &name) {
}

inline void to_json(json &j, const GeneralForumTopicHidden &name) {
    j = json::object();
}

inline void from_json(const json &j, GeneralForumTopicUnhidden &name) {
}

inline void to_json(json &j, const GeneralForumTopicUnhidden &name) {
    j = json::object();
}

inline void from_json(const json &j, UserShared &name) {
    name.request_id = j.contains("request_id") ? j.at("request_id").get<int>() : 0;
    name.user_id = j.contains("user_id") ? j.at("user_id").get<int>() : 0;
}

inline void to_json(json &j, const UserShared &name) {
    j = json::object();
    j["request_id"] = name.request_id;
    j["user_id"] = name.user_id;
}

inline void from_json(const json &j, ChatShared &name) {
    name.request_id = j.contains("request_id") ? j.at("request_id").get<int>() : 0;
    name.chat_id = j.contains("chat_id") ? j.at("chat_id").get<int>() : 0;
}

inline void to_json(json &j, const ChatShared &name) {
    j = json::object();
    j["request_id"] = name.request_id;
    j["chat_id"] = name.chat_id;
}

inline void from_json(const json &j, WriteAccessAllowed &name) {
}

inline void to_json(json &j, const WriteAccessAllowed &name) {
    j = json::object();
}

inline void from_json(const json &j, VideoChatScheduled &name) {
    name.start_date = j.contains("start_date") ? j.at("start_date").get<int>() : 0;
}

inline void to_json(json &j, const VideoChatScheduled &name) {
    j = json::object();
    j["start_date"] = name.start_date;
}

inline void from_json(const json &j, VideoChatStarted &name) {
}

inline void to_json(json &j, const VideoChatStarted &name) {
    j = json::object();
}

inline void from_json(const json &j, VideoChatEnded &name) {
    name.duration = j.contains("duration") ? j.at("duration").get<int>() : 0;
}

inline void to_json(json &j, const VideoChatEnded &name) {
    j = json::object();
    j["duration"] = name.duration;
}

inline void from_json(const json &j, VideoChatParticipantsInvited &name) {
    std::vector<std::shared_ptr<User>> users;
    if (j.contains("users")) {
        for (auto a: j.at("users").get<std::vector<User>>()) {
            users.push_back(std::make_shared<User>(a));
        }
    }
    name.users = users;
}

inline void to_json(json &j, const VideoChatParticipantsInvited &name) {
    j = json::object();
    for (auto a: j.at("users").get<std::vector<User>>()) {
        auto u = json::object();
        to_json(u, a);
        j["users"].push_back(u);
    }
}

inline void from_json(const json &j, UserProfilePhotos &name) {
    name.total_count = j.contains("total_count") ? j.at("total_count").get<int>() : 0;
    std::vector<std::shared_ptr<PhotoSize>> photos;
    if (j.contains("photos")) {
        for (auto a: j.at("photos").get<std::vector<PhotoSize>>()) {
            photos.push_back(std::make_shared<PhotoSize>(a));
        }
    }
    name.photos = photos;
}

inline void to_json(json &j, const UserProfilePhotos &name) {
    j = json::object();
    j["total_count"] = name.total_count;
    for (auto a: j.at("photos").get<std::vector<PhotoSize>>()) {
        auto u = json::object();
        to_json(u, a);
        j["photos"].push_back(u);
    }
}

inline void from_json(const json &j, File &name) {
    name.file_id = j.contains("file_id") ? j.at("file_id").get<std::string>() : "";
    name.file_unique_id = j.contains("file_unique_id") ? j.at("file_unique_id").get<std::string>() : "";
    name.file_size = j.contains("file_size") ? j.at("file_size").get<int>() : 0;
    name.file_path = j.contains("file_path") ? j.at("file_path").get<std::string>() : "";
}

inline void to_json(json &j, const File &name) {
    j = json::object();
    j["file_id"] = name.file_id;
    j["file_unique_id"] = name.file_unique_id;
    j["file_size"] = name.file_size;
    j["file_path"] = name.file_path;
}

inline void from_json(const json &j, WebAppInfo &name) {
    name.url = j.contains("url") ? j.at("url").get<std::string>() : "";
}

inline void to_json(json &j, const WebAppInfo &name) {
    j = json::object();
    j["url"] = name.url;
}

inline void from_json(const json &j, ReplyKeyboardMarkup &name) {
    std::vector<std::shared_ptr<KeyboardButton>> keyboard;
    if (j.contains("keyboard")) {
        for (auto a: j.at("keyboard").get<std::vector<KeyboardButton>>()) {
            keyboard.push_back(std::make_shared<KeyboardButton>(a));
        }
    }
    name.keyboard = keyboard;
    name.is_persistent = j.contains("is_persistent") ? j.at("is_persistent").get<bool>() : false;
    name.resize_keyboard = j.contains("resize_keyboard") ? j.at("resize_keyboard").get<bool>() : false;
    name.one_time_keyboard = j.contains("one_time_keyboard") ? j.at("one_time_keyboard").get<bool>() : false;
    name.input_field_placeholder = j.contains("input_field_placeholder") ? j.at(
            "input_field_placeholder").get<std::string>() : "";
    name.selective = j.contains("selective") ? j.at("selective").get<bool>() : false;
}

inline void to_json(json &j, const ReplyKeyboardMarkup &name) {
    j = json::object();
    for (auto a: j.at("keyboard").get<std::vector<KeyboardButton>>()) {
        auto u = json::object();
        to_json(u, a);
        j["keyboard"].push_back(u);
    }
    j["is_persistent"] = name.is_persistent;
    j["resize_keyboard"] = name.resize_keyboard;
    j["one_time_keyboard"] = name.one_time_keyboard;
    j["input_field_placeholder"] = name.input_field_placeholder;
    j["selective"] = name.selective;
}

inline void from_json(const json &j, KeyboardButton &name) {
    name.text = j.contains("text") ? j.at("text").get<std::string>() : "";
    name.request_user = j.contains("request_user") ? std::make_shared<KeyboardButtonRequestUser>(
            j.at("request_user").get<KeyboardButtonRequestUser>()) : nullptr;
    name.request_chat = j.contains("request_chat") ? std::make_shared<KeyboardButtonRequestChat>(
            j.at("request_chat").get<KeyboardButtonRequestChat>()) : nullptr;
    name.request_contact = j.contains("request_contact") ? j.at("request_contact").get<bool>() : false;
    name.request_location = j.contains("request_location") ? j.at("request_location").get<bool>() : false;
    name.request_poll = j.contains("request_poll") ? std::make_shared<KeyboardButtonPollType>(
            j.at("request_poll").get<KeyboardButtonPollType>()) : nullptr;
    name.web_app = j.contains("web_app") ? std::make_shared<WebAppInfo>(j.at("web_app").get<WebAppInfo>())
                                         : nullptr;
}

inline void to_json(json &j, const KeyboardButton &name) {
    j = json::object();
    j["text"] = name.text;
    to_json(j["request_user"], *name.request_user);
    to_json(j["request_chat"], *name.request_chat);
    j["request_contact"] = name.request_contact;
    j["request_location"] = name.request_location;
    to_json(j["request_poll"], *name.request_poll);
    to_json(j["web_app"], *name.web_app);
}

inline void from_json(const json &j, KeyboardButtonRequestUser &name) {
    name.request_id = j.contains("request_id") ? j.at("request_id").get<int>() : 0;
    name.user_is_bot = j.contains("user_is_bot") ? j.at("user_is_bot").get<bool>() : false;
    name.user_is_premium = j.contains("user_is_premium") ? j.at("user_is_premium").get<bool>() : false;
}

inline void to_json(json &j, const KeyboardButtonRequestUser &name) {
    j = json::object();
    j["request_id"] = name.request_id;
    j["user_is_bot"] = name.user_is_bot;
    j["user_is_premium"] = name.user_is_premium;
}

inline void from_json(const json &j, KeyboardButtonRequestChat &name) {
    name.request_id = j.contains("request_id") ? j.at("request_id").get<int>() : 0;
    name.chat_is_channel = j.contains("chat_is_channel") ? j.at("chat_is_channel").get<bool>() : false;
    name.chat_is_forum = j.contains("chat_is_forum") ? j.at("chat_is_forum").get<bool>() : false;
    name.chat_has_username = j.contains("chat_has_username") ? j.at("chat_has_username").get<bool>() : false;
    name.chat_is_created = j.contains("chat_is_created") ? j.at("chat_is_created").get<bool>() : false;
    name.user_administrator_rights = j.contains("user_administrator_rights")
                                     ? std::make_shared<ChatAdministratorRights>(
                    j.at("user_administrator_rights").get<ChatAdministratorRights>()) : nullptr;
    name.bot_administrator_rights = j.contains("bot_administrator_rights")
                                    ? std::make_shared<ChatAdministratorRights>(
                    j.at("bot_administrator_rights").get<ChatAdministratorRights>()) : nullptr;
    name.bot_is_member = j.contains("bot_is_member") ? j.at("bot_is_member").get<bool>() : false;
}

inline void to_json(json &j, const KeyboardButtonRequestChat &name) {
    j = json::object();
    j["request_id"] = name.request_id;
    j["chat_is_channel"] = name.chat_is_channel;
    j["chat_is_forum"] = name.chat_is_forum;
    j["chat_has_username"] = name.chat_has_username;
    j["chat_is_created"] = name.chat_is_created;
    to_json(j["user_administrator_rights"], *name.user_administrator_rights);
    to_json(j["bot_administrator_rights"], *name.bot_administrator_rights);
    j["bot_is_member"] = name.bot_is_member;
}

inline void from_json(const json &j, KeyboardButtonPollType &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
}

inline void to_json(json &j, const KeyboardButtonPollType &name) {
    j = json::object();
    j["type"] = name.type;
}

inline void from_json(const json &j, ReplyKeyboardRemove &name) {
}

inline void to_json(json &j, const ReplyKeyboardRemove &name) {
    j = json::object();
}

inline void from_json(const json &j, InlineKeyboardMarkup &name) {
    std::vector<std::shared_ptr<InlineKeyboardButton>> inline_keyboard;
    if (j.contains("inline_keyboard")) {
        for (auto a: j.at("inline_keyboard").get<std::vector<InlineKeyboardButton>>()) {
            inline_keyboard.push_back(std::make_shared<InlineKeyboardButton>(a));
        }
    }
    name.inline_keyboard = inline_keyboard;
}

inline void to_json(json &j, const InlineKeyboardMarkup &name) {
    j = json::object();
    for (auto a: j.at("inline_keyboard").get<std::vector<InlineKeyboardButton>>()) {
        auto u = json::object();
        to_json(u, a);
        j["inline_keyboard"].push_back(u);
    }
}

inline void from_json(const json &j, InlineKeyboardButton &name) {
    name.text = j.contains("text") ? j.at("text").get<std::string>() : "";
    name.url = j.contains("url") ? j.at("url").get<std::string>() : "";
    name.callback_data = j.contains("callback_data") ? j.at("callback_data").get<std::string>() : "";
    name.web_app = j.contains("web_app") ? std::make_shared<WebAppInfo>(j.at("web_app").get<WebAppInfo>())
                                         : nullptr;
    name.login_url = j.contains("login_url") ? std::make_shared<LoginUrl>(j.at("login_url").get<LoginUrl>())
                                             : nullptr;
    name.switch_inline_query = j.contains("switch_inline_query") ? j.at("switch_inline_query").get<std::string>()
                                                                 : "";
    name.switch_inline_query_current_chat = j.contains("switch_inline_query_current_chat") ? j.at(
            "switch_inline_query_current_chat").get<std::string>() : "";
    name.callback_game = j.contains("callback_game") ? std::make_shared<CallbackGame>(
            j.at("callback_game").get<CallbackGame>()) : nullptr;
    name.pay = j.contains("pay") ? j.at("pay").get<bool>() : false;
}

inline void to_json(json &j, const InlineKeyboardButton &name) {
    j = json::object();
    j["text"] = name.text;
    j["url"] = name.url;
    j["callback_data"] = name.callback_data;
    to_json(j["web_app"], *name.web_app);
    to_json(j["login_url"], *name.login_url);
    j["switch_inline_query"] = name.switch_inline_query;
    j["switch_inline_query_current_chat"] = name.switch_inline_query_current_chat;
    to_json(j["callback_game"], *name.callback_game);
    j["pay"] = name.pay;
}

inline void from_json(const json &j, LoginUrl &name) {
    name.url = j.contains("url") ? j.at("url").get<std::string>() : "";
    name.forward_text = j.contains("forward_text") ? j.at("forward_text").get<std::string>() : "";
    name.bot_username = j.contains("bot_username") ? j.at("bot_username").get<std::string>() : "";
    name.request_write_access = j.contains("request_write_access") ? j.at("request_write_access").get<bool>()
                                                                   : false;
}

inline void to_json(json &j, const LoginUrl &name) {
    j = json::object();
    j["url"] = name.url;
    j["forward_text"] = name.forward_text;
    j["bot_username"] = name.bot_username;
    j["request_write_access"] = name.request_write_access;
}

inline void from_json(const json &j, CallbackQuery &name) {
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.from = j.contains("from") ? std::make_shared<User>(j.at("from").get<User>()) : nullptr;
    name.message = j.contains("message") ? std::make_shared<Message>(j.at("message").get<Message>()) : nullptr;
    name.inline_message_id = j.contains("inline_message_id") ? j.at("inline_message_id").get<std::string>() : "";
    name.chat_instance = j.contains("chat_instance") ? j.at("chat_instance").get<std::string>() : "";
    name.data = j.contains("data") ? j.at("data").get<std::string>() : "";
    name.game_short_name = j.contains("game_short_name") ? j.at("game_short_name").get<std::string>() : "";
}

inline void to_json(json &j, const CallbackQuery &name) {
    j = json::object();
    j["id"] = name.id;
    to_json(j["from"], *name.from);
    to_json(j["message"], *name.message);
    j["inline_message_id"] = name.inline_message_id;
    j["chat_instance"] = name.chat_instance;
    j["data"] = name.data;
    j["game_short_name"] = name.game_short_name;
}

inline void from_json(const json &j, ForceReply &name) {
}

inline void to_json(json &j, const ForceReply &name) {
    j = json::object();
}

inline void from_json(const json &j, ChatPhoto &name) {
    name.small_file_id = j.contains("small_file_id") ? j.at("small_file_id").get<std::string>() : "";
    name.small_file_unique_id = j.contains("small_file_unique_id") ? j.at("small_file_unique_id").get<std::string>()
                                                                   : "";
    name.big_file_id = j.contains("big_file_id") ? j.at("big_file_id").get<std::string>() : "";
    name.big_file_unique_id = j.contains("big_file_unique_id") ? j.at("big_file_unique_id").get<std::string>() : "";
}

inline void to_json(json &j, const ChatPhoto &name) {
    j = json::object();
    j["small_file_id"] = name.small_file_id;
    j["small_file_unique_id"] = name.small_file_unique_id;
    j["big_file_id"] = name.big_file_id;
    j["big_file_unique_id"] = name.big_file_unique_id;
}

inline void from_json(const json &j, ChatInviteLink &name) {
    name.invite_link = j.contains("invite_link") ? j.at("invite_link").get<std::string>() : "";
    name.creator = j.contains("creator") ? std::make_shared<User>(j.at("creator").get<User>()) : nullptr;
    name.creates_join_request = j.contains("creates_join_request") ? j.at("creates_join_request").get<bool>()
                                                                   : false;
    name.is_primary = j.contains("is_primary") ? j.at("is_primary").get<bool>() : false;
    name.is_revoked = j.contains("is_revoked") ? j.at("is_revoked").get<bool>() : false;
    name.name = j.contains("name") ? j.at("name").get<std::string>() : "";
    name.expire_date = j.contains("expire_date") ? j.at("expire_date").get<int>() : 0;
    name.member_limit = j.contains("member_limit") ? j.at("member_limit").get<int>() : 0;
    name.pending_join_request_count = j.contains("pending_join_request_count") ? j.at(
            "pending_join_request_count").get<int>() : 0;
}

inline void to_json(json &j, const ChatInviteLink &name) {
    j = json::object();
    j["invite_link"] = name.invite_link;
    to_json(j["creator"], *name.creator);
    j["creates_join_request"] = name.creates_join_request;
    j["is_primary"] = name.is_primary;
    j["is_revoked"] = name.is_revoked;
    j["name"] = name.name;
    j["expire_date"] = name.expire_date;
    j["member_limit"] = name.member_limit;
    j["pending_join_request_count"] = name.pending_join_request_count;
}

inline void from_json(const json &j, ChatAdministratorRights &name) {
    name.is_anonymous = j.contains("is_anonymous") ? j.at("is_anonymous").get<bool>() : false;
    name.can_manage_chat = j.contains("can_manage_chat") ? j.at("can_manage_chat").get<bool>() : false;
    name.can_delete_messages = j.contains("can_delete_messages") ? j.at("can_delete_messages").get<bool>() : false;
    name.can_manage_video_chats = j.contains("can_manage_video_chats") ? j.at("can_manage_video_chats").get<bool>()
                                                                       : false;
    name.can_restrict_members = j.contains("can_restrict_members") ? j.at("can_restrict_members").get<bool>()
                                                                   : false;
    name.can_promote_members = j.contains("can_promote_members") ? j.at("can_promote_members").get<bool>() : false;
    name.can_change_info = j.contains("can_change_info") ? j.at("can_change_info").get<bool>() : false;
    name.can_invite_users = j.contains("can_invite_users") ? j.at("can_invite_users").get<bool>() : false;
    name.can_post_messages = j.contains("can_post_messages") ? j.at("can_post_messages").get<bool>() : false;
    name.can_edit_messages = j.contains("can_edit_messages") ? j.at("can_edit_messages").get<bool>() : false;
    name.can_pin_messages = j.contains("can_pin_messages") ? j.at("can_pin_messages").get<bool>() : false;
    name.can_manage_topics = j.contains("can_manage_topics") ? j.at("can_manage_topics").get<bool>() : false;
}

inline void to_json(json &j, const ChatAdministratorRights &name) {
    j = json::object();
    j["is_anonymous"] = name.is_anonymous;
    j["can_manage_chat"] = name.can_manage_chat;
    j["can_delete_messages"] = name.can_delete_messages;
    j["can_manage_video_chats"] = name.can_manage_video_chats;
    j["can_restrict_members"] = name.can_restrict_members;
    j["can_promote_members"] = name.can_promote_members;
    j["can_change_info"] = name.can_change_info;
    j["can_invite_users"] = name.can_invite_users;
    j["can_post_messages"] = name.can_post_messages;
    j["can_edit_messages"] = name.can_edit_messages;
    j["can_pin_messages"] = name.can_pin_messages;
    j["can_manage_topics"] = name.can_manage_topics;
}

inline void from_json(const json &j, ChatMember &name) {
    name.status = j.contains("status") ? j.at("status").get<std::string>() : "";
    name.user = j.contains("user") ? std::make_shared<User>(j.at("user").get<User>()) : nullptr;
    name.is_anonymous = j.contains("is_anonymous") ? j.at("is_anonymous").get<bool>() : false;
    name.custom_title = j.contains("custom_title") ? j.at("custom_title").get<std::string>() : "";
}

inline void to_json(json &j, const ChatMember &name) {
    j = json::object();
    j["status"] = name.status;
    to_json(j["user"], *name.user);
    j["is_anonymous"] = name.is_anonymous;
    j["custom_title"] = name.custom_title;
}

inline void from_json(const json &j, ChatMemberOwner &name) {
    name.status = j.contains("status") ? j.at("status").get<std::string>() : "";
    name.user = j.contains("user") ? std::make_shared<User>(j.at("user").get<User>()) : nullptr;
    name.is_anonymous = j.contains("is_anonymous") ? j.at("is_anonymous").get<bool>() : false;
    name.custom_title = j.contains("custom_title") ? j.at("custom_title").get<std::string>() : "";
}

inline void to_json(json &j, const ChatMemberOwner &name) {
    j = json::object();
    j["status"] = name.status;
    to_json(j["user"], *name.user);
    j["is_anonymous"] = name.is_anonymous;
    j["custom_title"] = name.custom_title;
}

inline void from_json(const json &j, ChatMemberAdministrator &name) {
    name.status = j.contains("status") ? j.at("status").get<std::string>() : "";
    name.user = j.contains("user") ? std::make_shared<User>(j.at("user").get<User>()) : nullptr;
    name.can_be_edited = j.contains("can_be_edited") ? j.at("can_be_edited").get<bool>() : false;
    name.is_anonymous = j.contains("is_anonymous") ? j.at("is_anonymous").get<bool>() : false;
    name.can_manage_chat = j.contains("can_manage_chat") ? j.at("can_manage_chat").get<bool>() : false;
    name.can_delete_messages = j.contains("can_delete_messages") ? j.at("can_delete_messages").get<bool>() : false;
    name.can_manage_video_chats = j.contains("can_manage_video_chats") ? j.at("can_manage_video_chats").get<bool>()
                                                                       : false;
    name.can_restrict_members = j.contains("can_restrict_members") ? j.at("can_restrict_members").get<bool>()
                                                                   : false;
    name.can_promote_members = j.contains("can_promote_members") ? j.at("can_promote_members").get<bool>() : false;
    name.can_change_info = j.contains("can_change_info") ? j.at("can_change_info").get<bool>() : false;
    name.can_invite_users = j.contains("can_invite_users") ? j.at("can_invite_users").get<bool>() : false;
    name.can_post_messages = j.contains("can_post_messages") ? j.at("can_post_messages").get<bool>() : false;
    name.can_edit_messages = j.contains("can_edit_messages") ? j.at("can_edit_messages").get<bool>() : false;
    name.can_pin_messages = j.contains("can_pin_messages") ? j.at("can_pin_messages").get<bool>() : false;
    name.can_manage_topics = j.contains("can_manage_topics") ? j.at("can_manage_topics").get<bool>() : false;
    name.custom_title = j.contains("custom_title") ? j.at("custom_title").get<std::string>() : "";
}

inline void to_json(json &j, const ChatMemberAdministrator &name) {
    j = json::object();
    j["status"] = name.status;
    to_json(j["user"], *name.user);
    j["can_be_edited"] = name.can_be_edited;
    j["is_anonymous"] = name.is_anonymous;
    j["can_manage_chat"] = name.can_manage_chat;
    j["can_delete_messages"] = name.can_delete_messages;
    j["can_manage_video_chats"] = name.can_manage_video_chats;
    j["can_restrict_members"] = name.can_restrict_members;
    j["can_promote_members"] = name.can_promote_members;
    j["can_change_info"] = name.can_change_info;
    j["can_invite_users"] = name.can_invite_users;
    j["can_post_messages"] = name.can_post_messages;
    j["can_edit_messages"] = name.can_edit_messages;
    j["can_pin_messages"] = name.can_pin_messages;
    j["can_manage_topics"] = name.can_manage_topics;
    j["custom_title"] = name.custom_title;
}

inline void from_json(const json &j, ChatMemberMember &name) {
    name.status = j.contains("status") ? j.at("status").get<std::string>() : "";
    name.user = j.contains("user") ? std::make_shared<User>(j.at("user").get<User>()) : nullptr;
}

inline void to_json(json &j, const ChatMemberMember &name) {
    j = json::object();
    j["status"] = name.status;
    to_json(j["user"], *name.user);
}

inline void from_json(const json &j, ChatMemberRestricted &name) {
    name.status = j.contains("status") ? j.at("status").get<std::string>() : "";
    name.user = j.contains("user") ? std::make_shared<User>(j.at("user").get<User>()) : nullptr;
    name.is_member = j.contains("is_member") ? j.at("is_member").get<bool>() : false;
    name.can_send_messages = j.contains("can_send_messages") ? j.at("can_send_messages").get<bool>() : false;
    name.can_send_audios = j.contains("can_send_audios") ? j.at("can_send_audios").get<bool>() : false;
    name.can_send_documents = j.contains("can_send_documents") ? j.at("can_send_documents").get<bool>() : false;
    name.can_send_photos = j.contains("can_send_photos") ? j.at("can_send_photos").get<bool>() : false;
    name.can_send_videos = j.contains("can_send_videos") ? j.at("can_send_videos").get<bool>() : false;
    name.can_send_video_notes = j.contains("can_send_video_notes") ? j.at("can_send_video_notes").get<bool>()
                                                                   : false;
    name.can_send_voice_notes = j.contains("can_send_voice_notes") ? j.at("can_send_voice_notes").get<bool>()
                                                                   : false;
    name.can_send_polls = j.contains("can_send_polls") ? j.at("can_send_polls").get<bool>() : false;
    name.can_send_other_messages = j.contains("can_send_other_messages") ? j.at(
            "can_send_other_messages").get<bool>() : false;
    name.can_add_web_page_previews = j.contains("can_add_web_page_previews") ? j.at(
            "can_add_web_page_previews").get<bool>() : false;
    name.can_change_info = j.contains("can_change_info") ? j.at("can_change_info").get<bool>() : false;
    name.can_invite_users = j.contains("can_invite_users") ? j.at("can_invite_users").get<bool>() : false;
    name.can_pin_messages = j.contains("can_pin_messages") ? j.at("can_pin_messages").get<bool>() : false;
    name.can_manage_topics = j.contains("can_manage_topics") ? j.at("can_manage_topics").get<bool>() : false;
    name.until_date = j.contains("until_date") ? j.at("until_date").get<int>() : 0;
}

inline void to_json(json &j, const ChatMemberRestricted &name) {
    j = json::object();
    j["status"] = name.status;
    to_json(j["user"], *name.user);
    j["is_member"] = name.is_member;
    j["can_send_messages"] = name.can_send_messages;
    j["can_send_audios"] = name.can_send_audios;
    j["can_send_documents"] = name.can_send_documents;
    j["can_send_photos"] = name.can_send_photos;
    j["can_send_videos"] = name.can_send_videos;
    j["can_send_video_notes"] = name.can_send_video_notes;
    j["can_send_voice_notes"] = name.can_send_voice_notes;
    j["can_send_polls"] = name.can_send_polls;
    j["can_send_other_messages"] = name.can_send_other_messages;
    j["can_add_web_page_previews"] = name.can_add_web_page_previews;
    j["can_change_info"] = name.can_change_info;
    j["can_invite_users"] = name.can_invite_users;
    j["can_pin_messages"] = name.can_pin_messages;
    j["can_manage_topics"] = name.can_manage_topics;
    j["until_date"] = name.until_date;
}

inline void from_json(const json &j, ChatMemberLeft &name) {
    name.status = j.contains("status") ? j.at("status").get<std::string>() : "";
    name.user = j.contains("user") ? std::make_shared<User>(j.at("user").get<User>()) : nullptr;
}

inline void to_json(json &j, const ChatMemberLeft &name) {
    j = json::object();
    j["status"] = name.status;
    to_json(j["user"], *name.user);
}

inline void from_json(const json &j, ChatMemberBanned &name) {
    name.status = j.contains("status") ? j.at("status").get<std::string>() : "";
    name.user = j.contains("user") ? std::make_shared<User>(j.at("user").get<User>()) : nullptr;
    name.until_date = j.contains("until_date") ? j.at("until_date").get<int>() : 0;
}

inline void to_json(json &j, const ChatMemberBanned &name) {
    j = json::object();
    j["status"] = name.status;
    to_json(j["user"], *name.user);
    j["until_date"] = name.until_date;
}

inline void from_json(const json &j, ChatMemberUpdated &name) {
    name.chat = j.contains("chat") ? std::make_shared<Chat>(j.at("chat").get<Chat>()) : nullptr;
    name.from = j.contains("from") ? std::make_shared<User>(j.at("from").get<User>()) : nullptr;
    name.date = j.contains("date") ? j.at("date").get<int>() : 0;
    name.old_chat_member = j.contains("old_chat_member") ? std::make_shared<ChatMember>(
            j.at("old_chat_member").get<ChatMember>()) : nullptr;
    name.new_chat_member = j.contains("new_chat_member") ? std::make_shared<ChatMember>(
            j.at("new_chat_member").get<ChatMember>()) : nullptr;
    name.invite_link = j.contains("invite_link") ? std::make_shared<ChatInviteLink>(
            j.at("invite_link").get<ChatInviteLink>()) : nullptr;
}

inline void to_json(json &j, const ChatMemberUpdated &name) {
    j = json::object();
    to_json(j["chat"], *name.chat);
    to_json(j["from"], *name.from);
    j["date"] = name.date;
    to_json(j["old_chat_member"], *name.old_chat_member);
    to_json(j["new_chat_member"], *name.new_chat_member);
    to_json(j["invite_link"], *name.invite_link);
}

inline void from_json(const json &j, ChatJoinRequest &name) {
    name.chat = j.contains("chat") ? std::make_shared<Chat>(j.at("chat").get<Chat>()) : nullptr;
    name.from = j.contains("from") ? std::make_shared<User>(j.at("from").get<User>()) : nullptr;
    name.user_chat_id = j.contains("user_chat_id") ? j.at("user_chat_id").get<int>() : 0;
    name.date = j.contains("date") ? j.at("date").get<int>() : 0;
    name.bio = j.contains("bio") ? j.at("bio").get<std::string>() : "";
    name.invite_link = j.contains("invite_link") ? std::make_shared<ChatInviteLink>(
            j.at("invite_link").get<ChatInviteLink>()) : nullptr;
}

inline void to_json(json &j, const ChatJoinRequest &name) {
    j = json::object();
    to_json(j["chat"], *name.chat);
    to_json(j["from"], *name.from);
    j["user_chat_id"] = name.user_chat_id;
    j["date"] = name.date;
    j["bio"] = name.bio;
    to_json(j["invite_link"], *name.invite_link);
}

inline void from_json(const json &j, ChatPermissions &name) {
    name.can_send_messages = j.contains("can_send_messages") ? j.at("can_send_messages").get<bool>() : false;
    name.can_send_audios = j.contains("can_send_audios") ? j.at("can_send_audios").get<bool>() : false;
    name.can_send_documents = j.contains("can_send_documents") ? j.at("can_send_documents").get<bool>() : false;
    name.can_send_photos = j.contains("can_send_photos") ? j.at("can_send_photos").get<bool>() : false;
    name.can_send_videos = j.contains("can_send_videos") ? j.at("can_send_videos").get<bool>() : false;
    name.can_send_video_notes = j.contains("can_send_video_notes") ? j.at("can_send_video_notes").get<bool>()
                                                                   : false;
    name.can_send_voice_notes = j.contains("can_send_voice_notes") ? j.at("can_send_voice_notes").get<bool>()
                                                                   : false;
    name.can_send_polls = j.contains("can_send_polls") ? j.at("can_send_polls").get<bool>() : false;
    name.can_send_other_messages = j.contains("can_send_other_messages") ? j.at(
            "can_send_other_messages").get<bool>() : false;
    name.can_add_web_page_previews = j.contains("can_add_web_page_previews") ? j.at(
            "can_add_web_page_previews").get<bool>() : false;
    name.can_change_info = j.contains("can_change_info") ? j.at("can_change_info").get<bool>() : false;
    name.can_invite_users = j.contains("can_invite_users") ? j.at("can_invite_users").get<bool>() : false;
    name.can_pin_messages = j.contains("can_pin_messages") ? j.at("can_pin_messages").get<bool>() : false;
    name.can_manage_topics = j.contains("can_manage_topics") ? j.at("can_manage_topics").get<bool>() : false;
}

inline void to_json(json &j, const ChatPermissions &name) {
    j = json::object();
    j["can_send_messages"] = name.can_send_messages;
    j["can_send_audios"] = name.can_send_audios;
    j["can_send_documents"] = name.can_send_documents;
    j["can_send_photos"] = name.can_send_photos;
    j["can_send_videos"] = name.can_send_videos;
    j["can_send_video_notes"] = name.can_send_video_notes;
    j["can_send_voice_notes"] = name.can_send_voice_notes;
    j["can_send_polls"] = name.can_send_polls;
    j["can_send_other_messages"] = name.can_send_other_messages;
    j["can_add_web_page_previews"] = name.can_add_web_page_previews;
    j["can_change_info"] = name.can_change_info;
    j["can_invite_users"] = name.can_invite_users;
    j["can_pin_messages"] = name.can_pin_messages;
    j["can_manage_topics"] = name.can_manage_topics;
}

inline void from_json(const json &j, ChatLocation &name) {
    name.location = j.contains("location") ? std::make_shared<Location>(j.at("location").get<Location>()) : nullptr;
    name.address = j.contains("address") ? j.at("address").get<std::string>() : "";
}

inline void to_json(json &j, const ChatLocation &name) {
    j = json::object();
    to_json(j["location"], *name.location);
    j["address"] = name.address;
}

inline void from_json(const json &j, ForumTopic &name) {
    name.message_thread_id = j.contains("message_thread_id") ? j.at("message_thread_id").get<int>() : 0;
    name.name = j.contains("name") ? j.at("name").get<std::string>() : "";
    name.icon_color = j.contains("icon_color") ? j.at("icon_color").get<int>() : 0;
    name.icon_custom_emoji_id = j.contains("icon_custom_emoji_id") ? j.at("icon_custom_emoji_id").get<std::string>()
                                                                   : "";
}

inline void to_json(json &j, const ForumTopic &name) {
    j = json::object();
    j["message_thread_id"] = name.message_thread_id;
    j["name"] = name.name;
    j["icon_color"] = name.icon_color;
    j["icon_custom_emoji_id"] = name.icon_custom_emoji_id;
}

inline void from_json(const json &j, BotCommand &name) {
    name.command = j.contains("command") ? j.at("command").get<std::string>() : "";
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
}

inline void to_json(json &j, const BotCommand &name) {
    j = json::object();
    j["command"] = name.command;
    j["description"] = name.description;
}

inline void from_json(const json &j, BotCommandScope &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
}

inline void to_json(json &j, const BotCommandScope &name) {
    j = json::object();
    j["type"] = name.type;
}

inline void from_json(const json &j, BotCommandScopeDefault &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
}

inline void to_json(json &j, const BotCommandScopeDefault &name) {
    j = json::object();
    j["type"] = name.type;
}

inline void from_json(const json &j, BotCommandScopeAllPrivateChats &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
}

inline void to_json(json &j, const BotCommandScopeAllPrivateChats &name) {
    j = json::object();
    j["type"] = name.type;
}

inline void from_json(const json &j, BotCommandScopeAllGroupChats &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
}

inline void to_json(json &j, const BotCommandScopeAllGroupChats &name) {
    j = json::object();
    j["type"] = name.type;
}

inline void from_json(const json &j, BotCommandScopeAllChatAdministrators &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
}

inline void to_json(json &j, const BotCommandScopeAllChatAdministrators &name) {
    j = json::object();
    j["type"] = name.type;
}

inline void from_json(const json &j, BotCommandScopeChat &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.chat_id = j.contains("chat_id") ? j.at("chat_id").get<int>() : 0;
}

inline void to_json(json &j, const BotCommandScopeChat &name) {
    j = json::object();
    j["type"] = name.type;
    j["chat_id"] = name.chat_id;
}

inline void from_json(const json &j, BotCommandScopeChatAdministrators &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.chat_id = j.contains("chat_id") ? j.at("chat_id").get<int>() : 0;
}

inline void to_json(json &j, const BotCommandScopeChatAdministrators &name) {
    j = json::object();
    j["type"] = name.type;
    j["chat_id"] = name.chat_id;
}

inline void from_json(const json &j, BotCommandScopeChatMember &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.chat_id = j.contains("chat_id") ? j.at("chat_id").get<int>() : 0;
    name.user_id = j.contains("user_id") ? j.at("user_id").get<int>() : 0;
}

inline void to_json(json &j, const BotCommandScopeChatMember &name) {
    j = json::object();
    j["type"] = name.type;
    j["chat_id"] = name.chat_id;
    j["user_id"] = name.user_id;
}

inline void from_json(const json &j, MenuButton &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
}

inline void to_json(json &j, const MenuButton &name) {
    j = json::object();
    j["type"] = name.type;
}

inline void from_json(const json &j, MenuButtonCommands &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
}

inline void to_json(json &j, const MenuButtonCommands &name) {
    j = json::object();
    j["type"] = name.type;
}

inline void from_json(const json &j, MenuButtonWebApp &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.text = j.contains("text") ? j.at("text").get<std::string>() : "";
    name.web_app = j.contains("web_app") ? std::make_shared<WebAppInfo>(j.at("web_app").get<WebAppInfo>())
                                         : nullptr;
}

inline void to_json(json &j, const MenuButtonWebApp &name) {
    j = json::object();
    j["type"] = name.type;
    j["text"] = name.text;
    to_json(j["web_app"], *name.web_app);
}

inline void from_json(const json &j, MenuButtonDefault &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
}

inline void to_json(json &j, const MenuButtonDefault &name) {
    j = json::object();
    j["type"] = name.type;
}

inline void from_json(const json &j, ResponseParameters &name) {
    name.migrate_to_chat_id = j.contains("migrate_to_chat_id") ? j.at("migrate_to_chat_id").get<int>() : 0;
    name.retry_after = j.contains("retry_after") ? j.at("retry_after").get<int>() : 0;
}

inline void to_json(json &j, const ResponseParameters &name) {
    j = json::object();
    j["migrate_to_chat_id"] = name.migrate_to_chat_id;
    j["retry_after"] = name.retry_after;
}

inline void from_json(const json &j, InputMedia &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.media = j.contains("media") ? j.at("media").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.has_spoiler = j.contains("has_spoiler") ? j.at("has_spoiler").get<bool>() : false;
}

inline void to_json(json &j, const InputMedia &name) {
    j = json::object();
    j["type"] = name.type;
    j["media"] = name.media;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["has_spoiler"] = name.has_spoiler;
}

inline void from_json(const json &j, InputMediaPhoto &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.media = j.contains("media") ? j.at("media").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.has_spoiler = j.contains("has_spoiler") ? j.at("has_spoiler").get<bool>() : false;
}

inline void to_json(json &j, const InputMediaPhoto &name) {
    j = json::object();
    j["type"] = name.type;
    j["media"] = name.media;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["has_spoiler"] = name.has_spoiler;
}

inline void from_json(const json &j, InputMediaVideo &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.media = j.contains("media") ? j.at("media").get<std::string>() : "";
    name.thumb = j.contains("thumb") ? j.at("thumb").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.width = j.contains("width") ? j.at("width").get<int>() : 0;
    name.height = j.contains("height") ? j.at("height").get<int>() : 0;
    name.duration = j.contains("duration") ? j.at("duration").get<int>() : 0;
    name.supports_streaming = j.contains("supports_streaming") ? j.at("supports_streaming").get<bool>() : false;
    name.has_spoiler = j.contains("has_spoiler") ? j.at("has_spoiler").get<bool>() : false;
}

inline void to_json(json &j, const InputMediaVideo &name) {
    j = json::object();
    j["type"] = name.type;
    j["media"] = name.media;
    j["thumb"] = name.thumb;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["width"] = name.width;
    j["height"] = name.height;
    j["duration"] = name.duration;
    j["supports_streaming"] = name.supports_streaming;
    j["has_spoiler"] = name.has_spoiler;
}

inline void from_json(const json &j, InputMediaAnimation &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.media = j.contains("media") ? j.at("media").get<std::string>() : "";
    name.thumb = j.contains("thumb") ? j.at("thumb").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.width = j.contains("width") ? j.at("width").get<int>() : 0;
    name.height = j.contains("height") ? j.at("height").get<int>() : 0;
    name.duration = j.contains("duration") ? j.at("duration").get<int>() : 0;
    name.has_spoiler = j.contains("has_spoiler") ? j.at("has_spoiler").get<bool>() : false;
}

inline void to_json(json &j, const InputMediaAnimation &name) {
    j = json::object();
    j["type"] = name.type;
    j["media"] = name.media;
    j["thumb"] = name.thumb;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["width"] = name.width;
    j["height"] = name.height;
    j["duration"] = name.duration;
    j["has_spoiler"] = name.has_spoiler;
}

inline void from_json(const json &j, InputMediaAudio &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.media = j.contains("media") ? j.at("media").get<std::string>() : "";
    name.thumb = j.contains("thumb") ? j.at("thumb").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.duration = j.contains("duration") ? j.at("duration").get<int>() : 0;
    name.performer = j.contains("performer") ? j.at("performer").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
}

inline void to_json(json &j, const InputMediaAudio &name) {
    j = json::object();
    j["type"] = name.type;
    j["media"] = name.media;
    j["thumb"] = name.thumb;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["duration"] = name.duration;
    j["performer"] = name.performer;
    j["title"] = name.title;
}

inline void from_json(const json &j, InputMediaDocument &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.media = j.contains("media") ? j.at("media").get<std::string>() : "";
    name.thumb = j.contains("thumb") ? j.at("thumb").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.disable_content_type_detection = j.contains("disable_content_type_detection") ? j.at(
            "disable_content_type_detection").get<bool>() : false;
}

inline void to_json(json &j, const InputMediaDocument &name) {
    j = json::object();
    j["type"] = name.type;
    j["media"] = name.media;
    j["thumb"] = name.thumb;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["disable_content_type_detection"] = name.disable_content_type_detection;
}

inline void from_json(const json &j, InputFile &name) {
    name.chat_id = j.contains("chat_id") ? j.at("chat_id").get<int>() : 0;
    name.message_thread_id = j.contains("message_thread_id") ? j.at("message_thread_id").get<int>() : 0;
    name.text = j.contains("text") ? j.at("text").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> entities;
    if (j.contains("entities")) {
        for (auto a: j.at("entities").get<std::vector<MessageEntity>>()) {
            entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.entities = entities;
    name.disable_web_page_preview = j.contains("disable_web_page_preview") ? j.at(
            "disable_web_page_preview").get<bool>() : false;
    name.disable_notification = j.contains("disable_notification") ? j.at("disable_notification").get<bool>()
                                                                   : false;
    name.protect_content = j.contains("protect_content") ? j.at("protect_content").get<bool>() : false;
    name.reply_to_message_id = j.contains("reply_to_message_id") ? j.at("reply_to_message_id").get<int>() : 0;
    name.allow_sending_without_reply = j.contains("allow_sending_without_reply") ? j.at(
            "allow_sending_without_reply").get<bool>() : false;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
}

inline void to_json(json &j, const InputFile &name) {
    j = json::object();
    j["chat_id"] = name.chat_id;
    j["message_thread_id"] = name.message_thread_id;
    j["text"] = name.text;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["entities"].push_back(u);
    }
    j["disable_web_page_preview"] = name.disable_web_page_preview;
    j["disable_notification"] = name.disable_notification;
    j["protect_content"] = name.protect_content;
    j["reply_to_message_id"] = name.reply_to_message_id;
    j["allow_sending_without_reply"] = name.allow_sending_without_reply;
    to_json(j["reply_markup"], *name.reply_markup);
}

inline void from_json(const json &j, Stickers &name) {
}

inline void to_json(json &j, const Stickers &name) {
    j = json::object();
}

inline void from_json(const json &j, Sticker &name) {
    name.file_id = j.contains("file_id") ? j.at("file_id").get<std::string>() : "";
    name.file_unique_id = j.contains("file_unique_id") ? j.at("file_unique_id").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.width = j.contains("width") ? j.at("width").get<int>() : 0;
    name.height = j.contains("height") ? j.at("height").get<int>() : 0;
    name.is_animated = j.contains("is_animated") ? j.at("is_animated").get<bool>() : false;
    name.is_video = j.contains("is_video") ? j.at("is_video").get<bool>() : false;
    name.thumb = j.contains("thumb") ? std::make_shared<PhotoSize>(j.at("thumb").get<PhotoSize>()) : nullptr;
    name.emoji = j.contains("emoji") ? j.at("emoji").get<std::string>() : "";
    name.set_name = j.contains("set_name") ? j.at("set_name").get<std::string>() : "";
    name.premium_animation = j.contains("premium_animation") ? std::make_shared<File>(
            j.at("premium_animation").get<File>()) : nullptr;
    name.mask_position = j.contains("mask_position") ? std::make_shared<MaskPosition>(
            j.at("mask_position").get<MaskPosition>()) : nullptr;
    name.custom_emoji_id = j.contains("custom_emoji_id") ? j.at("custom_emoji_id").get<std::string>() : "";
    name.file_size = j.contains("file_size") ? j.at("file_size").get<int>() : 0;
}

inline void to_json(json &j, const Sticker &name) {
    j = json::object();
    j["file_id"] = name.file_id;
    j["file_unique_id"] = name.file_unique_id;
    j["type"] = name.type;
    j["width"] = name.width;
    j["height"] = name.height;
    j["is_animated"] = name.is_animated;
    j["is_video"] = name.is_video;
    to_json(j["thumb"], *name.thumb);
    j["emoji"] = name.emoji;
    j["set_name"] = name.set_name;
    to_json(j["premium_animation"], *name.premium_animation);
    to_json(j["mask_position"], *name.mask_position);
    j["custom_emoji_id"] = name.custom_emoji_id;
    j["file_size"] = name.file_size;
}

inline void from_json(const json &j, StickerSet &name) {
    name.name = j.contains("name") ? j.at("name").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.sticker_type = j.contains("sticker_type") ? j.at("sticker_type").get<std::string>() : "";
    name.is_animated = j.contains("is_animated") ? j.at("is_animated").get<bool>() : false;
    name.is_video = j.contains("is_video") ? j.at("is_video").get<bool>() : false;
    std::vector<std::shared_ptr<Sticker>> stickers;
    if (j.contains("stickers")) {
        for (auto a: j.at("stickers").get<std::vector<Sticker>>()) {
            stickers.push_back(std::make_shared<Sticker>(a));
        }
    }
    name.stickers = stickers;
    name.thumb = j.contains("thumb") ? std::make_shared<PhotoSize>(j.at("thumb").get<PhotoSize>()) : nullptr;
}

inline void to_json(json &j, const StickerSet &name) {
    j = json::object();
    j["name"] = name.name;
    j["title"] = name.title;
    j["sticker_type"] = name.sticker_type;
    j["is_animated"] = name.is_animated;
    j["is_video"] = name.is_video;
    for (auto a: j.at("stickers").get<std::vector<Sticker>>()) {
        auto u = json::object();
        to_json(u, a);
        j["stickers"].push_back(u);
    }
    to_json(j["thumb"], *name.thumb);
}

inline void from_json(const json &j, MaskPosition &name) {
    name.point = j.contains("point") ? j.at("point").get<std::string>() : "";
    name.x_shift = j.contains("x_shift") ? j.at("x_shift").get<float>() : 0;
    name.y_shift = j.contains("y_shift") ? j.at("y_shift").get<float>() : 0;
    name.scale = j.contains("scale") ? j.at("scale").get<float>() : 0;
}

inline void to_json(json &j, const MaskPosition &name) {
    j = json::object();
    j["point"] = name.point;
    j["x_shift"] = name.x_shift;
    j["y_shift"] = name.y_shift;
    j["scale"] = name.scale;
}

inline void from_json(const json &j, InlineQuery &name) {
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.from = j.contains("from") ? std::make_shared<User>(j.at("from").get<User>()) : nullptr;
    name.query = j.contains("query") ? j.at("query").get<std::string>() : "";
    name.offset = j.contains("offset") ? j.at("offset").get<std::string>() : "";
    name.chat_type = j.contains("chat_type") ? j.at("chat_type").get<std::string>() : "";
    name.location = j.contains("location") ? std::make_shared<Location>(j.at("location").get<Location>()) : nullptr;
}

inline void to_json(json &j, const InlineQuery &name) {
    j = json::object();
    j["id"] = name.id;
    to_json(j["from"], *name.from);
    j["query"] = name.query;
    j["offset"] = name.offset;
    j["chat_type"] = name.chat_type;
    to_json(j["location"], *name.location);
}

inline void from_json(const json &j, InlineQueryResult &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.url = j.contains("url") ? j.at("url").get<std::string>() : "";
    name.hide_url = j.contains("hide_url") ? j.at("hide_url").get<bool>() : false;
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.thumb_url = j.contains("thumb_url") ? j.at("thumb_url").get<std::string>() : "";
    name.thumb_width = j.contains("thumb_width") ? j.at("thumb_width").get<int>() : 0;
    name.thumb_height = j.contains("thumb_height") ? j.at("thumb_height").get<int>() : 0;
}

inline void to_json(json &j, const InlineQueryResult &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["title"] = name.title;
    to_json(j["input_message_content"], *name.input_message_content);
    to_json(j["reply_markup"], *name.reply_markup);
    j["url"] = name.url;
    j["hide_url"] = name.hide_url;
    j["description"] = name.description;
    j["thumb_url"] = name.thumb_url;
    j["thumb_width"] = name.thumb_width;
    j["thumb_height"] = name.thumb_height;
}

inline void from_json(const json &j, InlineQueryResultArticle &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.url = j.contains("url") ? j.at("url").get<std::string>() : "";
    name.hide_url = j.contains("hide_url") ? j.at("hide_url").get<bool>() : false;
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.thumb_url = j.contains("thumb_url") ? j.at("thumb_url").get<std::string>() : "";
    name.thumb_width = j.contains("thumb_width") ? j.at("thumb_width").get<int>() : 0;
    name.thumb_height = j.contains("thumb_height") ? j.at("thumb_height").get<int>() : 0;
}

inline void to_json(json &j, const InlineQueryResultArticle &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["title"] = name.title;
    to_json(j["input_message_content"], *name.input_message_content);
    to_json(j["reply_markup"], *name.reply_markup);
    j["url"] = name.url;
    j["hide_url"] = name.hide_url;
    j["description"] = name.description;
    j["thumb_url"] = name.thumb_url;
    j["thumb_width"] = name.thumb_width;
    j["thumb_height"] = name.thumb_height;
}

inline void from_json(const json &j, InlineQueryResultPhoto &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.photo_url = j.contains("photo_url") ? j.at("photo_url").get<std::string>() : "";
    name.thumb_url = j.contains("thumb_url") ? j.at("thumb_url").get<std::string>() : "";
    name.photo_width = j.contains("photo_width") ? j.at("photo_width").get<int>() : 0;
    name.photo_height = j.contains("photo_height") ? j.at("photo_height").get<int>() : 0;
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultPhoto &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["photo_url"] = name.photo_url;
    j["thumb_url"] = name.thumb_url;
    j["photo_width"] = name.photo_width;
    j["photo_height"] = name.photo_height;
    j["title"] = name.title;
    j["description"] = name.description;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultGif &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.gif_url = j.contains("gif_url") ? j.at("gif_url").get<std::string>() : "";
    name.gif_width = j.contains("gif_width") ? j.at("gif_width").get<int>() : 0;
    name.gif_height = j.contains("gif_height") ? j.at("gif_height").get<int>() : 0;
    name.gif_duration = j.contains("gif_duration") ? j.at("gif_duration").get<int>() : 0;
    name.thumb_url = j.contains("thumb_url") ? j.at("thumb_url").get<std::string>() : "";
    name.thumb_mime_type = j.contains("thumb_mime_type") ? j.at("thumb_mime_type").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultGif &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["gif_url"] = name.gif_url;
    j["gif_width"] = name.gif_width;
    j["gif_height"] = name.gif_height;
    j["gif_duration"] = name.gif_duration;
    j["thumb_url"] = name.thumb_url;
    j["thumb_mime_type"] = name.thumb_mime_type;
    j["title"] = name.title;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultMpeg4Gif &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.mpeg4_url = j.contains("mpeg4_url") ? j.at("mpeg4_url").get<std::string>() : "";
    name.mpeg4_width = j.contains("mpeg4_width") ? j.at("mpeg4_width").get<int>() : 0;
    name.mpeg4_height = j.contains("mpeg4_height") ? j.at("mpeg4_height").get<int>() : 0;
    name.mpeg4_duration = j.contains("mpeg4_duration") ? j.at("mpeg4_duration").get<int>() : 0;
    name.thumb_url = j.contains("thumb_url") ? j.at("thumb_url").get<std::string>() : "";
    name.thumb_mime_type = j.contains("thumb_mime_type") ? j.at("thumb_mime_type").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultMpeg4Gif &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["mpeg4_url"] = name.mpeg4_url;
    j["mpeg4_width"] = name.mpeg4_width;
    j["mpeg4_height"] = name.mpeg4_height;
    j["mpeg4_duration"] = name.mpeg4_duration;
    j["thumb_url"] = name.thumb_url;
    j["thumb_mime_type"] = name.thumb_mime_type;
    j["title"] = name.title;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultVideo &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.video_url = j.contains("video_url") ? j.at("video_url").get<std::string>() : "";
    name.mime_type = j.contains("mime_type") ? j.at("mime_type").get<std::string>() : "";
    name.thumb_url = j.contains("thumb_url") ? j.at("thumb_url").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.video_width = j.contains("video_width") ? j.at("video_width").get<int>() : 0;
    name.video_height = j.contains("video_height") ? j.at("video_height").get<int>() : 0;
    name.video_duration = j.contains("video_duration") ? j.at("video_duration").get<int>() : 0;
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultVideo &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["video_url"] = name.video_url;
    j["mime_type"] = name.mime_type;
    j["thumb_url"] = name.thumb_url;
    j["title"] = name.title;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["video_width"] = name.video_width;
    j["video_height"] = name.video_height;
    j["video_duration"] = name.video_duration;
    j["description"] = name.description;
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultAudio &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.audio_url = j.contains("audio_url") ? j.at("audio_url").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.performer = j.contains("performer") ? j.at("performer").get<std::string>() : "";
    name.audio_duration = j.contains("audio_duration") ? j.at("audio_duration").get<int>() : 0;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultAudio &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["audio_url"] = name.audio_url;
    j["title"] = name.title;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["performer"] = name.performer;
    j["audio_duration"] = name.audio_duration;
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultVoice &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.voice_url = j.contains("voice_url") ? j.at("voice_url").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.voice_duration = j.contains("voice_duration") ? j.at("voice_duration").get<int>() : 0;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultVoice &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["voice_url"] = name.voice_url;
    j["title"] = name.title;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["voice_duration"] = name.voice_duration;
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultDocument &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.document_url = j.contains("document_url") ? j.at("document_url").get<std::string>() : "";
    name.mime_type = j.contains("mime_type") ? j.at("mime_type").get<std::string>() : "";
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
    name.thumb_url = j.contains("thumb_url") ? j.at("thumb_url").get<std::string>() : "";
    name.thumb_width = j.contains("thumb_width") ? j.at("thumb_width").get<int>() : 0;
    name.thumb_height = j.contains("thumb_height") ? j.at("thumb_height").get<int>() : 0;
}

inline void to_json(json &j, const InlineQueryResultDocument &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["title"] = name.title;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    j["document_url"] = name.document_url;
    j["mime_type"] = name.mime_type;
    j["description"] = name.description;
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
    j["thumb_url"] = name.thumb_url;
    j["thumb_width"] = name.thumb_width;
    j["thumb_height"] = name.thumb_height;
}

inline void from_json(const json &j, InlineQueryResultLocation &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.latitude = j.contains("latitude") ? j.at("latitude").get<float>() : 0;
    name.longitude = j.contains("longitude") ? j.at("longitude").get<float>() : 0;
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.horizontal_accuracy = j.contains("horizontal_accuracy") ? j.at("horizontal_accuracy").get<float>() : 0;
    name.live_period = j.contains("live_period") ? j.at("live_period").get<int>() : 0;
    name.heading = j.contains("heading") ? j.at("heading").get<int>() : 0;
    name.proximity_alert_radius = j.contains("proximity_alert_radius") ? j.at("proximity_alert_radius").get<int>()
                                                                       : 0;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
    name.thumb_url = j.contains("thumb_url") ? j.at("thumb_url").get<std::string>() : "";
    name.thumb_width = j.contains("thumb_width") ? j.at("thumb_width").get<int>() : 0;
    name.thumb_height = j.contains("thumb_height") ? j.at("thumb_height").get<int>() : 0;
}

inline void to_json(json &j, const InlineQueryResultLocation &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["latitude"] = name.latitude;
    j["longitude"] = name.longitude;
    j["title"] = name.title;
    j["horizontal_accuracy"] = name.horizontal_accuracy;
    j["live_period"] = name.live_period;
    j["heading"] = name.heading;
    j["proximity_alert_radius"] = name.proximity_alert_radius;
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
    j["thumb_url"] = name.thumb_url;
    j["thumb_width"] = name.thumb_width;
    j["thumb_height"] = name.thumb_height;
}

inline void from_json(const json &j, InlineQueryResultVenue &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.latitude = j.contains("latitude") ? j.at("latitude").get<float>() : 0;
    name.longitude = j.contains("longitude") ? j.at("longitude").get<float>() : 0;
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.address = j.contains("address") ? j.at("address").get<std::string>() : "";
    name.foursquare_id = j.contains("foursquare_id") ? j.at("foursquare_id").get<std::string>() : "";
    name.foursquare_type = j.contains("foursquare_type") ? j.at("foursquare_type").get<std::string>() : "";
    name.google_place_id = j.contains("google_place_id") ? j.at("google_place_id").get<std::string>() : "";
    name.google_place_type = j.contains("google_place_type") ? j.at("google_place_type").get<std::string>() : "";
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
    name.thumb_url = j.contains("thumb_url") ? j.at("thumb_url").get<std::string>() : "";
    name.thumb_width = j.contains("thumb_width") ? j.at("thumb_width").get<int>() : 0;
    name.thumb_height = j.contains("thumb_height") ? j.at("thumb_height").get<int>() : 0;
}

inline void to_json(json &j, const InlineQueryResultVenue &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["latitude"] = name.latitude;
    j["longitude"] = name.longitude;
    j["title"] = name.title;
    j["address"] = name.address;
    j["foursquare_id"] = name.foursquare_id;
    j["foursquare_type"] = name.foursquare_type;
    j["google_place_id"] = name.google_place_id;
    j["google_place_type"] = name.google_place_type;
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
    j["thumb_url"] = name.thumb_url;
    j["thumb_width"] = name.thumb_width;
    j["thumb_height"] = name.thumb_height;
}

inline void from_json(const json &j, InlineQueryResultContact &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.phone_number = j.contains("phone_number") ? j.at("phone_number").get<std::string>() : "";
    name.first_name = j.contains("first_name") ? j.at("first_name").get<std::string>() : "";
    name.last_name = j.contains("last_name") ? j.at("last_name").get<std::string>() : "";
    name.vcard = j.contains("vcard") ? j.at("vcard").get<std::string>() : "";
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
    name.thumb_url = j.contains("thumb_url") ? j.at("thumb_url").get<std::string>() : "";
    name.thumb_width = j.contains("thumb_width") ? j.at("thumb_width").get<int>() : 0;
    name.thumb_height = j.contains("thumb_height") ? j.at("thumb_height").get<int>() : 0;
}

inline void to_json(json &j, const InlineQueryResultContact &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["phone_number"] = name.phone_number;
    j["first_name"] = name.first_name;
    j["last_name"] = name.last_name;
    j["vcard"] = name.vcard;
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
    j["thumb_url"] = name.thumb_url;
    j["thumb_width"] = name.thumb_width;
    j["thumb_height"] = name.thumb_height;
}

inline void from_json(const json &j, InlineQueryResultGame &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.game_short_name = j.contains("game_short_name") ? j.at("game_short_name").get<std::string>() : "";
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultGame &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["game_short_name"] = name.game_short_name;
    to_json(j["reply_markup"], *name.reply_markup);
}

inline void from_json(const json &j, InlineQueryResultCachedPhoto &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.photo_file_id = j.contains("photo_file_id") ? j.at("photo_file_id").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultCachedPhoto &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["photo_file_id"] = name.photo_file_id;
    j["title"] = name.title;
    j["description"] = name.description;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultCachedGif &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.gif_file_id = j.contains("gif_file_id") ? j.at("gif_file_id").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultCachedGif &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["gif_file_id"] = name.gif_file_id;
    j["title"] = name.title;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultCachedMpeg4Gif &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.mpeg4_file_id = j.contains("mpeg4_file_id") ? j.at("mpeg4_file_id").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultCachedMpeg4Gif &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["mpeg4_file_id"] = name.mpeg4_file_id;
    j["title"] = name.title;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultCachedSticker &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.sticker_file_id = j.contains("sticker_file_id") ? j.at("sticker_file_id").get<std::string>() : "";
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultCachedSticker &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["sticker_file_id"] = name.sticker_file_id;
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultCachedDocument &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.document_file_id = j.contains("document_file_id") ? j.at("document_file_id").get<std::string>() : "";
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultCachedDocument &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["title"] = name.title;
    j["document_file_id"] = name.document_file_id;
    j["description"] = name.description;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultCachedVideo &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.video_file_id = j.contains("video_file_id") ? j.at("video_file_id").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultCachedVideo &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["video_file_id"] = name.video_file_id;
    j["title"] = name.title;
    j["description"] = name.description;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultCachedVoice &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.voice_file_id = j.contains("voice_file_id") ? j.at("voice_file_id").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultCachedVoice &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["voice_file_id"] = name.voice_file_id;
    j["title"] = name.title;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InlineQueryResultCachedAudio &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.audio_file_id = j.contains("audio_file_id") ? j.at("audio_file_id").get<std::string>() : "";
    name.caption = j.contains("caption") ? j.at("caption").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> caption_entities;
    if (j.contains("caption_entities")) {
        for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
            caption_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.caption_entities = caption_entities;
    name.reply_markup = j.contains("reply_markup") ? std::make_shared<InlineKeyboardMarkup>(
            j.at("reply_markup").get<InlineKeyboardMarkup>()) : nullptr;
    name.input_message_content = j.contains("input_message_content") ? std::make_shared<InputMessageContent>(
            j.at("input_message_content").get<InputMessageContent>()) : nullptr;
}

inline void to_json(json &j, const InlineQueryResultCachedAudio &name) {
    j = json::object();
    j["type"] = name.type;
    j["id"] = name.id;
    j["audio_file_id"] = name.audio_file_id;
    j["caption"] = name.caption;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("caption_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["caption_entities"].push_back(u);
    }
    to_json(j["reply_markup"], *name.reply_markup);
    to_json(j["input_message_content"], *name.input_message_content);
}

inline void from_json(const json &j, InputMessageContent &name) {
    name.message_text = j.contains("message_text") ? j.at("message_text").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> entities;
    if (j.contains("entities")) {
        for (auto a: j.at("entities").get<std::vector<MessageEntity>>()) {
            entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.entities = entities;
    name.disable_web_page_preview = j.contains("disable_web_page_preview") ? j.at(
            "disable_web_page_preview").get<bool>() : false;
}

inline void to_json(json &j, const InputMessageContent &name) {
    j = json::object();
    j["message_text"] = name.message_text;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["entities"].push_back(u);
    }
    j["disable_web_page_preview"] = name.disable_web_page_preview;
}

inline void from_json(const json &j, InputTextMessageContent &name) {
    name.message_text = j.contains("message_text") ? j.at("message_text").get<std::string>() : "";
    name.parse_mode = j.contains("parse_mode") ? j.at("parse_mode").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> entities;
    if (j.contains("entities")) {
        for (auto a: j.at("entities").get<std::vector<MessageEntity>>()) {
            entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.entities = entities;
    name.disable_web_page_preview = j.contains("disable_web_page_preview") ? j.at(
            "disable_web_page_preview").get<bool>() : false;
}

inline void to_json(json &j, const InputTextMessageContent &name) {
    j = json::object();
    j["message_text"] = name.message_text;
    j["parse_mode"] = name.parse_mode;
    for (auto a: j.at("entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["entities"].push_back(u);
    }
    j["disable_web_page_preview"] = name.disable_web_page_preview;
}

inline void from_json(const json &j, InputLocationMessageContent &name) {
    name.latitude = j.contains("latitude") ? j.at("latitude").get<float>() : 0;
    name.longitude = j.contains("longitude") ? j.at("longitude").get<float>() : 0;
    name.horizontal_accuracy = j.contains("horizontal_accuracy") ? j.at("horizontal_accuracy").get<float>() : 0;
    name.live_period = j.contains("live_period") ? j.at("live_period").get<int>() : 0;
    name.heading = j.contains("heading") ? j.at("heading").get<int>() : 0;
    name.proximity_alert_radius = j.contains("proximity_alert_radius") ? j.at("proximity_alert_radius").get<int>()
                                                                       : 0;
}

inline void to_json(json &j, const InputLocationMessageContent &name) {
    j = json::object();
    j["latitude"] = name.latitude;
    j["longitude"] = name.longitude;
    j["horizontal_accuracy"] = name.horizontal_accuracy;
    j["live_period"] = name.live_period;
    j["heading"] = name.heading;
    j["proximity_alert_radius"] = name.proximity_alert_radius;
}

inline void from_json(const json &j, InputVenueMessageContent &name) {
    name.latitude = j.contains("latitude") ? j.at("latitude").get<float>() : 0;
    name.longitude = j.contains("longitude") ? j.at("longitude").get<float>() : 0;
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.address = j.contains("address") ? j.at("address").get<std::string>() : "";
    name.foursquare_id = j.contains("foursquare_id") ? j.at("foursquare_id").get<std::string>() : "";
    name.foursquare_type = j.contains("foursquare_type") ? j.at("foursquare_type").get<std::string>() : "";
    name.google_place_id = j.contains("google_place_id") ? j.at("google_place_id").get<std::string>() : "";
    name.google_place_type = j.contains("google_place_type") ? j.at("google_place_type").get<std::string>() : "";
}

inline void to_json(json &j, const InputVenueMessageContent &name) {
    j = json::object();
    j["latitude"] = name.latitude;
    j["longitude"] = name.longitude;
    j["title"] = name.title;
    j["address"] = name.address;
    j["foursquare_id"] = name.foursquare_id;
    j["foursquare_type"] = name.foursquare_type;
    j["google_place_id"] = name.google_place_id;
    j["google_place_type"] = name.google_place_type;
}

inline void from_json(const json &j, InputContactMessageContent &name) {
    name.phone_number = j.contains("phone_number") ? j.at("phone_number").get<std::string>() : "";
    name.first_name = j.contains("first_name") ? j.at("first_name").get<std::string>() : "";
    name.last_name = j.contains("last_name") ? j.at("last_name").get<std::string>() : "";
    name.vcard = j.contains("vcard") ? j.at("vcard").get<std::string>() : "";
}

inline void to_json(json &j, const InputContactMessageContent &name) {
    j = json::object();
    j["phone_number"] = name.phone_number;
    j["first_name"] = name.first_name;
    j["last_name"] = name.last_name;
    j["vcard"] = name.vcard;
}

inline void from_json(const json &j, InputInvoiceMessageContent &name) {
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.payload = j.contains("payload") ? j.at("payload").get<std::string>() : "";
    name.provider_token = j.contains("provider_token") ? j.at("provider_token").get<std::string>() : "";
    name.currency = j.contains("currency") ? j.at("currency").get<std::string>() : "";
    std::vector<std::shared_ptr<LabeledPrice>> prices;
    if (j.contains("prices")) {
        for (auto a: j.at("prices").get<std::vector<LabeledPrice>>()) {
            prices.push_back(std::make_shared<LabeledPrice>(a));
        }
    }
    name.prices = prices;
    name.max_tip_amount = j.contains("max_tip_amount") ? j.at("max_tip_amount").get<int>() : 0;
    name.suggested_tip_amounts = j.contains("suggested_tip_amounts") ? j.at("suggested_tip_amounts").get<int>() : 0;
    name.provider_data = j.contains("provider_data") ? j.at("provider_data").get<std::string>() : "";
    name.photo_url = j.contains("photo_url") ? j.at("photo_url").get<std::string>() : "";
    name.photo_size = j.contains("photo_size") ? j.at("photo_size").get<int>() : 0;
    name.photo_width = j.contains("photo_width") ? j.at("photo_width").get<int>() : 0;
    name.photo_height = j.contains("photo_height") ? j.at("photo_height").get<int>() : 0;
    name.need_name = j.contains("need_name") ? j.at("need_name").get<bool>() : false;
    name.need_phone_number = j.contains("need_phone_number") ? j.at("need_phone_number").get<bool>() : false;
    name.need_email = j.contains("need_email") ? j.at("need_email").get<bool>() : false;
    name.need_shipping_address = j.contains("need_shipping_address") ? j.at("need_shipping_address").get<bool>()
                                                                     : false;
    name.send_phone_number_to_provider = j.contains("send_phone_number_to_provider") ? j.at(
            "send_phone_number_to_provider").get<bool>() : false;
    name.send_email_to_provider = j.contains("send_email_to_provider") ? j.at("send_email_to_provider").get<bool>()
                                                                       : false;
    name.is_flexible = j.contains("is_flexible") ? j.at("is_flexible").get<bool>() : false;
}

inline void to_json(json &j, const InputInvoiceMessageContent &name) {
    j = json::object();
    j["title"] = name.title;
    j["description"] = name.description;
    j["payload"] = name.payload;
    j["provider_token"] = name.provider_token;
    j["currency"] = name.currency;
    for (auto a: j.at("prices").get<std::vector<LabeledPrice>>()) {
        auto u = json::object();
        to_json(u, a);
        j["prices"].push_back(u);
    }
    j["max_tip_amount"] = name.max_tip_amount;
    j["suggested_tip_amounts"] = name.suggested_tip_amounts;
    j["provider_data"] = name.provider_data;
    j["photo_url"] = name.photo_url;
    j["photo_size"] = name.photo_size;
    j["photo_width"] = name.photo_width;
    j["photo_height"] = name.photo_height;
    j["need_name"] = name.need_name;
    j["need_phone_number"] = name.need_phone_number;
    j["need_email"] = name.need_email;
    j["need_shipping_address"] = name.need_shipping_address;
    j["send_phone_number_to_provider"] = name.send_phone_number_to_provider;
    j["send_email_to_provider"] = name.send_email_to_provider;
    j["is_flexible"] = name.is_flexible;
}

inline void from_json(const json &j, ChosenInlineResult &name) {
    name.result_id = j.contains("result_id") ? j.at("result_id").get<std::string>() : "";
    name.from = j.contains("from") ? std::make_shared<User>(j.at("from").get<User>()) : nullptr;
    name.location = j.contains("location") ? std::make_shared<Location>(j.at("location").get<Location>()) : nullptr;
    name.inline_message_id = j.contains("inline_message_id") ? j.at("inline_message_id").get<std::string>() : "";
    name.query = j.contains("query") ? j.at("query").get<std::string>() : "";
}

inline void to_json(json &j, const ChosenInlineResult &name) {
    j = json::object();
    j["result_id"] = name.result_id;
    to_json(j["from"], *name.from);
    to_json(j["location"], *name.location);
    j["inline_message_id"] = name.inline_message_id;
    j["query"] = name.query;
}

inline void from_json(const json &j, SentWebAppMessage &name) {
    name.inline_message_id = j.contains("inline_message_id") ? j.at("inline_message_id").get<std::string>() : "";
}

inline void to_json(json &j, const SentWebAppMessage &name) {
    j = json::object();
    j["inline_message_id"] = name.inline_message_id;
}

inline void from_json(const json &j, Payments &name) {
}

inline void to_json(json &j, const Payments &name) {
    j = json::object();
}

inline void from_json(const json &j, LabeledPrice &name) {
    name.label = j.contains("label") ? j.at("label").get<std::string>() : "";
    name.amount = j.contains("amount") ? j.at("amount").get<int>() : 0;
}

inline void to_json(json &j, const LabeledPrice &name) {
    j = json::object();
    j["label"] = name.label;
    j["amount"] = name.amount;
}

inline void from_json(const json &j, Invoice &name) {
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    name.start_parameter = j.contains("start_parameter") ? j.at("start_parameter").get<std::string>() : "";
    name.currency = j.contains("currency") ? j.at("currency").get<std::string>() : "";
    name.total_amount = j.contains("total_amount") ? j.at("total_amount").get<int>() : 0;
}

inline void to_json(json &j, const Invoice &name) {
    j = json::object();
    j["title"] = name.title;
    j["description"] = name.description;
    j["start_parameter"] = name.start_parameter;
    j["currency"] = name.currency;
    j["total_amount"] = name.total_amount;
}

inline void from_json(const json &j, ShippingAddress &name) {
    name.country_code = j.contains("country_code") ? j.at("country_code").get<std::string>() : "";
    name.state = j.contains("state") ? j.at("state").get<std::string>() : "";
    name.city = j.contains("city") ? j.at("city").get<std::string>() : "";
    name.street_line1 = j.contains("street_line1") ? j.at("street_line1").get<std::string>() : "";
    name.street_line2 = j.contains("street_line2") ? j.at("street_line2").get<std::string>() : "";
    name.post_code = j.contains("post_code") ? j.at("post_code").get<std::string>() : "";
}

inline void to_json(json &j, const ShippingAddress &name) {
    j = json::object();
    j["country_code"] = name.country_code;
    j["state"] = name.state;
    j["city"] = name.city;
    j["street_line1"] = name.street_line1;
    j["street_line2"] = name.street_line2;
    j["post_code"] = name.post_code;
}

inline void from_json(const json &j, OrderInfo &name) {
    name.name = j.contains("name") ? j.at("name").get<std::string>() : "";
    name.phone_number = j.contains("phone_number") ? j.at("phone_number").get<std::string>() : "";
    name.email = j.contains("email") ? j.at("email").get<std::string>() : "";
    name.shipping_address = j.contains("shipping_address") ? std::make_shared<ShippingAddress>(
            j.at("shipping_address").get<ShippingAddress>()) : nullptr;
}

inline void to_json(json &j, const OrderInfo &name) {
    j = json::object();
    j["name"] = name.name;
    j["phone_number"] = name.phone_number;
    j["email"] = name.email;
    to_json(j["shipping_address"], *name.shipping_address);
}

inline void from_json(const json &j, ShippingOption &name) {
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    std::vector<std::shared_ptr<LabeledPrice>> prices;
    if (j.contains("prices")) {
        for (auto a: j.at("prices").get<std::vector<LabeledPrice>>()) {
            prices.push_back(std::make_shared<LabeledPrice>(a));
        }
    }
    name.prices = prices;
}

inline void to_json(json &j, const ShippingOption &name) {
    j = json::object();
    j["id"] = name.id;
    j["title"] = name.title;
    for (auto a: j.at("prices").get<std::vector<LabeledPrice>>()) {
        auto u = json::object();
        to_json(u, a);
        j["prices"].push_back(u);
    }
}

inline void from_json(const json &j, SuccessfulPayment &name) {
    name.currency = j.contains("currency") ? j.at("currency").get<std::string>() : "";
    name.total_amount = j.contains("total_amount") ? j.at("total_amount").get<int>() : 0;
    name.invoice_payload = j.contains("invoice_payload") ? j.at("invoice_payload").get<std::string>() : "";
    name.shipping_option_id = j.contains("shipping_option_id") ? j.at("shipping_option_id").get<std::string>() : "";
    name.order_info = j.contains("order_info") ? std::make_shared<OrderInfo>(j.at("order_info").get<OrderInfo>())
                                               : nullptr;
    name.telegram_payment_charge_id = j.contains("telegram_payment_charge_id") ? j.at(
            "telegram_payment_charge_id").get<std::string>() : "";
    name.provider_payment_charge_id = j.contains("provider_payment_charge_id") ? j.at(
            "provider_payment_charge_id").get<std::string>() : "";
}

inline void to_json(json &j, const SuccessfulPayment &name) {
    j = json::object();
    j["currency"] = name.currency;
    j["total_amount"] = name.total_amount;
    j["invoice_payload"] = name.invoice_payload;
    j["shipping_option_id"] = name.shipping_option_id;
    to_json(j["order_info"], *name.order_info);
    j["telegram_payment_charge_id"] = name.telegram_payment_charge_id;
    j["provider_payment_charge_id"] = name.provider_payment_charge_id;
}

inline void from_json(const json &j, ShippingQuery &name) {
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.from = j.contains("from") ? std::make_shared<User>(j.at("from").get<User>()) : nullptr;
    name.invoice_payload = j.contains("invoice_payload") ? j.at("invoice_payload").get<std::string>() : "";
    name.shipping_address = j.contains("shipping_address") ? std::make_shared<ShippingAddress>(
            j.at("shipping_address").get<ShippingAddress>()) : nullptr;
}

inline void to_json(json &j, const ShippingQuery &name) {
    j = json::object();
    j["id"] = name.id;
    to_json(j["from"], *name.from);
    j["invoice_payload"] = name.invoice_payload;
    to_json(j["shipping_address"], *name.shipping_address);
}

inline void from_json(const json &j, PreCheckoutQuery &name) {
    name.id = j.contains("id") ? j.at("id").get<std::string>() : "";
    name.from = j.contains("from") ? std::make_shared<User>(j.at("from").get<User>()) : nullptr;
    name.currency = j.contains("currency") ? j.at("currency").get<std::string>() : "";
    name.total_amount = j.contains("total_amount") ? j.at("total_amount").get<int>() : 0;
    name.invoice_payload = j.contains("invoice_payload") ? j.at("invoice_payload").get<std::string>() : "";
    name.shipping_option_id = j.contains("shipping_option_id") ? j.at("shipping_option_id").get<std::string>() : "";
    name.order_info = j.contains("order_info") ? std::make_shared<OrderInfo>(j.at("order_info").get<OrderInfo>())
                                               : nullptr;
}

inline void to_json(json &j, const PreCheckoutQuery &name) {
    j = json::object();
    j["id"] = name.id;
    to_json(j["from"], *name.from);
    j["currency"] = name.currency;
    j["total_amount"] = name.total_amount;
    j["invoice_payload"] = name.invoice_payload;
    j["shipping_option_id"] = name.shipping_option_id;
    to_json(j["order_info"], *name.order_info);
}

inline void from_json(const json &j, PassportData &name) {
    std::vector<std::shared_ptr<EncryptedPassportElement>> data;
    if (j.contains("data")) {
        for (auto a: j.at("data").get<std::vector<EncryptedPassportElement>>()) {
            data.push_back(std::make_shared<EncryptedPassportElement>(a));
        }
    }
    name.data = data;
    name.credentials = j.contains("credentials") ? std::make_shared<EncryptedCredentials>(
            j.at("credentials").get<EncryptedCredentials>()) : nullptr;
}

inline void to_json(json &j, const PassportData &name) {
    j = json::object();
    for (auto a: j.at("data").get<std::vector<EncryptedPassportElement>>()) {
        auto u = json::object();
        to_json(u, a);
        j["data"].push_back(u);
    }
    to_json(j["credentials"], *name.credentials);
}

inline void from_json(const json &j, PassportFile &name) {
    name.file_id = j.contains("file_id") ? j.at("file_id").get<std::string>() : "";
    name.file_unique_id = j.contains("file_unique_id") ? j.at("file_unique_id").get<std::string>() : "";
    name.file_size = j.contains("file_size") ? j.at("file_size").get<int>() : 0;
    name.file_date = j.contains("file_date") ? j.at("file_date").get<int>() : 0;
}

inline void to_json(json &j, const PassportFile &name) {
    j = json::object();
    j["file_id"] = name.file_id;
    j["file_unique_id"] = name.file_unique_id;
    j["file_size"] = name.file_size;
    j["file_date"] = name.file_date;
}

inline void from_json(const json &j, EncryptedPassportElement &name) {
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.data = j.contains("data") ? j.at("data").get<std::string>() : "";
    name.phone_number = j.contains("phone_number") ? j.at("phone_number").get<std::string>() : "";
    name.email = j.contains("email") ? j.at("email").get<std::string>() : "";
    std::vector<std::shared_ptr<PassportFile>> files;
    if (j.contains("files")) {
        for (auto a: j.at("files").get<std::vector<PassportFile>>()) {
            files.push_back(std::make_shared<PassportFile>(a));
        }
    }
    name.files = files;
    name.front_side = j.contains("front_side") ? std::make_shared<PassportFile>(
            j.at("front_side").get<PassportFile>()) : nullptr;
    name.reverse_side = j.contains("reverse_side") ? std::make_shared<PassportFile>(
            j.at("reverse_side").get<PassportFile>()) : nullptr;
    name.selfie = j.contains("selfie") ? std::make_shared<PassportFile>(j.at("selfie").get<PassportFile>())
                                       : nullptr;
    std::vector<std::shared_ptr<PassportFile>> translation;
    if (j.contains("translation")) {
        for (auto a: j.at("translation").get<std::vector<PassportFile>>()) {
            translation.push_back(std::make_shared<PassportFile>(a));
        }
    }
    name.translation = translation;
    name.hash = j.contains("hash") ? j.at("hash").get<std::string>() : "";
}

inline void to_json(json &j, const EncryptedPassportElement &name) {
    j = json::object();
    j["type"] = name.type;
    j["data"] = name.data;
    j["phone_number"] = name.phone_number;
    j["email"] = name.email;
    for (auto a: j.at("files").get<std::vector<PassportFile>>()) {
        auto u = json::object();
        to_json(u, a);
        j["files"].push_back(u);
    }
    to_json(j["front_side"], *name.front_side);
    to_json(j["reverse_side"], *name.reverse_side);
    to_json(j["selfie"], *name.selfie);
    for (auto a: j.at("translation").get<std::vector<PassportFile>>()) {
        auto u = json::object();
        to_json(u, a);
        j["translation"].push_back(u);
    }
    j["hash"] = name.hash;
}

inline void from_json(const json &j, EncryptedCredentials &name) {
    name.data = j.contains("data") ? j.at("data").get<std::string>() : "";
    name.hash = j.contains("hash") ? j.at("hash").get<std::string>() : "";
    name.secret = j.contains("secret") ? j.at("secret").get<std::string>() : "";
}

inline void to_json(json &j, const EncryptedCredentials &name) {
    j = json::object();
    j["data"] = name.data;
    j["hash"] = name.hash;
    j["secret"] = name.secret;
}

inline void from_json(const json &j, PassportElementError &name) {
    name.source = j.contains("source") ? j.at("source").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.field_name = j.contains("field_name") ? j.at("field_name").get<std::string>() : "";
    name.data_hash = j.contains("data_hash") ? j.at("data_hash").get<std::string>() : "";
    name.message = j.contains("message") ? j.at("message").get<std::string>() : "";
}

inline void to_json(json &j, const PassportElementError &name) {
    j = json::object();
    j["source"] = name.source;
    j["type"] = name.type;
    j["field_name"] = name.field_name;
    j["data_hash"] = name.data_hash;
    j["message"] = name.message;
}

inline void from_json(const json &j, PassportElementErrorDataField &name) {
    name.source = j.contains("source") ? j.at("source").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.field_name = j.contains("field_name") ? j.at("field_name").get<std::string>() : "";
    name.data_hash = j.contains("data_hash") ? j.at("data_hash").get<std::string>() : "";
    name.message = j.contains("message") ? j.at("message").get<std::string>() : "";
}

inline void to_json(json &j, const PassportElementErrorDataField &name) {
    j = json::object();
    j["source"] = name.source;
    j["type"] = name.type;
    j["field_name"] = name.field_name;
    j["data_hash"] = name.data_hash;
    j["message"] = name.message;
}

inline void from_json(const json &j, PassportElementErrorFrontSide &name) {
    name.source = j.contains("source") ? j.at("source").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.file_hash = j.contains("file_hash") ? j.at("file_hash").get<std::string>() : "";
    name.message = j.contains("message") ? j.at("message").get<std::string>() : "";
}

inline void to_json(json &j, const PassportElementErrorFrontSide &name) {
    j = json::object();
    j["source"] = name.source;
    j["type"] = name.type;
    j["file_hash"] = name.file_hash;
    j["message"] = name.message;
}

inline void from_json(const json &j, PassportElementErrorReverseSide &name) {
    name.source = j.contains("source") ? j.at("source").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.file_hash = j.contains("file_hash") ? j.at("file_hash").get<std::string>() : "";
    name.message = j.contains("message") ? j.at("message").get<std::string>() : "";
}

inline void to_json(json &j, const PassportElementErrorReverseSide &name) {
    j = json::object();
    j["source"] = name.source;
    j["type"] = name.type;
    j["file_hash"] = name.file_hash;
    j["message"] = name.message;
}

inline void from_json(const json &j, PassportElementErrorSelfie &name) {
    name.source = j.contains("source") ? j.at("source").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.file_hash = j.contains("file_hash") ? j.at("file_hash").get<std::string>() : "";
    name.message = j.contains("message") ? j.at("message").get<std::string>() : "";
}

inline void to_json(json &j, const PassportElementErrorSelfie &name) {
    j = json::object();
    j["source"] = name.source;
    j["type"] = name.type;
    j["file_hash"] = name.file_hash;
    j["message"] = name.message;
}

inline void from_json(const json &j, PassportElementErrorFile &name) {
    name.source = j.contains("source") ? j.at("source").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.file_hash = j.contains("file_hash") ? j.at("file_hash").get<std::string>() : "";
    name.message = j.contains("message") ? j.at("message").get<std::string>() : "";
}

inline void to_json(json &j, const PassportElementErrorFile &name) {
    j = json::object();
    j["source"] = name.source;
    j["type"] = name.type;
    j["file_hash"] = name.file_hash;
    j["message"] = name.message;
}

inline void from_json(const json &j, PassportElementErrorFiles &name) {
    name.source = j.contains("source") ? j.at("source").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.file_hashes = j.contains("file_hashes") ? j.at("file_hashes").get<std::string>() : "";
    name.message = j.contains("message") ? j.at("message").get<std::string>() : "";
}

inline void to_json(json &j, const PassportElementErrorFiles &name) {
    j = json::object();
    j["source"] = name.source;
    j["type"] = name.type;
    j["file_hashes"] = name.file_hashes;
    j["message"] = name.message;
}

inline void from_json(const json &j, PassportElementErrorTranslationFile &name) {
    name.source = j.contains("source") ? j.at("source").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.file_hash = j.contains("file_hash") ? j.at("file_hash").get<std::string>() : "";
    name.message = j.contains("message") ? j.at("message").get<std::string>() : "";
}

inline void to_json(json &j, const PassportElementErrorTranslationFile &name) {
    j = json::object();
    j["source"] = name.source;
    j["type"] = name.type;
    j["file_hash"] = name.file_hash;
    j["message"] = name.message;
}

inline void from_json(const json &j, PassportElementErrorTranslationFiles &name) {
    name.source = j.contains("source") ? j.at("source").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.file_hashes = j.contains("file_hashes") ? j.at("file_hashes").get<std::string>() : "";
    name.message = j.contains("message") ? j.at("message").get<std::string>() : "";
}

inline void to_json(json &j, const PassportElementErrorTranslationFiles &name) {
    j = json::object();
    j["source"] = name.source;
    j["type"] = name.type;
    j["file_hashes"] = name.file_hashes;
    j["message"] = name.message;
}

inline void from_json(const json &j, PassportElementErrorUnspecified &name) {
    name.source = j.contains("source") ? j.at("source").get<std::string>() : "";
    name.type = j.contains("type") ? j.at("type").get<std::string>() : "";
    name.element_hash = j.contains("element_hash") ? j.at("element_hash").get<std::string>() : "";
    name.message = j.contains("message") ? j.at("message").get<std::string>() : "";
}

inline void to_json(json &j, const PassportElementErrorUnspecified &name) {
    j = json::object();
    j["source"] = name.source;
    j["type"] = name.type;
    j["element_hash"] = name.element_hash;
    j["message"] = name.message;
}

inline void from_json(const json &j, Games &name) {
}

inline void to_json(json &j, const Games &name) {
    j = json::object();
}

inline void from_json(const json &j, Game &name) {
    name.title = j.contains("title") ? j.at("title").get<std::string>() : "";
    name.description = j.contains("description") ? j.at("description").get<std::string>() : "";
    std::vector<std::shared_ptr<PhotoSize>> photo;
    if (j.contains("photo")) {
        for (auto a: j.at("photo").get<std::vector<PhotoSize>>()) {
            photo.push_back(std::make_shared<PhotoSize>(a));
        }
    }
    name.photo = photo;
    name.text = j.contains("text") ? j.at("text").get<std::string>() : "";
    std::vector<std::shared_ptr<MessageEntity>> text_entities;
    if (j.contains("text_entities")) {
        for (auto a: j.at("text_entities").get<std::vector<MessageEntity>>()) {
            text_entities.push_back(std::make_shared<MessageEntity>(a));
        }
    }
    name.text_entities = text_entities;
    name.animation = j.contains("animation") ? std::make_shared<Animation>(j.at("animation").get<Animation>())
                                             : nullptr;
}

inline void to_json(json &j, const Game &name) {
    j = json::object();
    j["title"] = name.title;
    j["description"] = name.description;
    for (auto a: j.at("photo").get<std::vector<PhotoSize>>()) {
        auto u = json::object();
        to_json(u, a);
        j["photo"].push_back(u);
    }
    j["text"] = name.text;
    for (auto a: j.at("text_entities").get<std::vector<MessageEntity>>()) {
        auto u = json::object();
        to_json(u, a);
        j["text_entities"].push_back(u);
    }
    to_json(j["animation"], *name.animation);
}

inline void from_json(const json &j, CallbackGame &name) {
}

inline void to_json(json &j, const CallbackGame &name) {
    j = json::object();
}

inline void from_json(const json &j, GameHighScore &name) {
    name.position = j.contains("position") ? j.at("position").get<int>() : 0;
    name.user = j.contains("user") ? std::make_shared<User>(j.at("user").get<User>()) : nullptr;
    name.score = j.contains("score") ? j.at("score").get<int>() : 0;
}

inline void to_json(json &j, const GameHighScore &name) {
    j = json::object();
    j["position"] = name.position;
    to_json(j["user"], *name.user);
    j["score"] = name.score;
}