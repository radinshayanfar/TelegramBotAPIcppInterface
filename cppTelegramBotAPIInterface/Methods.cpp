#include "Methods.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace libCURL;

namespace Methods
{
	const string BOTAPI = "https://api.telegram.org/botTOKEN/";
	
	struct curl_httppost *formpost=NULL;
	struct curl_httppost *lastptr=NULL;
	struct curl_slist *headerlist=NULL;
	static const char buf[] = "Expect:";
	
	void getMe()
	{
		string URL = BOTAPI + "getMe";

		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//getMe.json");
		
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void sendMessage(int chat_id, string text, bool disable_web_page_preview, int reply_to_message_id, string reply_markup)
	{
		string URL = BOTAPI + "sendMessage";

		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//sendMessage.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "chat_id", CURLFORM_COPYCONTENTS, to_string(chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "text", CURLFORM_COPYCONTENTS, text.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "disable_web_page_preview", CURLFORM_COPYCONTENTS, (disable_web_page_preview) ? "true" : "false", CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_to_message_id", CURLFORM_COPYCONTENTS, to_string(reply_to_message_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_markup", CURLFORM_COPYCONTENTS, reply_markup.c_str(), CURLFORM_END);
		// ============ Untitled =========== // 
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void forwardMessage(int chat_id, int from_chat_id, int message_id)
	{
		string URL = BOTAPI + "forwardMessage";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//forwardMessage.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "chat_id", CURLFORM_COPYCONTENTS, to_string(chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "from_chat_id", CURLFORM_COPYCONTENTS, to_string(from_chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "message_id", CURLFORM_COPYCONTENTS, to_string(message_id).c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void sendPhoto(int chat_id, string photo, string caption, int reply_to_message_id, string reply_markup)
	{
		string URL = BOTAPI + "sendPhoto";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//sendPhoto.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "chat_id", CURLFORM_COPYCONTENTS, to_string(chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "photo", CURLFORM_FILE, photo.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "caption", CURLFORM_COPYCONTENTS, caption.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_to_message_id", CURLFORM_COPYCONTENTS, to_string(reply_to_message_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_markup", CURLFORM_COPYCONTENTS, reply_markup.c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void sendAudio(int chat_id, string audio, int duration, string performer, string title, int reply_to_message_id, string reply_markup)
	{
		string URL = BOTAPI + "sendAudio";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//sendAudio.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "chat_id", CURLFORM_COPYCONTENTS, to_string(chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "audio", CURLFORM_FILE, audio.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "duration", CURLFORM_COPYCONTENTS, to_string(duration).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "performer", CURLFORM_COPYCONTENTS, performer.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "title", CURLFORM_COPYCONTENTS, title.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_to_message_id", CURLFORM_COPYCONTENTS, to_string(reply_to_message_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_markup", CURLFORM_COPYCONTENTS, reply_markup.c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void sendDocument(int chat_id, string document, int reply_to_message_id, string reply_markup)
	{
		string URL = BOTAPI + "sendDocument";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//sendDocument.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "chat_id", CURLFORM_COPYCONTENTS, to_string(chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "document", CURLFORM_FILE, document.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_to_message_id", CURLFORM_COPYCONTENTS, to_string(reply_to_message_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_markup", CURLFORM_COPYCONTENTS, reply_markup.c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void sendSticker(int chat_id, string sticker, int reply_to_message_id, string reply_markup)
	{
		string URL = BOTAPI + "sendSticker";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//sendSticker.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "chat_id", CURLFORM_COPYCONTENTS, to_string(chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "sticker", CURLFORM_FILE, sticker.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_to_message_id", CURLFORM_COPYCONTENTS, to_string(reply_to_message_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_markup", CURLFORM_COPYCONTENTS, reply_markup.c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void sendVideo(int chat_id, string video, int duration, string caption, int reply_to_message_id, string reply_markup)
	{
		string URL = BOTAPI + "sendVideo";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//sendVideo.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "chat_id", CURLFORM_COPYCONTENTS, to_string(chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "video", CURLFORM_FILE, video.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "duration", CURLFORM_COPYCONTENTS, to_string(duration).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "caption", CURLFORM_COPYCONTENTS, caption.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_to_message_id", CURLFORM_COPYCONTENTS, to_string(reply_to_message_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_markup", CURLFORM_COPYCONTENTS, reply_markup.c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void sendVoice(int chat_id, string voice, int duration, int reply_to_message_id, string reply_markup)	
	{
		string URL = BOTAPI + "sendVoice";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//sendVoice.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "chat_id", CURLFORM_COPYCONTENTS, to_string(chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "voice", CURLFORM_FILE, voice.c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "duration", CURLFORM_COPYCONTENTS, to_string(duration).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_to_message_id", CURLFORM_COPYCONTENTS, to_string(reply_to_message_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_markup", CURLFORM_COPYCONTENTS, reply_markup.c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void sendLocation(int chat_id, float latitude, float longitude, int reply_to_message_id, string reply_markup)
	{
		string URL = BOTAPI + "sendLocation";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//sendLocation.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "chat_id", CURLFORM_COPYCONTENTS, to_string(chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "latitude", CURLFORM_COPYCONTENTS, to_string(latitude).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "longitude", CURLFORM_COPYCONTENTS, to_string(longitude).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_to_message_id", CURLFORM_COPYCONTENTS, to_string(reply_to_message_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "reply_markup", CURLFORM_COPYCONTENTS, reply_markup.c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void sendChatAction(int chat_id, string action)
	{
		string URL = BOTAPI + "sendChatAction";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//sendChatAction.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "chat_id", CURLFORM_COPYCONTENTS, to_string(chat_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "action", CURLFORM_COPYCONTENTS, action.c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void getUserProfilePhotos(int user_id, int offset, int limit)
	{
		string URL = BOTAPI + "getUserProfilePhotos";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//getUserProfilePhotos.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "user_id", CURLFORM_COPYCONTENTS, to_string(user_id).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "offset", CURLFORM_COPYCONTENTS, to_string(offset).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "limit", CURLFORM_COPYCONTENTS, to_string(limit).c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void getUpdates(int offset, int limit, int timeout)
	{
		string URL = BOTAPI + "getUpdates";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//getUpdates.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "offset", CURLFORM_COPYCONTENTS, to_string(offset).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "limit", CURLFORM_COPYCONTENTS, to_string(limit).c_str(), CURLFORM_END);
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "timeout", CURLFORM_COPYCONTENTS, to_string(timeout).c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void setWebhook(string url, string certificate)
	{
		string URL = BOTAPI + "setWebhook";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//setWebhook.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "url", CURLFORM_COPYCONTENTS, url.c_str(), CURLFORM_END);
		if (certificate != "")
			curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "certificate", CURLFORM_FILE, certificate.c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
	void getFile(string file_id)
	{
		string URL = BOTAPI + "getFile";
		// ============ convert string to char array =========== // 
		char c[200];
		strncpy(c, URL.c_str(), sizeof(c));
		c[sizeof(c) - 1] = 0;
		
		CURL *curl = init(c, "..//getFile.json");
		// ============ add fields =========== // 
		curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "file_id", CURLFORM_COPYCONTENTS, file_id.c_str(), CURLFORM_END);
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
		curl_easy_perform(curl);
	    curl_easy_cleanup(curl);
	}
}
