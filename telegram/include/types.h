#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
#include "types_generator.h"
#include <cpr/cpr.h>
#include "network/Network.h"

using json = nlohmann::json;

namespace Telegram {
    namespace Bot {
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
                inline void
                logOut(int chat_id, std::string text, std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                       bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                       bool protect_content = false, bool disable_notification = false,
                       bool disable_web_page_preview = false,
                       std::vector<std::shared_ptr<MessageEntity>> entities = std::vector<std::shared_ptr<MessageEntity>>(),
                       std::string parse_mode = "", int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["text"] = text;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["disable_web_page_preview"] = disable_web_page_preview;
                    json j8 = json::object();
                    if (!entities.empty()) {
                        for (const auto a: entities) {
                            json j9 = json::object();
                            to_json(j9, *a);
                            j8.push_back(j9);
                        }
                        payload1["entities"] = j8;
                    }
                    payload1["parse_mode"] = parse_mode;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/logOut", result1);
                }

// Use this method to close the bot instance before moving it from one local server to another. You need to delete the webhook before calling this method to ensure that the bot isn&#39;t launched again after server restart. The method will return error 429 in the first 10 minutes after the bot is launched. Returns <em>True</em> on success. Requires no parameters.
                inline void
                close(int chat_id, std::string text, std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                      bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                      bool protect_content = false, bool disable_notification = false,
                      bool disable_web_page_preview = false,
                      std::vector<std::shared_ptr<MessageEntity>> entities = std::vector<std::shared_ptr<MessageEntity>>(),
                      std::string parse_mode = "", int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["text"] = text;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["disable_web_page_preview"] = disable_web_page_preview;
                    json j8 = json::object();
                    if (!entities.empty()) {
                        for (const auto a: entities) {
                            json j9 = json::object();
                            to_json(j9, *a);
                            j8.push_back(j9);
                        }
                        payload1["entities"] = j8;
                    }
                    payload1["parse_mode"] = parse_mode;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/close", result1);
                }

// Use this method to send text messages. On success, the sent <a href="#message">Message</a> is returned.
                inline void
                sendMessage(int chat_id, std::string text, std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                            bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                            bool protect_content = false, bool disable_notification = false,
                            bool disable_web_page_preview = false,
                            std::vector<std::shared_ptr<MessageEntity>> entities = std::vector<std::shared_ptr<MessageEntity>>(),
                            std::string parse_mode = "", int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["text"] = text;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["disable_web_page_preview"] = disable_web_page_preview;
                    json j8 = json::object();
                    if (!entities.empty()) {
                        for (const auto a: entities) {
                            json j9 = json::object();
                            to_json(j9, *a);
                            j8.push_back(j9);
                        }
                        payload1["entities"] = j8;
                    }
                    payload1["parse_mode"] = parse_mode;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendMessage", result1);
                }

// Use this method to forward messages of any kind. Service messages can&#39;t be forwarded. On success, the sent <a href="#message">Message</a> is returned.
                inline void forwardMessage(int chat_id, int from_chat_id, int message_id, bool protect_content = false,
                                           bool disable_notification = false, int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["from_chat_id"] = from_chat_id;
                    payload1["message_id"] = message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/forwardMessage", result1);
                }

// Use this method to copy messages of any kind. Service messages and invoice messages can&#39;t be copied. A quiz <a href="#poll">poll</a> can be copied only if the value of the field <em>correct_option_id</em> is known to the bot. The method is analogous to the method <a href="#forwardmessage">forwardMessage</a>, but the copied message doesn&#39;t have a link to the original message. Returns the <a href="#messageid">MessageId</a> of the sent message on success.
                inline void copyMessage(int chat_id, int from_chat_id, int message_id,
                                        std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                        bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                        bool protect_content = false, bool disable_notification = false,
                                        std::vector<std::shared_ptr<MessageEntity>> caption_entities = std::vector<std::shared_ptr<MessageEntity>>(),
                                        std::string parse_mode = "", std::string caption = "",
                                        int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["from_chat_id"] = from_chat_id;
                    payload1["message_id"] = message_id;
                    if (reply_markup != nullptr) {
                        json j3;
                        to_json(j3, *reply_markup);
                        payload1["reply_markup"] = j3;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    json j8 = json::object();
                    if (!caption_entities.empty()) {
                        for (const auto a: caption_entities) {
                            json j9 = json::object();
                            to_json(j9, *a);
                            j8.push_back(j9);
                        }
                        payload1["caption_entities"] = j8;
                    }
                    payload1["parse_mode"] = parse_mode;
                    payload1["caption"] = caption;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/copyMessage", result1);
                }

// Use this method to send photos. On success, the sent <a href="#message">Message</a> is returned.
                inline void
                sendPhoto(int chat_id, std::string photo, std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                          bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                          bool protect_content = false, bool disable_notification = false, bool has_spoiler = false,
                          std::vector<std::shared_ptr<MessageEntity>> caption_entities = std::vector<std::shared_ptr<MessageEntity>>(),
                          std::string parse_mode = "", std::string caption = "", int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;

                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["has_spoiler"] = has_spoiler;
                    json j8 = json::object();
                    if (!caption_entities.empty()) {
                        for (const auto a: caption_entities) {
                            json j9 = json::object();
                            to_json(j9, *a);
                            j8.push_back(j9);
                        }
                        payload1["caption_entities"] = j8;
                    }
                    if (parse_mode != "") {
                        payload1["parse_mode"] = parse_mode;
                    }
                    if (caption != "") {
                        payload1["caption"] = caption;
                    }
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendFile("/sendPhoto", result1, Telegram::MediaType::PHOTO, photo);
                }

// Use this method to send audio files, if you want Telegram clients to display them in the music player. Your audio must be in the .MP3 or .M4A format. On success, the sent <a href="#message">Message</a> is returned. Bots can currently send audio files of up to 50 MB in size, this limit may be changed in the future.
                inline void
                sendAudio(int chat_id, std::string audio, std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                          bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                          bool protect_content = false, bool disable_notification = false, std::string thumb = "",
                          std::string title = "", std::string performer = "", int duration = 0,
                          std::vector<std::shared_ptr<MessageEntity>> caption_entities = std::vector<std::shared_ptr<MessageEntity>>(),
                          std::string parse_mode = "", std::string caption = "", int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["audio"] = audio;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["thumb"] = thumb;
                    payload1["title"] = title;
                    payload1["performer"] = performer;
                    payload1["duration"] = duration;
                    json j11 = json::object();
                    if (!caption_entities.empty()) {
                        for (const auto a: caption_entities) {
                            json j12 = json::object();
                            to_json(j12, *a);
                            j11.push_back(j12);
                        }
                        payload1["caption_entities"] = j11;
                    }
                    if (parse_mode != "") {
                        payload1["parse_mode"] = parse_mode;
                    }
                    if (caption != "") {
                        payload1["caption"] = caption;
                    }
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendFile("/sendAudio", result1, Telegram::MediaType::AUDIO, audio);
                }

// Use this method to send general files. On success, the sent <a href="#message">Message</a> is returned. Bots can currently send files of any type of up to 50 MB in size, this limit may be changed in the future.
                inline void sendDocument(int chat_id, std::string document,
                                         std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                         bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                         bool protect_content = false, bool disable_notification = false,
                                         bool disable_content_type_detection = false,
                                         std::vector<std::shared_ptr<MessageEntity>> caption_entities = std::vector<std::shared_ptr<MessageEntity>>(),
                                         std::string parse_mode = "", std::string caption = "", std::string thumb = "",
                                         int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["document"] = document;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["disable_content_type_detection"] = disable_content_type_detection;
                    json j8 = json::object();
                    if (!caption_entities.empty()) {
                        for (const auto a: caption_entities) {
                            json j9 = json::object();
                            to_json(j9, *a);
                            j8.push_back(j9);
                        }
                        payload1["caption_entities"] = j8;
                    }
                    if (parse_mode != "") {
                        payload1["parse_mode"] = parse_mode;
                    }
                    if (caption != "") {
                        payload1["caption"] = caption;
                    }
                    if (thumb != "") {
                        payload1["thumb"] = thumb;
                    }
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendFile("/sendDocument", result1, Telegram::MediaType::DOCUMENT,
                                                      document);
                }

// Use this method to send video files, Telegram clients support MPEG4 videos (other formats may be sent as <a href="#document">Document</a>). On success, the sent <a href="#message">Message</a> is returned. Bots can currently send video files of up to 50 MB in size, this limit may be changed in the future.
                inline void
                sendVideo(int chat_id, std::string video, std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                          bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                          bool protect_content = false, bool disable_notification = false,
                          bool supports_streaming = false, bool has_spoiler = false,
                          std::vector<std::shared_ptr<MessageEntity>> caption_entities = std::vector<std::shared_ptr<MessageEntity>>(),
                          std::string parse_mode = "", std::string caption = "", std::string thumb = "", int height = 0,
                          int width = 0, int duration = 0, int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["video"] = video;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["supports_streaming"] = supports_streaming;
                    payload1["has_spoiler"] = has_spoiler;
                    json j9 = json::object();
                    if (!caption_entities.empty()) {
                        for (const auto a: caption_entities) {
                            json j10 = json::object();
                            to_json(j10, *a);
                            j9.push_back(j10);
                        }
                        payload1["caption_entities"] = j9;
                    }
                    if (parse_mode != "") {
                        payload1["parse_mode"] = parse_mode;
                    }
                    if (caption != "") {
                        payload1["caption"] = caption;
                    }
                    if (thumb != "") {
                        payload1["thumb"] = thumb;
                    }
                    payload1["height"] = height;
                    payload1["width"] = width;
                    payload1["duration"] = duration;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendFile("/sendVideo", result1, Telegram::MediaType::VIDEO, video);
                }

// Use this method to send animation files (GIF or H.264/MPEG-4 AVC video without sound). On success, the sent <a href="#message">Message</a> is returned. Bots can currently send animation files of up to 50 MB in size, this limit may be changed in the future.
                inline void sendAnimation(int chat_id, std::string animation,
                                          std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                          bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                          bool protect_content = false, bool disable_notification = false,
                                          bool has_spoiler = false,
                                          std::vector<std::shared_ptr<MessageEntity>> caption_entities = std::vector<std::shared_ptr<MessageEntity>>(),
                                          std::string parse_mode = "", std::string caption = "", std::string thumb = "",
                                          int height = 0, int width = 0, int duration = 0,
                                          int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["animation"] = animation;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["has_spoiler"] = has_spoiler;
                    json j8 = json::object();
                    if (!caption_entities.empty()) {
                        for (const auto a: caption_entities) {
                            json j9 = json::object();
                            to_json(j9, *a);
                            j8.push_back(j9);
                        }
                        payload1["caption_entities"] = j8;
                    }
                    if (parse_mode != "") {
                        payload1["parse_mode"] = parse_mode;
                    }
                    if (caption != "") {
                        payload1["caption"] = caption;
                    }
                    if (thumb != "") {
                        payload1["thumb"] = thumb;
                    }
                    payload1["height"] = height;
                    payload1["width"] = width;
                    payload1["duration"] = duration;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendFile("/sendAnimation", result1, Telegram::MediaType::VIDEO, animation);
                }

// Use this method to send audio files, if you want Telegram clients to display the file as a playable voice message. For this to work, your audio must be in an .OGG file encoded with OPUS (other formats may be sent as <a href="#audio">Audio</a> or <a href="#document">Document</a>). On success, the sent <a href="#message">Message</a> is returned. Bots can currently send voice messages of up to 50 MB in size, this limit may be changed in the future.
                inline void
                sendVoice(int chat_id, std::string voice, std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                          bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                          bool protect_content = false, bool disable_notification = false, int duration = 0,
                          std::vector<std::shared_ptr<MessageEntity>> caption_entities = std::vector<std::shared_ptr<MessageEntity>>(),
                          std::string parse_mode = "", std::string caption = "", int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["voice"] = voice;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["duration"] = duration;
                    json j8 = json::object();
                    if (!caption_entities.empty()) {
                        for (const auto a: caption_entities) {
                            json j9 = json::object();
                            to_json(j9, *a);
                            j8.push_back(j9);
                        }
                        payload1["caption_entities"] = j8;
                    }
                    if (parse_mode != "") {
                        payload1["parse_mode"] = parse_mode;
                    }
                    if (caption != "") {
                        payload1["caption"] = caption;
                    }
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendFile("/sendVoice", result1, Telegram::MediaType::AUDIO, voice);
                }

// As of <a href="https://telegram.org/blog/video-messages-and-telescope">v.4.0</a>, Telegram clients support rounded square MPEG4 videos of up to 1 minute long. Use this method to send video messages. On success, the sent <a href="#message">Message</a> is returned.
                inline void sendVideoNote(int chat_id, std::string video_note,
                                          std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                          bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                          bool protect_content = false, bool disable_notification = false,
                                          std::string thumb = "", int length = 0, int duration = 0,
                                          int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["video_note"] = video_note;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    if (thumb != "") {
                        payload1["thumb"] = thumb;
                    }
                    payload1["length"] = length;
                    payload1["duration"] = duration;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendFile("/sendVideoNote", result1, Telegram::MediaType::VIDEO,
                                                      video_note);
                }

// Use this method to send a group of photos, videos, documents or audios as an album. Documents and audio files can be only grouped in an album with messages of the same type. On success, an array of <a href="#message">Messages</a> that were sent is returned.
                inline void sendMediaGroup(int chat_id, std::vector<std::shared_ptr<InputMediaAudio>> media,
                                           bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                           bool protect_content = false, bool disable_notification = false,
                                           int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    json j1 = json::object();
                    if (!media.empty()) {
                        for (const auto a: media) {
                            json j2 = json::object();
                            to_json(j2, *a);
                            j1.push_back(j2);
                        }
                        payload1["media"] = j1;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendMediaGroup", result1);
                }

// Use this method to send point on the map. On success, the sent <a href="#message">Message</a> is returned.
                inline void sendLocation(int chat_id, float latitude, float longitude,
                                         std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                         bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                         bool protect_content = false, bool disable_notification = false,
                                         int proximity_alert_radius = 0, int heading = 0, int live_period = 0,
                                         float horizontal_accuracy = 0, int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["latitude"] = latitude;
                    payload1["longitude"] = longitude;
                    if (reply_markup != nullptr) {
                        json j3;
                        to_json(j3, *reply_markup);
                        payload1["reply_markup"] = j3;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["proximity_alert_radius"] = proximity_alert_radius;
                    payload1["heading"] = heading;
                    payload1["live_period"] = live_period;
                    payload1["horizontal_accuracy"] = horizontal_accuracy;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendLocation", result1);
                }

// Use this method to edit live location messages. A location can be edited until its <em>live_period</em> expires or editing is explicitly disabled by a call to <a href="#stopmessagelivelocation">stopMessageLiveLocation</a>. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                inline void editMessageLiveLocation(float latitude, float longitude,
                                                    std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                                    int proximity_alert_radius = 0, int heading = 0,
                                                    float horizontal_accuracy = 0, std::string inline_message_id = "",
                                                    int message_id = 0, int chat_id = 0) const {
                    json payload1;
                    payload1["latitude"] = latitude;
                    payload1["longitude"] = longitude;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["proximity_alert_radius"] = proximity_alert_radius;
                    payload1["heading"] = heading;
                    payload1["horizontal_accuracy"] = horizontal_accuracy;
                    payload1["inline_message_id"] = inline_message_id;
                    payload1["message_id"] = message_id;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/editMessageLiveLocation", result1);
                }

// Use this method to stop updating a live location message before <em>live_period</em> expires. On success, if the message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                inline void stopMessageLiveLocation(std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                                    std::string inline_message_id = "", int message_id = 0,
                                                    int chat_id = 0) const {
                    json payload1;
                    if (reply_markup != nullptr) {
                        json j0;
                        to_json(j0, *reply_markup);
                        payload1["reply_markup"] = j0;
                    }
                    payload1["inline_message_id"] = inline_message_id;
                    payload1["message_id"] = message_id;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/stopMessageLiveLocation", result1);
                }

// Use this method to send information about a venue. On success, the sent <a href="#message">Message</a> is returned.
                inline void
                sendVenue(int chat_id, float latitude, float longitude, std::string title, std::string address,
                          std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                          bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                          bool protect_content = false, bool disable_notification = false,
                          std::string google_place_type = "", std::string google_place_id = "",
                          std::string foursquare_type = "", std::string foursquare_id = "",
                          int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["latitude"] = latitude;
                    payload1["longitude"] = longitude;
                    payload1["title"] = title;
                    payload1["address"] = address;
                    if (reply_markup != nullptr) {
                        json j5;
                        to_json(j5, *reply_markup);
                        payload1["reply_markup"] = j5;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["google_place_type"] = google_place_type;
                    payload1["google_place_id"] = google_place_id;
                    payload1["foursquare_type"] = foursquare_type;
                    payload1["foursquare_id"] = foursquare_id;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendVenue", result1);
                }

// Use this method to send phone contacts. On success, the sent <a href="#message">Message</a> is returned.
                inline void sendContact(int chat_id, std::string phone_number, std::string first_name,
                                        std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                        bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                        bool protect_content = false, bool disable_notification = false,
                                        std::string vcard = "", std::string last_name = "",
                                        int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["phone_number"] = phone_number;
                    payload1["first_name"] = first_name;
                    if (reply_markup != nullptr) {
                        json j3;
                        to_json(j3, *reply_markup);
                        payload1["reply_markup"] = j3;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["vcard"] = vcard;
                    payload1["last_name"] = last_name;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendContact", result1);
                }

// Use this method to send a native poll. On success, the sent <a href="#message">Message</a> is returned.
                inline void sendPoll(int chat_id, std::string question, std::string options,
                                     std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                     bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                     bool protect_content = false, bool disable_notification = false,
                                     bool is_closed = false, int close_date = 0, int open_period = 0,
                                     std::vector<std::shared_ptr<MessageEntity>> explanation_entities = std::vector<std::shared_ptr<MessageEntity>>(),
                                     std::string explanation_parse_mode = "", std::string explanation = "",
                                     int correct_option_id = 0, bool allows_multiple_answers = false,
                                     std::string type = "", bool is_anonymous = false,
                                     int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["question"] = question;
                    payload1["options"] = options;
                    if (reply_markup != nullptr) {
                        json j3;
                        to_json(j3, *reply_markup);
                        payload1["reply_markup"] = j3;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["is_closed"] = is_closed;
                    payload1["close_date"] = close_date;
                    payload1["open_period"] = open_period;
                    json j11 = json::object();
                    if (!explanation_entities.empty()) {
                        for (const auto a: explanation_entities) {
                            json j12 = json::object();
                            to_json(j12, *a);
                            j11.push_back(j12);
                        }
                        payload1["explanation_entities"] = j11;
                    }
                    payload1["explanation_parse_mode"] = explanation_parse_mode;
                    payload1["explanation"] = explanation;
                    payload1["correct_option_id"] = correct_option_id;
                    payload1["allows_multiple_answers"] = allows_multiple_answers;
                    payload1["type"] = type;
                    payload1["is_anonymous"] = is_anonymous;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendPoll", result1);
                }

// Use this method to send an animated emoji that will display a random value. On success, the sent <a href="#message">Message</a> is returned.
                inline void sendDice(int chat_id, std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                     bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                     bool protect_content = false, bool disable_notification = false,
                                     std::string emoji = "", int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    if (reply_markup != nullptr) {
                        json j1;
                        to_json(j1, *reply_markup);
                        payload1["reply_markup"] = j1;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["emoji"] = emoji;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendDice", result1);
                }

// Use this method when you need to tell the user that something is happening on the bot&#39;s side. The status is set for 5 seconds or less (when a message arrives from your bot, Telegram clients clear its typing status). Returns <em>True</em> on success.
                inline void sendChatAction(int chat_id, std::string action, int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["action"] = action;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendChatAction", result1);
                }

// Use this method to get a list of profile pictures for a user. Returns a <a href="#userprofilephotos">UserProfilePhotos</a> object.
                inline UserProfilePhotos getUserProfilePhotos(int user_id, int limit = 0, int offset = 0) const {
                    json payload1;
                    payload1["user_id"] = user_id;
                    payload1["limit"] = limit;
                    payload1["offset"] = offset;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getUserProfilePhotos", result1);
                    UserProfilePhotos u;
                    auto response_u = json::parse(response);
                    from_json(response_u, u);
                    return u;
                }

// Use this method to get basic information about a file and prepare it for downloading. For the moment, bots can download files of up to 20MB in size. On success, a <a href="#file">File</a> object is returned. The file can then be downloaded via the link <code>https://api.telegram.org/file/bot&lt;token&gt;/&lt;file_path&gt;</code>, where <code>&lt;file_path&gt;</code> is taken from the response. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling <a href="#getfile">getFile</a> again.
                inline File getFile(std::string file_id) const {
                    json payload1;
                    payload1["file_id"] = file_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getFile", result1);
                    File u;
                    auto response_u = json::parse(response);
                    from_json(response_u, u);
                    return u;
                }

// Use this method to ban a user in a group, a supergroup or a channel. In the case of supergroups and channels, the user will not be able to return to the chat on their own using invite links, etc., unless <a href="#unbanchatmember">unbanned</a> first. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                inline void
                banChatMember(int chat_id, int user_id, bool revoke_messages = false, int until_date = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["user_id"] = user_id;
                    payload1["revoke_messages"] = revoke_messages;
                    payload1["until_date"] = until_date;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/banChatMember", result1);
                }

// Use this method to unban a previously banned user in a supergroup or channel. The user will <strong>not</strong> return to the group or channel automatically, but will be able to join via link, etc. The bot must be an administrator for this to work. By default, this method guarantees that after the call the user is not a member of the chat, but will be able to join it. So if the user is a member of the chat they will also be <strong>removed</strong> from the chat. If you don&#39;t want this, use the parameter <em>only_if_banned</em>. Returns <em>True</em> on success.
                inline void unbanChatMember(int chat_id, int user_id, bool only_if_banned = false) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["user_id"] = user_id;
                    payload1["only_if_banned"] = only_if_banned;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/unbanChatMember", result1);
                }

// Use this method to restrict a user in a supergroup. The bot must be an administrator in the supergroup for this to work and must have the appropriate administrator rights. Pass <em>True</em> for all permissions to lift restrictions from a user. Returns <em>True</em> on success.
                inline void restrictChatMember(int chat_id, int user_id, std::shared_ptr<ChatPermissions> permissions,
                                               int until_date = 0,
                                               bool use_independent_chat_permissions = false) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["user_id"] = user_id;
                    if (permissions != nullptr) {
                        json j2;
                        to_json(j2, *permissions);
                        payload1["permissions"] = j2;
                    }
                    payload1["until_date"] = until_date;
                    payload1["use_independent_chat_permissions"] = use_independent_chat_permissions;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/restrictChatMember", result1);
                }

// Use this method to promote or demote a user in a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Pass <em>False</em> for all boolean parameters to demote a user. Returns <em>True</em> on success.
                inline void promoteChatMember(int chat_id, int user_id, bool can_manage_topics = false,
                                              bool can_pin_messages = false, bool can_invite_users = false,
                                              bool can_change_info = false, bool can_promote_members = false,
                                              bool can_restrict_members = false, bool can_manage_video_chats = false,
                                              bool can_delete_messages = false, bool can_edit_messages = false,
                                              bool can_post_messages = false, bool can_manage_chat = false,
                                              bool is_anonymous = false) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["user_id"] = user_id;
                    payload1["can_manage_topics"] = can_manage_topics;
                    payload1["can_pin_messages"] = can_pin_messages;
                    payload1["can_invite_users"] = can_invite_users;
                    payload1["can_change_info"] = can_change_info;
                    payload1["can_promote_members"] = can_promote_members;
                    payload1["can_restrict_members"] = can_restrict_members;
                    payload1["can_manage_video_chats"] = can_manage_video_chats;
                    payload1["can_delete_messages"] = can_delete_messages;
                    payload1["can_edit_messages"] = can_edit_messages;
                    payload1["can_post_messages"] = can_post_messages;
                    payload1["can_manage_chat"] = can_manage_chat;
                    payload1["is_anonymous"] = is_anonymous;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/promoteChatMember", result1);
                }

// Use this method to set a custom title for an administrator in a supergroup promoted by the bot. Returns <em>True</em> on success.
                inline void setChatAdministratorCustomTitle(int chat_id, int user_id, std::string custom_title) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["user_id"] = user_id;
                    payload1["custom_title"] = custom_title;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setChatAdministratorCustomTitle", result1);
                }

// Use this method to ban a channel chat in a supergroup or a channel. Until the chat is <a href="#unbanchatsenderchat">unbanned</a>, the owner of the banned chat won&#39;t be able to send messages on behalf of <strong>any of their channels</strong>. The bot must be an administrator in the supergroup or channel for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                inline void banChatSenderChat(int chat_id, int sender_chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["sender_chat_id"] = sender_chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/banChatSenderChat", result1);
                }

// Use this method to unban a previously banned channel chat in a supergroup or channel. The bot must be an administrator for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                inline void unbanChatSenderChat(int chat_id, int sender_chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["sender_chat_id"] = sender_chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/unbanChatSenderChat", result1);
                }

// Use this method to set default chat permissions for all members. The bot must be an administrator in the group or a supergroup for this to work and must have the <em>can_restrict_members</em> administrator rights. Returns <em>True</em> on success.
                inline void setChatPermissions(int chat_id, std::shared_ptr<ChatPermissions> permissions,
                                               bool use_independent_chat_permissions = false) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    if (permissions != nullptr) {
                        json j1;
                        to_json(j1, *permissions);
                        payload1["permissions"] = j1;
                    }
                    payload1["use_independent_chat_permissions"] = use_independent_chat_permissions;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setChatPermissions", result1);
                }

// Use this method to generate a new primary invite link for a chat; any previously generated primary link is revoked. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the new invite link as <em>String</em> on success.
                inline void exportChatInviteLink(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/exportChatInviteLink", result1);
                }

// Use this method to create an additional invite link for a chat. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. The link can be revoked using the method <a href="#revokechatinvitelink">revokeChatInviteLink</a>. Returns the new invite link as <a href="#chatinvitelink">ChatInviteLink</a> object.
                inline void createChatInviteLink(int chat_id, bool creates_join_request = false, int member_limit = 0,
                                                 int expire_date = 0, std::string name = "") const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["creates_join_request"] = creates_join_request;
                    payload1["member_limit"] = member_limit;
                    payload1["expire_date"] = expire_date;
                    payload1["name"] = name;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/createChatInviteLink", result1);
                }

// Use this method to edit a non-primary invite link created by the bot. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the edited invite link as a <a href="#chatinvitelink">ChatInviteLink</a> object.
                inline void editChatInviteLink(int chat_id, std::string invite_link, bool creates_join_request = false,
                                               int member_limit = 0, int expire_date = 0, std::string name = "") const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["invite_link"] = invite_link;
                    payload1["creates_join_request"] = creates_join_request;
                    payload1["member_limit"] = member_limit;
                    payload1["expire_date"] = expire_date;
                    payload1["name"] = name;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/editChatInviteLink", result1);
                }

// Use this method to revoke an invite link created by the bot. If the primary link is revoked, a new link is automatically generated. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the revoked invite link as <a href="#chatinvitelink">ChatInviteLink</a> object.
                inline void revokeChatInviteLink(int chat_id, std::string invite_link) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["invite_link"] = invite_link;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/revokeChatInviteLink", result1);
                }

// Use this method to approve a chat join request. The bot must be an administrator in the chat for this to work and must have the <em>can_invite_users</em> administrator right. Returns <em>True</em> on success.
                inline void approveChatJoinRequest(int chat_id, int user_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["user_id"] = user_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/approveChatJoinRequest", result1);
                }

// Use this method to decline a chat join request. The bot must be an administrator in the chat for this to work and must have the <em>can_invite_users</em> administrator right. Returns <em>True</em> on success.
                inline void declineChatJoinRequest(int chat_id, int user_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["user_id"] = user_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/declineChatJoinRequest", result1);
                }

// Use this method to set a new profile photo for the chat. Photos can&#39;t be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                inline void setChatPhoto(int chat_id, std::shared_ptr<InputFile> photo) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    if (photo != nullptr) {
                        json j1;
                        to_json(j1, *photo);
                        payload1["photo"] = j1;
                    }
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setChatPhoto", result1);
                }

// Use this method to delete a chat photo. Photos can&#39;t be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                inline void deleteChatPhoto(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/deleteChatPhoto", result1);
                }

// Use this method to change the title of a chat. Titles can&#39;t be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                inline void setChatTitle(int chat_id, std::string title) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["title"] = title;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setChatTitle", result1);
                }

// Use this method to change the description of a group, a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns <em>True</em> on success.
                inline void setChatDescription(int chat_id, std::string description = "") const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["description"] = description;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setChatDescription", result1);
                }

// Use this method to add a message to the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the &#39;can_pin_messages&#39; administrator right in a supergroup or &#39;can_edit_messages&#39; administrator right in a channel. Returns <em>True</em> on success.
                inline void pinChatMessage(int chat_id, int message_id, bool disable_notification = false) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["message_id"] = message_id;
                    payload1["disable_notification"] = disable_notification;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/pinChatMessage", result1);
                }

// Use this method to remove a message from the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the &#39;can_pin_messages&#39; administrator right in a supergroup or &#39;can_edit_messages&#39; administrator right in a channel. Returns <em>True</em> on success.
                inline void unpinChatMessage(int chat_id, int message_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["message_id"] = message_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/unpinChatMessage", result1);
                }

// Use this method to clear the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the &#39;can_pin_messages&#39; administrator right in a supergroup or &#39;can_edit_messages&#39; administrator right in a channel. Returns <em>True</em> on success.
                inline void unpinAllChatMessages(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/unpinAllChatMessages", result1);
                }

// Use this method for your bot to leave a group, supergroup or channel. Returns <em>True</em> on success.
                inline void leaveChat(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/leaveChat", result1);
                }

// Use this method to get up to date information about the chat (current name of the user for one-on-one conversations, current username of a user, group or channel, etc.). Returns a <a href="#chat">Chat</a> object on success.
                inline Chat getChat(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getChat", result1);
                    Chat u;
                    auto response_u = json::parse(response);
                    from_json(response_u, u);
                    return u;
                }

// Use this method to get a list of administrators in a chat, which aren&#39;t bots. Returns an Array of <a href="#chatmember">ChatMember</a> objects.
                inline std::vector<ChatMember> getChatAdministrators(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getChatAdministrators", result1);
                    std::vector<ChatMember> u;
                    auto response_u = json::parse(response);
                    for (const auto &a: response_u) {
                        ChatMember u2;
                        from_json(a, u2);
                        u.push_back(u2);
                    }
                    return u;
                }

// Use this method to get the number of members in a chat. Returns <em>Int</em> on success.
                inline int getChatMemberCount(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getChatMemberCount", result1);
                    auto response_u = json::parse(response);
                    return response_u;
                }

// Use this method to get information about a member of a chat. The method is only guaranteed to work for other users if the bot is an administrator in the chat. Returns a <a href="#chatmember">ChatMember</a> object on success.
                inline ChatMember getChatMember(int chat_id, int user_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["user_id"] = user_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getChatMember", result1);
                    ChatMember u;
                    auto response_u = json::parse(response);
                    from_json(response_u, u);
                    return u;
                }

// Use this method to set a new group sticker set for a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field <em>can_set_sticker_set</em> optionally returned in <a href="#getchat">getChat</a> requests to check if the bot can use this method. Returns <em>True</em> on success.
                inline void setChatStickerSet(int chat_id, std::string sticker_set_name) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["sticker_set_name"] = sticker_set_name;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setChatStickerSet", result1);
                }

// Use this method to delete a group sticker set from a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field <em>can_set_sticker_set</em> optionally returned in <a href="#getchat">getChat</a> requests to check if the bot can use this method. Returns <em>True</em> on success.
                inline void deleteChatStickerSet(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/deleteChatStickerSet", result1);
                }

// Use this method to get custom emoji stickers, which can be used as a forum topic icon by any user. Requires no parameters. Returns an Array of <a href="#sticker">Sticker</a> objects.
                inline void
                getForumTopicIconStickers(int chat_id, std::string name, std::string icon_custom_emoji_id = "",
                                          int icon_color = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["name"] = name;
                    payload1["icon_custom_emoji_id"] = icon_custom_emoji_id;
                    payload1["icon_color"] = icon_color;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getForumTopicIconStickers", result1);
                }

// Use this method to create a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. Returns information about the created topic as a <a href="#forumtopic">ForumTopic</a> object.
                inline void createForumTopic(int chat_id, std::string name, std::string icon_custom_emoji_id = "",
                                             int icon_color = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["name"] = name;
                    payload1["icon_custom_emoji_id"] = icon_custom_emoji_id;
                    payload1["icon_color"] = icon_color;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/createForumTopic", result1);
                }

// Use this method to edit name and icon of a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have <em>can_manage_topics</em> administrator rights, unless it is the creator of the topic. Returns <em>True</em> on success.
                inline void editForumTopic(int chat_id, int message_thread_id, std::string icon_custom_emoji_id = "",
                                           std::string name = "") const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["message_thread_id"] = message_thread_id;
                    payload1["icon_custom_emoji_id"] = icon_custom_emoji_id;
                    payload1["name"] = name;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/editForumTopic", result1);
                }

// Use this method to close an open topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights, unless it is the creator of the topic. Returns <em>True</em> on success.
                inline void closeForumTopic(int chat_id, int message_thread_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/closeForumTopic", result1);
                }

// Use this method to reopen a closed topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights, unless it is the creator of the topic. Returns <em>True</em> on success.
                inline void reopenForumTopic(int chat_id, int message_thread_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/reopenForumTopic", result1);
                }

// Use this method to delete a forum topic along with all its messages in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_delete_messages</em> administrator rights. Returns <em>True</em> on success.
                inline void deleteForumTopic(int chat_id, int message_thread_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/deleteForumTopic", result1);
                }

// Use this method to clear the list of pinned messages in a forum topic. The bot must be an administrator in the chat for this to work and must have the <em>can_pin_messages</em> administrator right in the supergroup. Returns <em>True</em> on success.
                inline void unpinAllForumTopicMessages(int chat_id, int message_thread_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/unpinAllForumTopicMessages", result1);
                }

// Use this method to edit the name of the &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have <em>can_manage_topics</em> administrator rights. Returns <em>True</em> on success.
                inline void editGeneralForumTopic(int chat_id, std::string name) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["name"] = name;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/editGeneralForumTopic", result1);
                }

// Use this method to close an open &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. Returns <em>True</em> on success.
                inline void closeGeneralForumTopic(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/closeGeneralForumTopic", result1);
                }

// Use this method to reopen a closed &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. The topic will be automatically unhidden if it was hidden. Returns <em>True</em> on success.
                inline void reopenGeneralForumTopic(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/reopenGeneralForumTopic", result1);
                }

// Use this method to hide the &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. The topic will be automatically closed if it was open. Returns <em>True</em> on success.
                inline void hideGeneralForumTopic(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/hideGeneralForumTopic", result1);
                }

// Use this method to unhide the &#39;General&#39; topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the <em>can_manage_topics</em> administrator rights. Returns <em>True</em> on success.
                inline void unhideGeneralForumTopic(int chat_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/unhideGeneralForumTopic", result1);
                }

// Use this method to send answers to callback queries sent from <a href="/bots/features#inline-keyboards">inline keyboards</a>. The answer will be displayed to the user as a notification at the top of the chat screen or as an alert. On success, <em>True</em> is returned.
                inline void answerCallbackQuery(std::string callback_query_id, int cache_time = 0, std::string url = "",
                                                bool show_alert = false, std::string text = "") const {
                    json payload1;
                    payload1["callback_query_id"] = callback_query_id;
                    payload1["cache_time"] = cache_time;
                    payload1["url"] = url;
                    payload1["show_alert"] = show_alert;
                    payload1["text"] = text;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/answerCallbackQuery", result1);
                }

// Use this method to change the list of the bot&#39;s commands. See <a href="/bots/features#commands">this manual</a> for more details about bot commands. Returns <em>True</em> on success.
                inline void
                setMyCommands(std::vector<std::shared_ptr<BotCommand>> commands, std::string language_code = "",
                              std::shared_ptr<BotCommandScope> scope = nullptr) const {
                    json payload1;
                    json j0 = json::object();
                    if (!commands.empty()) {
                        for (const auto a: commands) {
                            json j1 = json::object();
                            to_json(j1, *a);
                            j0.push_back(j1);
                        }
                        payload1["commands"] = j0;
                    }
                    payload1["language_code"] = language_code;
                    if (scope != nullptr) {
                        json j2;
                        to_json(j2, *scope);
                        payload1["scope"] = j2;
                    }
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setMyCommands", result1);
                }

// Use this method to delete the list of the bot&#39;s commands for the given scope and user language. After deletion, <a href="#determining-list-of-commands">higher level commands</a> will be shown to affected users. Returns <em>True</em> on success.
                inline void deleteMyCommands(std::string language_code = "",
                                             std::shared_ptr<BotCommandScope> scope = nullptr) const {
                    json payload1;
                    payload1["language_code"] = language_code;
                    if (scope != nullptr) {
                        json j1;
                        to_json(j1, *scope);
                        payload1["scope"] = j1;
                    }
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/deleteMyCommands", result1);
                }

// Use this method to get the current list of the bot&#39;s commands for the given scope and user language. Returns an Array of <a href="#botcommand">BotCommand</a> objects. If commands aren&#39;t set, an empty list is returned.
                inline void
                getMyCommands(std::string language_code = "", std::shared_ptr<BotCommandScope> scope = nullptr) const {
                    json payload1;
                    payload1["language_code"] = language_code;
                    if (scope != nullptr) {
                        json j1;
                        to_json(j1, *scope);
                        payload1["scope"] = j1;
                    }
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getMyCommands", result1);
                }

// Use this method to change the bot&#39;s menu button in a private chat, or the default menu button. Returns <em>True</em> on success.
                inline void
                setChatMenuButton(std::shared_ptr<MenuButton> menu_button = nullptr, int chat_id = 0) const {
                    json payload1;
                    if (menu_button != nullptr) {
                        json j0;
                        to_json(j0, *menu_button);
                        payload1["menu_button"] = j0;
                    }
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setChatMenuButton", result1);
                }

// Use this method to get the current value of the bot&#39;s menu button in a private chat, or the default menu button. Returns <a href="#menubutton">MenuButton</a> on success.
                inline MenuButton getChatMenuButton(int chat_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getChatMenuButton", result1);
                    MenuButton u;
                    auto response_u = json::parse(response);
                    from_json(response_u, u);
                    return u;
                }

// Use this method to change the default administrator rights requested by the bot when it&#39;s added as an administrator to groups or channels. These rights will be suggested to users, but they are free to modify the list before adding the bot. Returns <em>True</em> on success.
                inline void setMyDefaultAdministratorRights(bool for_channels = false,
                                                            std::shared_ptr<ChatAdministratorRights> rights = nullptr) const {
                    json payload1;
                    payload1["for_channels"] = for_channels;
                    if (rights != nullptr) {
                        json j1;
                        to_json(j1, *rights);
                        payload1["rights"] = j1;
                    }
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setMyDefaultAdministratorRights", result1);
                }

// Use this method to get the current default administrator rights of the bot. Returns <a href="#chatadministratorrights">ChatAdministratorRights</a> on success.
                inline ChatAdministratorRights getMyDefaultAdministratorRights(bool for_channels = false) const {
                    json payload1;
                    payload1["for_channels"] = for_channels;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getMyDefaultAdministratorRights", result1);
                    ChatAdministratorRights u;
                    auto response_u = json::parse(response);
                    from_json(response_u, u);
                    return u;
                }

// Use this method to edit text and <a href="#games">game</a> messages. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                inline void
                editMessageText(std::string text, std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                bool disable_web_page_preview = false,
                                std::vector<std::shared_ptr<MessageEntity>> entities = std::vector<std::shared_ptr<MessageEntity>>(),
                                std::string parse_mode = "", std::string inline_message_id = "", int message_id = 0,
                                int chat_id = 0) const {
                    json payload1;
                    payload1["text"] = text;
                    if (reply_markup != nullptr) {
                        json j1;
                        to_json(j1, *reply_markup);
                        payload1["reply_markup"] = j1;
                    }
                    payload1["disable_web_page_preview"] = disable_web_page_preview;
                    json j3 = json::object();
                    if (!entities.empty()) {
                        for (const auto a: entities) {
                            json j4 = json::object();
                            to_json(j4, *a);
                            j3.push_back(j4);
                        }
                        payload1["entities"] = j3;
                    }
                    payload1["parse_mode"] = parse_mode;
                    payload1["inline_message_id"] = inline_message_id;
                    payload1["message_id"] = message_id;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/editMessageText", result1);
                }

// Use this method to edit captions of messages. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                inline void editMessageCaption(std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                               std::vector<std::shared_ptr<MessageEntity>> caption_entities = std::vector<std::shared_ptr<MessageEntity>>(),
                                               std::string parse_mode = "", std::string caption = "",
                                               std::string inline_message_id = "", int message_id = 0,
                                               int chat_id = 0) const {
                    json payload1;
                    if (reply_markup != nullptr) {
                        json j0;
                        to_json(j0, *reply_markup);
                        payload1["reply_markup"] = j0;
                    }
                    json j1 = json::object();
                    if (!caption_entities.empty()) {
                        for (const auto a: caption_entities) {
                            json j2 = json::object();
                            to_json(j2, *a);
                            j1.push_back(j2);
                        }
                        payload1["caption_entities"] = j1;
                    }
                    payload1["parse_mode"] = parse_mode;
                    payload1["caption"] = caption;
                    payload1["inline_message_id"] = inline_message_id;
                    payload1["message_id"] = message_id;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/editMessageCaption", result1);
                }

// Use this method to edit animation, audio, document, photo, or video messages. If a message is part of a message album, then it can be edited only to an audio for audio albums, only to a document for document albums and to a photo or a video otherwise. When an inline message is edited, a new file can&#39;t be uploaded; use a previously uploaded file via its file_id or specify a URL. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                inline void editMessageMedia(std::shared_ptr<InputMedia> media,
                                             std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                             std::string inline_message_id = "", int message_id = 0,
                                             int chat_id = 0) const {
                    json payload1;
                    if (media != nullptr) {
                        json j0;
                        to_json(j0, *media);
                        payload1["media"] = j0;
                    }
                    if (reply_markup != nullptr) {
                        json j1;
                        to_json(j1, *reply_markup);
                        payload1["reply_markup"] = j1;
                    }
                    payload1["inline_message_id"] = inline_message_id;
                    payload1["message_id"] = message_id;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/editMessageMedia", result1);
                }

// Use this method to edit only the reply markup of messages. On success, if the edited message is not an inline message, the edited <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned.
                inline void editMessageReplyMarkup(std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                                   std::string inline_message_id = "", int message_id = 0,
                                                   int chat_id = 0) const {
                    json payload1;
                    if (reply_markup != nullptr) {
                        json j0;
                        to_json(j0, *reply_markup);
                        payload1["reply_markup"] = j0;
                    }
                    payload1["inline_message_id"] = inline_message_id;
                    payload1["message_id"] = message_id;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/editMessageReplyMarkup", result1);
                }

// Use this method to stop a poll which was sent by the bot. On success, the stopped <a href="#poll">Poll</a> is returned.
                inline void stopPoll(int chat_id, int message_id,
                                     std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["message_id"] = message_id;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/stopPoll", result1);
                }

// Use this method to delete a message, including service messages, with the following limitations:<br>- A message can only be deleted if it was sent less than 48 hours ago.<br>- Service messages about a supergroup, channel, or forum topic creation can&#39;t be deleted.<br>- A dice message in a private chat can only be deleted if it was sent more than 24 hours ago.<br>- Bots can delete outgoing messages in private chats, groups, and supergroups.<br>- Bots can delete incoming messages in private chats.<br>- Bots granted <em>can_post_messages</em> permissions can delete outgoing messages in channels.<br>- If the bot is an administrator of a group, it can delete any message there.<br>- If the bot has <em>can_delete_messages</em> permission in a supergroup or a channel, it can delete any message there.<br>Returns <em>True</em> on success.
                inline void deleteMessage(int chat_id, int message_id) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["message_id"] = message_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/deleteMessage", result1);
                }

// Use this method to send static .WEBP, <a href="https://telegram.org/blog/animated-stickers">animated</a> .TGS, or <a href="https://telegram.org/blog/video-stickers-better-reactions">video</a> .WEBM stickers. On success, the sent <a href="#message">Message</a> is returned.
                inline void sendSticker(int chat_id, std::string sticker,
                                        std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                        bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                        bool protect_content = false, bool disable_notification = false,
                                        int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["sticker"] = sticker;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendSticker", result1);
                }

// Use this method to get a sticker set. On success, a <a href="#stickerset">StickerSet</a> object is returned.
                inline StickerSet getStickerSet(std::string name) const {
                    json payload1;
                    payload1["name"] = name;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getStickerSet", result1);
                    StickerSet u;
                    auto response_u = json::parse(response);
                    from_json(response_u, u);
                    return u;
                }

// Use this method to get information about custom emoji stickers by their identifiers. Returns an Array of <a href="#sticker">Sticker</a> objects.
                inline std::vector<Sticker> getCustomEmojiStickers(std::string custom_emoji_ids) const {
                    json payload1;
                    payload1["custom_emoji_ids"] = custom_emoji_ids;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getCustomEmojiStickers", result1);
                    std::vector<Sticker> u;
                    auto response_u = json::parse(response);
                    for (const auto &a: response_u) {
                        Sticker u2;
                        from_json(a, u2);
                        u.push_back(u2);
                    }
                    return u;
                }

// Use this method to upload a .PNG file with a sticker for later use in <em>createNewStickerSet</em> and <em>addStickerToSet</em> methods (can be used multiple times). Returns the uploaded <a href="#file">File</a> on success.
                inline void uploadStickerFile(int user_id, std::shared_ptr<InputFile> png_sticker) const {
                    json payload1;
                    payload1["user_id"] = user_id;
                    if (png_sticker != nullptr) {
                        json j1;
                        to_json(j1, *png_sticker);
                        payload1["png_sticker"] = j1;
                    }
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/uploadStickerFile", result1);
                }

// Use this method to create a new sticker set owned by a user. The bot will be able to edit the sticker set thus created. You <strong>must</strong> use exactly one of the fields <em>png_sticker</em>, <em>tgs_sticker</em>, or <em>webm_sticker</em>. Returns <em>True</em> on success.
                inline void createNewStickerSet(int user_id, std::string name, std::string title, std::string emojis,
                                                std::shared_ptr<MaskPosition> mask_position = nullptr,
                                                std::string sticker_type = "",
                                                std::shared_ptr<InputFile> webm_sticker = nullptr,
                                                std::shared_ptr<InputFile> tgs_sticker = nullptr,
                                                std::string png_sticker = "") const {
                    json payload1;
                    payload1["user_id"] = user_id;
                    payload1["name"] = name;
                    payload1["title"] = title;
                    payload1["emojis"] = emojis;
                    if (mask_position != nullptr) {
                        json j4;
                        to_json(j4, *mask_position);
                        payload1["mask_position"] = j4;
                    }
                    payload1["sticker_type"] = sticker_type;
                    if (webm_sticker != nullptr) {
                        json j6;
                        to_json(j6, *webm_sticker);
                        payload1["webm_sticker"] = j6;
                    }
                    if (tgs_sticker != nullptr) {
                        json j7;
                        to_json(j7, *tgs_sticker);
                        payload1["tgs_sticker"] = j7;
                    }
                    payload1["png_sticker"] = png_sticker;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/createNewStickerSet", result1);
                }

// Use this method to add a new sticker to a set created by the bot. You <strong>must</strong> use exactly one of the fields <em>png_sticker</em>, <em>tgs_sticker</em>, or <em>webm_sticker</em>. Animated stickers can be added to animated sticker sets and only to them. Animated sticker sets can have up to 50 stickers. Static sticker sets can have up to 120 stickers. Returns <em>True</em> on success.
                inline void addStickerToSet(int user_id, std::string name, std::string emojis,
                                            std::shared_ptr<MaskPosition> mask_position = nullptr,
                                            std::shared_ptr<InputFile> webm_sticker = nullptr,
                                            std::shared_ptr<InputFile> tgs_sticker = nullptr,
                                            std::string png_sticker = "") const {
                    json payload1;
                    payload1["user_id"] = user_id;
                    payload1["name"] = name;
                    payload1["emojis"] = emojis;
                    if (mask_position != nullptr) {
                        json j3;
                        to_json(j3, *mask_position);
                        payload1["mask_position"] = j3;
                    }
                    if (webm_sticker != nullptr) {
                        json j4;
                        to_json(j4, *webm_sticker);
                        payload1["webm_sticker"] = j4;
                    }
                    if (tgs_sticker != nullptr) {
                        json j5;
                        to_json(j5, *tgs_sticker);
                        payload1["tgs_sticker"] = j5;
                    }
                    payload1["png_sticker"] = png_sticker;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/addStickerToSet", result1);
                }

// Use this method to move a sticker in a set created by the bot to a specific position. Returns <em>True</em> on success.
                inline void setStickerPositionInSet(std::string sticker, int position) const {
                    json payload1;
                    payload1["sticker"] = sticker;
                    payload1["position"] = position;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setStickerPositionInSet", result1);
                }

// Use this method to delete a sticker from a set created by the bot. Returns <em>True</em> on success.
                inline void deleteStickerFromSet(std::string sticker) const {
                    json payload1;
                    payload1["sticker"] = sticker;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/deleteStickerFromSet", result1);
                }

// Use this method to set the thumbnail of a sticker set. Animated thumbnails can be set for animated sticker sets only. Video thumbnails can be set only for video sticker sets only. Returns <em>True</em> on success.
                inline void setStickerSetThumb(std::string name, int user_id, std::string thumb = "") const {
                    json payload1;
                    payload1["name"] = name;
                    payload1["user_id"] = user_id;
                    payload1["thumb"] = thumb;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setStickerSetThumb", result1);
                }

// Use this method to send answers to an inline query. On success, <em>True</em> is returned.<br>No more than <strong>50</strong> results per query are allowed.
                inline void
                answerInlineQuery(std::string inline_query_id, std::vector<std::shared_ptr<InlineQueryResult>> results,
                                  std::string switch_pm_parameter = "", std::string switch_pm_text = "",
                                  std::string next_offset = "", bool is_personal = false, int cache_time = 0) const {
                    json payload1;
                    payload1["inline_query_id"] = inline_query_id;
                    json j1 = json::object();
                    if (!results.empty()) {
                        for (const auto a: results) {
                            json j2 = json::object();
                            to_json(j2, *a);
                            j1.push_back(j2);
                        }
                        payload1["results"] = j1;
                    }
                    payload1["switch_pm_parameter"] = switch_pm_parameter;
                    payload1["switch_pm_text"] = switch_pm_text;
                    payload1["next_offset"] = next_offset;
                    payload1["is_personal"] = is_personal;
                    payload1["cache_time"] = cache_time;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/answerInlineQuery", result1);
                }

// Use this method to set the result of an interaction with a <a href="/bots/webapps">Web App</a> and send a corresponding message on behalf of the user to the chat from which the query originated. On success, a <a href="#sentwebappmessage">SentWebAppMessage</a> object is returned.
                inline void
                answerWebAppQuery(std::string web_app_query_id, std::shared_ptr<InlineQueryResult> result) const {
                    json payload1;
                    payload1["web_app_query_id"] = web_app_query_id;
                    if (result != nullptr) {
                        json j1;
                        to_json(j1, *result);
                        payload1["result"] = j1;
                    }
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/answerWebAppQuery", result1);
                }

// Use this method to send invoices. On success, the sent <a href="#message">Message</a> is returned.
                inline void sendInvoice(int chat_id, std::string title, std::string description, std::string payload,
                                        std::string provider_token, std::string currency,
                                        std::vector<std::shared_ptr<LabeledPrice>> prices,
                                        std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                        bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                        bool protect_content = false, bool disable_notification = false,
                                        bool is_flexible = false, bool send_email_to_provider = false,
                                        bool send_phone_number_to_provider = false, bool need_shipping_address = false,
                                        bool need_email = false, bool need_phone_number = false, bool need_name = false,
                                        int photo_height = 0, int photo_width = 0, int photo_size = 0,
                                        std::string photo_url = "", std::string provider_data = "",
                                        std::string start_parameter = "", int suggested_tip_amounts = 0,
                                        int max_tip_amount = 0, int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["title"] = title;
                    payload1["description"] = description;
                    payload1["payload"] = payload;
                    payload1["provider_token"] = provider_token;
                    payload1["currency"] = currency;
                    json j6 = json::object();
                    if (!prices.empty()) {
                        for (const auto a: prices) {
                            json j7 = json::object();
                            to_json(j7, *a);
                            j6.push_back(j7);
                        }
                        payload1["prices"] = j6;
                    }
                    if (reply_markup != nullptr) {
                        json j7;
                        to_json(j7, *reply_markup);
                        payload1["reply_markup"] = j7;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["is_flexible"] = is_flexible;
                    payload1["send_email_to_provider"] = send_email_to_provider;
                    payload1["send_phone_number_to_provider"] = send_phone_number_to_provider;
                    payload1["need_shipping_address"] = need_shipping_address;
                    payload1["need_email"] = need_email;
                    payload1["need_phone_number"] = need_phone_number;
                    payload1["need_name"] = need_name;
                    payload1["photo_height"] = photo_height;
                    payload1["photo_width"] = photo_width;
                    payload1["photo_size"] = photo_size;
                    payload1["photo_url"] = photo_url;
                    payload1["provider_data"] = provider_data;
                    payload1["start_parameter"] = start_parameter;
                    payload1["suggested_tip_amounts"] = suggested_tip_amounts;
                    payload1["max_tip_amount"] = max_tip_amount;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendInvoice", result1);
                }

// Use this method to create a link for an invoice. Returns the created invoice link as <em>String</em> on success.
                inline void createInvoiceLink(std::string title, std::string description, std::string payload,
                                              std::string provider_token, std::string currency,
                                              std::vector<std::shared_ptr<LabeledPrice>> prices,
                                              bool is_flexible = false, bool send_email_to_provider = false,
                                              bool send_phone_number_to_provider = false,
                                              bool need_shipping_address = false, bool need_email = false,
                                              bool need_phone_number = false, bool need_name = false,
                                              int photo_height = 0, int photo_width = 0, int photo_size = 0,
                                              std::string photo_url = "", std::string provider_data = "",
                                              int suggested_tip_amounts = 0, int max_tip_amount = 0) const {
                    json payload1;
                    payload1["title"] = title;
                    payload1["description"] = description;
                    payload1["payload"] = payload;
                    payload1["provider_token"] = provider_token;
                    payload1["currency"] = currency;
                    json j5 = json::object();
                    if (!prices.empty()) {
                        for (const auto a: prices) {
                            json j6 = json::object();
                            to_json(j6, *a);
                            j5.push_back(j6);
                        }
                        payload1["prices"] = j5;
                    }
                    payload1["is_flexible"] = is_flexible;
                    payload1["send_email_to_provider"] = send_email_to_provider;
                    payload1["send_phone_number_to_provider"] = send_phone_number_to_provider;
                    payload1["need_shipping_address"] = need_shipping_address;
                    payload1["need_email"] = need_email;
                    payload1["need_phone_number"] = need_phone_number;
                    payload1["need_name"] = need_name;
                    payload1["photo_height"] = photo_height;
                    payload1["photo_width"] = photo_width;
                    payload1["photo_size"] = photo_size;
                    payload1["photo_url"] = photo_url;
                    payload1["provider_data"] = provider_data;
                    payload1["suggested_tip_amounts"] = suggested_tip_amounts;
                    payload1["max_tip_amount"] = max_tip_amount;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/createInvoiceLink", result1);
                }

// If you sent an invoice requesting a shipping address and the parameter <em>is_flexible</em> was specified, the Bot API will send an <a href="#update">Update</a> with a <em>shipping_query</em> field to the bot. Use this method to reply to shipping queries. On success, <em>True</em> is returned.
                inline void answerShippingQuery(std::string shipping_query_id, bool ok, std::string error_message = "",
                                                std::vector<std::shared_ptr<ShippingOption>> shipping_options = std::vector<std::shared_ptr<ShippingOption>>()) const {
                    json payload1;
                    payload1["shipping_query_id"] = shipping_query_id;
                    payload1["ok"] = ok;
                    payload1["error_message"] = error_message;
                    json j3 = json::object();
                    if (!shipping_options.empty()) {
                        for (const auto a: shipping_options) {
                            json j4 = json::object();
                            to_json(j4, *a);
                            j3.push_back(j4);
                        }
                        payload1["shipping_options"] = j3;
                    }
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/answerShippingQuery", result1);
                }

// Once the user has confirmed their payment and shipping details, the Bot API sends the final confirmation in the form of an <a href="#update">Update</a> with the field <em>pre_checkout_query</em>. Use this method to respond to such pre-checkout queries. On success, <em>True</em> is returned. <strong>Note:</strong> The Bot API must receive an answer within 10 seconds after the pre-checkout query was sent.
                inline void answerPreCheckoutQuery(std::string pre_checkout_query_id, bool ok,
                                                   std::string error_message = "") const {
                    json payload1;
                    payload1["pre_checkout_query_id"] = pre_checkout_query_id;
                    payload1["ok"] = ok;
                    payload1["error_message"] = error_message;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/answerPreCheckoutQuery", result1);
                }

// Informs a user that some of the Telegram Passport elements they provided contains errors. The user will not be able to re-submit their Passport to you until the errors are fixed (the contents of the field for which you returned the error must change). Returns <em>True</em> on success.
                inline void
                setPassportDataErrors(int user_id, std::vector<std::shared_ptr<PassportElementError>> errors) const {
                    json payload1;
                    payload1["user_id"] = user_id;
                    json j1 = json::object();
                    if (!errors.empty()) {
                        for (const auto a: errors) {
                            json j2 = json::object();
                            to_json(j2, *a);
                            j1.push_back(j2);
                        }
                        payload1["errors"] = j1;
                    }
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setPassportDataErrors", result1);
                }

// Use this method to send a game. On success, the sent <a href="#message">Message</a> is returned.
                inline void sendGame(int chat_id, std::string game_short_name,
                                     std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr,
                                     bool allow_sending_without_reply = false, int reply_to_message_id = 0,
                                     bool protect_content = false, bool disable_notification = false,
                                     int message_thread_id = 0) const {
                    json payload1;
                    payload1["chat_id"] = chat_id;
                    payload1["game_short_name"] = game_short_name;
                    if (reply_markup != nullptr) {
                        json j2;
                        to_json(j2, *reply_markup);
                        payload1["reply_markup"] = j2;
                    }
                    payload1["allow_sending_without_reply"] = allow_sending_without_reply;
                    payload1["reply_to_message_id"] = reply_to_message_id;
                    payload1["protect_content"] = protect_content;
                    payload1["disable_notification"] = disable_notification;
                    payload1["message_thread_id"] = message_thread_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/sendGame", result1);
                }

// Use this method to set the score of the specified user in a game message. On success, if the message is not an inline message, the <a href="#message">Message</a> is returned, otherwise <em>True</em> is returned. Returns an error, if the new score is not greater than the user&#39;s current score in the chat and <em>force</em> is <em>False</em>.
                inline void setGameScore(int user_id, int score, std::string inline_message_id = "", int message_id = 0,
                                         int chat_id = 0, bool disable_edit_message = false, bool force = false) const {
                    json payload1;
                    payload1["user_id"] = user_id;
                    payload1["score"] = score;
                    payload1["inline_message_id"] = inline_message_id;
                    payload1["message_id"] = message_id;
                    payload1["chat_id"] = chat_id;
                    payload1["disable_edit_message"] = disable_edit_message;
                    payload1["force"] = force;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/setGameScore", result1);
                }

// Use this method to get data for high score tables. Will return the score of the specified user and several of their neighbors in a game. Returns an Array of <a href="#gamehighscore">GameHighScore</a> objects.
                inline std::vector<GameHighScore>
                getGameHighScores(int user_id, std::string inline_message_id = "", int message_id = 0,
                                  int chat_id = 0) const {
                    json payload1;
                    payload1["user_id"] = user_id;
                    payload1["inline_message_id"] = inline_message_id;
                    payload1["message_id"] = message_id;
                    payload1["chat_id"] = chat_id;
                    auto result1 = payload1.dump();
                    auto response = request->sendHttp("/getGameHighScores", result1);
                    std::vector<GameHighScore> u;
                    auto response_u = json::parse(response);
                    for (const auto &a: response_u) {
                        GameHighScore u2;
                        from_json(a, u2);
                        u.push_back(u2);
                    }
                    return u;
                }


                ~API() {};
            private:
                std::shared_ptr<Network> &request;
                std::string generalToken = "";
            };
        }
    }
}