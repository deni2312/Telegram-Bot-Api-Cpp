#pragma once

#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
#include "../../types_generator.h"
#include "network/HTTPrequest.h"
#include <cpr/cpr.h>
namespace Telegram{
	namespace Bot{
		namespace Types {
#ifndef _WIN32
            using __int64 = int64_t;
#endif
            using json = nlohmann::json;

            class API {
            public:

                API(std::string link, std::shared_ptr<Network> &request) : generalToken(link),
                                                                                  request{request} {};

                // Use this method to log out from the cloud Bot API server before launching the bot locally. You <strong>must</strong> log out the bot before running it locally, otherwise there is no guarantee that the bot will receive updates. After a successful call, you can immediately log in on a local server, but will not be able to log in back to the cloud Bot API server for 10 minutes. Returns <em>True</em> on success. Requires no parameters.
                void logOut(int chat_id, std::string text, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                            bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                            bool disable_notification, bool disable_web_page_preview,
                            std::vector<std::shared_ptr<MessageEntity>> entities, std::string parse_mode,
                            int message_thread_id);

// Use this method to close the bot instance before moving it from one local server to another. You need to delete the webhook before calling this method to ensure that the bot isn&#39;t launched again after server restart. The method will return error 429 in the first 10 minutes after the bot is launched. Returns <em>True</em> on success. Requires no parameters.
                void close(int chat_id, std::string text, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                           bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                           bool disable_notification, bool disable_web_page_preview,
                           std::vector<std::shared_ptr<MessageEntity>> entities, std::string parse_mode,
                           int message_thread_id);

// Use this method to send text messages. On success, the sent <a href="#message">Message</a> is returned.
                inline void sendMessage(int chat_id, std::string text) const{
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["text"] = text;
                    auto result1=payload1.dump();
                    auto response = cpr::Post(cpr::Url{generalToken+"/sendMessage"},
                                              cpr::Body{result1},
                                              cpr::Header{{"Content-Type", "application/json"}});}

// Use this method to forward messages of any kind. Service messages can&#39;t be forwarded. On success, the sent <a href="#message">Message</a> is returned.
                void forwardMessage(int chat_id, int from_chat_id, int message_id, bool protect_content,
                                    bool disable_notification, int message_thread_id);

// Use this method to copy messages of any kind. Service messages and invoice messages can&#39;t be copied. A quiz <a href="#poll">poll</a> can be copied only if the value of the field <em>correct_option_id</em> is known to the bot. The method is analogous to the method <a href="#forwardmessage">forwardMessage</a>, but the copied message doesn&#39;t have a link to the original message. Returns the <a href="#messageid">MessageId</a> of the sent message on success.
                void copyMessage(int chat_id, int from_chat_id, int message_id,
                                 std::shared_ptr<InlineKeyboardMarkup> reply_markup, bool allow_sending_without_reply,
                                 int reply_to_message_id, bool protect_content, bool disable_notification,
                                 std::vector<std::shared_ptr<MessageEntity>> caption_entities, std::string parse_mode,
                                 std::string caption, int message_thread_id);

// Use this method to send photos. On success, the sent <a href="#message">Message</a> is returned.
                void sendPhoto(int chat_id, std::string photo, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                               bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                               bool disable_notification, bool has_spoiler,
                               std::vector<std::shared_ptr<MessageEntity>> caption_entities, std::string parse_mode,
                               std::string caption, int message_thread_id);

// Use this method to send audio files, if you want Telegram clients to display them in the music player. Your audio must be in the .MP3 or .M4A format. On success, the sent <a href="#message">Message</a> is returned. Bots can currently send audio files of up to 50 MB in size, this limit may be changed in the future.
                void sendAudio(int chat_id, std::string audio, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                               bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                               bool disable_notification, std::string thumb, std::string title, std::string performer,
                               int duration, std::vector<std::shared_ptr<MessageEntity>> caption_entities,
                               std::string parse_mode, std::string caption, int message_thread_id);

// Use this method to send general files. On success, the sent <a href="#message">Message</a> is returned. Bots can currently send files of any type of up to 50 MB in size, this limit may be changed in the future.
                void sendDocument(int chat_id, std::string document, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                                  bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                                  bool disable_notification, bool disable_content_type_detection,
                                  std::vector<std::shared_ptr<MessageEntity>> caption_entities, std::string parse_mode,
                                  std::string caption, std::string thumb, int message_thread_id);

// Use this method to send video files, Telegram clients support MPEG4 videos (other formats may be sent as <a href="#document">Document</a>). On success, the sent <a href="#message">Message</a> is returned. Bots can currently send video files of up to 50 MB in size, this limit may be changed in the future.
                void sendVideo(int chat_id, std::string video, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                               bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                               bool disable_notification, bool supports_streaming, bool has_spoiler,
                               std::vector<std::shared_ptr<MessageEntity>> caption_entities, std::string parse_mode,
                               std::string caption, std::string thumb, int height, int width, int duration,
                               int message_thread_id);

// Use this method to send animation files (GIF or H.264/MPEG-4 AVC video without sound). On success, the sent <a href="#message">Message</a> is returned. Bots can currently send animation files of up to 50 MB in size, this limit may be changed in the future.
                void
                sendAnimation(int chat_id, std::string animation, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                              bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                              bool disable_notification, bool has_spoiler,
                              std::vector<std::shared_ptr<MessageEntity>> caption_entities, std::string parse_mode,
                              std::string caption, std::string thumb, int height, int width, int duration,
                              int message_thread_id);

// Use this method to send audio files, if you want Telegram clients to display the file as a playable voice message. For this to work, your audio must be in an .OGG file encoded with OPUS (other formats may be sent as <a href="#audio">Audio</a> or <a href="#document">Document</a>). On success, the sent <a href="#message">Message</a> is returned. Bots can currently send voice messages of up to 50 MB in size, this limit may be changed in the future.
                void sendVoice(int chat_id, std::string voice, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                               bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                               bool disable_notification, int duration,
                               std::vector<std::shared_ptr<MessageEntity>> caption_entities, std::string parse_mode,
                               std::string caption, int message_thread_id);

// As of <a href="https://telegram.org/blog/video-messages-and-telescope">v.4.0</a>, Telegram clients support rounded square MPEG4 videos of up to 1 minute long. Use this method to send video messages. On success, the sent <a href="#message">Message</a> is returned.
                void
                sendVideoNote(int chat_id, std::string video_note, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                              bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                              bool disable_notification, std::string thumb, int length, int duration,
                              int message_thread_id);

// Use this method to send a group of photos, videos, documents or audios as an album. Documents and audio files can be only grouped in an album with messages of the same type. On success, an array of <a href="#message">Messages</a> that were sent is returned.
                void sendMediaGroup(int chat_id, std::vector<std::shared_ptr<InputMediaAudio>> media,
                                    bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                                    bool disable_notification, int message_thread_id);

// Use this method to send point on the map. On success, the sent <a href="#message">Message</a> is returned.
                void sendLocation(int chat_id, float latitude, float longitude,
                                  std::shared_ptr<InlineKeyboardMarkup> reply_markup, bool allow_sending_without_reply,
                                  int reply_to_message_id, bool protect_content, bool disable_notification,
                                  int proximity_alert_radius, int heading, int live_period, float horizontal_accuracy,
                                  int message_thread_id);

// Use this method to edit live location messages. A location can be edited until its <em>live_period</em> expires or editing is explicitly disabled by a call to <a href="#stopmessagelivelocation">stopMessageLiveLocation</a>. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                void editMessageLiveLocation(float latitude, float longitude,
                                             std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                                             int proximity_alert_radius, int heading, float horizontal_accuracy,
                                             std::string inline_message_id, int message_id, int chat_id);

// Use this method to stop updating a live location message before <em>live_period</em> expires. On success, if the message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                void stopMessageLiveLocation(std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                                             std::string inline_message_id, int message_id, int chat_id);

// Use this method to send information about a venue. On success, the sent <a href="#message">Message</a> is returned.
                void sendVenue(int chat_id, float latitude, float longitude, std::string title, std::string address,
                               std::shared_ptr<InlineKeyboardMarkup> reply_markup, bool allow_sending_without_reply,
                               int reply_to_message_id, bool protect_content, bool disable_notification,
                               std::string google_place_type, std::string google_place_id, std::string foursquare_type,
                               std::string foursquare_id, int message_thread_id);

// Use this method to send phone contacts. On success, the sent <a href="#message">Message</a> is returned.
                void sendContact(int chat_id, std::string phone_number, std::string first_name,
                                 std::shared_ptr<InlineKeyboardMarkup> reply_markup, bool allow_sending_without_reply,
                                 int reply_to_message_id, bool protect_content, bool disable_notification,
                                 std::string vcard, std::string last_name, int message_thread_id);

// Use this method to send a native poll. On success, the sent <a href="#message">Message</a> is returned.
                void sendPoll(int chat_id, std::string question, std::string options,
                              std::shared_ptr<InlineKeyboardMarkup> reply_markup, bool allow_sending_without_reply,
                              int reply_to_message_id, bool protect_content, bool disable_notification, bool is_closed,
                              int close_date, int open_period,
                              std::vector<std::shared_ptr<MessageEntity>> explanation_entities,
                              std::string explanation_parse_mode, std::string explanation, int correct_option_id,
                              bool allows_multiple_answers, std::string type, bool is_anonymous, int message_thread_id);

// Use this method to send an animated emoji that will display a random value. On success, the sent <a href="#message">Message</a> is returned.
                void sendDice(int chat_id, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                              bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                              bool disable_notification, std::string emoji, int message_thread_id);

// Use this method when you need to tell the user that something is happening on the bot&#39;s side. The status is set for 5 seconds or less (when a message arrives from your bot, Telegram clients clear its typing status). Returns <em>True</em> on success.
                void sendChatAction(int chat_id, std::string action, int message_thread_id);

// Use this method to get a list of profile pictures for a user. Returns a <a href="#userprofilephotos">UserProfilePhotos</a> object.
                void getUserProfilePhotos(int user_id, int limit, int offset);

// Use this method to get basic information about a file and prepare it for downloading. For the moment, bots can download files of up to 20MB in size. On success, a <a href="#file">File</a> object is returned. The file can then be downloaded via the link <code>https://api.telegram.org/file/bot&lt;token&gt;/&lt;file_path&gt;</code>, where <code>&lt;file_path&gt;</code> is taken from the response. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling <a href="#getfile">getFile</a> again.
                void getFile(std::string file_id);

// Use this method to ban a user in a group, a supergroup or a channel. In the case of supergroups and channels, the user will not be able to return to the chat on their own using invite links, etc., unless <a href="#unbanchatmember">unbanned</a> first. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                void banChatMember(int chat_id, int user_id, bool revoke_messages, int until_date);

// Use this method to unban a previously banned user in a supergroup or channel. The user will <strong>not</strong> return to the group or channel automatically, but will be able to join via link, etc. The bot must be an administrator for this to work. By default, this method guarantees that after the call the user is not a member of the chat, but will be able to join it. So if the user is a member of the chat they will also be <strong>removed</strong> from the chat. If you don&#39;t want this, use the parameter <em>only_if_banned</em>. Returns <em>True</em> on success.
                void unbanChatMember(int chat_id, int user_id, bool only_if_banned);

// Use this method to restrict a user in a supergroup. The bot must be an administrator in the supergroup for this to work and must have the appropriate administrator rights. Pass <em>True</em> for all permissions to lift restrictions from a user. Returns <em>True</em> on success.
                void restrictChatMember(int chat_id, int user_id, std::shared_ptr<ChatPermissions> permissions,
                                        int until_date, bool use_independent_chat_permissions);

// Use this method to promote or demote a user in a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Pass <em>False</em> for all boolean parameters to demote a user. Returns <em>True</em> on success.
                void promoteChatMember(int chat_id, int user_id, bool can_manage_topics, bool can_pin_messages,
                                       bool can_invite_users, bool can_change_info, bool can_promote_members,
                                       bool can_restrict_members, bool can_manage_video_chats, bool can_delete_messages,
                                       bool can_edit_messages, bool can_post_messages, bool can_manage_chat,
                                       bool is_anonymous);

// Use this method to set a custom title for an administrator in a supergroup promoted by the bot. Returns <em>True</em> on success.
                void setChatAdministratorCustomTitle(int chat_id, int user_id, std::string custom_title);

// Use this method to ban a channel chat in a supergroup or a channel. Until the chat is <a href="#unbanchatsenderchat">unbanned</a>, the owner of the banned chat won&#39;t be able to send messages on behalf of <strong>any of their channels</strong>. The bot must be an administrator in the supergroup or channel for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                void banChatSenderChat(int chat_id, int sender_chat_id);

// Use this method to unban a previously banned channel chat in a supergroup or channel. The bot must be an administrator for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                void unbanChatSenderChat(int chat_id, int sender_chat_id);

// Use this method to set default chat permissions for all members. The bot must be an administrator in the group or a supergroup for this to work and must have the <em>can_restrict_members</em> administrator rights. Returns <em>True</em> on success.
                void setChatPermissions(int chat_id, std::shared_ptr<ChatPermissions> permissions,
                                        bool use_independent_chat_permissions);

// Use this method to generate a new primary invite link for a chat; any previously generated primary link is revoked. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the new invite link as <em>String</em> on success.
                void exportChatInviteLink(int chat_id);

// Use this method to create an additional invite link for a chat. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. The link can be revoked using the method <a href="#revokechatinvitelink">revokeChatInviteLink</a>. Returns the new invite link as <a href="#chatinvitelink">ChatInviteLink</a> object.
                void createChatInviteLink(int chat_id, bool creates_join_request, int member_limit, int expire_date,
                                          std::string name);

// Use this method to edit a non-primary invite link created by the bot. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the edited invite link as a <a href="#chatinvitelink">ChatInviteLink</a> object.
                void
                editChatInviteLink(int chat_id, std::string invite_link, bool creates_join_request, int member_limit,
                                   int expire_date, std::string name);

// Use this method to revoke an invite link created by the bot. If the primary link is revoked, a new link is automatically generated. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the revoked invite link as <a href="#chatinvitelink">ChatInviteLink</a> object.
                void revokeChatInviteLink(int chat_id, std::string invite_link);

// Use this method to approve a chat join request. The bot must be an administrator in the chat for this to work and must have the <em>can_invite_users</em> administrator right. Returns <em>True</em> on success.
                void approveChatJoinRequest(int chat_id, int user_id);

// Use this method to decline a chat join request. The bot must be an administrator in the chat for this to work and must have the <em>can_invite_users</em> administrator right. Returns <em>True</em> on success.
                void declineChatJoinRequest(int chat_id, int user_id);

// Use this method to set a new profile photo for the chat. Photos can&#39;t be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                void setChatPhoto(int chat_id, std::shared_ptr<InputFile> photo);

// Use this method to delete a chat photo. Photos can&#39;t be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                void deleteChatPhoto(int chat_id);

// Use this method to change the title of a chat. Titles can&#39;t be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                void setChatTitle(int chat_id, std::string title);

// Use this method to change the description of a group, a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                void setChatDescription(int chat_id, std::string description);

// Use this method to add a message to the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the &#39;can_pin_messages&#39; administrator right in a supergroup or &#39;can_edit_messages&#39; administrator right in a channel. Returns <em>True</em> on success.
                void pinChatMessage(int chat_id, int message_id, bool disable_notification);

// Use this method to remove a message from the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the &#39;can_pin_messages&#39; administrator right in a supergroup or &#39;can_edit_messages&#39; administrator right in a channel. Returns <em>True</em> on success.
                void unpinChatMessage(int chat_id, int message_id);

// Use this method to clear the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the &#39;can_pin_messages&#39; administrator right in a supergroup or &#39;can_edit_messages&#39; administrator right in a channel. Returns <em>True</em> on success.
                void unpinAllChatMessages(int chat_id);

// Use this method for your bot to leave a group, supergroup or channel. Returns <em>True</em> on success.
                void leaveChat(int chat_id);

// Use this method to get up to date information about the chat (current name of the user for one-on-one conversations, current username of a user, group or channel, etc.). Returns a <a href="#chat">Chat</a> object on success.
                void getChat(int chat_id);

// Use this method to get a list of administrators in a chat, which aren&#39;t bots. Returns an Array of <a href="#chatmember">ChatMember</a> objects.
                void getChatAdministrators(int chat_id);

// Use this method to get the number of members in a chat. Returns <em>Int</em> on success.
                void getChatMemberCount(int chat_id);

// Use this method to get information about a member of a chat. The method is only guaranteed to work for other users if the bot is an administrator in the chat. Returns a <a href="#chatmember">ChatMember</a> object on success.
                void getChatMember(int chat_id, int user_id);

// Use this method to set a new group sticker set for a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field <em>can_set_sticker_set</em> optionally returned in <a href="#getchat">getChat</a> requests to check if the bot can use this method. Returns <em>True</em> on success.
                void setChatStickerSet(int chat_id, std::string sticker_set_name);

// Use this method to delete a group sticker set from a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field <em>can_set_sticker_set</em> optionally returned in <a href="#getchat">getChat</a> requests to check if the bot can use this method. Returns <em>True</em> on success.
                void deleteChatStickerSet(int chat_id);

// Use this method to get custom emoji stickers, which can be used as a forum topic icon by any user. Requires no parameters. Returns an Array of <a href="#sticker">Sticker</a> objects.
                void getForumTopicIconStickers(int chat_id, std::string name, std::string icon_custom_emoji_id,
                                               int icon_color);

// Use this method to create a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. Returns information about the created topic as a <a href="#forumtopic">ForumTopic</a> object.
                void createForumTopic(int chat_id, std::string name, std::string icon_custom_emoji_id, int icon_color);

// Use this method to edit name and icon of a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have <em>can_manage_topics</em> administrator rights, unless it is the creator of the topic. Returns <em>True</em> on success.
                void
                editForumTopic(int chat_id, int message_thread_id, std::string icon_custom_emoji_id, std::string name);

// Use this method to close an open topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights, unless it is the creator of the topic. Returns <em>True</em> on success.
                void closeForumTopic(int chat_id, int message_thread_id);

// Use this method to reopen a closed topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights, unless it is the creator of the topic. Returns <em>True</em> on success.
                void reopenForumTopic(int chat_id, int message_thread_id);

// Use this method to delete a forum topic along with all its messages in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_delete_messages</em> administrator rights. Returns <em>True</em> on success.
                void deleteForumTopic(int chat_id, int message_thread_id);

// Use this method to clear the list of pinned messages in a forum topic. The bot must be an administrator in the chat for this to work and must have the <em>can_pin_messages</em> administrator right in the supergroup. Returns <em>True</em> on success.
                void unpinAllForumTopicMessages(int chat_id, int message_thread_id);

// Use this method to edit the name of the &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have <em>can_manage_topics</em> administrator rights. Returns <em>True</em> on success.
                void editGeneralForumTopic(int chat_id, std::string name);

// Use this method to close an open &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. Returns <em>True</em> on success.
                void closeGeneralForumTopic(int chat_id);

// Use this method to reopen a closed &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. The topic will be automatically unhidden if it was hidden. Returns <em>True</em> on success.
                void reopenGeneralForumTopic(int chat_id);

// Use this method to hide the &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. The topic will be automatically closed if it was open. Returns <em>True</em> on success.
                void hideGeneralForumTopic(int chat_id);

// Use this method to unhide the &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. Returns <em>True</em> on success.
                void unhideGeneralForumTopic(int chat_id);

// Use this method to send answers to callback queries sent from <a href="/bots/features#inline-keyboards">inline keyboards</a>. The answer will be displayed to the user as a notification at the top of the chat screen or as an alert. On success, <em>True</em> is returned.
                void
                answerCallbackQuery(std::string callback_query_id, int cache_time, std::string url, bool show_alert,
                                    std::string text);

// Use this method to change the list of the bot&#39;s commands. See <a href="/bots/features#commands">this manual</a> for more details about bot commands. Returns <em>True</em> on success.
                void setMyCommands(std::vector<std::shared_ptr<BotCommand>> commands, std::string language_code,
                                   std::shared_ptr<BotCommandScope> scope);

// Use this method to delete the list of the bot&#39;s commands for the given scope and user language. After deletion, <a href="#determining-list-of-commands">higher level commands</a> will be shown to affected users. Returns <em>True</em> on success.
                void deleteMyCommands(std::string language_code, std::shared_ptr<BotCommandScope> scope);

// Use this method to get the current list of the bot&#39;s commands for the given scope and user language. Returns an Array of <a href="#botcommand">BotCommand</a> objects. If commands aren&#39;t set, an empty list is returned.
                void getMyCommands(std::string language_code, std::shared_ptr<BotCommandScope> scope);

// Use this method to change the bot&#39;s menu button in a private chat, or the default menu button. Returns <em>True</em> on success.
                void setChatMenuButton(std::shared_ptr<MenuButton> menu_button, int chat_id);

// Use this method to get the current value of the bot&#39;s menu button in a private chat, or the default menu button. Returns <a href="#menubutton">MenuButton</a> on success.
                void getChatMenuButton(int chat_id);

// Use this method to change the default administrator rights requested by the bot when it&#39;s added as an administrator to groups or channels. These rights will be suggested to users, but they are are free to modify the list before adding the bot. Returns <em>True</em> on success.
                void
                setMyDefaultAdministratorRights(bool for_channels, std::shared_ptr<ChatAdministratorRights> rights);

// Use this method to get the current default administrator rights of the bot. Returns <a href="#chatadministratorrights">ChatAdministratorRights</a> on success.
                void getMyDefaultAdministratorRights(bool for_channels);

// Use this method to edit text and <a href="#games">game</a> messages. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                void editMessageText(std::string text, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                                     bool disable_web_page_preview,
                                     std::vector<std::shared_ptr<MessageEntity>> entities, std::string parse_mode,
                                     std::string inline_message_id, int message_id, int chat_id);

// Use this method to edit captions of messages. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                void editMessageCaption(std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                                        std::vector<std::shared_ptr<MessageEntity>> caption_entities,
                                        std::string parse_mode, std::string caption, std::string inline_message_id,
                                        int message_id, int chat_id);

// Use this method to edit animation, audio, document, photo, or video messages. If a message is part of a message album, then it can be edited only to an audio for audio albums, only to a document for document albums and to a photo or a video otherwise. When an inline message is edited, a new file can&#39;t be uploaded; use a previously uploaded file via its file_id or specify a URL. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                void
                editMessageMedia(std::shared_ptr<InputMedia> media, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                                 std::string inline_message_id, int message_id, int chat_id);

// Use this method to edit only the reply markup of messages. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                void editMessageReplyMarkup(std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                                            std::string inline_message_id, int message_id, int chat_id);

// Use this method to stop a poll which was sent by the bot. On success, the stopped <a href="#poll">Poll</a> is returned.
                void stopPoll(int chat_id, int message_id, std::shared_ptr<InlineKeyboardMarkup> reply_markup);

// Use this method to delete a message, including service messages, with the following limitations:<br>- A message can only be deleted if it was sent less than 48 hours ago.<br>- Service messages about a supergroup, channel, or forum topic creation can&#39;t be deleted.<br>- A dice message in a private chat can only be deleted if it was sent more than 24 hours ago.<br>- Bots can delete outgoing messages in private chats, groups, and supergroups.<br>- Bots can delete incoming messages in private chats.<br>- Bots granted <em>can_post_messages</em> permissions can delete outgoing messages in channels.<br>- If the bot is an administrator of a group, it can delete any message there.<br>- If the bot has <em>can_delete_messages</em> permission in a supergroup or a channel, it can delete any message there.<br>Returns <em>True</em> on success.
                void deleteMessage(int chat_id, int message_id);

// Use this method to send static .WEBP, <a href="https://telegram.org/blog/animated-stickers">animated</a> .TGS, or <a href="https://telegram.org/blog/video-stickers-better-reactions">video</a> .WEBM stickers. On success, the sent <a href="#message">Message</a> is returned.
                void sendSticker(int chat_id, std::string sticker, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                                 bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                                 bool disable_notification, int message_thread_id);

// Use this method to get a sticker set. On success, a <a href="#stickerset">StickerSet</a> object is returned.
                void getStickerSet(std::string name);

// Use this method to get information about custom emoji stickers by their identifiers. Returns an Array of <a href="#sticker">Sticker</a> objects.
                void getCustomEmojiStickers(std::string custom_emoji_ids);

// Use this method to upload a .PNG file with a sticker for later use in <em>createNewStickerSet</em> and <em>addStickerToSet</em> methods (can be used multiple times). Returns the uploaded <a href="#file">File</a> on success.
                void uploadStickerFile(int user_id, std::shared_ptr<InputFile> png_sticker);

// Use this method to create a new sticker set owned by a user. The bot will be able to edit the sticker set thus created. You <strong>must</strong> use exactly one of the fields <em>png_sticker</em>, <em>tgs_sticker</em>, or <em>webm_sticker</em>. Returns <em>True</em> on success.
                void createNewStickerSet(int user_id, std::string name, std::string title, std::string emojis,
                                         std::shared_ptr<MaskPosition> mask_position, std::string sticker_type,
                                         std::shared_ptr<InputFile> webm_sticker,
                                         std::shared_ptr<InputFile> tgs_sticker, std::string png_sticker);

// Use this method to add a new sticker to a set created by the bot. You <strong>must</strong> use exactly one of the fields <em>png_sticker</em>, <em>tgs_sticker</em>, or <em>webm_sticker</em>. Animated stickers can be added to animated sticker sets and only to them. Animated sticker sets can have up to 50 stickers. Static sticker sets can have up to 120 stickers. Returns <em>True</em> on success.
                void addStickerToSet(int user_id, std::string name, std::string emojis,
                                     std::shared_ptr<MaskPosition> mask_position,
                                     std::shared_ptr<InputFile> webm_sticker, std::shared_ptr<InputFile> tgs_sticker,
                                     std::string png_sticker);

// Use this method to move a sticker in a set created by the bot to a specific position. Returns <em>True</em> on success.
                void setStickerPositionInSet(std::string sticker, int position);

// Use this method to delete a sticker from a set created by the bot. Returns <em>True</em> on success.
                void deleteStickerFromSet(std::string sticker);

// Use this method to set the thumbnail of a sticker set. Animated thumbnails can be set for animated sticker sets only. Video thumbnails can be set only for video sticker sets only. Returns <em>True</em> on success.
                void setStickerSetThumb(std::string name, int user_id, std::string thumb);

// Use this method to send answers to an inline query. On success, <em>True</em> is returned.<br>No more than <strong>50</strong> results per query are allowed.
                void
                answerInlineQuery(std::string inline_query_id, std::vector<std::shared_ptr<InlineQueryResult>> results,
                                  std::string switch_pm_parameter, std::string switch_pm_text, std::string next_offset,
                                  bool is_personal, int cache_time);

// Use this method to set the result of an interaction with a <a href="/bots/webapps">Web App</a> and send a corresponding message on behalf of the user to the chat from which the query originated. On success, a <a href="#sentwebappmessage">SentWebAppMessage</a> object is returned.
                void answerWebAppQuery(std::string web_app_query_id, std::shared_ptr<InlineQueryResult> result);

// Use this method to send invoices. On success, the sent <a href="#message">Message</a> is returned.
                void sendInvoice(int chat_id, std::string title, std::string description, std::string payload,
                                 std::string provider_token, std::string currency,
                                 std::vector<std::shared_ptr<LabeledPrice>> prices,
                                 std::shared_ptr<InlineKeyboardMarkup> reply_markup, bool allow_sending_without_reply,
                                 int reply_to_message_id, bool protect_content, bool disable_notification,
                                 bool is_flexible, bool send_email_to_provider, bool send_phone_number_to_provider,
                                 bool need_shipping_address, bool need_email, bool need_phone_number, bool need_name,
                                 int photo_height, int photo_width, int photo_size, std::string photo_url,
                                 std::string provider_data, std::string start_parameter, int suggested_tip_amounts,
                                 int max_tip_amount, int message_thread_id);

// Use this method to create a link for an invoice. Returns the created invoice link as <em>String</em> on success.
                void createInvoiceLink(std::string title, std::string description, std::string payload,
                                       std::string provider_token, std::string currency,
                                       std::vector<std::shared_ptr<LabeledPrice>> prices, bool is_flexible,
                                       bool send_email_to_provider, bool send_phone_number_to_provider,
                                       bool need_shipping_address, bool need_email, bool need_phone_number,
                                       bool need_name, int photo_height, int photo_width, int photo_size,
                                       std::string photo_url, std::string provider_data, int suggested_tip_amounts,
                                       int max_tip_amount);

// If you sent an invoice requesting a shipping address and the parameter <em>is_flexible</em> was specified, the Bot API will send an <a href="#update">Update</a> with a <em>shipping_query</em> field to the bot. Use this method to reply to shipping queries. On success, <em>True</em> is returned.
                void answerShippingQuery(std::string shipping_query_id, bool ok, std::string error_message,
                                         std::vector<std::shared_ptr<ShippingOption>> shipping_options);

// Once the user has confirmed their payment and shipping details, the Bot API sends the final confirmation in the form of an <a href="#update">Update</a> with the field <em>pre_checkout_query</em>. Use this method to respond to such pre-checkout queries. On success, <em>True</em> is returned. <strong>Note:</strong> The Bot API must receive an answer within 10 seconds after the pre-checkout query was sent.
                void answerPreCheckoutQuery(std::string pre_checkout_query_id, bool ok, std::string error_message);

// Informs a user that some of the Telegram Passport elements they provided contains errors. The user will not be able to re-submit their Passport to you until the errors are fixed (the contents of the field for which you returned the error must change). Returns <em>True</em> on success.
                void setPassportDataErrors(int user_id, std::vector<std::shared_ptr<PassportElementError>> errors);

// Use this method to send a game. On success, the sent <a href="#message">Message</a> is returned.
                void
                sendGame(int chat_id, std::string game_short_name, std::shared_ptr<InlineKeyboardMarkup> reply_markup,
                         bool allow_sending_without_reply, int reply_to_message_id, bool protect_content,
                         bool disable_notification, int message_thread_id);

// Use this method to set the score of the specified user in a game message. On success, if the message is not an inline message, the <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned. Returns an error, if the new score is not greater than the user&#39;s current score in the chat and <em>force</em> is <em>False</em>.
                void setGameScore(int user_id, int score, std::string inline_message_id, int message_id, int chat_id,
                                  bool disable_edit_message, bool force);

// Use this method to get data for high score tables. Will return the score of the specified user and several of their neighbors in a game. Returns an Array of <a href="#gamehighscore">GameHighScore</a> objects.
                void getGameHighScores(int user_id, std::string inline_message_id, int message_id, int chat_id);

                ~API() {};
            private:
                std::shared_ptr<Network> &request;
                std::string generalToken = "";
            };
        }
    }
}
