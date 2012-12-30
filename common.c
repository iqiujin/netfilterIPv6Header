#include "common.h"

/*
 * 
 */
void init(ip_list *list)
{

    ip_list tmp = (ip_list)malloc(sizeof(struct _ip_list));
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->count = 0;
    *list = tmp;
}

/*
 * To judge whether the check_ip in ipaddres
 */
int match_rule(const ip_list ipaddrs, char * check_ip)
{
    ip_node node = ipaddrs->head;
    while(node != NULL)
    {
        /*if(ipaddrs->addr.u6_addr32[0] == check_ip.u6_addr32[0] &&
            ipaddrs->addr.u6_addr32[1] == check_ip.u6_addr32[1] &&
            ipaddrs->addr.u6_addr32[2] == check_ip.u6_addr32[2] &&
            ipaddrs->addr.u6_addr32[3] == check_ip.u6_addr32[3] )
            return true;*/
        //the check_ip's type is char*
        if(memcpy(node->addr,check_ip,strlen(check_ip)) == 0)
            return 1;
        node = node->next;
    }
    return 0;
}

/*
 *ADD the if it match the rull
 */
void add_rule(ip_list *ipaddrs, char* check_ip)
{
    //allocate memory
    ip_node node = (ip_node)malloc(sizeof(struct _ip_node));
    //copy data,because the type is pointer
    memcpy(node->addr,check_ip,strlen(check_ip));
//    node->addr = check_ip;
    //memcpy(check_ip, node->addr,sizeof());

    node->next=NULL;

    if(*ipaddrs==NULL)
    {
        init(ipaddrs);
        (*ipaddrs)->head = node;
        (*ipaddrs)->tail = node;
    }    
    else
    {
        (*ipaddrs)->tail->next = node;
        (*ipaddrs)->tail = node;
    }
    //count +1
    (*ipaddrs)->count ++;
}

/*
 *DEL the if it match the rull
 */
void del_rule(ip_list *ipaddrs, char* check_ip)
{
    ip_node node = (*ipaddrs)->head;
    ip_node pre = (*ipaddrs)->head;
    while(node != NULL)
    {
        //if find, only 1
        if(memcmp(node->addr,check_ip,strlen(node->addr)) == 0)
        {
            if(node == (*ipaddrs)->head)
            {
                (*ipaddrs)->head = node->next;
//free(node->addr);
                free(node);//free the node here will free 
            }
            else if(node == (*ipaddrs)->tail)
            {
                (*ipaddrs)->tail = pre;
                pre->next = NULL;
//free(node->addr);
                free(node);
            }
            else
            {
                pre->next = node->next;
//free(node->addr);
                free(node);
            }
            (*ipaddrs)->count --;
            break;
        }
        else
        {
            pre = node;
            node = node->next;
        }
    }


//    if(ipaddrs->count ==0)
//    {
//    }    
}

/*
 * Analysis str according to delim to get command and ip address
 */
void analysis_info(char *command, char *addr_str, char *str,const char *delim)
{
    char * tmp = strsep(&str,delim);
    memcpy(command,tmp,strlen(tmp));

//FIXME:段错误
    memcpy(addr_str,str,strlen(str));
}


void print_6addr(const struct in6_addr *addr)
{
    //PRINT
    printf("%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x\n",
                 (int)addr->s6_addr[0], (int)addr->s6_addr[1],
                 (int)addr->s6_addr[2], (int)addr->s6_addr[3],
                 (int)addr->s6_addr[4], (int)addr->s6_addr[5],
                 (int)addr->s6_addr[6], (int)addr->s6_addr[7],
                 (int)addr->s6_addr[8], (int)addr->s6_addr[9],
                 (int)addr->s6_addr[10], (int)addr->s6_addr[11],
                 (int)addr->s6_addr[12], (int)addr->s6_addr[13],
                 (int)addr->s6_addr[14], (int)addr->s6_addr[15]);
}
