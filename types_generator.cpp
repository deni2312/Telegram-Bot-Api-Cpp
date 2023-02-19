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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"id", id},{"is_bot", is_bot},{"first_name", first_name},{"last_name", last_name},{"username", username},{"language_code", language_code},{"is_premium", is_premium},{"added_to_attachment_menu", added_to_attachment_menu},{"can_join_groups", can_join_groups},{"can_read_all_group_messages", can_read_all_group_messages},{"supports_inline_queries", supports_inline_queries},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"id", id},{"type", type},{"title", title},{"username", username},{"first_name", first_name},{"last_name", last_name},{"is_forum", is_forum},{"photo", photo},{"active_usernames", active_usernames},{"emoji_status_custom_emoji_id", emoji_status_custom_emoji_id},{"bio", bio},{"has_private_forwards", has_private_forwards},{"has_restricted_voice_and_video_messages", has_restricted_voice_and_video_messages},{"join_to_send_messages", join_to_send_messages},{"join_by_request", join_by_request},{"description", description},{"invite_link", invite_link},{"pinned_message", pinned_message},{"permissions", permissions},{"slow_mode_delay", slow_mode_delay},{"message_auto_delete_time", message_auto_delete_time},{"has_aggressive_anti_spam_enabled", has_aggressive_anti_spam_enabled},{"has_hidden_members", has_hidden_members},{"has_protected_content", has_protected_content},{"sticker_set_name", sticker_set_name},{"can_set_sticker_set", can_set_sticker_set},{"linked_chat_id", linked_chat_id},{"location", location},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"message_id", message_id},{"message_thread_id", message_thread_id},{"from", from},{"sender_chat", sender_chat},{"date", date},{"chat", chat},{"forward_from", forward_from},{"forward_from_chat", forward_from_chat},{"forward_from_message_id", forward_from_message_id},{"forward_signature", forward_signature},{"forward_sender_name", forward_sender_name},{"forward_date", forward_date},{"is_topic_message", is_topic_message},{"is_automatic_forward", is_automatic_forward},{"reply_to_message", reply_to_message},{"via_bot", via_bot},{"edit_date", edit_date},{"has_protected_content", has_protected_content},{"media_group_id", media_group_id},{"author_signature", author_signature},{"text", text},{"entities", entities},{"animation", animation},{"audio", audio},{"document", document},{"photo", photo},{"sticker", sticker},{"video", video},{"video_note", video_note},{"voice", voice},{"caption", caption},{"caption_entities", caption_entities},{"has_media_spoiler", has_media_spoiler},{"contact", contact},{"dice", dice},{"game", game},{"poll", poll},{"venue", venue},{"location", location},{"new_chat_members", new_chat_members},{"left_chat_member", left_chat_member},{"new_chat_title", new_chat_title},{"new_chat_photo", new_chat_photo},{"delete_chat_photo", delete_chat_photo},{"group_chat_created", group_chat_created},{"supergroup_chat_created", supergroup_chat_created},{"channel_chat_created", channel_chat_created},{"message_auto_delete_timer_changed", message_auto_delete_timer_changed},{"migrate_to_chat_id", migrate_to_chat_id},{"migrate_from_chat_id", migrate_from_chat_id},{"pinned_message", pinned_message},{"invoice", invoice},{"successful_payment", successful_payment},{"user_shared", user_shared},{"chat_shared", chat_shared},{"connected_website", connected_website},{"write_access_allowed", write_access_allowed},{"passport_data", passport_data},{"proximity_alert_triggered", proximity_alert_triggered},{"forum_topic_created", forum_topic_created},{"forum_topic_edited", forum_topic_edited},{"forum_topic_closed", forum_topic_closed},{"forum_topic_reopened", forum_topic_reopened},{"general_forum_topic_hidden", general_forum_topic_hidden},{"general_forum_topic_unhidden", general_forum_topic_unhidden},{"video_chat_scheduled", video_chat_scheduled},{"video_chat_started", video_chat_started},{"video_chat_ended", video_chat_ended},{"video_chat_participants_invited", video_chat_participants_invited},{"web_app_data", web_app_data},{"reply_markup", reply_markup},};
	}
};

//This object represents a unique message identifier.
struct MessageId{
	int message_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"message_id", message_id},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"offset", offset},{"length", length},{"url", url},{"user", user},{"language", language},{"custom_emoji_id", custom_emoji_id},};
	}
};

//This object represents one size of a photo or a <a href="#document">file</a> / <a href="#sticker">sticker</a> thumbnail.
struct PhotoSize{
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int file_size;
    // Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"file_id", file_id},{"file_unique_id", file_unique_id},{"width", width},{"height", height},{"file_size", file_size},};
	}
    void from_json(const json& j) {

    }
};

//This object represents an animation file (GIF or H.264/MPEG-4 AVC video without sound).
struct Animation{
	std::string file_id;
	std::string file_unique_id;
	int width;
	int height;
	int duration;
	PhotoSize thumb;
	std::string file_name;
	std::string mime_type;
	int file_size;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"file_id", file_id},{"file_unique_id", file_unique_id},{"width", width},{"height", height},{"duration", duration},{"thumb", thumb},{"file_name", file_name},{"mime_type", mime_type},{"file_size", file_size}};
	}
    void from_json(const json& j) {

    }
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"file_id", file_id},{"file_unique_id", file_unique_id},{"duration", duration},{"performer", performer},{"title", title},{"file_name", file_name},{"mime_type", mime_type},{"file_size", file_size},{"thumb", thumb},};
	}
};

//This object represents a general file (as opposed to <a href="#photosize">photos</a>, <a href="#voice">voice messages</a> and <a href="#audio">audio files</a>).
struct Document{
	std::string file_id;
	std::string file_unique_id;
	std::shared_ptr<PhotoSize> thumb;
	std::string file_name;
	std::string mime_type;
	int file_size;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"file_id", file_id},{"file_unique_id", file_unique_id},{"thumb", thumb},{"file_name", file_name},{"mime_type", mime_type},{"file_size", file_size},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"file_id", file_id},{"file_unique_id", file_unique_id},{"width", width},{"height", height},{"duration", duration},{"thumb", thumb},{"file_name", file_name},{"mime_type", mime_type},{"file_size", file_size},};
	}
};

//This object represents a <a href="https://telegram.org/blog/video-messages-and-telescope">video message</a> (available in Telegram apps as of <a href="https://telegram.org/blog/video-messages-and-telescope">v.4.0</a>).
struct VideoNote{
	std::string file_id;
	std::string file_unique_id;
	int length;
	int duration;
	std::shared_ptr<PhotoSize> thumb;
	int file_size;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"file_id", file_id},{"file_unique_id", file_unique_id},{"length", length},{"duration", duration},{"thumb", thumb},{"file_size", file_size},};
	}
};

//This object represents a voice note.
struct Voice{
	std::string file_id;
	std::string file_unique_id;
	int duration;
	std::string mime_type;
	int file_size;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"file_id", file_id},{"file_unique_id", file_unique_id},{"duration", duration},{"mime_type", mime_type},{"file_size", file_size},};
	}
};

//This object represents a phone contact.
struct Contact{
	std::string phone_number;
	std::string first_name;
	std::string last_name;
	int user_id;
	std::string vcard;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"phone_number", phone_number},{"first_name", first_name},{"last_name", last_name},{"user_id", user_id},{"vcard", vcard},};
	}
};

//This object represents an animated emoji that displays a random value.
struct Dice{
	std::string emoji;
	int value;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"emoji", emoji},{"value", value},};
	}
};

//This object contains information about one answer option in a poll.
struct PollOption{
	std::string text;
	int voter_count;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"text", text},{"voter_count", voter_count},};
	}
};

//This object represents an answer of a user in a non-anonymous poll.
struct PollAnswer{
	std::string poll_id;
	std::shared_ptr<User> user;
	int option_ids;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"poll_id", poll_id},{"user", user},{"option_ids", option_ids},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"id", id},{"question", question},{"options", options},{"total_voter_count", total_voter_count},{"is_closed", is_closed},{"is_anonymous", is_anonymous},{"type", type},{"allows_multiple_answers", allows_multiple_answers},{"correct_option_id", correct_option_id},{"explanation", explanation},{"explanation_entities", explanation_entities},{"open_period", open_period},{"close_date", close_date},};
	}
};

//This object represents a point on the map.
struct Location{
	float longitude;
	float latitude;
	float horizontal_accuracy;
	int live_period;
	int heading;
	int proximity_alert_radius;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"longitude", longitude},{"latitude", latitude},{"horizontal_accuracy", horizontal_accuracy},{"live_period", live_period},{"heading", heading},{"proximity_alert_radius", proximity_alert_radius},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"location", location},{"title", title},{"address", address},{"foursquare_id", foursquare_id},{"foursquare_type", foursquare_type},{"google_place_id", google_place_id},{"google_place_type", google_place_type},};
	}
};

//Describes data sent from a <a href="/bots/webapps">Web App</a> to the bot.
struct WebAppData{
	std::string data;
	std::string button_text;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"data", data},{"button_text", button_text},};
	}
};

//This object represents the content of a service message, sent whenever a user in the chat triggers a proximity alert set by another user.
struct ProximityAlertTriggered{
	std::shared_ptr<User> traveler;
	std::shared_ptr<User> watcher;
	int distance;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"traveler", traveler},{"watcher", watcher},{"distance", distance},};
	}
};

//This object represents a service message about a change in auto-delete timer settings.
struct MessageAutoDeleteTimerChanged{
	int message_auto_delete_time;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"message_auto_delete_time", message_auto_delete_time},};
	}
};

//This object represents a service message about a new forum topic created in the chat.
struct ForumTopicCreated{
	std::string name;
	int icon_color;
	std::string icon_custom_emoji_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"name", name},{"icon_color", icon_color},{"icon_custom_emoji_id", icon_custom_emoji_id},};
	}
};

//This object represents a service message about a forum topic closed in the chat. Currently holds no information.
struct ForumTopicClosed{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object represents a service message about an edited forum topic.
struct ForumTopicEdited{
	std::string name;
	std::string icon_custom_emoji_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"name", name},{"icon_custom_emoji_id", icon_custom_emoji_id},};
	}
};

//This object represents a service message about a forum topic reopened in the chat. Currently holds no information.
struct ForumTopicReopened{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object represents a service message about General forum topic hidden in the chat. Currently holds no information.
struct GeneralForumTopicHidden{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object represents a service message about General forum topic unhidden in the chat. Currently holds no information.
struct GeneralForumTopicUnhidden{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object contains information about the user whose identifier was shared with the bot using a <a href="#keyboardbuttonrequestuser">KeyboardButtonRequestUser</a> button.
struct UserShared{
	int request_id;
	int user_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"request_id", request_id},{"user_id", user_id},};
	}
};

//This object contains information about the chat whose identifier was shared with the bot using a <a href="#keyboardbuttonrequestchat">KeyboardButtonRequestChat</a> button.
struct ChatShared{
	int request_id;
	int chat_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"request_id", request_id},{"chat_id", chat_id},};
	}
};

//This object represents a service message about a user allowing a bot added to the attachment menu to write messages. Currently holds no information.
struct WriteAccessAllowed{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object represents a service message about a video chat scheduled in the chat.
struct VideoChatScheduled{
	int start_date;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"start_date", start_date},};
	}
};

//This object represents a service message about a video chat started in the chat. Currently holds no information.
struct VideoChatStarted{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object represents a service message about a video chat ended in the chat.
struct VideoChatEnded{
	int duration;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"duration", duration},};
	}
};

//This object represents a service message about new members invited to a video chat.
struct VideoChatParticipantsInvited{
	std::vector<std::shared_ptr<User>> users;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"users", users},};
	}
};

//This object represent a user&#39;s profile pictures.
struct UserProfilePhotos{
	int total_count;
	std::vector<std::shared_ptr<PhotoSize>> photos;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"total_count", total_count},{"photos", photos},};
	}
};

//This object represents a file ready to be downloaded. The file can be downloaded via the link <code>https://api.telegram.org/file/bot&lt;token&gt;/&lt;file_path&gt;</code>. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling <a href="#getfile">getFile</a>.
struct File{
	std::string file_id;
	std::string file_unique_id;
	int file_size;
	std::string file_path;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"file_id", file_id},{"file_unique_id", file_unique_id},{"file_size", file_size},{"file_path", file_path},};
	}
};

//Describes a <a href="/bots/webapps">Web App</a>.
struct WebAppInfo{
	std::string url;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"url", url},};
	}
};

//This object represents a <a href="/bots/features#keyboards">custom keyboard</a> with reply options (see <a href="/bots/features#keyboards">Introduction to bots</a> for details and examples).
struct ReplyKeyboardMarkup{
	std::vector<std::shared_ptr<KeyboardButton>> keyboard;
	bool is_persistent;
	bool resize_keyboard;
	bool one_time_keyboard;
	std::string input_field_placeholder;
	bool selective;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"keyboard", keyboard},{"is_persistent", is_persistent},{"resize_keyboard", resize_keyboard},{"one_time_keyboard", one_time_keyboard},{"input_field_placeholder", input_field_placeholder},{"selective", selective},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"text", text},{"request_user", request_user},{"request_chat", request_chat},{"request_contact", request_contact},{"request_location", request_location},{"request_poll", request_poll},{"web_app", web_app},};
	}
};

//This object defines the criteria used to request a suitable user. The identifier of the selected user will be shared with the bot when the corresponding button is pressed.
struct KeyboardButtonRequestUser{
	int request_id;
	bool user_is_bot;
	bool user_is_premium;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"request_id", request_id},{"user_is_bot", user_is_bot},{"user_is_premium", user_is_premium},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"request_id", request_id},{"chat_is_channel", chat_is_channel},{"chat_is_forum", chat_is_forum},{"chat_has_username", chat_has_username},{"chat_is_created", chat_is_created},{"user_administrator_rights", user_administrator_rights},{"bot_administrator_rights", bot_administrator_rights},{"bot_is_member", bot_is_member},};
	}
};

//This object represents type of a poll, which is allowed to be created and sent when the corresponding button is pressed.
struct KeyboardButtonPollType{
	std::string type;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},};
	}
};

//Upon receiving a message with this object, Telegram clients will remove the current custom keyboard and display the default letter-keyboard. By default, custom keyboards are displayed until a new keyboard is sent by a bot. An exception is made for one-time keyboards that are hidden immediately after the user presses a button (see <a href="#replykeyboardmarkup">ReplyKeyboardMarkup</a>).
struct ReplyKeyboardRemove{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object represents an <a href="/bots/features#inline-keyboards">inline keyboard</a> that appears right next to the message it belongs to.
struct InlineKeyboardMarkup{
	std::vector<std::shared_ptr<InlineKeyboardButton>> inline_keyboard;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"inline_keyboard", inline_keyboard},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"text", text},{"url", url},{"callback_data", callback_data},{"web_app", web_app},{"login_url", login_url},{"switch_inline_query", switch_inline_query},{"switch_inline_query_current_chat", switch_inline_query_current_chat},{"callback_game", callback_game},{"pay", pay},};
	}
};

//This object represents a parameter of the inline keyboard button used to automatically authorize a user. Serves as a great replacement for the <a href="/widgets/login">Telegram Login Widget</a> when the user is coming from Telegram. All the user needs to do is tap/click a button and confirm that they want to log in:
struct LoginUrl{
	std::string url;
	std::string forward_text;
	std::string bot_username;
	bool request_write_access;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"url", url},{"forward_text", forward_text},{"bot_username", bot_username},{"request_write_access", request_write_access},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"id", id},{"from", from},{"message", message},{"inline_message_id", inline_message_id},{"chat_instance", chat_instance},{"data", data},{"game_short_name", game_short_name},};
	}
};

//Upon receiving a message with this object, Telegram clients will display a reply interface to the user (act as if the user has selected the bot&#39;s message and tapped &#39;Reply&#39;). This can be extremely useful if you want to create user-friendly step-by-step interfaces without having to sacrifice <a href="/bots/features#privacy-mode">privacy mode</a>.
struct ForceReply{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object represents a chat photo.
struct ChatPhoto{
	std::string small_file_id;
	std::string small_file_unique_id;
	std::string big_file_id;
	std::string big_file_unique_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"small_file_id", small_file_id},{"small_file_unique_id", small_file_unique_id},{"big_file_id", big_file_id},{"big_file_unique_id", big_file_unique_id},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"invite_link", invite_link},{"creator", creator},{"creates_join_request", creates_join_request},{"is_primary", is_primary},{"is_revoked", is_revoked},{"name", name},{"expire_date", expire_date},{"member_limit", member_limit},{"pending_join_request_count", pending_join_request_count},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"is_anonymous", is_anonymous},{"can_manage_chat", can_manage_chat},{"can_delete_messages", can_delete_messages},{"can_manage_video_chats", can_manage_video_chats},{"can_restrict_members", can_restrict_members},{"can_promote_members", can_promote_members},{"can_change_info", can_change_info},{"can_invite_users", can_invite_users},{"can_post_messages", can_post_messages},{"can_edit_messages", can_edit_messages},{"can_pin_messages", can_pin_messages},{"can_manage_topics", can_manage_topics},};
	}
};

//This object contains information about one member of a chat. Currently, the following 6 types of chat members are supported:
struct ChatMember{
	std::string status;
	std::shared_ptr<User> user;
	bool is_anonymous;
	std::string custom_title;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"status", status},{"user", user},{"is_anonymous", is_anonymous},{"custom_title", custom_title},};
	}
};

//Represents a <a href="#chatmember">chat member</a> that owns the chat and has all administrator privileges.
struct ChatMemberOwner{
	std::string status;
	std::shared_ptr<User> user;
	bool is_anonymous;
	std::string custom_title;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"status", status},{"user", user},{"is_anonymous", is_anonymous},{"custom_title", custom_title},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"status", status},{"user", user},{"can_be_edited", can_be_edited},{"is_anonymous", is_anonymous},{"can_manage_chat", can_manage_chat},{"can_delete_messages", can_delete_messages},{"can_manage_video_chats", can_manage_video_chats},{"can_restrict_members", can_restrict_members},{"can_promote_members", can_promote_members},{"can_change_info", can_change_info},{"can_invite_users", can_invite_users},{"can_post_messages", can_post_messages},{"can_edit_messages", can_edit_messages},{"can_pin_messages", can_pin_messages},{"can_manage_topics", can_manage_topics},{"custom_title", custom_title},};
	}
};

//Represents a <a href="#chatmember">chat member</a> that has no additional privileges or restrictions.
struct ChatMemberMember{
	std::string status;
	std::shared_ptr<User> user;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"status", status},{"user", user},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"status", status},{"user", user},{"is_member", is_member},{"can_send_messages", can_send_messages},{"can_send_audios", can_send_audios},{"can_send_documents", can_send_documents},{"can_send_photos", can_send_photos},{"can_send_videos", can_send_videos},{"can_send_video_notes", can_send_video_notes},{"can_send_voice_notes", can_send_voice_notes},{"can_send_polls", can_send_polls},{"can_send_other_messages", can_send_other_messages},{"can_add_web_page_previews", can_add_web_page_previews},{"can_change_info", can_change_info},{"can_invite_users", can_invite_users},{"can_pin_messages", can_pin_messages},{"can_manage_topics", can_manage_topics},{"until_date", until_date},};
	}
};

//Represents a <a href="#chatmember">chat member</a> that isn&#39;t currently a member of the chat, but may join it themselves.
struct ChatMemberLeft{
	std::string status;
	std::shared_ptr<User> user;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"status", status},{"user", user},};
	}
};

//Represents a <a href="#chatmember">chat member</a> that was banned in the chat and can&#39;t return to the chat or view chat messages.
struct ChatMemberBanned{
	std::string status;
	std::shared_ptr<User> user;
	int until_date;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"status", status},{"user", user},{"until_date", until_date},};
	}
};

//This object represents changes in the status of a chat member.
struct ChatMemberUpdated{
	std::shared_ptr<Chat> chat;
	std::shared_ptr<User> from;
	int date;
	std::shared_ptr<ChatMember> old_chat_member;
	std::shared_ptr<ChatMember> new_chat_member;
	std::shared_ptr<ChatInviteLink> invite_link;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"chat", chat},{"from", from},{"date", date},{"old_chat_member", old_chat_member},{"new_chat_member", new_chat_member},{"invite_link", invite_link},};
	}
};

//Represents a join request sent to a chat.
struct ChatJoinRequest{
	std::shared_ptr<Chat> chat;
	std::shared_ptr<User> from;
	int user_chat_id;
	int date;
	std::string bio;
	std::shared_ptr<ChatInviteLink> invite_link;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"chat", chat},{"from", from},{"user_chat_id", user_chat_id},{"date", date},{"bio", bio},{"invite_link", invite_link},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"can_send_messages", can_send_messages},{"can_send_audios", can_send_audios},{"can_send_documents", can_send_documents},{"can_send_photos", can_send_photos},{"can_send_videos", can_send_videos},{"can_send_video_notes", can_send_video_notes},{"can_send_voice_notes", can_send_voice_notes},{"can_send_polls", can_send_polls},{"can_send_other_messages", can_send_other_messages},{"can_add_web_page_previews", can_add_web_page_previews},{"can_change_info", can_change_info},{"can_invite_users", can_invite_users},{"can_pin_messages", can_pin_messages},{"can_manage_topics", can_manage_topics},};
	}
};

//Represents a location to which a chat is connected.
struct ChatLocation{
	std::shared_ptr<Location> location;
	std::string address;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"location", location},{"address", address},};
	}
};

//This object represents a forum topic.
struct ForumTopic{
	int message_thread_id;
	std::string name;
	int icon_color;
	std::string icon_custom_emoji_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"message_thread_id", message_thread_id},{"name", name},{"icon_color", icon_color},{"icon_custom_emoji_id", icon_custom_emoji_id},};
	}
};

//This object represents a bot command.
struct BotCommand{
	std::string command;
	std::string description;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"command", command},{"description", description},};
	}
};

//This object represents the scope to which bot commands are applied. Currently, the following 7 scopes are supported:
struct BotCommandScope{
	std::string type;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},};
	}
};

//Represents the default <a href="#botcommandscope">scope</a> of bot commands. Default commands are used if no commands with a <a href="#determining-list-of-commands">narrower scope</a> are specified for the user.
struct BotCommandScopeDefault{
	std::string type;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},};
	}
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all private chats.
struct BotCommandScopeAllPrivateChats{
	std::string type;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},};
	}
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all group and supergroup chats.
struct BotCommandScopeAllGroupChats{
	std::string type;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},};
	}
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all group and supergroup chat administrators.
struct BotCommandScopeAllChatAdministrators{
	std::string type;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},};
	}
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering a specific chat.
struct BotCommandScopeChat{
	std::string type;
	int chat_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"chat_id", chat_id},};
	}
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering all administrators of a specific group or supergroup chat.
struct BotCommandScopeChatAdministrators{
	std::string type;
	int chat_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"chat_id", chat_id},};
	}
};

//Represents the <a href="#botcommandscope">scope</a> of bot commands, covering a specific member of a group or supergroup chat.
struct BotCommandScopeChatMember{
	std::string type;
	int chat_id;
	int user_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"chat_id", chat_id},{"user_id", user_id},};
	}
};

//This object describes the bot&#39;s menu button in a private chat. It should be one of
struct MenuButton{
	std::string type;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},};
	}
};

//Represents a menu button, which opens the bot&#39;s list of commands.
struct MenuButtonCommands{
	std::string type;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},};
	}
};

//Represents a menu button, which launches a <a href="/bots/webapps">Web App</a>.
struct MenuButtonWebApp{
	std::string type;
	std::string text;
	std::shared_ptr<WebAppInfo> web_app;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"text", text},{"web_app", web_app},};
	}
};

//Describes that no specific value for the menu button was set.
struct MenuButtonDefault{
	std::string type;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},};
	}
};

//Describes why a request was unsuccessful.
struct ResponseParameters{
	int migrate_to_chat_id;
	int retry_after;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"migrate_to_chat_id", migrate_to_chat_id},{"retry_after", retry_after},};
	}
};

//This object represents the content of a media message to be sent. It should be one of
struct InputMedia{
	std::string type;
	std::string media;
	std::string caption;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	bool has_spoiler;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"media", media},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"has_spoiler", has_spoiler},};
	}
};

//Represents a photo to be sent.
struct InputMediaPhoto{
	std::string type;
	std::string media;
	std::string caption;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> caption_entities;
	bool has_spoiler;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"media", media},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"has_spoiler", has_spoiler},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"media", media},{"thumb", thumb},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"width", width},{"height", height},{"duration", duration},{"supports_streaming", supports_streaming},{"has_spoiler", has_spoiler},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"media", media},{"thumb", thumb},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"width", width},{"height", height},{"duration", duration},{"has_spoiler", has_spoiler},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"media", media},{"thumb", thumb},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"duration", duration},{"performer", performer},{"title", title},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"media", media},{"thumb", thumb},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"disable_content_type_detection", disable_content_type_detection},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"chat_id", chat_id},{"message_thread_id", message_thread_id},{"text", text},{"parse_mode", parse_mode},{"entities", entities},{"disable_web_page_preview", disable_web_page_preview},{"disable_notification", disable_notification},{"protect_content", protect_content},{"reply_to_message_id", reply_to_message_id},{"allow_sending_without_reply", allow_sending_without_reply},{"reply_markup", reply_markup},};
	}
};

//The following methods and objects allow your bot to handle stickers and sticker sets.
struct Stickers{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"file_id", file_id},{"file_unique_id", file_unique_id},{"type", type},{"width", width},{"height", height},{"is_animated", is_animated},{"is_video", is_video},{"thumb", thumb},{"emoji", emoji},{"set_name", set_name},{"premium_animation", premium_animation},{"mask_position", mask_position},{"custom_emoji_id", custom_emoji_id},{"file_size", file_size},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"name", name},{"title", title},{"sticker_type", sticker_type},{"is_animated", is_animated},{"is_video", is_video},{"stickers", stickers},{"thumb", thumb},};
	}
};

//This object describes the position on faces where a mask should be placed by default.
struct MaskPosition{
	std::string point;
	float x_shift;
	float y_shift;
	float scale;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"point", point},{"x_shift", x_shift},{"y_shift", y_shift},{"scale", scale},};
	}
};

//This object represents an incoming inline query. When the user sends an empty query, your bot could return some default or trending results.
struct InlineQuery{
	std::string id;
	std::shared_ptr<User> from;
	std::string query;
	std::string offset;
	std::string chat_type;
	std::shared_ptr<Location> location;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"id", id},{"from", from},{"query", query},{"offset", offset},{"chat_type", chat_type},{"location", location},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"title", title},{"input_message_content", input_message_content},{"reply_markup", reply_markup},{"url", url},{"hide_url", hide_url},{"description", description},{"thumb_url", thumb_url},{"thumb_width", thumb_width},{"thumb_height", thumb_height},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"title", title},{"input_message_content", input_message_content},{"reply_markup", reply_markup},{"url", url},{"hide_url", hide_url},{"description", description},{"thumb_url", thumb_url},{"thumb_width", thumb_width},{"thumb_height", thumb_height},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"photo_url", photo_url},{"thumb_url", thumb_url},{"photo_width", photo_width},{"photo_height", photo_height},{"title", title},{"description", description},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"gif_url", gif_url},{"gif_width", gif_width},{"gif_height", gif_height},{"gif_duration", gif_duration},{"thumb_url", thumb_url},{"thumb_mime_type", thumb_mime_type},{"title", title},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"mpeg4_url", mpeg4_url},{"mpeg4_width", mpeg4_width},{"mpeg4_height", mpeg4_height},{"mpeg4_duration", mpeg4_duration},{"thumb_url", thumb_url},{"thumb_mime_type", thumb_mime_type},{"title", title},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"video_url", video_url},{"mime_type", mime_type},{"thumb_url", thumb_url},{"title", title},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"video_width", video_width},{"video_height", video_height},{"video_duration", video_duration},{"description", description},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"audio_url", audio_url},{"title", title},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"performer", performer},{"audio_duration", audio_duration},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"voice_url", voice_url},{"title", title},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"voice_duration", voice_duration},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"title", title},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"document_url", document_url},{"mime_type", mime_type},{"description", description},{"reply_markup", reply_markup},{"input_message_content", input_message_content},{"thumb_url", thumb_url},{"thumb_width", thumb_width},{"thumb_height", thumb_height},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"latitude", latitude},{"longitude", longitude},{"title", title},{"horizontal_accuracy", horizontal_accuracy},{"live_period", live_period},{"heading", heading},{"proximity_alert_radius", proximity_alert_radius},{"reply_markup", reply_markup},{"input_message_content", input_message_content},{"thumb_url", thumb_url},{"thumb_width", thumb_width},{"thumb_height", thumb_height},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"latitude", latitude},{"longitude", longitude},{"title", title},{"address", address},{"foursquare_id", foursquare_id},{"foursquare_type", foursquare_type},{"google_place_id", google_place_id},{"google_place_type", google_place_type},{"reply_markup", reply_markup},{"input_message_content", input_message_content},{"thumb_url", thumb_url},{"thumb_width", thumb_width},{"thumb_height", thumb_height},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"phone_number", phone_number},{"first_name", first_name},{"last_name", last_name},{"vcard", vcard},{"reply_markup", reply_markup},{"input_message_content", input_message_content},{"thumb_url", thumb_url},{"thumb_width", thumb_width},{"thumb_height", thumb_height},};
	}
};

//Represents a <a href="#games">Game</a>.
struct InlineQueryResultGame{
	std::string type;
	std::string id;
	std::string game_short_name;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"game_short_name", game_short_name},{"reply_markup", reply_markup},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"photo_file_id", photo_file_id},{"title", title},{"description", description},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"gif_file_id", gif_file_id},{"title", title},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"mpeg4_file_id", mpeg4_file_id},{"title", title},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
};

//Represents a link to a sticker stored on the Telegram servers. By default, this sticker will be sent by the user. Alternatively, you can use <em>input_message_content</em> to send a message with the specified content instead of the sticker.
struct InlineQueryResultCachedSticker{
	std::string type;
	std::string id;
	std::string sticker_file_id;
	std::shared_ptr<InlineKeyboardMarkup> reply_markup;
	std::shared_ptr<InputMessageContent> input_message_content;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"sticker_file_id", sticker_file_id},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"title", title},{"document_file_id", document_file_id},{"description", description},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"video_file_id", video_file_id},{"title", title},{"description", description},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"voice_file_id", voice_file_id},{"title", title},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"id", id},{"audio_file_id", audio_file_id},{"caption", caption},{"parse_mode", parse_mode},{"caption_entities", caption_entities},{"reply_markup", reply_markup},{"input_message_content", input_message_content},};
	}
};

//This object represents the content of a message to be sent as a result of an inline query. Telegram clients currently support the following 5 types:
struct InputMessageContent{
	std::string message_text;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> entities;
	bool disable_web_page_preview;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"message_text", message_text},{"parse_mode", parse_mode},{"entities", entities},{"disable_web_page_preview", disable_web_page_preview},};
	}
};

//Represents the <a href="#inputmessagecontent">content</a> of a text message to be sent as the result of an inline query.
struct InputTextMessageContent{
	std::string message_text;
	std::string parse_mode;
	std::vector<std::shared_ptr<MessageEntity>> entities;
	bool disable_web_page_preview;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"message_text", message_text},{"parse_mode", parse_mode},{"entities", entities},{"disable_web_page_preview", disable_web_page_preview},};
	}
};

//Represents the <a href="#inputmessagecontent">content</a> of a location message to be sent as the result of an inline query.
struct InputLocationMessageContent{
	float latitude;
	float longitude;
	float horizontal_accuracy;
	int live_period;
	int heading;
	int proximity_alert_radius;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"latitude", latitude},{"longitude", longitude},{"horizontal_accuracy", horizontal_accuracy},{"live_period", live_period},{"heading", heading},{"proximity_alert_radius", proximity_alert_radius},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"latitude", latitude},{"longitude", longitude},{"title", title},{"address", address},{"foursquare_id", foursquare_id},{"foursquare_type", foursquare_type},{"google_place_id", google_place_id},{"google_place_type", google_place_type},};
	}
};

//Represents the <a href="#inputmessagecontent">content</a> of a contact message to be sent as the result of an inline query.
struct InputContactMessageContent{
	std::string phone_number;
	std::string first_name;
	std::string last_name;
	std::string vcard;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"phone_number", phone_number},{"first_name", first_name},{"last_name", last_name},{"vcard", vcard},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"title", title},{"description", description},{"payload", payload},{"provider_token", provider_token},{"currency", currency},{"prices", prices},{"max_tip_amount", max_tip_amount},{"suggested_tip_amounts", suggested_tip_amounts},{"provider_data", provider_data},{"photo_url", photo_url},{"photo_size", photo_size},{"photo_width", photo_width},{"photo_height", photo_height},{"need_name", need_name},{"need_phone_number", need_phone_number},{"need_email", need_email},{"need_shipping_address", need_shipping_address},{"send_phone_number_to_provider", send_phone_number_to_provider},{"send_email_to_provider", send_email_to_provider},{"is_flexible", is_flexible},};
	}
};

//Represents a <a href="#inlinequeryresult">result</a> of an inline query that was chosen by the user and sent to their chat partner.
struct ChosenInlineResult{
	std::string result_id;
	std::shared_ptr<User> from;
	std::shared_ptr<Location> location;
	std::string inline_message_id;
	std::string query;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"result_id", result_id},{"from", from},{"location", location},{"inline_message_id", inline_message_id},{"query", query},};
	}
};

//Describes an inline message sent by a <a href="/bots/webapps">Web App</a> on behalf of a user.
struct SentWebAppMessage{
	std::string inline_message_id;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"inline_message_id", inline_message_id},};
	}
};

//Your bot can accept payments from Telegram users. Please see the <a href="/bots/payments">introduction to payments</a> for more details on the process and how to set up payments for your bot. Please note that users will need Telegram v.4.0 or higher to use payments (released on May 18, 2017).
struct Payments{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object represents a portion of the price for goods or services.
struct LabeledPrice{
	std::string label;
	int amount;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"label", label},{"amount", amount},};
	}
};

//This object contains basic information about an invoice.
struct Invoice{
	std::string title;
	std::string description;
	std::string start_parameter;
	std::string currency;
	int total_amount;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"title", title},{"description", description},{"start_parameter", start_parameter},{"currency", currency},{"total_amount", total_amount},};
	}
};

//This object represents a shipping address.
struct ShippingAddress{
	std::string country_code;
	std::string state;
	std::string city;
	std::string street_line1;
	std::string street_line2;
	std::string post_code;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"country_code", country_code},{"state", state},{"city", city},{"street_line1", street_line1},{"street_line2", street_line2},{"post_code", post_code},};
	}
};

//This object represents information about an order.
struct OrderInfo{
	std::string name;
	std::string phone_number;
	std::string email;
	std::shared_ptr<ShippingAddress> shipping_address;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"name", name},{"phone_number", phone_number},{"email", email},{"shipping_address", shipping_address},};
	}
};

//This object represents one shipping option.
struct ShippingOption{
	std::string id;
	std::string title;
	std::vector<std::shared_ptr<LabeledPrice>> prices;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"id", id},{"title", title},{"prices", prices},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"currency", currency},{"total_amount", total_amount},{"invoice_payload", invoice_payload},{"shipping_option_id", shipping_option_id},{"order_info", order_info},{"telegram_payment_charge_id", telegram_payment_charge_id},{"provider_payment_charge_id", provider_payment_charge_id},};
	}
};

//This object contains information about an incoming shipping query.
struct ShippingQuery{
	std::string id;
	std::shared_ptr<User> from;
	std::string invoice_payload;
	std::shared_ptr<ShippingAddress> shipping_address;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"id", id},{"from", from},{"invoice_payload", invoice_payload},{"shipping_address", shipping_address},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"id", id},{"from", from},{"currency", currency},{"total_amount", total_amount},{"invoice_payload", invoice_payload},{"shipping_option_id", shipping_option_id},{"order_info", order_info},};
	}
};

//Describes Telegram Passport data shared with the bot by the user.
struct PassportData{
	std::vector<std::shared_ptr<EncryptedPassportElement>> data;
	std::shared_ptr<EncryptedCredentials> credentials;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"data", data},{"credentials", credentials},};
	}
};

//This object represents a file uploaded to Telegram Passport. Currently all Telegram Passport files are in JPEG format when decrypted and don&#39;t exceed 10MB.
struct PassportFile{
	std::string file_id;
	std::string file_unique_id;
	int file_size;
	int file_date;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"file_id", file_id},{"file_unique_id", file_unique_id},{"file_size", file_size},{"file_date", file_date},};
	}
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
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"type", type},{"data", data},{"phone_number", phone_number},{"email", email},{"files", files},{"front_side", front_side},{"reverse_side", reverse_side},{"selfie", selfie},{"translation", translation},{"hash", hash},};
	}
};

//Describes data required for decrypting and authenticating <a href="#encryptedpassportelement">EncryptedPassportElement</a>. See the <a href="/passport#receiving-information">Telegram Passport Documentation</a> for a complete description of the data decryption and authentication processes.
struct EncryptedCredentials{
	std::string data;
	std::string hash;
	std::string secret;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"data", data},{"hash", hash},{"secret", secret},};
	}
};

//This object represents an error in the Telegram Passport element which was submitted that should be resolved by the user. It should be one of:
struct PassportElementError{
	std::string source;
	std::string type;
	std::string field_name;
	std::string data_hash;
	std::string message;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"source", source},{"type", type},{"field_name", field_name},{"data_hash", data_hash},{"message", message},};
	}
};

//Represents an issue in one of the data fields that was provided by the user. The error is considered resolved when the field&#39;s value changes.
struct PassportElementErrorDataField{
	std::string source;
	std::string type;
	std::string field_name;
	std::string data_hash;
	std::string message;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"source", source},{"type", type},{"field_name", field_name},{"data_hash", data_hash},{"message", message},};
	}
};

//Represents an issue with the front side of a document. The error is considered resolved when the file with the front side of the document changes.
struct PassportElementErrorFrontSide{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"source", source},{"type", type},{"file_hash", file_hash},{"message", message},};
	}
};

//Represents an issue with the reverse side of a document. The error is considered resolved when the file with reverse side of the document changes.
struct PassportElementErrorReverseSide{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"source", source},{"type", type},{"file_hash", file_hash},{"message", message},};
	}
};

//Represents an issue with the selfie with a document. The error is considered resolved when the file with the selfie changes.
struct PassportElementErrorSelfie{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"source", source},{"type", type},{"file_hash", file_hash},{"message", message},};
	}
};

//Represents an issue with a document scan. The error is considered resolved when the file with the document scan changes.
struct PassportElementErrorFile{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"source", source},{"type", type},{"file_hash", file_hash},{"message", message},};
	}
};

//Represents an issue with a list of scans. The error is considered resolved when the list of files containing the scans changes.
struct PassportElementErrorFiles{
	std::string source;
	std::string type;
	std::string file_hashes;
	std::string message;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"source", source},{"type", type},{"file_hashes", file_hashes},{"message", message},};
	}
};

//Represents an issue with one of the files that constitute the translation of a document. The error is considered resolved when the file changes.
struct PassportElementErrorTranslationFile{
	std::string source;
	std::string type;
	std::string file_hash;
	std::string message;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"source", source},{"type", type},{"file_hash", file_hash},{"message", message},};
	}
};

//Represents an issue with the translated version of a document. The error is considered resolved when a file with the document translation change.
struct PassportElementErrorTranslationFiles{
	std::string source;
	std::string type;
	std::string file_hashes;
	std::string message;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"source", source},{"type", type},{"file_hashes", file_hashes},{"message", message},};
	}
};

//Represents an issue in an unspecified place. The error is considered resolved when new data is added.
struct PassportElementErrorUnspecified{
	std::string source;
	std::string type;
	std::string element_hash;
	std::string message;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"source", source},{"type", type},{"element_hash", element_hash},{"message", message},};
	}
};

//Your bot can offer users <strong>HTML5 games</strong> to play solo or to compete against each other in groups and one-on-one chats. Create games via <a href="https://t.me/botfather">@BotFather</a> using the <em>/newgame</em> command. Please note that this kind of power requires responsibility: you will need to accept the terms for each game that your bots will be offering.
struct Games{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object represents a game. Use BotFather to create and edit games, their short names will act as unique identifiers.
struct Game{
	std::string title;
	std::string description;
	std::vector<std::shared_ptr<PhotoSize>> photo;
	std::string text;
	std::vector<std::shared_ptr<MessageEntity>> text_entities;
	std::shared_ptr<Animation> animation;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"title", title},{"description", description},{"photo", photo},{"text", text},{"text_entities", text_entities},{"animation", animation},};
	}
};

//A placeholder, currently holds no information. Use <a href="https://t.me/botfather">BotFather</a> to set up your game.
struct CallbackGame{
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{};
	}
};

//This object represents one row of the high scores table for a game.
struct GameHighScore{
	int position;
	std::shared_ptr<User> user;
	int score;
// Define a to_json method for the Person struct
	void to_json(json& j) const {
		j = json{{"position", position},{"user", user},{"score", score},};
	}
};

