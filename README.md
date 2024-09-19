# CountWebpageWords

Here's a C++ program that uses std::map to count unique words on a web page. This program will prompt the user for a URL, fetch the content of the web page, and then output a list of words along with their counts, sorted in ascending order by the words.

To accomplish this, the program will:

1. Use the libcurl library to fetch the content from the URL.
2. Use std::map to count occurrences of each word.
3. Display the word counts in sorted order.

## Explanation:
1. `WriteCallback` Function:
A callback function used by libcurl to write data to a string.
2. `fetchWebPage` Function:
Uses libcurl to fetch the content from a given URL.
3. `countWords` Function:
Processes the content, tokenizes it into words, and counts occurrences while ignoring punctuation and converting words to lowercase.
4. `displayWordCounts` Function:
Outputs the words and their counts in ascending order.
5. `main` Function:
Prompts the user for a URL, fetches the content, counts the words, and displays the results.

Dependencies:
`libcurl`: You need to have the libcurl library installed to fetch the web page content. On Debian-based systems, you can install it using:
```
sudo apt-get install libcurl4-openssl-dev
```
On Red Hat-based systems:
```
sudo yum install libcurl-devel
```
