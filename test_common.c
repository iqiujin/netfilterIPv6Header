#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#include <sys/socket.h>

int main()
{
   /* char IPdotdec[40]; //存放点分十进制IP地址
    struct in6_addr s; // IPv4地址结构体
    
    // 输入IP地址 　　
    printf("Please input IP address: ");
    scanf("%s", IPdotdec);
    // 转换 
    inet_pton(AF_INET6, IPdotdec, (void *)&s);
    print_6addr(&s);
    //printf("inet_pton: 0x%x\n", s.s6_addr32[0]); // 注意得到的字节序
    // 反转换
    inet_ntop(AF_INET6, (void *)&s, IPdotdec, 16);
    printf("inet_ntop: %s\n", IPdotdec);

   */
    ip_list addrs = NULL;

    char command[6] ={'\0'},ipaddr[60]={'\0'};
    char inputs[60];
char *cmds;
    struct in6_addr s;
    ip_node node;


    while(1)
    {
        printf("Please input command: 'ADD/DEL + addr' or 'q' \n");
        scanf("%s", inputs);
        if(strncmp(inputs,"q",1) == 0)
           break;
        else
        {
            sscanf(inputs, "%[A-Za-z]>%s", command, ipaddr);
            cmds = inputs;
//            analysis_info(command, ipaddr, cmds, ">");


            if(strcmp(command,"ADD")==0)
            {

                add_rule(&addrs, ipaddr);
            }
            else if(strcmp(command,"DEL")==0)
            {
                del_rule(&addrs, ipaddr);
            }
        }
    }


    if(addrs != NULL)
    {
        node = addrs->head;
        while(node != NULL)
        {
            /*if(ipaddrs->addr.u6_addr32[0] == check_ip.u6_addr32[0] &&
                ipaddrs->addr.u6_addr32[1] == check_ip.u6_addr32[1] &&
                ipaddrs->addr.u6_addr32[2] == check_ip.u6_addr32[2] &&
                ipaddrs->addr.u6_addr32[3] == check_ip.u6_addr32[3] )
                return true;*/
            //the check_ip's type is char*
            inet_pton(AF_INET6, node->addr, (void *)&s);
             print_6addr(&s);
            node = node->next;
        }
    }
 
}
