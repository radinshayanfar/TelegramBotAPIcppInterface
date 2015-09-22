#include <curl/curl.h>
#include <curl/easy.h>
#include <string>

using namespace std;

namespace libCURL
{
	size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
	{
	    size_t written = fwrite(ptr, size, nmemb, stream);
	    return written;
	}
	
	CURL* init(char* URL, string FILENAME, FILE* (&fp))
	{
	    CURL *curl;
	    
	    CURLcode res;
	    char *url = URL;
	    string outfilename = FILENAME;
	    curl = curl_easy_init();
	    if (curl)
	    {
	        //curl_off_t max_speed = 1000 * 25;
		    //curl_easy_setopt(curl, CURLOPT_MAX_RECV_SPEED_LARGE, max_speed);
	        fp = fopen(outfilename.c_str(), "wb");
	        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
	        curl_easy_setopt(curl, CURLOPT_URL, url);
	        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	        //res = curl_easy_perform(curl);
	        /* always cleanup */
	        //curl_easy_cleanup(curl);
	        //fclose(fp);
	    }
		return curl;
	}
};
