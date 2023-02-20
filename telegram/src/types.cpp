#include "../include/types.h"

size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
void Telegram::Bot::Types::API::sendMessage(const std::string& chat_id,
	const std::string& msgp,
	const std::string& parse_mode,
	const bool& disable_web_page_preview,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const Json::Value& reply_markup) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id;
	text = text + "&text=" + msgp;
	
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
	text = text + "&reply_markup=" + (result.size()==2?"":result) + "&";
	
	std::string tosend = "/sendMessage?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::sendDocument(const std::string& chat_id,
	const std::string& mime_type,
	const std::string& document,
	const std::string& mime_thumb,
	const std::string& thumb,
	const std::string& caption,
	const std::string& parse_mode,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const std::string& reply_markup) const {
	
	std::string text;
	
	text = text + "/sendDocument";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&parse_mode=" + parse_mode;

	if (mime_thumb == "") {
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
		request->sendFile(text, "document", document, mime_thumb, thumb);
	}
	else {
		text = text + "&document=" + document;
		request->sendHttp(text);
	}
}
void Telegram::Bot::Types::API::sendPhoto(const std::string& chat_id,
	const std::string& mime_type,
	const std::string& photo,
	const std::string& caption,
	const std::string& parse_mode,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const std::string& reply_markup) const {
	std::string text;
	
	text = text + "/sendPhoto";
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
	
	if (mime_type != "") {
		request->sendFile(text, "photo", photo);
	}
	else {
		text = text + "&photo=" + photo;
		request->sendHttp(text);
	}
}
void Telegram::Bot::Types::API::sendAudio(const std::string& chat_id,
	const std::string& mime_type,
	const std::string& audio,
	const std::string& caption,
	const std::string& parse_mode,
	const __int64& duration,
	const __int64& performer,
	const std::string& title,
	const std::string& mime_thumb,
	const std::string& thumb,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const std::string& reply_markup) const {
	
	std::string text;
	
	text = text + "/sendAudio";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&parse_mode=" + parse_mode;
	text = text + "&duration=" + std::to_string(duration);
	text = text + "&performer=" + std::to_string(performer);
	text = text + "&title=" + title;
	if (mime_thumb == "") {
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
		request->sendFile(text, "audio", audio, mime_thumb, thumb);
	}
	else {
		text = text + "&audio=" + audio;
		request->sendHttp(text);
	}
}
void Telegram::Bot::Types::API::sendAnimation(const std::string& chat_id,
	const std::string& mime_type,
	const std::string& animation,
	const __int64& duration,
	const __int64& width,
	const __int64& height,
	const std::string& mime_thumb,
	const std::string& thumb,
	const std::string& caption,
	const std::string& parse_mode,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const std::string& reply_markup) const {
	
	std::string text;
	
	text = text + "/sendAnimation";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&parse_mode=" + parse_mode;
	text = text + "&duration=" + std::to_string(duration);
	text = text + "&width=" + std::to_string(width);
	text = text + "&height=" + std::to_string(height);
	if (mime_thumb == "") {
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
		request->sendFile(text, "animation", animation, mime_thumb, thumb);
	}
	else {
		text = text + "&animation=" + animation;
		request->sendHttp(text);
	}
}
void Telegram::Bot::Types::API::sendVoice(const std::string& chat_id,
	const std::string& mime_type,
	const std::string& voice,
	const std::string& caption,
	const std::string& parse_mode,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const std::string& reply_markup) const {
	
	std::string text;
	
	text = text + "/sendVoice";
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
	if (mime_type != "") {
		request->sendFile(text, "voice", voice);
	}
	else {
		text = text + "&voice=" + voice;
		request->sendHttp(text);
	}
}
void Telegram::Bot::Types::API::sendVideoNote(const std::string& chat_id,
	const std::string& mime_type,
	const std::string& video_note,
	const __int64& duration,
	const __int64& length,
	const std::string& mime_thumb,
	const std::string& thumb,
	const std::string& caption,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const std::string& reply_markup) const {
	
	std::string text;
	
	text = text + "/sendVideoNote";
	text = text + "?chat_id=" + chat_id;
	text = text + "&caption=" + caption;
	text = text + "&duration=" + std::to_string(duration);
	text = text + "&length=" + std::to_string(length);
	if (mime_thumb == "") {
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
		request->sendFile(text, "video_note", video_note, mime_thumb, thumb);
	}
	else {
		text = text + "&video_note=" + video_note;
		request->sendHttp(text);
	}
}
void Telegram::Bot::Types::API::sendVideo(const std::string& chat_id,
	const std::string& mime_type,
	const std::string& video,
	const __int64& duration,
	const __int64& width,
	const __int64& height,
	const std::string& mime_thumb,
	const std::string& thumb,
	const std::string& caption,
	const std::string& parse_mode,
	const bool& supports_streaming,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const std::string& reply_markup) const {
	
	std::string text;
	
	text = text + "/sendVideo";
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
	
	if (mime_thumb == "") {
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
		request->sendFile(text, "video", video, mime_thumb, thumb);
	}
	else {
		text = text + "&video=" + video;
		request->sendHttp(text);
	}
}
void Telegram::Bot::Types::API::sendMediaGroup(const std::string& chat_id,
	const std::string& mime_type,
	const std::vector < std::shared_ptr < InputMediaPhoto >>& media,
	const bool& disable_notification,
	const __int64& reply_to_message_id) const {
	std::string text;
	text = text + "/sendMediaGroup";
	text = text + "?chat_id=" + chat_id;
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
		std::vector<std::string> paths;
		for (__int64 i = 0; i < media.size(); i++) {
			paths.push_back(media.at(i)->media);
		}
		request->sendMultiFile(text, "photo", paths);
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
		request->sendHttp(text);
	}
}
void Telegram::Bot::Types::API::sendMediaGroup(const std::string& chat_id,
	const std::string& mime_type,
	const std::vector < std::shared_ptr < InputMediaVideo >>& media,
	const bool& disable_notification,
	const __int64& reply_to_message_id) const {
	std::string text;
	text = text + "/sendMediaGroup";
	text = text + "?chat_id=" + chat_id;
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
		std::vector<std::string> paths;
		for (__int64 i = 0; i < media.size(); i++) {
			paths.push_back(media.at(i)->media);
		}
		request->sendMultiFile(text, "photo", paths);
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
		request->sendHttp(text);
	}
}
void Telegram::Bot::Types::API::copyMessage(const Json::Value& from_chat_id,
	const std::string& chat_id,
	const Json::Value& reply_markup,
	const std::string& caption,
	const std::string& parse_mode,
	const __int64& message_id,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const bool& allow_sending_without_reply,
	const Json::Value& caption_entities) const {
	std::string text;
	
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, from_chat_id);
	text = text + "from_chat_id=" + (result.size()==2?"":result) + "&";
	text = text + "chat_id=" + chat_id + "&";

	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";

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
	text = text + "caption_entities=" + (result.size()==2?"":result) + "&";

	std::string tosend = generalToken + "/copyMessage?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::sendLocation(const float& latitude,
	const float& longitude,
	const std::string& chat_id,
	const Json::Value& reply_markup,
	const __int64& live_period,
	const float& horizontal_accuracy,
	const __int64& proximity_alert_radius,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const bool& allow_sending_without_reply,
	const __int64& heading) const {
	std::string text;
	
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";
	text = text + "chat_id=" + chat_id + "&";

	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";

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
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::editMessageLiveLocation(const float& latitude,
	const float& longitude,
	const Json::Value& reply_markup,
	const std::string& inline_message_id,
	const __int64& message_id,
	const float& horizontal_accuracy,
	const __int64& heading,
	const __int64& proximity_alert_radius,
	const std::string& chat_id) const {
	std::string text;
	
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";

	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";

	text = text + "inline_message_id=" + inline_message_id + "&";

	text = text + "message_id=" + std::to_string(message_id) + "&";

	text = text + "=" + std::to_string(horizontal_accuracy) + "&";

	text = text + "heading=" + std::to_string(heading) + "&";

	text = text + "proximity_alert_radius=" + std::to_string(proximity_alert_radius) + "&";

	text = text + "chat_id=" + chat_id + "&";

	std::string tosend = generalToken + "/editMessageLiveLocation?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::stopMessageLiveLocation(const std::string& chat_id,
	const __int64& message_id,
	const std::string& inline_message_id,
	const Json::Value& reply_markup) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "inline_message_id=" + inline_message_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/stopMessageLiveLocation?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::sendVenue(const float& latitude,
	const float& longitude,
	const std::string& title,
	const std::string& address,
	const std::string& chat_id,
	const Json::Value& reply_markup,
	const std::string& foursquare_id,
	const std::string& google_place_id,
	const std::string& google_place_type,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const bool& allow_sending_without_reply,
	const std::string& foursquare_type) const {
	std::string text;
	
	text = text + "=" + std::to_string(latitude) + "&";
	text = text + "=" + std::to_string(longitude) + "&";
	text = text + "title=" + title + "&";
	text = text + "address=" + address + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";
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
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::sendContact(const std::string& phone_number,
	const std::string& first_name,
	const std::string& chat_id,
	const Json::Value& reply_markup,
	const std::string& last_name,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const bool& allow_sending_without_reply,
	const std::string& vcard) const {
	std::string text;
	
	text = text + "phone_number=" + phone_number + "&";
	text = text + "first_name=" + first_name + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";
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
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::sendPoll(const std::string& question,
	const Json::Value& options,
	const std::string& chat_id,
	const Json::Value& reply_markup,
	const std::string& explanation_parse_mode,
	const __int64& open_period,
	const std::string& type,
	const __int64& close_date,
	const __int64& correct_option_id,
	const bool& is_closed,
	const bool& allows_multiple_answers,
	const std::string& explanation,
	const Json::Value& explanation_entities,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const bool& allow_sending_without_reply,
	const bool& is_anonymous) const {
	std::string text;
	
	text = text + "question=" + question + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, options);
	text = text + "options=" + (result.size()==2?"":result) + "&";
	text = text + "chat_id=" + chat_id + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";
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
	text = text + "explanation_entities=" + (result.size()==2?"":result) + "&";
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
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::sendDice(const std::string& chat_id,
	const std::string& emoji,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const bool& allow_sending_without_reply,
	const Json::Value& reply_markup) const {
	std::string text;
	
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
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/sendDice?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::sendChatAction(const std::string& chat_id,
	const std::string& action) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	text = text + "action=" + action + "&";
	std::string tosend = generalToken + "/sendChatAction?" + text;
	request->sendHttp(tosend);
}
Json::Value Telegram::Bot::Types::API::getUserProfilePhotos(const __int64& user_id,
	const __int64& offset,
	const __int64& limit) const {
	std::string text;
	
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "m_offset=" + std::to_string(offset) + "&";
	text = text + "limit=" + std::to_string(limit) + "&";
	std::string tosend = generalToken + "/getUserProfilePhotos?" + text;

	return request->sendHttp(tosend);
}
Json::Value Telegram::Bot::Types::API::getFile(const std::string& file_id) {
	std::string text;
	
	text = text + "file_id=" + file_id + "&";
	std::string tosend = generalToken + "/getFile?" + text;

	return request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::kickChatMember(const __int64& user_id,
	const std::string& chat_id,
	const __int64& until_date) const {
	std::string text;
	
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "until_date=" + std::to_string(until_date) + "&";
	std::string tosend = generalToken + "/kickChatMember?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::unbanChatMember(const __int64& user_id,
	const std::string& chat_id,
	const bool& only_if_banned) const {
	std::string text;
	
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	if (only_if_banned) {
		text = text + "only_if_banned=true&";
	}
	else {
		text = text + "only_if_banned=false&";
	}
	std::string tosend = generalToken + "/unbanChatMember?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::restrictChatMember(const __int64& user_id,
	const Json::Value& permissions,
	const std::string& chat_id,
	const __int64& until_date) const {
	std::string text;
	
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, permissions);
	text = text + "permissions=" + (result.size()==2?"":result) + "&";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "until_date=" + std::to_string(until_date) + "&";
	std::string tosend = generalToken + "/restrictChatMember?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::promoteChatMember(const __int64& user_id,
	const std::string& chat_id,
	const bool& can_promote_members,
	const bool& can_change_info,
	const bool& can_post_messages,
	const bool& is_anonymous,
	const bool& can_delete_messages,
	const bool& can_invite_users,
	const bool& can_restrict_members,
	const bool& can_pin_messages,
	const bool& can_edit_messages) const {
	std::string text;
	
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
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::setChatAdministratorCustomTitle(const __int64& user_id,
	const std::string& custom_title,
	const std::string& chat_id) const {
	std::string text;
	
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "custom_title=" + custom_title + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/setChatAdministratorCustomTitle?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::setChatPermissions(const Json::Value& permissions,
	const std::string& chat_id) const {
	std::string text;
	
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, permissions);
	text = text + "permissions=" + (result.size()==2?"":result) + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/setChatPermissions?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::exportChatInviteLink(const std::string& chat_id) const {
	std::string text;
	
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/exportChatInviteLink?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::setChatPhoto(const Json::Value& photo,
	const std::string& chat_id) const {
	std::string text;
	
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, photo);
	text = text + "photo=" + (result.size()==2?"":result) + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/setChatPhoto?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::deleteChatPhoto(const std::string& chat_id) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/deleteChatPhoto?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::setChatTitle(const std::string& title,
	const std::string& chat_id) const {
	std::string text;
	
	text = text + "title=" + title + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/setChatTitle?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::setChatDescription(const std::string& chat_id,
	const std::string& description) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	text = text + "description=" + description + "&";
	std::string tosend = generalToken + "/setChatDescription?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::pinChatMessage(const __int64& message_id,
	const std::string& chat_id,
	const bool& disable_notification) const {
	std::string text;
	
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
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::unpinChatMessage(const std::string& chat_id,
	const __int64& message_id) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	if (message_id) {
		text = text + "message_id=" + std::to_string(message_id) + "&";
	}
	std::string tosend = generalToken + "/unpinChatMessage?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::unpinAllChatMessages(const std::string& chat_id) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/unpinAllChatMessages?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::leaveChat(const std::string& chat_id) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/leaveChat?" + text;
	request->sendHttp(tosend);
}
Json::Value Telegram::Bot::Types::API::getChat(const std::string& chat_id) const {
	std::string text;
	
	text = text + "chat_id=" + "" + chat_id + "&";
	std::string tosend = "/getMe";
    ns::User user;
    auto n=request->sendHttp(tosend);
    nlohmann::json j=nlohmann::json::parse(n.asString());
    std::cout<<j["result"];
    const nlohmann::json u=j["result"];
    ns::from_json(u,user);
	return Json::Value();
}
Json::Value Telegram::Bot::Types::API::getChatAdministrators(const std::string& chat_id) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/getChatAdministrators?" + text;

	return request->sendHttp(tosend);
}
Json::Value Telegram::Bot::Types::API::getChatMembersCount(const std::string& chat_id) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/getChatMembersCount?" + text;
	
	
	return request->sendHttp(tosend);
}
Json::Value Telegram::Bot::Types::API::getChatMember(const __int64& user_id,
	const std::string& chat_id) const {
	std::string text;
	
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/getChatMember?" + text;

	return request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::setChatStickerSet(const std::string& sticker_set_name,
	const std::string& chat_id) const {
	std::string text;
	
	text = text + "sticker_set_name=" + sticker_set_name + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/setChatStickerSet?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::deleteChatStickerSet(const std::string& chat_id) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/deleteChatStickerSet?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::answerCallbackQuery(const std::string& callback_query_id,
	const std::string& text,
	const bool& show_alert,
	const std::string& url,
	const __int64& cache_time) const {
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
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::setMyCommands(const Json::Value& commands) {
	std::string text;
	
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, commands);
	text = text + "commands=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/setMyCommands?" + text;
	request->sendHttp(tosend);
}
Json::Value Telegram::Bot::Types::API::getMyCommands(const std::string& text,
	const std::string& chat_id,
	const __int64& message_id,
	const std::string& inline_message_id,
	const std::string& parse_mode,
	const Json::Value& entities,
	const bool& disable_web_page_preview,
	const Json::Value& reply_markup) const {
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
	text1 = text1 + "entities=" + (result.size()==2?"":result) + "&";
	if (disable_web_page_preview) {
		text1 = text1 + "disable_web_page_preview=true&";
	}
	else {
		text1 = text1 + "disable_web_page_preview=false&";
	}
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text1 = text1 + "reply_markup=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/getMyCommands?" + text1;

	return request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::editMessageCaption(const std::string& chat_id,
	const __int64& message_id,
	const std::string& inline_message_id,
	const std::string& caption,
	const std::string& parse_mode,
	const Json::Value& caption_entities,
	const Json::Value& reply_markup) const {
	std::string text;
	

	text = text + "chat_id=" + chat_id + "&";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "inline_message_id=" + inline_message_id + "&";
	text = text + "caption=" + caption + "&";
	text = text + "parse_mode=" + parse_mode + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, caption_entities);
	text = text + "caption_entities=" + (result.size()==2?"":result) + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/editMessageCaption?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::editMessageMedia(const Json::Value& media,
	const std::string& chat_id,
	const __int64& message_id,
	const std::string& inline_message_id,
	const Json::Value& reply_markup) const {
	std::string text;
	
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, media);
	text = text + "media=" + (result.size()==2?"":result) + "&";
	text = text + "chat_id=" + chat_id + "&";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "inline_message_id=" + inline_message_id + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/editMessageMedia?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::editMessageReplyMarkup(const std::string& chat_id,
	const __int64& message_id,
	const std::string& inline_message_id,
	const Json::Value& reply_markup) const {
	std::string text;
	
	text = text + "chat_id=" + chat_id + "&";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "inline_message_id=" + inline_message_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/editMessageReplyMarkup?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::stopPoll(const __int64& message_id,
	const std::string& chat_id,
	const Json::Value& reply_markup) const {
	std::string text;
	
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, reply_markup);
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/stopPoll?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::deleteMessage(const __int64& message_id,
	const std::string& chat_id) const {
	std::string text;
	
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "chat_id=" + chat_id + "&";
	std::string tosend = generalToken + "/deleteMessage?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::sendSticker(const Json::Value& sticker,
	const std::string& chat_id,
	const bool& disable_notification,
	const __int64& reply_to_message_id,
	const bool& allow_sending_without_reply,
	const Json::Value& reply_markup) const {
	std::string text;
	
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, sticker);
	text = text + "sticker=" + (result.size()==2?"":result) + "&";
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
	text = text + "reply_markup=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/sendSticker?" + text;
	request->sendHttp(tosend);
}
Json::Value Telegram::Bot::Types::API::getStickerSet(const std::string& name) {
	std::string text;
	
	text = text + "name=" + name + "&";
	std::string tosend = generalToken + "/getStickerSet?" + text;

	return request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::uploadStickerFile(const Json::Value& png_sticker,
	const __int64& user_id) {
	std::string text;
	
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, png_sticker);
	text = text + "png_sticker=" + (result.size()==2?"":result) + "&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string tosend = generalToken + "/uploadStickerFile?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::createNewStickerSet(const std::string& emojis,
	const std::string& title,
	const __int64& user_id,
	const std::string& name,
	const Json::Value& png_sticker,
	const Json::Value& tgs_sticker,
	const bool& contains_masks,
	const Json::Value& mask_position) const {
	std::string text;
	
	text = text + "emojis=" + emojis + "&";
	text = text + "title=" + title + "&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "name=" + name + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, png_sticker);
	text = text + "png_sticker=" + (result.size()==2?"":result) + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, tgs_sticker);
	text = text + "tgs_sticker=" + (result.size()==2?"":result) + "&";
	if (contains_masks) {
		text = text + "contains_masks=true&";
	}
	else {
		text = text + "contains_masks=false&";
	}
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, mask_position);
	text = text + "mask_position=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/createNewStickerSet?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::addStickerToSet(const std::string& name,
	const std::string& emojis,
	const __int64& user_id,
	const Json::Value& png_sticker,
	const Json::Value& tgs_sticker,
	const Json::Value& mask_position) const {
	std::string text;
	
	text = text + "name=" + name + "&";
	text = text + "emojis=" + emojis + "&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, png_sticker);
	text = text + "png_sticker=" + (result.size()==2?"":result) + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, tgs_sticker);
	text = text + "tgs_sticker=" + (result.size()==2?"":result) + "&";
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, mask_position);
	text = text + "mask_position=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/addStickerToSet?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::setStickerPositionInSet(const __int64& position,
	const std::string& sticker) {
	std::string text;
	
	text = text + "position=" + std::to_string(position) + "&";
	text = text + "sticker=" + sticker + "&";
	std::string tosend = generalToken + "/setStickerPositionInSet?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::deleteStickerFromSet(const std::string& sticker) {
	std::string text;
	
	text = text + "sticker=" + sticker + "&";
	std::string tosend = generalToken + "/deleteStickerFromSet?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::setStickerSetThumb(const __int64& user_id,
	const std::string& name,
	const Json::Value& thumb) const {
	std::string text;
	
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "name=" + name + "&";
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, thumb);
	text = text + "thumb=" + (result.size()==2?"":result) + "&";
	std::string tosend = generalToken + "/setStickerSetThumb?" + text;
	request->sendHttp(tosend);
}

void Telegram::Bot::Types::API::answerInlineQuery(const Json::Value& results,
	const std::string& inline_query_id,
	const __int64& cache_time,
	const bool& is_personal,
	const std::string& next_offset,
	const std::string& switch_pm_text,
	const std::string& switch_pm_parameter) const {
	std::string text;
	
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, results);
	text = text + "results=" + (result.size()==2?"":result) + "&";
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
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::answerShippingQuery(const bool& ok,
	const std::string& shipping_query_id,
	const Json::Value& shipping_options,
	const std::string& error_message) const {
	std::string text;
	
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
	text = text + "shipping_options=" + "[" + (result.size()==2?"":result) + "]&";
	text = text + "error_message=" + error_message + "&";
	std::string tosend = generalToken + "/answerShippingQuery?" + text;
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::answerPreCheckoutQuery(const std::string& pre_checkout_query_id,
	const bool& ok,
	const std::string& error_message) const {
	std::string text;
	
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
	request->sendHttp(tosend);
}
void Telegram::Bot::Types::API::setPassportDataErrors(const Json::Value& errors,
	const __int64& user_id) const {
	std::string text;
	
	std::string result;
	Json::StreamWriterBuilder wbuilder;
	wbuilder["indentation"] = "";
	result = Json::writeString(wbuilder, errors);
	text = text + "errors=" + "[" + (result.size()==2?"":result) + "]&";
	text = text + "user_id=" + std::to_string(user_id) + "&";
	std::string tosend = generalToken + "/setPassportDataErrors?" + text;
	request->sendHttp(tosend);
}
Json::Value Telegram::Bot::Types::API::getGameHighScores(const __int64& user_id,
	const __int64& chat_id,
	const __int64& message_id,
	const std::string& inline_message_id) const {
	std::string text;
	
	text = text + "user_id=" + std::to_string(user_id) + "&";
	text = text + "chat_id=" + std::to_string(chat_id) + "&";
	text = text + "message_id=" + std::to_string(message_id) + "&";
	text = text + "inline_message_id=" + inline_message_id + "&";
	std::string tosend = generalToken + "/getGameHighScores?" + text;

	return request->sendHttp(tosend);
}

