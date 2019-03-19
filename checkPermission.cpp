#include "checkPermission.h"

string checkPermission::generateMD5(const char* password)
{
    unsigned char md[MD5_DIGEST_LENGTH];
    unsigned char* buffer_md5 = MD5((unsigned char*)password, strlen(password), md);
    char buf[32];
    string result;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
         sprintf(buf, "%02x", buffer_md5[i]);
         result.append( buf );
        // ss << hex << (unsigned int)(result[i]);
    }
    return result;
}

bool checkPermission::check(string md5String)
{
    bool result = false;
    std::vector<string> source;
    const char * filename = "/home/yapie/github/gketh/permissionController/cipherText.out";
    std::ifstream file;
    file.open(filename,ios::in);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            source.push_back(line);
        }
    }
    else
    {
        cout<<"cant open "<<filename<<endl;
    }
    
    file.close();
    if (search(source, md5String))
    {
        result = true;
    }
    return result;
}


bool checkPermission::search(std::vector<std::string> source, std::string needFind)
{
   bool result = false;
    for (unsigned int i = 0; i < source.size(); i++)
    {
        if (source[i] == needFind)
        {
            result = true;
            break;
        }
    }
    return result;
}

size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool checkPermission::checkUser(string userId, string password)
{
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    /* In windows, this will init the winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL);

    /* get a curl handle */
    curl = curl_easy_init();
    if (curl)
    {
        /* First set the URL that is about to receive our POST. This URL can
           just as well be a https:// URL if that is what should receive the
           data. */
        curl_easy_setopt(curl, CURLOPT_URL, "http://47.99.188.146:9999/api/user/");
        /* Now specify the POST data */
        char data[1024];
        
        snprintf(data, sizeof(data), "password=%s&userId=%s", &password[0], &userId[0]);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA, &readBuffer);
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
        std::cout<<readBuffer;
    }
    curl_global_cleanup();
    if(readBuffer == "true\n")
    {
        return true;
    }
    else
    {
        return false;
    }
    

}
