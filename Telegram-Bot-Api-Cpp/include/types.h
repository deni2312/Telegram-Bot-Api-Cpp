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
		API(std::string link="") : generalToken(link) {};
		void sendMessage(const std::string & chat_id,
			const std::string & msgp,
			const std::string & parse_mode = "",
			const bool & disable_web_page_preview = false,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const Json::Value & reply_markup = "") const;
		void sendDocument(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & document,
			const std::string & mime_thumb = "",
			const std::string & thumb = "",
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "") const;
		void sendPhoto(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & photo,
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "") const;
		void sendAudio(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & audio,
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const __int64 & duration = 0,
			const __int64 & performer = 0,
			const std::string & title = "",
			const std::string & mime_thumb = "",
			const std::string & thumb = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "") const;
		void sendAnimation(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & animation,
			const __int64 & duration = 0,
			const __int64 & width = 0,
			const __int64 & height = 0,
			const std::string & mime_thumb = "",
			const std::string & thumb = "",
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "") const;
		void sendVoice(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & voice,
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "") const;
		void sendVideoNote(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & video_note,
			const __int64 & duration = 0,
			const __int64 & length = 0,
			const std::string & mime_thumb = "",
			const std::string & thumb = "",
			const std::string & caption = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "") const;
		void sendVideo(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & video,
			const __int64 & duration = 0,
			const __int64 & width = 0,
			const __int64 & height = 0,
			const std::string & mime_thumb = "",
			const std::string & thumb = "",
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const bool & supports_streaming = false,
			const bool & disable_notification = 0,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "") const;
		void sendMediaGroup(const std::string & chat_id,
			const std::string & mime_type,
			const std::vector < std::shared_ptr < InputMediaPhoto >> & media,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0) const;
		void sendMediaGroup(const std::string & chat_id,
			const std::string & mime_type,
			const std::vector < std::shared_ptr < InputMediaVideo >> & media,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0) const;
		void copyMessage(const Json::Value & from_chat_id,
			const std::string & chat_id,
			const Json::Value & reply_markup = nullptr,
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const __int64 & message_id = 0,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const Json::Value & caption_entities = nullptr) const;
		void sendLocation(const float & latitude,
			const float & longitude,
			const std::string & chat_id,
			const Json::Value & reply_markup = nullptr,
			const __int64 & live_period = 0,
			const float & horizontal_accuracy = 0,
			const __int64 & proximity_alert_radius = 0,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const __int64 & heading = 0) const;
		void editMessageLiveLocation(const float & latitude,
			const float & longitude,
			const Json::Value & reply_markup = nullptr,
			const std::string & inline_message_id = "",
			const __int64 & message_id = 0,
			const float & horizontal_accuracy = 0,
			const __int64 & heading = 0,
			const __int64 & proximity_alert_radius = 0,
			const std::string & chat_id = nullptr) const;
		void stopMessageLiveLocation(const std::string & chat_id = nullptr,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "",
			const Json::Value & reply_markup = nullptr) const;
		void sendVenue(const float & latitude,
			const float & longitude,
			const std::string & title,
			const std::string & address,
			const std::string & chat_id,
			const Json::Value & reply_markup = nullptr,
			const std::string & foursquare_id = "",
			const std::string & google_place_id = "",
			const std::string & google_place_type = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const std::string & foursquare_type = "") const;
		void sendContact(const std::string & phone_number,
			const std::string & first_name,
			const std::string & chat_id,
			const Json::Value & reply_markup = nullptr,
			const std::string & last_name = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const std::string & vcard = "") const;
		void sendPoll(const std::string & question,
			const Json::Value & options,
			const std::string & chat_id,
			const Json::Value & reply_markup = nullptr,
			const std::string & explanation_parse_mode = "",
			const __int64 & open_period = 0,
			const std::string & type = "",
			const __int64 & close_date = 0,
			const __int64 & correct_option_id = 0,
			const bool & is_closed = false,
			const bool & allows_multiple_answers = false,
			const std::string & explanation = "",
			const Json::Value & explanation_entities = nullptr,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const bool & is_anonymous = false) const;
		void sendDice(const std::string & chat_id,
			const std::string & emoji = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const Json::Value & reply_markup = nullptr) const;
		void sendChatAction(const std::string & chat_id,
			const std::string & action = "") const;
		Json::Value getUserProfilePhotos(const __int64 & user_id,
			const __int64 & offset = 0,
			const __int64 & limit = 0) const;
		Json::Value getFile(const std::string & file_id);
		void kickChatMember(const __int64 & user_id,
			const std::string & chat_id,
			const __int64 & until_date = 0) const;
		void unbanChatMember(const __int64 & user_id,
			const std::string & chat_id,
			const bool & only_if_banned = false) const;
		void restrictChatMember(const __int64 & user_id,
			const Json::Value & permissions,
			const std::string & chat_id,
			const __int64 & until_date = 0) const;
		void promoteChatMember(const __int64 & user_id,
			const std::string & chat_id,
			const bool & can_promote_members = false,
			const bool & can_change_info = false,
			const bool & can_post_messages = false,
			const bool & is_anonymous = false,
			const bool & can_delete_messages = false,
			const bool & can_invite_users = false,
			const bool & can_restrict_members = false,
			const bool & can_pin_messages = false,
			const bool & can_edit_messages = false) const;
		void setChatAdministratorCustomTitle(const __int64 & user_id,
			const std::string & custom_title,
			const std::string & chat_id) const;
		void setChatPermissions(const Json::Value & permissions,
			const std::string & chat_id) const;
		void exportChatInviteLink(const std::string & chat_id) const;
		void setChatPhoto(const Json::Value & photo,
			const std::string & chat_id) const;
		void deleteChatPhoto(const std::string & chat_id) const;
		void setChatTitle(const std::string & title,
			const std::string & chat_id) const;
		void setChatDescription(const std::string & chat_id,
			const std::string & description = "") const;
		void pinChatMessage(const __int64 & message_id,
			const std::string & chat_id,
			const bool & disable_notification = false) const;
		void unpinChatMessage(const std::string & chat_id,
			const __int64 & message_id = 0) const;
		void unpinAllChatMessages(const std::string & chat_id) const;
		void leaveChat(const std::string & chat_id) const;
		Json::Value getChat(const std::string & chat_id) const;
		Json::Value getChatAdministrators(const std::string & chat_id) const;
		Json::Value getChatMembersCount(const std::string & chat_id) const;
		Json::Value getChatMember(const __int64 & user_id,
			const std::string & chat_id) const;
		void setChatStickerSet(const std::string & sticker_set_name,
			const std::string & chat_id) const;
		void deleteChatStickerSet(const std::string & chat_id) const;
		void answerCallbackQuery(const std::string & callback_query_id,
			const std::string & text = "",
			const bool & show_alert = false,
			const std::string & url = "",
			const __int64 & cache_time = 0) const;
		void setMyCommands(const Json::Value & commands);
		Json::Value getMyCommands(const std::string & text,
			const std::string & chat_id = nullptr,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "",
			const std::string & parse_mode = "",
			const Json::Value & entities = nullptr,
			const bool & disable_web_page_preview = false,
			const Json::Value & reply_markup = nullptr) const;
		void editMessageCaption(const std::string & chat_id = nullptr,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "",
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const Json::Value & caption_entities = nullptr,
			const Json::Value & reply_markup = nullptr) const;
		void editMessageMedia(const Json::Value & media,
			const std::string & chat_id = nullptr,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "",
			const Json::Value & reply_markup = nullptr) const;
		void editMessageReplyMarkup(const std::string & chat_id = nullptr,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "",
			const Json::Value & reply_markup = nullptr) const;
		void stopPoll(const __int64 & message_id,
			const std::string & chat_id,
			const Json::Value & reply_markup = nullptr) const;
		void deleteMessage(const __int64 & message_id,
			const std::string & chat_id) const;
		void sendSticker(const Json::Value & sticker,
			const std::string & chat_id,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const Json::Value & reply_markup = nullptr) const;
		Json::Value getStickerSet(const std::string & name);
		void uploadStickerFile(const Json::Value & png_sticker,
			const __int64 & user_id);
		void createNewStickerSet(const std::string & emojis,
			const std::string & title,
			const __int64 & user_id,
			const std::string & name = "",
			const Json::Value & png_sticker = nullptr,
			const Json::Value & tgs_sticker = nullptr,
			const bool & contains_masks = false,
			const Json::Value & mask_position = nullptr) const;
		void addStickerToSet(const std::string & name,
			const std::string & emojis,
			const __int64 & user_id,
			const Json::Value & png_sticker = nullptr,
			const Json::Value & tgs_sticker = nullptr,
			const Json::Value & mask_position = nullptr) const;
		void setStickerPositionInSet(const __int64 & position,
			const std::string & sticker);
		void deleteStickerFromSet(const std::string & sticker);
		void setStickerSetThumb(const __int64 & user_id,
			const std::string & name,
			const Json::Value & thumb = nullptr) const;
		void answerInlineQuery(const Json::Value & results,
			const std::string & inline_query_id,
			const __int64 & cache_time = 0,
			const bool & is_personal = false,
			const std::string & next_offset = "",
			const std::string & switch_pm_text = "",
			const std::string & switch_pm_parameter = "") const;
		void answerShippingQuery(const bool & ok,
			const std::string & shipping_query_id,
			const Json::Value & shipping_options = {},
			const std::string & error_message = "") const;
		void answerPreCheckoutQuery(const std::string & pre_checkout_query_id,
			const bool & ok = false,
			const std::string & error_message = "") const;
		void setPassportDataErrors(const Json::Value & errors,
			const __int64 & user_id) const;
		Json::Value getGameHighScores(const __int64 & user_id,
			const __int64 & chat_id = 0,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "") const;
		~API() {};
	private:

		std::string generalToken = "";
		void sendQuery(std::string & query) const ;
		Json::Value getQuery(std::string & query) const;
	};
}
