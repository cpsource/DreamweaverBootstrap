
#include <stdio.h>
#include <string.h>

#include "autoedit.h"

#if 0
---
title: 'The Case of the Missing Architect.'
date: 2022-01-20T09:15:00.000Z
draft: false
description: >-
  In this case, we visit a sub-contractor working on an interface to a telephone switch for a much larger client.
---
#endif // 0

  // get header - note we leave the file open and the next fgets will start
  // reading after the ---
  
char *date = NULL;
char *title = NULL;
char *desc = NULL;

void build_html(FILE **outf, char *fname)
{
  char wbuf[4096];
  char fullname[1024];
  char *c,*d,*n;
  int cnt = sizeof(wbuf)-10;
  int i;
  FILE *inf;
  
  // build file name

  // create <file>.html in DreamweaverBootstrap
  sprintf(fullname,DW_HTML_PATH,fname);
  *outf = fopen(fullname,"w");
  if ( ! *outf ) {
    printf("Error: can't create file <%s>\n",fullname);
    exit(0);
  }

#define TITLE "<title>template</title>"
  // dump out front of heml file from template.html
  for ( i = 0 ; front[i] != NULL ; i++ ) {
    if ( strstr(front[i],TITLE) ) {
      fprintf(*outf,"<title>%s</title>\n",title);
    } else {
      fprintf(*outf,"%s\n",front[i]);
    }
  }
#undef TITLE
  
  // open <file>.html from one-click-hugo-cms
  sprintf(fullname,HUG_HTML_PATH,fname);
  inf = fopen(fullname,"r");
  if ( ! inf ) {
    printf("Error: can open <%s> for reading\n",fullname);
    exit ( 0 );
  }
  
#define NAV "</nav>"
#define FOOTER "<footer"
  
  // skip down to just after </nav>
  while ( fgets(wbuf,sizeof(wbuf),inf) ) {
    if ( strstr(wbuf,NAV) ) {
      break;
    }
  } // while
    
    // copy out until we reach FOOTER
    
  while ( fgets(wbuf,sizeof(wbuf),inf) ) {
    if ( strstr(wbuf,FOOTER) ) {
      break;
    }
    fprintf(*outf,"%s",wbuf);
  } // while
    
  fclose(inf);

  // dump out back of heml file from template.html
  for ( i = 0 ; back[i] != NULL ; i++ ) {
    fprintf(*outf,"%s\n",back[i]);
  }
#undef NAV
#undef FOOTAR
    
}

void get_hdr_info(FILE **inf, char *fname)
{
  char wbuf[4096];
  char fullname[1024];
  char *c,*d,*n;
  int cnt = sizeof(wbuf)-10;
  
  sprintf(fullname,HUG_MD_PATH,fname);
  *inf = fopen(fullname,"r");
  if ( !*inf ) {
    printf("Error: can't open <%s>\n",wbuf);
    exit(0);
  }

  cnt = sizeof(wbuf);
  while (fgets(wbuf,cnt,*inf)) {
    n = strchr(wbuf,'\n'); if ( n ) *n = 0;
    n = strchr(wbuf,'\r'); if ( n ) *n = 0;
    printf("reading line <%s>\n",wbuf);
#define DATE "date: "
    if ( 0 == strncmp(DATE,wbuf,strlen(DATE)) ) {
      c = wbuf;
      //printf("date matched\n");
      c += sizeof(DATE);
      date = strdup(c);
      goto cont;
    }
#define TITLE "title: "    
    if ( 0 == strncmp(TITLE,wbuf,strlen(TITLE)) ) {
      c = wbuf;
      c += sizeof(TITLE);
      if ( *c == '\'' ) c += 1;
      d = strchr(c,'\''); if ( d ) *d = 0;
      title = strdup(c);
      goto cont;
    }

#define DESC "description: "

    if ( 0 == strncmp(DESC,wbuf,strlen(DESC)) ) {
      c = wbuf;
      cnt = sizeof(wbuf);
      while (cnt > 256 && fgets(c,cnt,*inf)) {
	if ( *c == '-' ) {
	  *c = 0;
	  break;
	}
	//	n = strchr(c,'\n' ); if ( n ) *n = 0;
	//	n = strchr(c,'\r' ); if ( n ) *n = 0;
	cnt -= strlen(c);
	c += strlen(c);
	continue;
      } // inner while
      // no more input
      c = strrchr(wbuf,'\n' ); if ( c ) *c = 0;
      if ( c[-1] == '\r' ) c[-1] = 0;
      desc = strdup(wbuf);
      goto cont;
    }
    
  cont:;
    c = wbuf;
    cnt = sizeof(wbuf);
    memset(wbuf,0,sizeof(wbuf));
  } // while

  // lets log
  printf("get_hdr_info for file <%s>\n",fullname);
  printf("  date = <%s>\n",date);
  printf("  title = <%s>\n",title);
  printf("  desc = <%s>\n",desc);

  // done
}

int main(int argc, char *argv[])
{
  FILE *md_inf = NULL;
  FILE *html_outf = NULL;
  
  if ( argc < 2 ) {
    printf("Usage: ./autoedit: file-to-merge\n");
    exit(0);
  }

  get_hdr_info(&md_inf,argv[1]);
  if ( md_inf ) fclose(md_inf);

  build_html(&html_outf, argv[1]);
  if ( html_outf ) fclose(html_outf);
  
  return 0;
}
