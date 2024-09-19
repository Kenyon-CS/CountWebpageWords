#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cctype>
#include <curl/curl.h>

using namespace std;

// Callback function to write data received from curl
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Function to fetch the content of the web page
string fetchWebPage(const string& url) {
    CURL* curl;
    CURLcode res;
    string data;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if(res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            return "";
        }
    }
    return data;
}

// Function to process the web page content and count words
void countWords(const string& content, map<string, int>& wordCount) {
    stringstream ss(content);
    string word;

    while (ss >> word) {
        // Remove punctuation and convert to lowercase
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (!word.empty()) {
            wordCount[word]++;
        }
    }
}

// Function to display the word counts
void displayWordCounts(const map<string, int>& wordCount) {
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string url;
    cout << "Enter the URL of the web page: ";
    getline(cin, url);

    string content = fetchWebPage(url);
    if (content.empty()) {
        cerr << "Failed to fetch content from URL." << endl;
        return 1;
    }

    map<string, int> wordCount;
    countWords(content, wordCount);

    cout << "\nWord counts:" << endl;
    displayWordCounts(wordCount);

    return 0;
}
