#define METHODS_H
#ifndef METHODS_H

#include "CURL.h"

#endif
#include <curl/curl.h>

namespace Methods
{	
	void getMe();
	void sendMessage(int chat_id, string text, bool disable_web_page_preview = false, int reply_to_message_id = 0, string reply_markup = "");
	void forwardMessage(int chat_id, int from_chat_id, int message_id);
	void sendPhoto(int chat_id, string photo, string caption = "", int reply_to_message_id = 0, string reply_markup = "");
	void sendAudio(int chat_id, string audio, int duration = 0, string performer = "", string title = "", int reply_to_message_id = 0, string reply_markup = "");
	void sendDocument(int chat_id, string document, int reply_to_message_id = 0, string reply_markup = "");
	void sendSticker(int chat_id, string sticker, int reply_to_message_id = 0, string reply_markup = "");
	void sendVideo(int chat_id, string video, int duration = 0, string caption = "", int reply_to_message_id = 0, string reply_markup = "");
	void sendVoice(int chat_id, string voice, int duration = 0, int reply_to_message_id = 0, string reply_markup = "");
	void sendLocation(int chat_id, float latitude, float longitude, int reply_to_message_id = 0, string reply_markup = "");
	void sendChatAction(int chat_id, string action);
	void getUserProfilePhotos(int user_id, int offset = 0, int limit = 100);
	void getUpdates(int offset = 0, int limit = 100, int timeout = 0);
	void setWebhook(string url = "", string certificate = "");
	void getFile(string file_id);
	
}
