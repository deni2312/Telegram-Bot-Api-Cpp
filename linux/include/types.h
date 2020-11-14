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
		inline void sendMessage(const std::string & chat_id,
			const std::string & msgp,
			const std::string & parse_mode = "",
			const bool & disable_web_page_preview = false,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const Json::Value & reply_markup = "");
		inline void sendDocument(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & document,
			const std::string & mime_thumb = "",
			const std::string & thumb = "",
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "");
		inline void sendPhoto(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & photo,
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "");
		inline void sendAudio(const std::string & chat_id,
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
			const std::string & reply_markup = "");
		inline void sendAnimation(const std::string & chat_id,
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
			const std::string & reply_markup = "");
		inline void sendVoice(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & voice,
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "");
		inline void sendVideoNote(const std::string & chat_id,
			const std::string & mime_type,
			const std::string & video_note,
			const __int64 & duration = 0,
			const __int64 & length = 0,
			const std::string & mime_thumb = "",
			const std::string & thumb = "",
			const std::string & caption = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const std::string & reply_markup = "");
		inline void sendVideo(const std::string & chat_id,
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
			const std::string & reply_markup = "");
		inline void sendMediaGroup(const std::string & chat_id,
			const std::string & mime_type,
			const std::vector < std::shared_ptr < InputMediaPhoto >> & media,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0);
		inline void sendMediaGroup(const std::string & chat_id,
			const std::string & mime_type,
			const std::vector < std::shared_ptr < InputMediaVideo >> & media,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0);
		inline void copyMessage(const Json::Value & from_chat_id,
			const std::string & chat_id,
			const Json::Value & reply_markup = nullptr,
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const __int64 & message_id = 0,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const Json::Value & caption_entities = nullptr);
		inline void sendLocation(const float & latitude,
			const float & longitude,
			const std::string & chat_id,
			const Json::Value & reply_markup = nullptr,
			const __int64 & live_period = 0,
			const float & horizontal_accuracy = 0,
			const __int64 & proximity_alert_radius = 0,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const __int64 & heading = 0);
		inline void editMessageLiveLocation(const float & latitude,
			const float & longitude,
			const Json::Value & reply_markup = nullptr,
			const std::string & inline_message_id = "",
			const __int64 & message_id = 0,
			const float & horizontal_accuracy = 0,
			const __int64 & heading = 0,
			const __int64 & proximity_alert_radius = 0,
			const std::string & chat_id = nullptr);
		inline void stopMessageLiveLocation(const std::string & chat_id = nullptr,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "",
			const Json::Value & reply_markup = nullptr);
		inline void sendVenue(const float & latitude,
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
			const std::string & foursquare_type = "");
		inline void sendContact(const std::string & phone_number,
			const std::string & first_name,
			const std::string & chat_id,
			const Json::Value & reply_markup = nullptr,
			const std::string & last_name = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const std::string & vcard = "");
		inline void sendPoll(const std::string & question,
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
			const bool & is_anonymous = false);
		inline void sendDice(const std::string & chat_id,
			const std::string & emoji = "",
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const Json::Value & reply_markup = nullptr);
		inline void sendChatAction(const std::string & chat_id,
			const std::string & action = "");
		inline Json::Value getUserProfilePhotos(const __int64 & user_id,
			const __int64 & offset = 0,
			const __int64 & limit = 0);
		inline Json::Value getFile(const std::string & file_id);
		inline void kickChatMember(const __int64 & user_id,
			const std::string & chat_id,
			const __int64 & until_date = 0);
		inline void unbanChatMember(const __int64 & user_id,
			const std::string & chat_id,
			const bool & only_if_banned = false);
		inline void restrictChatMember(const __int64 & user_id,
			const Json::Value & permissions,
			const std::string & chat_id,
			const __int64 & until_date = 0);
		inline void promoteChatMember(const __int64 & user_id,
			const std::string & chat_id,
			const bool & can_promote_members = false,
			const bool & can_change_info = false,
			const bool & can_post_messages = false,
			const bool & is_anonymous = false,
			const bool & can_delete_messages = false,
			const bool & can_invite_users = false,
			const bool & can_restrict_members = false,
			const bool & can_pin_messages = false,
			const bool & can_edit_messages = false);
		inline void setChatAdministratorCustomTitle(const __int64 & user_id,
			const std::string & custom_title,
			const std::string & chat_id);
		inline void setChatPermissions(const Json::Value & permissions,
			const std::string & chat_id);
		inline void exportChatInviteLink(const std::string & chat_id);
		inline void setChatPhoto(const Json::Value & photo,
			const std::string & chat_id);
		inline void deleteChatPhoto(const std::string & chat_id);
		inline void setChatTitle(const std::string & title,
			const std::string & chat_id);
		inline void setChatDescription(const std::string & chat_id,
			const std::string & description = "");
		inline void pinChatMessage(const __int64 & message_id,
			const std::string & chat_id,
			const bool & disable_notification = false);
		inline void unpinChatMessage(const std::string & chat_id,
			const __int64 & message_id = 0);
		inline void unpinAllChatMessages(const std::string & chat_id);
		inline void leaveChat(const std::string & chat_id);
		inline Json::Value getChat(const std::string & chat_id);
		inline Json::Value getChatAdministrators(const std::string & chat_id);
		inline Json::Value getChatMembersCount(const std::string & chat_id);
		inline Json::Value getChatMember(const __int64 & user_id,
			const std::string & chat_id);
		inline void setChatStickerSet(const std::string & sticker_set_name,
			const std::string & chat_id);
		inline void deleteChatStickerSet(const std::string & chat_id);
		inline void answerCallbackQuery(const std::string & callback_query_id,
			const std::string & text = "",
			const bool & show_alert = false,
			const std::string & url = "",
			const __int64 & cache_time = 0);
		inline void setMyCommands(const Json::Value & commands);
		inline Json::Value getMyCommands(const std::string & text,
			const std::string & chat_id = nullptr,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "",
			const std::string & parse_mode = "",
			const Json::Value & entities = nullptr,
			const bool & disable_web_page_preview = false,
			const Json::Value & reply_markup = nullptr);
		inline void editMessageCaption(const std::string & chat_id = nullptr,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "",
			const std::string & caption = "",
			const std::string & parse_mode = "",
			const Json::Value & caption_entities = nullptr,
			const Json::Value & reply_markup = nullptr);
		inline void editMessageMedia(const Json::Value & media,
			const std::string & chat_id = nullptr,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "",
			const Json::Value & reply_markup = nullptr);
		inline void editMessageReplyMarkup(const std::string & chat_id = nullptr,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "",
			const Json::Value & reply_markup = nullptr);
		inline void stopPoll(const __int64 & message_id,
			const std::string & chat_id,
			const Json::Value & reply_markup = nullptr);
		inline void deleteMessage(const __int64 & message_id,
			const std::string & chat_id);
		inline void sendSticker(const Json::Value & sticker,
			const std::string & chat_id,
			const bool & disable_notification = false,
			const __int64 & reply_to_message_id = 0,
			const bool & allow_sending_without_reply = false,
			const Json::Value & reply_markup = nullptr);
		inline Json::Value getStickerSet(const std::string & name);
		inline void uploadStickerFile(const Json::Value & png_sticker,
			const __int64 & user_id);
		inline void createNewStickerSet(const std::string & emojis,
			const std::string & title,
			const __int64 & user_id,
			const std::string & name = "",
			const Json::Value & png_sticker = nullptr,
			const Json::Value & tgs_sticker = nullptr,
			const bool & contains_masks = false,
			const Json::Value & mask_position = nullptr);
		inline void addStickerToSet(const std::string & name,
			const std::string & emojis,
			const __int64 & user_id,
			const Json::Value & png_sticker = nullptr,
			const Json::Value & tgs_sticker = nullptr,
			const Json::Value & mask_position = nullptr);
		inline void setStickerPositionInSet(const __int64 & position,
			const std::string & sticker);
		inline void deleteStickerFromSet(const std::string & sticker);
		inline void setStickerSetThumb(const __int64 & user_id,
			const std::string & name,
			const Json::Value & thumb = nullptr);
		inline void answerInlineQuery(const Json::Value & results,
			const std::string & inline_query_id,
			const __int64 & cache_time = 0,
			const bool & is_personal = false,
			const std::string & next_offset = "",
			const std::string & switch_pm_text = "",
			const std::string & switch_pm_parameter = "");
		inline void answerShippingQuery(const bool & ok,
			const std::string & shipping_query_id,
			const Json::Value & shipping_options = {},
			const std::string & error_message = "");
		inline void answerPreCheckoutQuery(const std::string & pre_checkout_query_id,
			const bool & ok = false,
			const std::string & error_message = "");
		inline void setPassportDataErrors(const Json::Value & errors,
			const __int64 & user_id);
		inline Json::Value getGameHighScores(const __int64 & user_id,
			const __int64 & chat_id = 0,
			const __int64 & message_id = 0,
			const std::string & inline_message_id = "");
		~API() {};
	private:

		std::string generalToken = "";
		inline void sendQuery(std::string & query);
		inline Json::Value getQuery(std::string & query);
	};
}
inline size_t WriteCallback(char * contents, size_t size, size_t nmemb, void * userp) {
	((std::string *) userp)->append((char *)contents, size * nmemb);
	return size * nmemb;
}
inline void TelegramTypes::API::sendMessage(const std::string & chat_id,
	const std::string & msgp,
	const std::string & parse_mode,
	const bool & disable_web_page_preview,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const Json::Value & reply_markup) {
	std::string text = "";
	text = text + "chat_id=" + chat_id;
	text = text + "&text=" + msgp;
	for (__int64 i = 0; i < msgp.length(); i++) {
		if (text.at(i) == ' ') {
			text.at(i) = '+';
		}
	}
	text = text + "&parse_mode=" + parse_mode;
	if (disable_web_page_preview) {
		text = text + "&disable_web_page_preview=true";
	}
	else {
		text = text + "&disable_web_page_preview=false";
	}
	if (disable_notification) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notifiaction=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id);

	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";

	std::string tosend = generalToken + "/sendMessage?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendDocument(const std::string & chat_id,
	const std::string & mime_type,
	const std::string & document,
	const std::string & mime_thumb,
	const std::string & thumb,
	const std::string & caption,
	const std::string & parse_mode,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const std::string & reply_markup) {
	CURL * curl;
	CURLcode res;
	curl_mime * form = NULL;
	curl_mimepart * field = NULL;
	struct curl_slist * headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&parse_mode=" + parse_mode;
	curl = curl_easy_init();

	if (mime_thumb != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb");
			curl_mime_filedata(field, thumb.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb=");
			curl_mime_data(field, "thumb", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
		}
	}
	else {
		text = text + "&thumb=" + thumb;
	}

	if (disable_notification) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id);
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup;
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
inline void TelegramTypes::API::sendPhoto(const std::string & chat_id,
	const std::string & mime_type,
	const std::string & photo,
	const std::string & caption,
	const std::string & parse_mode,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const std::string & reply_markup) {
	CURL * curl;
	CURLcode res;
	curl_mime * form = NULL;
	curl_mimepart * field = NULL;
	struct curl_slist * headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&parse_mode=" + parse_mode;
	if (disable_notification) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id);
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup;
	curl = curl_easy_init();
	if (mime_type != "") {
		curl_mime * form = NULL;
		curl_mimepart * field = NULL;
		struct curl_slist * headerlist = NULL;
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
inline void TelegramTypes::API::sendAudio(const std::string & chat_id,
	const std::string & mime_type,
	const std::string & audio,
	const std::string & caption,
	const std::string & parse_mode,
	const __int64 & duration,
	const __int64 & performer,
	const std::string & title,
	const std::string & mime_thumb,
	const std::string & thumb,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const std::string & reply_markup) {
	CURL * curl;
	CURLcode res;
	curl_mime * form = NULL;
	curl_mimepart * field = NULL;
	struct curl_slist * headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&parse_mode=" + parse_mode;
	text = text + "&duration=" + std::to_string(duration);
	text = text + "&performer=" + std::to_string(performer);
	text = text + "&title=" + title;
	curl = curl_easy_init();
	if (mime_thumb != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb");
			curl_mime_filedata(field, thumb.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb=");
			curl_mime_data(field, "thumb", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
		}
	}
	else {
		text = text + "&thumb=" + thumb;
	}
	if (disable_notification) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id);
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup;
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
inline void TelegramTypes::API::sendAnimation(const std::string & chat_id,
	const std::string & mime_type,
	const std::string & animation,
	const __int64 & duration,
	const __int64 & width,
	const __int64 & height,
	const std::string & mime_thumb,
	const std::string & thumb,
	const std::string & caption,
	const std::string & parse_mode,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const std::string & reply_markup) {
	CURL * curl;
	CURLcode res;
	curl_mime * form = NULL;
	curl_mimepart * field = NULL;
	struct curl_slist * headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&parse_mode=" + parse_mode;
	text = text + "&duration=" + std::to_string(duration);
	text = text + "&width=" + std::to_string(width);
	text = text + "&height=" + std::to_string(height);
	curl = curl_easy_init();
	if (mime_thumb != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb");
			curl_mime_filedata(field, thumb.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb=");
			curl_mime_data(field, "thumb", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
		}
	}
	else {
		text = text + "&thumb=" + thumb;
	}
	if (disable_notification) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id);
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup;
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
inline void TelegramTypes::API::sendVoice(const std::string & chat_id,
	const std::string & mime_type,
	const std::string & voice,
	const std::string & caption,
	const std::string & parse_mode,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const std::string & reply_markup) {
	CURL * curl;
	CURLcode res;
	curl_mime * form = NULL;
	curl_mimepart * field = NULL;
	struct curl_slist * headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&parse_mode=" + parse_mode;
	curl = curl_easy_init();
	if (disable_notification) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id);
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
inline void TelegramTypes::API::sendVideoNote(const std::string & chat_id,
	const std::string & mime_type,
	const std::string & video_note,
	const __int64 & duration,
	const __int64 & length,
	const std::string & mime_thumb,
	const std::string & thumb,
	const std::string & caption,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const std::string & reply_markup) {
	CURL * curl;
	CURLcode res;
	curl_mime * form = NULL;
	curl_mimepart * field = NULL;
	struct curl_slist * headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&duration=" + std::to_string(duration);
	text = text + "&length=" + std::to_string(length);
	curl = curl_easy_init();
	if (mime_thumb != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb");
			curl_mime_filedata(field, thumb.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb=");
			curl_mime_data(field, "thumb", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
		}
	}
	else {
		text = text + "&thumb=" + thumb;
	}
	if (disable_notification) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id);
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup;
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
inline void TelegramTypes::API::sendVideo(const std::string & chat_id,
	const std::string & mime_type,
	const std::string & video,
	const __int64 & duration,
	const __int64 & width,
	const __int64 & height,
	const std::string & mime_thumb,
	const std::string & thumb,
	const std::string & caption,
	const std::string & parse_mode,
	const bool & supports_streaming,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const std::string & reply_markup) {
	CURL * curl;
	CURLcode res;
	curl_mime * form = NULL;
	curl_mimepart * field = NULL;
	struct curl_slist * headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&parse_mode=" + parse_mode;
	text = text + "&duration=" + std::to_string(duration);
	text = text + "&width=" + std::to_string(width);
	text = text + "&height=" + std::to_string(height);
	if (supports_streaming) {
		text = text + "&supports_streaming=true";
	}
	else {
		text = text + "&supports_streaming=false";
	}
	curl = curl_easy_init();
	if (mime_thumb != "") {
		if (curl) {
			form = curl_mime_init(curl);
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb");
			curl_mime_filedata(field, thumb.c_str());
			field = curl_mime_addpart(form);
			curl_mime_name(field, "thumb=");
			curl_mime_data(field, "thumb", CURL_ZERO_TERMINATED);
			headerlist = curl_slist_append(headerlist, buf);
		}
	}
	else {
		text = text + "&thumb=" + thumb;
	}
	if (disable_notification) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id);
	std::string readBuffer;
	text = text + "&reply_markup=" + reply_markup;
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
inline void TelegramTypes::API::sendMediaGroup(const std::string & chat_id,
	const std::string & mime_type,
	const std::vector < std::shared_ptr < InputMediaPhoto >> & media,
	const bool & disable_notification,
	const __int64 & reply_to_message_id) {
	CURL * curl;
	CURLcode res;
	curl_mime * form = NULL;
	curl_mimepart * field = NULL;
	struct curl_slist * headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	curl = curl_easy_init();
	if (disable_notification) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id);
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
inline void TelegramTypes::API::sendMediaGroup(const std::string & chat_id,
	const std::string & mime_type,
	const std::vector < std::shared_ptr < InputMediaVideo >> & media,
	const bool & disable_notification,
	const __int64 & reply_to_message_id) {
	CURL * curl;
	CURLcode res;
	curl_mime * form = NULL;
	curl_mimepart * field = NULL;
	struct curl_slist * headerlist = NULL;
	const char buf[] = "Expect:";
	std::string text;
	text = "";
	text = text + "?chat_id=" + chat_id;
	curl = curl_easy_init();
	if (disable_notification) {
		text = text + "&disable_notification=true";
	}
	else {
		text = text + "&disable_notification=false";
	}
	text = text + "&reply_to_message_id=" + std::to_string(reply_to_message_id);
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
inline void TelegramTypes::API::copyMessage(const Json::Value & from_chat_id,
	const std::string & chat_id,
	const Json::Value & reply_markup,
	const std::string & caption,
	const std::string & parse_mode,
	const __int64 & message_id,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const bool & allow_sending_without_reply,
	const Json::Value & caption_entities) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, from_chat_id);
	text = text + "from_chat_id=" + result + "&";
	text = text + "chat_id=" + chat_id + "&";

	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";

	text = text + "caption=" + caption + "&";

	text = text + "parse_mode=" + parse_mode + "&";

	text = text + "message_id=" + std::to_string(message_id) + "&";

	if (disable_notification) {
		if (disable_notification) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	if (reply_to_message_id) {
		text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id) + "&";
	}
	if (allow_sending_without_reply) {
		if (allow_sending_without_reply) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}

	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, caption_entities);
	text = text + "caption_entities=" + result + "&";

	std::string tosend = generalToken + "/copyMessage?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendLocation(const float & latitude,
	const float & longitude,
	const std::string & chat_id,
	const Json::Value & reply_markup,
	const __int64 & live_period,
	const float & horizontal_accuracy,
	const __int64 & proximity_alert_radius,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const bool & allow_sending_without_reply,
	const __int64 & heading) {
	std::string text;
	text = "";
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";
	text = text + "chat_id=" + chat_id + "&";

	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";

	text = text + "live_period=" + std::to_string(live_period) + "&";

	text = text + "=" + std::to_string(horizontal_accuracy) + "&";

	text = text + "proximity_alert_radius=" + std::to_string(proximity_alert_radius) + "&";

	if (disable_notification) {
		if (disable_notification) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	if (reply_to_message_id) {
		text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id) + "&";
	}
	if (allow_sending_without_reply) {
		if (allow_sending_without_reply) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}
	if (heading) {
		text = text + "heading=" + std::to_string(heading) + "&";
	}
	std::string tosend = generalToken + "/sendLocation?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::editMessageLiveLocation(const float & latitude,
	const float & longitude,
	const Json::Value & reply_markup,
	const std::string & inline_message_id,
	const __int64 & message_id,
	const float & horizontal_accuracy,
	const __int64 & heading,
	const __int64 & proximity_alert_radius,
	const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";

	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";

	text = text + "inline_message_id=" + inline_message_id + "&";

	text = text + "message_id=" + std::to_string(message_id) + "&";

	text = text + "=" + std::to_string(horizontal_accuracy) + "&";

	text = text + "heading=" + std::to_string(heading) + "&";

	text = text + "proximity_alert_radius=" + std::to_string(proximity_alert_radius) + "&";

	text = text + "chat_id=" + chat_id + "&";

	std::string tosend = generalToken + "/editMessageLiveLocation?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::stopMessageLiveLocation(const std::string & chat_id,
	const __int64 & message_id,
	const std::string & inline_message_id,
	const Json::Value & reply_markup) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "inline_message_id=" + inline_message_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";
	std::string tosend = generalToken + "/stopMessageLiveLocation?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendVenue(const float & latitude,
	const float & longitude,
	const std::string & title,
	const std::string & address,
	const std::string & chat_id,
	const Json::Value & reply_markup,
	const std::string & foursquare_id,
	const std::string & google_place_id,
	const std::string & google_place_type,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const bool & allow_sending_without_reply,
	const std::string & foursquare_type) {
	std::string text;
	text = "";
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";
	text = text + "title=" + title + "&";
	text = text + "address=" + address + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";
	text = text + "foursquare_id=" + foursquare_id + "&";
	text = text + "google_place_id=" + google_place_id + "&";
	text = text + "google_place_type=" + google_place_type + "&";
	if (disable_notification) {
		text = text + "disable_notification=true&";
	}
	else {
		text = text + "disable_notification=false&";
	}
	if (reply_to_message_id) {
		text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id) + "&";
	}
	if (allow_sending_without_reply) {
		if (allow_sending_without_reply) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}
	text = text + "foursquare_type=" + foursquare_type + "&";
	std::string tosend = generalToken + "/sendVenue?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendContact(const std::string & phone_number,
	const std::string & first_name,
	const std::string & chat_id,
	const Json::Value & reply_markup,
	const std::string & last_name,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const bool & allow_sending_without_reply,
	const std::string & vcard) {
	std::string text;
	text = "";
	text = text + "phone_number=" + phone_number + "&";
	text = text + "first_name=" + first_name + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";
	text = text + "last_name=" + last_name + "&";
	if (disable_notification) {
		text = text + "disable_notification=true&";
	}
	else {
		text = text + "disable_notification=false&";
	}
	text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id) + "&";
	if (allow_sending_without_reply) {
		if (allow_sending_without_reply) {
			text = text + "allow_sending_without_reply=true&";
		}
		else {
			text = text + "allow_sending_without_reply=false&";
		}
	}
	text = text + "vcard=" + vcard + "&";
	std::string tosend = generalToken + "/sendContact?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendPoll(const std::string & question,
	const Json::Value & options,
	const std::string & chat_id,
	const Json::Value & reply_markup,
	const std::string & explanation_parse_mode,
	const __int64 & open_period,
	const std::string & type,
	const __int64 & close_date,
	const __int64 & correct_option_id,
	const bool & is_closed,
	const bool & allows_multiple_answers,
	const std::string & explanation,
	const Json::Value & explanation_entities,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const bool & allow_sending_without_reply,
	const bool & is_anonymous) {
	std::string text;
	text = "";
	text = text + "question=" + question + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, options);
	text = text + "options=" + result + "&";
	text = text + "chat_id=" + chat_id + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";
	text = text + "explanation_parse_mode=" + explanation_parse_mode + "&";
	text = text + "open_period=" + std::to_string(open_period) + "&";
	text = text + "type=" + type + "&";
	text = text + "close_date=" + std::to_string(close_date) + "&";
	text = text + "correct_option_id=" + std::to_string(correct_option_id) + "&";
	if (is_closed) {
		text = text + "is_closed=true&";
	}
	else {
		text = text + "is_closed=false&";
	}
	if (allows_multiple_answers) {
		if (allows_multiple_answers) {
			text = text + "allows_multiple_answers=true&";
		}
		else {
			text = text + "allows_multiple_answers=false&";
		}
	}
	text = text + "explanation=" + explanation + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, explanation_entities);
	text = text + "explanation_entities=" + result + "&";
	if (disable_notification) {
		text = text + "disable_notification=true&";
	}
	else {
		text = text + "disable_notification=false&";
	}
	text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id) + "&";
	if (allow_sending_without_reply) {
		text = text + "allow_sending_without_reply=true&";
	}
	else {
		text = text + "allow_sending_without_reply=false&";
	}
	if (is_anonymous) {
		text = text + "is_anonymous=true&";
	}
	else {
		text = text + "is_anonymous=false&";
	}
	std::string tosend = generalToken + "/sendPoll?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendDice(const std::string & chat_id,
	const std::string & emoji,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const bool & allow_sending_without_reply,
	const Json::Value & reply_markup) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "emoji=" + emoji + "&";
	if (disable_notification) {
		text = text + "disable_notification=true&";
	}
	else {
		text = text + "disable_notification=false&";
	}
	text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id) + "&";
	if (allow_sending_without_reply) {
		text = text + "allow_sending_without_reply=true&";
	}
	else {
		text = text + "allow_sending_without_reply=false&";
	}
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";
	std::string tosend = generalToken + "/sendDice?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendChatAction(const std::string & chat_id,
	const std::string & action) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "action=" + action + "&";
	std::string tosend = generalToken + "/sendChatAction?" + text;
	sendQuery(tosend);
}
inline Json::Value TelegramTypes::API::getUserProfilePhotos(const __int64 & user_id,
	const __int64 & offset,
	const __int64 & limit) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "offset=" + std::to_string(offset) + "&";
	text = text + "limit=" + std::to_string(limit) + "&";
	std::string tosend = generalToken + "/getUserProfilePhotos?" + text;

	return getQuery(tosend);
}
inline Json::Value TelegramTypes::API::getFile(const std::string & file_id) {
	std::string text;
	text = "";
	text = text + "file_id=" + file_id + "&";
	std::string tosend = generalToken + "/getFile?" + text;

	return getQuery(tosend);
}
inline void TelegramTypes::API::kickChatMember(const __int64 & user_id,
	const std::string & chat_id,
	const __int64 & until_date) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "until_date=" + std::to_string(until_date) + "&";
	std::string tosend = generalToken + "/kickChatMember?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::unbanChatMember(const __int64 & user_id,
	const std::string & chat_id,
	const bool & only_if_banned) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	if (only_if_banned) {
		text = text + "only_if_banned=true&";
	}
	else {
		text = text + "only_if_banned=false&";
	}
	std::string tosend = generalToken + "/unbanChatMember?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::restrictChatMember(const __int64 & user_id,
	const Json::Value & permissions,
	const std::string & chat_id,
	const __int64 & until_date) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, permissions);
	text = text + "permissions=" + result + "&";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "until_date=" + std::to_string(until_date) + "&";
	std::string tosend = generalToken + "/restrictChatMember?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::promoteChatMember(const __int64 & user_id,
	const std::string & chat_id,
	const bool & can_promote_members,
	const bool & can_change_info,
	const bool & can_post_messages,
	const bool & is_anonymous,
	const bool & can_delete_messages,
	const bool & can_invite_users,
	const bool & can_restrict_members,
	const bool & can_pin_messages,
	const bool & can_edit_messages) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	if (can_promote_members) {
		text = text + "can_promote_members=true&";
	}
	else {
		text = text + "can_promote_members=false&";
	}
	if (can_change_info) {
		text = text + "can_change_info=true&";
	}
	else {
		text = text + "can_change_info=false&";
	}
	if (can_post_messages) {
		text = text + "can_post_messages=true&";
	}
	else {
		text = text + "can_post_messages=false&";
	}
	if (is_anonymous) {
		text = text + "is_anonymous=true&";
	}
	else {
		text = text + "is_anonymous=false&";
	}
	if (can_delete_messages) {
		text = text + "can_delete_messages=true&";
	}
	else {
		text = text + "can_delete_messages=false&";
	}
	if (can_invite_users) {
		text = text + "can_invite_users=true&";
	}
	else {
		text = text + "can_invite_users=false&";
	}
	if (can_restrict_members) {
		text = text + "can_restrict_members=true&";
	}
	else {
		text = text + "can_restrict_members=false&";
	}
	if (can_pin_messages) {
		text = text + "can_pin_messages=true&";
	}
	else {
		text = text + "can_pin_messages=false&";
	}
	if (can_edit_messages) {
		text = text + "can_edit_messages=true&";
	}
	else {
		text = text + "can_edit_messages=false&";
	}
	std::string tosend = generalToken + "/promoteChatMember?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setChatAdministratorCustomTitle(const __int64 & user_id,
	const std::string & custom_title,
	const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "custom_title=" + custom_title + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/setChatAdministratorCustomTitle?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setChatPermissions(const Json::Value & permissions,
	const std::string & chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, permissions);
	text = text + "permissions=" + result + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/setChatPermissions?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::exportChatInviteLink(const std::string & chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/exportChatInviteLink?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setChatPhoto(const Json::Value & photo,
	const std::string & chat_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, photo);
	text = text + "photo=" + result + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/setChatPhoto?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::deleteChatPhoto(const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/deleteChatPhoto?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setChatTitle(const std::string & title,
	const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "title=" + title + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/setChatTitle?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setChatDescription(const std::string & chat_id,
	const std::string & description) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "description=" + description + "&";
	std::string tosend = generalToken + "/setChatDescription?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::pinChatMessage(const __int64 & message_id,
	const std::string & chat_id,
	const bool & disable_notification) {
	std::string text;
	text = "";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	if (disable_notification) {
		if (disable_notification) {
			text = text + "disable_notification=true&";
		}
		else {
			text = text + "disable_notification=false&";
		}
	}
	std::string tosend = generalToken + "/pinChatMessage?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::unpinChatMessage(const std::string & chat_id,
	const __int64 & message_id) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	if (message_id) {
		text = text + "message_id=" + std::to_string(message_id) + "&";
	}
	std::string tosend = generalToken + "/unpinChatMessage?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::unpinAllChatMessages(const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/unpinAllChatMessages?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::leaveChat(const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/leaveChat?" + text;
	sendQuery(tosend);
}
inline Json::Value TelegramTypes::API::getChat(const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "chat_id=" + "" + chat_id + "&";
	std::string tosend = generalToken + "/getChat?" + text;

	return getQuery(tosend);
}
inline Json::Value TelegramTypes::API::getChatAdministrators(const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/getChatAdministrators?" + text;

	return getQuery(tosend);
}
inline Json::Value TelegramTypes::API::getChatMembersCount(const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/getChatMembersCount?" + text;
	CURL * curl;
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
inline Json::Value TelegramTypes::API::getChatMember(const __int64 & user_id,
	const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/getChatMember?" + text;

	return getQuery(tosend);
}
inline void TelegramTypes::API::setChatStickerSet(const std::string & sticker_set_name,
	const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "sticker_set_name=" + sticker_set_name + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/setChatStickerSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::deleteChatStickerSet(const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/deleteChatStickerSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::answerCallbackQuery(const std::string & callback_query_id,
	const std::string & text,
	const bool & show_alert,
	const std::string & url,
	const __int64 & cache_time) {
	std::string text1;
	text1 = "";
	text1 = text1 + "callback_query_id=" + callback_query_id + "&";
	text1 = text1 + "text=" + text + "&";
	if (show_alert) {
		text1 = text1 + "show_alert=true&";
	}
	else {
		text1 = text1 + "show_alert=false&";
	}
	text1 = text1 + "url=" + url + "&";
	text1 = text1 + "cache_time=" + std::to_string(cache_time) + "&";
	std::string tosend = generalToken + "/answerCallbackQuery?" + text1;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setMyCommands(const Json::Value & commands) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, commands);
	text = text + "commands=" + result + "&";
	std::string tosend = generalToken + "/setMyCommands?" + text;
	sendQuery(tosend);
}
inline Json::Value TelegramTypes::API::getMyCommands(const std::string & text,
	const std::string & chat_id,
	const __int64 & message_id,
	const std::string & inline_message_id,
	const std::string & parse_mode,
	const Json::Value & entities,
	const bool & disable_web_page_preview,
	const Json::Value & reply_markup) {
	std::string text1;
	text1 = "";
	text1 = text1 + "text=" + text1 + "&";
	text1 = text1 + "chat_id=" + chat_id + "&";
	text1 = text1 + "message_id=" + std::to_string(message_id) + "&";
	text1 = text1 + "inline_message_id=" + inline_message_id + "&";
	text1 = text1 + "parse_mode=" + parse_mode + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, entities);
	text1 = text1 + "entities=" + result + "&";
	if (disable_web_page_preview) {
		text1 = text1 + "disable_web_page_preview=true&";
	}
	else {
		text1 = text1 + "disable_web_page_preview=false&";
	}
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text1 = text1 + "reply_markup=" + result + "&";
	std::string tosend = generalToken + "/getMyCommands?" + text1;

	return getQuery(tosend);
}
inline void TelegramTypes::API::editMessageCaption(const std::string & chat_id,
	const __int64 & message_id,
	const std::string & inline_message_id,
	const std::string & caption,
	const std::string & parse_mode,
	const Json::Value & caption_entities,
	const Json::Value & reply_markup) {
	std::string text;
	text = "";

	text = text + "chat_id=" + chat_id + "&";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "inline_message_id=" + inline_message_id + "&";
	text = text + "caption=" + caption + "&";
	text = text + "parse_mode=" + parse_mode + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, caption_entities);
	text = text + "caption_entities=" + result + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";
	std::string tosend = generalToken + "/editMessageCaption?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::editMessageMedia(const Json::Value & media,
	const std::string & chat_id,
	const __int64 & message_id,
	const std::string & inline_message_id,
	const Json::Value & reply_markup) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, media);
	text = text + "media=" + result + "&";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "inline_message_id=" + inline_message_id + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";
	std::string tosend = generalToken + "/editMessageMedia?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::editMessageReplyMarkup(const std::string & chat_id,
	const __int64 & message_id,
	const std::string & inline_message_id,
	const Json::Value & reply_markup) {
	std::string text;
	text = "";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "inline_message_id=" + inline_message_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";
	std::string tosend = generalToken + "/editMessageReplyMarkup?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::stopPoll(const __int64 & message_id,
	const std::string & chat_id,
	const Json::Value & reply_markup) {
	std::string text;
	text = "";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";
	std::string tosend = generalToken + "/stopPoll?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::deleteMessage(const __int64 & message_id,
	const std::string & chat_id) {
	std::string text;
	text = "";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/deleteMessage?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendSticker(const Json::Value & sticker,
	const std::string & chat_id,
	const bool & disable_notification,
	const __int64 & reply_to_message_id,
	const bool & allow_sending_without_reply,
	const Json::Value & reply_markup) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, sticker);
	text = text + "sticker=" + result + "&";
	text = text + "chat_id=" + chat_id + "&";
	if (disable_notification) {
		text = text + "disable_notification=true&";
	}
	else {
		text = text + "disable_notification=false&";
	}
	text = text + "reply_to_message_id=" + std::to_string(reply_to_message_id) + "&";
	if (allow_sending_without_reply) {
		text = text + "allow_sending_without_reply=true&";
	}
	else {
		text = text + "allow_sending_without_reply=false&";
	}
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + result + "&";
	std::string tosend = generalToken + "/sendSticker?" + text;
	sendQuery(tosend);
}
inline Json::Value TelegramTypes::API::getStickerSet(const std::string & name) {
	std::string text;
	text = "";
	text = text + "name=" + name + "&";
	std::string tosend = generalToken + "/getStickerSet?" + text;

	return getQuery(tosend);
}
inline void TelegramTypes::API::uploadStickerFile(const Json::Value & png_sticker,
	const __int64 & user_id) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, png_sticker);
	text = text + "png_sticker=" + result + "&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string tosend = generalToken + "/uploadStickerFile?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::createNewStickerSet(const std::string & emojis,
	const std::string & title,
	const __int64 & user_id,
	const std::string & name,
	const Json::Value & png_sticker,
	const Json::Value & tgs_sticker,
	const bool & contains_masks,
	const Json::Value & mask_position) {
	std::string text;
	text = "";
	text = text + "emojis=" + emojis + "&";
	text = text + "title=" + title + "&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "name=" + name + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, png_sticker);
	text = text + "png_sticker=" + result + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, tgs_sticker);
	text = text + "tgs_sticker=" + result + "&";
	if (contains_masks) {
		text = text + "contains_masks=true&";
	}
	else {
		text = text + "contains_masks=false&";
	}
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, mask_position);
	text = text + "mask_position=" + result + "&";
	std::string tosend = generalToken + "/createNewStickerSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::addStickerToSet(const std::string & name,
	const std::string & emojis,
	const __int64 & user_id,
	const Json::Value & png_sticker,
	const Json::Value & tgs_sticker,
	const Json::Value & mask_position) {
	std::string text;
	text = "";
	text = text + "name=" + name + "&";
	text = text + "emojis=" + emojis + "&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, png_sticker);
	text = text + "png_sticker=" + result + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, tgs_sticker);
	text = text + "tgs_sticker=" + result + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, mask_position);
	text = text + "mask_position=" + result + "&";
	std::string tosend = generalToken + "/addStickerToSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setStickerPositionInSet(const __int64 & position,
	const std::string & sticker) {
	std::string text;
	text = "";
	text = text + "position=" + std::to_string(position) + "&";
	text = text + "sticker=" + sticker + "&";
	std::string tosend = generalToken + "/setStickerPositionInSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::deleteStickerFromSet(const std::string & sticker) {
	std::string text;
	text = "";
	text = text + "sticker=" + sticker + "&";
	std::string tosend = generalToken + "/deleteStickerFromSet?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setStickerSetThumb(const __int64 & user_id,
	const std::string & name,
	const Json::Value & thumb) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "name=" + name + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, thumb);
	text = text + "thumb=" + result + "&";
	std::string tosend = generalToken + "/setStickerSetThumb?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::sendQuery(std::string & query) {
	CURL * curl;
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
inline Json::Value TelegramTypes::API::getQuery(std::string & query) {
	CURL * curl;
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
	return Json::Value(readBuffer);
}
inline void TelegramTypes::API::answerInlineQuery(const Json::Value & results,
	const std::string & inline_query_id,
	const __int64 & cache_time,
	const bool & is_personal,
	const std::string & next_offset,
	const std::string & switch_pm_text,
	const std::string & switch_pm_parameter) {
	std::string text;
	text = "";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, results);
	text = text + "results=" + result + "&";
	text = text + "inline_query_id=" + inline_query_id + "&";
	text = text + "cache_time=" + std::to_string(cache_time) + "&";
	if (is_personal) {
		text = text + "is_personal=true&";
	}
	else {
		text = text + "is_personal=false&";
	}
	text = text + "next_offset=" + next_offset + "&";
	text = text + "switch_pm_text=" + switch_pm_text + "&";
	text = text + "switch_pm_parameter=" + switch_pm_parameter + "&";
	std::string tosend = generalToken + "/answerInlineQuery?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::answerShippingQuery(const bool & ok,
	const std::string & shipping_query_id,
	const Json::Value & shipping_options,
	const std::string & error_message) {
	std::string text;
	text = "";
	if (ok) {
		text = text + "ok=true&";
	}
	else {
		text = text + "ok=false&";
	}
	text = text + "shipping_query_id=" + shipping_query_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, shipping_options);
	text = text + "shipping_options=" + "[" + result + "]&";
	text = text + "error_message=" + error_message + "&";
	std::string tosend = generalToken + "/answerShippingQuery?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::answerPreCheckoutQuery(const std::string & pre_checkout_query_id,
	const bool & ok,
	const std::string & error_message) {
	std::string text;
	text = "";
	text = text + "pre_checkout_query_id=" + pre_checkout_query_id + "&";
	if (ok) {
		if (ok) {
			text = text + "ok=true&";
		}
		else {
			text = text + "ok=false&";
		}
	}
	text = text + "error_message=" + error_message + "&";
	std::string tosend = generalToken + "/answerPreCheckoutQuery?" + text;
	sendQuery(tosend);
}
inline void TelegramTypes::API::setPassportDataErrors(const Json::Value & errors,
	const __int64 & user_id) {
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
inline Json::Value TelegramTypes::API::getGameHighScores(const __int64 & user_id,
	const __int64 & chat_id,
	const __int64 & message_id,
	const std::string & inline_message_id) {
	std::string text;
	text = "";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "chat_id=" + std::to_string(chat_id) + "&";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "inline_message_id=" + inline_message_id + "&";
	std::string tosend = generalToken + "/getGameHighScores?" + text;

	return getQuery(tosend);
}
