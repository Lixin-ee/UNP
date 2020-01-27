//hostent.c
//Code by Lixin on 2020.02.27

#include "unp.h"

int main(int argc,char **argv){
	char *ptr,**pptr;
	char str[INET_ADDRSTRLEN];
	struct hostent *hptr;

	while(--argc>0){
		ptr=*++argv;
		if((hptr=gethostbyname(ptr)==NULL)){
			printf("gethostbyname errno");
			continue;
		}
		printf("official hostname: %s\n",htpr->h_name);

		for(pptr=hptr->h_aliases;*pptr!=NULL;++pptr)
			printf("\talias:%s\n",*pptr);

		switch(hptr->h_addrtype){
			case AF_INET:
				pptr=hptr->h_addr_list;
				for(;*pptr!=NULL;pptr++)
					printf("\taddress:%s\n",inet_ntop(hptr->h_addrtype,*pptr,str,sizeof(str)));
				break;
			default:
			printf("unknown address type");
			break;
		}
	}
	exit(0);
}
