#pragma once
#include <string>
#include <functional>
#include <iostream>
#include <json/json.h>
#include <vector>
#include <memory>
#include <optional>
#include <thread>
#include <mutex>
#define CURL_STATICLIB
#include "../curl/curl.h"
namespace TelegramTypes {
	using MessageReceive = Json::Value;
	struct InputMediaPhoto {
		std::string type;
		std::string media;
		std::string caption;
		std::string parse_mode;
	};
	struct InputMediaVideo {
		std::string mime_thumb;
		std::string type;
		std::string media;
		std::string thumb;
		std::string caption;
		std::string parse_mode;
		__int64 width;
		__int64 height;
		__int64 duration;
		bool supports_streaming;
	};
	struct InputMediaAudio {
		std::string type;
		std::string media;
		std::string thumb;
		std::string caption;
		std::string parse_mode;
		__int64 duration;
		std::string performer;
		std::string title;
	};
	struct InputMediaDocument {
		std::string type;
		std::string media;
		std::string thumb;
		std::string caption;
		std::string parse_mode;
	};
	class API {
	public:
		API(std::string link) : generalToken(link) {};
		inline void sendMessage(const std::string& chat_id, const std::string& msgp, const std::optional<std::string>& parse_mode = "", const std::optional<bool>& disable_web_page_preview = false, const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<Json::Value>& reply_markup = "");
		inline void sendDocument(const std::string& chat_id, const std::string& mime_type, const std::string& document, const std::optional<std::string>& mime_thumb = "", const std::optional<std::string>& thumb = "", const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<std::string>& reply_markup = "");
		inline void sendPhoto(const std::string& chat_id, const std::string& mime_type, const std::string& photo, const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<std::string>& reply_markup = "");
		inline void sendAudio(const std::string& chat_id, const std::string& mime_type, const std::string& audio, const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<__int64>& duration = 0, const std::optional<__int64>& performer = 0, const std::optional<std::string>& title = "", const std::optional<std::string>& mime_thumb = "", const std::optional<std::string>& thumb = "", const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<std::string>& reply_markup = "");
		inline void sendAnimation(const std::string& chat_id, const std::string& mime_type, const std::string& animation, const std::optional<__int64>& duration = 0, const std::optional<__int64>& width = 0, const std::optional<__int64>& height = 0, const std::optional<std::string>& mime_thumb = "", const std::optional<std::string>& thumb = "", const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<std::string>& reply_markup = "");
		inline void sendVoice(const std::string& chat_id, const std::string& mime_type, const std::string& voice, const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<std::string>& reply_markup = "");
		inline void sendVideoNote(const std::string& chat_id, const std::string& mime_type, const std::string& video_note, const std::optional<__int64>& duration = 0, const std::optional<__int64>& length = 0, const std::optional<std::string>& mime_thumb = "", const std::optional<std::string>& thumb = "", const std::optional<std::string>& caption = "", const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<std::string>& reply_markup = "");
		inline void sendVideo(const std::string& chat_id, const std::string& mime_type, const std::string& video, const std::optional<__int64>& duration = 0, const std::optional<__int64>& width = 0, const std::optional<__int64>& height = 0, const std::optional<std::string>& mime_thumb = "", const std::optional<std::string>& thumb = "", const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<bool>& supports_streaming = false, const std::optional<bool>& disable_notification = 0, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<std::string>& reply_markup = "");
		inline void sendMediaGroup(const std::string& chat_id, const std::string& mime_type, const std::vector<std::shared_ptr<InputMediaPhoto>>& media, const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0);
		inline void sendMediaGroup(const std::string& chat_id, const std::string& mime_type, const std::vector<std::shared_ptr<InputMediaVideo>>& media, const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0);
		inline void copyMessage(const Json::Value& from_chat_id, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<__int64>& message_id = 0, const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<bool>& allow_sending_without_reply = false, const std::optional<Json::Value>& caption_entities = nullptr);
		inline void sendLocation(const float& latitude, const float& longitude, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<__int64>& live_period = 0, const std::optional<float>& horizontal_accuracy = 0, const std::optional<__int64>& proximity_alert_radius = 0, const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<bool>& allow_sending_without_reply = false, const std::optional<__int64>& heading = 0);
		inline void editMessageLiveLocation(const float& latitude, const float& longitude, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& inline_message_id = "", const std::optional<__int64>& message_id = 0, const std::optional<float>& horizontal_accuracy = 0, const std::optional<__int64>& heading = 0, const std::optional<__int64>& proximity_alert_radius = 0, const std::optional<Json::Value>& chat_id = nullptr);
		inline void stopMessageLiveLocation(const std::optional<Json::Value>& chat_id = nullptr, const std::optional<__int64>& message_id = 0, const std::optional<std::string>& inline_message_id = "", const std::optional<Json::Value>& reply_markup = nullptr);
		inline void sendVenue(const float& latitude, const float& longitude, const std::string& title, const std::string& address, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& foursquare_id = "", const std::optional<std::string>& google_place_id = "", const std::optional<std::string>& google_place_type = "", const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<bool>& allow_sending_without_reply = false, const std::optional<std::string>& foursquare_type = "");
		inline void sendContact(const std::string& phone_number, const std::string& first_name, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& last_name = "", const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<bool>& allow_sending_without_reply = false, const std::optional<std::string>& vcard = "");
		inline void sendPoll(const std::string& question, const Json::Value& options, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& explanation_parse_mode = "", const std::optional<__int64>& open_period = 0, const std::optional<std::string>& type = "", const std::optional<__int64>& close_date = 0, const std::optional<__int64>& correct_option_id = 0, const std::optional<bool>& is_closed = false, const std::optional<bool>& allows_multiple_answers = false, const std::optional<std::string>& explanation = "", const std::optional<Json::Value>& explanation_entities = nullptr, const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<bool>& allow_sending_without_reply = false, const std::optional<bool>& is_anonymous = false);
		inline void sendDice(const Json::Value& chat_id, const std::optional<std::string>& emoji = "", const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<bool>& allow_sending_without_reply = false, const std::optional<Json::Value>& reply_markup = nullptr);
		inline void sendChatAction(const Json::Value& chat_id, const std::optional<std::string>& action = "");
		inline Json::Value getUserProfilePhotos(const __int64& user_id, const std::optional<__int64>& offset = 0, const std::optional<__int64>& limit = 0);
		inline Json::Value getFile(const std::string& file_id);
		inline void kickChatMember(const __int64& user_id, const Json::Value& chat_id, const std::optional<__int64>& until_date = 0);
		inline void unbanChatMember(const __int64& user_id, const Json::Value& chat_id, const std::optional<bool>& only_if_banned = false);
		inline void restrictChatMember(const __int64& user_id, const Json::Value& permissions, const Json::Value& chat_id, const std::optional<__int64>& until_date = 0);
		inline void promoteChatMember(const __int64& user_id, const Json::Value& chat_id, const std::optional<bool>& can_promote_members = false, const std::optional<bool>& can_change_info = false, const std::optional<bool>& can_post_messages = false, const std::optional<bool>& is_anonymous = false, const std::optional<bool>& can_delete_messages = false, const std::optional<bool>& can_invite_users = false, const std::optional<bool>& can_restrict_members = false, const std::optional<bool>& can_pin_messages = false, const std::optional<bool>& can_edit_messages = false);
		inline void setChatAdministratorCustomTitle(const __int64& user_id, const std::string& custom_title, const Json::Value& chat_id);
		inline void setChatPermissions(const Json::Value& permissions, const Json::Value& chat_id);
		inline void exportChatInviteLink(const Json::Value& chat_id);
		inline void setChatPhoto(const Json::Value& photo, const Json::Value& chat_id);
		inline void deleteChatPhoto(const Json::Value& chat_id);
		inline void setChatTitle(const std::string& title, const Json::Value& chat_id);
		inline void setChatDescription(const Json::Value& chat_id, const std::optional<std::string>& description = "");
		inline void pinChatMessage(const __int64& message_id, const Json::Value& chat_id, const std::optional<bool>& disable_notification = false);
		inline void unpinChatMessage(const Json::Value& chat_id, const std::optional<__int64>& message_id = 0);
		inline void unpinAllChatMessages(const Json::Value& chat_id);
		inline void leaveChat(const Json::Value& chat_id);
		inline Json::Value getChat(const std::string& chat_id);
		inline Json::Value getChatAdministrators(const Json::Value& chat_id);
		inline Json::Value getChatMembersCount(const Json::Value& chat_id);
		inline Json::Value getChatMember(const __int64& user_id, const Json::Value& chat_id);
		inline void setChatStickerSet(const std::string& sticker_set_name, const Json::Value& chat_id);
		inline void deleteChatStickerSet(const Json::Value& chat_id);
		inline void answerCallbackQuery(const std::string& callback_query_id, const std::optional<std::string>& text = "", const std::optional<bool>& show_alert = false, const std::optional<std::string>& url = "", const std::optional<__int64>& cache_time = 0);
		inline void setMyCommands(const Json::Value& commands);
		inline Json::Value getMyCommands(const std::string& text, const std::optional<Json::Value>& chat_id = nullptr, const std::optional<__int64>& message_id = 0, const std::optional<std::string>& inline_message_id = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& entities = nullptr, const std::optional<bool>& disable_web_page_preview = false, const std::optional<Json::Value>& reply_markup = nullptr);
		inline void editMessageCaption(const std::optional<Json::Value>& chat_id = nullptr, const std::optional<__int64>& message_id = 0, const std::optional<std::string>& inline_message_id = "", const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = nullptr, const std::optional<Json::Value>& reply_markup = nullptr);
		inline void editMessageMedia(const Json::Value& media, const std::optional<Json::Value>& chat_id = nullptr, const std::optional<__int64>& message_id = 0, const std::optional<std::string>& inline_message_id = "", const std::optional<Json::Value>& reply_markup = nullptr);
		inline void editMessageReplyMarkup(const std::optional<Json::Value>& chat_id = nullptr, const std::optional<__int64>& message_id = 0, const std::optional<std::string>& inline_message_id = "", const std::optional<Json::Value>& reply_markup = nullptr);
		inline void stopPoll(const __int64& message_id, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup = nullptr);
		inline void deleteMessage(const __int64& message_id, const Json::Value& chat_id);
		inline void StickerSet(const std::string& title, const Json::Value& stickers, const std::string& name, const std::optional<bool>& is_animated = false, const std::optional<bool>& contains_masks = false, const std::optional<Json::Value>& thumb = nullptr);
		inline void MaskPosition(const float& x_shift, const float& y_shift, const float& scale, const std::string& point);
		inline void sendSticker(const Json::Value& sticker, const Json::Value& chat_id, const std::optional<bool>& disable_notification = false, const std::optional<__int64>& reply_to_message_id = 0, const std::optional<bool>& allow_sending_without_reply = false, const std::optional<Json::Value>& reply_markup = nullptr);
		inline Json::Value getStickerSet(const std::string& name);
		inline void uploadStickerFile(const Json::Value& png_sticker, const __int64& user_id);
		inline void createNewStickerSet(const std::string& emojis, const std::string& title, const __int64& user_id, const std::optional<std::string>& name = "", const std::optional<Json::Value>& png_sticker = nullptr, const std::optional<Json::Value>& tgs_sticker = nullptr, const std::optional<bool>& contains_masks = false, const std::optional<Json::Value>& mask_position = nullptr);
		inline void addStickerToSet(const std::string& name, const std::string& emojis, const __int64& user_id, const std::optional<Json::Value>& png_sticker = nullptr, const std::optional<Json::Value>& tgs_sticker = nullptr, const std::optional<Json::Value>& mask_position = nullptr);
		inline void setStickerPositionInSet(const __int64& position, const std::string& sticker);
		inline void deleteStickerFromSet(const std::string& sticker);
		inline void setStickerSetThumb(const __int64& user_id, const std::string& name, const std::optional<Json::Value>& thumb = nullptr);
		inline void answerInlineQuery(const Json::Value& results, const std::string& inline_query_id, const std::optional<__int64>& cache_time = 0, const std::optional<bool>& is_personal = false, const std::optional<std::string>& next_offset = "", const std::optional<std::string>& switch_pm_text = "", const std::optional<std::string>& switch_pm_parameter = "");
		inline void InlineQueryResult(const std::string& id, const std::string& title, const Json::Value& input_message_content, const std::optional<__int64>& thumb_height = 0, const std::optional<std::string>& url = "", const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<bool>& hide_url = false, const std::optional<std::string>& description = "", const std::optional<std::string>& thumb_url = "", const std::optional<__int64>& thumb_width = 0, const std::optional<std::string>& type = "");
		inline void InlineQueryResultPhoto(const std::string& id, const std::string& photo_url, const std::string& thumb_url, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& title = "", const std::optional<__int64>& photo_height = 0, const std::optional<__int64>& photo_width = 0, const std::optional<std::string>& description = "", const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& type = "");
		inline void InlineQueryResultGif(const std::string& id, const std::string& gif_url, const std::string& thumb_url, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& thumb_mime_type = "", const std::optional<std::string>& type = "", const std::optional<std::string>& caption = "", const std::optional<__int64>& gif_width = 0, const std::optional<std::string>& title = "", const std::optional<__int64>& gif_height = 0, const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<__int64>& gif_duration = 0);
		inline void InlineQueryResultMpeg4Gif(const std::string& id, const std::string& mpeg4_url, const std::string& thumb_url, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& thumb_mime_type = "", const std::optional<std::string>& type = "", const std::optional<std::string>& caption = "", const std::optional<__int64>& mpeg4_width = 0, const std::optional<std::string>& title = "", const std::optional<__int64>& mpeg4_height = 0, const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<__int64>& mpeg4_duration = 0);
		inline void InlineQueryResultVideo(const std::string& id, const std::string& video_url, const std::string& mime_type, const std::string& thumb_url, const std::string& title, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& parse_mode = "", const std::optional<std::string>& caption = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<__int64>& video_width = 0, const std::optional<__int64>& video_height = 0, const std::optional<__int64>& video_duration = 0, const std::optional<std::string>& description = "", const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& type = "");
		inline void InlineQueryResultAudio(const std::string& id, const std::string& audio_url, const std::string& title, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& parse_mode = "", const std::optional<std::string>& caption = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<std::string>& performer = "", const std::optional<__int64>& audio_duration = 0, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& type = "");
		inline void InlineQueryResultVoice(const std::string& id, const std::string& voice_url, const std::string& title, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& parse_mode = "", const std::optional<std::string>& caption = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<__int64>& voice_duration = 0, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& type = "");
		inline void InlineQueryResultDocument(const std::string& id, const std::string& title, const std::string& document_url, const std::string& mime_type, const std::optional<__int64>& thumb_height = 0, const std::optional<std::string>& type = "", const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& caption = "", const std::optional<std::string>& description = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& thumb_url = "", const std::optional<__int64>& thumb_width = 0, const std::optional<Json::Value>& caption_entities = {});
		inline void InlineQueryResultLocation(const std::string& id, const float& latitude, const float& longitude, const std::string& title, const std::optional<__int64>& thumb_height = 0, const std::optional<__int64>& heading = 0, const std::optional<__int64>& live_period = 0, const std::optional<float>& horizontal_accuracy = 0, const std::optional<__int64>& proximity_alert_radius = 0, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& thumb_url = "", const std::optional<__int64>& thumb_width = 0, const std::optional<std::string>& type = "");
		inline void InlineQueryResultVenue(const std::string& id, const float& latitude, const float& longitude, const std::string& title, const std::string& address, const std::optional<__int64>& thumb_height = 0, const std::optional<std::string>& foursquare_type = "", const std::optional<std::string>& foursquare_id = "", const std::optional<std::string>& google_place_id = "", const std::optional<std::string>& google_place_type = "", const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& thumb_url = "", const std::optional<__int64>& thumb_width = 0, const std::optional<std::string>& type = "");
		inline void InlineQueryResultContact(const std::string& id, const std::string& phone_number, const std::string& first_name, const std::optional<__int64>& thumb_height = 0, const std::optional<std::string>& vcard = "", const std::optional<std::string>& last_name = "", const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& thumb_url = "", const std::optional<__int64>& thumb_width = 0, const std::optional<std::string>& type = "");
		inline void InlineQueryResultGame(const std::string& id, const std::string& game_short_name, const std::optional<std::string>& type = "", const std::optional<Json::Value>& reply_markup = nullptr);
		inline void InlineQueryResultCachedPhoto(const std::string& id, const std::string& photo_file_id, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& caption = "", const std::optional<std::string>& description = "", const std::optional<std::string>& title = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& type = "");
		inline void InlineQueryResultCachedGif(const std::string& id, const std::string& gif_file_id, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& caption = "", const std::optional<std::string>& title = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& type = "");
		inline void InlineQueryResultCachedMpeg4Gif(const std::string& id, const std::string& mpeg4_file_id, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& caption = "", const std::optional<std::string>& title = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& type = "");
		inline void InlineQueryResultCachedSticker(const std::string& id, const std::string& sticker_file_id, const std::optional<std::string>& type = "", const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<Json::Value>& input_message_content = nullptr);
		inline void InlineQueryResultCachedDocument(const std::string& id, const std::string& title, const std::string& document_file_id, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& caption = "", const std::optional<std::string>& description = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& type = "");
		inline void InlineQueryResultCachedVideo(const std::string& id, const std::string& video_file_id, const std::string& title, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& caption = "", const std::optional<std::string>& description = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& type = "");
		inline void InlineQueryResultCachedVoice(const std::string& id, const std::string& voice_file_id, const std::string& title, const std::optional<Json::Value>& input_message_content = nullptr, const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<std::string>& type = "");
		inline void InlineQueryResultCachedAudio(const std::string& id, const std::string& audio_file_id, const std::optional<std::string>& type = "", const std::optional<std::string>& caption = "", const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& caption_entities = {}, const std::optional<Json::Value>& reply_markup = nullptr, const std::optional<Json::Value>& input_message_content = nullptr);
		inline void InputMessageContent(const std::string& message_text, const std::optional<std::string>& parse_mode = "", const std::optional<Json::Value>& entities = {}, const std::optional<bool>& disable_web_page_preview = false);
		inline void InputLocationMessageContent(const float& longitude, const float& latitude, const std::optional<float>& horizontal_accuracy = 0, const std::optional<__int64>& live_period = 0, const std::optional<__int64>& heading = 0, const std::optional<__int64>& proximity_alert_radius = 0);
		inline void InputVenueMessageContent(const float& longitude, const std::string& title, const std::string& address, const float& latitude, const std::optional<std::string>& foursquare_id = "", const std::optional<std::string>& foursquare_type = "", const std::optional<std::string>& google_place_id = "", const std::optional<std::string>& google_place_type = "");
		inline void InputContactMessageContent(const std::string& first_name, const std::string& phone_number, const std::optional<std::string>& last_name = "", const std::optional<std::string>& vcard = "");
		inline void ChosenInlineResult(const Json::Value& from, const std::string& query, const std::string& result_id, const std::optional<Json::Value>& location = nullptr, const std::optional<std::string>& inline_message_id = "");
		inline void answerShippingQuery(const bool& ok, const std::string& shipping_query_id, const std::optional<Json::Value>& shipping_options = {}, const std::optional<std::string>& error_message = "");
		inline void answerPreCheckoutQuery(const std::string& pre_checkout_query_id, const std::optional<bool>& ok = false, const std::optional<std::string>& error_message = "");
		inline void LabeledPrice(const std::string& label, const std::optional<__int64>& amount = 0);
		inline void Invoice(const std::string& description, const std::string& start_parameter, const std::string& currency, const std::string& title, const std::optional<__int64>& total_amount = 0);
		inline void ShippingAddress(const std::string& state, const std::string& city, const std::string& street_line1, const std::string& street_line2, const std::string& post_code, const std::string& country_code);
		inline void OrderInfo(const std::optional<std::string>& name = "", const std::optional<std::string>& phone_number = "", const std::optional<std::string>& email = "", const std::optional<Json::Value>& shipping_address = nullptr);
		inline void ShippingOption(const std::string& title, const Json::Value& prices, const std::string& id);
		inline void SuccessfulPayment(const std::string& provider_payment_charge_id, const std::string& invoice_payload, const std::string& telegram_payment_charge_id, const std::string& currency, const std::optional<__int64>& total_amount = 0, const std::optional<std::string>& shipping_option_id = "", const std::optional<Json::Value>& order_info = nullptr);
		inline void ShippingQuery(const Json::Value& from, const std::string& invoice_payload, const Json::Value& shipping_address, const std::string& id);
		inline void PreCheckoutQuery(const Json::Value& from, const std::string& currency, const std::string& invoice_payload, const std::string& id, const std::optional<__int64>& total_amount = 0, const std::optional<std::string>& shipping_option_id = "", const std::optional<Json::Value>& order_info = nullptr);
		inline void PassportFile(const std::string& file_unique_id, const __int64& file_size, const __int64& file_date, const std::string& file_id);
		inline void EncryptedPassportElement(const std::string& type, const std::string& hash, const std::optional<std::string>& phone_number = "", const std::optional<std::string>& email = "", const std::optional<Json::Value>& files = {}, const std::optional<std::string>& data = "", const std::optional<Json::Value>& reverse_side = nullptr, const std::optional<Json::Value>& selfie = nullptr, const std::optional<Json::Value>& translation = {}, const std::optional<Json::Value>& front_side = nullptr);
		inline void EncryptedCredentials(const std::string& hash, const std::string& secret, const std::string& data);
		inline void setPassportDataErrors(const Json::Value& errors, const __int64& user_id);
		inline void PassportElementError(const std::string& type, const std::string& field_name, const std::string& data_hash, const std::string& message, const std::optional<std::string>& source = "");
		inline void PassportElementErrorFrontSide(const std::string& type, const std::string& file_hash, const std::string& message, const std::optional<std::string>& source = "");
		inline void PassportElementErrorReverseSide(const std::string& type, const std::string& file_hash, const std::string& message, const std::optional<std::string>& source = "");
		inline void PassportElementErrorSelfie(const std::string& type, const std::string& file_hash, const std::string& message, const std::optional<std::string>& source = "");
		inline void PassportElementErrorFile(const std::string& type, const std::string& file_hash, const std::string& message, const std::optional<std::string>& source = "");
		inline void PassportElementErrorFiles(const std::string& type, const Json::Value& file_hashes, const std::string& message, const std::optional<std::string>& source = "");
		inline void PassportElementErrorTranslationFile(const std::string& type, const std::string& file_hash, const std::string& message, const std::optional<std::string>& source = "");
		inline void PassportElementErrorTranslationFiles(const std::string& type, const Json::Value& file_hashes, const std::string& message, const std::optional<std::string>& source = "");
		inline void PassportElementErrorUnspecified(const std::string& type, const std::string& element_hash, const std::string& message, const std::optional<std::string>& source = "");
		inline void Game(const std::string& description, const Json::Value& photo, const std::string& title, const std::optional<std::string>& text = "", const std::optional<Json::Value>& text_entities = {}, const std::optional<Json::Value>& animation = nullptr);
		inline void CallbackGame(const __int64& score, const __int64& user_id, const std::optional<bool>& force = false, const std::optional<bool>& disable_edit_message = false, const std::optional<__int64>& chat_id = 0, const std::optional<__int64>& message_id = 0, const std::optional<std::string>& inline_message_id = "");
		inline Json::Value getGameHighScores(const __int64& user_id, const std::optional<__int64>& chat_id = 0, const std::optional<__int64>& message_id = 0, const std::optional<std::string>& inline_message_id = "");
		inline void GameHighScore(const Json::Value& user, const __int64& score, const __int64& position);
		~API() {};
	private:
		std::string generalToken = "";
		inline void sendQuery(std::string& query);
	};
}
inline size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
inline void TelegramTypes::API::sendMessage(const std::string& chat_id, const std::string& msgp, const  std::optional<std::string>& parse_mode, const std::optional<bool>& disable_web_page_preview, const  std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<Json::Value>& reply_markup)
{
	std::string text = "";
	text = text + "chat_id=" + chat_id;
	text = text + "&text=" + msgp;
	for (__int64 i = 0; i < msgp.length(); i++) {
		if (text.at(i) == ' ') {
			text.at(i) = '+';
		}
	}
	text = text + "&parse_mode=" + parse_mode.value();
	if (disable_web_page_preview.has_value()) {
		text = text + "&disable_web_page_preview=true";
	}
	else {
		text = text + "&disable_web_page_preview=false";
	}
	if (disable_notification.has_value()) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notifiaction=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id.value());
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/sendMessage?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendDocument(const std::string& chat_id, const std::string& mime_type, const std::string& document, const std::optional<std::string>& mime_thumb, const std::optional<std::string>& thumb, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<std::string>& reply_markup)
{
	CURL* curl;
	CURLcode res;
	curl_mime* form = NULL;
	curl_mimepart* field = NULL;
	struct curl_slist* headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption.value();
	text = text + "&parse_mode=" + parse_mode.value();
	curl = curl_easy_init();
	if (mime_thumb.has_value()) {
		if (thumb.has_value()) {
			if (mime_thumb.value() != "") {
				if (curl) {
					form = curl_mime_init(curl);
					field = curl_mime_addpart(form);
					curl_mime_name(field, "thumb");
					curl_mime_filedata(field, thumb.value().c_str());
					field = curl_mime_addpart(form);
					curl_mime_name(field, "thumb=");
					curl_mime_data(field, "thumb", CURL_ZERO_TERMINATED);
					headerlist = curl_slist_append(headerlist, buf);
				}
			}
			else {
				text = text + "&thumb=" + thumb.value();
			}
		}
	}
	if (disable_notification.value()) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id.value());
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup.value();
	if (mime_type != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "document");
			curl_mime_filedata(field, document.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "document=");
			curl_mime_data(field, "document", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
			std::string toSend = generalToken + "/sendDocument" + text;
			curl_easy_setopt(curl, CURLOPT_URL, toSend.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
			curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_mime_free(form);
			curl_slist_free_all(headerlist);
		}
	}
	else {
		text = text + "&document=" + document;
		std::string tosend = generalToken + "/sendDocument" + text;
		sendQuery(tosend);
	}
}
inline void TelegramTypes::API::sendPhoto(const std::string& chat_id, const std::string& mime_type, const std::string& photo, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<std::string>& reply_markup)
{
	CURL* curl;
	CURLcode res;
	curl_mime* form = NULL;
	curl_mimepart* field = NULL;
	struct curl_slist* headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption.value();
	text = text + "&parse_mode=" + parse_mode.value();
	if (disable_notification.value()) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id.value());
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup.value();
	curl = curl_easy_init();
	if (mime_type != "") {
		curl_mime* form = NULL;
		curl_mimepart* field = NULL;
		struct curl_slist* headerlist = NULL;
		const char buf[] = "Expect:";
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "photo");
			curl_mime_filedata(field, photo.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "photo=");
			curl_mime_data(field, "photo", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
			std::string toSend = generalToken + "/sendPhoto" + text;
			curl_easy_setopt(curl, CURLOPT_URL, toSend.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
			curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_mime_free(form);
			curl_slist_free_all(headerlist);
		}
	}
	else {
		text = text + "&photo=" + photo;
		std::string tosend = generalToken + "/sendPhoto" + text;
		sendQuery(tosend);
	}
}
inline void TelegramTypes::API::sendAudio(const std::string& chat_id, const std::string& mime_type, const std::string& audio, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<__int64>& duration, const std::optional<__int64>& performer, const std::optional<std::string>& title, const std::optional<std::string>& mime_thumb, const std::optional<std::string>& thumb, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<std::string>& reply_markup)
{
	CURL* curl;
	CURLcode res;
	curl_mime* form = NULL;
	curl_mimepart* field = NULL;
	struct curl_slist* headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption.value();
	text = text + "&parse_mode=" + parse_mode.value();
	text = text + "&duration=" + std::to_string(duration.value());
	text = text + "&performer=" + std::to_string(performer.value());
	text = text + "&title=" + title.value();
	curl = curl_easy_init();
	if (mime_thumb.value() != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb");
			curl_mime_filedata(field, thumb.value().c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb=");
			curl_mime_data(field, "thumb", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
		}
	}
	else {
		text = text + "&thumb=" + thumb.value();
	}
	if (disable_notification.value()) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id.value());
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup.value();
	if (mime_type != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "audio");
			curl_mime_filedata(field, audio.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "audio=");
			curl_mime_data(field, "audio", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
			std::string toSend = generalToken + "/sendAudio" + text;
			curl_easy_setopt(curl, CURLOPT_URL, toSend.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
			curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_mime_free(form);
			curl_slist_free_all(headerlist);
		}
	}
	else {
		text = text + "&audio=" + audio;
		std::string tosend = generalToken + "/sendAudio" + text;
		sendQuery(tosend);
	}
}
inline void TelegramTypes::API::sendAnimation(const std::string& chat_id, const std::string& mime_type, const std::string& animation, const std::optional<__int64>& duration, const std::optional<__int64>& width, const std::optional<__int64>& height, const std::optional<std::string>& mime_thumb, const std::optional<std::string>& thumb, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<std::string>& reply_markup)
{
	CURL* curl;
	CURLcode res;
	curl_mime* form = NULL;
	curl_mimepart* field = NULL;
	struct curl_slist* headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption.value();
	text = text + "&parse_mode=" + parse_mode.value();
	text = text + "&duration=" + std::to_string(duration.value());
	text = text + "&width=" + std::to_string(width.value());
	text = text + "&height=" + std::to_string(height.value());
	curl = curl_easy_init();
	if (mime_thumb.value() != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb");
			curl_mime_filedata(field, thumb.value().c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb=");
			curl_mime_data(field, "thumb", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
		}
	}
	else {
		text = text + "&thumb=" + thumb.value();
	}
	if (disable_notification.value()) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id.value());
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup.value();
	if (mime_type != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "animation");
			curl_mime_filedata(field, animation.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "animation=");
			curl_mime_data(field, "animation", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
			std::string toSend = generalToken + "/sendAnimation" + text;
			curl_easy_setopt(curl, CURLOPT_URL, toSend.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
			curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_mime_free(form);
			curl_slist_free_all(headerlist);
		}
	}
	else {
		text = text + "&animation=" + animation;
		std::string tosend = generalToken + "/sendAnimation" + text;
		sendQuery(tosend);
	}
}
inline void TelegramTypes::API::sendVoice(const std::string& chat_id, const std::string& mime_type, const std::string& voice, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<std::string>& reply_markup)
{
	CURL* curl;
	CURLcode res;
	curl_mime* form = NULL;
	curl_mimepart* field = NULL;
	struct curl_slist* headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption.value();
	text = text + "&parse_mode=" + parse_mode.value();
	curl = curl_easy_init();
	if (disable_notification.value()) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id.value());
	std::string readBuffer;
	if (mime_type != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "voice");
			curl_mime_filedata(field, voice.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "voice=");
			curl_mime_data(field, "voice", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
			std::string toSend = generalToken + "/sendVoice" + text;
			curl_easy_setopt(curl, CURLOPT_URL, toSend.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
			curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_mime_free(form);
			curl_slist_free_all(headerlist);
		}
	}
	else {
		text = text + "&voice=" + voice;
		std::string tosend = generalToken + "/sendVoice" + text;
		sendQuery(tosend);
	}
}
inline void TelegramTypes::API::sendVideoNote(const std::string& chat_id, const std::string& mime_type, const std::string& video_note, const std::optional<__int64>& duration, const std::optional<__int64>& length, const std::optional<std::string>& mime_thumb, const std::optional<std::string>& thumb, const std::optional<std::string>& caption, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<std::string>& reply_markup)
{
	CURL* curl;
	CURLcode res;
	curl_mime* form = NULL;
	curl_mimepart* field = NULL;
	struct curl_slist* headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption.value();
	text = text + "&duration=" + std::to_string(duration.value());
	text = text + "&length=" + std::to_string(length.value());
	curl = curl_easy_init();
	if (mime_thumb.value() != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb");
			curl_mime_filedata(field, thumb.value().c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb=");
			curl_mime_data(field, "thumb", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
		}
	}
	else {
		text = text + "&thumb=" + thumb.value();
	}
	if (disable_notification.value()) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id.value());
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup.value();
	if (mime_type != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "video_note");
			curl_mime_filedata(field, video_note.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "video_note=");
			curl_mime_data(field, "video_note", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
			std::string toSend = generalToken + "/sendVideoNote" + text;
			curl_easy_setopt(curl, CURLOPT_URL, toSend.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
			curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_mime_free(form);
			curl_slist_free_all(headerlist);
		}
	}
	else {
		text = text + "&video_note=" + video_note;
		std::string tosend = generalToken + "/sendVideoNote" + text;
		sendQuery(tosend);
	}
}
inline void TelegramTypes::API::sendVideo(const std::string& chat_id, const std::string& mime_type, const std::string& video, const std::optional<__int64>& duration, const std::optional<__int64>& width, const std::optional<__int64>& height, const std::optional<std::string>& mime_thumb, const std::optional<std::string>& thumb, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<bool>& supports_streaming, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<std::string>& reply_markup)
{
	CURL* curl;
	CURLcode res;
	curl_mime* form = NULL;
	curl_mimepart* field = NULL;
	struct curl_slist* headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption.value();
	text = text + "&parse_mode=" + parse_mode.value();
	text = text + "&duration=" + std::to_string(duration.value());
	text = text + "&width=" + std::to_string(width.value());
	text = text + "&height=" + std::to_string(height.value());
	if (supports_streaming.value()) {
		text = text + "&supports_streaming=true";
	}
	else {
		text = text + "&supports_streaming=false";
	}
	curl = curl_easy_init();
	if (mime_thumb.value() != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb");
			curl_mime_filedata(field, thumb.value().c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb=");
			curl_mime_data(field, "thumb", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
		}
	}
	else {
		text = text + "&thumb=" + thumb.value();
	}
	if (disable_notification.value()) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id.value());
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup.value();
	if (mime_type != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "video");
			curl_mime_filedata(field, video.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "video=");
			curl_mime_data(field, "video", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
			std::string toSend = generalToken + "/sendVideo" + text;
			curl_easy_setopt(curl, CURLOPT_URL, toSend.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
			curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_mime_free(form);
			curl_slist_free_all(headerlist);
		}
	}
	else {
		text = text + "&video=" + video;
		std::string tosend = generalToken + "/sendVideo" + text;
		sendQuery(tosend);
	}
}
inline void TelegramTypes::API::sendMediaGroup(const std::string& chat_id, const std::string& mime_type, const std::vector<std::shared_ptr<InputMediaPhoto>>& media, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id)
{
	CURL* curl;
	CURLcode res;
	curl_mime* form = NULL;
	curl_mimepart* field = NULL;
	struct curl_slist* headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	curl = curl_easy_init();
	if (disable_notification.value()) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id.value());
	std::string readBuffer;
	if (mime_type != "") {
		text = text + "&media=[";
		for (__int64 i = 0; i < media.size(); i++) {
			text = text + "{\"type\": \"" + media.at(i)->type + "\", \"caption\": \"" + media.at(i)->caption + "\"" + ", \"parse_mode\": \"" + media.at(i)->parse_mode;
			if (i == media.size() - 1) {
				text = text + "\", \"media\": \"attach://photo_" + std::to_string(i) + "\"}]";
			}
			else {
				text = text + "\", \"media\": \"attach://photo_" + std::to_string(i) + "\"}, ";
			}
		}
		if (curl) {
			form = curl_mime_init(curl);
			for (__int64 i = 0; i < media.size(); i++) {
				field = curl_mime_addpart(form);
				curl_mime_name(field, ("photo_" + std::to_string(i)).c_str());
				curl_mime_filedata(field, media.at(i)->media.c_str());
				field = curl_mime_addpart(form);
				curl_mime_name(field, "media=");
				curl_mime_data(field, ("photo_" + std::to_string(i)).c_str(), CURL_ZERO_TERMINATED);
			}
			headerlist = curl_slist_append(headerlist, buf);
			std::string toSend = generalToken + "/sendMediaGroup" + text;
			curl_easy_setopt(curl, CURLOPT_URL, toSend.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
			curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_mime_free(form);
			curl_slist_free_all(headerlist);
		}
	}
	else {
		text = text + "&media=[";
		for (__int64 i = 0; i < media.size(); i++) {
			if (i == media.size() - 1) {
				text = text + "{\"type\": \"" + media.at(i)->type + "\", \"caption\": \"" + media.at(i)->caption + "\", \"parse_mode\": \"" + media.at(i)->parse_mode + "\", \"media\": \"" + media.at(i)->media + "\"}]";
			}
			else {
				text = text + "{\"type\": \"" + media.at(i)->type + "\", \"caption\": \"" + media.at(i)->caption + "\", \"parse_mode\": \"" + media.at(i)->parse_mode + "\", \"media\": \"" + media.at(i)->media + "\"}, ";
			}
		}
		std::string tosend = generalToken + "/sendMediaGroup" + text;
		sendQuery(tosend);
	}
}
inline void TelegramTypes::API::sendMediaGroup(const std::string& chat_id, const std::string& mime_type, const std::vector<std::shared_ptr<InputMediaVideo>>& media, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id)
{
	CURL* curl;
	CURLcode res;
	curl_mime* form = NULL;
	curl_mimepart* field = NULL;
	struct curl_slist* headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	curl = curl_easy_init();
	if (disable_notification.value()) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id.value());
	std::string readBuffer;
	if (mime_type != "") {
		text = text + "&media=[";
		for (__int64 i = 0; i < media.size(); i++) {
			text = text + "{\"type\": \"" + media.at(i)->type + "\", \"caption\": \"" + media.at(i)->caption + "\"" + ", \"parse_mode\": \"" + media.at(i)->parse_mode;
			if (i == media.size() - 1) {
				text = text + "\", \"media\": \"attach://photo_" + std::to_string(i) + "\"}]";
			}
			else {
				text = text + "\", \"media\": \"attach://photo_" + std::to_string(i) + "\"}, ";
			}
		}
		if (curl) {
			form = curl_mime_init(curl);
			for (__int64 i = 0; i < media.size(); i++) {
				field = curl_mime_addpart(form);
				curl_mime_name(field, ("photo_" + std::to_string(i)).c_str());
				curl_mime_filedata(field, media.at(i)->media.c_str());
				field = curl_mime_addpart(form);
				curl_mime_name(field, "media=");
				curl_mime_data(field, ("photo_" + std::to_string(i)).c_str(), CURL_ZERO_TERMINATED);
			}
			headerlist = curl_slist_append(headerlist, buf);
			std::string toSend = generalToken + "/sendMediaGroup" + text;
			curl_easy_setopt(curl, CURLOPT_URL, toSend.c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
			curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK)
				fprintf(stderr, "curl_easy_perform() failed: %s\n",
					curl_easy_strerror(res));
			curl_easy_cleanup(curl);
			curl_mime_free(form);
			curl_slist_free_all(headerlist);
		}
	}
	else {
		text = text + "&media=[";
		for (__int64 i = 0; i < media.size(); i++) {
			if (i == media.size() - 1) {
				text = text + "{\"type\": \"" + media.at(i)->type + "\", \"caption\": \"" + media.at(i)->caption + "\", \"parse_mode\": \"" + media.at(i)->parse_mode + "\", \"media\": \"" + media.at(i)->media + "\"}]";
			}
			else {
				text = text + "{\"type\": \"" + media.at(i)->type + "\", \"caption\": \"" + media.at(i)->caption + "\", \"parse_mode\": \"" + media.at(i)->parse_mode + "\", \"media\": \"" + media.at(i)->media + "\"}, ";
			}
		}
		std::string tosend = generalToken + "/sendMediaGroup" + text;
		sendQuery(tosend);
	}
}
inline void TelegramTypes::API::copyMessage(const Json::Value& from_chat_id, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<__int64>& message_id, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<bool>& allow_sending_without_reply, const std::optional<Json::Value>& caption_entities) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, from_chat_id);
	text = text + "from_chat_id=" + "[" + result + "]&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (message_id.has_value()) {
		text = text + "message_id=" + std::to_string(message_id.value()) + "&";
	}
	if (disable_notification.has_value()) {
		if (disable_notification.value()) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	if (reply_to_message_id.has_value()) {
		text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id.value()) + "&";
	}
	if (allow_sending_without_reply.has_value()) {
		if (allow_sending_without_reply.value()) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/copyMessage?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendLocation(const float& latitude, const float& longitude, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup, const std::optional<__int64>& live_period, const std::optional<float>& horizontal_accuracy, const std::optional<__int64>& proximity_alert_radius, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<bool>& allow_sending_without_reply, const std::optional<__int64>& heading) {
	std::string text;
	text = "";
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	if (live_period.has_value()) {
		text = text + "live_period=" + std::to_string(live_period.value()) + "&";
	}
	if (horizontal_accuracy.has_value()) {
		text = text + "=" + std::to_string(horizontal_accuracy.value()) + "&";
	}
	if (proximity_alert_radius.has_value()) {
		text = text + "proximity_alert_radius=" + std::to_string(proximity_alert_radius.value()) + "&";
	}
	if (disable_notification.has_value()) {
		if (disable_notification.value()) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	if (reply_to_message_id.has_value()) {
		text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id.value()) + "&";
	}
	if (allow_sending_without_reply.has_value()) {
		if (allow_sending_without_reply.value()) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}
	if (heading.has_value()) {
		text = text + "heading=" + std::to_string(heading.value()) + "&";
	}
	std::string tosend = generalToken + "/sendLocation?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::editMessageLiveLocation(const float& latitude, const float& longitude, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& inline_message_id, const std::optional<__int64>& message_id, const std::optional<float>& horizontal_accuracy, const std::optional<__int64>& heading, const std::optional<__int64>& proximity_alert_radius, const std::optional<Json::Value>& chat_id) {
	std::string text;
	text = "";
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	if (inline_message_id.has_value()) {
		text = text + "inline_message_id=" + inline_message_id.value() + "&";
	}
	if (message_id.has_value()) {
		text = text + "message_id=" + std::to_string(message_id.value()) + "&";
	}
	if (horizontal_accuracy.has_value()) {
		text = text + "=" + std::to_string(horizontal_accuracy.value()) + "&";
	}
	if (heading.has_value()) {
		text = text + "heading=" + std::to_string(heading.value()) + "&";
	}
	if (proximity_alert_radius.has_value()) {
		text = text + "proximity_alert_radius=" + std::to_string(proximity_alert_radius.value()) + "&";
	}
	if (chat_id.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, chat_id.value());
		text = text + "chat_id=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/editMessageLiveLocation?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::stopMessageLiveLocation(const std::optional<Json::Value>& chat_id, const std::optional<__int64>& message_id, const std::optional<std::string>& inline_message_id, const std::optional<Json::Value>& reply_markup) {
	std::string text;
	text = "";
	if (chat_id.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, chat_id.value());
		text = text + "chat_id=" + "[" + result + "]" + "&";
	}
	if (message_id.has_value()) {
		text = text + "message_id=" + std::to_string(message_id.value()) + "&";
	}
	if (inline_message_id.has_value()) {
		text = text + "inline_message_id=" + inline_message_id.value() + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/stopMessageLiveLocation?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendVenue(const float& latitude, const float& longitude, const std::string& title, const std::string& address, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& foursquare_id, const std::optional<std::string>& google_place_id, const std::optional<std::string>& google_place_type, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<bool>& allow_sending_without_reply, const std::optional<std::string>& foursquare_type) {
	std::string text;
	text = "";
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";
	text = text + "title=" + title + "&";
	text = text + "address=" + address + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	if (foursquare_id.has_value()) {
		text = text + "foursquare_id=" + foursquare_id.value() + "&";
	}
	if (google_place_id.has_value()) {
		text = text + "google_place_id=" + google_place_id.value() + "&";
	}
	if (google_place_type.has_value()) {
		text = text + "google_place_type=" + google_place_type.value() + "&";
	}
	if (disable_notification.has_value()) {
		if (disable_notification.value()) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	if (reply_to_message_id.has_value()) {
		text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id.value()) + "&";
	}
	if (allow_sending_without_reply.has_value()) {
		if (allow_sending_without_reply.value()) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}
	if (foursquare_type.has_value()) {
		text = text + "foursquare_type=" + foursquare_type.value() + "&";
	}
	std::string tosend = generalToken + "/sendVenue?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendContact(const std::string& phone_number, const std::string& first_name, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& last_name, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<bool>& allow_sending_without_reply, const std::optional<std::string>& vcard) {
	std::string text;
	text = "";
	text = text + "phone_number=" + phone_number + "&";
	text = text + "first_name=" + first_name + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	if (last_name.has_value()) {
		text = text + "last_name=" + last_name.value() + "&";
	}
	if (disable_notification.has_value()) {
		if (disable_notification.value()) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	if (reply_to_message_id.has_value()) {
		text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id.value()) + "&";
	}
	if (allow_sending_without_reply.has_value()) {
		if (allow_sending_without_reply.value()) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}
	if (vcard.has_value()) {
		text = text + "vcard=" + vcard.value() + "&";
	}
	std::string tosend = generalToken + "/sendContact?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendPoll(const std::string& question, const Json::Value& options, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& explanation_parse_mode, const std::optional<__int64>& open_period, const std::optional<std::string>& type, const std::optional<__int64>& close_date, const std::optional<__int64>& correct_option_id, const std::optional<bool>& is_closed, const std::optional<bool>& allows_multiple_answers, const std::optional<std::string>& explanation, const std::optional<Json::Value>& explanation_entities, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<bool>& allow_sending_without_reply, const std::optional<bool>& is_anonymous) {
	std::string text;
	text = "";
	text = text + "question=" + question + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, options);
	text = text + "options=" + "[" + result + "]&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	if (explanation_parse_mode.has_value()) {
		text = text + "explanation_parse_mode=" + explanation_parse_mode.value() + "&";
	}
	if (open_period.has_value()) {
		text = text + "open_period=" + std::to_string(open_period.value()) + "&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	if (close_date.has_value()) {
		text = text + "close_date=" + std::to_string(close_date.value()) + "&";
	}
	if (correct_option_id.has_value()) {
		text = text + "correct_option_id=" + std::to_string(correct_option_id.value()) + "&";
	}
	if (is_closed.has_value()) {
		if (is_closed.value()) {
			text = text + "is_closed=true&";
		}
		else {
			text = text + "is_closed=false&";
		}
	}
	if (allows_multiple_answers.has_value()) {
		if (allows_multiple_answers.value()) {
			text = text + "allows_multiple_answers=true&";
		}
		else {
			text = text + "allows_multiple_answers=false&";
		}
	}
	if (explanation.has_value()) {
		text = text + "explanation=" + explanation.value() + "&";
	}
	if (explanation_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, explanation_entities.value());
		text = text + "explanation_entities=" + "[" + result + "]" + "&";
	}
	if (disable_notification.has_value()) {
		if (disable_notification.value()) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	if (reply_to_message_id.has_value()) {
		text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id.value()) + "&";
	}
	if (allow_sending_without_reply.has_value()) {
		if (allow_sending_without_reply.value()) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}
	if (is_anonymous.has_value()) {
		if (is_anonymous.value()) {
			text = text + "is_anonymous=true&";
		}
		else {
			text = text + "is_anonymous=false&";
		}
	}
	std::string tosend = generalToken + "/sendPoll?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendDice(const Json::Value& chat_id, const std::optional<std::string>& emoji, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<bool>& allow_sending_without_reply, const std::optional<Json::Value>& reply_markup) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (emoji.has_value()) {
		text = text + "emoji=" + emoji.value() + "&";
	}
	if (disable_notification.has_value()) {
		if (disable_notification.value()) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	if (reply_to_message_id.has_value()) {
		text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id.value()) + "&";
	}
	if (allow_sending_without_reply.has_value()) {
		if (allow_sending_without_reply.value()) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/sendDice?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendChatAction(const Json::Value& chat_id, const std::optional<std::string>& action) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (action.has_value()) {
		text = text + "action=" + action.value() + "&";
	}
	std::string tosend = generalToken + "/sendChatAction?" + text;
	sendQuery(tosend);
}
inline Json::Value TelegramTypes::API::getUserProfilePhotos(const __int64& user_id, const std::optional<__int64>& offset, const std::optional<__int64>& limit) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	if (offset.has_value()) {
		text = text + "offset=" + std::to_string(offset.value()) + "&";
	}
	if (limit.has_value()) {
		text = text + "limit=" + std::to_string(limit.value()) + "&";
	}
	std::string tosend = generalToken + "/getUserProfilePhotos?" + text;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, tosend.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return Json::Value(readBuffer);
}
inline Json::Value TelegramTypes::API::getFile(const std::string& file_id) {
	std::string text;
	text = "";
	text = text + "file_id=" + file_id + "&";
	std::string tosend = generalToken + "/getFile?" + text;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, tosend.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return Json::Value(readBuffer);
}
inline void TelegramTypes::API::kickChatMember(const __int64& user_id, const Json::Value& chat_id, const std::optional<__int64>& until_date) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (until_date.has_value()) {
		text = text + "until_date=" + std::to_string(until_date.value()) + "&";
	}
	std::string tosend = generalToken + "/kickChatMember?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::unbanChatMember(const __int64& user_id, const Json::Value& chat_id, const std::optional<bool>& only_if_banned) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (only_if_banned.has_value()) {
		if (only_if_banned.value()) {
			text = text + "only_if_banned=true&";
		}
		else {
			text = text + "only_if_banned=false&";
		}
	}
	std::string tosend = generalToken + "/unbanChatMember?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::restrictChatMember(const __int64& user_id, const Json::Value& permissions, const Json::Value& chat_id, const std::optional<__int64>& until_date) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, permissions);
	text = text + "permissions=" + "[" + result + "]&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (until_date.has_value()) {
		text = text + "until_date=" + std::to_string(until_date.value()) + "&";
	}
	std::string tosend = generalToken + "/restrictChatMember?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::promoteChatMember(const __int64& user_id, const Json::Value& chat_id, const std::optional<bool>& can_promote_members, const std::optional<bool>& can_change_info, const std::optional<bool>& can_post_messages, const std::optional<bool>& is_anonymous, const std::optional<bool>& can_delete_messages, const std::optional<bool>& can_invite_users, const std::optional<bool>& can_restrict_members, const std::optional<bool>& can_pin_messages, const std::optional<bool>& can_edit_messages) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (can_promote_members.has_value()) {
		if (can_promote_members.value()) {
			text = text + "can_promote_members=true&";
		}
		else {
			text = text + "can_promote_members=false&";
		}
	}
	if (can_change_info.has_value()) {
		if (can_change_info.value()) {
			text = text + "can_change_info=true&";
		}
		else {
			text = text + "can_change_info=false&";
		}
	}
	if (can_post_messages.has_value()) {
		if (can_post_messages.value()) {
			text = text + "can_post_messages=true&";
		}
		else {
			text = text + "can_post_messages=false&";
		}
	}
	if (is_anonymous.has_value()) {
		if (is_anonymous.value()) {
			text = text + "is_anonymous=true&";
		}
		else {
			text = text + "is_anonymous=false&";
		}
	}
	if (can_delete_messages.has_value()) {
		if (can_delete_messages.value()) {
			text = text + "can_delete_messages=true&";
		}
		else {
			text = text + "can_delete_messages=false&";
		}
	}
	if (can_invite_users.has_value()) {
		if (can_invite_users.value()) {
			text = text + "can_invite_users=true&";
		}
		else {
			text = text + "can_invite_users=false&";
		}
	}
	if (can_restrict_members.has_value()) {
		if (can_restrict_members.value()) {
			text = text + "can_restrict_members=true&";
		}
		else {
			text = text + "can_restrict_members=false&";
		}
	}
	if (can_pin_messages.has_value()) {
		if (can_pin_messages.value()) {
			text = text + "can_pin_messages=true&";
		}
		else {
			text = text + "can_pin_messages=false&";
		}
	}
	if (can_edit_messages.has_value()) {
		if (can_edit_messages.value()) {
			text = text + "can_edit_messages=true&";
		}
		else {
			text = text + "can_edit_messages=false&";
		}
	}
	std::string tosend = generalToken + "/promoteChatMember?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setChatAdministratorCustomTitle(const __int64& user_id, const std::string& custom_title, const Json::Value& chat_id) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "custom_title=" + custom_title + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/setChatAdministratorCustomTitle?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setChatPermissions(const Json::Value& permissions, const Json::Value& chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, permissions);
	text = text + "permissions=" + "[" + result + "]&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/setChatPermissions?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::exportChatInviteLink(const Json::Value& chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/exportChatInviteLink?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setChatPhoto(const Json::Value& photo, const Json::Value& chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, photo);
	text = text + "photo=" + "[" + result + "]&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/setChatPhoto?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::deleteChatPhoto(const Json::Value& chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/deleteChatPhoto?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setChatTitle(const std::string& title, const Json::Value& chat_id) {
	std::string text;
	text = "";
	text = text + "title=" + title + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/setChatTitle?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setChatDescription(const Json::Value& chat_id, const std::optional<std::string>& description) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (description.has_value()) {
		text = text + "description=" + description.value() + "&";
	}
	std::string tosend = generalToken + "/setChatDescription?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::pinChatMessage(const __int64& message_id, const Json::Value& chat_id, const std::optional<bool>& disable_notification) {
	std::string text;
	text = "";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (disable_notification.has_value()) {
		if (disable_notification.value()) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	std::string tosend = generalToken + "/pinChatMessage?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::unpinChatMessage(const Json::Value& chat_id, const std::optional<__int64>& message_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (message_id.has_value()) {
		text = text + "message_id=" + std::to_string(message_id.value()) + "&";
	}
	std::string tosend = generalToken + "/unpinChatMessage?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::unpinAllChatMessages(const Json::Value& chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/unpinAllChatMessages?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::leaveChat(const Json::Value& chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/leaveChat?" + text;
	sendQuery(tosend);
}
inline Json::Value TelegramTypes::API::getChat(const std::string& chat_id) {
	std::string text;
	text = "";
	text = text + "chat_id=" + "" + chat_id + "&";
	std::string tosend = generalToken + "/getChat?" + text;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, tosend.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return Json::Value(readBuffer);
}
inline Json::Value TelegramTypes::API::getChatAdministrators(const Json::Value& chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/getChatAdministrators?" + text;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, tosend.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return Json::Value(readBuffer);
}
inline Json::Value TelegramTypes::API::getChatMembersCount(const Json::Value& chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/getChatMembersCount?" + text;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, tosend.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return Json::Value(readBuffer);
}
inline Json::Value TelegramTypes::API::getChatMember(const __int64& user_id, const Json::Value& chat_id) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/getChatMember?" + text;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, tosend.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return Json::Value(readBuffer);
}
inline void TelegramTypes::API::setChatStickerSet(const std::string& sticker_set_name, const Json::Value& chat_id) {
	std::string text;
	text = "";
	text = text + "sticker_set_name=" + sticker_set_name + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/setChatStickerSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::deleteChatStickerSet(const Json::Value& chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/deleteChatStickerSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::answerCallbackQuery(const std::string& callback_query_id, const std::optional<std::string>& text, const std::optional<bool>& show_alert, const std::optional<std::string>& url, const std::optional<__int64>& cache_time) {
	std::string text1;
	text1 = "";
	text1 = text1 + "callback_query_id=" + callback_query_id + "&";
	if (text.has_value()) {
		text1 = text1 + "text=" + text.value() + "&";
	}
	if (show_alert.has_value()) {
		if (show_alert.value()) {
			text1 = text1 + "show_alert=true&";
		}
		else {
			text1 = text1 + "show_alert=false&";
		}
	}
	if (url.has_value()) {
		text1 = text1 + "url=" + url.value() + "&";
	}
	if (cache_time.has_value()) {
		text1 = text1 + "cache_time=" + std::to_string(cache_time.value()) + "&";
	}
	std::string tosend = generalToken + "/answerCallbackQuery?" + text1;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setMyCommands(const Json::Value& commands) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, commands);
	text = text + "commands=" + "[" + result + "]&";
	std::string tosend = generalToken + "/setMyCommands?" + text;
	sendQuery(tosend);
}
inline Json::Value TelegramTypes::API::getMyCommands(const std::string& text, const std::optional<Json::Value>& chat_id, const std::optional<__int64>& message_id, const std::optional<std::string>& inline_message_id, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& entities, const std::optional<bool>& disable_web_page_preview, const std::optional<Json::Value>& reply_markup) {
	std::string text1;
	text1 = "";
	text1 = text1 + "text=" + text + "&";
	if (chat_id.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, chat_id.value());
		text1 = text1 + "chat_id=" + "[" + result + "]" + "&";
	}
	if (message_id.has_value()) {
		text1 = text1 + "message_id=" + std::to_string(message_id.value()) + "&";
	}
	if (inline_message_id.has_value()) {
		text1 = text1 + "inline_message_id=" + inline_message_id.value() + "&";
	}
	if (parse_mode.has_value()) {
		text1 = text1 + "parse_mode=" + parse_mode.value() + "&";
	}
	if (entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, entities.value());
		text1 = text1 + "entities=" + "[" + result + "]" + "&";
	}
	if (disable_web_page_preview.has_value()) {
		if (disable_web_page_preview.value()) {
			text1 = text1 + "disable_web_page_preview=true&";
		}
		else {
			text1 = text1 + "disable_web_page_preview=false&";
		}
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text1 = text1 + "reply_markup=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/getMyCommands?" + text1;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, tosend.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return Json::Value(readBuffer);
}
inline void TelegramTypes::API::editMessageCaption(const std::optional<Json::Value>& chat_id, const std::optional<__int64>& message_id, const std::optional<std::string>& inline_message_id, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup) {
	std::string text;
	text = "";
	if (chat_id.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, chat_id.value());
		text = text + "chat_id=" + "[" + result + "]" + "&";
	}
	if (message_id.has_value()) {
		text = text + "message_id=" + std::to_string(message_id.value()) + "&";
	}
	if (inline_message_id.has_value()) {
		text = text + "inline_message_id=" + inline_message_id.value() + "&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]" + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/editMessageCaption?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::editMessageMedia(const Json::Value& media, const std::optional<Json::Value>& chat_id, const std::optional<__int64>& message_id, const std::optional<std::string>& inline_message_id, const std::optional<Json::Value>& reply_markup) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, media);
	text = text + "media=" + "[" + result + "]&";
	if (chat_id.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, chat_id.value());
		text = text + "chat_id=" + "[" + result + "]" + "&";
	}
	if (message_id.has_value()) {
		text = text + "message_id=" + std::to_string(message_id.value()) + "&";
	}
	if (inline_message_id.has_value()) {
		text = text + "inline_message_id=" + inline_message_id.value() + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/editMessageMedia?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::editMessageReplyMarkup(const std::optional<Json::Value>& chat_id, const std::optional<__int64>& message_id, const std::optional<std::string>& inline_message_id, const std::optional<Json::Value>& reply_markup) {
	std::string text;
	text = "";
	if (chat_id.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, chat_id.value());
		text = text + "chat_id=" + "[" + result + "]" + "&";
	}
	if (message_id.has_value()) {
		text = text + "message_id=" + std::to_string(message_id.value()) + "&";
	}
	if (inline_message_id.has_value()) {
		text = text + "inline_message_id=" + inline_message_id.value() + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/editMessageReplyMarkup?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::stopPoll(const __int64& message_id, const Json::Value& chat_id, const std::optional<Json::Value>& reply_markup) {
	std::string text;
	text = "";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/stopPoll?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::deleteMessage(const __int64& message_id, const Json::Value& chat_id) {
	std::string text;
	text = "";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	std::string tosend = generalToken + "/deleteMessage?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::StickerSet(const std::string& title, const Json::Value& stickers, const std::string& name, const std::optional<bool>& is_animated, const std::optional<bool>& contains_masks, const std::optional<Json::Value>& thumb) {
	std::string text;
	text = "";
	text = text + "title=" + title + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, stickers);
	text = text + "stickers=" + "[" + result + "]&";
	text = text + "name=" + name + "&";
	if (is_animated.has_value()) {
		if (is_animated.value()) {
			text = text + "is_animated=true&";
		}
		else {
			text = text + "is_animated=false&";
		}
	}
	if (contains_masks.has_value()) {
		if (contains_masks.value()) {
			text = text + "contains_masks=true&";
		}
		else {
			text = text + "contains_masks=false&";
		}
	}
	if (thumb.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, thumb.value());
		text = text + "thumb=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/StickerSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::MaskPosition(const float& x_shift, const float& y_shift, const float& scale, const std::string& point) {
	std::string text;
	text = "";
	text = text + "=" + std::to_string(x_shift) + "&";
	text = text + "=" + std::to_string(y_shift) + "&";
	text = text + "=" + std::to_string(scale) + "&";
	text = text + "point=" + point + "&";
	std::string tosend = generalToken + "/MaskPosition?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendSticker(const Json::Value& sticker, const Json::Value& chat_id, const std::optional<bool>& disable_notification, const std::optional<__int64>& reply_to_message_id, const std::optional<bool>& allow_sending_without_reply, const std::optional<Json::Value>& reply_markup) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, sticker);
	text = text + "sticker=" + "[" + result + "]&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, chat_id);
	text = text + "chat_id=" + "[" + result + "]&";
	if (disable_notification.has_value()) {
		if (disable_notification.value()) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	if (reply_to_message_id.has_value()) {
		text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id.value()) + "&";
	}
	if (allow_sending_without_reply.has_value()) {
		if (allow_sending_without_reply.value()) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/sendSticker?" + text;
	sendQuery(tosend);
}
inline Json::Value TelegramTypes::API::getStickerSet(const std::string& name) {
	std::string text;
	text = "";
	text = text + "name=" + name + "&";
	std::string tosend = generalToken + "/getStickerSet?" + text;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, tosend.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return Json::Value(readBuffer);
}
inline void TelegramTypes::API::uploadStickerFile(const Json::Value& png_sticker, const __int64& user_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, png_sticker);
	text = text + "png_sticker=" + "[" + result + "]&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string tosend = generalToken + "/uploadStickerFile?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::createNewStickerSet(const std::string& emojis, const std::string& title, const __int64& user_id, const std::optional<std::string>& name, const std::optional<Json::Value>& png_sticker, const std::optional<Json::Value>& tgs_sticker, const std::optional<bool>& contains_masks, const std::optional<Json::Value>& mask_position) {
	std::string text;
	text = "";
	text = text + "emojis=" + emojis + "&";
	text = text + "title=" + title + "&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	if (name.has_value()) {
		text = text + "name=" + name.value() + "&";
	}
	if (png_sticker.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, png_sticker.value());
		text = text + "png_sticker=" + "[" + result + "]" + "&";
	}
	if (tgs_sticker.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, tgs_sticker.value());
		text = text + "tgs_sticker=" + "[" + result + "]" + "&";
	}
	if (contains_masks.has_value()) {
		if (contains_masks.value()) {
			text = text + "contains_masks=true&";
		}
		else {
			text = text + "contains_masks=false&";
		}
	}
	if (mask_position.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, mask_position.value());
		text = text + "mask_position=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/createNewStickerSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::addStickerToSet(const std::string& name, const std::string& emojis, const __int64& user_id, const std::optional<Json::Value>& png_sticker, const std::optional<Json::Value>& tgs_sticker, const std::optional<Json::Value>& mask_position) {
	std::string text;
	text = "";
	text = text + "name=" + name + "&";
	text = text + "emojis=" + emojis + "&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	if (png_sticker.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, png_sticker.value());
		text = text + "png_sticker=" + "[" + result + "]" + "&";
	}
	if (tgs_sticker.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, tgs_sticker.value());
		text = text + "tgs_sticker=" + "[" + result + "]" + "&";
	}
	if (mask_position.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, mask_position.value());
		text = text + "mask_position=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/addStickerToSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setStickerPositionInSet(const __int64& position, const std::string& sticker) {
	std::string text;
	text = "";
	text = text + "position=" + std::to_string(position) + "&";
	text = text + "sticker=" + sticker + "&";
	std::string tosend = generalToken + "/setStickerPositionInSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::deleteStickerFromSet(const std::string& sticker) {
	std::string text;
	text = "";
	text = text + "sticker=" + sticker + "&";
	std::string tosend = generalToken + "/deleteStickerFromSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setStickerSetThumb(const __int64& user_id, const std::string& name, const std::optional<Json::Value>& thumb) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "name=" + name + "&";
	if (thumb.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, thumb.value());
		text = text + "thumb=" + "[" + result + "]" + "&";
	}
	std::string tosend = generalToken + "/setStickerSetThumb?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendQuery(std::string& query)
{
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, query.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	if (readBuffer.find("\"ok\":false") != std::string::npos) {
		throw readBuffer;
	}
}
inline void TelegramTypes::API::answerInlineQuery(const Json::Value& results, const std::string& inline_query_id, const std::optional<__int64>& cache_time, const std::optional<bool>& is_personal, const std::optional<std::string>& next_offset, const std::optional<std::string>& switch_pm_text, const std::optional<std::string>& switch_pm_parameter) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, results);
	text = text + "results=" + "[" + result + "]&";
	text = text + "inline_query_id=" + inline_query_id + "&";
	if (cache_time.has_value()) {
		text = text + "cache_time=" + std::to_string(cache_time.value()) + "&";
	}
	if (is_personal.has_value()) {
		if (is_personal.value()) {
			text = text + "is_personal=true&";
		}
		else {
			text = text + "is_personal=false&";
		}
	}
	if (next_offset.has_value()) {
		text = text + "next_offset=" + next_offset.value() + "&";
	}
	if (switch_pm_text.has_value()) {
		text = text + "switch_pm_text=" + switch_pm_text.value() + "&";
	}
	if (switch_pm_parameter.has_value()) {
		text = text + "switch_pm_parameter=" + switch_pm_parameter.value() + "&";
	}
	std::string tosend = generalToken + "/answerInlineQuery?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResult(const std::string& id, const std::string& title, const Json::Value& input_message_content, const std::optional<__int64>& thumb_height, const std::optional<std::string>& url, const std::optional<Json::Value>& reply_markup, const std::optional<bool>& hide_url, const std::optional<std::string>& description, const std::optional<std::string>& thumb_url, const std::optional<__int64>& thumb_width, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "title=" + title + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, input_message_content);
	text = text + "input_message_content=" + "[" + result + "]&";
	if (thumb_height.has_value()) {
		text = text + "thumb_height=" + std::to_string(thumb_height.value()) + "&";
	}
	if (url.has_value()) {
		text = text + "url=" + url.value() + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (hide_url.has_value()) {
		if (hide_url.value()) {
			text = text + "hide_url=true&";
		}
		else {
			text = text + "hide_url=false&";
		}
	}
	if (description.has_value()) {
		text = text + "description=" + description.value() + "&";
	}
	if (thumb_url.has_value()) {
		text = text + "thumb_url=" + thumb_url.value() + "&";
	}
	if (thumb_width.has_value()) {
		text = text + "thumb_width=" + std::to_string(thumb_width.value()) + "&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResult?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultPhoto(const std::string& id, const std::string& photo_url, const std::string& thumb_url, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& title, const std::optional<__int64>& photo_height, const std::optional<__int64>& photo_width, const std::optional<std::string>& description, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "photo_url=" + photo_url + "&";
	text = text + "thumb_url=" + thumb_url + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (title.has_value()) {
		text = text + "title=" + title.value() + "&";
	}
	if (photo_height.has_value()) {
		text = text + "photo_height=" + std::to_string(photo_height.value()) + "&";
	}
	if (photo_width.has_value()) {
		text = text + "photo_width=" + std::to_string(photo_width.value()) + "&";
	}
	if (description.has_value()) {
		text = text + "description=" + description.value() + "&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultPhoto?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultGif(const std::string& id, const std::string& gif_url, const std::string& thumb_url, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& thumb_mime_type, const std::optional<std::string>& type, const std::optional<std::string>& caption, const std::optional<__int64>& gif_width, const std::optional<std::string>& title, const std::optional<__int64>& gif_height, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup, const std::optional<__int64>& gif_duration) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "gif_url=" + gif_url + "&";
	text = text + "thumb_url=" + thumb_url + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (thumb_mime_type.has_value()) {
		text = text + "thumb_mime_type=" + thumb_mime_type.value() + "&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (gif_width.has_value()) {
		text = text + "gif_width=" + std::to_string(gif_width.value()) + "&";
	}
	if (title.has_value()) {
		text = text + "title=" + title.value() + "&";
	}
	if (gif_height.has_value()) {
		text = text + "gif_height=" + std::to_string(gif_height.value()) + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (gif_duration.has_value()) {
		text = text + "gif_duration=" + std::to_string(gif_duration.value()) + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultGif?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultMpeg4Gif(const std::string& id, const std::string& mpeg4_url, const std::string& thumb_url, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& thumb_mime_type, const std::optional<std::string>& type, const std::optional<std::string>& caption, const std::optional<__int64>& mpeg4_width, const std::optional<std::string>& title, const std::optional<__int64>& mpeg4_height, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup, const std::optional<__int64>& mpeg4_duration) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "mpeg4_url=" + mpeg4_url + "&";
	text = text + "thumb_url=" + thumb_url + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (thumb_mime_type.has_value()) {
		text = text + "thumb_mime_type=" + thumb_mime_type.value() + "&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (mpeg4_width.has_value()) {
		text = text + "mpeg4_width=" + std::to_string(mpeg4_width.value()) + "&";
	}
	if (title.has_value()) {
		text = text + "title=" + title.value() + "&";
	}
	if (mpeg4_height.has_value()) {
		text = text + "mpeg4_height=" + std::to_string(mpeg4_height.value()) + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (mpeg4_duration.has_value()) {
		text = text + "mpeg4_duration=" + std::to_string(mpeg4_duration.value()) + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultMpeg4Gif?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultVideo(const std::string& id, const std::string& video_url, const std::string& mime_type, const std::string& thumb_url, const std::string& title, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& parse_mode, const std::optional<std::string>& caption, const std::optional<Json::Value>& caption_entities, const std::optional<__int64>& video_width, const std::optional<__int64>& video_height, const std::optional<__int64>& video_duration, const std::optional<std::string>& description, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "video_url=" + video_url + "&";
	text = text + "mime_type=" + mime_type + "&";
	text = text + "thumb_url=" + thumb_url + "&";
	text = text + "title=" + title + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (video_width.has_value()) {
		text = text + "video_width=" + std::to_string(video_width.value()) + "&";
	}
	if (video_height.has_value()) {
		text = text + "video_height=" + std::to_string(video_height.value()) + "&";
	}
	if (video_duration.has_value()) {
		text = text + "video_duration=" + std::to_string(video_duration.value()) + "&";
	}
	if (description.has_value()) {
		text = text + "description=" + description.value() + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultVideo?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultAudio(const std::string& id, const std::string& audio_url, const std::string& title, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& parse_mode, const std::optional<std::string>& caption, const std::optional<Json::Value>& caption_entities, const std::optional<std::string>& performer, const std::optional<__int64>& audio_duration, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "audio_url=" + audio_url + "&";
	text = text + "title=" + title + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (performer.has_value()) {
		text = text + "performer=" + performer.value() + "&";
	}
	if (audio_duration.has_value()) {
		text = text + "audio_duration=" + std::to_string(audio_duration.value()) + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultAudio?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultVoice(const std::string& id, const std::string& voice_url, const std::string& title, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& parse_mode, const std::optional<std::string>& caption, const std::optional<Json::Value>& caption_entities, const std::optional<__int64>& voice_duration, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "voice_url=" + voice_url + "&";
	text = text + "title=" + title + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (voice_duration.has_value()) {
		text = text + "voice_duration=" + std::to_string(voice_duration.value()) + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultVoice?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultDocument(const std::string& id, const std::string& title, const std::string& document_url, const std::string& mime_type, const std::optional<__int64>& thumb_height, const std::optional<std::string>& type, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& caption, const std::optional<std::string>& description, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& thumb_url, const std::optional<__int64>& thumb_width, const std::optional<Json::Value>& caption_entities) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "title=" + title + "&";
	text = text + "document_url=" + document_url + "&";
	text = text + "mime_type=" + mime_type + "&";
	if (thumb_height.has_value()) {
		text = text + "thumb_height=" + std::to_string(thumb_height.value()) + "&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (description.has_value()) {
		text = text + "description=" + description.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (thumb_url.has_value()) {
		text = text + "thumb_url=" + thumb_url.value() + "&";
	}
	if (thumb_width.has_value()) {
		text = text + "thumb_width=" + std::to_string(thumb_width.value()) + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/InlineQueryResultDocument?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultLocation(const std::string& id, const float& latitude, const float& longitude, const std::string& title, const std::optional<__int64>& thumb_height, const std::optional<__int64>& heading, const std::optional<__int64>& live_period, const std::optional<float>& horizontal_accuracy, const std::optional<__int64>& proximity_alert_radius, const std::optional<Json::Value>& reply_markup, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& thumb_url, const std::optional<__int64>& thumb_width, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";
	text = text + "title=" + title + "&";
	if (thumb_height.has_value()) {
		text = text + "thumb_height=" + std::to_string(thumb_height.value()) + "&";
	}
	if (heading.has_value()) {
		text = text + "heading=" + std::to_string(heading.value()) + "&";
	}
	if (live_period.has_value()) {
		text = text + "live_period=" + std::to_string(live_period.value()) + "&";
	}
	if (horizontal_accuracy.has_value()) {
		text = text + "=" + std::to_string(horizontal_accuracy.value()) + "&";
	}
	if (proximity_alert_radius.has_value()) {
		text = text + "proximity_alert_radius=" + std::to_string(proximity_alert_radius.value()) + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (thumb_url.has_value()) {
		text = text + "thumb_url=" + thumb_url.value() + "&";
	}
	if (thumb_width.has_value()) {
		text = text + "thumb_width=" + std::to_string(thumb_width.value()) + "&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultLocation?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultVenue(const std::string& id, const float& latitude, const float& longitude, const std::string& title, const std::string& address, const std::optional<__int64>& thumb_height, const std::optional<std::string>& foursquare_type, const std::optional<std::string>& foursquare_id, const std::optional<std::string>& google_place_id, const std::optional<std::string>& google_place_type, const std::optional<Json::Value>& reply_markup, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& thumb_url, const std::optional<__int64>& thumb_width, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";
	text = text + "title=" + title + "&";
	text = text + "address=" + address + "&";
	if (thumb_height.has_value()) {
		text = text + "thumb_height=" + std::to_string(thumb_height.value()) + "&";
	}
	if (foursquare_type.has_value()) {
		text = text + "foursquare_type=" + foursquare_type.value() + "&";
	}
	if (foursquare_id.has_value()) {
		text = text + "foursquare_id=" + foursquare_id.value() + "&";
	}
	if (google_place_id.has_value()) {
		text = text + "google_place_id=" + google_place_id.value() + "&";
	}
	if (google_place_type.has_value()) {
		text = text + "google_place_type=" + google_place_type.value() + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (thumb_url.has_value()) {
		text = text + "thumb_url=" + thumb_url.value() + "&";
	}
	if (thumb_width.has_value()) {
		text = text + "thumb_width=" + std::to_string(thumb_width.value()) + "&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultVenue?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultContact(const std::string& id, const std::string& phone_number, const std::string& first_name, const std::optional<__int64>& thumb_height, const std::optional<std::string>& vcard, const std::optional<std::string>& last_name, const std::optional<Json::Value>& reply_markup, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& thumb_url, const std::optional<__int64>& thumb_width, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "phone_number=" + phone_number + "&";
	text = text + "first_name=" + first_name + "&";
	if (thumb_height.has_value()) {
		text = text + "thumb_height=" + std::to_string(thumb_height.value()) + "&";
	}
	if (vcard.has_value()) {
		text = text + "vcard=" + vcard.value() + "&";
	}
	if (last_name.has_value()) {
		text = text + "last_name=" + last_name.value() + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (thumb_url.has_value()) {
		text = text + "thumb_url=" + thumb_url.value() + "&";
	}
	if (thumb_width.has_value()) {
		text = text + "thumb_width=" + std::to_string(thumb_width.value()) + "&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultContact?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultGame(const std::string& id, const std::string& game_short_name, const std::optional<std::string>& type, const std::optional<Json::Value>& reply_markup) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "game_short_name=" + game_short_name + "&";
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/InlineQueryResultGame?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultCachedPhoto(const std::string& id, const std::string& photo_file_id, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& caption, const std::optional<std::string>& description, const std::optional<std::string>& title, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "photo_file_id=" + photo_file_id + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (description.has_value()) {
		text = text + "description=" + description.value() + "&";
	}
	if (title.has_value()) {
		text = text + "title=" + title.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultCachedPhoto?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultCachedGif(const std::string& id, const std::string& gif_file_id, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& caption, const std::optional<std::string>& title, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "gif_file_id=" + gif_file_id + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (title.has_value()) {
		text = text + "title=" + title.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultCachedGif?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultCachedMpeg4Gif(const std::string& id, const std::string& mpeg4_file_id, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& caption, const std::optional<std::string>& title, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "mpeg4_file_id=" + mpeg4_file_id + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (title.has_value()) {
		text = text + "title=" + title.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultCachedMpeg4Gif?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultCachedSticker(const std::string& id, const std::string& sticker_file_id, const std::optional<std::string>& type, const std::optional<Json::Value>& reply_markup, const std::optional<Json::Value>& input_message_content) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "sticker_file_id=" + sticker_file_id + "&";
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/InlineQueryResultCachedSticker?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultCachedDocument(const std::string& id, const std::string& title, const std::string& document_file_id, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& caption, const std::optional<std::string>& description, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "title=" + title + "&";
	text = text + "document_file_id=" + document_file_id + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (description.has_value()) {
		text = text + "description=" + description.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultCachedDocument?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultCachedVideo(const std::string& id, const std::string& video_file_id, const std::string& title, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& caption, const std::optional<std::string>& description, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "video_file_id=" + video_file_id + "&";
	text = text + "title=" + title + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (description.has_value()) {
		text = text + "description=" + description.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultCachedVideo?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultCachedVoice(const std::string& id, const std::string& voice_file_id, const std::string& title, const std::optional<Json::Value>& input_message_content, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup, const std::optional<std::string>& type) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "voice_file_id=" + voice_file_id + "&";
	text = text + "title=" + title + "&";
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	std::string tosend = generalToken + "/InlineQueryResultCachedVoice?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InlineQueryResultCachedAudio(const std::string& id, const std::string& audio_file_id, const std::optional<std::string>& type, const std::optional<std::string>& caption, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& caption_entities, const std::optional<Json::Value>& reply_markup, const std::optional<Json::Value>& input_message_content) {
	std::string text;
	text = "";
	text = text + "id=" + id + "&";
	text = text + "audio_file_id=" + audio_file_id + "&";
	if (type.has_value()) {
		text = text + "type=" + type.value() + "&";
	}
	if (caption.has_value()) {
		text = text + "caption=" + caption.value() + "&";
	}
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (caption_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, caption_entities.value());
		text = text + "caption_entities=" + "[" + result + "]&";
	}
	if (reply_markup.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reply_markup.value());
		text = text + "reply_markup=" + "[" + result + "]&";
	}
	if (input_message_content.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, input_message_content.value());
		text = text + "input_message_content=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/InlineQueryResultCachedAudio?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InputMessageContent(const std::string& message_text, const std::optional<std::string>& parse_mode, const std::optional<Json::Value>& entities, const std::optional<bool>& disable_web_page_preview) {
	std::string text;
	text = "";
	text = text + "message_text=" + message_text + "&";
	if (parse_mode.has_value()) {
		text = text + "parse_mode=" + parse_mode.value() + "&";
	}
	if (entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, entities.value());
		text = text + "entities=" + "[" + result + "]&";
	}
	if (disable_web_page_preview.has_value()) {
		if (disable_web_page_preview.value()) {
			text = text + "disable_web_page_preview=true&";
		}
		else {
			text = text + "disable_web_page_preview=false&";
		}
	}
	std::string tosend = generalToken + "/InputMessageContent?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InputLocationMessageContent(const float& longitude, const float& latitude, const std::optional<float>& horizontal_accuracy, const std::optional<__int64>& live_period, const std::optional<__int64>& heading, const std::optional<__int64>& proximity_alert_radius) {
	std::string text;
	text = "";
	text = text + "=" + std::to_string(longitude) + "&";
	text = text + "=" + std::to_string(latitude) + "&";
	if (horizontal_accuracy.has_value()) {
		text = text + "=" + std::to_string(horizontal_accuracy.value()) + "&";
	}
	if (live_period.has_value()) {
		text = text + "live_period=" + std::to_string(live_period.value()) + "&";
	}
	if (heading.has_value()) {
		text = text + "heading=" + std::to_string(heading.value()) + "&";
	}
	if (proximity_alert_radius.has_value()) {
		text = text + "proximity_alert_radius=" + std::to_string(proximity_alert_radius.value()) + "&";
	}
	std::string tosend = generalToken + "/InputLocationMessageContent?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InputVenueMessageContent(const float& longitude, const std::string& title, const std::string& address, const float& latitude, const std::optional<std::string>& foursquare_id, const std::optional<std::string>& foursquare_type, const std::optional<std::string>& google_place_id, const std::optional<std::string>& google_place_type) {
	std::string text;
	text = "";
	text = text + "=" + std::to_string(longitude) + "&";
	text = text + "title=" + title + "&";
	text = text + "address=" + address + "&";
	text = text + "=" + std::to_string(latitude) + "&";
	if (foursquare_id.has_value()) {
		text = text + "foursquare_id=" + foursquare_id.value() + "&";
	}
	if (foursquare_type.has_value()) {
		text = text + "foursquare_type=" + foursquare_type.value() + "&";
	}
	if (google_place_id.has_value()) {
		text = text + "google_place_id=" + google_place_id.value() + "&";
	}
	if (google_place_type.has_value()) {
		text = text + "google_place_type=" + google_place_type.value() + "&";
	}
	std::string tosend = generalToken + "/InputVenueMessageContent?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::InputContactMessageContent(const std::string& first_name, const std::string& phone_number, const std::optional<std::string>& last_name, const std::optional<std::string>& vcard) {
	std::string text;
	text = "";
	text = text + "first_name=" + first_name + "&";
	text = text + "phone_number=" + phone_number + "&";
	if (last_name.has_value()) {
		text = text + "last_name=" + last_name.value() + "&";
	}
	if (vcard.has_value()) {
		text = text + "vcard=" + vcard.value() + "&";
	}
	std::string tosend = generalToken + "/InputContactMessageContent?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::ChosenInlineResult(const Json::Value& from, const std::string& query, const std::string& result_id, const std::optional<Json::Value>& location, const std::optional<std::string>& inline_message_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, from);
	text = text + "from=" + "[" + result + "]&";
	text = text + "query=" + query + "&";
	text = text + "result_id=" + result_id + "&";
	if (location.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, location.value());
		text = text + "location=" + "[" + result + "]&";
	}
	if (inline_message_id.has_value()) {
		text = text + "inline_message_id=" + inline_message_id.value() + "&";
	}
	std::string tosend = generalToken + "/ChosenInlineResult?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::answerShippingQuery(const bool& ok, const std::string& shipping_query_id, const std::optional<Json::Value>& shipping_options, const std::optional<std::string>& error_message) {
	std::string text;
	text = "";
	if (ok) {
		text = text + "ok=true&";
	}
	else {
		text = text + "ok=false&";
	}
	text = text + "shipping_query_id=" + shipping_query_id + "&";
	if (shipping_options.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, shipping_options.value());
		text = text + "shipping_options=" + "[" + result + "]&";
	}
	if (error_message.has_value()) {
		text = text + "error_message=" + error_message.value() + "&";
	}
	std::string tosend = generalToken + "/answerShippingQuery?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::answerPreCheckoutQuery(const std::string& pre_checkout_query_id, const std::optional<bool>& ok, const std::optional<std::string>& error_message) {
	std::string text;
	text = "";
	text = text + "pre_checkout_query_id=" + pre_checkout_query_id + "&";
	if (ok.has_value()) {
		if (ok.value()) {
			text = text + "ok=true&";
		}
		else {
			text = text + "ok=false&";
		}
	}
	if (error_message.has_value()) {
		text = text + "error_message=" + error_message.value() + "&";
	}
	std::string tosend = generalToken + "/answerPreCheckoutQuery?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::LabeledPrice(const std::string& label, const std::optional<__int64>& amount) {
	std::string text;
	text = "";
	text = text + "label=" + label + "&";
	if (amount.has_value()) {
		text = text + "amount=" + std::to_string(amount.value()) + "&";
	}
	std::string tosend = generalToken + "/LabeledPrice?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::Invoice(const std::string& description, const std::string& start_parameter, const std::string& currency, const std::string& title, const std::optional<__int64>& total_amount) {
	std::string text;
	text = "";
	text = text + "description=" + description + "&";
	text = text + "start_parameter=" + start_parameter + "&";
	text = text + "currency=" + currency + "&";
	text = text + "title=" + title + "&";
	if (total_amount.has_value()) {
		text = text + "total_amount=" + std::to_string(total_amount.value()) + "&";
	}
	std::string tosend = generalToken + "/Invoice?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::ShippingAddress(const std::string& state, const std::string& city, const std::string& street_line1, const std::string& street_line2, const std::string& post_code, const std::string& country_code) {
	std::string text;
	text = "";
	text = text + "state=" + state + "&";
	text = text + "city=" + city + "&";
	text = text + "street_line1=" + street_line1 + "&";
	text = text + "street_line2=" + street_line2 + "&";
	text = text + "post_code=" + post_code + "&";
	text = text + "country_code=" + country_code + "&";
	std::string tosend = generalToken + "/ShippingAddress?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::OrderInfo(const std::optional<std::string>& name, const std::optional<std::string>& phone_number, const std::optional<std::string>& email, const std::optional<Json::Value>& shipping_address) {
	std::string text;
	text = "";
	if (name.has_value()) {
		text = text + "name=" + name.value() + "&";
	}
	if (phone_number.has_value()) {
		text = text + "phone_number=" + phone_number.value() + "&";
	}
	if (email.has_value()) {
		text = text + "email=" + email.value() + "&";
	}
	if (shipping_address.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, shipping_address.value());
		text = text + "shipping_address=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/OrderInfo?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::ShippingOption(const std::string& title, const Json::Value& prices, const std::string& id) {
	std::string text;
	text = "";
	text = text + "title=" + title + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, prices);
	text = text + "prices=" + "[" + result + "]&";
	text = text + "id=" + id + "&";
	std::string tosend = generalToken + "/ShippingOption?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::SuccessfulPayment(const std::string& provider_payment_charge_id, const std::string& invoice_payload, const std::string& telegram_payment_charge_id, const std::string& currency, const std::optional<__int64>& total_amount, const std::optional<std::string>& shipping_option_id, const std::optional<Json::Value>& order_info) {
	std::string text;
	text = "";
	text = text + "provider_payment_charge_id=" + provider_payment_charge_id + "&";
	text = text + "invoice_payload=" + invoice_payload + "&";
	text = text + "telegram_payment_charge_id=" + telegram_payment_charge_id + "&";
	text = text + "currency=" + currency + "&";
	if (total_amount.has_value()) {
		text = text + "total_amount=" + std::to_string(total_amount.value()) + "&";
	}
	if (shipping_option_id.has_value()) {
		text = text + "shipping_option_id=" + shipping_option_id.value() + "&";
	}
	if (order_info.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, order_info.value());
		text = text + "order_info=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/SuccessfulPayment?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::ShippingQuery(const Json::Value& from, const std::string& invoice_payload, const Json::Value& shipping_address, const std::string& id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, from);
	text = text + "from=" + "[" + result + "]&";
	text = text + "invoice_payload=" + invoice_payload + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, shipping_address);
	text = text + "shipping_address=" + "[" + result + "]&";
	text = text + "id=" + id + "&";
	std::string tosend = generalToken + "/ShippingQuery?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PreCheckoutQuery(const Json::Value& from, const std::string& currency, const std::string& invoice_payload, const std::string& id, const std::optional<__int64>& total_amount, const std::optional<std::string>& shipping_option_id, const std::optional<Json::Value>& order_info) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, from);
	text = text + "from=" + "[" + result + "]&";
	text = text + "currency=" + currency + "&";
	text = text + "invoice_payload=" + invoice_payload + "&";
	text = text + "id=" + id + "&";
	if (total_amount.has_value()) {
		text = text + "total_amount=" + std::to_string(total_amount.value()) + "&";
	}
	if (shipping_option_id.has_value()) {
		text = text + "shipping_option_id=" + shipping_option_id.value() + "&";
	}
	if (order_info.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, order_info.value());
		text = text + "order_info=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/PreCheckoutQuery?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PassportFile(const std::string& file_unique_id, const __int64& file_size, const __int64& file_date, const std::string& file_id) {
	std::string text;
	text = "";
	text = text + "file_unique_id=" + file_unique_id + "&";
	text = text + "file_size=" + std::to_string(file_size) + "&";
	text = text + "file_date=" + std::to_string(file_date) + "&";
	text = text + "file_id=" + file_id + "&";
	std::string tosend = generalToken + "/PassportFile?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::EncryptedPassportElement(const std::string& type, const std::string& hash, const std::optional<std::string>& phone_number, const std::optional<std::string>& email, const std::optional<Json::Value>& files, const std::optional<std::string>& data, const std::optional<Json::Value>& reverse_side, const std::optional<Json::Value>& selfie, const std::optional<Json::Value>& translation, const std::optional<Json::Value>& front_side) {
	std::string text;
	text = "";
	text = text + "type=" + type + "&";
	text = text + "hash=" + hash + "&";
	if (phone_number.has_value()) {
		text = text + "phone_number=" + phone_number.value() + "&";
	}
	if (email.has_value()) {
		text = text + "email=" + email.value() + "&";
	}
	if (files.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, files.value());
		text = text + "files=" + "[" + result + "]&";
	}
	if (data.has_value()) {
		text = text + "data=" + data.value() + "&";
	}
	if (reverse_side.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, reverse_side.value());
		text = text + "reverse_side=" + "[" + result + "]&";
	}
	if (selfie.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, selfie.value());
		text = text + "selfie=" + "[" + result + "]&";
	}
	if (translation.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, translation.value());
		text = text + "translation=" + "[" + result + "]&";
	}
	if (front_side.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, front_side.value());
		text = text + "front_side=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/EncryptedPassportElement?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::EncryptedCredentials(const std::string& hash, const std::string& secret, const std::string& data) {
	std::string text;
	text = "";
	text = text + "hash=" + hash + "&";
	text = text + "secret=" + secret + "&";
	text = text + "data=" + data + "&";
	std::string tosend = generalToken + "/EncryptedCredentials?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setPassportDataErrors(const Json::Value& errors, const __int64& user_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, errors);
	text = text + "errors=" + "[" + result + "]&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string tosend = generalToken + "/setPassportDataErrors?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PassportElementError(const std::string& type, const std::string& field_name, const std::string& data_hash, const std::string& message, const std::optional<std::string>& source) {
	std::string text;
	text = "";
	text = text + "type=" + type + "&";
	text = text + "field_name=" + field_name + "&";
	text = text + "data_hash=" + data_hash + "&";
	text = text + "message=" + message + "&";
	if (source.has_value()) {
		text = text + "source=" + source.value() + "&";
	}
	std::string tosend = generalToken + "/PassportElementError?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PassportElementErrorFrontSide(const std::string& type, const std::string& file_hash, const std::string& message, const std::optional<std::string>& source) {
	std::string text;
	text = "";
	text = text + "type=" + type + "&";
	text = text + "file_hash=" + file_hash + "&";
	text = text + "message=" + message + "&";
	if (source.has_value()) {
		text = text + "source=" + source.value() + "&";
	}
	std::string tosend = generalToken + "/PassportElementErrorFrontSide?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PassportElementErrorReverseSide(const std::string& type, const std::string& file_hash, const std::string& message, const std::optional<std::string>& source) {
	std::string text;
	text = "";
	text = text + "type=" + type + "&";
	text = text + "file_hash=" + file_hash + "&";
	text = text + "message=" + message + "&";
	if (source.has_value()) {
		text = text + "source=" + source.value() + "&";
	}
	std::string tosend = generalToken + "/PassportElementErrorReverseSide?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PassportElementErrorSelfie(const std::string& type, const std::string& file_hash, const std::string& message, const std::optional<std::string>& source) {
	std::string text;
	text = "";
	text = text + "type=" + type + "&";
	text = text + "file_hash=" + file_hash + "&";
	text = text + "message=" + message + "&";
	if (source.has_value()) {
		text = text + "source=" + source.value() + "&";
	}
	std::string tosend = generalToken + "/PassportElementErrorSelfie?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PassportElementErrorFile(const std::string& type, const std::string& file_hash, const std::string& message, const std::optional<std::string>& source) {
	std::string text;
	text = "";
	text = text + "type=" + type + "&";
	text = text + "file_hash=" + file_hash + "&";
	text = text + "message=" + message + "&";
	if (source.has_value()) {
		text = text + "source=" + source.value() + "&";
	}
	std::string tosend = generalToken + "/PassportElementErrorFile?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PassportElementErrorFiles(const std::string& type, const Json::Value& file_hashes, const std::string& message, const std::optional<std::string>& source) {
	std::string text;
	text = "";
	text = text + "type=" + type + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, file_hashes);
	text = text + "file_hashes=" + "[" + result + "]&";
	text = text + "message=" + message + "&";
	if (source.has_value()) {
		text = text + "source=" + source.value() + "&";
	}
	std::string tosend = generalToken + "/PassportElementErrorFiles?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PassportElementErrorTranslationFile(const std::string& type, const std::string& file_hash, const std::string& message, const std::optional<std::string>& source) {
	std::string text;
	text = "";
	text = text + "type=" + type + "&";
	text = text + "file_hash=" + file_hash + "&";
	text = text + "message=" + message + "&";
	if (source.has_value()) {
		text = text + "source=" + source.value() + "&";
	}
	std::string tosend = generalToken + "/PassportElementErrorTranslationFile?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PassportElementErrorTranslationFiles(const std::string& type, const Json::Value& file_hashes, const std::string& message, const std::optional<std::string>& source) {
	std::string text;
	text = "";
	text = text + "type=" + type + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, file_hashes);
	text = text + "file_hashes=" + "[" + result + "]&";
	text = text + "message=" + message + "&";
	if (source.has_value()) {
		text = text + "source=" + source.value() + "&";
	}
	std::string tosend = generalToken + "/PassportElementErrorTranslationFiles?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::PassportElementErrorUnspecified(const std::string& type, const std::string& element_hash, const std::string& message, const std::optional<std::string>& source) {
	std::string text;
	text = "";
	text = text + "type=" + type + "&";
	text = text + "element_hash=" + element_hash + "&";
	text = text + "message=" + message + "&";
	if (source.has_value()) {
		text = text + "source=" + source.value() + "&";
	}
	std::string tosend = generalToken + "/PassportElementErrorUnspecified?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::Game(const std::string& description, const Json::Value& photo, const std::string& title, const std::optional<std::string>& text, const std::optional<Json::Value>& text_entities, const std::optional<Json::Value>& animation) {
	std::string text1;
	text1 = "";
	text1 = text1 + "description=" + description + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, photo);
	text1 = text1 + "photo=" + "[" + result + "]&";
	text1 = text1 + "title=" + title + "&";
	if (text.has_value()) {
		text1 = text1 + "text=" + text.value() + "&";
	}
	if (text_entities.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, text_entities.value());
		text1 = text1 + "text_entities=" + "[" + result + "]&";
	}
	if (animation.has_value()) {
		std::string result;
		Json::StreamWriterBuilder wbuilder;
		wbuilder["indentation"] = "";
		result = Json::writeString(wbuilder, animation.value());
		text1 = text1 + "animation=" + "[" + result + "]&";
	}
	std::string tosend = generalToken + "/Game?" + text1;
	sendQuery(tosend);
}
inline void TelegramTypes::API::CallbackGame(const __int64& score, const __int64& user_id, const std::optional<bool>& force, const std::optional<bool>& disable_edit_message, const std::optional<__int64>& chat_id, const std::optional<__int64>& message_id, const std::optional<std::string>& inline_message_id) {
	std::string text;
	text = "";
	text = text + "score=" + std::to_string(score) + "&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	if (force.has_value()) {
		if (force.value()) {
			text = text + "force=true&";
		}
		else {
			text = text + "force=false&";
		}
	}
	if (disable_edit_message.has_value()) {
		if (disable_edit_message.value()) {
			text = text + "disable_edit_message=true&";
		}
		else {
			text = text + "disable_edit_message=false&";
		}
	}
	if (chat_id.has_value()) {
		text = text + "chat_id=" + std::to_string(chat_id.value()) + "&";
	}
	if (message_id.has_value()) {
		text = text + "message_id=" + std::to_string(message_id.value()) + "&";
	}
	if (inline_message_id.has_value()) {
		text = text + "inline_message_id=" + inline_message_id.value() + "&";
	}
	std::string tosend = generalToken + "/CallbackGame?" + text;
	sendQuery(tosend);
}
inline Json::Value TelegramTypes::API::getGameHighScores(const __int64& user_id, const std::optional<__int64>& chat_id, const std::optional<__int64>& message_id, const std::optional<std::string>& inline_message_id) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	if (chat_id.has_value()) {
		text = text + "chat_id=" + std::to_string(chat_id.value()) + "&";
	}
	if (message_id.has_value()) {
		text = text + "message_id=" + std::to_string(message_id.value()) + "&";
	}
	if (inline_message_id.has_value()) {
		text = text + "inline_message_id=" + inline_message_id.value() + "&";
	}
	std::string tosend = generalToken + "/getGameHighScores?" + text;
	CURL* curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, tosend.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return Json::Value(readBuffer);
}
inline void TelegramTypes::API::GameHighScore(const Json::Value& user, const __int64& score, const __int64& position) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, user);
	text = text + "user=" + "[" + result + "]&";
	text = text + "score=" + std::to_string(score) + "&";
	text = text + "position=" + std::to_string(position) + "&";
	std::string tosend = generalToken + "/GameHighScore?" + text;
	sendQuery(tosend);
}