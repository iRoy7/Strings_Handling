#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

const int YES = 1;
const int NO = 0;

int is_ip_address11(const char* ip)
{
	printf("input ip is %s\n ", ip);
	struct sockaddr_in ip4addr;

	ip4addr.sin_family = AF_INET;
	ip4addr.sin_port = htons(3490);
	ip4addr.sin_addr.s_addr = inet_addr("10.0.0.1");
		
	//unsigned char buf_ipv4[4];
	//unsigned char buf_ipv4[INET_ADDRSTRLEN];
	//unsigned char buf_ipv6[INET6_ADDRSTRLEN];

	//in_addr* ipAddress;

	int ipv4_ok;
	ipv4_ok = InetPton(AF_INET, (PCTSTR)"10.0.0.1", &ip4addr.sin_addr);

	//unsigned long ipaddr = InetPton(AF_INET, (PCTSTR)ip, &ipAddress);
	//int ret = InetPton(AF_INET, ip, buf_ipv4);
	//int ret = InetPton(AF_INET, (PCTSTR)ip, &ip4addr.sin_addr);
	printf("Error code ret = %d\n", ipv4_ok);
	//if ((InetPton(AF_INET, (PCTSTR)ip, buf_ipv4) == 1) || (InetPton(AF_INET6, (PCTSTR)ip, buf_ipv6) == 1))
	//if ((inet_pton(AF_INET, ip, buf_ipv4) == 1) || (inet_pton(AF_INET6, ip, buf_ipv6) == 1))
	//inet_pton(AF_INET, ip, buf_ipv4);
	//InetPton(AF_INET, (PCTSTR)ip, buf_ipv4);
	if (1)
		return YES;
	else 
		return NO;
}


int main()
{
	printf("Simple parser:\n");
	const char* server_ip = "136.149.3.29:8080";
	printf("server ip with port: %s\n", server_ip);

	char isp_ip[INET_ADDRSTRLEN];
	int i;
	for (i = 0; server_ip[i]; i++)
	{
		if (server_ip[i] != ':')
		{
			isp_ip[i] = server_ip[i];
			continue;
		}
		else 
			break;
	}
	isp_ip[i] = '\0';
	printf("isp ip = %s\n", isp_ip);
	if (is_ip_address11(isp_ip) == YES)
	//if (is_ip_address11(server_ip) == YES)
		printf("PASS\n");
	else
		printf("NO\n");

	return 0;
}