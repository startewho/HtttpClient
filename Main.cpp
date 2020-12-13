
#include "HTTPClient.h"
using std::string;

void UploadIamge(string host,string file)
{
	string response;
	long httpCode = 0;
	CHTTPClient::QueryMap Queries;
	CHTTPClient::PostFormInfo UploadInfo;
	CHTTPClient::SettingsFlag setting;
	string imageUrl = host + "/Image/Upload";

	setting = CHTTPClient::SettingsFlag::ENABLE_LOG;

	CHTTPClient client([](const std::string& log) { std::cout << log << std::endl; });

	client.InitSession(false,setting);
	
	Queries.emplace("keyName", "中文Id");
	Queries.emplace("random", "Id中文");

	UploadInfo.AddFormFile("file", file);

	client.UploadForm(imageUrl, UploadInfo, Queries, response, httpCode);

	client.CleanupSession();
	string utf8Response = UTF8_To_GBK(response);

	std::cout << utf8Response << std::endl;
}

void UploadProject(string host, string token,string file)
{
	string response;
	long httpCode = 0;
	CHTTPClient::QueryMap Queries;
	CHTTPClient::HeadersMap Headers;
	CHTTPClient::PostFormInfo UploadInfo;
	CHTTPClient::SettingsFlag setting;
	string imageUrl = host + "/Project/AddFile";

	setting = CHTTPClient::SettingsFlag::ENABLE_LOG;

	CHTTPClient client([](const std::string& log) { std::cout << log << std::endl; });
	
	client.InitSession(false,setting);

	Headers.emplace("Authorization", "Bearer " + token);
	client.AddHeaders(Headers);

	Queries.emplace("id", "0");
	Queries.emplace("clientId", "ClientId中文");

	UploadInfo.AddFormFile("file", file);

	client.UploadForm(imageUrl, UploadInfo, Queries, response, httpCode);
	client.CleanupSession();

	string utf8Response = UTF8_To_GBK(response);

	std::cout << utf8Response << std::endl;
}


int main()
{
	string token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiZGZzYXMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1laWRlbnRpZmllciI6IjEiLCJodHRwOi8vc2NoZW1hcy5taWNyb3NvZnQuY29tL3dzLzIwMDgvMDYvaWRlbnRpdHkvY2xhaW1zL3JvbGUiOiIiLCJleHAiOjE2MDc4NTk4MDksImlzcyI6Ii9hcGkvdXNlci9sb2dpbiIsImF1ZCI6Ii9hcGkvdXNlci9sb2dpbiJ9.8nRCOeMAMeitGQJxfltm6y27fZxMIW7T_htQlE7ygFg";
	std::cout << "http上传图片" << std::endl;
	UploadIamge("http://localhost:5000/api","C:\\Users\\hoolo\\Pictures\\1.jpg");
	std::cout << "http上传项目" << std::endl;
	UploadProject("http://localhost:5000/api", token,"C:\\Users\\hoolo\\Pictures\\1.jpg");
	std::cout << "https上传图片" << std::endl;
	UploadIamge("https://localhost:443/api", "C:\\Users\\hoolo\\Pictures\\1.jpg");
	std::cout << "https上传项目" << std::endl;
	UploadProject("https://localhost:443/api", token, "C:\\Users\\hoolo\\Pictures\\1.jpg");
}