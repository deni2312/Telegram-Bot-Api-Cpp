#include <string>
struct User{
    std::string id;
    std::string is_bot;
    std::string first_name;
    std::string last_name;
    std::string username;
    std::string language_code;
    std::string is_premium;
    std::string added_to_attachment_menu;
    std::string can_join_groups;
    std::string can_read_all_group_messages;
    std::string supports_inline_queries;
};
struct Chat{
    std::string id;
    std::string type;
    std::string title;
    std::string username;
    std::string first_name;
    std::string last_name;
    std::string is_forum;
    std::string photo;
    std::string active_usernames;
    std::string emoji_status_custom_emoji_id;
    std::string bio;
    std::string has_private_forwards;
    std::string has_restricted_voice_and_video_messages;
    std::string join_to_send_messages;
    std::string join_by_request;
    std::string description;
    std::string invite_link;
    std::string pinned_message;
    std::string permissions;
    std::string slow_mode_delay;
    std::string message_auto_delete_time;
    std::string has_aggressive_anti_spam_enabled;
    std::string has_hidden_members;
    std::string has_protected_content;
    std::string sticker_set_name;
    std::string can_set_sticker_set;
    std::string linked_chat_id;
    std::string location;
};
struct Message{
    std::string message_id;
    std::string message_thread_id;
    std::string from;
    std::string sender_chat;
    std::string date;
    std::string chat;
    std::string forward_from;
    std::string forward_from_chat;
    std::string forward_from_message_id;
    std::string forward_signature;
    std::string forward_sender_name;
    std::string forward_date;
    std::string is_topic_message;
    std::string is_automatic_forward;
    std::string reply_to_message;
    std::string via_bot;
    std::string edit_date;
    std::string has_protected_content;
    std::string media_group_id;
    std::string author_signature;
    std::string text;
    std::string entities;
    std::string animation;
    std::string audio;
    std::string document;
    std::string photo;
    std::string sticker;
    std::string video;
    std::string video_note;
    std::string voice;
    std::string caption;
    std::string caption_entities;
    std::string has_media_spoiler;
    std::string contact;
    std::string dice;
    std::string game;
    std::string poll;
    std::string venue;
    std::string location;
    std::string new_chat_members;
    std::string left_chat_member;
    std::string new_chat_title;
    std::string new_chat_photo;
    std::string delete_chat_photo;
    std::string group_chat_created;
    std::string supergroup_chat_created;
    std::string channel_chat_created;
    std::string message_auto_delete_timer_changed;
    std::string migrate_to_chat_id;
    std::string migrate_from_chat_id;
    std::string pinned_message;
    std::string invoice;
    std::string successful_payment;
    std::string user_shared;
    std::string chat_shared;
    std::string connected_website;
    std::string write_access_allowed;
    std::string passport_data;
    std::string proximity_alert_triggered;
    std::string forum_topic_created;
    std::string forum_topic_edited;
    std::string forum_topic_closed;
    std::string forum_topic_reopened;
    std::string general_forum_topic_hidden;
    std::string general_forum_topic_unhidden;
    std::string video_chat_scheduled;
    std::string video_chat_started;
    std::string video_chat_ended;
    std::string video_chat_participants_invited;
    std::string web_app_data;
    std::string reply_markup;
};
struct MessageId{
    std::string message_id;
};
struct MessageEntity{
    std::string type;
    std::string offset;
    std::string length;
    std::string url;
    std::string user;
    std::string language;
    std::string custom_emoji_id;
};
struct PhotoSize{
    std::string file_id;
    std::string file_unique_id;
    std::string width;
    std::string height;
    std::string file_size;
};
struct Animation{
    std::string file_id;
    std::string file_unique_id;
    std::string width;
    std::string height;
    std::string duration;
    std::string thumb;
    std::string file_name;
    std::string mime_type;
    std::string file_size;
};
struct Audio{
    std::string file_id;
    std::string file_unique_id;
    std::string duration;
    std::string performer;
    std::string title;
    std::string file_name;
    std::string mime_type;
    std::string file_size;
    std::string thumb;
};
struct Document{
    std::string file_id;
    std::string file_unique_id;
    std::string thumb;
    std::string file_name;
    std::string mime_type;
    std::string file_size;
};
struct Video{
    std::string file_id;
    std::string file_unique_id;
    std::string width;
    std::string height;
    std::string duration;
    std::string thumb;
    std::string file_name;
    std::string mime_type;
    std::string file_size;
};
struct VideoNote{
    std::string file_id;
    std::string file_unique_id;
    std::string length;
    std::string duration;
    std::string thumb;
    std::string file_size;
};
struct Voice{
    std::string file_id;
    std::string file_unique_id;
    std::string duration;
    std::string mime_type;
    std::string file_size;
};
struct Contact{
    std::string phone_number;
    std::string first_name;
    std::string last_name;
    std::string user_id;
    std::string vcard;
};
struct Dice{
    std::string emoji;
    std::string value;
};
struct PollOption{
    std::string text;
    std::string voter_count;
};
struct PollAnswer{
    std::string poll_id;
    std::string user;
    std::string option_ids;
};
struct Poll{
    std::string id;
    std::string question;
    std::string options;
    std::string total_voter_count;
    std::string is_closed;
    std::string is_anonymous;
    std::string type;
    std::string allows_multiple_answers;
    std::string correct_option_id;
    std::string explanation;
    std::string explanation_entities;
    std::string open_period;
    std::string close_date;
};
struct Location{
    std::string longitude;
    std::string latitude;
    std::string horizontal_accuracy;
    std::string live_period;
    std::string heading;
    std::string proximity_alert_radius;
};
struct Venue{
    std::string location;
    std::string title;
    std::string address;
    std::string foursquare_id;
    std::string foursquare_type;
    std::string google_place_id;
    std::string google_place_type;
};
struct WebAppData{
    std::string data;
    std::string button_text;
};
struct ProximityAlertTriggered{
    std::string traveler;
    std::string watcher;
    std::string distance;
};
struct MessageAutoDeleteTimerChanged{
    std::string message_auto_delete_time;
};
struct ForumTopicCreated{
    std::string name;
    std::string icon_color;
    std::string icon_custom_emoji_id;
};
struct ForumTopicClosed{
    std::string name;
    std::string icon_custom_emoji_id;
};
struct ForumTopicEdited{
    std::string request_id;
    std::string user_id;
};
struct ForumTopicReopened{
    std::string request_id;
    std::string chat_id;
};
struct GeneralForumTopicHidden{
    std::string start_date;
};
struct GeneralForumTopicUnhidden{
    std::string duration;
};
struct UserShared{
    std::string users;
};
struct ChatShared{
    std::string total_count;
    std::string photos;
};
struct WriteAccessAllowed{
    std::string file_id;
    std::string file_unique_id;
    std::string file_size;
    std::string file_path;
};
struct VideoChatScheduled{
    std::string url;
};
struct VideoChatStarted{
    std::string keyboard;
    std::string is_persistent;
    std::string resize_keyboard;
    std::string one_time_keyboard;
    std::string input_field_placeholder;
    std::string selective;
};
struct VideoChatEnded{
    std::string text;
    std::string request_user;
    std::string request_chat;
    std::string request_contact;
    std::string request_location;
    std::string request_poll;
    std::string web_app;
};
struct VideoChatParticipantsInvited{
    std::string request_id;
    std::string user_is_bot;
    std::string user_is_premium;
};
struct UserProfilePhotos{
    std::string request_id;
    std::string chat_is_channel;
    std::string chat_is_forum;
    std::string chat_has_username;
    std::string chat_is_created;
    std::string user_administrator_rights;
    std::string bot_administrator_rights;
    std::string bot_is_member;
};
struct File{
    std::string type;
};
struct WebAppInfo{
    std::string remove_keyboard;
    std::string selective;
};
struct ReplyKeyboardMarkup{
    std::string inline_keyboard;
};
struct KeyboardButton{
    std::string text;
    std::string url;
    std::string callback_data;
    std::string web_app;
    std::string login_url;
    std::string switch_inline_query;
    std::string switch_inline_query_current_chat;
    std::string callback_game;
    std::string pay;
};
struct KeyboardButtonRequestUser{
    std::string url;
    std::string forward_text;
    std::string bot_username;
    std::string request_write_access;
};
struct KeyboardButtonRequestChat{
    std::string id;
    std::string from;
    std::string message;
    std::string inline_message_id;
    std::string chat_instance;
    std::string data;
    std::string game_short_name;
};
struct KeyboardButtonPollType{
    std::string force_reply;
    std::string input_field_placeholder;
    std::string selective;
};
struct ReplyKeyboardRemove{
    std::string small_file_id;
    std::string small_file_unique_id;
    std::string big_file_id;
    std::string big_file_unique_id;
};
struct InlineKeyboardMarkup{
    std::string invite_link;
    std::string creator;
    std::string creates_join_request;
    std::string is_primary;
    std::string is_revoked;
    std::string name;
    std::string expire_date;
    std::string member_limit;
    std::string pending_join_request_count;
};
struct InlineKeyboardButton{
    std::string is_anonymous;
    std::string can_manage_chat;
    std::string can_delete_messages;
    std::string can_manage_video_chats;
    std::string can_restrict_members;
    std::string can_promote_members;
    std::string can_change_info;
    std::string can_invite_users;
    std::string can_post_messages;
    std::string can_edit_messages;
    std::string can_pin_messages;
    std::string can_manage_topics;
};
struct LoginUrl{
    std::string status;
    std::string user;
    std::string is_anonymous;
    std::string custom_title;
};
struct CallbackQuery{
    std::string status;
    std::string user;
    std::string can_be_edited;
    std::string is_anonymous;
    std::string can_manage_chat;
    std::string can_delete_messages;
    std::string can_manage_video_chats;
    std::string can_restrict_members;
    std::string can_promote_members;
    std::string can_change_info;
    std::string can_invite_users;
    std::string can_post_messages;
    std::string can_edit_messages;
    std::string can_pin_messages;
    std::string can_manage_topics;
    std::string custom_title;
};
struct ForceReply{
    std::string status;
    std::string user;
};
struct ChatPhoto{
    std::string status;
    std::string user;
    std::string is_member;
    std::string can_send_messages;
    std::string can_send_audios;
    std::string can_send_documents;
    std::string can_send_photos;
    std::string can_send_videos;
    std::string can_send_video_notes;
    std::string can_send_voice_notes;
    std::string can_send_polls;
    std::string can_send_other_messages;
    std::string can_add_web_page_previews;
    std::string can_change_info;
    std::string can_invite_users;
    std::string can_pin_messages;
    std::string can_manage_topics;
    std::string until_date;
};
struct ChatInviteLink{
    std::string status;
    std::string user;
};
struct ChatAdministratorRights{
    std::string status;
    std::string user;
    std::string until_date;
};
struct ChatMember{
    std::string chat;
    std::string from;
    std::string date;
    std::string old_chat_member;
    std::string new_chat_member;
    std::string invite_link;
};
struct ChatMemberOwner{
    std::string chat;
    std::string from;
    std::string user_chat_id;
    std::string date;
    std::string bio;
    std::string invite_link;
};
struct ChatMemberAdministrator{
    std::string can_send_messages;
    std::string can_send_audios;
    std::string can_send_documents;
    std::string can_send_photos;
    std::string can_send_videos;
    std::string can_send_video_notes;
    std::string can_send_voice_notes;
    std::string can_send_polls;
    std::string can_send_other_messages;
    std::string can_add_web_page_previews;
    std::string can_change_info;
    std::string can_invite_users;
    std::string can_pin_messages;
    std::string can_manage_topics;
};
struct ChatMemberMember{
    std::string location;
    std::string address;
};
struct ChatMemberRestricted{
    std::string message_thread_id;
    std::string name;
    std::string icon_color;
    std::string icon_custom_emoji_id;
};
struct ChatMemberLeft{
    std::string command;
    std::string description;
};
struct ChatMemberBanned{
    std::string type;
};
struct ChatMemberUpdated{
    std::string type;
};
struct ChatJoinRequest{
    std::string type;
};
struct ChatPermissions{
    std::string type;
};
struct ChatLocation{
    std::string type;
    std::string chat_id;
};
struct ForumTopic{
    std::string type;
    std::string chat_id;
};
struct BotCommand{
    std::string type;
    std::string chat_id;
    std::string user_id;
};
struct BotCommandScope{
    std::string type;
};
struct Determining list of commands{
        std::string type;
        std::string text;
        std::string web_app;
};
struct BotCommandScopeDefault{
    std::string type;
};
struct BotCommandScopeAllPrivateChats{
    std::string migrate_to_chat_id;
    std::string retry_after;
};
struct BotCommandScopeAllGroupChats{
    std::string type;
    std::string media;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string has_spoiler;
};
struct BotCommandScopeAllChatAdministrators{
    std::string type;
    std::string media;
    std::string thumb;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string width;
    std::string height;
    std::string duration;
    std::string supports_streaming;
    std::string has_spoiler;
};
struct BotCommandScopeChat{
    std::string type;
    std::string media;
    std::string thumb;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string width;
    std::string height;
    std::string duration;
    std::string has_spoiler;
};
struct BotCommandScopeChatAdministrators{
    std::string type;
    std::string media;
    std::string thumb;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string duration;
    std::string performer;
    std::string title;
};
struct BotCommandScopeChatMember{
    std::string type;
    std::string media;
    std::string thumb;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string disable_content_type_detection;
};
struct MenuButton{
    std::string chat_id;
    std::string message_thread_id;
    std::string text;
    std::string parse_mode;
    std::string entities;
    std::string disable_web_page_preview;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
    std::string reply_markup;
};
struct MenuButtonCommands{
    std::string chat_id;
    std::string message_thread_id;
    std::string from_chat_id;
    std::string disable_notification;
    std::string protect_content;
    std::string message_id;
};
struct MenuButtonWebApp{
    std::string chat_id;
    std::string message_thread_id;
    std::string from_chat_id;
    std::string message_id;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
    std::string reply_markup;
};
struct MenuButtonDefault{
    std::string chat_id;
    std::string message_thread_id;
    std::string photo;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string has_spoiler;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
    std::string reply_markup;
};
struct ResponseParameters{
    std::string chat_id;
    std::string message_thread_id;
    std::string audio;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string duration;
    std::string performer;
    std::string title;
    std::string thumb;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
    std::string reply_markup;
};
struct InputMedia{
    std::string chat_id;
    std::string message_thread_id;
    std::string document;
    std::string thumb;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string disable_content_type_detection;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
    std::string reply_markup;
};
struct InputMediaPhoto{
    std::string chat_id;
    std::string message_thread_id;
    std::string video;
    std::string duration;
    std::string width;
    std::string height;
    std::string thumb;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string has_spoiler;
    std::string supports_streaming;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
    std::string reply_markup;
};
struct InputMediaVideo{
    std::string chat_id;
    std::string message_thread_id;
    std::string animation;
    std::string duration;
    std::string width;
    std::string height;
    std::string thumb;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string has_spoiler;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
    std::string reply_markup;
};
struct InputMediaAnimation{
    std::string chat_id;
    std::string message_thread_id;
    std::string voice;
    std::string caption;
    std::string parse_mode;
    std::string caption_entities;
    std::string duration;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
    std::string reply_markup;
};
struct InputMediaAudio{
    std::string chat_id;
    std::string message_thread_id;
    std::string video_note;
    std::string duration;
    std::string length;
    std::string thumb;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
    std::string reply_markup;
};
struct InputMediaDocument{
    std::string chat_id;
    std::string message_thread_id;
    std::string media;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
};
struct InputFile{
    std::string chat_id;
    std::string message_thread_id;
    std::string latitude;
    std::string longitude;
    std::string horizontal_accuracy;
    std::string live_period;
    std::string heading;
    std::string proximity_alert_radius;
    std::string disable_notification;
    std::string protect_content;
    std::string reply_to_message_id;
    std::string allow_sending_without_reply;
    std::string reply_markup;
};
