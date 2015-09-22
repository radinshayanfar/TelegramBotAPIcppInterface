#include "CURL.h"
#include <curl/curl.h>

using namespace libCURL;

namespace Methods
{
	const string BOTAPI = "https://api.telegram.org/botTOKEN/";
	
	struct curl_httppost *formpost=NULL;
	struct curl_httppost *lastptr=NULL;
	struct curl_slist *headerlist=NULL;
	static const char buf[] = "Expect:";
	
	void getMe();
	void sendMessage(int chat_id, string text, bool disable_web_page_preview, int reply_to_message_id, string reply_markup);
	void forwardMessage(int chat_id, int from_chat_id, int message_id);
	void sendPhoto(int chat_id, string photo, string caption, int reply_to_message_id, string reply_markup);
	void sendAudio(int chat_id, string audio, int duration, string performer, string title, int reply_to_message_id, string reply_markup);
	void sendDocument(int chat_id, string document, int reply_to_message_id, string reply_markup);
	void sendSticker(int chat_id, string sticker, int reply_to_message_id, string reply_markup);
	void sendVideo(int chat_id, string video, int duration, string caption, int reply_to_message_id, string reply_markup);
	void sendVoice(int chat_id, string voice, int duration, int reply_to_message_id, string reply_markup);
	void sendLocation(int chat_id, float latitude, float longitude, int reply_to_message_id, string reply_markup);
	void sendChatAction(int chat_id, string action);
	void getUserProfilePhotos(int user_id, int offset, int limit);
	void getUpdates(int offset, int limit, int timeout);
	void setWebhook(string url, string certificate);
	void getFile(string file_id);
	
}
