#include "SplayBST.h"
#include <string>
#include <stdio.h>
using namespace std;
int main() {
    SplayBST<string, string> search;
    search.put("www.baidu.com", "119.75.217.109");
    printf("www.baidu.com:%s\n", search.get("www.baidu.com").c_str());
    search.put("www.sina.com", "218.30.108.184");
    search.put("www.baidu.com", "119.75.217.119");
    printf("www.baidu.com:%s\n", search.get("www.baidu.com").c_str());
    printf("www.sina.com:%s\n", search.get("www.sina.com").c_str());
    search.put("www.soso.com", "124.192.132.236");
    printf("www.soso.com:%s\n", search.get("www.soso.com").c_str());
    search.put("www.soso.com", "124.192.132.236");
    printf("www.soso.com:%s\n", search.get("www.soso.com").c_str());
    printf("www.nba.com:%s\n", search.get("www.nba.com").c_str()); // crash
}
